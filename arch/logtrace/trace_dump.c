/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  $Id: trace_dump.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�g���[�X���O�̃_���v
 */

#include "kernel_impl.h"
#include "task.h"
#include <log_output.h>

/* 
 *  �J�[�l�����̎�o��
 */
static intptr_t
get_tskid(intptr_t info)
{
	TCB		*p_tcb;
	ID		tskid;

	p_tcb = (TCB *) info;
	if (p_tcb == NULL) {
		tskid = 0;
	}
	else {
		tskid = TSKID(p_tcb);
	}
	return((intptr_t) tskid);
}

static intptr_t
get_tskstat(intptr_t info)
{
	uint_t		tstat;
	const char	*tstatstr;

	tstat = (uint_t) info;
	switch (tstat & (TS_RUNNABLE|TS_WAITING|TS_SUSPENDED)) {
	case TS_DORMANT:
		tstatstr = "DORMANT";
		break;
	case TS_RUNNABLE:
		tstatstr = "RUNNABLE";
		break;
	case TS_WAITING:
		tstatstr = "WAITING";
		break;
	case TS_SUSPENDED:
		tstatstr = "SUSPENDED";
		break;
	case TS_WAITING|TS_SUSPENDED:
		tstatstr = "WAITING-SUSPENDED";
		break;
	default:
		tstatstr = "unknown state";
		break;
	}
	return((intptr_t) tstatstr);
}

/* 
 *  �g���[�X���O�̕\��
 */
static void
trace_print(TRACE *p_trace, void (*putc)(char))
{
	intptr_t	traceinfo[TMAX_LOGINFO + 1];
	const char	*tracemsg;
	int_t		i;

	traceinfo[0] = (intptr_t)(p_trace->logtim);
	syslog_printf("[%d] ", traceinfo, putc);

	switch (p_trace->logtype) {
	case LOG_TYPE_TSKSTAT:
		traceinfo[0] = get_tskid(p_trace->loginfo[0]);
		traceinfo[1] = get_tskstat(p_trace->loginfo[1]);
		tracemsg = "task %d becomes %s.";
		break;
	case LOG_TYPE_DSP|LOG_LEAVE:
		traceinfo[0] = get_tskid(p_trace->loginfo[0]);
		tracemsg = "dispatch to task %d.";
		break;
	case LOG_TYPE_COMMENT:
		for (i = 1; i < TMAX_LOGINFO; i++) {
			traceinfo[i-1] = p_trace->loginfo[i];
		}
		tracemsg = (const char *)(p_trace->loginfo[0]);
		break;
	case LOG_TYPE_ASSERT:
		traceinfo[0] = p_trace->loginfo[0];
		traceinfo[1] = p_trace->loginfo[1];
		traceinfo[2] = p_trace->loginfo[2];
		tracemsg = "%s:%u: Assertion `%s' failed.";
		break;
	default:
		traceinfo[0] = p_trace->logtype;
		tracemsg = "unknown trace log type: %d.";
		break;
	}
	syslog_printf(tracemsg, traceinfo, putc);
	(*putc)('\n');
}

/* 
 *  �g���[�X���O�̃_���v
 */
void
trace_dump(intptr_t exinf)
{
	TRACE	trace;
	void	(*putc)(char);

	putc = (void (*)(char)) exinf;
	while (trace_rea_log(&trace) >= 0) {
		trace_print(&trace, putc);
	}
}

/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: trace_config.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�g���[�X���O�@�\
 */

#include "kernel_impl.h"
#include "task.h"
#include "time_event.h"
#include <sil.h>

/*
 *  �g���[�X���O�o�b�t�@�Ƃ���ɃA�N�Z�X���邽�߂̃|�C���^
 */
SYSLOG	trace_buffer[TCNT_TRACE_BUFFER];	/* �g���[�X���O�o�b�t�@ */
uint_t	trace_count;				/* �g���[�X���O�o�b�t�@���̃��O�̐� */
uint_t	trace_head;					/* �擪�̃g���[�X���O�̊i�[�ʒu */
uint_t	trace_tail;					/* ���̃g���[�X���O�̊i�[�ʒu */
MODE	trace_mode;					/* �g���[�X���[�h */

/*
 *  �g���[�X���O�@�\�̏�����
 */
void
trace_initialize(intptr_t exinf)
{
	MODE	mode = ((MODE) exinf);

	trace_count = 0U;
	trace_head = 0U;
	trace_tail = 0U;
	trace_mode = mode;
}     

/*
 *  �g���[�X���O�̊J�n
 */
ER
trace_sta_log(MODE mode)
{
	if ((mode & TRACE_CLEAR) != 0U) {
		trace_count = 0U;
		trace_head = 0U;
		trace_tail = 0U;
	}
	trace_mode = mode;
	return(E_OK);
}     

/* 
 *  �g���[�X���O�̏�����
 */
ER
trace_wri_log(TRACE *p_trace)
{
	SIL_PRE_LOC;

	if (trace_mode != TRACE_STOP) {
		SIL_LOC_INT();

		/*
		 *  �g���[�X�����̐ݒ�
		 *
		 *  LOG_WRI_LOG_ENTER����Ă΂ꂽ�ꍇ��p_trace->logtim��������
		 *  ���Ă��܂��̂͋C�������������Cwri_log�̕��ŏ㏑�����邽�ߖ�
		 *  ��͂Ȃ��D
		 */
		p_trace->logtim = TRACE_GET_TIM();

		/*
		 *  �g���[�X�o�b�t�@�ɋL�^
		 */
		trace_buffer[trace_tail] = *p_trace;
		trace_tail++;
		if (trace_tail >= TCNT_TRACE_BUFFER) {
			trace_tail = 0U;
		}
		if (trace_count < TCNT_TRACE_BUFFER) {
			trace_count++;
			if (trace_count >= TCNT_TRACE_BUFFER
						&& (trace_mode & TRACE_AUTOSTOP) != 0U) {
				trace_mode = TRACE_STOP;
			}
		}
		else {
			trace_head = trace_tail;
		}

		SIL_UNL_INT();
	}
	return(E_OK);
}

/*
 *  �g���[�X���O�̓Ǐo��
 */
ER
trace_rea_log(TRACE *p_trace)
{
	ER_UINT	ercd;
	SIL_PRE_LOC;

	SIL_LOC_INT();

	/*
	 *  �g���[�X���O�o�b�t�@����̎�o��
	 */
	if (trace_count > 0U) {
		*p_trace = trace_buffer[trace_head];
		trace_count--;
		trace_head++;
		if (trace_head >= TCNT_TRACE_BUFFER) {
			trace_head = 0U;
		}
		ercd = E_OK;
	}
	else {
		ercd = E_OBJ;
	}

	SIL_UNL_INT();
	return(ercd);
}

/*
 *  �g���[�X���O���o�͂��邽�߂̃��C�u�����֐�
 */

void
trace_write_0(uint_t type)
{
	TRACE	trace;

	trace.logtype = type;
	(void) trace_wri_log(&trace);
}

void
trace_write_1(uint_t type, intptr_t arg1)
{
	TRACE	trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	(void) trace_wri_log(&trace);
}

void
trace_write_2(uint_t type, intptr_t arg1, intptr_t arg2)
{
	TRACE	trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	(void) trace_wri_log(&trace);
}

void
trace_write_3(uint_t type, intptr_t arg1, intptr_t arg2, intptr_t arg3)
{
	TRACE	trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	trace.loginfo[2] = arg3;
	(void) trace_wri_log(&trace);
}

/*
 *  �A�Z���u������ŋL�q�����R�[�h����g���[�X���O���o�͂��邽�߂̊�
 *  ��
 */

void
log_dsp_enter(TCB *p_tcb)
{
	trace_1(LOG_TYPE_DSP|LOG_ENTER, p_tcb);
}

void
log_dsp_leave(TCB *p_tcb)
{
	trace_1(LOG_TYPE_DSP|LOG_LEAVE, p_tcb);
}

void
log_inh_enter(INHNO inhno)
{
	trace_1(LOG_TYPE_INH|LOG_ENTER, inhno);
}

void
log_inh_leave(INHNO inhno)
{
	trace_1(LOG_TYPE_INH|LOG_LEAVE, inhno);
}

void
log_exc_enter(EXCNO excno)
{
	trace_1(LOG_TYPE_EXC|LOG_ENTER, excno);
}

void
log_exc_leave(EXCNO excno)
{
	trace_1(LOG_TYPE_EXC|LOG_LEAVE, excno);
}

/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2012 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: sample1.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *  �T���v���v���O����(1)�̖{��
 *
 *  ASP�J�[�l���̊�{�I�ȓ�����m�F���邽�߂̃T���v���v���O�����D
 *
 *  �v���O�����̊T�v:
 *
 *  ���[�U�C���^�t�F�[�X���󂯎����C���^�X�N�i�^�X�NID: MAIN_TASK�C�D
 *  ��x: MAIN_PRIORITY�j�ƁC3�̕��s���s�����^�X�N�i�^�X�NID:
 *  TASK1�`TASK3�C�����D��x: MID_PRIORITY�j�ō\�������D�܂��C�N����
 *  ����2�b�̎����n���h���i�����n���h��ID: CYCHDR1�j��p����D
 *
 *  ���s���s�����^�X�N�́Ctask_loop��󃋁[�v�����s����x�ɁC�^�X�N��
 *  ���s���ł��邱�Ƃ�����킷���b�Z�[�W��\������D�󃋁[�v�����s����
 *  �̂́C�󃋁[�v�Ȃ��Ń��b�Z�[�W���o�͂���ƁC���ʂ̃��b�Z�[�W���o��
 *  ����C�v���O�����̓��삪�m�F�����炭�Ȃ邽�߂ł���D�܂��C�ᑬ�ȃV
 *  ���A���|�[�g��p���ă��b�Z�[�W���o�͂���ꍇ�ɁC���ׂẴ��b�Z�[�W
 *  ���o�͂ł���悤�ɁC���b�Z�[�W�̗ʂ𐧌�����Ƃ������R������D
 *
 *  �����n���h���́C�O�̗D��x�iHIGH_PRIORITY�CMID_PRIORITY�C
 *  LOW_PRIORITY�j�̃��f�B�L���[����]������D�v���O�����̋N������́C
 *  �����n���h���͒�~��ԂɂȂ��Ă���D
 *
 *  ���C���^�X�N�́C�V���A��I/O�|�[�g����̕������͂��s���i�������͂�
 *  �҂��Ă���Ԃ́C���s���s�����^�X�N�����s����Ă���j�C���͂��ꂽ
 *  �����ɑΉ��������������s����D���͂��ꂽ�����Ə����̊֌W�͎��̒ʂ�D
 *  Control-C�܂���'Q'�����͂����ƁC�v���O�������I������D
 *
 *  '1' : �Ώۃ^�X�N��TASK1�ɐ؂芷����i�����ݒ�j�D
 *  '2' : �Ώۃ^�X�N��TASK2�ɐ؂芷����D
 *  '3' : �Ώۃ^�X�N��TASK3�ɐ؂芷����D
 *  'a' : �Ώۃ^�X�N��act_tsk�ɂ��N������D
 *  'A' : �Ώۃ^�X�N�ɑ΂���N���v����can_act�ɂ��L�����Z������D
 *  'e' : �Ώۃ^�X�N��ext_tsk���Ăяo�����C�I��������D
 *  't' : �Ώۃ^�X�N��ter_tsk�ɂ�苭���I������D
 *  '>' : �Ώۃ^�X�N�̗D��x��HIGH_PRIORITY�ɂ���D
 *  '=' : �Ώۃ^�X�N�̗D��x��MID_PRIORITY�ɂ���D
 *  '<' : �Ώۃ^�X�N�̗D��x��LOW_PRIORITY�ɂ���D
 *  'G' : �Ώۃ^�X�N�̗D��x��get_pri�œǂݏo���D
 *  's' : �Ώۃ^�X�N��slp_tsk���Ăяo�����C�N���҂��ɂ�����D
 *  'S' : �Ώۃ^�X�N��tslp_tsk(10�b)���Ăяo�����C�N���҂��ɂ�����D
 *  'w' : �Ώۃ^�X�N��wup_tsk�ɂ��N������D
 *  'W' : �Ώۃ^�X�N�ɑ΂���N���v����can_wup�ɂ��L�����Z������D
 *  'l' : �Ώۃ^�X�N��rel_wai�ɂ�苭���I�ɑ҂������ɂ���D
 *  'u' : �Ώۃ^�X�N��sus_tsk�ɂ�苭���҂���Ԃɂ���D
 *  'm' : �Ώۃ^�X�N�̋����҂���Ԃ�rsm_tsk�ɂ���������D
 *  'd' : �Ώۃ^�X�N��dly_tsk(10�b)���Ăяo�����C���Ԍo�ߑ҂��ɂ�����D
 *  'x' : �Ώۃ^�X�N�ɗ�O�p�^�[��0x0001�̗�O������v������D
 *  'X' : �Ώۃ^�X�N�ɗ�O�p�^�[��0x0002�̗�O������v������D
 *  'y' : �Ώۃ^�X�N��dis_tex���Ăяo�����C�^�X�N��O���֎~����D
 *  'Y' : �Ώۃ^�X�N��ena_tex���Ăяo�����C�^�X�N��O��������D
 *  'r' : 3�̗D��x�iHIGH_PRIORITY�CMID_PRIORITY�CLOW_PRIORITY�j�̃�
 *        �f�B�L���[����]������D
 *  'c' : �����n���h���𓮍�J�n������D
 *  'C' : �����n���h���𓮍��~������D
 *  'b' : �A���[���n���h����5�b��ɋN������悤����J�n������D
 *  'B' : �A���[���n���h���𓮍��~������D
 *  'z' : �Ώۃ^�X�N��CPU��O�𔭐�������i�^�X�N���I��������j�D
 *  'Z' : �Ώۃ^�X�N��CPU���b�N��Ԃ�CPU��O�𔭐�������i�v���O������
 *        �I������j�D
 *  'V' : get_utm�Ő��\�]���p�V�X�e��������2��ǂށD
 *  'v' : ���s�����V�X�e���R�[����\������i�f�t�H���g�j�D
 *  'q' : ���s�����V�X�e���R�[����\�����Ȃ��D
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"

/*
 *  �T�[�r�X�R�[���̃G���[�̃��O�o��
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))

/*
 *  ���s���s�����^�X�N�ւ̃��b�Z�[�W�̈�
 */
char	message[3];

/*
 *  ���[�v��
 */
ulong_t	task_loop;		/* �^�X�N���ł̃��[�v�� */
ulong_t	tex_loop;		/* ��O�������[�`�����ł̃��[�v�� */

/*
 *  ���s���s�����^�X�N
 */
void task(intptr_t exinf)
{
	volatile ulong_t	i;
	int_t		n = 0;
	int_t		tskno = (int_t) exinf;
	const char	*graph[] = { "|", "  +", "    *" };
	char		c;

	SVC_PERROR(ena_tex());
	while (true) {
		syslog(LOG_NOTICE, "task%d is running (%03d).   %s",
										tskno, ++n, graph[tskno-1]);
		for (i = 0; i < task_loop; i++);
		c = message[tskno-1];
		message[tskno-1] = 0;
		switch (c) {
		case 'e':
			syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
			SVC_PERROR(ext_tsk());
			assert(0);
		case 's':
			syslog(LOG_INFO, "#%d#slp_tsk()", tskno);
			SVC_PERROR(slp_tsk());
			break;
		case 'S':
			syslog(LOG_INFO, "#%d#tslp_tsk(10000)", tskno);
			SVC_PERROR(tslp_tsk(10000));
			break;
		case 'd':
			syslog(LOG_INFO, "#%d#dly_tsk(10000)", tskno);
			SVC_PERROR(dly_tsk(10000));
			break;
		case 'y':
			syslog(LOG_INFO, "#%d#dis_tex()", tskno);
			SVC_PERROR(dis_tex());
			break;
		case 'Y':
			syslog(LOG_INFO, "#%d#ena_tex()", tskno);
			SVC_PERROR(ena_tex());
			break;
#ifdef CPUEXC1
		case 'z':
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			break;
		case 'Z':
			SVC_PERROR(loc_cpu());
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			SVC_PERROR(unl_cpu());
			break;
#endif /* CPUEXC1 */
		default:
			break;
		}
	}
}

/*
 *  ���s���Ď��s�����^�X�N�p�̃^�X�N��O�������[�`��
 */
void tex_routine(TEXPTN texptn, intptr_t exinf)
{
	volatile ulong_t	i;
	int_t	tskno = (int_t) exinf;

	syslog(LOG_NOTICE, "task%d receives exception 0x%04x.", tskno, texptn);
	for (i = 0; i < tex_loop; i++);

	if ((texptn & 0x8000U) != 0U) {
		syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
		SVC_PERROR(ext_tsk());
		assert(0);
	}
}

/*
 *  CPU��O�n���h��
 */
#ifdef CPUEXC1

void
cpuexc_handler(void *p_excinf)
{
	ID		tskid;

	syslog(LOG_NOTICE, "CPU exception handler (p_excinf = %08p).", p_excinf);
	if (sns_ctx() != true) {
		syslog(LOG_WARNING,
					"sns_ctx() is not true in CPU exception handler.");
	}
	if (sns_dpn() != true) {
		syslog(LOG_WARNING,
					"sns_dpn() is not true in CPU exception handler.");
	}
	syslog(LOG_INFO, "sns_loc = %d sns_dsp = %d sns_tex = %d",
									sns_loc(), sns_dsp(), sns_tex());
	syslog(LOG_INFO, "xsns_dpn = %d xsns_xpn = %d",
									xsns_dpn(p_excinf), xsns_xpn(p_excinf));

	if (xsns_xpn(p_excinf)) {
		syslog(LOG_NOTICE, "Sample program ends with exception.");
		SVC_PERROR(ext_ker());
		assert(0);
	}

	SVC_PERROR(iget_tid(&tskid));
	SVC_PERROR(iras_tex(tskid, 0x8000U));
}

#endif /* CPUEXC1 */

/*
 *  �����n���h��
 *
 *  HIGH_PRIORITY�CMID_PRIORITY�CLOW_PRIORITY �̊e�D��x�̃��f�B�L���[
 *  ����]������D
 */
void cyclic_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}

/*
 *  �A���[���n���h��
 *
 *  HIGH_PRIORITY�CMID_PRIORITY�CLOW_PRIORITY �̊e�D��x�̃��f�B�L���[
 *  ����]������D
 */
void alarm_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}

/*
 *  ���C���^�X�N
 */
void main_task(intptr_t exinf)
{
	char	c;
	ID		tskid = TASK1;
	int_t	tskno = 1;
	ER_UINT	ercd;
	PRI		tskpri;
#ifndef TASK_LOOP
	volatile ulong_t	i;
	SYSTIM	stime1, stime2;
#endif /* TASK_LOOP */
#ifdef TOPPERS_SUPPORT_GET_UTM
	SYSUTM	utime1, utime2;
#endif /* TOPPERS_SUPPORT_GET_UTM */

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  �V���A���|�[�g�̏�����
	 *
	 *  �V�X�e�����O�^�X�N�Ɠ����V���A���|�[�g���g���ꍇ�ȂǁC�V���A��
	 *  �|�[�g���I�[�v���ς݂̏ꍇ�ɂ͂�����E_OBJ�G���[�ɂȂ邪�C�x���
	 *  �Ȃ��D
	 */
	ercd = serial_opn_por(TASK_PORTID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));

	/*
 	 *  ���[�v�񐔂̐ݒ�
	 *
	 *  ���s���s�����^�X�N���ł̋󃋁[�v�̉񐔁itask_loop�j�́C�󃋁[
	 *  �v�̎��s���Ԃ���0.4�b�ɂȂ�悤�ɐݒ肷��D���̐ݒ�̂��߂ɁC
	 *  LOOP_REF��̋󃋁[�v�̎��s���Ԃ��C���̑O���get_tim���ĂԂ��Ƃ�
	 *  ���肵�C���̑��茋�ʂ���󃋁[�v�̎��s���Ԃ�0.4�b�ɂȂ郋�[�v��
	 *  �������߁Ctask_loop�ɐݒ肷��D
	 *
	 *  LOOP_REF�́C�f�t�H���g�ł�1,000,000�ɐݒ肵�Ă��邪�C�z�肵����
	 *  ��x���v���Z�b�T�ł́C�T���v���v���O�����̎��s�J�n�Ɏ��Ԃ�����
	 *  �肷����Ƃ������𐶂���D�t�ɑz�肵����葬���v���Z�b�T�ł́C
	 *  LOOP_REF��̋󃋁[�v�̎��s���Ԃ��Z���Ȃ�Ctask_loop�ɐݒ肷��l
	 *  �̌덷���傫���Ȃ�Ƃ�����肪����D
	 *
	 *  �����ŁC���̂悤�ȃ^�[�Q�b�g�ł́Ctarget_test.h�ŁCLOOP_REF��K
	 *  �؂Ȓl�ɒ�`����̂��]�܂����D
	 *
	 *  �܂��Ctask_loop�̒l���Œ肵�����ꍇ�ɂ́C���̒l��TASK_LOOP�Ƀ}
	 *  �N����`����DTASK_LOOP���}�N����`����Ă���ꍇ�C��L�̑����
	 *  �s�킸�ɁCTASK_LOOP�ɒ�`���ꂽ�l���󃋁[�v�̉񐔂Ƃ���D
	 *
	 * �^�[�Q�b�g�ɂ���ẮC�󃋁[�v�̎��s���Ԃ�1��ڂ̑���ŁC�{����
	 * ������߂ɂȂ���̂�����D���̂悤�ȃ^�[�Q�b�g�ł́CMEASURE_TWICE
	 * ���}�N����`���邱�ƂŁC1��ڂ̑��茋�ʂ��̂ĂāC2��ڂ̑��茋��
	 * ���g���D
	 *
	 *  �^�X�N��O�������[�`�����ł̋󃋁[�v�̉񐔁itex_loop�j�́C
	 *  task_loop��4����1�̒l�i�󃋁[�v�̎��s���Ԃ�0.1�b�ɂȂ郋�[�v��
	 *  ���j�ɐݒ肷��D
	 */
#ifdef TASK_LOOP
	task_loop = TASK_LOOP;
#else /* TASK_LOOP */

#ifdef MEASURE_TWICE
	task_loop = LOOP_REF;
	SVC_PERROR(get_tim(&stime1));
	for (i = 0; i < task_loop; i++);
	SVC_PERROR(get_tim(&stime2));
#endif /* MEASURE_TWICE */

	task_loop = LOOP_REF;
	SVC_PERROR(get_tim(&stime1));
	for (i = 0; i < task_loop; i++);
	SVC_PERROR(get_tim(&stime2));
	task_loop = LOOP_REF * 400UL / (stime2 - stime1);

#endif /* TASK_LOOP */
	tex_loop = task_loop / 4;

	/*
 	 *  �^�X�N�̋N��
	 */
	SVC_PERROR(act_tsk(TASK1));
	SVC_PERROR(act_tsk(TASK2));
	SVC_PERROR(act_tsk(TASK3));

	/*
 	 *  ���C�����[�v
	 */
	do {
		SVC_PERROR(serial_rea_dat(TASK_PORTID, &c, 1));
		switch (c) {
		case 'e':
		case 's':
		case 'S':
		case 'd':
		case 'y':
		case 'Y':
		case 'z':
		case 'Z':
			message[tskno-1] = c;
			break;
		case '1':
			tskno = 1;
			tskid = TASK1;
			break;
		case '2':
			tskno = 2;
			tskid = TASK2;
			break;
		case '3':
			tskno = 3;
			tskid = TASK3;
			break;
		case 'a':
			syslog(LOG_INFO, "#act_tsk(%d)", tskno);
			SVC_PERROR(act_tsk(tskid));
			break;
		case 'A':
			syslog(LOG_INFO, "#can_act(%d)", tskno);
			SVC_PERROR(ercd = can_act(tskid));
			if (ercd >= 0) {
				syslog(LOG_NOTICE, "can_act(%d) returns %d", tskno, ercd);
			}
			break;
		case 't':
			syslog(LOG_INFO, "#ter_tsk(%d)", tskno);
			SVC_PERROR(ter_tsk(tskid));
			break;
		case '>':
			syslog(LOG_INFO, "#chg_pri(%d, HIGH_PRIORITY)", tskno);
			SVC_PERROR(chg_pri(tskid, HIGH_PRIORITY));
			break;
		case '=':
			syslog(LOG_INFO, "#chg_pri(%d, MID_PRIORITY)", tskno);
			SVC_PERROR(chg_pri(tskid, MID_PRIORITY));
			break;
		case '<':
			syslog(LOG_INFO, "#chg_pri(%d, LOW_PRIORITY)", tskno);
			SVC_PERROR(chg_pri(tskid, LOW_PRIORITY));
			break;
		case 'G':
			syslog(LOG_INFO, "#get_pri(%d, &tskpri)", tskno);
			SVC_PERROR(ercd = get_pri(tskid, &tskpri));
			if (ercd >= 0) {
				syslog(LOG_NOTICE, "priority of task %d is %d", tskno, tskpri);
			}
			break;
		case 'w':
			syslog(LOG_INFO, "#wup_tsk(%d)", tskno);
			SVC_PERROR(wup_tsk(tskid));
			break;
		case 'W':
			syslog(LOG_INFO, "#can_wup(%d)", tskno);
			SVC_PERROR(ercd = can_wup(tskid));
			if (ercd >= 0) {
				syslog(LOG_NOTICE, "can_wup(%d) returns %d", tskno, ercd);
			}
			break;
		case 'l':
			syslog(LOG_INFO, "#rel_wai(%d)", tskno);
			SVC_PERROR(rel_wai(tskid));
			break;
		case 'u':
			syslog(LOG_INFO, "#sus_tsk(%d)", tskno);
			SVC_PERROR(sus_tsk(tskid));
			break;
		case 'm':
			syslog(LOG_INFO, "#rsm_tsk(%d)", tskno);
			SVC_PERROR(rsm_tsk(tskid));
			break;
		case 'x':
			syslog(LOG_INFO, "#ras_tex(%d, 0x0001U)", tskno);
			SVC_PERROR(ras_tex(tskid, 0x0001U));
			break;
		case 'X':
			syslog(LOG_INFO, "#ras_tex(%d, 0x0002U)", tskno);
			SVC_PERROR(ras_tex(tskid, 0x0002U));
			break;
		case 'r':
			syslog(LOG_INFO, "#rot_rdq(three priorities)");
			SVC_PERROR(rot_rdq(HIGH_PRIORITY));
			SVC_PERROR(rot_rdq(MID_PRIORITY));
			SVC_PERROR(rot_rdq(LOW_PRIORITY));
			break;
		case 'c':
			syslog(LOG_INFO, "#sta_cyc(1)");
			SVC_PERROR(sta_cyc(CYCHDR1));
			break;
		case 'C':
			syslog(LOG_INFO, "#stp_cyc(1)");
			SVC_PERROR(stp_cyc(CYCHDR1));
			break;
		case 'b':
			syslog(LOG_INFO, "#sta_alm(1, 5000)");
			SVC_PERROR(sta_alm(ALMHDR1, 5000));
			break;
		case 'B':
			syslog(LOG_INFO, "#stp_alm(1)");
			SVC_PERROR(stp_alm(ALMHDR1));
			break;

		case 'V':
#ifdef TOPPERS_SUPPORT_GET_UTM
			SVC_PERROR(get_utm(&utime1));
			SVC_PERROR(get_utm(&utime2));
			syslog(LOG_NOTICE, "utime1 = %ld, utime2 = %ld",
										(ulong_t) utime1, (ulong_t) utime2);
#else /* TOPPERS_SUPPORT_GET_UTM */
			syslog(LOG_NOTICE, "get_utm is not supported.");
#endif /* TOPPERS_SUPPORT_GET_UTM */
			break;

		case 'v':
			SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO),
										LOG_UPTO(LOG_EMERG)));
			break;
		case 'q':
			SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_NOTICE),
										LOG_UPTO(LOG_EMERG)));
			break;

#ifdef BIT_KERNEL
		case ' ':
			SVC_PERROR(loc_cpu());
			{
				extern ER	bit_kernel(void);

				SVC_PERROR(ercd = bit_kernel());
				if (ercd >= 0) {
					syslog(LOG_NOTICE, "bit_kernel passed.");
				}
			}
			SVC_PERROR(unl_cpu());
			break;
#endif /* BIT_KERNEL */

		default:
			break;
		}
	} while (c != '\003' && c != 'Q');

	syslog(LOG_NOTICE, "Sample program ends.");
	SVC_PERROR(ext_ker());
	assert(0);
}

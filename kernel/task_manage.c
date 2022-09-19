/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: task_manage.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�X�N�Ǘ��@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_ACT_TSK_ENTER
#define LOG_ACT_TSK_ENTER(tskid)
#endif /* LOG_ACT_TSK_ENTER */

#ifndef LOG_ACT_TSK_LEAVE
#define LOG_ACT_TSK_LEAVE(ercd)
#endif /* LOG_ACT_TSK_LEAVE */

#ifndef LOG_IACT_TSK_ENTER
#define LOG_IACT_TSK_ENTER(tskid)
#endif /* LOG_IACT_TSK_ENTER */

#ifndef LOG_IACT_TSK_LEAVE
#define LOG_IACT_TSK_LEAVE(ercd)
#endif /* LOG_IACT_TSK_LEAVE */

#ifndef LOG_CAN_ACT_ENTER
#define LOG_CAN_ACT_ENTER(tskid)
#endif /* LOG_CAN_ACT_ENTER */

#ifndef LOG_CAN_ACT_LEAVE
#define LOG_CAN_ACT_LEAVE(ercd)
#endif /* LOG_CAN_ACT_LEAVE */

#ifndef LOG_EXT_TSK_ENTER
#define LOG_EXT_TSK_ENTER()
#endif /* LOG_EXT_TSK_ENTER */

#ifndef LOG_EXT_TSK_LEAVE
#define LOG_EXT_TSK_LEAVE(ercd)
#endif /* LOG_EXT_TSK_LEAVE */

#ifndef LOG_TER_TSK_ENTER
#define LOG_TER_TSK_ENTER(tskid)
#endif /* LOG_TER_TSK_ENTER */

#ifndef LOG_TER_TSK_LEAVE
#define LOG_TER_TSK_LEAVE(ercd)
#endif /* LOG_TER_TSK_LEAVE */

#ifndef LOG_CHG_PRI_ENTER
#define LOG_CHG_PRI_ENTER(tskid, tskpri)
#endif /* LOG_CHG_PRI_ENTER */

#ifndef LOG_CHG_PRI_LEAVE
#define LOG_CHG_PRI_LEAVE(ercd)
#endif /* LOG_CHG_PRI_LEAVE */

#ifndef LOG_GET_PRI_ENTER
#define LOG_GET_PRI_ENTER(tskid, p_tskpri)
#endif /* LOG_GET_PRI_ENTER */

#ifndef LOG_GET_PRI_LEAVE
#define LOG_GET_PRI_LEAVE(ercd, tskpri)
#endif /* LOG_GET_PRI_LEAVE */

#ifndef LOG_GET_INF_ENTER
#define LOG_GET_INF_ENTER(p_exinf)
#endif /* LOG_GET_INF_ENTER */

#ifndef LOG_GET_INF_LEAVE
#define LOG_GET_INF_LEAVE(ercd, exinf)
#endif /* LOG_GET_INF_LEAVE */

/*
 *  �^�X�N�̋N��
 */
#ifdef TOPPERS_act_tsk

ER
act_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_ACT_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		if (make_active(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->actque)) {
		p_tcb->actque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	t_unlock_cpu();

  error_exit:
	LOG_ACT_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_act_tsk */

/*
 *  �^�X�N�̋N���i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_iact_tsk

ER
iact_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IACT_TSK_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		if (make_active(p_tcb)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->actque)) {
		p_tcb->actque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IACT_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iact_tsk */

/*
 *  �^�X�N�N���v���̃L�����Z��
 */
#ifdef TOPPERS_can_act

ER_UINT
can_act(ID tskid)
{
	TCB		*p_tcb;
	ER_UINT	ercd;

	LOG_CAN_ACT_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	ercd = p_tcb->actque ? 1 : 0;
	p_tcb->actque = false;
	t_unlock_cpu();

  error_exit:
	LOG_CAN_ACT_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_can_act */

/*
 *  ���^�X�N�̏I��
 */
#ifdef TOPPERS_ext_tsk

ER
ext_tsk(void)
{
	ER		ercd;

	LOG_EXT_TSK_ENTER();
	CHECK_TSKCTX();

	if (t_sense_lock()) {
		/*
		 *  CPU���b�N��Ԃ�ext_tsk���Ă΂ꂽ�ꍇ�́CCPU���b�N��������
		 *  �Ă���^�X�N���I������D������́C�T�[�r�X�R�[�����ł�CPU
		 *  ���b�N���ȗ�����΂悢�����D
		 */
	}
	else {
		t_lock_cpu();
	}
	if (disdsp) {
		/*
		 *  �f�B�X�p�b�`�֎~��Ԃ�ext_tsk���Ă΂ꂽ�ꍇ�́C�f�B�X�p�b
		 *  �`����Ԃɂ��Ă���^�X�N���I������D
		 */
		disdsp = false;
	}
	if (!ipmflg) {
		/*
		 *  �����ݗD��x�}�X�N�iIPM�j��TIPM_ENAALL�ȊO�̏�Ԃ�ext_tsk
		 *  ���Ă΂ꂽ�ꍇ�́CIPM��TIPM_ENAALL�ɂ��Ă���^�X�N���I����
		 *  ��D
		 */
		t_set_ipm(TIPM_ENAALL);
		ipmflg = true;
	}
	dspflg = true;

	(void) make_non_runnable(p_runtsk);
	make_dormant(p_runtsk);
	if (p_runtsk->actque) {
		p_runtsk->actque = false;
		(void) make_active(p_runtsk);
	}
	exit_and_dispatch();
	ercd = E_SYS;

  error_exit:
	LOG_EXT_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ext_tsk */

/*
 *  �^�X�N�̋����I��
 */
#ifdef TOPPERS_ter_tsk

ER
ter_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_TER_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);
	CHECK_NONSELF(p_tcb);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (TSTAT_RUNNABLE(p_tcb->tstat)) {
			/*
			 *  p_tcb�͎��^�X�N�łȂ����߁C�i�V���O���v���Z�b�T�ł́j��
			 *  �s��ԂłȂ��Cmake_non_runnable(p_tcb)�Ń^�X�N�f�B�X�p�b
			 *  �`���K�v�ɂȂ邱�Ƃ͂Ȃ��D
			 */
			(void) make_non_runnable(p_tcb);
		}
		else if (TSTAT_WAITING(p_tcb->tstat)) {
			wait_dequeue_wobj(p_tcb);
			wait_dequeue_tmevtb(p_tcb);
		}
		make_dormant(p_tcb);
		if (p_tcb->actque) {
			p_tcb->actque = false;
			if (make_active(p_tcb)) {
				dispatch();
			}
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TER_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ter_tsk */

/*
 *  �^�X�N�̃x�[�X�D��x�̕ύX
 */
#ifdef TOPPERS_chg_pri

ER
chg_pri(ID tskid, PRI tskpri)
{
	TCB		*p_tcb;
	uint_t	newpri;
	ER		ercd;

	LOG_CHG_PRI_ENTER(tskid, tskpri);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	CHECK_TPRI_INI(tskpri);
	p_tcb = get_tcb_self(tskid);
	newpri = (tskpri == TPRI_INI) ? p_tcb->p_tinib->ipriority
										: INT_PRIORITY(tskpri);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (change_priority(p_tcb, newpri)) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_CHG_PRI_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_chg_pri */

/*
 *  �^�X�N�D��x�̎Q��
 */
#ifdef TOPPERS_get_pri

ER
get_pri(ID tskid, PRI *p_tskpri)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_GET_PRI_ENTER(tskid, p_tskpri);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		*p_tskpri = EXT_TSKPRI(p_tcb->priority);
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_GET_PRI_LEAVE(ercd, *p_tskpri);
	return(ercd);
}

#endif /* TOPPERS_get_pri */

/*
 *  ���^�X�N�̊g�����̎Q��
 */
#ifdef TOPPERS_get_inf

ER
get_inf(intptr_t *p_exinf)
{
	ER		ercd;

	LOG_GET_INF_ENTER(p_exinf);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_exinf = p_runtsk->p_tinib->exinf;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_GET_INF_LEAVE(ercd, *p_exinf);
	return(ercd);
}

#endif /* TOPPERS_get_inf */

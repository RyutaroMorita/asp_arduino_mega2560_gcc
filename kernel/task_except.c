/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
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
 *  $Id: task_except.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�X�N��O�����@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_RAS_TEX_ENTER
#define LOG_RAS_TEX_ENTER(tskid, rasptn)
#endif /* LOG_RAS_TEX_ENTER */

#ifndef LOG_RAS_TEX_LEAVE
#define LOG_RAS_TEX_LEAVE(ercd)
#endif /* LOG_RAS_TEX_LEAVE */

#ifndef LOG_IRAS_TEX_ENTER
#define LOG_IRAS_TEX_ENTER(tskid, rasptn)
#endif /* LOG_IRAS_TEX_ENTER */

#ifndef LOG_IRAS_TEX_LEAVE
#define LOG_IRAS_TEX_LEAVE(ercd)
#endif /* LOG_IRAS_TEX_LEAVE */

#ifndef LOG_DIS_TEX_ENTER
#define LOG_DIS_TEX_ENTER()
#endif /* LOG_DIS_TEX_ENTER */

#ifndef LOG_DIS_TEX_LEAVE
#define LOG_DIS_TEX_LEAVE(ercd)
#endif /* LOG_DIS_TEX_LEAVE */

#ifndef LOG_ENA_TEX_ENTER
#define LOG_ENA_TEX_ENTER()
#endif /* LOG_ENA_TEX_ENTER */

#ifndef LOG_ENA_TEX_LEAVE
#define LOG_ENA_TEX_LEAVE(ercd)
#endif /* LOG_ENA_TEX_LEAVE */

#ifndef LOG_SNS_TEX_ENTER
#define LOG_SNS_TEX_ENTER()
#endif /* LOG_SNS_TEX_ENTER */

#ifndef LOG_SNS_TEX_LEAVE
#define LOG_SNS_TEX_LEAVE(state)
#endif /* LOG_SNS_TEX_LEAVE */

#ifndef LOG_REF_TEX_ENTER
#define LOG_REF_TEX_ENTER(tskid, pk_rtex)
#endif /* LOG_REF_TEX_ENTER */

#ifndef LOG_REF_TEX_LEAVE
#define LOG_REF_TEX_LEAVE(ercd, pk_rtex)
#endif /* LOG_REF_TEX_LEAVE */

/*
 *  �^�X�N��O�����̗v��
 */
#ifdef TOPPERS_ras_tex

ER
ras_tex(ID tskid, TEXPTN rasptn)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_RAS_TEX_ENTER(tskid, rasptn);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	CHECK_PAR(rasptn != 0U);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_tcb->texptn |= rasptn;
		if (p_tcb == p_runtsk && p_runtsk->enatex && ipmflg) {
			call_texrtn();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_RAS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ras_tex */

/*
 *  �^�X�N��O�����̗v���i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_iras_tex

ER
iras_tex(ID tskid, TEXPTN rasptn)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IRAS_TEX_ENTER(tskid, rasptn);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	CHECK_PAR(rasptn != 0U);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_tcb->texptn |= rasptn;
		if (p_tcb == p_runtsk && p_runtsk->enatex && ipmflg) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IRAS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iras_tex */

/*
 *  �^�X�N��O�����̋֎~
 */
#ifdef TOPPERS_dis_tex

ER
dis_tex(void)
{
	ER		ercd;

	LOG_DIS_TEX_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	if (p_runtsk->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_runtsk->enatex = false;
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_DIS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_dis_tex */

/*
 *  �^�X�N��O�����̋���
 */
#ifdef TOPPERS_ena_tex

ER
ena_tex(void)
{
	ER		ercd;

	LOG_ENA_TEX_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	if (p_runtsk->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_runtsk->enatex = true;
		if (p_runtsk->texptn != 0U && ipmflg) {
			call_texrtn();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_ENA_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ena_tex */

/*
 *  �^�X�N��O�����֎~��Ԃ̎Q��
 */
#ifdef TOPPERS_sns_tex

bool_t
sns_tex(void)
{
	bool_t	state;

	LOG_SNS_TEX_ENTER();
	state = (p_runtsk != NULL && p_runtsk->enatex) ? false : true;
	LOG_SNS_TEX_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_tex */

/*
 *  �^�X�N��O�����̏�ԎQ��
 */
#ifdef TOPPERS_ref_tex

ER
ref_tex(ID tskid, T_RTEX *pk_rtex)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_REF_TEX_ENTER(tskid, pk_rtex);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		pk_rtex->texstat = (p_tcb->enatex) ? TTEX_ENA : TTEX_DIS;
		pk_rtex->pndptn = p_tcb->texptn;
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_REF_TEX_LEAVE(ercd, pk_rtex);
	return(ercd);
}

#endif /* TOPPERS_ref_tex */

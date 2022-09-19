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
 *  $Id: time_manage.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�V�X�e�������Ǘ��@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "time_event.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_GET_TIM_ENTER
#define LOG_GET_TIM_ENTER(p_systim)
#endif /* LOG_GET_TIM_ENTER */

#ifndef LOG_GET_TIM_LEAVE
#define LOG_GET_TIM_LEAVE(ercd, systim)
#endif /* LOG_GET_TIM_LEAVE */

#ifndef LOG_GET_UTM_ENTER
#define LOG_GET_UTM_ENTER(p_sysutm)
#endif /* LOG_GET_UTM_ENTER */

#ifndef LOG_GET_UTM_LEAVE
#define LOG_GET_UTM_LEAVE(ercd, sysutm)
#endif /* LOG_GET_UTM_LEAVE */

/*
 *  �V�X�e�������̎Q��
 */
#ifdef TOPPERS_get_tim

ER
get_tim(SYSTIM *p_systim)
{
	ER		ercd;

	LOG_GET_TIM_ENTER(p_systim);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_systim = current_time;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_GET_TIM_LEAVE(ercd, *p_systim);
	return(ercd);
}

#endif /* TOPPERS_get_tim */

/*
 *  ���\�]���p�V�X�e�������̎Q��
 */
#ifdef TOPPERS_get_utm
#ifdef TOPPERS_SUPPORT_GET_UTM
#ifndef OMIT_GET_UTM
#include "target_timer.h"

ER
get_utm(SYSUTM *p_sysutm)
{
	SYSUTM	utime;
	SYSTIM	time;
#if TIC_DENO != 1
	uint_t	subtime;
#endif /* TIC_DENO != 1 */
	CLOCK	clock1, clock2;
	bool_t	ireq;
	SIL_PRE_LOC;

	LOG_GET_UTM_ENTER(p_sysutm);

	SIL_LOC_INT();
	time = next_time;
#if TIC_DENO != 1
	subtime = next_subtime;
#endif /* TIC_DENO != 1 */
	clock1 = target_timer_get_current();
	ireq = target_timer_probe_int();
	clock2 = target_timer_get_current();
	SIL_UNL_INT();

	utime = ((SYSUTM) time) * 1000U;
#if TIC_DENO != 1
	utime += subtime * 1000U / TIC_DENO;
#endif /* TIC_DENO != 1 */

	if (!ireq || clock1 > clock2) {
		utime -= TIC_NUME * 1000U / TIC_DENO;
	}
	utime += TO_USEC(clock1);
	*p_sysutm = utime;

	LOG_GET_UTM_LEAVE(E_OK, *p_sysutm);
	return(E_OK);
}

#endif /* OMIT_GET_UTM */
#endif /* TOPPERS_SUPPORT_GET_UTM */
#endif /* TOPPERS_get_utm */

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
 *  @(#) $Id: exception.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		CPU��O�Ǘ��@�\
 */

#include "kernel_impl.h"
#include "task.h"
#include "exception.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_XSNS_DPN_ENTER
#define LOG_XSNS_DPN_ENTER(p_excinf)
#endif /* LOG_XSNS_DPN_ENTER */

#ifndef LOG_XSNS_DPN_LEAVE
#define LOG_XSNS_DPN_LEAVE(state)
#endif /* LOG_XSNS_DPN_LEAVE */

#ifndef LOG_XSNS_XPN_ENTER
#define LOG_XSNS_XPN_ENTER(p_excinf)
#endif /* LOG_XSNS_XPN_ENTER */

#ifndef LOG_XSNS_XPN_LEAVE
#define LOG_XSNS_XPN_LEAVE(state)
#endif /* LOG_XSNS_XPN_LEAVE */

/*
 *  CPU��O�n���h���Ǘ��@�\�̏�����
 */
#ifdef TOPPERS_excini
#ifndef OMIT_INITIALIZE_EXCEPTION

void
initialize_exception(void)
{
	uint_t			i;
	const EXCINIB	*p_excinib;

	for (i = 0; i < tnum_excno; i++) {
		p_excinib = &(excinib_table[i]);
		x_define_exc(p_excinib->excno, p_excinib->exc_entry);
	}
}

#endif /* OMIT_INITIALIZE_EXCEPTION */
#endif /* TOPPERS_excini */

/*
 *  CPU��O�̔��������R���e�L�X�g�̎Q��
 */

/*
 *  CPU��O�������̃f�B�X�p�b�`�ۗ���Ԃ̎Q��
 *
 *  CPU��O�n���h������disdsp���ω����邱�Ƃ͂Ȃ����߁CCPU��O��������
 *  ������disdsp��ۑ����Ă����K�v�͂Ȃ��D
 */
#ifdef TOPPERS_xsns_dpn

bool_t
xsns_dpn(void *p_excinf)
{
	bool_t	state;

	LOG_XSNS_DPN_ENTER(p_excinf);
	state = (kerflg && exc_sense_intmask(p_excinf)
									&& !disdsp) ? false : true;
	LOG_XSNS_DPN_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_xsns_dpn */

/*
 *  CPU��O�������̃^�X�N��O�����ۗ���Ԃ̎Q��
 *
 *  CPU��O�n���h������p_runtsk��p_runtsk->enatex���ω����邱�Ƃ͂Ȃ�
 *  ���߁CCPU��O��������������p_runtsk->enatex��ۑ����Ă����K�v�͂�
 *  ���D
 */
#ifdef TOPPERS_xsns_xpn

bool_t
xsns_xpn(void *p_excinf)
{
	bool_t	state;

	LOG_XSNS_XPN_ENTER(p_excinf);
	state = (kerflg && exc_sense_intmask(p_excinf)
									&& p_runtsk->enatex) ? false : true;
	LOG_XSNS_XPN_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_xsns_xpn */

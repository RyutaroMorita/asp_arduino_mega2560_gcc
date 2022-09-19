/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: startup.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�J�[�l���̏������ƏI������
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_KER_ENTER
#define LOG_KER_ENTER()
#endif /* LOG_KER_ENTER */

#ifndef LOG_KER_LEAVE
#define LOG_KER_LEAVE()
#endif /* LOG_KER_LEAVE */

#ifndef LOG_EXT_KER_ENTER
#define LOG_EXT_KER_ENTER()
#endif /* LOG_EXT_KER_ENTER */

#ifndef LOG_EXT_KER_LEAVE
#define LOG_EXT_KER_LEAVE(ercd)
#endif /* LOG_EXT_KER_LEAVE */

#ifdef TOPPERS_sta_ker

/*
 *  �J�[�l�������ԃt���O
 *
 *  �X�^�[�g�A�b�v���[�`���ŁCfalse�i��0�j�ɏ���������邱�Ƃ����҂���
 *  ����D
 */
bool_t	kerflg = false;

/*
 *  �J�[�l���̋N��
 */
void
sta_ker(void)
{
	/*
	 *  �^�[�Q�b�g�ˑ��̏�����
	 */
	target_initialize();

	/*
	 *  �e���W���[���̏�����
	 *
	 *  �^�C���C�x���g�Ǘ����W���[���͑��̃��W���[������ɏ�����
	 *  ����K�v������D
	 */
	initialize_tmevt();
	initialize_object();

	/*
	 *  ���������[�`���̎��s
	 */ 
	call_inirtn();

	/*
	 *  �J�[�l������̊J�n
	 */
	kerflg = true;
	LOG_KER_ENTER();
	start_dispatch();
	assert(0);
}

#endif /* TOPPERS_sta_ker */

/*
 *  �J�[�l���̏I��
 */
#ifdef TOPPERS_ext_ker

ER
ext_ker(void)
{
	SIL_PRE_LOC;

	LOG_EXT_KER_ENTER();

	/*
	 *  �����݃��b�N��ԂɈڍs
	 */
	SIL_LOC_INT();

	/*
	 *  �J�[�l������̏I��
	 */
	LOG_KER_LEAVE();
	kerflg = false;

	/*
	 *  �J�[�l���̏I�������̌ďo��
	 *
	 *  ��^�X�N�R���e�L�X�g�ɐ؂芷���āCexit_kernel���Ăяo���D
	 */
	call_exit_kernel();

	/*
	 *  �R���p�C���̌x���΍�i�����֗��邱�Ƃ͂Ȃ��͂��j
	 */
	SIL_UNL_INT();
	LOG_EXT_KER_LEAVE(E_SYS);
	return(E_SYS);
}

/*
 *  �J�[�l���̏I������
 */
void
exit_kernel(void)
{
	/*
	 *  �I���������[�`���̎��s
	 */
	call_terrtn();

	/*
	 *  �^�[�Q�b�g�ˑ��̏I������
	 */
	target_exit();
	assert(0);
}

#endif /* TOPPERS_ext_ker */

/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2005-2013 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: test_lib.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/* 
 *		�e�X�g�v���O�����p���C�u����
 */

#ifndef TOPPERS_TEST_LIB_H
#define TOPPERS_TEST_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <t_stddef.h>

/*
 *  �^�[�Q�b�g�ˑ��̒�`
 */
#include "target_test.h"

/*
 *	���Ȑf�f�֐��̌^
 */
typedef ER (*BIT_FUNC)(void);

/*
 *	���Ȑf�f�֐��̐ݒ�
 */
extern void	set_bit_func(BIT_FUNC bit_func);

/*
 *  �e�X�g�v���O�����̊J�n
 */
extern void	test_start(char *progname);

/*
 *  �V�X�e�����O�̏o�͏���
 */
extern void	syslog_flush(void);

/*
 *	�e�X�g�v���O�����̏I��
 */
extern void	test_finish(void);

/*
 *	�`�F�b�N�|�C���g
 */
extern void	check_point(uint_t count);

/*
 *	�����`�F�b�N�|�C���g
 */
extern void	check_finish(uint_t count);

/*
 *	�����`�F�b�N
 */
extern void	_check_assert(const char *expr, const char *file, int_t line);
#define check_assert(exp) \
	((void)(!(exp) ? (_check_assert(#exp, __FILE__, __LINE__), 0) : 0))

/*
 *	�G���[�R�[�h�`�F�b�N
 */
extern void	_check_ercd(ER ercd, const char *file, int_t line);
#define check_ercd(ercd, expected_ercd) \
	((void)((ercd) != (expected_ercd) ? \
					(_check_ercd(ercd, __FILE__, __LINE__), 0) : 0))

/*
 *	�V�X�e����Ԃ̃`�F�b�N
 */
Inline void
check_state(bool_t ctx, bool_t loc, PRI ipm, bool_t dsp,
										bool_t dpn, bool_t tex)
{
	PRI		intpri;
	ER		ercd;

	check_assert(sns_ctx() == ctx);
	check_assert(sns_loc() == loc);
	if (!loc) {
		/*
		 *  IPM�̃`�F�b�N�́CCPU���b�N������Ԃ̏ꍇ�ɂ̂ݍs���D
		 */
		ercd = get_ipm(&intpri);
		check_ercd(ercd, E_OK);
		check_assert(intpri == ipm);
	}
	check_assert(sns_dsp() == dsp);
	check_assert(sns_dpn() == dpn);
	check_assert(sns_tex() == tex);
}

/*
 *	�V�X�e����Ԃ̃`�F�b�N�i��^�X�N�R���e�L�X�g�p�j
 */
Inline void
check_state_i(bool_t ctx, bool_t loc, bool_t dsp, bool_t dpn, bool_t tex)
{
	check_assert(sns_ctx() == ctx);
	check_assert(sns_loc() == loc);
	check_assert(sns_dsp() == dsp);
	check_assert(sns_dpn() == dpn);
	check_assert(sns_tex() == tex);
}

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_TEST_LIB_H */

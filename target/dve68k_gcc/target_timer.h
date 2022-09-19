/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: target_timer.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�C�}�h���C�o�iDVE68K/40�p�j
 */

#ifndef TOPPERS_TARGET_TIMER_H
#define TOPPERS_TARGET_TIMER_H

#include <sil.h>
#include "dve68k.h"

/*
 *  �^�C�}�����݃n���h���o�^�̂��߂̒萔
 */
#define INHNO_TIMER		TINHNO_TT0		/* �����݃n���h���ԍ� */
#define INTNO_TIMER		TINTNO_TT0		/* �����ݔԍ� */
#define INTPRI_TIMER	TIRQ_LEVEL4		/* �����ݗD��x */
#define INTATR_TIMER	TA_EDGE			/* �����ݑ��� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef uint32_t	CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 *  DVE68K/40�ł́C�^�C�}��1�ʕb���ɃJ�E���g�A�b�v����D
 */
#define TIMER_CLOCK				1000U
#define TO_CLOCK(nume, deno)	((CLOCK)(TIMER_CLOCK * (nume) / (deno)))
#define TO_USEC(clock)			(((SYSUTM) clock) * 1000U / TIMER_CLOCK)

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK		((CLOCK) 0xffffffU)

/*
 *  �^�C�}��~�܂ł̎��ԁinsec�P�ʁj
 *
 *  �l�ɍ����͂Ȃ��D
 */
#define TIMER_STOP_DELAY	200U

/*
 *  ���W�X�^�̐ݒ�l
 */
#define CSR12_START		0x80000000U		/* �^�C�}���� */
#define CSR12_STOP		0x00000000U		/* �^�C�}��~ */

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
extern void	target_timer_initialize(intptr_t exinf);

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
extern void	target_timer_terminate(intptr_t exinf);

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
target_timer_get_current(void)
{
	CLOCK		clk;
	uint32_t	saved_csr12;
	SIL_PRE_LOC;

	/*
	 *  �^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D�^�C�}�̓���
	 *  ���ꎞ�I�ɒ�~������ƁC�V�X�e������������邽�߂ɖ]�܂����Ȃ�
	 *  ���CDVE68K/40�̃n�[�h�E�F�A�I�Ȑ���ł���C��ނ����Ȃ��D�����
	 *  �ŏ��ɗ}���邽�߂ɁC�����݃��b�N��ԂƂ���D
	 */
	SIL_LOC_INT();
	saved_csr12 = dga_read((void *) TADR_DGA_CSR12);
	dga_write((void *) TADR_DGA_CSR12, CSR12_STOP);
	sil_dly_nse(TIMER_STOP_DELAY);
	clk = dga_read((void *) TADR_DGA_CSR13) & 0x00ffffffU;
	dga_write((void *) TADR_DGA_CSR12, saved_csr12);
	SIL_UNL_INT();
	return(clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline bool_t
target_timer_probe_int(void)
{
	return(x_probe_int(INTNO_TIMER));
}

/*
 *  �^�C�}�����݃n���h��
 */
extern void	target_timer_handler(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_TIMER_H */

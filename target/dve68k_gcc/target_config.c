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
 *  @(#) $Id: target_config.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�[�Q�b�g�ˑ����W���[���iDVE68K/40�p�j
 */

#include "kernel_impl.h"
#include <sil.h>

/*
 *  �v���Z�b�T���ʂ̂��߂̕ϐ��i�}���`�v���Z�b�T�Ή��j
 */
uint_t	board_id;			/* �{�[�hID */
void	*board_addr;		/* ���[�J���������̐擪�A�h���X */

/*
 *  �^�[�Q�b�g�ˑ��̏�����
 */
void
target_initialize(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏�����
	 */
	prc_initialize();

	/*
	 *  �v���Z�b�T���ʂ̂��߂̕ϐ��̏�����
	 */
	board_id = ((uint_t)(sil_rew_mem((void *) TADR_BOARD_REG0)) & 0x1fU);
	board_addr = (void *)(board_id << 24);

	/*
	 *  �����݊֘A�̏�����
	 *
	 *  �����ݑ������ݒ肳��Ă��邩�𔻕ʂ��邽�߂̕ϐ�������������D
	 *  �܂��C���ׂĂ̊����݂��}�X�N�E�N���A���C�����݃x�N�g����ݒ肷
	 *  ��D
	 */
	dga_write((void *) TADR_DGA_CSR21, 0U);
	dga_write((void *) TADR_DGA_CSR23, ~0U);
	dga_write((void *) TADR_DGA_CSR19, (TVEC_G0I << 24) | (TVEC_G1I << 16)
										| (TVEC_SWI << 8) | TVEC_SPRI);

	/*
	 *  �A�{�[�g�����݂̐ݒ�iNMI�j
	 *
	 *  �A�{�[�g�����݂��G�b�W�g���K�C�����݃��x����NMI�ɐݒ肵�C�}�X�N
	 *  ����������D
	 */
	x_config_int(TINTNO_ABT, TA_EDGE, TIRQ_NMI);

	/*
	 *  �������̈�̐ݒ�
	 *
	 *  ���[�J����������VME�o�X��ł̐擪�A�h���X�ƃT�C�Y�i16MB�j���C�A
	 *  �N�Z�X���󂯕t����悤�ɐݒ肷��D�܂��CVME�o�X����g���A�h���X
	 *  �A�N�Z�X���󂯕t����悤�ɂɐݒ肷��D
	 */
	dga_write((void *) TADR_DGA_CSR4, (uint32_t) board_addr | 0x00ffU);
	dga_write((void *) TADR_DGA_CSR5, 0x0000012fU);

	/*
	 *  �C���^�t�F�[�X���W�X�^�iIFR�j�̐ݒ�
	 *
	 *  �C���^�t�F�[�X���W�X�^�̃x�[�X�A�h���X��ݒ肷��D�܂��C�C���^
	 *  �t�F�[�X���W�X�^0�̃T�[�r�X���N�G�X�g�t���O���N���A�D�C���^�t�F�[
	 *  �X���W�X�^3�Ƀ{�[�h��ID�ԍ���ݒ�D
	 */
	dga_write((void *) TADR_DGA_CSR3, (board_id << 4) | 0x3U);
	dga_write((void *) TADR_DGA_IFR0, 0x80000000U);
	dga_write((void *) TADR_DGA_IFR3, board_id);

	/*
	 *  ���E���h���r�����[�h�ɐݒ�i�}���`�v���Z�b�T�Ή��j
	 */
	dga_write((void *) TADR_DGA_CSR1,
						(dga_read((void *) TADR_DGA_CSR1) & 0xffeffcffU)
									| (1U << 20) | ((board_id % 4) << 8));
}

/*
 *  �^�[�Q�b�g�ˑ��̏I������
 */
void
target_exit(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏I������
	 */
	prc_terminate();

	/*
	 *  ���ׂĂ̊����݂��}�X�N�E�N���A����D
	 */
	dga_write((void *) TADR_DGA_CSR21, 0U);
	dga_write((void *) TADR_DGA_CSR23, ~0U);

	/*
	 *  �J�����ˑ��̏I������
	 */
	dve68k_exit();
}

/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void
target_fput_log(char c)
{
	if (c == '\n') {
		dve68k_putc('\r');
	}
	dve68k_putc(c);
}

/*
 *  �����ݗv�����C���̑����̐ݒ�
 *
 *  ASP�J�[�l���ł̗��p��z�肵�āC�p�����[�^�G���[�̓A�T�[�V�����Ń`�F�b
 *  �N���Ă���Dcfg_int�T�[�r�X�R�[����݂���ꍇ�ɂ́C�G���[��Ԃ��悤
 *  �ɂ��ׂ��ł��낤�D
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	uint32_t	bitpat = DGA_INT_BITPAT(intno);

	assert(VALID_INTNO_CFGINT(intno));
	assert(TIRQ_NMI <= intpri && intpri <= TIRQ_LEVEL1);

	/*
	 *  �����݂̃}�X�N
	 *
	 *  �����݂��󂯕t�����܂܁C���x���g���K�^�G�b�W�g���K�̐ݒ��C��
	 *  ���ݗD��x�̐ݒ���s���̂͊댯�Ȃ��߁C�����ݑ����ɂ�����炸�C
	 *  ��U�}�X�N����D
	 */
	(void) x_disable_int(intno);

	/*
	 *  ���x���g���K�^�G�b�W�g���K�̐ݒ�
	 */
	if ((bitpat & DGA_INT_TRG_CONF) != 0U) {
		/*
		 *  ������ɂ��ݒ�ł���ꍇ
		 */
		if ((intatr & TA_EDGE) != 0U) {
			dga_bit_or((void *) TADR_DGA_CSR18, (1U << (24 - (intno))));
			x_clear_int(intno);
		}
		else {
			dga_bit_and((void *) TADR_DGA_CSR18, ~(1U << (24 - (intno))));
		}
	}
	else if ((bitpat & DGA_INT_TRG_EDGE) != 0U) {
		/*
		 *  �G�b�W�g���K�ɌŒ肳��Ă���ꍇ
		 */
		assert((intatr & TA_EDGE) != 0U);
		x_clear_int(intno);
	}
	else {
		/*
		 *  ���x���g���K�ɌŒ肳��Ă���ꍇ
		 */
		assert((intatr & TA_EDGE) == 0U);
	}

	/*
	 *  �����ݗD��x�̐ݒ�
	 */
	dga_set_ilv((void *)(TADR_DGA_CSR24 + (intno - 1) / 8 * 4),
				(uint_t)(((32 - intno) % 8) * 4), (uint_t)(7 + intpri));

	/*
	 *  �����݂̃}�X�N�����i�K�v�ȏꍇ�j
 	 */
	if ((intatr & TA_ENAINT) != 0U) {
		(void) x_enable_int(intno);
	}
}

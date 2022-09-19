/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_sil.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		sil.h�̃v���Z�b�T�ˑ����iM68040�p�j
 */

#ifndef TOPPERS_PRC_SIL_H
#define TOPPERS_PRC_SIL_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  NMI���������ׂĂ̊����݂̋֎~
 */
Inline uint16_t
TOPPERS_disint(void)
{
	uint16_t	TOPPERS_sr;

	Asm("move.w %%sr, %0" : "=g"(TOPPERS_sr));
	Asm("or.w #0x0700, %%sr" : : : "memory");
	return(TOPPERS_sr & 0x0700U);
}

/*
 *  �����ݗD��x�}�X�N�i�����\���j�̌��ݒl�̐ݒ�
 */
Inline void
TOPPERS_set_iipm(uint16_t TOPPERS_iipm)
{
	uint16_t	TOPPERS_sr;

	Asm("move.w %%sr, %0" : "=g"(TOPPERS_sr));
	Asm("move.w %0, %%sr" : : "g"((TOPPERS_sr & ~0x0700U) | TOPPERS_iipm)
							: "memory");
}

/*
 *  �S�����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC		uint16_t TOPPERS_iipm
#define SIL_LOC_INT()	((void)(TOPPERS_iipm = TOPPERS_disint()))
#define SIL_UNL_INT()	(TOPPERS_set_iipm(TOPPERS_iipm))

/*
 *  �������ԑ҂�
 */
Inline void
sil_dly_nse(ulong_t dlytim)
{
	register uint32_t d0 asm("d0") = (uint32_t) dlytim;
	Asm("jsr _sil_dly_nse" : "=g"(d0) : "0"(d0));
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN_BIG				/* �r�b�O�G���f�B�A�� */

#endif /* TOPPERS_PRC_SIL_H */

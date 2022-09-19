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
 *  @(#) $Id: dve68k.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		DVE-68K/40 CPU�{�[�h�̃n�[�h�E�F�A�����̒�`
 */

#ifndef TOPPERS_DVE68K_H
#define TOPPERS_DVE68K_H

#include <sil.h>

/*
 *  �����ݔԍ��iintno�j�̒�`
 */
#define TINTNO_ACF		1U			/* ACFAIL������ */
#define TINTNO_ABT		2U			/* �A�{�[�g������ */
#define TINTNO_SF		3U			/* SYSFAIL������ */
#define TINTNO_BER		4U			/* �o�X�G���[������ */
#define TINTNO_IAK		5U			/* IAK������ */
#define TINTNO_SRQ		6U			/* SRQ������ */
#define TINTNO_SAK		7U			/* SAK������ */
#define TINTNO_GP7		9U			/* GP7������ */
#define TINTNO_DMA		10U			/* DMA������ */
#define TINTNO_TT1		11U			/* �^�C�}1������ */
#define TINTNO_TT0		12U			/* �^�C�}0������ */
#define TINTNO_GP3		13U			/* �t���b�V�������������� */
#define TINTNO_GP2		14U			/* SCSI������ */
#define TINTNO_GP1		15U			/* Ethernet������ */
#define TINTNO_GP0		16U			/* �V���A��I/O������ */
#define TINTNO_SWI7		17U			/* �\�t�g�E�F�A������7 */
#define TINTNO_SWI6		18U			/* �\�t�g�E�F�A������6 */
#define TINTNO_SWI5		19U			/* �\�t�g�E�F�A������5 */
#define TINTNO_SWI4		20U			/* �\�t�g�E�F�A������4 */
#define TINTNO_SWI3		21U			/* �\�t�g�E�F�A������3 */
#define TINTNO_SWI2		22U			/* �\�t�g�E�F�A������2 */
#define TINTNO_SWI1		23U			/* �\�t�g�E�F�A������1 */
#define TINTNO_SWI0		24U			/* �\�t�g�E�F�A������0 */
#define TINTNO_VM7		25U			/* VME������7 */
#define TINTNO_VM6		26U			/* VME������6 */
#define TINTNO_VM5		27U			/* VME������5 */
#define TINTNO_VM4		28U			/* VME������4 */
#define TINTNO_VM3		29U			/* VME������3 */
#define TINTNO_VM2		30U			/* VME������2 */
#define TINTNO_VM1		31U			/* VME������1 */

/*
 *  �����݃x�N�g���̐ݒ�l�̒�`
 */
#define TVEC_G0I		0x40U		/* �O���[�v0�����݃x�N�g�� */
#define TVEC_G1I		0x48U		/* �O���[�v1�����݃x�N�g�� */
#define TVEC_SWI		0x50U		/* �\�t�g�E�F�A�����݃x�N�g�� */
#define TVEC_SPRI		0x40U		/* �X�v���A�X�����݃x�N�g�� */

/*
 *  �����݃n���h���ԍ��iinhno�j�̒�`
 */
#define TINHNO_ACF		0x47U		/* ACFAIL������ */
#define TINHNO_ABT		0x46U		/* �A�{�[�g������ */
#define TINHNO_SF		0x45U		/* SYSFAIL������ */
#define TINHNO_BER		0x44U		/* �o�X�G���[������ */
#define TINHNO_IAK		0x43U		/* IAK������ */
#define TINHNO_SRQ		0x42U		/* SRQ������ */
#define TINHNO_SAK		0x41U		/* SAK������ */
#define TINHNO_GP7		0x4fU		/* GP7������ */
#define TINHNO_DMA		0x4eU		/* DMA������ */
#define TINHNO_TT1		0x4dU		/* �^�C�}1������ */
#define TINHNO_TT0		0x4cU		/* �^�C�}0������ */
#define TINHNO_GP3		0x4bU		/* �t���b�V�������������� */
#define TINHNO_GP2		0x4aU		/* SCSI������ */
#define TINHNO_GP1		0x49U		/* Ethernet������ */
#define TINHNO_GP0		0x48U		/* �V���A��I/O������ */
#define TINHNO_SWI7		0x57U		/* �\�t�g�E�F�A������7 */
#define TINHNO_SWI6		0x56U		/* �\�t�g�E�F�A������6 */
#define TINHNO_SWI5		0x55U		/* �\�t�g�E�F�A������5 */
#define TINHNO_SWI4		0x54U		/* �\�t�g�E�F�A������4 */
#define TINHNO_SWI3		0x53U		/* �\�t�g�E�F�A������3 */
#define TINHNO_SWI2		0x52U		/* �\�t�g�E�F�A������2 */
#define TINHNO_SWI1		0x51U		/* �\�t�g�E�F�A������1 */
#define TINHNO_SWI0		0x50U		/* �\�t�g�E�F�A������0 */
#define TINHNO_SPRI		0x40U		/* �X�v���A�X������ */

/*
 *  CPU�{�[�h��̃��W�X�^
 */
#define TADR_BOARD_REG0		0xfff48000
#define TADR_BOARD_REG1		0xfff48004
#define TADR_BOARD_REG2		0xfff48008

/*
 *  DGA-001�̃��W�X�^�̃A�h���X
 */
#define TADR_DGA_CSR0		0xfff44000
#define TADR_DGA_CSR1		0xfff44004
#define TADR_DGA_CSR3		0xfff4400c
#define TADR_DGA_CSR4		0xfff44010
#define TADR_DGA_CSR5		0xfff44014
#define TADR_DGA_CSR12		0xfff44030
#define TADR_DGA_CSR13		0xfff44034
#define TADR_DGA_CSR14		0xfff44038
#define TADR_DGA_CSR15		0xfff4403c
#define TADR_DGA_CSR18		0xfff44048
#define TADR_DGA_CSR19		0xfff4404c
#define TADR_DGA_CSR20		0xfff44050
#define TADR_DGA_CSR21		0xfff44054
#define TADR_DGA_CSR23		0xfff4405c
#define TADR_DGA_CSR24		0xfff44060
#define TADR_DGA_IFR0		0xfff44070
#define TADR_DGA_IFR3		0xfff4407c

/*
 *  DGA-001�̊����ݗD��x�ݒ�̂��߂̒�`
 */
#define TIRQ_NMI		(-7)		/* �m���}�X�J�u�������� */
#define TIRQ_LEVEL6		(-6)		/* �����݃��x��6 */
#define TIRQ_LEVEL5		(-5)		/* �����݃��x��5 */
#define TIRQ_LEVEL4		(-4)		/* �����݃��x��4 */
#define TIRQ_LEVEL3		(-3)		/* �����݃��x��3 */
#define TIRQ_LEVEL2		(-2)		/* �����݃��x��2 */
#define TIRQ_LEVEL1		(-1)		/* �����݃��x��1 */

/*
 *  DGA�ւ̃A�N�Z�X�֐�
 */
#define dga_rew_reg(addr)			sil_rew_mem(((uint32_t *) addr))
#define dga_wrw_reg(addr, val)		sil_wrw_mem(((uint32_t *) addr), val)

/*
 *  DGA�̃��W�X�^�ւ̃A�N�Z�X�֐�
 */
#ifndef TOPPERS_MACRO_ONLY

Inline uint32_t
dga_read(void *addr)
{
	return(dga_rew_reg(addr));
}

Inline void
dga_write(void *addr, uint32_t val)
{
	dga_wrw_reg(addr, val);
}

Inline void
dga_bit_or(void *addr, uint32_t bitpat)
{
	dga_write(addr, dga_read(addr) | bitpat);
}

Inline void
dga_bit_and(void *addr, uint32_t bitpat)
{
	dga_write(addr, dga_read(addr) & bitpat);
}

Inline void
dga_set_ilv(void *addr, uint_t shift, uint_t level)
{
	dga_write(addr, (dga_read(addr) & ~(0x07 << shift)) | (level << shift));
} 

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ��PD72001�iMPSC�j�̃��W�X�^�̃A�h���X
 */
#define TADR_UPD72001_DATAA		0xfff45003U
#define TADR_UPD72001_CTRLA		0xfff45007U
#define TADR_UPD72001_DATAB		0xfff4500bU
#define TADR_UPD72001_CTRLB		0xfff4500fU

/*
 *  ��PD72001�ւ̃A�N�Z�X�֐�
 */
#define upd72001_reb_reg(addr)			sil_reb_mem(((uint8_t *) addr))
#define upd72001_wrb_reg(addr, val)		sil_wrb_mem(((uint8_t *) addr), val)

/*
 *  �J�����ˑ��̏���
 */
#ifndef TOPPERS_MACRO_ONLY
#ifdef TOPPERS_GDB_STUB				/* GDB�X�^�u */

Inline void
dve68k_exit(void)
{
	Asm("trap #2");
}

Inline void
dve68k_putc(char c)
{
	Asm("move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"(c)
	  : "d0", "d1", "d2", "d6", "d7");
}

#else /* TOPPERS_GDB_STUB */		/* ���̑��̊J���� */

extern void		dve68k_exit(void) NoReturn;
extern void		dve68k_putc(char c);

#endif /* TOPPERS_GDB_STUB */
#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_DVE68K_H */

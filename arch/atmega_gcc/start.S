/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: start.S 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�J�[�l���Ή��̃X�^�[�g�A�b�v���W���[���iATMega�p�j
 */
#include "macro.d"

#include <avr/io.h>

#define	TOPPERS_MACRO_ONLY
#include "kernel_impl.h"

	.text
	.globl start
start:
	/*
	 *  �v���Z�b�T���[�h�ƃX�^�b�N�|�C���^�̏�����
	 */
	clr		r24
	out		_SFR_IO_ADDR(SREG),r24	/* status reg. */

	ldi		r24,lo8(RAMEND)			/* ;defined in system */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24	/* 1word */

    ; MCU control register (reset value is 0x00)
;	ldi	r24,0b00000000
		;;     |||||___ISC3-0: interrupt sense control
		;;     ||||
		;;     ||___SM2:0 sleep mode 000=idle mode
		;;     |_SE sleep enable
;	out	MCUCR,r24		;

	/*
	 * �E�H�b�`�h�b�O�E�^�C�}�[�����Z�b�g
	 */
	wdr
	; MCUSR���W�X�^��WDRF���N���A
	in		r24, _SFR_IO_ADDR(MCUSR)
	andi	r24, (0xff & (0<<WDRF))
	out		_SFR_IO_ADDR(MCUSR), r24
	; WDCE��WDE��1����������
	; �Ӑ}���Ȃ��^�C���A�E�g���������Ȃ��悤�ɁC������̑O��ݒ�͂��̂܂܂ɂ���
	lds		r24, WDTCSR
	ori		r24, (1<<WDCE) | (1<<WDE)
	sts		WDTCSR, r24
	; WDT���I�t�ɂ���
	ldi		r24, (0<<WDE)
	sts		WDTCSR, r24

	/*
	 *  hardware_init_hook�̌ďo���i0�łȂ��ꍇ�j
	 *
	 *  �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook�Ƃ����֐���p�ӂ���D
	 */
	ldi		ZL,lo8(gs(hardware_init_hook))
	ldi		ZH,hi8(gs(hardware_init_hook))
	tst		ZL
	brne	0f
	tst		ZH
	brne	0f
	rjmp	1f
0:
	icall
1:

	/*
	 *  data�Z�N�V�����̏������iROM���Ή��j
	 *
	 *  _dload���C_sdata����_edata�܂ŃR�s�[����D
	 */
	ldi		ZL,lo8(__idata_start)
	ldi		ZH,hi8(__idata_start)	/* Z:src in ROM */
	ldi		XL,lo8(__data_start)
	ldi		XH,hi8(__data_start)	/* X:dst in RAM */
	ldi		YL,lo8(__data_end)
	ldi		YH,hi8(__data_end)		/* (Y=data_end) */
	rjmp	3f
2:
	lpm		r0,Z+					/* (r0=*src++) */
	st		X+,r0					/* (*dst++=r0) */
    ;cnt==0 ? (cmp 16-bit)
3:
	cpse	XL,YL					/* compare then skip if equal */
	rjmp	2b
	cpse	XH,YH
	rjmp	2b

	/*
	 *  bss�Z�N�V�����̃N���A
	 */
	ldi		XL,lo8(__bss_start)
	ldi		XH,hi8(__bss_start)		/* X:dst */
	ldi		ZL,lo8(__bss_end)
	ldi		ZH,hi8(__bss_end)		/* Z:addr of end */
	clr		r1						/* filled pattern */
	rjmp	5f
4:
	st		X+,r1					/* *dst++=r1 */
    ;reach at end ?
5:
	cpse	XL,ZL
	rjmp	4b
	cpse	XH,ZH					/* compare then skip if equal */
	rjmp	4b

	/*
	 *  software_init_hook�̌ďo���i0�łȂ��ꍇ�j
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�����������
	 *  ����ꍇ�́Csoftware_init_hook�Ƃ����֐���p�ӂ���΂悢�D
	 */
	ldi		ZL,lo8(gs(software_init_hook))
	ldi		ZH,hi8(gs(software_init_hook))
	tst		ZL
	brne	6f
	tst		ZH
	brne	6f
	rjmp	7f
6:
	icall
7:
;----- hardware initialization before EI
	clr		r1						/* r1 assumed as zero reg. */
;	sei								/* enable global interrupt */

	/*
	 *  �J�[�l�����N������D
	 */
	jmp sta_ker
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
 *  $Id: prc_support.S 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iATMega�p�j
 */

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t�^�̒萔�����}�N�� */
#define ULONG_C(val)		(val)		/* ulong_t�^�̒萔�����}�N�� */
#define CAST(type, val)		(val)		/* �^�L���X�g���s���}�N�� */
#include "kernel_impl.h"
#include "offset.h"
#include <avr/io.h>

/*
 *  �^�X�N�f�B�X�p�b�`��
 */
	.text
	.globl dispatch
dispatch:
	/*
	 *  ���̃��[�`���́C�^�X�N�R���e�L�X�g�ECPU���b�N��ԁE�f�B�X�p�b�`
	 *  ����ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂŌĂяo��
	 *  ���D
	 */
	in		r0,_SFR_IO_ADDR(SREG)		/* ���W�X�^��ۑ� */
	push	r0
;
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
;
	push	r28		;Y-low
	push	r29		;  high

	lds		r24,p_runtsk+0
	lds		r25,p_runtsk+1
	movw	ZL,r24
	in		r24,_SFR_IO_ADDR(SPL)		/* �^�X�N�X�^�b�N��ۑ� */
	std		Z+TCB_sp+0,r24
	in		r24,_SFR_IO_ADDR(SPH)
	std		Z+TCB_sp+1,r24
	ldi		r24,lo8(gs(dispatch_r))		/* ���s�ĊJ�Ԓn��ۑ� */
	std		Z+TCB_pc+0,r24
	ldi		r24,hi8(gs(dispatch_r))
	std		Z+TCB_pc+1,r24
	rjmp	dispatcher

dispatch_r:
	pop		r29							/* ���W�X�^�𕜋A */
	pop		r28
;
	pop		r17
	pop		r16
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r7
	pop		r6
	pop		r5
	pop		r4
	pop		r3
	pop		r2
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0

	ldi		r24,TCB_enatex_bit			/* r25 = (1 << TCB_enatex_bit) */
	ldi		r25,1
0:
	lsl		r25
	dec		r24
	brne	0b

	lds		ZL,p_runtsk+0
	lds		ZH,p_runtsk+1
	ldd		r24,Z+TCB_enatex
	and		r24,r25
	breq	dispatch_r_1				/* enatex��false�Ȃ烊�^�[�� */

	ldd		r24,Z+TCB_texptn+0
	tst		r24
	brne	1f

	ldd		r24,Z+TCB_texptn+1
	tst		r24
	brne	1f

	rjmp	dispatch_r_1				/* texptn��0�Ȃ烊�^�[�� */

1:
	lds		r24,ipmflg+0				/* ipmflg��true�ł����            */
	tst		r24
	brne	2f

	lds		r24,ipmflg+1
	tst		r24
	brne	2f

	rjmp	dispatch_r_1

2:
	jmp		call_texrtn					/*  �^�X�N��O�������[�`���̌ďo�� */

dispatch_r_1:
	ret

/*
 *  �f�B�X�p�b�`���̓���J�n�iprc_support.S�j
 */
	.globl start_dispatch
start_dispatch:
	/*
	 *  ���̃��[�`���́C�J�[�l���N�����ɁC���ׂĂ̊����݂��֎~�������
	 * �i�����݃��b�N��ԂƓ����j�ŌĂяo�����D�܂��C�����݃��[�h�i��
	 *  �^�X�N�R���e�L�X�g�Ɠ����j�ŌĂяo����邱�Ƃ�z�肵�Ă���D
	 *
	 *  prc_initialize�ŁClock_flag��true�ɁCsaved_iipm��IIPM_ENAALL��
	 *  ���������Ă��邽�߁C�J�[�l���Ǘ��O�̊����݂������邱�ƂŁC
	 *  CPU���b�N��ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂɂȂ�D
	 *  �܂��Cinitialize_task��disdsp��false�ɏ��������Ă��邽�߁C�f�B
	 *  �X�p�b�`����ԂɂȂ��Ă���D
	 */
	clr		r1							/* �}�X�^���[�h�� */
	sts		int_cnt,r1
;	sei									/* �J�[�l���Ǘ��O�̊����݂����� */
	rjmp	dispatcher_0

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 */
	.globl exit_and_dispatch
exit_and_dispatch:
	/* �f�B�X�p�b�`���{�́idispatcher�j�� */

/*
 *  �f�B�X�p�b�`���{��
 */
dispatcher:
	/*
	 *  ���̃��[�`���́C�^�X�N�R���e�L�X�g�ECPU���b�N��ԁE�f�B�X�p�b�`
	 *  ����ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂŌĂяo��
	 *  ���D
	 *
	 *  ���Ȃ킿�C�}�X�^���[�h�Elock_flag��true�Edisdsp��false�Edspflg
	 *  ��true�Esaved_iipm��IIPM_ENAALL�ƂȂ��Ă���D���s�ĊJ�Ԓn�ւ���
	 *  �̏�Ԃ̂܂ܕ��򂷂�D
	 */
#ifdef LOG_DSP_ENTER
	lds		r24,p_runtsk+0				/* p_runtsk���p�����[�^�� */
	lds		r25,p_runtsk+1
	call	log_dsp_enter
#endif /* LOG_DSP_ENTER */

dispatcher_0:
	lds		r24,p_schedtsk+0			/* p_schedtsk��p_runtsk�� */
	lds		r25,p_schedtsk+1
	sts		p_runtsk+0,r24
	sts		p_runtsk+1,r25
	tst		r24
	brne	0f

	tst		r25
	brne	0f

	rjmp	dispatcher_1				/* p_runtsk��NULL�Ȃ�dispatcher_1�� */

0:
	movw	ZL,r24
	ldd		r24,Z+TCB_sp+0				/* �^�X�N�X�^�b�N�𕜋A */
	out		_SFR_IO_ADDR(SPL),r24
	ldd		r24,Z+TCB_sp+1
	out		_SFR_IO_ADDR(SPH),r24

#ifdef LOG_DSP_LEAVE
	ldd		r24,Z+0						/* p_runtsk���p�����[�^�� */
	ldd		r25,Z+1
	push	r24
	push	r25
	call	log_dsp_leave

	pop		r25
	pop		r24
	std		Z+0,r24
	std		Z+1,r25
#endif

	ldd		r24,Z+TCB_pc+0				/* ���s�ĊJ�Ԓn�֕��� */
	ldd		r25,Z+TCB_pc+1
	movw	XL,ZL
	movw	ZL,r24
	ijmp

dispatcher_1:
	/*
	 *  CPU���b�N��Ԃ��������鏀��������D
	 */
	ldi		r24,1						/* �����݃��[�h�� */
	sts		int_cnt+0,r24
	ldi		r24,lo8(RAMEND)				/* �����ݗp�̃X�^�b�N�֐ؑւ� */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24
	in		r24,_SFR_IO_ADDR(SREG)		/* SREG��r24�ɕۑ� */
	clr		r1
	sts		lock_flag, r1				/* CPU���b�N������Ԃ� */

dispatcher_2:
	/*
	 *  �����݂������C�����݃��[�h�ɐ؂芷���āC�����݂�҂D
	 *
	 *  �����Ŋ����݃��[�h�ɐ؂芷����̂́C�����Ŕ������銄���ݏ�����
	 *  �ǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h�����ł̃^
	 *  �X�N�f�B�X�p�b�`�̖h�~�Ƃ���2�̈Ӗ�������D
	 *
	 *  �v���Z�b�T�������ݑ҂��Ɉڍs�����鏈���ƁC�����݋��Ƃ́C�s��
	 *  ���ɍs�Ȃ��K�v������D�����s���ɍs�Ȃ�Ȃ��ꍇ�C�����݂���
	 *  ��������Ɋ����݂�����C���̒��Ń^�X�N�����s�\��ԂɂȂ��
	 *  ���s���ׂ��^�X�N������ɂ�������炸�v���Z�b�T�������ݑ҂��ɂ�
	 *  ���Ă��܂��D
	 *
	 *  �����ݑ҂��̊Ԃ́Cp_runtsk��NULL�i��0�j�ɐݒ肵�Ȃ���΂Ȃ��
	 *  ���D���̂悤�ɐݒ肵�Ȃ��ƁC�����݃n���h������iget_tid���Ăяo
	 *  �����ۂ̓��삪�d�l�ɍ��v���Ȃ��Ȃ�D
	 */
	sei									/* �����ݑ҂� */
	nop
	cli
	out		_SFR_IO_ADDR(SREG),r24		/* ���̏�Ԃɖ߂� */
	lds		r25,reqflg
	tst		r25							/* reqflg��false�Ȃ�dispatcher_2�� */
	breq	dispatcher_2

	clr		r1
	sts		reqflg,r1					/* reqflg��false�� */

	/*
	 *  CPU���b�N��Ԃɖ߂��D�����ݑ҂��̊ԂɎ��s���������݃n���h���ɂ�
	 *  ��Csaved_iipm��������������\�������邽�߁C���̒l�ɖ߂��K
	 *  �v������Ddispatcher�����s����鎞�́Csaved_iipm��IIPM_ENAALL
	 *  �ƂȂ��Ă��邽�߁C�����ł�saved_iipm��IIPM_ENAALL�i��0�j�ɖ߂�
	 *  �΂悢�D
	 */
	clr		r1							/* �}�X�^���[�h�� */
	sts		int_cnt+0,r1
	clr		r1							/* saved_iipm��0�ɂ��� */
	sts		saved_iipm,r1
	ldi		r24,1
	sts		lock_flag,r24				/* CPU���b�N��Ԃ� */
	rjmp	dispatcher_0

/*
 *  �J�[�l���̏I�������̌ďo��
 */
	.globl call_exit_kernel
call_exit_kernel:
	ldi		r24,1						/* �����݃��[�h�� */
	sts		int_cnt+0,r24
	ldi		r24,lo8(RAMEND)				/* �����ݗp�̃X�^�b�N�֐ؑւ� */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24
	jmp		exit_kernel					/* �J�[�l���̏I���������Ă� */

/*
 *
 *  �^�X�N�J�n������
 *
 *  dispatcher����Ăяo����邽�߁CTCB�̃A�h���X��X�ɓ����Ă���
 *
 */
	.text
	.globl start_r
start_r:
	clr		r1							/* CPU���b�N������Ԃ� */
	sts		lock_flag,r1
	sei									/* �����݋��� */

	movw	ZL,XL
	ldd		r24,Z+TCB_p_tinib+0			/* p_runtsk->p_tinib��Z�� */
	ldd		r25,Z+TCB_p_tinib+1
	movw	ZL,r24
	ldd		r24,Z+TINIB_exinf+0			/* exinf���p�����[�^�ɐς� */
	ldd		r25,Z+TINIB_exinf+1
	ldi		XL,lo8(gs(ext_tsk))			/* ext_tsk���X�^�b�N�ɐς� */
	ldi		XH,hi8(gs(ext_tsk))
	push	XL
	push	XH
	push	r1
	ldd		r22,Z+TINIB_task+0
	ldd		r23,Z+TINIB_task+1
	movw	ZL,r22
	ijmp

/*
 *  �����݃G���g��
 */
	.global inthdr_entry
inthdr_entry:
	push	r1
	push	r0
	in		r0,_SFR_IO_ADDR(SREG)		/* �X�N���b�`���W�X�^��ۑ� */
	push	r0
	clr		r1
;
	push	r18
	push	r19
	push	r20
	push	r21
	push	r22
	push	r23
;	push	r24
	push	r25
	push	r26		;X-low
	push	r27		;  high
;
	push	r30		;Z-low
	push	r31		;  high

	lds		r25,int_cnt+0
	inc 	r25							/* �����݃��[�h�� */
	sts 	int_cnt+0,r25
	cpi		r25,1						/* ���Z�O��0�łȂ���Α��d������ */
	brne	inthdr_entry_0_d

	in		r22,_SFR_IO_ADDR(SPL)		/* �^�X�N�X�^�b�N��ۑ� */
	sts		int_sp+0,r22
	in		r22,_SFR_IO_ADDR(SPH)
	sts		int_sp+1,r22
	ldi		r22,lo8(RAMEND)				/* �����ݗp�̃X�^�b�N�֐ؑւ� */
	out		_SFR_IO_ADDR(SPL),r22
	ldi		r22,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r22
	rjmp	inthdr_entry_0

inthdr_entry_0_d:
	rjmp	inthdr_entry_0

inthdr_entry_0:
;	sei									/* ���d���荞�݋��� */
										/* AVR�ł̑��d���荞�݂͐�������Ȃ��I */
	ldi		ZL,lo8(_kernel_exc_tbl)
	ldi		ZH,hi8(_kernel_exc_tbl)
	clr		r1
	add		ZL,r24
	adc		ZH,r1
	add		ZL,r24
	adc		ZH,r1

	ld		r22,Z+
	ld		r23,Z
	movw	ZL,r22
	push	r24							/* for Debug */
#ifdef LOG_INH_ENTER
	push	r30		;Z-low
	push	r31		;  high
	clr		r25
	call	log_inh_enter				/* log_exc_enter���Ăяo�� */

	pop		r31		;  high
	pop		r30		;Z-low

#endif /* LOG_EXC_ENTER */

	icall								/* C���[�`���Ăяo�� */

#ifdef LOG_INH_LEAVE
	pop		r24
	clr		r25							/* ��O�ԍ���������        */
	call	log_inh_leave				/* log_exc_leave���Ăяo�� */

	push	r24
#endif /* LOG_INH_LEAVE */

	sei
	nop

/*
 *  �����݃n���h���o������
 *
 *  ret_int�́C�����݃n���h������߂�������Ɏ��s���郋�[�`���ŁC
 *  INTHDR_ENTRY�}�N���œW�J���銄���݃n���h���̓��������ŁC�����݃n��
 *  �h������̖߂�Ԓn�ɐݒ肳���D
 */
	.text
	.globl ret_int
ret_int:
	cli									/* ���d���荞�݋֎~ */
	pop		r24							/* for Debug */
	lds		r25,int_cnt
	dec		r25
	sts		int_cnt+0,r25
	tst		r25							/* �߂�悪�����݃��[�h�Ȃ� */
	brne	ret_int_1_d					/*           �����Ƀ��^�[�� */

	lds		r22,reqflg					/* reqflg��true�ł����ret_int_2�� */
	tst		r22
	brne	ret_int_2

	lds		r22,int_sp+0
	out		_SFR_IO_ADDR(SPL),r22
	lds		r22,int_sp+1
	out		_SFR_IO_ADDR(SPH),r22

ret_int_1:
	/*
	 *  �����ݏ�������̃��^�[���ɂ��CCPU���b�N������ԂɈڍs����悤
	 *  ��������D�����ݗD��x�}�X�N�́CRTE���߂ɂ�茳�̒l�ɖ߂邽�߁C
	 *  lock_flag��false�ɂ��Ă����΂悢�ilock_flag��false�ɂ���̂́C
	 *  CPU���b�N��Ԃ̂܂܊����݃n���h������߂������̑΍�j�D
	 */
	clr		r1							/* CPU���b�N�����̏��� */
	sts		lock_flag,r1

	pop		r31							/* �X�N���b�`���W�X�^�𕜋A */
	pop		r30
;
	pop		r27
	pop		r26
	pop		r25
;	pop		r24
	pop		r23
	pop		r22
	pop		r21
	pop		r20
	pop		r19
	pop		r18
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0
	pop		r0
	pop		r1

	pop		r24

	reti

ret_int_1_d:
	rjmp	ret_int_1

ret_int_2:
	lds		r22,int_sp+0
	out		_SFR_IO_ADDR(SPL),r22
	lds		r22,int_sp+1
	out		_SFR_IO_ADDR(SPH),r22

ret_int_3:
	/*
	 *  �����ւ́CCPU��O�n���h���̏o��������������򂵂Ă���D
	 *
	 *  �����ł́C�߂�悪�^�X�N�ł���C�X�^�b�N�́C��O�X�^�b�N�t���[
	 *  ���̏�ɃX�N���b�`���W�X�^�݂̂��ۑ����ꂽ��ԂɂȂ��Ă���D��
	 *  ���C�v���Z�b�T�́C�}�X�^���[�h�E�J�[�l���Ǘ��̊����݂��֎~����
	 *  ��ԂƂȂ��Ă���D
	 */
	clr		r1							/* reqflg��false�� */
	sts		reqflg,r1

	/*
	 *  CPU���b�N��ԂɈڍs���C�����ݗD��x�}�X�N�������ݏ����O�̒l�ɐ�
	 *	�肷��D�J�[�l���Ǘ��̊����݂͂��łɋ֎~���Ă���̂ŁClock_flag
	 *  ��saved_iipm���X�V����Dsaved_iipm�́C�߂��̊����ݗD��x�}�X
	 *  �N�i�̓����\���j�ɐݒ肷��D
	 *
	 *  ���̎��_��CPU���b�N��ԂƂ���̂́Cdispatcher�֕��򂷂鎞�ƁC
	 *  call_texrtn���Ăяo�����ɁCCPU���b�N��ԂɂȂ��Ă���K�v������
	 *  ���߂ł���D
	 */
	ldi		r24,1						/* lock_flag��true�� */
	sts		lock_flag,r24

	/*
	 *  dspflg��false�ł���ꍇ�ƁCp_runtsk��p_schedtsk�������ꍇ�ɂ́C
	 *  �f�B�X�p�b�`���s��Ȃ��D���̃`�F�b�N���K�v�Ȃ̂́C�^�X�N��O��
	 *  �����[�`���̌ďo�����K�v�ȏꍇ�ɁC�f�B�X�p�b�`���K�v�Ȃ��Ă��C
	 *  reqflg��true�ɂ��邽�߂ł���D
	 */
	lds		r24,p_runtsk+0
	lds		r25,p_runtsk+1
	movw	ZL,r24
	lds		r22,dspflg					/* dspflg��false�Ȃ�ret_int_4�� */
	tst		r22
	breq	ret_int_4

	lds		r22,p_schedtsk+0			/* p_runtsk��p_schedtsk�������Ȃ� */
	lds		r23,p_schedtsk+1
	cp		r22,r24
	brne	0f

	cp		r23,r25
	brne	0f

	movw	XL,ZL
	rjmp	ret_int_4					/*                    ret_int_4�� */

0:
	in		r0,_SFR_IO_ADDR(SREG)		/* �c��̃��W�X�^��ۑ� */
	push	r0
;
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
;
	push	r28
	push	r29

	in		r24,_SFR_IO_ADDR(SPL)		/* �^�X�N�X�^�b�N��ۑ� */
	std		Z+TCB_sp+0,r24
	in		r24,_SFR_IO_ADDR(SPH)
	std		Z+TCB_sp+1,r24
	ldi		r24,lo8(gs(ret_int_r))		/* ���s�ĊJ�Ԓn��ۑ� */
	std		Z+TCB_pc+0,r24
	ldi		r24,hi8(gs(ret_int_r))
	std		Z+TCB_pc+1,r24

	rjmp	dispatcher

ret_int_r:
	pop		r29							/* ���W�X�^�𕜋A */
	pop		r28
;
	pop		r17
	pop		r16
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r7
	pop		r6
	pop		r5
	pop		r4
	pop		r3
	pop		r2
;
	pop		r0		;status reg.
	out		_SFR_IO_ADDR(SREG),r0

ret_int_4:
	/*
	 *  enatex��true�ŁCtexptn��0�łȂ��Cipmflg��true�ł���΁C�^�X�N
	 *  ��O�������[�`�����Ăяo���D
	 *  ret_int_3��dispatcher����Ăяo����邽�߁CTCB�̃A�h���X��X�ɓ����Ă���
	 */
	movw	ZL,XL
	ldi		r24,TCB_enatex_bit
	ldi		r25,1
1:
	lsl		r25
	dec		r24
	brne	1b

	ldd		r24,Z+TCB_enatex
	and		r24,r25
	breq	ret_int_5					/* enatex��false�Ȃ�ret_int_5�� */

	ldd		r24,Z+TCB_texptn
	tst		r24
	breq	ret_int_5					/* texptn��0�Ȃ�ret_int_5�� */

	call	call_texrtn					/* �^�X�N��O�������[�`���̌ďo�� */

ret_int_5:
	/*
	 *  �����ݏ�������̃��^�[���ɂ��CCPU���b�N������ԂɈڍs�����
	 *  ����������D�����ݗD��x�}�X�N�́CRTE���߂ɂ�茳�̒l�ɖ߂邽
	 *  �߁Clock_flag��false�ɂ��Ă����΂悢�D
	 */
	clr		r1							/* CPU���b�N�����̏��� */
	sts		lock_flag,r1

	pop		r31							/* �X�N���b�`���W�X�^�𕜋A */
	pop		r30
;
	pop		r27
	pop		r26
	pop		r25
;	pop		r24
	pop		r23
	pop		r22
	pop		r21
	pop		r20
	pop		r19
	pop		r18
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0
	pop		r0
	pop		r1

	pop		r24

	reti
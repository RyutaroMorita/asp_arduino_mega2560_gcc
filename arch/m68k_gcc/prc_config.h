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
 *  $Id: prc_config.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�v���Z�b�T�ˑ����W���[���iM68040�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ctarget_config.h�i�܂��́C��������C���N
 *  ���[�h�����t�@�C���j�݂̂���C���N���[�h�����D���̃t�@�C������
 *  ���ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#include "prc_insn.h"

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	void	*msp;		/* �X�^�b�N�|�C���^ */
	FP		pc;			/* �v���O�����J�E���^ */
} TSKCTXB;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �����ݗD��x�}�X�N���색�C�u����
 *
 *  M68040�ł́C�X�e�[�^�X���W�X�^�iSR�j�̉�����8�`10�r�b�g�߂�3�r�b�g
 *  �Ɋ����ݗD��x�}�X�N�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�CIPM�j���u��
 *  ��Ă���DIPM��ۑ����Ă������߂ɁC�����ݗD��x�̊O���\���i-1����A
 *  ���������̒l�j���g�����Ƃ��\�ł��邪�C�]�v�ȍ��E�r�b�g�V�t�g�ƕ�
 *  �����]���K�v�ɂȂ�D���������邽�߂ɁCIPM��ۑ�����ꍇ�ɂ́CSR��
 *  8�`10�r�b�g�߂����o�����l���g�����Ƃɂ���D���̒l�������ݗD��x�}
 *  �X�N�̓����\���ƌĂсCIIPM�Ə������Ƃɂ���D
 */

/*
 *  �����ݗD��x�}�X�N�̊O���\���Ɠ����\���̕ϊ�
 */
#define EXT_IPM(iipm)	(-CAST(PRI, (iipm) >> 8))		/* �O���\���ɕϊ� */
#define INT_IPM(ipm)	(CAST(uint16_t, -(ipm)) << 8)	/* �����\���ɕϊ� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�C�����\���j�̌��ݒl�̓Ǐo��
 */
Inline uint16_t
current_iipm(void)
{
	return(current_sr() & 0x0700U);
}

/*
 *  IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�C�����\���j�̌��ݒl�̐ݒ�
 */
Inline void
set_iipm(uint16_t iipm)
{
	set_sr((current_sr() & ~0x0700U) | iipm);
}

/*
 *  TOPPERS�W�������ݏ������f���̎���
 *
 *  M68040�́C�X�e�[�^�X���W�X�^�iSR�j���Ɋ����ݗD��x�}�X�N�i�n�[�h�E�F
 *  �A�̊����ݗD��x�}�X�N�CIPM�j�������Ă��邪�CCPU���b�N�t���O�ɑ���
 *  ����@�\�������Ȃ��D���̂��߁CCPU���b�N�t���O�̋@�\���CIPM�ɂ����
 *  ��������D
 *
 *  �܂�CPU���b�N�t���O�̒l�i���Ȃ킿�CCPU���b�N��Ԃ�CPU���b�N�������
 *  ���j�́C���̂��߂̕ϐ��ilock_flag�j��p�ӂ��ĕێ�����D
 *
 *  CPU���b�N�t���O���N���A����Ă���ԁi���Ȃ킿�CCPU���b�N������Ԃ�
 *  �ԁj�́CIPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���C���f����̊�����
 *  �D��x�}�X�N�̒l�ɐݒ肷��D���̊Ԃ́C���f����̊����ݗD��x�}�X�N
 *  �́CIPM��p���ĕێ�����D
 *
 *  ����ɑ΂���CPU���b�N�t���O���Z�b�g����Ă���ԁi���Ȃ킿�CCPU���b
 *  �N��Ԃ̊ԁj�́CIPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���C�J�[�l��
 *  �Ǘ��̊����݂����ׂă}�X�N����l�iTIPM_LOCK�j�ƁC���f����̊����ݗD
 *  ��x�}�X�N�Ƃ̍������ɐݒ肷��D���̊Ԃ̃��f����̊����ݗD��x�}�X
 *  �N�́C���̂��߂̕ϐ��isaved_iipm�C�����\���ŕێ��j��p�ӂ��ĕێ���
 *  ��D
 */

/*
 *  �R���e�L�X�g�̎Q��
 *
 *  M68040�ł́C�^�X�N�R���e�L�X�g���}�X�^���[�h�ŁC��^�X�N�R���e�L�X
 *  �g�������݃��[�h�Ŏ��s����D�}�X�^���[�h�������݃��[�h���́C�X�e�[
 *  �^�X���W�X�^�iSR�j���̊����݃��[�h�r�b�g�ɂ�蔻�ʂł���D
 */
Inline bool_t
sense_context(void)
{
	return((current_sr() & 0x1000U) == 0U);
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  CPU���b�N��Ԃł̊����ݗD��x�}�X�N
 *
 *  TIPM_LOCK�́C�J�[�l���Ǘ��̊����݂����ׂă}�X�N����l�ɒ�`����D
 *
 *  TIPM_LOCK�́C��{�I�ɂ�TMIN_INTPRI�Ɉ�v������΂悢���CM68040�ł́C
 *  IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j��-6�̏ꍇ��-7�̏ꍇ�̐U����
 *  �������ŁCIPM��-7��ݒ肷�邱�Ƃ͌����I�ɍs���邱�Ƃ���C
 *  TMIN_INTPRI��-6�̎���TIPM_LOCK��-7�ɂ��Ă���D
 */
#if TMIN_INTPRI == -6		/* NMI�ȊO�ɃJ�[�l���Ǘ��O�̊����݂�݂��Ȃ� */
#define TIPM_LOCK		(-7)
#else /* TMIN_INTPRI == -6 */
#if (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6)
#define TIPM_LOCK		TMIN_INTPRI
#else /* (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6) */
#error TMIN_INTPRI out of range.
#endif /* (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6) */
#endif /* TMIN_INTPRI == -6 */

/*
 *  CPU���b�N��Ԃł̊����ݗD��x�}�X�N�̓����\��
 */
#define IIPM_LOCK		INT_IPM(TIPM_LOCK)

/*
 *  TIPM_ENAALL�i�����ݗD��x�}�X�N�S�����j�̓����\��
 */
#define IIPM_ENAALL		INT_IPM(TIPM_ENAALL)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  CPU���b�N�t���O�����̂��߂̕ϐ�
 *
 *  �����̕ϐ��́CCPU���b�N��Ԃ̎��̂ݏ��������Ă悢���̂Ƃ���D
 */
extern volatile bool_t		lock_flag;	/* CPU���b�N�t���O�̒l��ێ�����ϐ� */
extern volatile uint16_t	saved_iipm;	/* �����ݗD��x�}�X�N��ۑ�����ϐ� */

/*
 *  CPU���b�N��Ԃւ̈ڍs
 *
 *  IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���Csaved_iipm�ɕۑ����C�J�[
 *  �l���Ǘ��̊����݂����ׂă}�X�N����l�iTIPM_LOCK�j�ɐݒ肷��D�܂��C
 *  lock_flag��true�ɂ���D
 *
 *  IPM���C�ŏ�����TIPM_LOCK�Ɠ����������荂���ꍇ�ɂ́C�����
 *  saved_iipm�ɕۑ�����݂̂ŁCTIPM_LOCK�ɂ͐ݒ肵�Ȃ��D����́C���f��
 *  ��̊����ݗD��x�}�X�N���CTIPM_LOCK�Ɠ����������荂�����x���ɐݒ�
 *  ����Ă����Ԃɂ�����D
 *
 *  ���̊֐��́CCPU���b�N��ԁilock_flag��true�̏�ԁj�ŌĂ΂�邱�Ƃ�
 *  �Ȃ����̂Ƒz�肵�Ă���D
 */
Inline void
x_lock_cpu(void)
{
	uint16_t	iipm;

	/*
	 *  current_iipm()�̕Ԃ�l�𒼐�saved_iipm�ɕۑ������C�ꎞ�ϐ�iipm
	 *  ��p���Ă���̂́Ccurrent_iipm()���Ă񂾒���Ɋ����݂��������C
	 *  �N�����ꂽ�����ݏ�����saved_iipm���ύX�����\�������邽�߂�
	 *  ����D
	 */
	iipm = current_iipm();
#if TIPM_LOCK == -7
	disint();
#else /* TIPM_LOCK == -7 */
	if (IIPM_LOCK > iipm) {
		set_iipm(IIPM_LOCK);
	}
#endif /* TIPM_LOCK == -7 */
	saved_iipm = iipm;
	lock_flag = true;
	Asm("":::"memory");
}

#define t_lock_cpu()	x_lock_cpu()
#define i_lock_cpu()	x_lock_cpu()

/*
 *  CPU���b�N��Ԃ̉���
 *
 *  lock_flag��false�ɂ��CIPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���C
 *  saved_iipm�ɕۑ������l�ɖ߂��D
 *
 *  ���̊֐��́CCPU���b�N��ԁilock_flag��true�̏�ԁj�ł̂݌Ă΂���
 *  �̂Ƒz�肵�Ă���D
 */
Inline void
x_unlock_cpu(void)
{
	Asm("":::"memory");
	lock_flag = false;
	set_iipm(saved_iipm);
}

#define t_unlock_cpu()	x_unlock_cpu()
#define i_unlock_cpu()	x_unlock_cpu()

/*
 *  CPU���b�N��Ԃ̎Q��
 */
Inline bool_t
x_sense_lock(void)
{
	return(lock_flag);
}

#define t_sense_lock()	x_sense_lock()
#define i_sense_lock()	x_sense_lock()

/*
 *  chg_ipm�ŗL���Ȋ����ݗD��x�͈̔͂̔���
 *
 *  TMIN_INTPRI�̒l�ɂ�炸�Cchg_ipm�ł́C-6�`TIPM_ENAALL�i��0�j�͈̔�
 *  �ɐݒ�ł��邱�ƂƂ���i�^�[�Q�b�g��`�̊g���j�D
 */
#define VALID_INTPRI_CHGIPM(intpri) \
				(-6 <= (intpri) && (intpri) <= TIPM_ENAALL)

/*
 * �i���f����́j�����ݗD��x�}�X�N�̐ݒ�
 *
 *  CPU���b�N�t���O���N���A����Ă��鎞�́C�n�[�h�E�F�A�̊����ݗD��x�}
 *  �X�N��ݒ肷��DCPU���b�N�t���O���Z�b�g����Ă��鎞�́Csaved_iipm
 *  ��ݒ肵�C����ɁC�n�[�h�E�F�A�̊����ݗD��x�}�X�N���C�ݒ肵�悤��
 *  �����i���f����́j�����ݗD��x�}�X�N��TIPM_LOCK�̍������ɐݒ肷��D
 */
Inline void
x_set_ipm(PRI intpri)
{
	uint16_t	iipm = INT_IPM(intpri);

	if (!lock_flag) {
		set_iipm(iipm);
	}
	else {
		saved_iipm = iipm;
#if TIPM_LOCK == -7
		/*
		 *  TIPM_LOCK��-7�̏ꍇ�ɂ́C���̎��_�Ńn�[�h�E�F�A�̊����ݗD��
		 *  �x�}�X�N���K��7�ɐݒ肳��Ă��邽�߁C�ݒ肵�Ȃ����K�v���Ȃ��D
		 */
#else /* TIPM_LOCK == -7 */
		set_iipm(iipm > IIPM_LOCK ? iipm : IIPM_LOCK);
#endif /* TIPM_LOCK == -7 */
	}
}

#define t_set_ipm(intpri)	x_set_ipm(intpri)
#define i_set_ipm(intpri)	x_set_ipm(intpri)

/*
 * �i���f����́j�����ݗD��x�}�X�N�̎Q��
 *
 *  CPU���b�N�t���O���N���A����Ă��鎞�̓n�[�h�E�F�A�̊����ݗD��x�}
 *  �X�N���C�Z�b�g����Ă��鎞��saved_iipm���Q�Ƃ���D
 */
Inline PRI
x_get_ipm(void)
{
	uint16_t	iipm;

	if (!lock_flag) {
		iipm = current_iipm();
	}
	else {
		iipm = saved_iipm;
	}
	return(EXT_IPM(iipm));
}

#define t_get_ipm()		x_get_ipm()
#define i_get_ipm()		x_get_ipm()

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�iprc_support.S�j
 *
 *  dispatch�́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[��������
 *  ��Ăяo���ׂ����̂ŁC�^�X�N�R���e�L�X�g�ECPU���b�N��ԁE�f�B�X�p�b
 *  �`����ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂŌĂяo����
 *  ����΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  �f�B�X�p�b�`���̓���J�n�iprc_support.S�j
 *
 *  start_dispatch�́C�J�[�l���N�����ɌĂяo���ׂ����̂ŁC���ׂĂ̊���
 *  �݂��֎~������ԁi�����݃��b�N��ԂƓ����̏�ԁj�ŌĂяo���Ȃ����
 *  �Ȃ�Ȃ��D
 */
extern void	start_dispatch(void) NoReturn;

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�iprc_support.S�j
 *
 *  exit_and_dispatch�́Cext_tsk����Ăяo���ׂ����̂ŁC�^�X�N�R���e�L
 *  �X�g�ECPU���b�N��ԁE�f�B�X�p�b�`����ԁE�i���f����́j�����ݗD��
 *  �x�}�X�N�S������ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	exit_and_dispatch(void) NoReturn;

/*
 *  �J�[�l���̏I�������̌ďo���iprc_support.S�j
 *
 *  call_exit_kernel�́C�J�[�l���̏I�����ɌĂяo���ׂ����̂ŁC��^�X�N
 *  �R���e�L�X�g�ɐ؂芷���āC�J�[�l���̏I�������iexit_kernel�j���Ăяo
 *  ���D
 */
extern void call_exit_kernel(void) NoReturn;

/*
 *  �^�X�N�R���e�L�X�g�̏�����
 *
 *  �^�X�N���x�~��Ԃ�����s�ł����ԂɈڍs���鎞�ɌĂ΂��D���̎��_
 *  �ŃX�^�b�N�̈���g���Ă͂Ȃ�Ȃ��D
 *
 *  activate_context���C�C�����C���֐��ł͂Ȃ��}�N����`�Ƃ��Ă���̂́C
 *  ���̎��_�ł�TCB����`����Ă��Ȃ����߂ł���D
 */
extern void	start_r(void);

#define activate_context(p_tcb)											\
{																		\
	(p_tcb)->tskctxb.msp = (void *)((char *)((p_tcb)->p_tinib->stk)		\
										+ (p_tcb)->p_tinib->stksz);		\
	(p_tcb)->tskctxb.pc = (void *) start_r;								\
}

/*
 *  calltex�͎g�p���Ȃ�
 */
#define OMIT_CALLTEX

/*
 *  ��O�x�N�^�e�[�u���̍\���̒�`
 */
typedef struct exc_vector_entry {
	FP		exc_handler;		/* ��O�n���h���̋N���Ԓn */
} EXCVE;

/*
 *  �����݃n���h���ԍ���CPU��O�n���h���ԍ��͈̔͂̔���
 */
#define VALID_INHNO_DEFINH(inhno)	((0x10U <= (inhno) && (inhno) <= 0x1fU) \
									|| (0x40U <= (inhno) && (inhno) <= 0xffU))
#define VALID_EXCNO_DEFEXC(excno)	((0x02U <= (excno) && (excno) <= 0x0fU) \
									|| (0x20U <= (excno) && (excno) <= 0x3fU))

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ�inhno�̊����݃n���h���̏o���������̔Ԓn��int_entry�ɐ�
 *  �肷��D
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{
	EXCVE	*excvt;

	assert(VALID_INHNO_DEFINH(inhno));

#ifdef EXCVT_KERNEL
	/*
	 *  EXCVT_KERNEL����`����Ă��鎞�́C�����������̒���VBR��
	 *  EXCVT_KERNEL�ɐݒ肷��̂ŁCEXCVT_KERNEL���g���D
	 */
	excvt = (EXCVE *) EXCVT_KERNEL;
#else /* EXCVT_KERNEL */
	excvt = (EXCVE *) current_vbr();
#endif /* EXCVT_KERNEL */
	excvt[inhno].exc_handler = int_entry;
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ�excno��CPU��O�n���h���̏o���������̔Ԓn��exc_entry�ɐ�
 *  �肷��D
 */
Inline void
x_define_exc(EXCNO excno, FP exc_entry)
{
	EXCVE	*excvt;

	assert(VALID_EXCNO_DEFEXC(excno));

#ifdef EXCVT_KERNEL
	/*
	 *  EXCVT_KERNEL����`����Ă��鎞�́C�����������̒���VBR��
	 *  EXCVT_KERNEL�ɐݒ肷��̂ŁCEXCVT_KERNEL���g���D
	 */
	excvt = (EXCVE *) EXCVT_KERNEL;
#else /* EXCVT_KERNEL */
	excvt = (EXCVE *) current_vbr();
#endif /* EXCVT_KERNEL */
	excvt[excno].exc_handler = exc_entry;
}

/*
 *  �����݃n���h���̏o���������̐���
 */

/*
 *  �����݃n���h���̏o���������̃��x�������}�N��
 */
#define INT_ENTRY(inhno, inthdr)	_kernel_##inthdr##_##inhno

/*
 *  LOG_INH_ENTER���}�N����`����Ă���ꍇ�ɁCCALL_LOG_INH_ENTER���C
 *  inhno_num���p�����[�^�Ƃ���log_inh_enter���Ăяo���A�Z���u������R�[
 *  �h�Ƀ}�N����`����D
 */
#ifdef LOG_INH_ENTER

#define CALL_LOG_INH_ENTER(inhno_num) \
"	move.l #" #inhno_num ", -(%sp)	\n"  /* inhno_num���p�����[�^�� */ \
"	jsr _kernel_log_inh_enter		\n"  /* log_inh_enter���Ăяo�� */ \
"	addq.l #4, %sp					\n"

#else /* LOG_INH_ENTER */
#define CALL_LOG_INH_ENTER(inhno_num)
#endif /* LOG_INH_ENTER */

#ifdef LOG_INH_LEAVE

/*
 *  CALL_LOG_INH_LEAVE���Cinhno_num���p�����[�^�Ƃ���log_inh_leave����
 *  �яo���A�Z���u������R�[�h�Ƀ}�N����`����D
 */
#define CALL_LOG_INH_LEAVE(inhno_num) \
"	move.l #" #inhno_num ", -(%sp)	\n"  /* inhno_num���p�����[�^�� */ \
"	jsr _kernel_log_inh_leave		\n"  /* log_inh_leave���Ăяo�� */ \
"	addq.l #4, %sp					\n"

/*
 *  LOG_INH_LEAVE���}�N����`����Ă���ꍇ�̊����݃n���h���̏o���������D
 *  �����݃n���h�����T�u���[�`���R�[�����C�߂��Ă�����C�g���[�X���O��
 *  �擾��Cret_int�ɕ��򂷂�D
 */
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) \
extern void _kernel_##inthdr##_##inhno(void); \
asm(".text							\n" \
"_kernel_" #inthdr "_" #inhno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* �X�N���b�`���W�X�^��ۑ� */ \
	CALL_LOG_INH_ENTER(inhno_num) \
"	jsr " #inthdr "					\n"  /* �����݃n���h�����Ăяo�� */ \
	CALL_LOG_INH_LEAVE(inhno_num) \
"	jmp _kernel_ret_int				\n");/* ret_int�֕��� */

#else /* LOG_INH_LEAVE */

/*
 *  LOG_INH_LEAVE���}�N����`����Ă��Ȃ��ꍇ�̊����݃n���h���̏o������
 *  ���D�߂�Ԓn�Ƃ���ret_int���X�^�b�N�ɐς񂾌�C�����݃n���h���̋N��
 *  �Ԓn�ɕ��򂷂�D�����݃n���h������̃��^�[���ɂ��Cret_int�֕���
 *  ��D
 */
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) \
extern void _kernel_##inthdr##_##inhno(void); \
asm(".text							\n" \
"_kernel_" #inthdr "_" #inhno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* �X�N���b�`���W�X�^��ۑ� */ \
	CALL_LOG_INH_ENTER(inhno_num) \
"	move.l #_kernel_ret_int, -(%sp)	\n"  /* �߂�Ԓn���X�^�b�N�ɐς� */ \
"	jmp " #inthdr "					\n");/* �����݃n���h���֕��� */

#endif /* LOG_INH_LEAVE */

/*
 *  CPU��O�n���h���̏o���������̐���
 *
 *  CPU��O�n���h���̔Ԓn��A1�ɁCCPU��O�n���h���ԍ���D1�ɓ���āC
 *  exchdr_entry�ɕ��򂷂�D�����݃n���h���̏o���������Ɠ��l�ɁCCPU��O
 *  �n���h������CPU��O�n���h�����Ăяo��������W�J������@�����邪�C�W
 *  �J���鏈�����e�����G�ł��邽�߁C�̗p���Ă��Ȃ��D
 */

/*
 *  CPU��O�n���h���̏o���������̃��x�������}�N��
 */
#define EXC_ENTRY(excno, exchdr)	_kernel_##exchdr##_##excno

/*
 *  CPU��O�n���h���̏o��������
 */
#define EXCHDR_ENTRY(excno, excno_num, exchdr) \
extern void _kernel_##exchdr##_##excno(void *sp); \
asm(".text							\n" \
"_kernel_" #exchdr "_" #excno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* �X�N���b�`���W�X�^��ۑ� */ \
"	lea.l " #exchdr ", %a1			\n"  /* CPU��O�n���h���̔Ԓn��A1�� */ \
"	move.l #" #excno_num ", %d1		\n"  /* excno_num��D1�� */ \
"	jmp _kernel_exchdr_entry		\n");/* exchdr_entry�ɕ��� */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 *
 *  CPU��O�̔����������̃R���e�L�X�g���C�^�X�N�R���e�L�X�g�̎���false�C
 *  �����łȂ�����true��Ԃ��D
 */
Inline bool_t
exc_sense_context(void *p_excinf)
{
	return((*((uint16_t *) p_excinf) & 0x1000U) == 0U);
}

/*
 *  CPU��O�̔�����������IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�C�����\
 *  ���j�̎Q��
 */
Inline uint16_t
exc_get_iipm(void *p_excinf)
{
	return(*((uint16_t *) p_excinf) & 0x0700U);
}

/*
 *  CPU��O�̔����������̃R���e�L�X�g�Ɗ����݂̃}�X�N��Ԃ̎Q��
 *
 *  CPU��O�̔����������̃V�X�e����Ԃ��C�J�[�l�����s���łȂ��C�^�X�N�R
 *  ���e�L�X�g�ł���C�S�����݃��b�N��ԂłȂ��CCPU���b�N��ԂłȂ��C��
 *  ���ݗD��x�}�X�N�S������Ԃł��鎞��true�C�����łȂ�����false��Ԃ�
 *  �iCPU��O���J�[�l���Ǘ��O�̊����ݏ������Ŕ��������ꍇ�ɂ�false���
 *  ���j�D
 *
 *  M68040�ł́CCPU��O�̔�����������IPM�i�n�[�h�E�F�A�̊����ݗD��x�}
 *  �X�N�j�����ׂĂ̊����݂��������Ԃł��邱�Ƃ��`�F�b�N���邱�ƂŁC
 *  �J�[�l�����s���łȂ����ƁC�S�����݃��b�N��ԂłȂ����ƁCCPU���b�N��
 *  �ԂłȂ����ƁC�����ݗD��x�}�X�N�S������Ԃł��邱�Ƃ�4�̏�����
 *  �`�F�b�N���邱�Ƃ��ł���iCPU��O��������������lock_flag���Q�Ƃ���
 *  �K�v�͂Ȃ��j�D
 */
Inline bool_t
exc_sense_intmask(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
					&& exc_get_iipm(p_excinf) == IIPM_ENAALL);
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	prc_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	prc_terminate(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_PRC_CONFIG_H */

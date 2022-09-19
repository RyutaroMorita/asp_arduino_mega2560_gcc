/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2012 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: trace_config.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�g���[�X���O�Ɋւ���ݒ�
 *
 *  ���̃C���N���[�h�t�@�C���́Ctarget_config.h�����target_syssvc.h��
 *  �݂���C���N���[�h�����D�܂��C�g���[�X���O�@�\�̏�������L�^�̊J
 *  �n�^��~�C�g���[�X���O�̃_���v���s���v���O��������C���N���[�h����
 *  ���Ƃ�z�肵�Ă���D
 */

#ifndef TOPPERS_TRACE_CONFIG_H
#define TOPPERS_TRACE_CONFIG_H

/*
 *  �g���[�X���O�o�b�t�@�̃T�C�Y
 */
#ifndef TCNT_TRACE_BUFFER
#define TCNT_TRACE_BUFFER	1024
#endif /* TCNT_TRACE_BUFFER */

/*
 *  �g���[�X�����̎擾���@
 */
#ifndef TRACE_GET_TIM
#define TRACE_GET_TIM()		(current_time)
#endif /* TRACE_GET_TIM */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �g���[�X���O�̃f�[�^�\��
 *
 *  �V�X�e�����O�@�\�̃��O���̃f�[�^�\���Ɠ������̂�p����D
 */
#include <t_syslog.h>
typedef	SYSLOG	TRACE;

/*
 *  �g���[�X���O�o�b�t�@�Ƃ���ɃA�N�Z�X���邽�߂̃|�C���^
 */
extern TRACE	trace_buffer[];		/* �g���[�X���O�o�b�t�@ */
extern uint_t	trace_count;		/* �g���[�X���O�o�b�t�@���̃��O�̐� */
extern uint_t	trace_head;			/* �擪�̃g���[�X���O�̊i�[�ʒu */
extern uint_t	trace_tail;			/* ���̃g���[�X���O�̊i�[�ʒu */
extern uint_t	trace_lost;			/* ����ꂽ�g���[�X�̐� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �g���[�X���[�h�̒�`
 */
#define TRACE_STOP			UINT_C(0x00)	/* �g���[�X��~ */
#define TRACE_RINGBUF		UINT_C(0x01)	/* �����O�o�b�t�@���[�h */
#define TRACE_AUTOSTOP		UINT_C(0x02)	/* ������~���[�h */
#define TRACE_CLEAR			UINT_C(0x04)	/* �g���[�X���O�̃N���A */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �g���[�X���O�@�\�̏�����
 *
 *  �g���[�X���O�@�\������������D���������[�`���Ƃ��ēo�^���邱�Ƃ�z
 *  �肵�Ă���D�����ɂ�莟�̓�����s���D
 *
 *  TRACE_STOP�F�������݂̂Ńg���[�X�͊J�n���Ȃ��D
 *  TRACE_RINGBUF�F�����O�o�b�t�@���[�h�Ńg���[�X���J�n�D
 *  TRACE_AUTOSTOP�F������~���[�h�Ńg���[�X���J�n�D
 */
extern void	trace_initialize(intptr_t exinf);

/*
 *  �g���[�X���O�̊J�n
 *
 *  �g���[�X���O�̋L�^���J�n�^��~����D�����ɂ�莟�̓�����s���D
 *
 *  TRACE_STOP�F�g���[�X���~�D
 *  TRACE_RINGBUF�F�����O�o�b�t�@���[�h�Ńg���[�X���J�n�D
 *  TRACE_AUTOSTOP�F������~���[�h�Ńg���[�X���J�n�D
 *  TRACE_CLEAR�F�g���[�X���O���N���A�D
 */
extern ER	trace_sta_log(MODE mode);

/*
 *  �g���[�X���O�̏�����
 */
extern ER	trace_wri_log(TRACE *p_trace);

/*
 *  �g���[�X���O�̓Ǐo��
 */
extern ER	trace_rea_log(TRACE *p_trace);

/* 
 *  �g���[�X���O�̃_���v�itrace_dump.c�j
 *
 *  �g���[�X���O���_���v����D�I���������[�`���Ƃ��ēo�^���邱�Ƃ��z��
 *  ���Ă���D�����Ƃ��āC�_���v��ƂȂ镶���o�͊֐��ւ̃|�C���^��n���D
 *  �^�[�Q�b�g�ˑ��̒჌�x�������o�͂𗘗p����ꍇ�ɂ́Ctarget_putc��n
 *  ���D
 */
extern void	trace_dump(intptr_t exinf);

/*
 *  �g���[�X���O���o�͂��邽�߂̃��C�u�����֐�
 */
extern void	trace_write_0(uint_t type);
extern void	trace_write_1(uint_t type, intptr_t arg1);
extern void	trace_write_2(uint_t type, intptr_t arg1, intptr_t arg2);
extern void	trace_write_3(uint_t type, intptr_t arg1, intptr_t arg2,
														intptr_t arg3);

/*
 *  �g���[�X���O���o�͂��邽�߂̃}�N��
 */

#define trace_0(type) \
				trace_write_0(type)

#define trace_1(type, arg1) \
				trace_write_1(type, (intptr_t)(arg1))

#define trace_2(type, arg1, arg2) \
				trace_write_2(type, (intptr_t)(arg1), (intptr_t)(arg2))

#define trace_3(type, arg1, arg2, arg3) \
				trace_write_3(type, (intptr_t)(arg1), (intptr_t)(arg2), \
						(intptr_t)(arg3))

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �g���[�X���O���@�̐ݒ�
 */
#define LOG_TSKSTAT(p_tcb)		trace_2(LOG_TYPE_TSKSTAT, p_tcb, p_tcb->tstat)

#define LOG_DSP_LEAVE(p_tcb)	trace_1(LOG_TYPE_DSP|LOG_LEAVE, p_tcb)

#define LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog) \
								trace_wri_log((TRACE *) p_syslog)

#endif /* TOPPERS_TRACE_CONFIG_H */

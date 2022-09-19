/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: t_syslog.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�V�X�e�����O�o�͂��s�����߂̒�`
 *
 *  �V�X�e�����O�T�[�r�X�́C�V�X�e���̃��O�����o�͂��邽�߂̃T�[�r�X
 *  �ł���D�J�[�l������̃��O���̏o�͂ɂ��p���邽�߁C�����ő҂����
 *  �ɂ͂��邱�Ƃ͂Ȃ��D
 *
 *  ���O���́C�J�[�l�����̃��O�o�b�t�@�ɏ������ނ��C�჌�x���̕����o
 *  �͊֐���p���ďo�͂���D�ǂ�����g�����́C�g���T�[�r�X�R�[���Ő؂�
 *  �����邱�Ƃ��ł���D
 *
 *  ���O�o�b�t�@�̈悪�I�[�o�t���[�����ꍇ�ɂ́C�Â����O���������ď�
 *  ��������D
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă������ƂŁC�}�N����`�ȊO�̋L�q��
 *  �������Ƃ��ł���D
 *
 *  ���̃t�@�C�����C���N���[�h����O�ɁCt_stddef.h���C���N���[�h���Ă�
 *  �����Ƃ��K�v�ł���D
 */

#ifndef TOPPERS_T_SYSLOG_H
#define TOPPERS_T_SYSLOG_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ���O���̎�ʂ̒�`
 */
#define LOG_TYPE_COMMENT	UINT_C(0x01)	/* �R�����g */
#define LOG_TYPE_ASSERT		UINT_C(0x02)	/* �A�T�[�V�����̎��s */

#define LOG_TYPE_INH		UINT_C(0x11)	/* �����݃n���h�� */
#define LOG_TYPE_ISR		UINT_C(0x12)	/* �����݃T�[�r�X���[�`�� */
#define LOG_TYPE_CYC		UINT_C(0x13)	/* �����n���h�� */
#define LOG_TYPE_ALM		UINT_C(0x14)	/* �A���[���n���h�� */
#define LOG_TYPE_OVR		UINT_C(0x15)	/* �I�[�o�����n���h�� */
#define LOG_TYPE_EXC		UINT_C(0x16)	/* CPU��O�n���h�� */
#define LOG_TYPE_TEX		UINT_C(0x17)	/* �^�X�N��O�������[�`�� */
#define LOG_TYPE_TSKSTAT	UINT_C(0x18)	/* �^�X�N��ԕω� */
#define LOG_TYPE_DSP		UINT_C(0x19)	/* �f�B�X�p�b�`�� */
#define LOG_TYPE_SVC		UINT_C(0x1a)	/* �T�[�r�X�R�[�� */

#define LOG_ENTER			UINT_C(0x00)	/* �����^�J�n */
#define LOG_LEAVE			UINT_C(0x80)	/* �o���^�I�� */

/*
 *  ���O���̏d�v�x�̒�`
 */
#define LOG_EMERG			UINT_C(0)		/* �V���b�g�_�E���ɒl����G���[ */
#define LOG_ALERT			UINT_C(1)
#define LOG_CRIT			UINT_C(2)
#define LOG_ERROR			UINT_C(3)		/* �V�X�e���G���[ */
#define LOG_WARNING			UINT_C(4)		/* �x�����b�Z�[�W */
#define LOG_NOTICE			UINT_C(5)
#define LOG_INFO			UINT_C(6)
#define LOG_DEBUG			UINT_C(7)		/* �f�o�b�O�p���b�Z�[�W */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ���O���̃f�[�^�\��
 */

#define TMAX_LOGINFO	6

typedef struct {
	uint_t		logtype;				/* ���O���̎�� */
	SYSTIM		logtim;					/* ���O���� */
	intptr_t	loginfo[TMAX_LOGINFO];	/* ���̑��̃��O��� */
} SYSLOG;

/*
 *  ���O���̏d�v�x�̃r�b�g�}�b�v����邽�߂̃}�N��
 */
#define LOG_MASK(prio)		(1U << (prio))
#define LOG_UPTO(prio)		((1U << ((prio) + 1)) - 1)

/*
 *  �p�P�b�g�`���̒�`
 */
typedef struct t_syslog_rlog {
	uint_t	count;		/* ���O�o�b�t�@���̃��O�̐� */
	uint_t	lost;		/* ����ꂽ���O�̐� */
	uint_t	logmask;	/* ���O�o�b�t�@�ɋL�^���ׂ��d�v�x */
	uint_t	lowmask;	/* �჌�x���o�͂��ׂ��d�v�x */
} T_SYSLOG_RLOG;

/*
 *  ���O�����o�͂��邽�߂̃��C�u�����֐�
 */

#ifndef TOPPERS_OMIT_SYSLOG

extern ER	syslog_wri_log(uint_t prio, const SYSLOG *p_syslog) throw();

Inline void
_syslog_0(uint_t prio, uint_t type)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_1(uint_t prio, uint_t type, intptr_t arg1)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_2(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	logbuf.loginfo[1] = arg2;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_3(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
														intptr_t arg3)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	logbuf.loginfo[1] = arg2;
	logbuf.loginfo[2] = arg3;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_4(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
										intptr_t arg3, intptr_t arg4)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	logbuf.loginfo[1] = arg2;
	logbuf.loginfo[2] = arg3;
	logbuf.loginfo[3] = arg4;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_5(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
							intptr_t arg3, intptr_t arg4, intptr_t arg5)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	logbuf.loginfo[1] = arg2;
	logbuf.loginfo[2] = arg3;
	logbuf.loginfo[3] = arg4;
	logbuf.loginfo[4] = arg5;
	(void) syslog_wri_log(prio, &logbuf);
}

Inline void
_syslog_6(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
				intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6)
{
	SYSLOG	logbuf;

	logbuf.logtype = type;
	logbuf.loginfo[0] = arg1;
	logbuf.loginfo[1] = arg2;
	logbuf.loginfo[2] = arg3;
	logbuf.loginfo[3] = arg4;
	logbuf.loginfo[4] = arg5;
	logbuf.loginfo[5] = arg6;
	(void) syslog_wri_log(prio, &logbuf);
}

/*
 *  ���O���i�R�����g�j���o�͂��邽�߂̃��C�u�����֐��ivasyslog.c�j
 */
extern void	syslog(uint_t prio, const char *format, ...) throw();

#else /* TOPPERS_OMIT_SYSLOG */

/*
 *  �V�X�e�����O�o�͂�}�~����ꍇ
 */

Inline void
_syslog_0(uint_t prio, uint_t type)
{
}

Inline void
_syslog_1(uint_t prio, uint_t type, intptr_t arg1)
{
}

Inline void
_syslog_2(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2)
{
}

Inline void
_syslog_3(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
														intptr_t arg3)
{
}

Inline void
_syslog_4(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
										intptr_t arg3, intptr_t arg4)
{
}

Inline void
_syslog_5(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
							intptr_t arg3, intptr_t arg4, intptr_t arg5)
{
}

Inline void
_syslog_6(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
				intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6)
{
}

Inline void
syslog(uint_t prio, const char *format, ...)
{
}

#endif /* TOPPERS_OMIT_SYSLOG */

/*
 *  ���O���i�R�����g�j���o�͂��邽�߂̃}�N��
 *
 *  format����ь㑱�̈�������쐬�������b�Z�[�W���C�d��xprio�Ń��O��
 *  ��Ƃ��ďo�͂��邽�߂̃}�N���Darg1�`argn��intptr_t�^�ɃL���X�g����
 *  ���߁Cintptr_t�^�Ɍ^�ϊ��ł���C�ӂ̌^�ł悢�D
 */

#define syslog_0(prio, format) \
				_syslog_1(prio, LOG_TYPE_COMMENT, (intptr_t)(format))

#define syslog_1(prio, format, arg1) \
				_syslog_2(prio, LOG_TYPE_COMMENT, (intptr_t)(format), \
														(intptr_t)(arg1))

#define syslog_2(prio, format, arg1, arg2) \
				_syslog_3(prio, LOG_TYPE_COMMENT, (intptr_t)(format), \
										(intptr_t)(arg1), (intptr_t)(arg2))

#define syslog_3(prio, format, arg1, arg2, arg3) \
				_syslog_4(prio, LOG_TYPE_COMMENT, (intptr_t)(format), \
						(intptr_t)(arg1), (intptr_t)(arg2), (intptr_t)(arg3))

#define syslog_4(prio, format, arg1, arg2, arg3, arg4) \
				_syslog_5(prio, LOG_TYPE_COMMENT, (intptr_t)(format), \
						(intptr_t)(arg1), (intptr_t)(arg2), (intptr_t)(arg3), \
														(intptr_t)(arg4))

#define syslog_5(prio, format, arg1, arg2, arg3, arg4, arg5) \
				_syslog_6(prio, LOG_TYPE_COMMENT, (intptr_t)(format), \
						(intptr_t)(arg1), (intptr_t)(arg2), (intptr_t)(arg3), \
										(intptr_t)(arg4), (intptr_t)(arg5))

/*
 *  ���O���i�A�T�[�V�����̎��s�j���o�͂��邽�߂̃}�N��
 */
#ifndef TOPPERS_assert_fail
#define TOPPERS_assert_fail(exp, file, line) \
				_syslog_3(LOG_EMERG, LOG_TYPE_ASSERT, (intptr_t)(file), \
										(intptr_t)(line), (intptr_t)(exp))
#endif /* TOPPERS_assert_fail */

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_T_SYSLOG_H */

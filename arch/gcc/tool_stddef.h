/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
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
 *  @(#) $Id: tool_stddef.h 2243 2011-08-26 21:56:55Z ertl-hiro $
 */

/*
 *		t_stddef.h�̊J�����ˑ����iGCC�p�j
 */

#ifndef TOPPERS_TOOL_STDDEF_H
#define TOPPERS_TOOL_STDDEF_H

/*
 *  �R���p�C���̊g���@�\�̂��߂̃}�N����`
 */
#ifndef __cplusplus					/* C++�ɂ�inline ������ */
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
									/* C99�ɂ�inline ������ */
#define inline	__inline__			/* �C�����C���֐� */
#endif /* !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L */
#endif /* __cplusplus */

#define Inline	static __inline__	/* �C�����C���֐� */

#ifndef __cplusplus					/* C++�ɂ�asm������ */
#define asm		__asm__				/* �C�����C���A�Z���u�� */
#endif /* __cplusplus */

#define Asm		__asm__ volatile	/* �C�����C���A�Z���u���i�œK���}�~�j*/

#define NoReturn	__attribute__((__noreturn__))
									/* ���^�[�����Ȃ��֐� */

/*
 *  �J�����̕W���C���N���[�h�t�@�C���̗��p
 *
 *  NULL�̒�`��stddef.h����CINT_MAX�CINT_MIN�CUINT_MAX�CLONG_MAX�C
 *  LONG_MIN�CULONG_MAX�CCHAR_BIT�̒�`��limits.h�����荞�ށD
 *
 *  C++/EC++�ł́C�W���d�l��͂����̃C���N���[�h�t�@�C�����p�ӂ����
 *  ����Ƃ͌���Ȃ��̂Œ��ӂ��K�v�ł���i�قƂ�ǂ̊J�����ŗp�ӂ���
 *  �Ă���j�D
 */
#ifndef TOPPERS_MACRO_ONLY
#include <stddef.h>
#include <limits.h>
#endif /* TOPPERS_MACRO_ONLY */

/*
 *  stdint.h�̑�p�ƂȂ��`
 *
 *  �J������stdint.h���p�ӂ���Ă��炸�C�e�����^�̃T�C�Y������p�^�[
 *  ���ɓ��Ă͂܂�ꍇ�ɁCstdint.h�̑�p�ƂȂ��`��^����D
 *
 *  TOPPERS_STDINT_TYPE1: char/short/int/long long�̃r�b�g�������ꂼ��
 *                        8/16/32/64�r�b�g�ŁC�|�C���^�̃r�b�g����long
 *                        �̃r�b�g���ƈ�v����ꍇ
 */
#ifdef TOPPERS_STDINT_TYPE1

/*
 *  �R���p�C���ˑ��̃f�[�^�^�̒�`
 */
#ifndef TOPPERS_MACRO_ONLY

typedef signed char			int8_t;		/* �����t��8�r�b�g���� */
typedef unsigned char		uint8_t;	/* ��������8�r�b�g���� */

typedef signed short		int16_t;	/* �����t��16�r�b�g���� */
typedef unsigned short		uint16_t;	/* ��������16�r�b�g���� */

typedef signed int			int32_t;	/* �����t��32�r�b�g���� */
typedef unsigned int		uint32_t;	/* ��������32�r�b�g���� */

typedef signed long long	int64_t;	/* �����t��64�r�b�g���� */
typedef unsigned long long	uint64_t;	/* ��������64�r�b�g���� */

typedef int8_t				int_least8_t;	/* 8�r�b�g�ȏ�̕����t������ */
typedef uint8_t				uint_least8_t;	/* 8�r�b�g�ȏ�̕����������� */

typedef long				intptr_t;	/* �|�C���^���i�[�ł��镄���t������ */
typedef unsigned long		uintptr_t;	/* �|�C���^���i�[�ł��镄���������� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �R���p�C���ˑ��̃f�[�^�^�̐����萔�����}�N��
 */
#ifndef INT8_C
#define INT8_C(val)			(val)
#endif /* INT8_C */

#ifndef UINT8_C
#define UINT8_C(val)		(val ## U)
#endif /* UINT8_C */

#ifndef INT16_C
#define INT16_C(val)		(val)
#endif /* INT16_C */

#ifndef UINT16_C
#define UINT16_C(val)		(val ## U)
#endif /* UINT16_C */

#ifndef INT32_C
#define INT32_C(val)		(val)
#endif /* INT32_C */

#ifndef UINT32_C
#define UINT32_C(val)		(val ## U)
#endif /* UINT32_C */

#ifndef INT64_C
#define INT64_C(val)		(val ## LL)
#endif /* INT64_C */

#ifndef UINT64_C
#define UINT64_C(val)		(val ## ULL)
#endif /* UINT64_C */

/*
 *  �R���p�C���ˑ��̃f�[�^�^�Ɋi�[�ł���ő�l�ƍŏ��l�̒�`
 */
#define INT8_MAX			SCHAR_MAX
#define INT8_MIN			SCHAR_MIN
#define UINT8_MAX			UCHAR_MAX

#define INT16_MAX			SHRT_MAX
#define INT16_MIN			SHRT_MIN
#define UINT16_MAX			USHRT_MAX

#define INT32_MAX			INT_MAX
#define INT32_MIN			INT_MIN
#define UINT32_MAX			UINT_MAX

#define INT64_MAX			LLONG_MAX
#define INT64_MIN			LLONG_MIN
#define UINT64_MAX			ULLONG_MAX

#define INT_LEAST8_MAX		INT8_MAX
#define INT_LEAST8_MIN		INT8_MIN
#define UINT_LEAST8_MAX		INT8_MAX

#endif /* TOPPERS_STDINT_TYPE1 */

/*
 *  ���������_�^�Ɋւ����`
 *
 *  TOPPERS_STDFLOAT_TYPE1: float��IEEE754�����̒P���x���������_���C
 *							double���{���x���������_���̏ꍇ
 */
#ifdef TOPPERS_STDFLOAT_TYPE1
#ifndef TOPPERS_MACRO_ONLY

typedef float		float32_t;			/* IEEE754�����̒P���x���������_�� */
typedef double		double64_t;			/* IEEE754�����̔{���x���������_�� */

#endif /* TOPPERS_MACRO_ONLY */

#define FLOAT32_MIN		1.17549435e-38F
#define FLOAT32_MAX		3.40282347e+38F
#define DOUBLE64_MIN	2.2250738585072014e-308
#define DOUBLE64_MAX	1.7976931348623157e+308

#endif /* TOPPERS_STDFLOAT_TYPE1 */
#endif /* TOPPERS_TOOL_STDDEF_H */

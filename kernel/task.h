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
 *  $Id: task.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�X�N�Ǘ����W���[��
 */

#ifndef TOPPERS_TASK_H
#define TOPPERS_TASK_H

#include <queue.h>
#include "time_event.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_TSKSTAT
#define LOG_TSKSTAT(p_tcb)
#endif /* LOG_TSKSTAT */

/*
 *  �^�X�N�D��x�̓����\���E�O���\���ϊ��}�N��
 */
#define INT_PRIORITY(x)		((uint_t)((x) - TMIN_TPRI))
#define EXT_TSKPRI(x)		((PRI)(x) + TMIN_TPRI)

/*
 *  �^�X�N��Ԃ̓����\��
 *
 *  TCB���̃^�X�N��Ԃł́C���s��ԁiRUNNING�j�Ǝ��s�\��ԁiREADY�j
 *  �͋�ʂ��Ȃ��D����Ԃ𑍏̂��āC���s�ł����ԁiRUNNABLE�j�ƌĂԁD
 *  ��d�҂���Ԃ́C(TS_WAITING | TS_SUSPENDED)�ŕ\���DTS_WAIT_???�͑�
 *  ���v����\���C�҂���ԁi��d�҂���Ԃ��܂ށj�̏ꍇ�ɂ̂ݐݒ肷��D
 */
#define TS_DORMANT		0x00U			/* �x�~��� */
#define TS_RUNNABLE		0x01U			/* ���s�ł����� */
#define TS_WAITING		0x02U			/* �҂���� */
#define TS_SUSPENDED	0x04U			/* �����҂���� */

#define TS_WAIT_DLY		(0x00U << 3)	/* ���Ԍo�ߑ҂� */
#define TS_WAIT_SLP		(0x01U << 3)	/* �N���҂� */
#define TS_WAIT_RDTQ	(0x02U << 3)	/* �f�[�^�L���[����̎�M�҂� */
#define TS_WAIT_RPDQ	(0x03U << 3)	/* �D��x�f�[�^�L���[����̎�M�҂� */
#define TS_WAIT_SEM		(0x04U << 3)	/* �Z�}�t�H�����̊l���҂� */
#define TS_WAIT_FLG		(0x05U << 3)	/* �C�x���g�t���O�҂� */
#define TS_WAIT_SDTQ	(0x06U << 3)	/* �f�[�^�L���[�ւ̑��M�҂� */
#define TS_WAIT_SPDQ	(0x07U << 3)	/* �D��x�f�[�^�L���[�ւ̑��M�҂� */
#define TS_WAIT_MBX		(0x08U << 3)	/* ���[���{�b�N�X����̎�M�҂� */
#define TS_WAIT_MPF		(0x09U << 3)	/* �Œ蒷�������u���b�N�̊l���҂� */

/*
 *  �^�X�N��Ԕ��ʃ}�N��
 *
 *  TSTAT_DORMANT�̓^�X�N���x�~��Ԃł��邩�ǂ������CTSTAT_RUNNABLE��
 *  �^�X�N�����s�ł����Ԃł��邩�ǂ����𔻕ʂ���DTSTAT_WAITING�͑�
 *  ����ԂƓ�d�҂���Ԃ̂����ꂩ�ł��邩�ǂ������CTSTAT_SUSPENDED��
 *  �����҂���ԂƓ�d�҂���Ԃ̂����ꂩ�ł��邩�ǂ����𔻕ʂ���D
 */
#define TSTAT_DORMANT(tstat)	((tstat) == TS_DORMANT)
#define TSTAT_RUNNABLE(tstat)	(((tstat) & TS_RUNNABLE) != 0U)
#define TSTAT_WAITING(tstat)	(((tstat) & TS_WAITING) != 0U)
#define TSTAT_SUSPENDED(tstat)	(((tstat) & TS_SUSPENDED) != 0U)

/*
 *  �^�X�N�҂��v�����ʃ}�N��
 *
 *  TSTAT_WAIT_SLP�̓^�X�N���N���҂��ł��邩�ǂ������CTSTAT_WAIT_WOBJ
 *  �̓^�X�N�������E�ʐM�I�u�W�F�N�g�ɑ΂���҂��ł��邩�i����������ƁC
 *  �����ʐM�I�u�W�F�N�g�̑҂��L���[�ɂȂ���Ă��邩�j�ǂ����𔻕ʂ�
 *  ��D�܂��CTSTAT_WAIT_WOBJCB�̓^�X�N�������E�ʐM�I�u�W�F�N�g�̊Ǘ�
 *  �u���b�N�̋��ʕ����iWOBJCB�j�̑҂��L���[�ɂȂ���Ă��邩�ǂ�����
 *  ���ʂ���D
 *
 *  TSTAT_WAIT_SLP�́C�C�ӂ̃^�X�N��Ԃ̒�����C�^�X�N���N���҂��ł���
 *  ���Ƃ𔻕ʂł���D���Ȃ킿�CTSTAT_WAITING�ɂ��҂���Ԃł��邱�Ƃ�
 *  ���ʂ����ɁCTSTAT_SLP������p���ċN���҂���Ԃł��邱�Ƃ𔻕ʂł���D
 *  ����������I�Ɏ������邽�߂ɁCTS_WAIT_SLP�̒l���C(0x00U << 3)�ł͂�
 *  ��(0x01U << 3)�Ƃ��Ă���D���̂��߁C�^�X�N�����Ԍo�ߑ҂���Ԃł���
 *  ���Ƃ𔻕ʂ��邽�߂�TSTAT_WAIT_DLY���CTSTAT_WAIT_SLP�Ɠ��l�̕��@��
 *  �������邱�Ƃ͂ł��Ȃ��D
 */
#define TS_WAIT_MASK	(0x0fU << 3)	/* �҂��v���̎�o���}�X�N */

#define TSTAT_WAIT_SLP(tstat)		(((tstat) & TS_WAIT_MASK) == TS_WAIT_SLP)
#define TSTAT_WAIT_WOBJ(tstat)		(((tstat) & TS_WAIT_MASK) >= TS_WAIT_RDTQ)
#define TSTAT_WAIT_WOBJCB(tstat)	(((tstat) & TS_WAIT_MASK) >= TS_WAIT_SEM)

/*
 *  �҂����u���b�N�iWINFO�j�̒�`
 *
 *  �^�X�N���҂���Ԃ̊Ԃ́CTCB����т���p_winfo�Ŏw�����WINFO������
 *  �悤�ɐݒ肵�Ȃ���΂Ȃ�Ȃ��D
 *
 *  (a) TCB�̃^�X�N��Ԃ�҂���ԁiTS_WAITING�j�ɂ���D���̍ۂɁC�҂�
 *  �v���iTS_WAIT_???�j���ݒ肷��D
 *
 *  (b) �^�C���A�E�g���Ď����邽�߂ɁC�^�C���C�x���g�u���b�N��o�^����D
 *  �o�^����^�C���C�x���g�u���b�N�́C�҂��ɓ���T�[�r�X�R�[�������֐�
 *  �̃��[�J���ϐ��Ƃ��Ċm�ۂ��C����ւ̃|�C���^��WINFO��p_tmevtb�ɋL
 *  ������D�^�C���A�E�g�̊Ď����K�v�Ȃ��ꍇ�i�i�v�҂��̏ꍇ�j�ɂ́C
 *  p_tmevtb��NULL�ɂ���D
 *
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃ̏ꍇ�ɂ́C�W����WINFO��
 *  p_wobjcb�t�B�[���h��ǉ������\���́iWINFO_WOBJ�Cwait.h�Œ�`�j���g
 *  ���D�܂��C�ȉ���(c)�`(e)�̐ݒ���s���K�v������D�����E�ʐM�I�u�W�F
 *  �N�g�Ɋ֌W���Ȃ��҂��i�N���҂��C���Ԍo�ߑ҂��j�̏ꍇ�ɂ́C(c)�`(e)
 *  �͕K�v�Ȃ��D
 *
 *  (c) TCB��҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�̑҂��L���[�ɂȂ��D��
 *  ���L���[�ɂȂ����߂ɁCtask_queue���g���D
 *
 *  (d) �҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�ւ̃|�C���^���C
 *  WINFO_WOBJ��p_wobjcb�ɋL������D
 *
 *  (e) �҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�Ɉˑ����ċL�����邱�Ƃ��K�v��
 *  ��񂪂���ꍇ�ɂ́CWINFO_WOBJ�ɕK�v�ȏ��̂��߂̃t�B�[���h��ǉ�
 *  �����\���̂��`���CWINFO_WOBJ�̑���ɗp����D
 *
 *  �҂���Ԃ���������ۂɂ́C�҂����������^�X�N�ɑ΂���Ԓl��WINFO��
 *  wercd�ɐݒ肷��Dwercd���K�v�Ȃ̂͑҂������ȍ~�ł���̂ɑ΂��āC
 *  p_tmevtb�͑҂�������͕K�v�Ȃ����߁C�������ߖ�̂��߂ɋ��p�̂��g��
 *  �Ă���D���̂��߁Cwercd�փG���[�R�[�h��ݒ肷��̂́C�^�C���C�x���g
 *  �u���b�N��o�^����������ɂ��Ȃ���΂Ȃ�Ȃ��D
 */
typedef union waiting_information {
	ER		wercd;			/* �҂��������̃G���[�R�[�h */
	TMEVTB	*p_tmevtb;		/* �҂���ԗp�̃^�C���C�x���g�u���b�N */
} WINFO;

/*
 *  �^�X�N�������u���b�N
 *
 *  �^�X�N�Ɋւ�������C�l���ς��Ȃ����߂�ROM�ɒu���镔���i�^�X�N
 *  �������u���b�N�j�ƁC�l���ω����邽�߂�RAM�ɒu���Ȃ���΂Ȃ�Ȃ���
 *  ���i�^�X�N�Ǘ��u���b�N�CTCB�j�ɕ������CTCB���ɑΉ�����^�X�N������
 *  �u���b�N���w���|�C���^������D�^�X�N�������u���b�N���ɑΉ�����
 *  TCB���w���|�C���^��������@�̕����CRAM�̐ߖ�̊ϓ_����͖]�܂���
 *  ���C���s�����������Ȃ邽�߂ɍ̗p���Ă��Ȃ��D���̃I�u�W�F�N�g�ɂ�
 *  �Ă����l�Ɉ����D
 *
 *  �^�X�N�������u���b�N�ɂ́CDEF_TEX�Œ�`�����^�X�N��O�������[�`
 *  ���Ɋւ�������܂ށD
 */
typedef struct task_initialization_block {
	ATR			tskatr;			/* �^�X�N���� */
	intptr_t	exinf;			/* �^�X�N�̊g����� */
	TASK		task;			/* �^�X�N�̋N���Ԓn */
	uint_t		ipriority;		/* �^�X�N�̋N�����D��x�i�����\���j */

#ifdef USE_TSKINICTXB
	TSKINICTXB	tskinictxb;		/* �^�X�N�������R���e�L�X�g�u���b�N */
#else /* USE_TSKINICTXB */
	SIZE		stksz;			/* �X�^�b�N�̈�̃T�C�Y�i�ۂ߂��l�j */
	void		*stk;			/* �X�^�b�N�̈�̐擪�Ԓn */
#endif /* USE_TSKINICTXB */

	ATR			texatr;			/* �^�X�N��O�������[�`������ */
	TEXRTN		texrtn;			/* �^�X�N��O�������[�`���̋N���Ԓn */
} TINIB;

/*
 *  TCB���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  �v���Z�b�T�ɂ���ẮCTCB���̃t�B�[���h�̃r�b�g���Ń������g�p�ʂ�
 *  ���\���g���[�h�I�t�ɂȂ邽�߁C�^�[�Q�b�g�ˑ��Ƀt�B�[���h�̃r�b�g��
 *  ��ύX���邱�Ƃ������Ă���D
 */
#ifndef TBIT_TCB_PRIORITY
#define	TBIT_TCB_PRIORITY		8		/* priority�t�B�[���h�̃r�b�g�� */
#endif /* TBIT_TCB_PRIORITY */

/*
 *  �^�X�N�Ǘ��u���b�N�iTCB�j
 *
 *  ASP�J�[�l���ł́C�^�X�N�̋N���v���L���[�C���O���̍ő�l�iTMAX_ACTCNT�j
 *  �ƋN���v���L���[�C���O���̍ő�l�iTMAX_WUPCNT�j��1�ɌŒ肳��Ă���
 *  ���߁C�L���[�C���O����Ă��邩�ǂ����̐^�U�l�ŕ\�����邱�Ƃ��ł���D
 *  �܂��C�����҂��v���l�X�g���̍ő�l�iTMAX_SUSCNT�j��1�ɌŒ肳��Ă�
 *  ��̂ŁC�����҂��v���l�X�g���isuscnt�j�͕K�v�Ȃ��D
 *
 *  TCB�̂������̃t�B�[���h�́C����̃^�X�N��Ԃł̂ݗL���Ȓl��ێ����C
 *  ����ȊO�̏ꍇ�͒l���ۏ؂���Ȃ��i����āC�Q�Ƃ��Ă͂Ȃ�Ȃ��j�D�e
 *  �t�B�[���h���L���Ȓl��ێ���������͎��̒ʂ�D
 *
 *  �E��������͏�ɗL���F
 *  		p_tinib�Ctstat�Cactque
 *  �E�x�~��ԈȊO�ŗL���i�x�~��Ԃł͏����l�ɂȂ��Ă���j�F
 *  		priority�Cwupque�Cenatex�Ctexptn
 *  �E�҂���ԁi��d�҂���Ԃ��܂ށj�ŗL���F
 *  		p_winfo
 *  �E���s�ł����ԂƓ����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���ԂŗL���F
 *  		task_queue
 *  �E���s�\��ԁC�҂���ԁC�����҂���ԁC��d�҂���ԂŗL���F
 *  		tskctxb
 */
typedef struct task_control_block {
	QUEUE			task_queue;		/* �^�X�N�L���[ */
	const TINIB		*p_tinib;		/* �������u���b�N�ւ̃|�C���^ */

#ifdef UINT8_MAX
	uint8_t			tstat;			/* �^�X�N��ԁi�����\���j*/
#else /* UINT8_MAX */
	BIT_FIELD_UINT	tstat : 8;		/* �^�X�N��ԁi�����\���j*/
#endif /* UINT8_MAX */
#if defined(UINT8_MAX) && (TBIT_TCB_PRIORITY == 8)
	uint8_t			priority;		/* ���݂̗D��x�i�����\���j*/
#else /* defined(UINT8_MAX) && (TBIT_TCB_PRIORITY == 8) */
	BIT_FIELD_UINT	priority : TBIT_TCB_PRIORITY;
									/* ���݂̗D��x�i�����\���j*/
#endif /* defined(UINT8_MAX) && (TBIT_TCB_PRIORITY == 8) */
	BIT_FIELD_BOOL	actque : 1;		/* �N���v���L���[�C���O */
	BIT_FIELD_BOOL	wupque : 1;		/* �N���v���L���[�C���O */
	BIT_FIELD_BOOL	enatex : 1;		/* �^�X�N��O��������� */

	TEXPTN			texptn;			/* �ۗ���O�v�� */
	WINFO			*p_winfo;		/* �҂����u���b�N�ւ̃|�C���^ */
	TSKCTXB			tskctxb;		/* �^�X�N�R���e�L�X�g�u���b�N */
} TCB;

/*
 *  ���s��Ԃ̃^�X�N
 *
 *  ���s��Ԃ̃^�X�N�i���v���Z�b�T���R���e�L�X�g�������Ă���^�X�N�j��
 *  TCB���w���|�C���^�D���s��Ԃ̃^�X�N���Ȃ��ꍇ��NULL�ɂ���D
 *
 *  �T�[�r�X�R�[���̏������ŁC���^�X�N�i�T�[�r�X�R�[�����Ăяo�����^�X
 *  �N�j�Ɋւ�������Q�Ƃ���ꍇ��p_runtsk���g���Dp_runtsk����������
 *  ��̂́C�f�B�X�p�b�`���i�Ə����������j�݂̂ł���D
 */
extern TCB	*p_runtsk;

/*
 *  �ō��D�揇�ʂ̃^�X�N
 *
 *  ���s�ł���^�X�N�̒��ōō��D�揇�ʂ̃^�X�N��TCB���w���|�C���^�D��
 *  �s�ł���^�X�N���Ȃ��ꍇ��NULL�ɂ���D
 *
 *  �f�B�X�p�b�`�֎~��ԂȂǁC�f�B�X�p�b�`���ۗ�����Ă���Ԃ�p_runtsk
 *  �ƈ�v���Ă���Ƃ͌���Ȃ��D
 */
extern TCB	*p_schedtsk;

/*
 *  �f�B�X�p�b�`�^�^�X�N��O�������[�`���N���v���t���O
 *
 *  �����݃n���h���^CPU��O�n���h���̏o�������ɁC�f�B�X�p�b�`�܂���
 *  �^�X�N��O�������[�`���̋N����v�����邱�Ƃ������t���O�D
 */
extern bool_t	reqflg;

/*
 *  �����ݗD��x�}�X�N�S�������
 *
 *  �����ݗD��x�}�X�N�S������Ԃł��邱�Ƃ������t���O�D
 */
extern bool_t	ipmflg;

/*
 *  �f�B�X�p�b�`�֎~���
 *
 *  �f�B�X�p�b�`�֎~��Ԃł��邱�Ƃ������t���O�D
 */
extern bool_t	disdsp;

/*
 *  �^�X�N�f�B�X�p�b�`�\���
 *
 *  �����ݗD��x�}�X�N�S������Ԃł���C�f�B�X�p�b�`����Ԃł���i�f�B
 *  �X�p�b�`�֎~��ԂłȂ��j���Ƃ������t���O�D
 */
extern bool_t	dspflg;

/*
 *  ���f�B�L���[
 *
 *  ���f�B�L���[�́C���s�ł����Ԃ̃^�X�N���Ǘ����邽�߂̃L���[�ł���D
 *  ���s��Ԃ̃^�X�N���Ǘ����Ă��邽�߁C���f�B�i���s�\�j�L���[�Ƃ���
 *  ���̂͐��m�ł͂Ȃ����C���f�B�L���[�Ƃ������̂��蒅���Ă��邽�߁C��
 *  �̖��̂ŌĂԂ��Ƃɂ���D
 *
 *  ���f�B�L���[�́C�D��x���Ƃ̃^�X�N�L���[�ō\������Ă���D�^�X�N��
 *  TCB�́C�Y������D��x�̃L���[�ɓo�^�����D
 */
extern QUEUE	ready_queue[TNUM_TPRI];

/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v
 *
 *  ���f�B�L���[�̃T�[�`�������悭�s�����߂ɁC�D��x���Ƃ̃^�X�N�L���[
 *  �Ƀ^�X�N�������Ă��邩�ǂ����������r�b�g�}�b�v��p�ӂ��Ă���D�r�b
 *  �g�}�b�v���g�����ƂŁC�������A�N�Z�X�̉񐔂����炷���Ƃ��ł��邪�C
 *  �r�b�g���얽�߂��[�����Ă��Ȃ��v���Z�b�T�ŁC�D��x�̒i�K�������Ȃ�
 *  �ꍇ�ɂ́C�r�b�g�}�b�v����̃I�[�o�[�w�b�h�̂��߂ɁC�t�Ɍ���������
 *  ��\��������D
 *
 *  �D��x��16�i�K�ł��邱�Ƃ����肵�Ă��邽�߁Cuint16_t�^�Ƃ��Ă���D
 */
extern uint16_t	ready_primap;

/*
 *  �^�X�NID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_tskid;

/*
 *  �^�X�N�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const TINIB	tinib_table[];

/*
 *  �^�X�N���������e�[�u���ikernel_cfg.c�j
 */
extern const ID	torder_table[];

/*
 *  TCB�̃G���A�ikernel_cfg.c�j
 */
extern TCB	tcb_table[];

/*
 *  �^�X�N�̐�
 */
#define tnum_tsk	((uint_t)(tmax_tskid - TMIN_TSKID + 1))

/*
 *  �^�X�NID����TCB�����o�����߂̃}�N��
 */
#define INDEX_TSK(tskid)	((uint_t)((tskid) - TMIN_TSKID))
#define get_tcb(tskid)		(&(tcb_table[INDEX_TSK(tskid)]))
#define get_tcb_self(tskid)	((tskid) == TSK_SELF ? p_runtsk : get_tcb(tskid))

/*
 *  TCB����^�X�NID�����o�����߂̃}�N��
 */
#define	TSKID(p_tcb)	((ID)(((p_tcb) - tcb_table) + TMIN_TSKID))

/*
 *  �^�X�N�Ǘ����W���[���̏�����
 */
extern void	initialize_task(void);

/*
 *  �ō��D�揇�ʃ^�X�N�̃T�[�`
 *
 *  ���f�B�L���[���̍ō��D�揇�ʂ̃^�X�N���T�[�`���C����TCB�ւ̃|�C���^
 *  ��Ԃ��D���f�B�L���[����̏ꍇ�ɂ́C���̊֐����Ăяo���Ă͂Ȃ�Ȃ��D
 */
extern TCB	*search_schedtsk(void);

/*
 *  ���s�ł����Ԃւ̑J��
 *
 *  p_tcb�Ŏw�肳���^�X�N�����f�B�L���[�ɑ}������D���f�B�L���[�ɑ}��
 *  �����^�X�N�̗D��x���C�ō��D�揇�ʂ̃^�X�N�̗D��x���������ꍇ�́C
 *  �ō��D�揇�ʂ̃^�X�N���X�V���C�f�B�X�p�b�`����Ԃł����true���
 *  ���D�����łȂ��ꍇ��false��Ԃ��D
 */
extern bool_t	make_runnable(TCB *p_tcb);

/*
 *  ���s�ł����Ԃ��瑼�̏�Ԃւ̑J��
 *
 *  p_tcb�Ŏw�肳���^�X�N�����f�B�L���[����폜����Dp_tcb�Ŏw�肵��
 *  �^�X�N���ō��D�揇�ʂ̃^�X�N�ł������ꍇ�ɂ́C�ō��D�揇�ʂ̃^�X�N
 *  ��ݒ肵�Ȃ����C�f�B�X�p�b�`����Ԃł����true��Ԃ��D�����łȂ�
 *  �ꍇ��false��Ԃ��D�^�X�N�̏�Ԃ͍X�V���Ȃ��D
 */
extern bool_t	make_non_runnable(TCB *p_tcb);

/*
 *  �x�~��Ԃւ̑J��
 *
 *  p_tcb�Ŏw�肳���^�X�N�̏�Ԃ��x�~��ԂƂ���D�܂��C�^�X�N�̋N��
 *  ���ɏ��������ׂ��ϐ��̏������ƁC�^�X�N�N���̂��߂̃R���e�L�X�g���
 *  �肷��D
 */
extern void	make_dormant(TCB *p_tcb);

/*
 *  �x�~��Ԃ�����s�ł����Ԃւ̑J��
 *
 *  p_tcb�Ŏw�肳���^�X�N�̏�Ԃ��x�~��Ԃ�����s�ł����ԂƂ���D
 *  ���s�ł����ԂɑJ�ڂ����^�X�N�ւ̃f�B�X�p�b�`���K�v�ȏꍇ��true�C
 *  �����łȂ��ꍇ��false��Ԃ��D
 */
extern bool_t	make_active(TCB *p_tcb);

/*
 *  �^�X�N�̗D��x�̕ύX
 *
 *  p_tcb�Ŏw�肳���^�X�N�̗D��x��newpri�i�����\���j�ɕύX����D�܂��C
 *  �K�v�ȏꍇ�ɂ͍ō��D�揇�ʂ̃^�X�N���X�V���C�f�B�X�p�b�`����Ԃ�
 *  �����true��Ԃ��D�����łȂ��ꍇ��false��Ԃ��D
 */
extern bool_t	change_priority(TCB *p_tcb, uint_t newpri);

/*
 *  ���f�B�L���[�̉�]
 *
 *  ���f�B�L���[���́Cpri�Ŏw�肳���D��x�̃^�X�N�L���[����]������D
 *  �܂��C�K�v�ȏꍇ�ɂ͍ō��D�揇�ʂ̃^�X�N��ύX���C�f�B�X�p�b�`����
 *  ������Ă��Ȃ����true��Ԃ��D�����łȂ��ꍇ��false��Ԃ��D
 */
extern bool_t	rotate_ready_queue(uint_t pri);

/*
 *  �^�X�N��O�������[�`���̌ďo��
 *
 *  �^�X�N��O�������[�`�����Ăяo���D�Ăяo���O�ɁC���s��Ԃ̃^�X�N��
 *  �ۗ���O�v�����N���A���C�^�X�N��O�����֎~��Ԃɂ��CCPU���b�N����
 *  ������D
 *
 *  �^�X�N��O�������[�`������߂�ƁC�܂�CPU���b�N��Ԃɖ߂��C���̊�
 *  �ɕۗ���O�v����0�łȂ��Ȃ��Ă���΁C�Ăу^�X�N��O�������[�`����
 *  �Ăяo���D�ۗ���O�v����0�̏ꍇ�ɂ́C��O��������Ԃɂ��Ċ֐���
 *  �烊�^�[������D
 *
 *  ���̊֐��́C���s��Ԃ̃^�X�N���C�^�X�N��O��������ԁienatex��
 *  true�j�ŁC�ۗ���O�v����0�łȂ��itexptn��0�łȂ��j�ꍇ�ɌĂяo����
 *  �Ƃ�z�肵�Ă���D���̊֐��́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�
 *  �Ȃ��D
 */
extern void	call_texrtn(void);

/*
 *  �^�X�N��O�������[�`���̋N��
 *
 *  ���s��Ԃ̃^�X�N���^�X�N��O�������[�`���̋N�������𖞂����Ă���΁C
 *  �^�X�N��O�������[�`�����Ăяo���DCPU��O�������[�`�����Ăяo����
 *  �́C�ꎞ�I��CPU���b�N����������D
 *
 *  ���̊֐��́C�f�B�X�p�b�`���⊄���݃n���h���^CPU��O�n���h���̏o��
 *  ��������Ăяo����邱�Ƃ�z�肵�Ă���D���̊֐��́CCPU���b�N���
 *  �ŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 *
 *  ���s�������グ�邽�߂ɁC���̊֐����^�[�Q�b�g�ˑ����ŋL�q���Ă��悢�D
 *  ���̏ꍇ�ɂ́COMIT_CALLTEX���}�N����`����D
 */
extern void	calltex(void);

#endif /* TOPPERS_TASK_H */

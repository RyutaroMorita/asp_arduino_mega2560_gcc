/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2014 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: kernel.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		TOPPERS/ASP�J�[�l�� �W���w�b�_�t�@�C��
 *
 *  TOPPERS/ASP�J�[�l�����T�|�[�g����T�[�r�X�R�[���̐錾�ƁC�K�v�ȃf�[
 *  �^�^�C�萔�C�}�N���̒�`���܂ރw�b�_�t�@�C���D
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă����D����ɂ��C�}�N����`�ȊO��
 *  �����悤�ɂȂ��Ă���D
 *
 *  ���̃t�@�C�����C���N���[�h����O�ɃC���N���[�h���Ă����ׂ��t�@�C��
 *  �͂Ȃ��D
 */

#ifndef TOPPERS_KERNEL_H
#define TOPPERS_KERNEL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	TOPPERS���ʂ̃f�[�^�^�E�萔�E�}�N��
 */
#include <t_stddef.h>

/*
 *  �^�[�Q�b�g�ˑ���
 */
#include "target_kernel.h"

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �f�[�^�^�̒�`
 */

/*
 *  �r�b�g�p�^�[����I�u�W�F�N�g�ԍ��̌^��`
 */
typedef	uint_t		TEXPTN;		/* �^�X�N��O�v���̃r�b�g�p�^�[�� */
typedef	uint_t		FLGPTN;		/* �C�x���g�t���O�̃r�b�g�p�^�[�� */
typedef	uint_t		INTNO;		/* �����ݔԍ� */
typedef	uint_t		INHNO;		/* �����݃n���h���ԍ� */
typedef	uint_t		EXCNO;		/* CPU��O�n���h���ԍ� */

/*
 *  �����P�ʂ̌^��`
 */
typedef void	(*TASK)(intptr_t exinf);
typedef void	(*TEXRTN)(TEXPTN texptn, intptr_t exinf);
typedef void	(*CYCHDR)(intptr_t exinf);
typedef void	(*ALMHDR)(intptr_t exinf);
typedef void	(*ISR)(intptr_t exinf);
typedef void	(*INTHDR)(void);
typedef void	(*EXCHDR)(void *p_excinf);
typedef void	(*INIRTN)(intptr_t exinf);
typedef void	(*TERRTN)(intptr_t exinf);

/*
 *  �������̈�m�ۂ̂��߂̌^��`
 */
#ifndef TOPPERS_STK_T
#define TOPPERS_STK_T	intptr_t
#endif /* TOPPERS_STK_T */
typedef	TOPPERS_STK_T	STK_T;	/* �X�^�b�N�̈���m�ۂ��邽�߂̌^ */

#ifndef TOPPERS_MPF_T
#define TOPPERS_MPF_T	intptr_t
#endif /* TOPPERS_MPF_T */
typedef	TOPPERS_MPF_T	MPF_T;	/* �Œ蒷�������v�[���̈���m�ۂ��邽�߂̌^ */

/*
 *  ���b�Z�[�W�w�b�_�̌^��`
 */
typedef	struct t_msg {			/* ���[���{�b�N�X�̃��b�Z�[�W�w�b�_ */
	struct t_msg	*pk_next;
} T_MSG;

typedef	struct t_msg_pri {		/* �D��x�t�����b�Z�[�W�w�b�_ */
	T_MSG	msgque;				/* ���b�Z�[�W�w�b�_ */
	PRI		msgpri;				/* ���b�Z�[�W�D��x */
} T_MSG_PRI;

/*
 *  �p�P�b�g�`���̒�`
 */
typedef struct t_rtsk {
	STAT	tskstat;	/* �^�X�N��� */
	PRI		tskpri;		/* �^�X�N�̌��ݗD��x */
	PRI		tskbpri;	/* �^�X�N�̃x�[�X�D��x */
	STAT	tskwait;	/* �҂��v�� */
	ID		wobjid;		/* �҂��Ώۂ̃I�u�W�F�N�g��ID */
	TMO		lefttmo;	/* �^�C���A�E�g����܂ł̎��� */
	uint_t	actcnt;		/* �N���v���L���[�C���O�� */
	uint_t	wupcnt;		/* �N���v���L���[�C���O�� */
} T_RTSK;

typedef struct t_rtex {
	STAT	texstat;	/* �^�X�N��O�����̏�� */
	TEXPTN	pndptn;		/* �ۗ���O�v�� */
} T_RTEX;

typedef struct t_rsem {
	ID		wtskid;		/* �Z�}�t�H�̑҂��s��̐擪�̃^�X�N��ID�ԍ� */
	uint_t	semcnt;		/* �Z�}�t�H�̌��݂̎����� */
} T_RSEM;

typedef struct t_rflg {
	ID		wtskid;		/* �C�x���g�t���O�̑҂��s��̐擪�̃^�X�N��ID�ԍ� */
	FLGPTN	flgptn;		/* �C�x���g�t���O�̌��݂̃r�b�g�p�^�[�� */
} T_RFLG;

typedef struct t_rdtq {
	ID		stskid;		/* �f�[�^�L���[�̑��M�҂��s��̐擪�̃^�X�N��ID�ԍ� */
	ID		rtskid;		/* �f�[�^�L���[�̎�M�҂��s��̐擪�̃^�X�N��ID�ԍ� */
	uint_t	sdtqcnt;	/* �f�[�^�L���[�Ǘ��̈�Ɋi�[����Ă���f�[�^�̐� */
} T_RDTQ;

typedef struct t_rpdq {
	ID		stskid;		/* �D��x�f�[�^�L���[�̑��M�҂��s��̐擪�̃^�X�N
						   ��ID�ԍ� */
	ID		rtskid;		/* �D��x�f�[�^�L���[�̎�M�҂��s��̐擪�̃^�X�N
						   ��ID�ԍ� */
	uint_t	spdqcnt;	/* �D��x�f�[�^�L���[�Ǘ��̈�Ɋi�[����Ă���f�[
						   �^�̐� */
} T_RPDQ;

typedef struct t_rmbx {
	ID		wtskid;		/* ���[���{�b�N�X�̑҂��s��̐擪�̃^�X�N��ID�ԍ� */
	T_MSG	*pk_msg;	/* ���b�Z�[�W�L���[�̐擪�ɂȂ��ꂽ���b�Z�[�W
						   �̐擪�Ԓn */
} T_RMBX;

typedef struct t_rmpf {
	ID		wtskid;		/* �Œ蒷�������v�[���̑҂��s��̐擪�̃^�X�N��
						   ID�ԍ� */
	uint_t	fblkcnt;	/* �Œ蒷�������v�[���̈�̋󂫃������̈�Ɋ���
						   �t���邱�Ƃ��ł���Œ蒷�������u���b�N�̐� */
} T_RMPF;

typedef struct t_rcyc {
	STAT	cycstat;	/* �����n���h���̓����� */
	RELTIM	lefttim;	/* ���Ɏ����n���h�����N�����鎞���܂ł̑��Ύ��� */
} T_RCYC;

typedef struct t_ralm {
	STAT	almstat;	/* �A���[���n���h���̓����� */
	RELTIM	lefttim;	/* �A���[���n���h�����N�����鎞���܂ł̑��Ύ��� */
} T_RALM;

/*
 *  �T�[�r�X�R�[���̐錾
 */

/*
 *  �^�X�N�Ǘ��@�\
 */
extern ER		act_tsk(ID tskid) throw();
extern ER		iact_tsk(ID tskid) throw();
extern ER_UINT	can_act(ID tskid) throw();
extern ER		ext_tsk(void) throw();
extern ER		ter_tsk(ID tskid) throw();
extern ER		chg_pri(ID tskid, PRI tskpri) throw();
extern ER		get_pri(ID tskid, PRI *p_tskpri) throw();
extern ER		get_inf(intptr_t *p_exinf) throw();
extern ER		ref_tsk(ID tskid, T_RTSK *pk_rtsk) throw();

/*
 *  �^�X�N�t�������@�\
 */
extern ER		slp_tsk(void) throw();
extern ER		tslp_tsk(TMO tmout) throw();
extern ER		wup_tsk(ID tskid) throw();
extern ER		iwup_tsk(ID tskid) throw();
extern ER_UINT	can_wup(ID tskid) throw();
extern ER		rel_wai(ID tskid) throw();
extern ER		irel_wai(ID tskid) throw();
extern ER		sus_tsk(ID tskid) throw();
extern ER		rsm_tsk(ID tskid) throw();
extern ER		dly_tsk(RELTIM dlytim) throw();

/*
 *  �^�X�N��O�����@�\
 */
extern ER		ras_tex(ID tskid, TEXPTN rasptn) throw();
extern ER		iras_tex(ID tskid, TEXPTN rasptn) throw();
extern ER		dis_tex(void) throw();
extern ER		ena_tex(void) throw();
extern bool_t	sns_tex(void) throw();
extern ER		ref_tex(ID tskid, T_RTEX *pk_rtex) throw();

/*
 *  �����E�ʐM�@�\
 */
extern ER		sig_sem(ID semid) throw();
extern ER		isig_sem(ID semid) throw();
extern ER		wai_sem(ID semid) throw();
extern ER		pol_sem(ID semid) throw();
extern ER		twai_sem(ID semid, TMO tmout) throw();
extern ER		ini_sem(ID semid) throw();
extern ER		ref_sem(ID semid, T_RSEM *pk_rsem) throw();

extern ER		set_flg(ID flgid, FLGPTN setptn) throw();
extern ER		iset_flg(ID flgid, FLGPTN setptn) throw();
extern ER		clr_flg(ID flgid, FLGPTN clrptn) throw();
extern ER		wai_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn) throw();
extern ER		pol_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn) throw();
extern ER		twai_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn, TMO tmout) throw();
extern ER		ini_flg(ID flgid) throw();
extern ER		ref_flg(ID flgid, T_RFLG *pk_rflg) throw();

extern ER		snd_dtq(ID dtqid, intptr_t data) throw();
extern ER		psnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		ipsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		tsnd_dtq(ID dtqid, intptr_t data, TMO tmout) throw();
extern ER		fsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		ifsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		rcv_dtq(ID dtqid, intptr_t *p_data) throw();
extern ER		prcv_dtq(ID dtqid, intptr_t *p_data) throw();
extern ER		trcv_dtq(ID dtqid, intptr_t *p_data, TMO tmout) throw();
extern ER		ini_dtq(ID dtqid) throw();
extern ER		ref_dtq(ID dtqid, T_RDTQ *pk_rdtq) throw();

extern ER		snd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		psnd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		ipsnd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		tsnd_pdq(ID pdqid, intptr_t data,
										PRI datapri, TMO tmout) throw();
extern ER		rcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) throw();
extern ER		prcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) throw();
extern ER		trcv_pdq(ID pdqid, intptr_t *p_data,
										PRI *p_datapri, TMO tmout) throw();
extern ER		ini_pdq(ID pdqid) throw();
extern ER		ref_pdq(ID pdqid, T_RPDQ *pk_rpdq) throw();

extern ER		snd_mbx(ID mbxid, T_MSG *pk_msg) throw();
extern ER		rcv_mbx(ID mbxid, T_MSG **ppk_msg) throw();
extern ER		prcv_mbx(ID mbxid, T_MSG **ppk_msg) throw();
extern ER		trcv_mbx(ID mbxid, T_MSG **ppk_msg, TMO tmout) throw();
extern ER		ini_mbx(ID mbxid) throw();
extern ER		ref_mbx(ID mbxid, T_RMBX *pk_rmbx) throw();

/*
 *  �������v�[���Ǘ��@�\
 */
extern ER		get_mpf(ID mpfid, void **p_blk) throw();
extern ER		pget_mpf(ID mpfid, void **p_blk) throw();
extern ER		tget_mpf(ID mpfid, void **p_blk, TMO tmout) throw();
extern ER		rel_mpf(ID mpfid, void *blk) throw();
extern ER		ini_mpf(ID mpfid) throw();
extern ER		ref_mpf(ID mpfid, T_RMPF *pk_rmpf) throw();

/*
 *  ���ԊǗ��@�\
 */
extern ER		get_tim(SYSTIM *p_systim) throw();
extern ER		get_utm(SYSUTM *p_sysutm) throw();

extern ER		sta_cyc(ID cycid) throw();
extern ER		stp_cyc(ID cycid) throw();
extern ER		ref_cyc(ID cycid, T_RCYC *pk_rcyc) throw();

extern ER		sta_alm(ID almid, RELTIM almtim) throw();
extern ER		ista_alm(ID almid, RELTIM almtim) throw();
extern ER		stp_alm(ID almid) throw();
extern ER		istp_alm(ID almid) throw();
extern ER		ref_alm(ID almid, T_RALM *pk_ralm) throw();

/*
 *  �V�X�e����ԊǗ��@�\
 */
extern ER		rot_rdq(PRI tskpri) throw();
extern ER		irot_rdq(PRI tskpri) throw();
extern ER		get_tid(ID *p_tskid) throw();
extern ER		iget_tid(ID *p_tskid) throw();
extern ER		loc_cpu(void) throw();
extern ER		iloc_cpu(void) throw();
extern ER		unl_cpu(void) throw();
extern ER		iunl_cpu(void) throw();
extern ER		dis_dsp(void) throw();
extern ER		ena_dsp(void) throw();
extern bool_t	sns_ctx(void) throw();
extern bool_t	sns_loc(void) throw();
extern bool_t	sns_dsp(void) throw();
extern bool_t	sns_dpn(void) throw();
extern bool_t	sns_ker(void) throw();
extern ER		ext_ker(void) throw();

/*
 *  �����݊Ǘ��@�\
 */
extern ER		dis_int(INTNO intno) throw();
extern ER		ena_int(INTNO intno) throw();
extern ER		chg_ipm(PRI intpri) throw();
extern ER		get_ipm(PRI *p_intpri) throw();

/*
 *  CPU��O�Ǘ��@�\
 */
extern bool_t	xsns_dpn(void *p_excinf) throw();
extern bool_t	xsns_xpn(void *p_excinf) throw();

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �I�u�W�F�N�g�����̒�`
 */
#define TA_ACT			UINT_C(0x02)	/* �^�X�N���N�����ꂽ��ԂŐ��� */

#define TA_TPRI			UINT_C(0x01)	/* �^�X�N�̑҂��s���D��x���� */
#define TA_MPRI			UINT_C(0x02)	/* ���b�Z�[�W�L���[��D��x���� */

#define TA_WMUL			UINT_C(0x02)	/* �����̑҂��^�X�N */
#define TA_CLR			UINT_C(0x04)	/* �C�x���g�t���O�̃N���A�w�� */

#define TA_STA			UINT_C(0x02)	/* �����n���h���𓮍��ԂŐ��� */

#define TA_NONKERNEL	UINT_C(0x02)	/* �J�[�l���Ǘ��O�̊����� */

#define TA_ENAINT		UINT_C(0x01)	/* �����ݗv���֎~�t���O���N���A */
#define TA_EDGE			UINT_C(0x02)	/* �G�b�W�g���K */

/*
 *  �T�[�r�X�R�[���̓��샂�[�h�̒�`
 */
#define TWF_ORW			UINT_C(0x01)	/* �C�x���g�t���O��OR�҂� */
#define TWF_ANDW		UINT_C(0x02)	/* �C�x���g�t���O��AND�҂� */

/*
 *  �I�u�W�F�N�g�̏�Ԃ̒�`
 */
#define TTS_RUN			UINT_C(0x01)	/* ���s��� */
#define TTS_RDY			UINT_C(0x02)	/* ���s�\��� */
#define TTS_WAI			UINT_C(0x04)	/* �҂���� */
#define TTS_SUS			UINT_C(0x08)	/* �����҂���� */
#define TTS_WAS			UINT_C(0x0c)	/* ��d�҂���� */
#define TTS_DMT			UINT_C(0x10)	/* �x�~��� */

#define TTW_SLP			UINT_C(0x0001)	/* �N���҂� */
#define TTW_DLY			UINT_C(0x0002)	/* ���Ԍo�ߑ҂� */
#define TTW_SEM			UINT_C(0x0004)	/* �Z�}�t�H�̎����l���҂� */
#define TTW_FLG			UINT_C(0x0008)	/* �C�x���g�t���O�҂� */
#define TTW_SDTQ		UINT_C(0x0010)	/* �f�[�^�L���[�ւ̑��M�҂� */
#define TTW_RDTQ		UINT_C(0x0020)	/* �f�[�^�L���[����̎�M�҂� */
#define TTW_SPDQ		UINT_C(0x0100)	/* �D��x�f�[�^�L���[�ւ̑��M�҂� */
#define TTW_RPDQ		UINT_C(0x0200)	/* �D��x�f�[�^�L���[����̎�M�҂� */
#define TTW_MBX			UINT_C(0x0040)	/* ���[���{�b�N�X����̎�M�҂� */
#define TTW_MPF			UINT_C(0x2000)	/* �Œ蒷�������u���b�N�̊l���҂� */

#define TTEX_ENA		UINT_C(0x01)	/* �^�X�N��O��������� */
#define TTEX_DIS		UINT_C(0x02)	/* �^�X�N��O�����֎~��� */

#define TCYC_STP		UINT_C(0x01)	/* �����n���h�������삵�Ă��Ȃ� */
#define TCYC_STA		UINT_C(0x02)	/* �����n���h�������삵�Ă��� */

#define TALM_STP		UINT_C(0x01)	/* �A���[���n���h�������삵�Ă��Ȃ� */
#define TALM_STA		UINT_C(0x02)	/* �A���[���n���h�������삵�Ă��� */

/*
 *  ���̑��̒萔�̒�`
 */
#define TSK_SELF		0			/* ���^�X�N�w�� */
#define TSK_NONE		0			/* �Y������^�X�N���Ȃ� */

#define TPRI_SELF		0			/* ���^�X�N�̃x�[�X�D��x */
#define TPRI_INI		0			/* �^�X�N�̋N�����D��x */

#define TIPM_ENAALL		0			/* �����ݗD��x�}�X�N�S���� */

/*
 *  �\���萔�ƃ}�N��
 */

/*
 *  �T�|�[�g����@�\
 */
#ifdef TOPPERS_TARGET_SUPPORT_DIS_INT
#define TOPPERS_SUPPORT_DIS_INT			/* dis_int���T�|�[�g����Ă��� */
#endif /* TOPPERS_TARGET_SUPPORT_DIS_INT */

#ifdef TOPPERS_TARGET_SUPPORT_ENA_INT
#define TOPPERS_SUPPORT_ENA_INT			/* ena_int���T�|�[�g����Ă��� */
#endif /* TOPPERS_TARGET_SUPPORT_ENA_INT */

#ifdef TOPPERS_TARGET_SUPPORT_GET_UTM
#define TOPPERS_SUPPORT_GET_UTM			/* get_utm���T�|�[�g����Ă��� */
#endif /* TOPPERS_TARGET_SUPPORT_GET_UTM */

/*
 *  �D��x�͈̔�
 */
#define TMIN_TPRI		1			/* �^�X�N�D��x�̍ŏ��l�i�ō��l�j*/
#define TMAX_TPRI		16			/* �^�X�N�D��x�̍ő�l�i�Œ�l�j*/
#define TMIN_DPRI		1			/* �f�[�^�D��x�̍ŏ��l�i�ō��l�j*/
#define TMAX_DPRI		16			/* �f�[�^�D��x�̍ő�l�i�Œ�l�j*/
#define TMIN_MPRI		1			/* ���b�Z�[�W�D��x�̍ŏ��l�i�ō��l�j*/
#define TMAX_MPRI		16			/* ���b�Z�[�W�D��x�̍ő�l�i�Œ�l�j*/
#define TMIN_ISRPRI		1			/* �����݃T�[�r�X���[�`���D��x�̍ŏ��l */
#define TMAX_ISRPRI		16			/* �����݃T�[�r�X���[�`���D��x�̍ő�l */

/*
 *  �o�[�W�������
 */
#define TKERNEL_MAKER	UINT_C(0x0118)	/* �J�[�l���̃��[�J�[�R�[�h */
#define TKERNEL_PRID	UINT_C(0x0007)	/* �J�[�l���̎��ʔԍ� */
#define TKERNEL_SPVER	UINT_C(0xf517)	/* �J�[�l���d�l�̃o�[�W�����ԍ� */
#define TKERNEL_PRVER	UINT_C(0x1092)	/* �J�[�l���̃o�[�W�����ԍ� */

/*
 *  �L���[�C���O�񐔂̍ő�l
 */
#define TMAX_ACTCNT		UINT_C(1)		/* �N���v���L���[�C���O���̍ő�l */
#define TMAX_WUPCNT		UINT_C(1)		/* �N���v���L���[�C���O���̍ő�l */

/*
 *  �r�b�g�p�^�[���̃r�b�g��
 */
#ifndef TBIT_TEXPTN					/* �^�X�N��O�v���̃r�b�g�� */
#define TBIT_TEXPTN		(sizeof(TEXPTN) * CHAR_BIT)
#endif /* TBIT_TEXPTN */

#ifndef TBIT_FLGPTN					/* �C�x���g�t���O�̃r�b�g�� */
#define TBIT_FLGPTN		(sizeof(FLGPTN) * CHAR_BIT)
#endif /* TBIT_FLGPTN */

/*
 *  �������̈�m�ۂ̂��߂̃}�N��
 *
 *  �ȉ���TOPPERS_COUNT_SZ��TOPPERS_ROUND_SZ�̒�`�́Cunit��2�̋Џ�ł�
 *  �邱�Ƃ����肵�Ă���D
 */
#ifndef TOPPERS_COUNT_SZ
#define TOPPERS_COUNT_SZ(sz, unit)	(((sz) + (unit) - 1) / (unit))
#endif /* TOPPERS_COUNT_SZ */
#ifndef TOPPERS_ROUND_SZ
#define TOPPERS_ROUND_SZ(sz, unit)	(((sz) + (unit) - 1) & ~((unit) - 1))
#endif /* TOPPERS_ROUND_SZ */

#define COUNT_STK_T(sz)		TOPPERS_COUNT_SZ(sz, sizeof(STK_T))
#define ROUND_STK_T(sz)		TOPPERS_ROUND_SZ(sz, sizeof(STK_T))

#define COUNT_MPF_T(blksz)	TOPPERS_COUNT_SZ(blksz, sizeof(MPF_T))
#define ROUND_MPF_T(blksz)	TOPPERS_ROUND_SZ(blksz, sizeof(MPF_T))

/*
 *  ���̑��̍\���萔
 */
#define TMAX_MAXSEM		UINT_MAX	/* �Z�}�t�H�̍ő厑�����̍ő�l */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_KERNEL_H */

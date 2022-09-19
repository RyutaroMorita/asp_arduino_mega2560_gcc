$ ======================================================================
$
$   TOPPERS/ASP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       Advanced Standard Profile Kernel
$
$   Copyright (C) 2007 by TAKAGI Nobuhisa
$   Copyright (C) 2007-2013 by Embedded and Real-Time Systems Laboratory
$               Graduate School of Information Science, Nagoya Univ., JAPAN
$
$   ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
$   �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
$   �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
$   (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
$       ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
$       �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
$   (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
$       �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
$       �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
$       �̖��ۏ؋K����f�ڂ��邱�ƁD
$   (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
$       �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
$       �ƁD
$     (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
$         �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
$     (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
$         �񍐂��邱�ƁD
$   (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
$       �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
$       �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
$       �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
$       �Ɛӂ��邱�ƁD
$
$   �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
$   ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
$   �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
$   �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
$   �̐ӔC�𕉂�Ȃ��D
$
$   $Id: kernel.tf 2728 2015-12-30 01:46:11Z ertl-honda $
$
$ =====================================================================

$ =====================================================================
$ kernel_cfg.h�̐���
$ =====================================================================

$FILE "kernel_cfg.h"$
/* kernel_cfg.h */$NL$
#ifndef TOPPERS_KERNEL_CFG_H$NL$
#define TOPPERS_KERNEL_CFG_H$NL$
$NL$
#define TNUM_TSKID	$LENGTH(TSK.ID_LIST)$$NL$
#define TNUM_SEMID	$LENGTH(SEM.ID_LIST)$$NL$
#define TNUM_FLGID	$LENGTH(FLG.ID_LIST)$$NL$
#define TNUM_DTQID	$LENGTH(DTQ.ID_LIST)$$NL$
#define TNUM_PDQID	$LENGTH(PDQ.ID_LIST)$$NL$
#define TNUM_MBXID	$LENGTH(MBX.ID_LIST)$$NL$
#define TNUM_MPFID	$LENGTH(MPF.ID_LIST)$$NL$
#define TNUM_CYCID	$LENGTH(CYC.ID_LIST)$$NL$
#define TNUM_ALMID	$LENGTH(ALM.ID_LIST)$$NL$
$NL$
$FOREACH id TSK.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id SEM.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id FLG.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id DTQ.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id PDQ.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id MBX.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id MPF.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id CYC.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id ALM.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$NL$
#endif /* TOPPERS_KERNEL_CFG_H */$NL$

$ =====================================================================
$ kernel_cfg.c�̐���
$ =====================================================================

$FILE "kernel_cfg.c"$
/* kernel_cfg.c */$NL$
#include "kernel/kernel_int.h"$NL$
#include "kernel_cfg.h"$NL$
$NL$
#if TKERNEL_PRID != 0x07u$NL$
#error The kernel does not match this configuration file.$NL$
#endif$NL$
$NL$

$
$  �C���N���[�h�f�B���N�e�B�u�i#include�j
$
/*$NL$
$SPC$*  Include Directives (#include)$NL$
$SPC$*/$NL$
$NL$
$INCLUDES$
$NL$

$
$  �I�u�W�F�N�g��ID�ԍ���ێ�����ϐ�
$
$IF USE_EXTERNAL_ID$
	/*$NL$
	$SPC$*  Variables for Object ID$NL$
	$SPC$*/$NL$
	$NL$
	$FOREACH id TSK.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id SEM.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id FLG.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id DTQ.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id PDQ.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id MBX.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id MPF.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id CYC.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id ALM.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
$END$

$
$  �X�^�b�N�̈�̊m�ۊ֐�
$
$IF !ISFUNCTION("ALLOC_STACK")$
$FUNCTION ALLOC_STACK$
$	// �傫�����Ɋۂ߂��T�C�Y�Ŋm�ۂ���
	static STK_T $ARGV[1]$[COUNT_STK_T($ARGV[2]$)];$NL$
	$RESULT = FORMAT("ROUND_STK_T(%1%)", ARGV[2])$
$END$
$END$

$
$  �g���[�X���O�}�N���̃f�t�H���g��`
$
/*$NL$
$SPC$*  Default Definitions of Trace Log Macros$NL$
$SPC$*/$NL$
$NL$
#ifndef LOG_ISR_ENTER$NL$
#define LOG_ISR_ENTER(intno)$NL$
#endif /* LOG_ISR_ENTER */$NL$
$NL$
#ifndef LOG_ISR_LEAVE$NL$
#define LOG_ISR_LEAVE(intno)$NL$
#endif /* LOG_ISR_LEAVE */$NL$
$NL$

$
$  �^�X�N
$
/*$NL$
$SPC$*  Task Management Functions$NL$
$SPC$*/$NL$
$NL$

$ �^�X�N��1�ȏ㑶�݂��邱�Ƃ̃`�F�b�N
$IF !LENGTH(TSK.ID_LIST)$
	$ERROR$$FORMAT(_("no task is registered"))$$END$
$END$

$ �^�X�NID�ԍ��̍ő�l
const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);$NL$
$NL$

$ �G���[�`�F�b�N
$FOREACH tskid TSK.ID_LIST$
$	// tskatr���i�mTA_ACT�n�j�łȂ��ꍇ�iE_RSATR�j
	$IF (TSK.TSKATR[tskid] & ~(TA_ACT|TARGET_TSKATR)) != 0$
		$ERROR TSK.TEXT_LINE[tskid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "tskatr", TSK.TSKATR[tskid], tskid, "CRE_TSK")$$END$
	$END$

$	// (TMIN_TPRI <= itskpri && itskpri <= TMAX_TPRI)�łȂ��ꍇ�iE_PAR�j
	$IF !(TMIN_TPRI <= TSK.ITSKPRI[tskid] && TSK.ITSKPRI[tskid] <= TMAX_TPRI)$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "itskpri", TSK.ITSKPRI[tskid], tskid, "CRE_TSK")$$END$
	$END$

$ 	// texatr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF LENGTH(TSK.TEXATR[tskid]) && TSK.TEXATR[tskid] != 0$
		$ERROR DEF_TEX.TEXT_LINE[tskid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "texatr", TSK.TEXATR[tskid], tskid, "DEF_TEX")$$END$
	$END$
$END$

$ �X�^�b�N�̈�̐����Ƃ���Ɋւ���G���[�`�F�b�N
$FOREACH tskid TSK.ID_LIST$
$	// stksz��0�ȉ����C�^�[�Q�b�g��`�̍ŏ��l�iTARGET_MIN_STKSZ�j����
$	// �������ꍇ�iE_PAR�j
	$IF TSK.STKSZ[tskid] <= 0 || (TARGET_MIN_STKSZ
									&& TSK.STKSZ[tskid] < TARGET_MIN_STKSZ)$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("%1% `%2%\' of `%3%\' in %4% is too small"), "stksz", TSK.STKSZ[tskid], tskid, "CRE_TSK")$$END$
	$END$

$ 	// stksz���X�^�b�N�̈�̃T�C�Y�Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !EQ(TSK.STK[tskid], "NULL") && CHECK_STKSZ_ALIGN
							&& (TSK.STKSZ[tskid] & (CHECK_STKSZ_ALIGN - 1))$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"), "stksz", TSK.STKSZ[tskid], tskid, "CRE_TSK")$$END$
	$END$

	$IF EQ(TSK.STK[tskid],"NULL")$
		$TSK.TINIB_STKSZ[tskid] = ALLOC_STACK(CONCAT("_kernel_stack_",
												tskid), TSK.STKSZ[tskid])$
		$TSK.TINIB_STK[tskid] = CONCAT("_kernel_stack_", tskid)$
	$ELSE$
		$TSK.TINIB_STKSZ[tskid] = FORMAT("(%1%)", TSK.STKSZ[tskid])$
		$TSK.TINIB_STK[tskid] = FORMAT("(void *)(%1%)", TSK.STK[tskid])$
	$END$
$END$
$NL$

$ �^�X�N�������u���b�N�̐����i�^�X�N��1�ȏ㑶�݂���j
const TINIB _kernel_tinib_table[TNUM_TSKID] = {$NL$
$JOINEACH tskid TSK.ID_LIST ",\n"$
$	// �^�X�N�����C�g�����C�N���Ԓn�C�N�����D��x
	$TAB${
	$SPC$($TSK.TSKATR[tskid]$), (intptr_t)($TSK.EXINF[tskid]$),
	$SPC$((TASK)($TSK.TASK[tskid]$)), INT_PRIORITY($TSK.ITSKPRI[tskid]$),

$	// �^�X�N�������R���e�L�X�g�u���b�N�C�X�^�b�N�̈�
	$IF USE_TSKINICTXB$
		$GENERATE_TSKINICTXB(tskid)$
	$ELSE$
		$SPC$$TSK.TINIB_STKSZ[tskid]$, $TSK.TINIB_STK[tskid]$,
	$END$

$	// �^�X�N��O�������[�`���̑����ƋN���Ԓn
	$SPC$($ALT(TSK.TEXATR[tskid],"TA_NULL")$), ($ALT(TSK.TEXRTN[tskid],"NULL")$) }
$END$$NL$
};$NL$
$NL$

$ �^�X�N�Ǘ��u���b�N�̐���
TCB _kernel_tcb_table[TNUM_TSKID];$NL$
$NL$

$ �^�X�N���������e�[�u���̐���
const ID _kernel_torder_table[TNUM_TSKID] = {$NL$
$TAB$$JOINEACH tskid TSK.ORDER_LIST ", "$$tskid$$END$$NL$
};$NL$
$NL$

$
$  �Z�}�t�H
$
/*$NL$
$SPC$*  Semaphore Functions$NL$
$SPC$*/$NL$
$NL$

$ �Z�}�t�HID�ԍ��̍ő�l
const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);$NL$
$NL$

$ �Z�}�t�H�������u���b�N�̐���
$IF LENGTH(SEM.ID_LIST)$
	const SEMINIB _kernel_seminib_table[TNUM_SEMID] = {$NL$
	$JOINEACH semid SEM.ID_LIST ",\n"$
$		// sematr���i�mTA_TPRI�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (SEM.SEMATR[semid] & ~TA_TPRI) != 0$
			$ERROR SEM.TEXT_LINE[semid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "sematr", SEM.SEMATR[semid], semid, "CRE_SEM")$$END$
		$END$

$		// (0 <= isemcnt && isemcnt <= maxsem)�łȂ��ꍇ�iE_PAR�j
		$IF !(0 <= SEM.ISEMCNT[semid] && SEM.ISEMCNT[semid] <= SEM.MAXSEM[semid])$
			$ERROR SEM.TEXT_LINE[semid]$E_PAR: $FORMAT(_("too large %1% `%2%\' of `%3%\' in %4%"), "isemcnt", SEM.ISEMCNT[semid], semid, "CRE_SEM")$$END$
		$END$

$		// (1 <= maxsem && maxsem <= TMAX_MAXSEM)�łȂ��ꍇ�iE_PAR�j
		$IF !(1 <= SEM.MAXSEM[semid] && SEM.MAXSEM[semid] <= TMAX_MAXSEM)$
			$ERROR SEM.TEXT_LINE[semid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxsem", SEM.MAXSEM[semid], semid, "CRE_SEM")$$END$
		$END$

$		// �Z�}�t�H�������u���b�N
		$TAB${ ($SEM.SEMATR[semid]$), ($SEM.ISEMCNT[semid]$), ($SEM.MAXSEM[semid]$) }
	$END$$NL$
	};$NL$
	$NL$

$	// �Z�}�t�H�Ǘ��u���b�N
	SEMCB _kernel_semcb_table[TNUM_SEMID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const SEMINIB, _kernel_seminib_table);$NL$
	TOPPERS_EMPTY_LABEL(SEMCB, _kernel_semcb_table);$NL$
$END$$NL$

$
$  �C�x���g�t���O
$
/*$NL$
$SPC$*  Eventflag Functions$NL$
$SPC$*/$NL$
$NL$

$ �C�x���g�t���OID�ԍ��̍ő�l
const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);$NL$
$NL$

$ �C�x���g�t���O�������u���b�N�̐���
$IF LENGTH(FLG.ID_LIST)$
	const FLGINIB _kernel_flginib_table[TNUM_FLGID] = {$NL$
	$JOINEACH flgid FLG.ID_LIST ",\n"$
$		// flgatr���i�mTA_TPRI�n�b�mTA_WMUL�n�b�mTA_CLR�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (FLG.FLGATR[flgid] & ~(TA_TPRI|TA_WMUL|TA_CLR)) != 0$
			$ERROR FLG.TEXT_LINE[flgid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "flgatr", FLG.FLGATR[flgid], flgid, "CRE_FLG")$$END$
		$END$

$		// iflgptn��FLGPTN�Ɋi�[�ł��Ȃ��ꍇ�iE_PAR�j
		$IF (FLG.IFLGPTN[flgid] & ~((1 << TBIT_FLGPTN) - 1)) != 0$
			$ERROR FLG.TEXT_LINE[flgid]$E_PAR: $FORMAT(_("too large %1% `%2%\' of `%3%\' in %4%"), "iflgptn", FLG.IFLGPTN[flgid], flgid, "CRE_FLG")$$END$
		$END$

$		// �C�x���g�t���O�������u���b�N
		$TAB${ ($FLG.FLGATR[flgid]$), ($FLG.IFLGPTN[flgid]$) }
	$END$$NL$
	};$NL$
	$NL$

$	// �C�x���g�t���O�Ǘ��u���b�N
	FLGCB _kernel_flgcb_table[TNUM_FLGID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const FLGINIB, _kernel_flginib_table);$NL$
	TOPPERS_EMPTY_LABEL(FLGCB, _kernel_flgcb_table);$NL$
$END$$NL$

$
$  �f�[�^�L���[
$
/*$NL$
$SPC$*  Dataqueue Functions$NL$
$SPC$*/$NL$
$NL$

$ �f�[�^�L���[ID�ԍ��̍ő�l
const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);$NL$
$NL$

$IF LENGTH(DTQ.ID_LIST)$
	$FOREACH dtqid DTQ.ID_LIST$
$		// dtqatr���i�mTA_TPRI�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (DTQ.DTQATR[dtqid] & ~TA_TPRI) != 0$
			$ERROR DTQ.TEXT_LINE[dtqid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "dtqatr", DTQ.DTQATR[dtqid], dtqid, "CRE_DTQ")$$END$
		$END$

$		// dtqcnt�����̏ꍇ�iE_PAR�j
		$IF DTQ.DTQCNT[dtqid] < 0$
			$ERROR DTQ.TEXT_LINE[dtqid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "dtqcnt", DTQ.DTQCNT[dtqid], dtqid, "CRE_DTQ")$$END$
		$END$

$		// dtqmb��NULL�łȂ��ꍇ�iE_NOSPT�j
		$IF !EQ(DTQ.DTQMB[dtqid], "NULL")$
			$ERROR DTQ.TEXT_LINE[dtqid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "dtqmb", DTQ.DTQMB[dtqid], dtqid, "CRE_DTQ")$$END$
		$END$

$		// �f�[�^�L���[�Ǘ��̈�
		$IF DTQ.DTQCNT[dtqid]$
			static DTQMB _kernel_dtqmb_$dtqid$[$DTQ.DTQCNT[dtqid]$];$NL$
		$END$
	$END$

$	// �f�[�^�L���[�������u���b�N�̐���
	const DTQINIB _kernel_dtqinib_table[TNUM_DTQID] = {$NL$
	$JOINEACH dtqid DTQ.ID_LIST ",\n"$
		$TAB${ ($DTQ.DTQATR[dtqid]$), ($DTQ.DTQCNT[dtqid]$), $IF DTQ.DTQCNT[dtqid]$(_kernel_dtqmb_$dtqid$)$ELSE$NULL$END$ }
	$END$$NL$
	};$NL$
	$NL$

$	// �f�[�^�L���[�Ǘ��u���b�N
	DTQCB _kernel_dtqcb_table[TNUM_DTQID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);$NL$
	TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);$NL$
$END$$NL$

$
$  �D��x�f�[�^�L���[
$
/*$NL$
$SPC$*  Priority Dataqueue Functions$NL$
$SPC$*/$NL$
$NL$

$ �D��x�f�[�^�L���[ID�ԍ��̍ő�l
const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);$NL$
$NL$

$IF LENGTH(PDQ.ID_LIST)$
	$FOREACH pdqid PDQ.ID_LIST$
$		// pdqatr���i�mTA_TPRI�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (PDQ.PDQATR[pdqid] & ~TA_TPRI) != 0$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "pdqatr", PDQ.PDQATR[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// pdqcnt�����̏ꍇ�iE_PAR�j
		$IF PDQ.PDQCNT[pdqid] < 0$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "pdqcnt", PDQ.PDQCNT[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// (TMIN_DPRI <= maxdpri && maxdpri <= TMAX_DPRI)�łȂ��ꍇ�iE_PAR�j
		$IF !(TMIN_DPRI <= PDQ.MAXDPRI[pdqid] && PDQ.MAXDPRI[pdqid] <= TMAX_DPRI)$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxdpri", PDQ.MAXDPRI[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// pdqmb��NULL�łȂ��ꍇ�iE_NOSPT�j
		$IF !EQ(PDQ.PDQMB[pdqid], "NULL")$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "pdqmb", PDQ.PDQMB[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// �D��x�f�[�^�L���[�Ǘ��̈�
		$IF PDQ.PDQCNT[pdqid]$
			static PDQMB _kernel_pdqmb_$pdqid$[$PDQ.PDQCNT[pdqid]$];$NL$
		$END$
	$END$

$	// �D��x�f�[�^�L���[�������u���b�N�̐���
	const PDQINIB _kernel_pdqinib_table[TNUM_PDQID] = {$NL$
	$JOINEACH pdqid PDQ.ID_LIST ",\n"$
		$TAB${ ($PDQ.PDQATR[pdqid]$), ($PDQ.PDQCNT[pdqid]$), ($PDQ.MAXDPRI[pdqid]$), $IF PDQ.PDQCNT[pdqid]$(_kernel_pdqmb_$pdqid$)$ELSE$NULL$END$ }
	$END$$NL$
	};$NL$
	$NL$

$	// �D��x�f�[�^�L���[�Ǘ��u���b�N
	PDQCB _kernel_pdqcb_table[TNUM_PDQID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);$NL$
	TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);$NL$
$END$$NL$

$
$  ���[���{�b�N�X
$
/*$NL$
$SPC$*  Mailbox Functions$NL$
$SPC$*/$NL$
$NL$

$ ���[���{�b�N�XID�ԍ��̍ő�l
const ID _kernel_tmax_mbxid = (TMIN_MBXID + TNUM_MBXID - 1);$NL$
$NL$

$ ���[���{�b�N�X�������u���b�N�̐���
$IF LENGTH(MBX.ID_LIST)$
	const MBXINIB _kernel_mbxinib_table[TNUM_MBXID] = {$NL$
	$JOINEACH mbxid MBX.ID_LIST ",\n"$
$		// mbxatr���i�mTA_TPRI�n�b�mTA_MPRI�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (MBX.MBXATR[mbxid] & ~(TA_TPRI|TA_MPRI)) != 0$
			$ERROR MBX.TEXT_LINE[mbxid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mbxatr", MBX.MBXATR[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// (TMIN_MPRI <= maxmpri && maxmpri <= TMAX_MPRI)�łȂ��ꍇ�iE_PAR�j
		$IF !(TMIN_MPRI <= MBX.MAXMPRI[mbxid] && MBX.MAXMPRI[mbxid] <= TMAX_MPRI)$
			$ERROR MBX.TEXT_LINE[mbxid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxmpri", MBX.MAXMPRI[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// mprihd��NULL�łȂ��ꍇ�iE_NOSPT�j
		$IF !EQ(MBX.MPRIHD[mbxid], "NULL")$
			$ERROR MBX.TEXT_LINE[mbxid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mprihd", MBX.MPRIHD[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// ���[���{�b�N�X�������u���b�N
		$TAB${ ($MBX.MBXATR[mbxid]$), ($MBX.MAXMPRI[mbxid]$) }
	$END$$NL$
	};$NL$
	$NL$

$	// ���[���{�b�N�X�Ǘ��u���b�N
	MBXCB _kernel_mbxcb_table[TNUM_MBXID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const MBXINIB, _kernel_mbxinib_table);$NL$
	TOPPERS_EMPTY_LABEL(MBXCB, _kernel_mbxcb_table);$NL$
$END$$NL$

$
$  �Œ蒷�������v�[��
$
/*$NL$
$SPC$*  Fixed-sized Memorypool Functions$NL$
$SPC$*/$NL$
$NL$

$ �Œ蒷�������v�[��ID�ԍ��̍ő�l
const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);$NL$
$NL$

$IF LENGTH(MPF.ID_LIST)$
	$FOREACH mpfid MPF.ID_LIST$
$		// mpfatr���i�mTA_TPRI�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (MPF.MPFATR[mpfid] & ~TA_TPRI) != 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mpfatr", MPF.MPFATR[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// blkcnt��0�ȉ��̏ꍇ�iE_PAR�j
		$IF MPF.BLKCNT[mpfid] <= 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "blkcnt", MPF.BLKCNT[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// blksz��0�ȉ��̏ꍇ�iE_PAR�j
		$IF MPF.BLKSZ[mpfid] <= 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "blksz", MPF.BLKSZ[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// �Œ蒷�������v�[���̈�
		$IF EQ(MPF.MPF[mpfid], "NULL")$
			#ifdef USE_SEPARATED_MEMORY_POOL$NL$
			static MPF_T _kernel_mpf_$mpfid$[($MPF.BLKCNT[mpfid]$) * COUNT_MPF_T($MPF.BLKSZ[mpfid]$)] __attribute__((section(".MemoryPool")));$NL$
			#else$NL$
			static MPF_T _kernel_mpf_$mpfid$[($MPF.BLKCNT[mpfid]$) * COUNT_MPF_T($MPF.BLKSZ[mpfid]$)];$NL$
			#endif$NL$
		$END$

$		// mpfmb��NULL�łȂ��ꍇ�iE_NOSPT�j
		$IF !EQ(MPF.MPFMB[mpfid], "NULL")$
			$ERROR MPF.TEXT_LINE[mpfid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mpfmb", MPF.MPFMB[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// �Œ蒷�������v�[���Ǘ��̈�
		static MPFMB _kernel_mpfmb_$mpfid$[$MPF.BLKCNT[mpfid]$];$NL$
	$END$

$	// �Œ蒷�������v�[���������u���b�N�̐���
	const MPFINIB _kernel_mpfinib_table[TNUM_MPFID] = {$NL$
	$JOINEACH mpfid MPF.ID_LIST ",\n"$
		$TAB${ ($MPF.MPFATR[mpfid]$), ($MPF.BLKCNT[mpfid]$), ROUND_MPF_T($MPF.BLKSZ[mpfid]$), $IF EQ(MPF.MPF[mpfid],"NULL")$(_kernel_mpf_$mpfid$)$ELSE$(void *)($MPF.MPF[mpfid]$)$END$, (_kernel_mpfmb_$mpfid$) }
	$END$$NL$
	};$NL$
	$NL$

$	// �Œ蒷�������v�[���Ǘ��u���b�N
	MPFCB _kernel_mpfcb_table[TNUM_MPFID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);$NL$
	TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);$NL$
$END$$NL$

$
$  �����n���h��
$
/*$NL$
$SPC$*  Cyclic Handler Functions$NL$
$SPC$*/$NL$
$NL$

$ �����n���h��ID�ԍ��̍ő�l
const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);$NL$
$NL$

$ �����n���h���������e�[�u���̐���
$IF LENGTH(CYC.ID_LIST)$
	const CYCINIB _kernel_cycinib_table[TNUM_CYCID] = {$NL$
	$JOINEACH cycid CYC.ID_LIST ",\n"$
$		// cycatr���i�mTA_STA�n�j�łȂ��ꍇ�iE_RSATR�j
		$IF (CYC.CYCATR[cycid] & ~TA_STA) != 0$
			$ERROR CYC.TEXT_LINE[cycid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cycatr", CYC.CYCATR[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// (0 < cyctim && cyctim <= TMAX_RELTIM)�łȂ��ꍇ�iE_PAR�j
		$IF !(0 < CYC.CYCTIM[cycid] && CYC.CYCTIM[cycid] <= TMAX_RELTIM)$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cyctim", CYC.CYCTIM[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// (0 <= cycphs && cycphs <= TMAX_RELTIM)�łȂ��ꍇ�iE_PAR�j
		$IF !(0 <= CYC.CYCPHS[cycid] && CYC.CYCPHS[cycid] <= TMAX_RELTIM)$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cycphs", CYC.CYCPHS[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// �x���Fcycatr��TA_STA���ݒ肳��Ă��āC(cycphs == 0)�̏ꍇ
		$IF (CYC.CYCATR[cycid] & TA_STA) != 0 && CYC.CYCPHS[cycid] == 0$
			$WARNING CYC.TEXT_LINE[cycid]$$FORMAT(_("%1% is not recommended when %2% is set to %3% in %4%"), "cycphs==0", "TA_STA", "cycatr", "CRE_CYC")$$END$
		$END$

$		// �����n���h���������u���b�N
		$TAB${ ($CYC.CYCATR[cycid]$), (intptr_t)($CYC.EXINF[cycid]$), ($CYC.CYCHDR[cycid]$), ($CYC.CYCTIM[cycid]$), ($CYC.CYCPHS[cycid]$) }
	$END$$NL$
	};$NL$
	$NL$

$	// �����n���h���Ǘ��u���b�N
	CYCCB _kernel_cyccb_table[TNUM_CYCID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const CYCINIB, _kernel_cycinib_table);$NL$
	TOPPERS_EMPTY_LABEL(CYCCB, _kernel_cyccb_table);$NL$
$END$$NL$

$
$  �A���[���n���h��
$
/*$NL$
$SPC$*  Alarm Handler Functions$NL$
$SPC$*/$NL$
$NL$

$ �A���[���n���h��ID�ԍ��̍ő�l
const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);$NL$
$NL$

$ �A���[���n���h���������u���b�N�̐���
$IF LENGTH(ALM.ID_LIST)$
	const ALMINIB _kernel_alminib_table[TNUM_ALMID] = {$NL$
	$JOINEACH almid ALM.ID_LIST ",\n"$
$		// almatr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
		$IF ALM.ALMATR[almid] != 0$
			$ERROR ALM.TEXT_LINE[almid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "almatr", ALM.ALMATR[almid], almid, "CRE_ALM")$$END$
		$END$

$		// �A���[���n���h���������u���b�N
		$TAB${ ($ALM.ALMATR[almid]$), (intptr_t)($ALM.EXINF[almid]$), ($ALM.ALMHDR[almid]$) }
	$END$$NL$
	};$NL$
	$NL$

$	// �A���[���n���h���Ǘ��u���b�N
	ALMCB _kernel_almcb_table[TNUM_ALMID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);$NL$
	TOPPERS_EMPTY_LABEL(ALMCB, _kernel_almcb_table);$NL$
$END$$NL$

$
$  �����݊Ǘ��@�\
$
/*$NL$
$SPC$*  Interrupt Management Functions$NL$
$SPC$*/$NL$
$NL$

$ �����ݔԍ��Ɗ����݃n���h���ԍ��̕ϊ��e�[�u���̍쐬
$IF LENGTH(INTNO_ATTISR_VALID) != LENGTH(INHNO_ATTISR_VALID)$
	$ERROR$length of `INTNO_ATTISR_VALID' is different from length of `INHNO_ATTISR_VALID'$END$
$END$
$i = 0$
$FOREACH intno INTNO_ATTISR_VALID$
	$inhno = AT(INHNO_ATTISR_VALID, i)$
	$INHNO[intno] = inhno$
	$INTNO[inhno] = intno$
	$i = i + 1$
$END$

$ �����ݗv�����C���Ɋւ���G���[�`�F�b�N
$i = 0$
$FOREACH intno INT.ORDER_LIST$
$	// intno��CFG_INT�ɑ΂��銄���ݔԍ��Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !LENGTH(FIND(INTNO_CFGINT_VALID, INT.INTNO[intno]))$
		$ERROR INT.TEXT_LINE[intno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intno", INT.INTNO[intno], "CFG_INT")$$END$
	$END$

$	// intno��CFG_INT�ɂ���Đݒ�ς݂̏ꍇ�iE_OBJ�j
	$j = 0$
	$FOREACH intno2 INT.ORDER_LIST$
		$IF INT.INTNO[intno] == INT.INTNO[intno2] && j < i$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "intno", INT.INTNO[intno], "CFG_INT")$$END$
		$END$
		$j = j + 1$
	$END$

$	// intatr���i�mTA_ENAINT�n�b�mTA_EDGE�n�j�łȂ��ꍇ�iE_RSATR�j
	$IF (INT.INTATR[intno] & ~(TA_ENAINT|TA_EDGE|TARGET_INTATR)) != 0$
		$ERROR INT.TEXT_LINE[intno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "intatr", INT.INTATR[intno], "intno", INT.INTNO[intno], "CFG_INT")$$END$
	$END$

$	// intpri��CFG_INT�ɑ΂��銄���ݗD��x�Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !LENGTH(FIND(INTPRI_CFGINT_VALID, INT.INTPRI[intno]))$
		$ERROR INT.TEXT_LINE[intno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intpri", INT.INTPRI[intno], "CFG_INT")$$END$
	$END$

$	// �J�[�l���Ǘ��ɌŒ肳��Ă���intno�ɑ΂��āCintpri��TMIN_INTPRI
$	// �����������l���w�肳�ꂽ�ꍇ�iE_OBJ�j
	$IF LENGTH(FIND(INTNO_FIX_KERNEL, intno))$
		$IF INT.INTPRI[intno] < TMIN_INTPRI$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' must not have higher priority than %3%"), "intno", INT.INTNO[intno], "TMIN_INTPRI")$$END$
		$END$
	$END$

$	// �J�[�l���Ǘ��O�ɌŒ肳��Ă���intno�ɑ΂��āCintpri��TMIN_INTPRI
$	// �����������l���w�肳��Ȃ������ꍇ�iE_OBJ�j
	$IF LENGTH(FIND(INTNO_FIX_NONKERNEL, intno))$
		$IF INT.INTPRI[intno] >= TMIN_INTPRI$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' must have higher priority than %3%"), "intno", INT.INTNO[intno], "TMIN_INTPRI")$$END$
		$END$
	$END$
	$i = i + 1$
$END$

$ �����݃n���h���Ɋւ���G���[�`�F�b�N
$i = 0$
$FOREACH inhno INH.ORDER_LIST$
$	// inhno��DEF_INH�ɑ΂��銄���݃n���h���ԍ��Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !LENGTH(FIND(INHNO_DEFINH_VALID, INH.INHNO[inhno]))$
		$ERROR INH.TEXT_LINE[inhno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
	$END$

$	// inhno��DEF_INH�ɂ���Đݒ�ς݂̏ꍇ�iE_OBJ�j
	$j = 0$
	$FOREACH inhno2 INH.ORDER_LIST$
		$IF INH.INHNO[inhno] == INH.INHNO[inhno2] && j < i$
			$ERROR INH.TEXT_LINE[inhno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
		$END$
		$j = j + 1$
	$END$

$	// inhatr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF (INH.INHATR[inhno] & ~TARGET_INHATR) != 0$
		$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "inhatr", INH.INHATR[inhno], "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
	$END$

$	// �J�[�l���Ǘ��ɌŒ肳��Ă���inhno�ɑ΂��āCinhatr��TA_NONKERNEL
$	//�@���w�肳��Ă���ꍇ�iE_RSATR�j
	$IF LENGTH(FIND(INHNO_FIX_KERNEL, inhno))$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) != 0$
			$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("%1% `%2%\' must not be non-kernel interrupt"), "inhno", INH.INHNO[inhno])$$END$
		$END$
	$END$

$	// �J�[�l���Ǘ��O�ɌŒ肳��Ă���inhno�ɑ΂��āCinhatr��TA_NONKERNEL
$	// ���w�肳��Ă��Ȃ��ꍇ�iE_RSATR�j
	$IF LENGTH(FIND(INHNO_FIX_NONKERNEL, inhno))$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
			$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("%1% `%2%\' must be non-kernel interrupt"), "inhno", INH.INHNO[inhno])$$END$
		$END$
	$END$

	$IF LENGTH(INTNO[INH.INHNO[inhno]])$
		$intno = INTNO[INH.INHNO[inhno]]$
$		// inhno�ɑΉ�����intno�ɑ΂���CFG_INT���Ȃ��ꍇ�iE_OBJ�j
		$IF !LENGTH(INT.INTNO[intno])$
			$ERROR INH.TEXT_LINE[inhno]$E_OBJ: $FORMAT(_("%1% `%2%\' corresponding to %3% `%4%\' is not configured with %5%"), "intno", INT.INTNO[intno], "inhno", INH.INHNO[inhno], "CFG_INT")$$END$
		$ELSE$
			$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
$				// inhatr��TA_NONKERNEL���w�肳��Ă��炸�Cinhno�ɑΉ�
$				// ����intno�ɑ΂���CFG_INT�Őݒ肳�ꂽ�����ݗD��x��
$				// TMIN_INTPRI�����������ꍇ�iE_OBJ�j
				$IF INT.INTPRI[intno] < TMIN_INTPRI$
					$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is higher than %5%"), "intpri", INT.INTPRI[intno], "inhno", INH.INHNO[inhno], "TMIN_INTPRI")$$END$
				$END$
			$ELSE$
$				// inhatr��TA_NONKERNEL���w�肳��Ă���Cinhno�ɑΉ�
$				// ����intno�ɑ΂���CFG_INT�Őݒ肳�ꂽ�����ݗD��x��
$				// TMIN_INTPRI�ȏ�ł���ꍇ�iE_OBJ�j
				$IF INT.INTPRI[intno] >= TMIN_INTPRI$
					$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is lower than or equal to %5%"), "intpri", INT.INTPRI[intno], "inhno", INH.INHNO[inhno], "TMIN_INTPRI")$$END$
				$END$
			$END$
		$END$
	$END$
	$i = i + 1$
$END$

$ �����݃T�[�r�X���[�`���iISR�j�Ɋւ���G���[�`�F�b�N�Ɗ����݃n���h���̐���
$FOREACH order ISR.ORDER_LIST$
$	// isratr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF (ISR.ISRATR[order] & ~TARGET_ISRATR) != 0$
		$ERROR ISR.TEXT_LINE[order]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "isratr", ISR.ISRATR[order], "ATT_ISR")$$END$
	$END$

$	// intno��ATT_ISR�ɑ΂��銄���ݔԍ��Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !LENGTH(FIND(INTNO_ATTISR_VALID, ISR.INTNO[order]))$
		$ERROR ISR.TEXT_LINE[order]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intno", ISR.INTNO[order], "ATT_ISR")$$END$
	$END$

$	// (TMIN_ISRPRI <= isrpri && isrpri <= TMAX_ISRPRI)�łȂ��ꍇ�iE_PAR�j
	$IF !(TMIN_ISRPRI <= ISR.ISRPRI[order] && ISR.ISRPRI[order] <= TMAX_ISRPRI)$
		$ERROR ISR.TEXT_LINE[order]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "isrpri", ISR.ISRPRI[order], "ATT_ISR")$$END$
	$END$
$END$

$FOREACH intno INTNO_ATTISR_VALID$
	$inhno = INHNO[intno]$

$	// �����ݔԍ�intno�ɑ΂��ēo�^���ꂽISR�̃��X�g�̍쐬
	$isr_order_list = {}$
	$FOREACH order ISR.ORDER_LIST$
		$IF ISR.INTNO[order] == intno$
			$isr_order_list = APPEND(isr_order_list, order)$
			$order_for_error = order$
		$END$
	$END$

$	// �����ݔԍ�intno�ɑ΂��ēo�^���ꂽISR�����݂���ꍇ
	$IF LENGTH(isr_order_list) > 0$
$		// intno�ɑΉ�����inhno�ɑ΂���DEF_INH������ꍇ�iE_OBJ�j
		$IF LENGTH(INH.INHNO[inhno])$
			$ERROR ISR.TEXT_LINE[order_for_error]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated with %4% `%5%\'"), "intno", ISR.INTNO[order_for_error], "ATT_ISR", "inhno", INH.INHNO[inhno])$$END$
		$END$

$		// intno�ɑ΂���CFG_INT���Ȃ��ꍇ�iE_OBJ�j
		$IF !LENGTH(INT.INTNO[intno])$
			$ERROR ISR.TEXT_LINE[order_for_error]$E_OBJ: $FORMAT(_("%1% `%2%\' is not configured with %3%"), "intno", ISR.INTNO[order_for_error], "CFG_INT")$$END$
		$ELSE$
$			// intno�ɑ΂���CFG_INT�Őݒ肳�ꂽ�����ݗD��x��TMIN_INTPRI
$			// �����������ꍇ�iE_OBJ�j
			$IF INT.INTPRI[intno] < TMIN_INTPRI$
				$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is higher than %5%"), "intpri", INT.INTPRI[intno], "intno", ISR.INTNO[order_for_error], "TMIN_INTPRI")$$END$
			$END$
		$END$

$		// DEF_INH(inhno, { TA_NULL, _kernel_inthdr_<intno> } );
		$INH.INHNO[inhno] = inhno$
		$INH.INHATR[inhno] = VALUE("TA_NULL", 0)$
		$INH.INTHDR[inhno] = CONCAT("_kernel_inthdr_", intno)$
		$INH.ORDER_LIST = APPEND(INH.ORDER_LIST, inhno)$

$		// ISR�p�̊����݃n���h��
		void$NL$
		_kernel_inthdr_$intno$(void)$NL$
		{$NL$
		$IF LENGTH(isr_order_list) > 1$
			$TAB$PRI	saved_ipm;$NL$
			$NL$
			$TAB$i_begin_int($intno$);$NL$
			$TAB$saved_ipm = i_get_ipm();$NL$
		$ELSE$
			$TAB$i_begin_int($intno$);$NL$
		$END$
$		// ISR��D��x���ɌĂяo��
		$JOINEACH order SORT(isr_order_list, "ISR.ISRPRI") "\tif (i_sense_lock()) {\n\t\ti_unlock_cpu();\n\t}\n\ti_set_ipm(saved_ipm);\n"$
			$TAB$LOG_ISR_ENTER($intno$);$NL$
			$TAB$((ISR)($ISR.ISR[order]$))((intptr_t)($ISR.EXINF[order]$));$NL$
			$TAB$LOG_ISR_LEAVE($intno$);$NL$
		$END$
		$TAB$i_end_int($intno$);$NL$
		}$NL$
	$END$
$END$
$NL$

$
$  �����݊Ǘ��@�\�̂��߂̕W���I�ȏ��������̐���
$
$ �����݃n���h���̏������ɕK�v�ȏ��
$IF !OMIT_INITIALIZE_INTERRUPT || ALT(USE_INHINIB_TABLE,0)$

$ �����݃n���h����
#define TNUM_INHNO	$LENGTH(INH.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_inhno = TNUM_INHNO;$NL$
$NL$
$FOREACH inhno INH.ORDER_LIST$
	$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
		INTHDR_ENTRY($INH.INHNO[inhno]$, $+INH.INHNO[inhno]$, $INH.INTHDR[inhno]$)$NL$
	$END$
$END$
$NL$

$ �����݃n���h���������e�[�u��
$IF LENGTH(INH.ORDER_LIST)$
	const INHINIB _kernel_inhinib_table[TNUM_INHNO] = {$NL$
	$JOINEACH inhno INH.ORDER_LIST ",\n"$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
			$TAB${ ($INH.INHNO[inhno]$), ($INH.INHATR[inhno]$), (FP)(INT_ENTRY($INH.INHNO[inhno]$, $INH.INTHDR[inhno]$)) }
		$ELSE$
			$TAB${ ($INH.INHNO[inhno]$), ($INH.INHATR[inhno]$), (FP)($INH.INTHDR[inhno]$) }
		$END$
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const INHINIB, _kernel_inhinib_table);$NL$
$END$$NL$
$END$

$ �����ݗv�����C���̏������ɕK�v�ȏ��
$IF !OMIT_INITIALIZE_INTERRUPT || ALT(USE_INTINIB_TABLE,0)$

$ �����ݗv�����C����
#define TNUM_INTNO	$LENGTH(INT.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_intno = TNUM_INTNO;$NL$
$NL$

$ �����ݗv�����C���������e�[�u��
$IF LENGTH(INT.ORDER_LIST)$
	const INTINIB _kernel_intinib_table[TNUM_INTNO] = {$NL$
	$JOINEACH intno INT.ORDER_LIST ",\n"$
		$TAB${ ($INT.INTNO[intno]$), ($INT.INTATR[intno]$), ($INT.INTPRI[intno]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const INTINIB, _kernel_intinib_table);$NL$
$END$$NL$
$END$

$
$  CPU��O�Ǘ��@�\
$
/*$NL$
$SPC$*  CPU Exception Management Functions$NL$
$SPC$*/$NL$
$NL$

$ CPU��O�n���h���Ɋւ���G���[�`�F�b�N
$i = 0$
$FOREACH excno EXC.ORDER_LIST$
$	// excno��DEF_EXC�ɑ΂���CPU��O�n���h���ԍ��Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !LENGTH(FIND(EXCNO_DEFEXC_VALID, EXC.EXCNO[excno]))$
		$ERROR EXC.TEXT_LINE[excno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
	$END$

$	// excno��DEF_EXC�ɂ���Đݒ�ς݂̏ꍇ�iE_OBJ�j
	$j = 0$
	$FOREACH excno2 EXC.ORDER_LIST$
		$IF EXC.EXCNO[excno] == EXC.EXCNO[excno2] && j < i$
			$ERROR EXC.TEXT_LINE[excno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
		$END$
		$j = j + 1$
	$END$

$	// excatr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF (EXC.EXCATR[excno] & ~TARGET_EXCATR) != 0$
		$ERROR EXC.TEXT_LINE[excno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "excatr", EXC.EXCATR[excno], "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
	$END$
	$i = i + 1$
$END$

$ CPU��O�n���h���̂��߂̕W���I�ȏ��������̐���
$IF !OMIT_INITIALIZE_EXCEPTION$

$ CPU��O�n���h����
#define TNUM_EXCNO	$LENGTH(EXC.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_excno = TNUM_EXCNO;$NL$
$NL$
$FOREACH excno EXC.ORDER_LIST$
	EXCHDR_ENTRY($EXC.EXCNO[excno]$, $+EXC.EXCNO[excno]$, $EXC.EXCHDR[excno]$)$NL$
$END$
$NL$

$ CPU��O�n���h���������e�[�u��
$IF LENGTH(EXC.ORDER_LIST)$
	const EXCINIB _kernel_excinib_table[TNUM_EXCNO] = {$NL$
	$JOINEACH excno EXC.ORDER_LIST ",\n"$
		$TAB${ ($EXC.EXCNO[excno]$), ($EXC.EXCATR[excno]$), (FP)(EXC_ENTRY($EXC.EXCNO[excno]$, $EXC.EXCHDR[excno]$)) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);$NL$
$END$$NL$
$END$

$
$  ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�
$
/*$NL$
$SPC$*  Stack Area for Non-task Context$NL$
$SPC$*/$NL$
$NL$

$IF !LENGTH(ICS.ORDER_LIST)$
$	// DEF_ICS���Ȃ��ꍇ�̃f�t�H���g�l�̐ݒ�
	#ifdef DEFAULT_ISTK$NL$
	$NL$
	#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ$NL$
	#define TOPPERS_ISTK		DEFAULT_ISTK$NL$
	$NL$
	#else /* DEAULT_ISTK */$NL$
	$NL$
	$istksz = ALLOC_STACK("_kernel_istack", "DEFAULT_ISTKSZ")$$NL$
	#define TOPPERS_ISTKSZ		$istksz$$NL$
	#define TOPPERS_ISTK		_kernel_istack$NL$
	$NL$
	#endif /* DEAULT_ISTK */$NL$
$ELSE$

$	// �ÓIAPI�uDEF_ICS�v����������iE_OBJ�j
	$IF LENGTH(ICS.ORDER_LIST) > 1$
		$ERROR$E_OBJ: $FORMAT(_("too many %1%"), "DEF_ICS")$$END$
	$END$

$	// istksz��0�ȉ����C�^�[�Q�b�g��`�̍ŏ��l�iTARGET_MIN_ISTKSZ�j����
$	// �������ꍇ�iE_PAR�j
	$IF ICS.ISTKSZ[1] <= 0 || (TARGET_MIN_ISTKSZ
									&& ICS.ISTKSZ[1] < TARGET_MIN_ISTKSZ)$
		$ERROR ICS.TEXT_LINE[1]$E_PAR: $FORMAT(_("%1% `%2%\' in %3% is too small"), "istksz", ICS.ISTKSZ[1], "DEF_ICS")$$END$
	$END$

$ 	// istksz���X�^�b�N�̈�̃T�C�Y�Ƃ��Đ������Ȃ��ꍇ�iE_PAR�j
	$IF !EQ(ICS.ISTK[1], "NULL") && CHECK_STKSZ_ALIGN
							&& (ICS.ISTKSZ[1] & (CHECK_STKSZ_ALIGN - 1))$
		$ERROR ICS.TEXT_LINE[1]$E_PAR: $FORMAT(_("%1% `%2%\' in %3% is not aligned"), "istksz", ICS.ISTKSZ[1], "DEF_ICS")$$END$
	$END$

	$IF EQ(ICS.ISTK[1], "NULL")$
$		// �X�^�b�N�̈�̎������t��
		$istksz = ALLOC_STACK("_kernel_istack", ICS.ISTKSZ[1])$$NL$
		#define TOPPERS_ISTKSZ		$istksz$$NL$
		#define TOPPERS_ISTK		_kernel_istack$NL$
	$ELSE$
		#define TOPPERS_ISTKSZ		($ICS.ISTKSZ[1]$)$NL$
		#define TOPPERS_ISTK		(void *)($ICS.ISTK[1]$)$NL$
	$END$
$END$
$NL$

$ ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�
const SIZE		_kernel_istksz = TOPPERS_ISTKSZ;$NL$
STK_T *const	_kernel_istk = TOPPERS_ISTK;$NL$
$NL$
#ifdef TOPPERS_ISTKPT$NL$
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ);$NL$
#endif /* TOPPERS_ISTKPT */$NL$
$NL$

$
$  �^�C���C�x���g�Ǘ�
$
/*$NL$
$SPC$*  Time Event Management$NL$
$SPC$*/$NL$
$NL$
TMEVTN   _kernel_tmevt_heap[TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];$NL$
$NL$

$
$  �e���W���[���̏������֐�
$
/*$NL$
$SPC$*  Module Initialization Function$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_initialize_object(void)$NL$
{$NL$
$TAB$_kernel_initialize_task();$NL$
$IF LENGTH(SEM.ID_LIST)$$TAB$_kernel_initialize_semaphore();$NL$$END$
$IF LENGTH(FLG.ID_LIST)$$TAB$_kernel_initialize_eventflag();$NL$$END$
$IF LENGTH(DTQ.ID_LIST)$$TAB$_kernel_initialize_dataqueue();$NL$$END$
$IF LENGTH(PDQ.ID_LIST)$$TAB$_kernel_initialize_pridataq();$NL$$END$
$IF LENGTH(MBX.ID_LIST)$$TAB$_kernel_initialize_mailbox();$NL$$END$
$IF LENGTH(MPF.ID_LIST)$$TAB$_kernel_initialize_mempfix();$NL$$END$
$IF LENGTH(CYC.ID_LIST)$$TAB$_kernel_initialize_cyclic();$NL$$END$
$IF LENGTH(ALM.ID_LIST)$$TAB$_kernel_initialize_alarm();$NL$$END$
$TAB$_kernel_initialize_interrupt();$NL$
$TAB$_kernel_initialize_exception();$NL$
}$NL$
$NL$

$
$  ���������[�`���̎��s�֐�
$
/*$NL$
$SPC$*  Initialization Routine$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_call_inirtn(void)$NL$
{$NL$
$FOREACH order INI.ORDER_LIST$
$ 	// iniatr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF INI.INIATR[order] != 0$
		$ERROR INI.TEXT_LINE[order]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "iniatr", INI.INIATR[order], "inirtn", INI.INIRTN[order], "ATT_INI")$$END$
	$END$
	$TAB$((INIRTN)($INI.INIRTN[order]$))((intptr_t)($INI.EXINF[order]$));$NL$
$END$
}$NL$
$NL$

$
$  �I���������[�`���̎��s�֐�
$
/*$NL$
$SPC$*  Termination Routine$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_call_terrtn(void)$NL$
{$NL$
$FOREACH rorder TER.RORDER_LIST$
$ 	// teratr���iTA_NULL�j�łȂ��ꍇ�iE_RSATR�j
	$IF TER.TERATR[rorder] != 0$
		$ERROR TER.TEXT_LINE[rorder]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "teratr", TER.TERATR[rorder], "terrtn", TER.TERRTN[rorder], "ATT_TER")$$END$
	$END$
	$TAB$((TERRTN)($TER.TERRTN[rorder]$))((intptr_t)($TER.EXINF[rorder]$));$NL$
$END$
}$NL$
$NL$

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
 *  $Id: task.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�X�N�Ǘ����W���[��
 */

#include "kernel_impl.h"
#include "wait.h"
#include "task.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_TEX_ENTER
#define LOG_TEX_ENTER(p_tcb, texptn)
#endif /* LOG_TEX_ENTER */

#ifndef LOG_TEX_LEAVE
#define LOG_TEX_LEAVE(p_tcb)
#endif /* LOG_TEX_LEAVE */

#ifdef TOPPERS_tskini

/*
 *  ���s��Ԃ̃^�X�N
 */
TCB		*p_runtsk;

/*
 *  �ō��D�揇�ʂ̃^�X�N
 */
TCB		*p_schedtsk;

/*
 *  �^�X�N�f�B�X�p�b�`�^�^�X�N��O�������[�`���N���v���t���O
 */
bool_t	reqflg;

/*
 *  �����ݗD��x�}�X�N�S�������
 */
bool_t	ipmflg;

/*
 *  �f�B�X�p�b�`�֎~���
 */
bool_t	disdsp;

/*
 *  �^�X�N�f�B�X�p�b�`�\���
 */
bool_t	dspflg;

/*
 *  ���f�B�L���[
 */
QUEUE	ready_queue[TNUM_TPRI];

/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v
 */
uint16_t	ready_primap;

/*
 *  �^�X�N�Ǘ����W���[���̏�����
 */
void
initialize_task(void)
{
	uint_t	i, j;
	TCB		*p_tcb;

	p_runtsk = NULL;
	p_schedtsk = NULL;
	reqflg = false;
	ipmflg = true;
	disdsp = false;
	dspflg = true;

	for (i = 0; i < TNUM_TPRI; i++) {
		queue_initialize(&(ready_queue[i]));
	}
	ready_primap = 0U;

	for (i = 0; i < tnum_tsk; i++) {
		j = INDEX_TSK(torder_table[i]);
		p_tcb = &(tcb_table[j]);
		p_tcb->p_tinib = &(tinib_table[j]);
		p_tcb->actque = false;
		make_dormant(p_tcb);
		if ((p_tcb->p_tinib->tskatr & TA_ACT) != 0U) {
			(void) make_active(p_tcb);
		}
	}
}

#endif /* TOPPERS_tskini */

/*
 *  �r�b�g�}�b�v�T�[�`�֐�
 *
 *  bitmap����1�̃r�b�g�̓��C�ł����ʁi�E�j�̂��̂��T�[�`���C���̃r�b
 *  �g�ԍ���Ԃ��D�r�b�g�ԍ��́C�ŉ��ʃr�b�g��0�Ƃ���Dbitmap��0���w��
 *  ���Ă͂Ȃ�Ȃ��D���̊֐��ł́Cbitmap��16�r�b�g�ł��邱�Ƃ����肵�C
 *  uint16_t�^�Ƃ��Ă���D
 *
 *  �r�b�g�T�[�`���߂����v���Z�b�T�ł́C�r�b�g�T�[�`���߂��g���悤��
 *  ���������������������ǂ��ꍇ������D���̂悤�ȏꍇ�ɂ́C�^�[�Q�b�g
 *  �ˑ����Ńr�b�g�T�[�`���߂��g����bitmap_search���`���C
 *  OMIT_BITMAP_SEARCH���}�N����`����΂悢�D�܂��C�r�b�g�T�[�`���߂�
 *  �T�[�`�������t�Ȃǂ̗��R�ŗD��x�ƃr�b�g�Ƃ̑Ή���ύX�������ꍇ��
 *  �́CPRIMAP_BIT���}�N����`����΂悢�D
 *
 *  �܂��C���C�u������ffs������Ȃ�C���̂悤�ɒ�`���ă��C�u�����֐���
 *  �g���������������ǂ��\��������D
 *		#define	bitmap_search(bitmap) (ffs(bitmap) - 1)
 */
#ifndef PRIMAP_BIT
#define	PRIMAP_BIT(pri)		(1U << (pri))
#endif /* PRIMAP_BIT */

#ifndef OMIT_BITMAP_SEARCH

static const unsigned char bitmap_search_table[] = { 0, 1, 0, 2, 0, 1, 0,
												3, 0, 1, 0, 2, 0, 1, 0 };

Inline uint_t
bitmap_search(uint16_t bitmap)
{
	uint_t	n = 0U;

	assert(bitmap != 0U);
	if ((bitmap & 0x00ffU) == 0U) {
		bitmap >>= 8;
		n += 8;
	}
	if ((bitmap & 0x0fU) == 0U) {
		bitmap >>= 4;
		n += 4;
	}
	return(n + bitmap_search_table[(bitmap & 0x0fU) - 1]);
}

#endif /* OMIT_BITMAP_SEARCH */

/*
 *  �D��x�r�b�g�}�b�v���󂩂̃`�F�b�N
 */
Inline bool_t
primap_empty(void)
{
	return(ready_primap == 0U);
}

/*
 *  �D��x�r�b�g�}�b�v�̃T�[�`
 */
Inline uint_t
primap_search(void)
{
	return(bitmap_search(ready_primap));
}

/*
 *  �D��x�r�b�g�}�b�v�̃Z�b�g
 */
Inline void
primap_set(uint_t pri)
{
	ready_primap |= PRIMAP_BIT(pri);
}

/*
 *  �D��x�r�b�g�}�b�v�̃N���A
 */
Inline void
primap_clear(uint_t pri)
{
	ready_primap &= ~PRIMAP_BIT(pri);
}

/*
 *  �ō��D�揇�ʃ^�X�N�̃T�[�`
 */
#ifdef TOPPERS_tsksched

TCB *
search_schedtsk(void)
{
	uint_t	schedpri;

	schedpri = primap_search();
	return((TCB *)(ready_queue[schedpri].p_next));
}

#endif /* TOPPERS_tsksched */

/*
 *  ���s�ł����Ԃւ̑J��
 *
 *  �ō��D�揇�ʂ̃^�X�N���X�V����̂́C���s�ł���^�X�N���Ȃ������ꍇ
 *  �ƁCp_tcb�̗D��x���ō��D�揇�ʂ̃^�X�N�̗D��x���������ꍇ�ł�
 *  ��D
 */
#ifdef TOPPERS_tskrun

bool_t
make_runnable(TCB *p_tcb)
{
	uint_t	pri = p_tcb->priority;

	queue_insert_prev(&(ready_queue[pri]), &(p_tcb->task_queue));
	primap_set(pri);

	if (p_schedtsk == (TCB *) NULL || pri < p_schedtsk->priority) {
		p_schedtsk = p_tcb;
		return(dspflg);
	}
	return(false);
}

#endif /* TOPPERS_tskrun */

/*
 *  ���s�ł����Ԃ��瑼�̏�Ԃւ̑J��
 *
 *  �ō��D�揇�ʂ̃^�X�N���X�V����̂́Cp_tcb���ō��D�揇�ʂ̃^�X�N��
 *  �������ꍇ�ł���Dp_tcb�Ɠ����D��x�̃^�X�N�����ɂ���ꍇ�́Cp_tcb
 *  �̎��̃^�X�N���ō��D�揇�ʂɂȂ�D�����łȂ��ꍇ�́C���f�B�L���[��
 *  �T�[�`����K�v������D
 */
#ifdef TOPPERS_tsknrun

bool_t
make_non_runnable(TCB *p_tcb)
{
	uint_t	pri = p_tcb->priority;
	QUEUE	*p_queue = &(ready_queue[pri]);

	queue_delete(&(p_tcb->task_queue));
	if (queue_empty(p_queue)) {
		primap_clear(pri);
		if (p_schedtsk == p_tcb) {
			p_schedtsk = primap_empty() ? (TCB *) NULL : search_schedtsk();
			return(dspflg);
		}
	}
	else {
		if (p_schedtsk == p_tcb) {
			p_schedtsk = (TCB *)(p_queue->p_next);
			return(dspflg);
		}
	}
	return(false);
}

#endif /* TOPPERS_tsknrun */

/*
 *  �x�~��Ԃւ̑J��
 */
#ifdef TOPPERS_tskdmt

void
make_dormant(TCB *p_tcb)
{
	p_tcb->tstat = TS_DORMANT;
	p_tcb->priority = p_tcb->p_tinib->ipriority;
	p_tcb->wupque = false;
	p_tcb->enatex = false;
	p_tcb->texptn = 0U;
	LOG_TSKSTAT(p_tcb);
}

#endif /* TOPPERS_tskdmt */

/*
 *  �x�~��Ԃ�����s�ł����Ԃւ̑J��
 */
#ifdef TOPPERS_tskact

bool_t
make_active(TCB *p_tcb)
{
	activate_context(p_tcb);
	p_tcb->tstat = TS_RUNNABLE;
	LOG_TSKSTAT(p_tcb);
	return(make_runnable(p_tcb));
}

#endif /* TOPPERS_tskact */

/*
 *  �^�X�N�̗D��x�̕ύX
 *
 *  �^�X�N�����s�ł����Ԃ̏ꍇ�ɂ́C���f�B�L���[�̒��ł̈ʒu��ύX��
 *  ��D�I�u�W�F�N�g�̑҂��L���[�̒��ő҂���ԂɂȂ��Ă���ꍇ�ɂ́C��
 *  ���L���[�̒��ł̈ʒu��ύX����D
 *
 *  �ō��D�揇�ʂ̃^�X�N���X�V����̂́C(1) p_tcb���ō��D�揇�ʂ̃^�X
 *  �N�ł����āC���̗D��x���������ꍇ�C(2) p_tcb���ō��D�揇�ʂ̃^�X
 *  �N�ł͂Ȃ��C�ύX��̗D��x���ō��D�揇�ʂ̃^�X�N�̗D��x��������
 *  �ꍇ�ł���D(1)�̏ꍇ�ɂ́C���f�B�L���[���T�[�`����K�v������D
 */
#ifdef TOPPERS_tskpri

bool_t
change_priority(TCB *p_tcb, uint_t newpri)
{
	uint_t	oldpri;

	oldpri = p_tcb->priority;
	p_tcb->priority = newpri;

	if (TSTAT_RUNNABLE(p_tcb->tstat)) {
		/*
		 *  �^�X�N�����s�ł����Ԃ̏ꍇ
		 */
		queue_delete(&(p_tcb->task_queue));
		if (queue_empty(&(ready_queue[oldpri]))) {
			primap_clear(oldpri);
		}
		queue_insert_prev(&(ready_queue[newpri]), &(p_tcb->task_queue));
		primap_set(newpri);

		if (p_schedtsk == p_tcb) {
			if (newpri >= oldpri) {
				p_schedtsk = search_schedtsk();
				return(p_schedtsk != p_tcb && dspflg);
			}
		}
		else {
			if (newpri < p_schedtsk->priority) {
				p_schedtsk = p_tcb;
				return(dspflg);
			}
		}
	}
	else {
		if (TSTAT_WAIT_WOBJCB(p_tcb->tstat)) {
			/*
			 *  �^�X�N���C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ�
			 *  ���iWOBJCB�j�̑҂��L���[�ɂȂ���Ă���ꍇ
			 */
			wobj_change_priority(((WINFO_WOBJ *)(p_tcb->p_winfo))->p_wobjcb,
																	p_tcb);
		}
	}
	return(false);
}

#endif /* TOPPERS_tskpri */

/*
 *  ���f�B�L���[�̉�]
 *
 *  �ō��D�揇�ʂ̃^�X�N���X�V����̂́C�ō��D�揇�ʂ̃^�X�N���^�X�N�L
 *  ���[�̖����Ɉړ������ꍇ�ł���D
 */
#ifdef TOPPERS_tskrot

bool_t
rotate_ready_queue(uint_t pri)
{
	QUEUE	*p_queue = &(ready_queue[pri]);
	QUEUE	*p_entry;

	if (!queue_empty(p_queue) && p_queue->p_next->p_next != p_queue) {
		p_entry = queue_delete_next(p_queue);
		queue_insert_prev(p_queue, p_entry);
		if (p_schedtsk == (TCB *) p_entry) {
			p_schedtsk = (TCB *)(p_queue->p_next);
			return(dspflg);
		}
	}
	return(false);
}

#endif /* TOPPERS_tskrot */

/*
 *  �^�X�N��O�������[�`���̌ďo��
 *
 *  ASP�J�[�l���ł́C�^�X�N��O�������[�`������CPU���b�N��ԂɑJ�ڂ��C
 *  ���̏�Ԃɖ߂����Ƀ��^�[�������ꍇ�C�J�[�l�������̏�Ԃɖ߂��D
 */
#ifdef TOPPERS_tsktex

void
call_texrtn(void)
{
	TEXPTN	texptn;
	bool_t	saved_disdsp;

	saved_disdsp = disdsp;
	p_runtsk->enatex = false;
	do {
		texptn = p_runtsk->texptn;
		p_runtsk->texptn = 0U;

		t_unlock_cpu();
		LOG_TEX_ENTER(p_runtsk, texptn);
		(*((TEXRTN)(p_runtsk->p_tinib->texrtn)))(texptn,
												p_runtsk->p_tinib->exinf);
		LOG_TEX_LEAVE(p_runtsk);
		if (!t_sense_lock()) {
			t_lock_cpu();
		}
		if (!ipmflg) {
			t_set_ipm(TIPM_ENAALL);
			ipmflg = true;
		}
		disdsp = saved_disdsp;
		dspflg = !disdsp;
		p_runtsk->enatex = false;
		if (p_runtsk != p_schedtsk && dspflg) {
			/*
			 *  ������dispatch���Ăяo�������́C���ݍċA�ďo���ɂȂ���
			 *  ���邪�Cdispatch���ĂԑO��p_runtsk->enatex��false�ɂ���
			 *  �����Ύx�Ⴊ�Ȃ��D���̗��R�ɂ��ẮC�uTOPPERS/ASP �J�[
			 *  �l�� �݌v�����v���Q�Ƃ̂��ƁD
			 */
			dispatch();
		}
	} while (p_runtsk->texptn != 0U);
	p_runtsk->enatex = true;
}

/*
 *  �^�X�N��O�������[�`���̋N��
 */
#ifndef OMIT_CALLTEX

void
calltex(void)
{
	if (p_runtsk->enatex && p_runtsk->texptn != 0U && ipmflg) {
		call_texrtn();
	}
}

#endif /* OMIT_CALLTEX */
#endif /* TOPPERS_tsktex */

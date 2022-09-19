/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: wait.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�҂���ԊǗ����W���[��
 */

#ifndef TOPPERS_WAIT_H
#define TOPPERS_WAIT_H

#include "task.h"
#include "time_event.h"

/*
 *  �^�X�N�̗D��x���̑҂��L���[�ւ̑}��
 *
 *  p_tcb�Ŏw�肳���^�X�N���C�^�X�N�D��x���̃L���[p_queue�ɑ}������D
 *  �L���[�̒��ɓ����D��x�̃^�X�N������ꍇ�ɂ́C���̍Ō�ɑ}������D
 */
Inline void
queue_insert_tpri(QUEUE *p_queue, TCB *p_tcb)
{
	QUEUE	*p_entry;
	uint_t	pri = p_tcb->priority;

	for (p_entry = p_queue->p_next; p_entry != p_queue;
										p_entry = p_entry->p_next) {
		if (pri < ((TCB *) p_entry)->priority) {
			break;
		}
	}
	queue_insert_prev(p_entry, &(p_tcb->task_queue));
}

/*
 *  �҂���Ԃւ̑J��
 *
 *  ���s���̃^�X�N��҂���ԂɑJ�ڂ�����D��̓I�ɂ́C���s���̃^�X�N��
 *  ���f�B�L���[����폜���CTCB��p_winfo�t�B�[���h�CWINFO��p_tmevtb�t�B�[
 *  ���h��ݒ肷��D
 */
Inline void
make_wait(WINFO *p_winfo)
{
	(void) make_non_runnable(p_runtsk);
	p_runtsk->p_winfo = p_winfo;
	p_winfo->p_tmevtb = NULL;
}

/*
 *  �҂���Ԃւ̑J�ځi�^�C���A�E�g�w��j
 *
 *  ���s���̃^�X�N���C�^�C���A�E�g�w��t���ő҂���ԂɑJ�ڂ�����D���
 *  �I�ɂ́C���s���̃^�X�N�����f�B�L���[����폜���CTCB��p_winfo�t�B�[
 *  ���h�CWINFO��p_tmevtb�t�B�[���h��ݒ肷��D�܂��C�^�C���C�x���g�u
 *  ���b�N��o�^����D
 */
extern void	make_wait_tmout(WINFO *p_winfo, TMEVTB *p_tmevtb, TMO tmout);

/*
 *  �҂������̂��߂̃^�X�N��Ԃ̍X�V
 *
 *  p_tcb�Ŏw�肳���^�X�N���C�҂���������悤�^�X�N��Ԃ��X�V����D
 *  �҂���������^�X�N�����s�ł����ԂɂȂ�ꍇ�́C���f�B�L���[�ɂ�
 *  ���D�܂��C�f�B�X�p�b�`���K�v�ȏꍇ�ɂ�true��Ԃ��D
 */
Inline bool_t
make_non_wait(TCB *p_tcb)
{
	assert(TSTAT_WAITING(p_tcb->tstat));

	if (!TSTAT_SUSPENDED(p_tcb->tstat)) {
		/*
		 *  �҂���Ԃ�����s�ł����Ԃւ̑J��
		 */
		p_tcb->tstat = TS_RUNNABLE;
		LOG_TSKSTAT(p_tcb);
		return(make_runnable(p_tcb));
	}
	else {
		/*
		 *  ��d�҂���Ԃ��狭���҂���Ԃւ̑J��
		 */
		p_tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		return(false);
	}
}

/*
 *  �I�u�W�F�N�g�҂��L���[����̍폜
 *
 *  p_tcb�Ŏw�肳���^�X�N���C�����E�ʐM�I�u�W�F�N�g�̑҂��L���[�ɂ�
 *  �Ȃ���Ă���΁C�҂��L���[����폜����D
 */
Inline void
wait_dequeue_wobj(TCB *p_tcb)
{
	if (TSTAT_WAIT_WOBJ(p_tcb->tstat)) {
		queue_delete(&(p_tcb->task_queue));
	}
}

/*
 *  ���ԑ҂��̂��߂̃^�C���C�x���g�u���b�N�̓o�^����
 *
 *  p_tcb�Ŏw�肳���^�X�N�ɑ΂��āC���ԑ҂��̂��߂̃^�C���C�x���g�u
 *  ���b�N���o�^����Ă���΁C�����o�^��������D
 */
Inline void
wait_dequeue_tmevtb(TCB *p_tcb)
{
	if (p_tcb->p_winfo->p_tmevtb != NULL) {
		tmevtb_dequeue(p_tcb->p_winfo->p_tmevtb);
	}
}

/*
 *  �҂�����
 *
 *  p_tcb�Ŏw�肳���^�X�N�̑҂���Ԃ���������D��̓I�ɂ́C�^�C���C
 *  �x���g�u���b�N���o�^����Ă���΁C�����o�^��������D�܂��C�^�X�N
 *  ��Ԃ��X�V���C�҂����������^�X�N����̕Ԓl��E_OK�Ƃ���D�҂��L���[
 *  ����̍폜�͍s��Ȃ��D�҂����������^�X�N�ւ̃f�B�X�p�b�`���K�v�ȏ�
 *  ���ɂ�true��Ԃ��D
 */
extern bool_t	wait_complete(TCB *p_tcb);

/*
 *  �^�C���A�E�g�ɔ����҂�����
 *
 *  p_tcb�Ŏw�肳���^�X�N���C�҂��L���[�ɂȂ���Ă���Α҂��L���[
 *  ����폜���C�^�X�N��Ԃ��X�V����D�܂��C�҂����������^�X�N����̕�
 *  �l���Cwait_tmout�ł�E_TMOUT�Cwait_tmout_ok�ł�E_OK�Ƃ���D�҂�����
 *  �����^�X�N�ւ̃f�B�X�p�b�`���K�v�Ȏ��́Creqflg��true�ɂ���D
 *
 *  wait_tmout_ok�́Cdly_tsk�Ŏg�����߂̂��̂ŁC�҂��L���[����폜����
 *  �������s��Ȃ��D
 *
 *  ������̊֐����C�^�C���C�x���g�̃R�[���o�b�N�֐��Ƃ��ėp���邽�߂�
 *  ���̂ŁC�����݃n���h������Ăяo����邱�Ƃ�z�肵�Ă���D
 */
extern void	wait_tmout(TCB *p_tcb);
extern void	wait_tmout_ok(TCB *p_tcb);

/*
 *  �҂���Ԃ̋�������
 *
 *  p_tcb�Ŏw�肳���^�X�N�̑҂���Ԃ������I�ɉ�������D��̓I�ɂ́C
 *  �^�X�N���҂��L���[�ɂȂ���Ă���Α҂��L���[����폜���C�^�C���C
 *  �x���g�u���b�N���o�^����Ă���΂����o�^��������D�܂��C�^�X�N��
 *  ��Ԃ��X�V���C�҂����������^�X�N����̕Ԓl��E_RLWAI�Ƃ���D�܂��C
 *  �҂����������^�X�N�ւ̃f�B�X�p�b�`���K�v�ȏꍇ�ɂ�true��Ԃ��D
 */
extern bool_t	wait_release(TCB *p_tcb);

/*
 *  �҂��L���[�̐擪�̃^�X�NID
 *
 *  p_wait_queue�Ŏw�肵���҂��L���[�̐擪�̃^�X�NID��Ԃ��D�҂��L���[
 *  ����̏ꍇ�ɂ́CTSK_NONE��Ԃ��D
 */
Inline ID
wait_tskid(QUEUE *p_wait_queue)
{
	if (!queue_empty(p_wait_queue)) {
		return(TSKID((TCB *) p_wait_queue->p_next));
	}
	else {
		return(TSK_NONE);
	}
}

/*
 *  �����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ������샋�[�`��
 *
 *  �����E�ʐM�I�u�W�F�N�g�̏������u���b�N�ƊǗ��u���b�N�̐擪�����͋�
 *  �ʂɂȂ��Ă���D�ȉ��́C���̋��ʕ������������߂̌^����у��[�`���Q
 *  �ł���D
 *
 *  �����̑҂��L���[���������E�ʐM�I�u�W�F�N�g�̏ꍇ�C�擪�ȊO�̑҂�
 *  �L���[�𑀍삷��ꍇ�ɂ́C�����̃��[�`���͎g���Ȃ��D�܂��C�I�u�W�F
 *  �N�g������TA_TPRI�r�b�g���Q�Ƃ���̂ŁC���̃r�b�g�𑼂̖ړI�Ɏg����
 *  ����ꍇ���C�����̃��[�`���͎g���Ȃ��D
 */

/*
 *  �����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 */
typedef struct wait_object_initialization_block {
	ATR			wobjatr;		/* �I�u�W�F�N�g���� */
} WOBJINIB;

/*
 *  �����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ���
 */
typedef struct wait_object_control_block {
	QUEUE		wait_queue;		/* �҂��L���[ */
	const WOBJINIB *p_wobjinib;	/* �������u���b�N�ւ̃|�C���^ */
} WOBJCB;

/*
 *  �����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *
 *  ���̍\���̂́C�҂����u���b�N�iWINFO�j���g���i�I�u�W�F�N�g�w����
 *  ��̌p���ɑ����j�������̂ł��邪�CWINFO�����p�̂Œ�`����Ă��邽
 *  �߂ɁC1�̃t�B�[���h�Ƃ��Ċ܂߂Ă���D
 */
typedef struct wait_object_waiting_information {
	WINFO	winfo;			/* �W���̑҂����u���b�N */
	WOBJCB	*p_wobjcb;		/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
} WINFO_WOBJ;

/*
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃւ̑J��
 *  
 *  ���s���̃^�X�N��҂���ԂɑJ�ڂ����C�����E�ʐM�I�u�W�F�N�g�̑҂��L���[
 *  �ɂȂ��D�܂��C�҂����u���b�N�iWINFO�j��p_wobjcb��ݒ肷��D
 *  wobj_make_wait_tmout�́C�^�C���C�x���g�u���b�N�̓o�^���s���D
 */
extern void	wobj_make_wait(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo);
extern void	wobj_make_wait_tmout(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo,
											TMEVTB *p_tmevtb, TMO tmout);

/*
 *  �^�X�N�D��x�ύX���̏���
 *
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃɂ���^�X�N�̗D��x���ύX��
 *  �ꂽ�ꍇ�ɁC�҂��L���[�̒��ł̃^�X�N�̈ʒu���C������D
 */
Inline void
wobj_change_priority(WOBJCB *p_wobjcb, TCB *p_tcb)
{
	if ((p_wobjcb->p_wobjinib->wobjatr & TA_TPRI) != 0U) {
		queue_delete(&(p_tcb->task_queue));
		queue_insert_tpri(&(p_wobjcb->wait_queue), p_tcb);
	}
}

/*
 *  �҂��L���[�̏�����
 *
 *  �҂��L���[�ɂȂ���Ă���^�X�N�����ׂđ҂���������D�҂���������
 *  �^�X�N����̕Ԓl�́CE_DLT�Ƃ���D�҂����������^�X�N�ւ̃f�B�X�p�b�`
 *  ���K�v�ȏꍇ��true�C�����łȂ��ꍇ��false��Ԃ��D
 */
extern bool_t	init_wait_queue(QUEUE *p_wait_queue);

#endif /* TOPPERS_WAIT_H */

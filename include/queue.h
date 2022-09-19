/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: queue.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�L���[���색�C�u����
 *
 *  ���̃L���[���색�C�u�����ł́C�L���[�w�b�_���܂ރ����O�\���̃_�u��
 *  �����N�L���[�������D��̓I�ɂ́C�L���[�w�b�_�̎��G���g���̓L���[��
 *  �擪�̃G���g���C�O�G���g���̓L���[�̖����̃G���g���Ƃ���D�܂��C�L
 *  ���[�̐擪�̃G���g���̑O�G���g���ƁC�L���[�̖����̃G���g���̎��G��
 *  �g���́C�L���[�w�b�_�Ƃ���D��̃L���[�́C���G���g���C�O�G���g����
 *  ���������g���w���L���[�w�b�_�ł���킷�D
 */

#ifndef	TOPPERS_QUEUE_H
#define	TOPPERS_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  �L���[�̃f�[�^�\���̒�`
 */
typedef struct queue {
	struct queue *p_next;		/* ���G���g���ւ̃|�C���^ */
	struct queue *p_prev;		/* �O�G���g���ւ̃|�C���^ */
} QUEUE;

/*
 *  �L���[�̏�����
 *
 *  p_queue�ɂ̓L���[�w�b�_���w�肷��D
 */
Inline void
queue_initialize(QUEUE *p_queue)
{
	p_queue->p_prev = p_queue;
	p_queue->p_next = p_queue;
}

/*
 *  �L���[�̑O�G���g���ւ̑}��
 *
 *  p_queue�̑O��p_entry��}������Dp_queue�ɃL���[�w�b�_���w�肵����
 *  ���ɂ́C�L���[�̖�����p_entry��}�����邱�ƂɂȂ�D
 */
Inline void
queue_insert_prev(QUEUE *p_queue, QUEUE *p_entry)
{
	p_entry->p_prev = p_queue->p_prev;
	p_entry->p_next = p_queue;
	p_queue->p_prev->p_next = p_entry;
	p_queue->p_prev = p_entry;
}

/*
 *  �L���[�̎��G���g���ւ̑}��
 *
 *  p_queue�̎���p_entry��}������Dp_queue�ɃL���[�w�b�_���w�肵����
 *  ���ɂ́C�L���[�̐擪��p_entry��}�����邱�ƂɂȂ�D
 */
Inline void
queue_insert_next(QUEUE *p_queue, QUEUE *p_entry)
{
	p_entry->p_prev = p_queue;
	p_entry->p_next = p_queue->p_next;
	p_queue->p_next->p_prev = p_entry;
	p_queue->p_next = p_entry;
}

/*
 *  �G���g���̍폜
 *
 *  p_entry���L���[����폜����D
 */
Inline void
queue_delete(QUEUE *p_entry)
{
	p_entry->p_prev->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_entry->p_prev;
}

/*
 *  �L���[�̎��G���g���̎�o��
 *
 *  p_queue�̎��G���g�����L���[����폜���C�폜�����G���g����Ԃ��D
 *  p_queue�ɃL���[�w�b�_���w�肵���ꍇ�ɂ́C�L���[�̐擪�̃G���g����
 *  ���o�����ƂɂȂ�Dp_queue�ɋ�̃L���[���w�肵�ČĂяo���Ă͂Ȃ�
 *  �Ȃ��D
 */
Inline QUEUE *
queue_delete_next(QUEUE *p_queue)
{
	QUEUE	*p_entry;

	assert(p_queue->p_next != p_queue);
	p_entry = p_queue->p_next;
	p_queue->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_queue;
	return(p_entry);
}

/*
 *  �L���[���󂩂ǂ����̃`�F�b�N
 *
 *  p_queue�ɂ̓L���[�w�b�_���w�肷��D
 */
Inline bool_t
queue_empty(QUEUE *p_queue)
{
	if (p_queue->p_next == p_queue) {
		assert(p_queue->p_prev == p_queue);
		return(true);
	}
	return(false);
}

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_QUEUE_H */

/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2013 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: time_event.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�C���C�x���g�Ǘ����W���[��
 */

#include "kernel_impl.h"
#include "time_event.h"

/*
 *  �^�C���C�x���g�q�[�v����}�N��
 */
#define	PARENT(index)		((index) >> 1)		/* �e�m�[�h�����߂� */
#define	LCHILD(index)		((index) << 1)		/* ���̎q�m�[�h�����߂� */
#define	TMEVT_NODE(index)	(tmevt_heap[(index) - 1])

/*
 *  �C�x���g����������r�}�N��
 *
 *  �C�x���g���������́Cmin_time����̑��Βl�Ŕ�r����D���Ȃ킿�C
 *  min_time���ŏ��l�i�ł��߂������j�Cmit_time-1���ő�l�i�ł����������j
 *  �Ƃ݂Ȃ��Ĕ�r����D
 */
#define	EVTTIM_LT(t1, t2) (((t1) - min_time) < ((t2) - min_time))
#define	EVTTIM_LE(t1, t2) (((t1) - min_time) <= ((t2) - min_time))

#ifdef TOPPERS_tmeini

/*
 *  ���݂̃V�X�e�������i�P��: 1�~���b�j
 *
 *  �����ɂ́C�O�̃^�C���e�B�b�N�̃V�X�e�������D
 */
EVTTIM	current_time;

/*
 *  �^�C���C�x���g�q�[�v���ŗL���ȍŏ��̃V�X�e�������i�P��: 1�~���b�j
 */
EVTTIM	min_time;

/*
 *  ���̃^�C���e�B�b�N�̃V�X�e�������i�P��: 1�~���b�j
 */
EVTTIM	next_time;

/*
 *  �V�X�e�������ώZ�p�ϐ��i�P��: 1/TIC_DENO�~���b�j
 */
#if TIC_DENO != 1U
uint_t	next_subtime;
#endif /* TIC_DENO != 1U */

/*
 *  �^�C���C�x���g�q�[�v�̍Ō�̎g�p�̈�̃C���f�b�N�X
 */
uint_t	last_index;

/*
 *  �^�C�}���W���[���̏�����
 */
void
initialize_tmevt(void)
{
	current_time = 0U;
	min_time = 0U;
	next_time = current_time + TIC_NUME / TIC_DENO;
#if TIC_DENO != 1U
	next_subtime = TIC_NUME % TIC_DENO;
#endif /* TIC_DENO != 1U */
	last_index = 0U;
}

#endif /* TOPPERS_tmeini */

/*
 *  �^�C���C�x���g�̑}���ʒu��������ɒT��
 *
 *  ����time�ɔ�������^�C���C�x���g��}������m�[�h���󂯂邽�߂ɁC
 *  �q�[�v�̏�Ɍ������ċ�m�[�h���ړ�������D�ړ��O�̋�m�[�h�̈ʒu��
 *  index�ɓn���ƁC�ړ���̋�m�[�h�̈ʒu�i���Ȃ킿�}���ʒu�j��Ԃ��D
 */
#ifdef TOPPERS_tmeup

uint_t
tmevt_up(uint_t index, EVTTIM time)
{
	uint_t	parent;

	while (index > 1) {
		/*
		 *  �e�m�[�h�̃C�x���g���������̕��������i�܂��͓����j�Ȃ�΁C
		 *  index���}���ʒu�Ȃ̂Ń��[�v�𔲂���D
		 */
		parent = PARENT(index);
		if (EVTTIM_LE(TMEVT_NODE(parent).time, time)) {
			break;
		}

		/*
		 *  �e�m�[�h��index�̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  index��e�m�[�h�̈ʒu�ɍX�V�D
		 */
		index = parent;
	}
	return(index);
}

#endif /* TOPPERS_tmeup */

/*
 *  �^�C���C�x���g�̑}���ʒu���������ɒT��
 *
 *  ����time�ɔ�������^�C���C�x���g��}������m�[�h���󂯂邽�߂ɁC
 *  �q�[�v�̉��Ɍ������ċ�m�[�h���ړ�������D�ړ��O�̋�m�[�h�̈ʒu�� 
 *  index�ɓn���ƁC�ړ���̋�m�[�h�̈ʒu�i���Ȃ킿�}���ʒu�j��Ԃ��D
 */
#ifdef TOPPERS_tmedown

uint_t
tmevt_down(uint_t index, EVTTIM time)
{
	uint_t	child;

	while ((child = LCHILD(index)) <= last_index) {
		/*
		 *  ���E�̎q�m�[�h�̃C�x���g�����������r���C�������̎q�m�[�h
		 *  �̈ʒu��child�ɐݒ肷��D�ȉ��̎q�m�[�h�́C�����őI�΂ꂽ��
		 *  �̎q�m�[�h�̂��ƁD
		 */
		if (child + 1 <= last_index
						&& EVTTIM_LT(TMEVT_NODE(child + 1).time,
										TMEVT_NODE(child).time)) {
			child = child + 1;
		}

		/*
		 *  �q�m�[�h�̃C�x���g���������̕����x���i�܂��͓����j�Ȃ�΁C
		 *  index���}���ʒu�Ȃ̂Ń��[�v�𔲂���D
		 */
		if (EVTTIM_LE(time, TMEVT_NODE(child).time)) {
			break;
		}

		/*
		 *  �q�m�[�h��index�̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(child);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  index���q�m�[�h�̈ʒu�ɍX�V�D
		 */
		index = child;
	}
	return(index);
}

#endif /* TOPPERS_tmedown */

/*
 *  �^�C���C�x���g�q�[�v�ւ̓o�^
 *
 *  p_tmevtb�Ŏw�肵���^�C���C�x���g�u���b�N���Ctime�Ŏw�肵�����Ԃ��o
 *  �ߌ�ɃC�x���g����������悤�ɁC�^�C���C�x���g�q�[�v�ɓo�^����D
 */
#ifdef TOPPERS_tmeins

void
tmevtb_insert(TMEVTB *p_tmevtb, EVTTIM time)
{
	uint_t	index;

	/*
	 *  last_index���C���N�������g���C���������ɑ}���ʒu��T���D
	 */
	index = tmevt_up(++last_index, time);

	/*
	 *  �^�C���C�x���g��index�̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index).time = time;
	TMEVT_NODE(index).p_tmevtb = p_tmevtb;
	p_tmevtb->index = index;
}

#endif /* TOPPERS_tmeins */

/*
 *  �^�C���C�x���g�q�[�v����̍폜
 */
#ifdef TOPPERS_tmedel

void
tmevtb_delete(TMEVTB *p_tmevtb)
{
	uint_t	index = p_tmevtb->index;
	uint_t	parent;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  �폜�ɂ��^�C���C�x���g�q�[�v����ɂȂ�ꍇ�͉������Ȃ��D
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  �폜�����m�[�h�̈ʒu�ɍŌ�̃m�[�h�ilast_index+1�̈ʒu�̃m�[�h�j
	 *  ��}�����C�����K�؂Ȉʒu�ֈړ�������D���ۂɂ́C�Ō�̃m�[�h
	 *  �����ۂɑ}������̂ł͂Ȃ��C�폜�����m�[�h�̈ʒu����m�[�h�ɂ�
	 *  ��̂ŁC�Ō�̃m�[�h��}�����ׂ��ʒu�֌����ċ�m�[�h���ړ�����
	 *  ��D
	 *  �Ō�̃m�[�h�̃C�x���g�����������C�폜�����m�[�h�̐e�m�[�h�̃C
	 *  �x���g�����������O�̏ꍇ�ɂ́C��Ɍ������đ}���ʒu��T���D��
	 *  ���łȂ��ꍇ�ɂ́C���Ɍ������ĒT���D
	 */
	if (index > 1 && EVTTIM_LT(event_time,
								TMEVT_NODE(parent = PARENT(index)).time)) {
		/*
		 *  �e�m�[�h��index�̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  �폜�����m�[�h�̐e�m�[�h�����Ɍ������đ}���ʒu��T���D
		 */
		index = tmevt_up(parent, event_time);
	}
	else {
		/*
		 *  �폜�����m�[�h���牺�Ɍ������đ}���ʒu��T���D
		 */
		index = tmevt_down(index, event_time);
	}

	/*
	 *  �Ō�̃m�[�h��index�̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).p_tmevtb->index = index;
}

#endif /* TOPPERS_tmedel */

/*
 *  �^�C���C�x���g�q�[�v�̐擪�̃m�[�h�̍폜
 */
Inline void
tmevtb_delete_top(void)
{
	uint_t	index;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  �폜�ɂ��^�C���C�x���g�q�[�v����ɂȂ�ꍇ�͉������Ȃ��D
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  ���[�g�m�[�h�ɍŌ�̃m�[�h�ilast_index + 1 �̈ʒu�̃m�[�h�j��
	 *  �}�����C�����K�؂Ȉʒu�ֈړ�������D���ۂɂ́C�Ō�̃m�[�h��
	 *  ���ۂɑ}������̂ł͂Ȃ��C���[�g�m�[�h����m�[�h�ɂȂ�̂ŁC��
	 *  ��̃m�[�h��}�����ׂ��ʒu�֌����ċ�m�[�h���ړ�������D
	 */
	index = tmevt_down(1, event_time);

	/*
	 *  �Ō�̃m�[�h��index�̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).p_tmevtb->index = index;
}

/*
 *  �^�C���C�x���g�܂ł̎c�莞�Ԃ̌v�Z
 */
#ifdef TOPPERS_tmeltim

RELTIM
tmevt_lefttim(TMEVTB *p_tmevtb)
{
	EVTTIM	time;

	time = TMEVT_NODE(p_tmevtb->index).time;
	if (EVTTIM_LE(time, next_time)) {
		/*
		 *  ���̃^�C���e�B�b�N�ŏ��������ꍇ�ɂ�0��Ԃ��D
		 */
		return(0U);
	}
	else {
		return((RELTIM)(time - base_time));
	}
}

#endif /* TOPPERS_tmeltim */

/*
 *  �^�C���e�B�b�N�̋���
 */
#ifdef TOPPERS_sigtim

void
signal_time(void)
{
	TMEVTB	*p_tmevtb;

	assert(sense_context());
	assert(!i_sense_lock());

	i_lock_cpu();

	/*
	 *  current_time���X�V����D
	 */
	current_time = next_time;

	/*
	 *  next_time�Cnext_subtime���X�V����D
	 */
#if TIC_DENO == 1U
	next_time = current_time + TIC_NUME;
#else /* TIC_DENO == 1U */
	next_subtime += TIC_NUME % TIC_DENO;
	next_time = current_time + TIC_NUME / TIC_DENO;
	if (next_subtime >= TIC_DENO) {
		next_subtime -= TIC_DENO;
		next_time += 1U;
	}
#endif /* TIC_DENO == 1U */

	/*
	 *  current_time���C�x���g���������̑����i�܂��͓����j�^�C���C�x
	 *  ���g���C�^�C���C�x���g�q�[�v����폜���C�R�[���o�b�N�֐����Ă�
	 *  �o���D
	 */
	while (last_index > 0 && EVTTIM_LE(TMEVT_NODE(1).time, current_time)) {
		p_tmevtb = TMEVT_NODE(1).p_tmevtb;
		tmevtb_delete_top();
		(*(p_tmevtb->callback))(p_tmevtb->arg);
	}

	/*
	 *  min_time���X�V����D
	 */
	min_time = current_time;

	i_unlock_cpu();
}

#endif /* TOPPERS_sigtim */

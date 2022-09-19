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
 *  $Id: time_event.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�C���C�x���g�Ǘ����W���[��
 */

#ifndef TOPPERS_TIME_EVENT_H
#define TOPPERS_TIME_EVENT_H

/*
 *  �C�x���g���������̃f�[�^�^�̒�`
 *
 *  EVTTIM�́CRELTIM�Ƃ��Ďw��ł���͈͂����L���͈͂�\���ł���K�v
 *  ������D��ITRON4.0�d�l�̃X�^���_�[�h�v���t�@�C���ł́CRELTIM��16�r�b
 *  �g�ȏ�łȂ���΂Ȃ�Ȃ����߁CEVTTIM��17�r�b�g�ȏ�ł��邱�Ƃ��K�v
 *  �ł���D���̂��߁C16�r�b�g�ɂȂ�ꍇ������uint_t�ł͂Ȃ��Culong_t��
 *  ��`���Ă���D
 */
typedef ulong_t	EVTTIM;

/* 
 *  �^�C���C�x���g�u���b�N�̃f�[�^�^�̒�`
 */
typedef void	(*CBACK)(void *);	/* �R�[���o�b�N�֐��̌^ */

typedef struct time_event_block {
	uint_t	index;			/* �^�C���C�x���g�q�[�v���ł̈ʒu */
	CBACK	callback;		/* �R�[���o�b�N�֐� */
	void	*arg;			/* �R�[���o�b�N�֐��֓n������ */
} TMEVTB;

/*
 *  �^�C���C�x���g�q�[�v���̃m�[�h�̃f�[�^�^�̒�`
 */
typedef struct time_event_node {
	EVTTIM	time;			/* �C�x���g�������� */
	TMEVTB	*p_tmevtb;		/* �Ή�����^�C���C�x���g�u���b�N */
} TMEVTN;

/*
 *  �^�C���C�x���g�q�[�v�ikernel_cfg.c�j
 */
extern TMEVTN	tmevt_heap[];

/*
 *  ���݂̃V�X�e�������i�P��: 1�~���b�j
 *
 *  �V�X�e���N������0�ɏ���������C�ȍ~�C�^�C���e�B�b�N�����������x��
 *  �P���ɑ�������D
 */
extern EVTTIM	current_time;

/*
 *  �^�C���C�x���g�q�[�v���ŗL���ȍŏ��̃V�X�e�������i�P��: 1�~���b�j
 */
extern EVTTIM	min_time;

/*
 *  ���̃^�C���e�B�b�N�̃V�X�e�������i�P��: 1�~���b�j
 */
extern EVTTIM	next_time;

/*
 *  �V�X�e�������ώZ�p�ϐ��i�P��: 1/TIC_DENO�~���b�j
 *
 *  ���̃^�C���e�B�b�N�̃V�X�e�������̉��ʌ��������i��ʌ���next_time�j�D
 *  TIC_DENO��1�̎��́C���ʌ��͏��0�ł��邽�߁C���̕ϐ��͕K�v�Ȃ��D
 */
#if TIC_DENO != 1U
extern uint_t	next_subtime;
#endif /* TIC_DENO != 1U */

/*
 *  ���Ύ��Ԃ̊�����i�P��: 1�~���b�j
 *
 *  ���̃^�C���e�B�b�N�̃V�X�e��������؂�グ�������DTIC_DENO��1�̎�
 *  �́Cnext_time�Ɉ�v����D
 */
#if TIC_DENO == 1U
#define	base_time	(next_time)
#else /* TIC_DENO == 1U */
#define	base_time	(next_time + (next_subtime > 0U ? 1U : 0U))
#endif /* TIC_DENO == 1U */

/*
 *  �^�C���C�x���g�q�[�v�̍Ō�̎g�p�̈�̃C���f�b�N�X
 *
 *  �^�C���C�x���g�q�[�v�ɓo�^����Ă���^�C���C�x���g�̐��Ɉ�v����D
 */
extern uint_t	last_index;

/*
 *  �^�C���C�x���g�Ǘ����W���[���̏�����
 */
extern void	initialize_tmevt(void);

/*
 *  �^�C���C�x���g�̑}���ʒu�̒T��
 */
extern uint_t	tmevt_up(uint_t index, EVTTIM time);
extern uint_t	tmevt_down(uint_t index, EVTTIM time);

/*
 *  �^�C���C�x���g�q�[�v�ւ̓o�^�ƍ폜
 */
extern void	tmevtb_insert(TMEVTB *p_tmevtb, EVTTIM time);
extern void	tmevtb_delete(TMEVTB *p_tmevtb);

/*
 *  �^�C���C�x���g�u���b�N�̓o�^�i���Ύ��Ԏw��j
 *
 *  time�Ŏw�肵�����Ύ��Ԃ��o�߂�����ɁCarg�������Ƃ���callback����
 *  �яo�����悤�ɁCp_tmevtb�Ŏw�肵���^�C���C�x���g�u���b�N��o�^��
 *  ��D
 *  
 */
Inline void
tmevtb_enqueue(TMEVTB *p_tmevtb, RELTIM time, CBACK callback, void *arg)
{
	assert(time <= TMAX_RELTIM);

	p_tmevtb->callback = callback;
	p_tmevtb->arg = arg;
	tmevtb_insert(p_tmevtb, base_time + time);
}

/*
 *  �^�C���C�x���g�u���b�N�̓o�^�i�C�x���g���������w��j
 *
 *  time�Ŏw�肵���C�x���g���������ɁCarg�������Ƃ���callback���Ăяo
 *  �����悤�ɁCp_tmevtb�Ŏw�肵���^�C���C�x���g�u���b�N��o�^����D
 */
Inline void
tmevtb_enqueue_evttim(TMEVTB *p_tmevtb, EVTTIM time, CBACK callback, void *arg)
{
	p_tmevtb->callback = callback;
	p_tmevtb->arg = arg;
	tmevtb_insert(p_tmevtb, time);
}

/*
 *  �^�C���C�x���g�u���b�N�̓o�^����
 */
Inline void
tmevtb_dequeue(TMEVTB *p_tmevtb)
{
	tmevtb_delete(p_tmevtb);
}

/*
 *  �^�C���C�x���g�܂ł̎c�莞�Ԃ̌v�Z
 */
extern RELTIM	tmevt_lefttim(TMEVTB *p_tmevtb);

/*
 *  �^�C���e�B�b�N�̋���
 */
extern void	signal_time(void);

#endif /* TOPPERS_TIME_EVENT_H */

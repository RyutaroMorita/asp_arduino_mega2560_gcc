/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_config.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�v���Z�b�T�ˑ����W���[���iM68040�p�j
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  CPU���b�N�t���O�����̂��߂̕ϐ�
 */
volatile bool_t		lock_flag;		/* CPU���b�N�t���O�̒l��ێ�����ϐ� */
volatile uint16_t	saved_iipm;		/* �����ݗD��x�}�X�N��ۑ�����ϐ� */

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
prc_initialize(void)
{
	/*
	 *  CPU���b�N�t���O�����̂��߂̕ϐ��̏�����
	 */
	lock_flag = true;
	saved_iipm = IIPM_ENAALL;

	/*
	 *  ��O�x�N�^�e�[�u���̏�����
	 */
#ifdef EXCVT_KERNEL
	memcpy(EXCVT_KERNEL, EXCVT_ORIG, EXCVT_LEN);
	set_vbr(EXCVT_KERNEL);
#endif /* EXCVT_KERNEL */
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
prc_terminate(void)
{
	extern void	software_term_hook(void);
	void (*volatile fp)(void) = software_term_hook;

	/*
	 *  software_term_hook�ւ̃|�C���^���C��Uvolatile�w��̂���fp�ɑ�
	 *  �����Ă���g���̂́C0�Ƃ̔�r���œK���ō폜����Ȃ��悤�ɂ��邽
	 *  �߂ł���D
	 */
	if (fp != 0) {
		(*fp)();
	}

#ifdef EXCVT_KERNEL
	set_vbr(EXCVT_ORIG);
#endif /* EXCVT_KERNEL */
}

/*
 *  CPU��O�̔����󋵂̃��O�o��
 *
 *  CPU��O�n���h���̒�����CCPU��O���|�C���^�ip_excinf�j�������Ƃ�
 *  �ČĂяo�����ƂŁCCPU��O�̔����󋵂��V�X�e�����O�ɏo�͂���D
 */
#ifdef SUPPORT_XLOG_SYS

void
xlog_sys(void *p_excinf)
{
	char	*excsp = (char *) p_excinf;
	uint_t	format;

	syslog_0(LOG_ERROR, "CPU Exception Information:");
	syslog_4(LOG_ERROR, "SR = %04x (M = %d, S = %d, IPM = %d)",
				*((uint16_t *) excsp),
				(*((uint16_t *) excsp) & 0x1000U) >> 12,
				(*((uint16_t *) excsp) & 0x2000U) >> 13,
				(*((uint16_t *) excsp) & 0x0700U) >> 8);
	syslog_1(LOG_ERROR, "PC = %08x", *((uint32_t *)(excsp + 2)));
	format = (*((uint16_t *)(excsp + 6)) & 0xf000U) >> 12;
	syslog_2(LOG_ERROR, "Format = %d, Vector Offset = %03x",
				format, (*((uint16_t *)(excsp + 6)) & 0x0fffU));
	if (format >= 2U) {
		syslog_1(LOG_ERROR, "ADR = %08x", *((uint32_t *)(excsp + 8)));
	}
}

#endif /* SUPPORT_XLOG_SYS */

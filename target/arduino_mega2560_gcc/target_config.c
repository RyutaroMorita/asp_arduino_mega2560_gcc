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
 *  @(#) $Id: target_config.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�^�[�Q�b�g�ˑ����W���[���iArduino Mega2560�p�j
 */

#include "kernel_impl.h"
#include "target_syssvc.h"
#include <sil.h>
#include <avr/io.h>

/*
 *  �v���Z�b�T���ʂ̂��߂̕ϐ��i�}���`�v���Z�b�T�Ή��j
 */
uint_t	board_id;			/* �{�[�hID */
void	*board_addr;		/* ���[�J���������̐擪�A�h���X */

/*
 *  �N�����̃n�[�h�E�F�A����������
 */
void
hardware_init_hook(void) {
	/*
	 *  -fdata-sections���g�p�����istk���폜����C
	 *  cfg�̃p�X3�̃`�F�b�N���G���[�ƂȂ邽�߁C
	 *  �폜����Ȃ��悤�ɂ���
	 */
//	SystemCoreClock = (uint32_t)istk;
}

void
usart_early_init()
{
	/* Set baudrate parameter = 9600bps */
	//UBRR0 = (16000000/16/9600-1);
	UBRR0 =  (SYS_CLOCK/16/BPS_SETTING-1);
	/* Enable receiver and transmitter */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	/* Set frame format: 8data, 1stop bit : 8N1 */
	UCSR0C = (0 << USBS0) | (3 << UCSZ00);
}

/*
 *  �^�[�Q�b�g�ˑ��̏�����
 */
void
target_initialize(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏�����
	 */
	prc_initialize();

	usart_early_init();
}

/*
 *  �^�[�Q�b�g�ˑ��̏I������
 */
void
target_exit(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏I������
	 */
	prc_terminate();
	while(1);
}

/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void
target_fput_log(char c)
{
	if (c == '\n') {
		while ( !(UCSR0A & (1 << UDRE0)));
		UDR0 = '\r';
	}
	while ( !(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

/*
 *  �����ݗv�����C���̑����̐ݒ�
 *
 *  ASP�J�[�l���ł̗��p��z�肵�āC�p�����[�^�G���[�̓A�T�[�V�����Ń`�F�b
 *  �N���Ă���Dcfg_int�T�[�r�X�R�[����݂���ꍇ�ɂ́C�G���[��Ԃ��悤
 *  �ɂ��ׂ��ł��낤�D
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	assert(VALID_INTNO_CFGINT(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);
}

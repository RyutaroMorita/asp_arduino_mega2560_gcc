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
 *	2022/9/20 Ryutaro Morita
 */

/*
 *		�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iArduino Mega2560�p�j
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_serial.h"

/*
 * ���W�X�^�ݒ�l
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 * USART���W�X�^��`
 */
#define UART_UCSRxA(x)		(x)
#define UART_UCSRxB(x)		(x + 0x01)
#define UART_UCSRxC(x)		(x + 0x02)
#define UART_UBRRx(x)		(x + 0x04)
#define UART_UDRx(x)		(x + 0x06)

/*
 *  �V���A���|�[�g�̊Ǘ��u���b�N
 */
struct sio_port_control_block {
	ID port;
	uint8_t reg;
	intptr_t exinf;
};

/*
 * �V���A��I/O�|�[�g�Ǘ��u���b�N�G���A
 */
SIOPCB siopcb_table[TNUM_PORT];

static const uint32_t sioreg_table[TNUM_PORT] = {
	0xC0,
#if (TNUM_PORT >= 2)
	0xC8,
#endif
};

Inline bool_t
sio_putready(SIOPCB* siopcb)
{
	if ((_SFR_MEM8(UART_UCSRxB(siopcb->reg)) & (1 << UDRIE0)) &&
		(_SFR_MEM8(UART_UCSRxA(siopcb->reg)) & (1 << UDRE0)))
	{
		return 1;
	}
	return 0;
}

Inline bool_t
sio_getready(SIOPCB* siopcb)
{
	if ((_SFR_MEM8(UART_UCSRxB(siopcb->reg)) & (1 << RXCIE0)) &&
		(_SFR_MEM8(UART_UCSRxA(siopcb->reg)) & (1 << RXC0)))
	{
		return 1;
	}
	return 0;
}

/*
 *  SIO�h���C�o�̏�����
 */
void
sio_initialize(intptr_t exinf)
{
	int i;

	for (i = 0; i < TNUM_PORT; i++) {
		siopcb_table[i].port = i;
		siopcb_table[i].reg = sioreg_table[i];
		siopcb_table[i].exinf = 0;
	}
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB* siopcb;
	//ER		ercd;

	if (siopid > TNUM_PORT) {
		return NULL;
	}

	siopcb = GET_SIOPCB(siopid);
	siopcb->exinf = exinf;

	/* Disable receiver and transmitter */
	_SFR_MEM8(UART_UCSRxB(siopcb->reg)) = 0;
	/* Set baudrate parameter */
	_SFR_MEM16(UART_UBRRx(siopcb->reg)) = (SYS_CLOCK/16/BPS_SETTING-1);
	/* Set frame format: 8data, 1stop bit : 8N1 */
	_SFR_MEM8(UART_UCSRxC(siopcb->reg)) = (0 << USBS0) | (3 << UCSZ00);
	/* Enable receiver and transmitter */
	_SFR_MEM8(UART_UCSRxB(siopcb->reg)) = (1 << RXEN0) | (1 << TXEN0);

	return siopcb;
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	//ER		ercd;

	/* USART�̖����� */
	_SFR_MEM8(UART_UCSRxB(p_siopcb->reg)) = 0;
}

/*
 *  �����݃T�[�r�X���[�`��
 */
void
sio_isr_rx(intptr_t exinf)
{
	SIOPCB* siopcb = GET_SIOPCB(exinf);

	if (sio_getready(siopcb)) {
		sio_irdy_rcv(siopcb->exinf);
	}
}

void
sio_isr_tx(intptr_t exinf)
{
	SIOPCB* siopcb = GET_SIOPCB(exinf);

	if (sio_putready(siopcb)) {
		sio_irdy_snd(siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char c)
{
	if (sio_putready(siopcb)) {
		_SFR_MEM8(UART_UDRx(siopcb->reg)) = c;

		return true;
	}

	return false;
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
int_t
sio_rcv_chr(SIOPCB *siopcb)
{
	int_t c = -1;

	if (sio_getready(siopcb)) {
		c = _SFR_MEM8(UART_UDRx(siopcb->reg)) & 0xFF;
	}

	return c;
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		_SFR_MEM8(UART_UCSRxB(siopcb->reg)) |= (1 << UDRIE0);
		break;
	case SIO_RDY_RCV:
		_SFR_MEM8(UART_UCSRxB(siopcb->reg)) |= (1 << RXCIE0);
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		_SFR_MEM8(UART_UCSRxB(siopcb->reg)) &= ~(1 << UDRIE0);
		break;
	case SIO_RDY_RCV:
		_SFR_MEM8(UART_UCSRxB(siopcb->reg)) &= ~(1 << RXCIE0);
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
void
upd72001_irdy_snd(intptr_t exinf)
{
	sio_irdy_snd(exinf);
}

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
void
upd72001_irdy_rcv(intptr_t exinf)
{
	sio_irdy_rcv(exinf);
}

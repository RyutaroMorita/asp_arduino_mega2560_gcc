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
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *	2022/9/20 Ryutaro Morita
 */

/*
 *		シリアルI/Oデバイス（SIO）ドライバ（Arduino Mega2560用）
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_serial.h"

/*
 * レジスタ設定値
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 * USARTレジスタ定義
 */
#define UART_UCSRxA(x)		(x)
#define UART_UCSRxB(x)		(x + 0x01)
#define UART_UCSRxC(x)		(x + 0x02)
#define UART_UBRRx(x)		(x + 0x04)
#define UART_UDRx(x)		(x + 0x06)

/*
 *  シリアルポートの管理ブロック
 */
struct sio_port_control_block {
	ID port;
	uint8_t reg;
	intptr_t exinf;
};

/*
 * シリアルI/Oポート管理ブロックエリア
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
 *  SIOドライバの初期化
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
 *  シリアルI/Oポートのオープン
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
 *  シリアルI/Oポートのクローズ
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	//ER		ercd;

	/* USARTの無効化 */
	_SFR_MEM8(UART_UCSRxB(p_siopcb->reg)) = 0;
}

/*
 *  割込みサービスルーチン
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
 *  シリアルI/Oポートへの文字送信
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
 *  シリアルI/Oポートからの文字受信
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
 *  シリアルI/Oポートからのコールバックの許可
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
 *  シリアルI/Oポートからのコールバックの禁止
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
 *  シリアルI/Oポートからの送信可能コールバック
 */
void
upd72001_irdy_snd(intptr_t exinf)
{
	sio_irdy_snd(exinf);
}

/*
 *  シリアルI/Oポートからの受信通知コールバック
 */
void
upd72001_irdy_rcv(intptr_t exinf)
{
	sio_irdy_rcv(exinf);
}

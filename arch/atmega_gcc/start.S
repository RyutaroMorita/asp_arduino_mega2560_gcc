/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: start.S 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		カーネル対応のスタートアップモジュール（ATMega用）
 */
#include "macro.d"

#include <avr/io.h>

#define	TOPPERS_MACRO_ONLY
#include "kernel_impl.h"

	.text
	.globl start
start:
	/*
	 *  プロセッサモードとスタックポインタの初期化
	 */
	clr		r24
	out		_SFR_IO_ADDR(SREG),r24	/* status reg. */

	ldi		r24,lo8(RAMEND)			/* ;defined in system */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24	/* 1word */

    ; MCU control register (reset value is 0x00)
;	ldi	r24,0b00000000
		;;     |||||___ISC3-0: interrupt sense control
		;;     ||||
		;;     ||___SM2:0 sleep mode 000=idle mode
		;;     |_SE sleep enable
;	out	MCUCR,r24		;

	/*
	 * ウォッチドッグ・タイマーをリセット
	 */
	wdr
	; MCUSRレジスタのWDRFをクリア
	in		r24, _SFR_IO_ADDR(MCUSR)
	andi	r24, (0xff & (0<<WDRF))
	out		_SFR_IO_ADDR(MCUSR), r24
	; WDCEとWDEに1を書き込み
	; 意図しないタイムアウトが発生しないように，分周比の前回設定はそのままにする
	lds		r24, WDTCSR
	ori		r24, (1<<WDCE) | (1<<WDE)
	sts		WDTCSR, r24
	; WDTをオフにする
	ldi		r24, (0<<WDE)
	sts		WDTCSR, r24

	/*
	 *  hardware_init_hookの呼出し（0でない場合）
	 *
	 *  ターゲットハードウェアに依存して必要な初期化処理がある場合は，
	 *  hardware_init_hookという関数を用意する．
	 */
	ldi		ZL,lo8(gs(hardware_init_hook))
	ldi		ZH,hi8(gs(hardware_init_hook))
	tst		ZL
	brne	0f
	tst		ZH
	brne	0f
	rjmp	1f
0:
	icall
1:

	/*
	 *  dataセクションの初期化（ROM化対応）
	 *
	 *  _dloadを，_sdataから_edataまでコピーする．
	 */
	ldi		ZL,lo8(__idata_start)
	ldi		ZH,hi8(__idata_start)	/* Z:src in ROM */
	ldi		XL,lo8(__data_start)
	ldi		XH,hi8(__data_start)	/* X:dst in RAM */
	ldi		YL,lo8(__data_end)
	ldi		YH,hi8(__data_end)		/* (Y=data_end) */
	rjmp	3f
2:
	lpm		r0,Z+					/* (r0=*src++) */
	st		X+,r0					/* (*dst++=r0) */
    ;cnt==0 ? (cmp 16-bit)
3:
	cpse	XL,YL					/* compare then skip if equal */
	rjmp	2b
	cpse	XH,YH
	rjmp	2b

	/*
	 *  bssセクションのクリア
	 */
	ldi		XL,lo8(__bss_start)
	ldi		XH,hi8(__bss_start)		/* X:dst */
	ldi		ZL,lo8(__bss_end)
	ldi		ZH,hi8(__bss_end)		/* Z:addr of end */
	clr		r1						/* filled pattern */
	rjmp	5f
4:
	st		X+,r1					/* *dst++=r1 */
    ;reach at end ?
5:
	cpse	XL,ZL
	rjmp	4b
	cpse	XH,ZH					/* compare then skip if equal */
	rjmp	4b

	/*
	 *  software_init_hookの呼出し（0でない場合）
	 *
	 *  ソフトウェア環境（特にライブラリ）に依存して必要な初期化処理が
	 *  ある場合は，software_init_hookという関数を用意すればよい．
	 */
	ldi		ZL,lo8(gs(software_init_hook))
	ldi		ZH,hi8(gs(software_init_hook))
	tst		ZL
	brne	6f
	tst		ZH
	brne	6f
	rjmp	7f
6:
	icall
7:
;----- hardware initialization before EI
	clr		r1						/* r1 assumed as zero reg. */
;	sei								/* enable global interrupt */

	/*
	 *  カーネルを起動する．
	 */
	jmp sta_ker

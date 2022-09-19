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
 *  $Id: prc_support.S 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		プロセッサ依存モジュール アセンブリ言語部（ATMega用）
 */

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t型の定数を作るマクロ */
#define ULONG_C(val)		(val)		/* ulong_t型の定数を作るマクロ */
#define CAST(type, val)		(val)		/* 型キャストを行うマクロ */
#include "kernel_impl.h"
#include "offset.h"
#include <avr/io.h>

/*
 *  タスクディスパッチャ
 */
	.text
	.globl dispatch
dispatch:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 */
	in		r0,_SFR_IO_ADDR(SREG)		/* レジスタを保存 */
	push	r0
;
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
;
	push	r28		;Y-low
	push	r29		;  high

	lds		r24,p_runtsk+0
	lds		r25,p_runtsk+1
	movw	ZL,r24
	in		r24,_SFR_IO_ADDR(SPL)		/* タスクスタックを保存 */
	std		Z+TCB_sp+0,r24
	in		r24,_SFR_IO_ADDR(SPH)
	std		Z+TCB_sp+1,r24
	ldi		r24,lo8(gs(dispatch_r))		/* 実行再開番地を保存 */
	std		Z+TCB_pc+0,r24
	ldi		r24,hi8(gs(dispatch_r))
	std		Z+TCB_pc+1,r24
	rjmp	dispatcher

dispatch_r:
	pop		r29							/* レジスタを復帰 */
	pop		r28
;
	pop		r17
	pop		r16
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r7
	pop		r6
	pop		r5
	pop		r4
	pop		r3
	pop		r2
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0

	ldi		r24,TCB_enatex_bit			/* r25 = (1 << TCB_enatex_bit) */
	ldi		r25,1
0:
	lsl		r25
	dec		r24
	brne	0b

	lds		ZL,p_runtsk+0
	lds		ZH,p_runtsk+1
	ldd		r24,Z+TCB_enatex
	and		r24,r25
	breq	dispatch_r_1				/* enatexがfalseならリターン */

	ldd		r24,Z+TCB_texptn+0
	tst		r24
	brne	1f

	ldd		r24,Z+TCB_texptn+1
	tst		r24
	brne	1f

	rjmp	dispatch_r_1				/* texptnが0ならリターン */

1:
	lds		r24,ipmflg+0				/* ipmflgがtrueであれば            */
	tst		r24
	brne	2f

	lds		r24,ipmflg+1
	tst		r24
	brne	2f

	rjmp	dispatch_r_1

2:
	jmp		call_texrtn					/*  タスク例外処理ルーチンの呼出し */

dispatch_r_1:
	ret

/*
 *  ディスパッチャの動作開始（prc_support.S）
 */
	.globl start_dispatch
start_dispatch:
	/*
	 *  このルーチンは，カーネル起動時に，すべての割込みを禁止した状態
	 * （割込みロック状態と同等）で呼び出される．また，割込みモード（非
	 *  タスクコンテキストと同等）で呼び出されることを想定している．
	 *
	 *  prc_initializeで，lock_flagをtrueに，saved_iipmをIIPM_ENAALLに
	 *  初期化しているため，カーネル管理外の割込みを許可することで，
	 *  CPUロック状態・（モデル上の）割込み優先度マスク全解除状態になる．
	 *  また，initialize_taskでdisdspをfalseに初期化しているため，ディ
	 *  スパッチ許可状態になっている．
	 */
	clr		r1							/* マスタモードに */
	sts		int_cnt,r1
;	sei									/* カーネル管理外の割込みを許可 */
	rjmp	dispatcher_0

/*
 *  現在のコンテキストを捨ててディスパッチ
 */
	.globl exit_and_dispatch
exit_and_dispatch:
	/* ディスパッチャ本体（dispatcher）へ */

/*
 *  ディスパッチャ本体
 */
dispatcher:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 *
	 *  すなわち，マスタモード・lock_flagがtrue・disdspがfalse・dspflg
	 *  がtrue・saved_iipmがIIPM_ENAALLとなっている．実行再開番地へもこ
	 *  の状態のまま分岐する．
	 */
#ifdef LOG_DSP_ENTER
	lds		r24,p_runtsk+0				/* p_runtskをパラメータに */
	lds		r25,p_runtsk+1
	call	log_dsp_enter
#endif /* LOG_DSP_ENTER */

dispatcher_0:
	lds		r24,p_schedtsk+0			/* p_schedtskをp_runtskに */
	lds		r25,p_schedtsk+1
	sts		p_runtsk+0,r24
	sts		p_runtsk+1,r25
	tst		r24
	brne	0f

	tst		r25
	brne	0f

	rjmp	dispatcher_1				/* p_runtskがNULLならdispatcher_1へ */

0:
	movw	ZL,r24
	ldd		r24,Z+TCB_sp+0				/* タスクスタックを復帰 */
	out		_SFR_IO_ADDR(SPL),r24
	ldd		r24,Z+TCB_sp+1
	out		_SFR_IO_ADDR(SPH),r24

#ifdef LOG_DSP_LEAVE
	ldd		r24,Z+0						/* p_runtskをパラメータに */
	ldd		r25,Z+1
	push	r24
	push	r25
	call	log_dsp_leave

	pop		r25
	pop		r24
	std		Z+0,r24
	std		Z+1,r25
#endif

	ldd		r24,Z+TCB_pc+0				/* 実行再開番地へ分岐 */
	ldd		r25,Z+TCB_pc+1
	movw	XL,ZL
	movw	ZL,r24
	ijmp

dispatcher_1:
	/*
	 *  CPUロック状態を解除する準備をする．
	 */
	ldi		r24,1						/* 割込みモードに */
	sts		int_cnt+0,r24
	ldi		r24,lo8(RAMEND)				/* 割込み用のスタックへ切替え */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24
	in		r24,_SFR_IO_ADDR(SREG)		/* SREGをr24に保存 */
	clr		r1
	sts		lock_flag, r1				/* CPUロック解除状態に */

dispatcher_2:
	/*
	 *  割込みを許可し，割込みモードに切り換えて，割込みを待つ．
	 *
	 *  ここで割込みモードに切り換えるのは，ここで発生する割込み処理に
	 *  どのスタックを使うかという問題の解決と，割込みハンドラ内でのタ
	 *  スクディスパッチの防止という2つの意味がある．
	 *
	 *  プロセッサを割込み待ちに移行させる処理と，割込み許可とは，不可
	 *  分に行なう必要がある．これを不可分に行なわない場合，割込みを許
	 *  可した直後に割込みが入り，その中でタスクが実行可能状態になると
	 *  実行すべきタスクがあるにもかかわらずプロセッサが割込み待ちにな
	 *  ってしまう．
	 *
	 *  割込み待ちの間は，p_runtskをNULL（＝0）に設定しなければならな
	 *  い．このように設定しないと，割込みハンドラからiget_tidを呼び出
	 *  した際の動作が仕様に合致しなくなる．
	 */
	sei									/* 割込み待ち */
	nop
	cli
	out		_SFR_IO_ADDR(SREG),r24		/* 元の状態に戻す */
	lds		r25,reqflg
	tst		r25							/* reqflgがfalseならdispatcher_2へ */
	breq	dispatcher_2

	clr		r1
	sts		reqflg,r1					/* reqflgをfalseに */

	/*
	 *  CPUロック状態に戻す．割込み待ちの間に実行した割込みハンドラによ
	 *  り，saved_iipmが書き換えられる可能性があるため，元の値に戻す必
	 *  要がある．dispatcherが実行される時は，saved_iipmがIIPM_ENAALL
	 *  となっているため，ここではsaved_iipmをIIPM_ENAALL（＝0）に戻せ
	 *  ばよい．
	 */
	clr		r1							/* マスタモードに */
	sts		int_cnt+0,r1
	clr		r1							/* saved_iipmを0にする */
	sts		saved_iipm,r1
	ldi		r24,1
	sts		lock_flag,r24				/* CPUロック状態に */
	rjmp	dispatcher_0

/*
 *  カーネルの終了処理の呼出し
 */
	.globl call_exit_kernel
call_exit_kernel:
	ldi		r24,1						/* 割込みモードに */
	sts		int_cnt+0,r24
	ldi		r24,lo8(RAMEND)				/* 割込み用のスタックへ切替え */
	out		_SFR_IO_ADDR(SPL),r24
	ldi		r24,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r24
	jmp		exit_kernel					/* カーネルの終了処理を呼ぶ */

/*
 *
 *  タスク開始時処理
 *
 *  dispatcherから呼び出されるため，TCBのアドレスはXに入っている
 *
 */
	.text
	.globl start_r
start_r:
	clr		r1							/* CPUロック解除状態に */
	sts		lock_flag,r1
	sei									/* 割込み許可 */

	movw	ZL,XL
	ldd		r24,Z+TCB_p_tinib+0			/* p_runtsk->p_tinibをZに */
	ldd		r25,Z+TCB_p_tinib+1
	movw	ZL,r24
	ldd		r24,Z+TINIB_exinf+0			/* exinfをパラメータに積む */
	ldd		r25,Z+TINIB_exinf+1
	ldi		XL,lo8(gs(ext_tsk))			/* ext_tskをスタックに積む */
	ldi		XH,hi8(gs(ext_tsk))
	push	XL
	push	XH
	push	r1
	ldd		r22,Z+TINIB_task+0
	ldd		r23,Z+TINIB_task+1
	movw	ZL,r22
	ijmp

/*
 *  割込みエントリ
 */
	.global inthdr_entry
inthdr_entry:
	push	r1
	push	r0
	in		r0,_SFR_IO_ADDR(SREG)		/* スクラッチレジスタを保存 */
	push	r0
	clr		r1
;
	push	r18
	push	r19
	push	r20
	push	r21
	push	r22
	push	r23
;	push	r24
	push	r25
	push	r26		;X-low
	push	r27		;  high
;
	push	r30		;Z-low
	push	r31		;  high

	lds		r25,int_cnt+0
	inc 	r25							/* 割込みモードに */
	sts 	int_cnt+0,r25
	cpi		r25,1						/* 加算前が0でなければ多重割込み */
	brne	inthdr_entry_0_d

	in		r22,_SFR_IO_ADDR(SPL)		/* タスクスタックを保存 */
	sts		int_sp+0,r22
	in		r22,_SFR_IO_ADDR(SPH)
	sts		int_sp+1,r22
	ldi		r22,lo8(RAMEND)				/* 割込み用のスタックへ切替え */
	out		_SFR_IO_ADDR(SPL),r22
	ldi		r22,hi8(RAMEND)
	out		_SFR_IO_ADDR(SPH),r22
	rjmp	inthdr_entry_0

inthdr_entry_0_d:
	rjmp	inthdr_entry_0

inthdr_entry_0:
;	sei									/* 多重割り込み許可 */
										/* AVRでの多重割り込みは推奨されない！ */
	ldi		ZL,lo8(_kernel_exc_tbl)
	ldi		ZH,hi8(_kernel_exc_tbl)
	clr		r1
	add		ZL,r24
	adc		ZH,r1
	add		ZL,r24
	adc		ZH,r1

	ld		r22,Z+
	ld		r23,Z
	movw	ZL,r22
	push	r24							/* for Debug */
#ifdef LOG_INH_ENTER
	push	r30		;Z-low
	push	r31		;  high
	clr		r25
	call	log_inh_enter				/* log_exc_enterを呼び出す */

	pop		r31		;  high
	pop		r30		;Z-low

#endif /* LOG_EXC_ENTER */

	icall								/* Cルーチン呼び出し */

#ifdef LOG_INH_LEAVE
	pop		r24
	clr		r25							/* 例外番号を引数に        */
	call	log_inh_leave				/* log_exc_leaveを呼び出す */

	push	r24
#endif /* LOG_INH_LEAVE */

	sei
	nop

/*
 *  割込みハンドラ出口処理
 *
 *  ret_intは，割込みハンドラから戻った直後に実行するルーチンで，
 *  INTHDR_ENTRYマクロで展開する割込みハンドラの入口処理で，割込みハン
 *  ドラからの戻り番地に設定される．
 */
	.text
	.globl ret_int
ret_int:
	cli									/* 多重割り込み禁止 */
	pop		r24							/* for Debug */
	lds		r25,int_cnt
	dec		r25
	sts		int_cnt+0,r25
	tst		r25							/* 戻り先が割込みモードなら */
	brne	ret_int_1_d					/*           すぐにリターン */

	lds		r22,reqflg					/* reqflgがtrueであればret_int_2へ */
	tst		r22
	brne	ret_int_2

	lds		r22,int_sp+0
	out		_SFR_IO_ADDR(SPL),r22
	lds		r22,int_sp+1
	out		_SFR_IO_ADDR(SPH),r22

ret_int_1:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよう
	 *  準備する．割込み優先度マスクは，RTE命令により元の値に戻るため，
	 *  lock_flagをfalseにしておけばよい（lock_flagをfalseにするのは，
	 *  CPUロック状態のまま割込みハンドラから戻った時の対策）．
	 */
	clr		r1							/* CPUロック解除の準備 */
	sts		lock_flag,r1

	pop		r31							/* スクラッチレジスタを復帰 */
	pop		r30
;
	pop		r27
	pop		r26
	pop		r25
;	pop		r24
	pop		r23
	pop		r22
	pop		r21
	pop		r20
	pop		r19
	pop		r18
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0
	pop		r0
	pop		r1

	pop		r24

	reti

ret_int_1_d:
	rjmp	ret_int_1

ret_int_2:
	lds		r22,int_sp+0
	out		_SFR_IO_ADDR(SPL),r22
	lds		r22,int_sp+1
	out		_SFR_IO_ADDR(SPH),r22

ret_int_3:
	/*
	 *  ここへは，CPU例外ハンドラの出口処理からも分岐してくる．
	 *
	 *  ここでは，戻り先がタスクであり，スタックは，例外スタックフレー
	 *  ムの上にスクラッチレジスタのみが保存された状態になっている．ま
	 *  た，プロセッサは，マスタモード・カーネル管理の割込みを禁止した
	 *  状態となっている．
	 */
	clr		r1							/* reqflgをfalseに */
	sts		reqflg,r1

	/*
	 *  CPUロック状態に移行し，割込み優先度マスクを割込み処理前の値に設
	 *	定する．カーネル管理の割込みはすでに禁止しているので，lock_flag
	 *  とsaved_iipmを更新する．saved_iipmは，戻り先の割込み優先度マス
	 *  ク（の内部表現）に設定する．
	 *
	 *  この時点でCPUロック状態とするのは，dispatcherへ分岐する時と，
	 *  call_texrtnを呼び出す時に，CPUロック状態になっている必要がある
	 *  ためである．
	 */
	ldi		r24,1						/* lock_flagをtrueに */
	sts		lock_flag,r24

	/*
	 *  dspflgがfalseである場合と，p_runtskとp_schedtskが同じ場合には，
	 *  ディスパッチを行わない．このチェックが必要なのは，タスク例外処
	 *  理ルーチンの呼出しが必要な場合に，ディスパッチが必要なくても，
	 *  reqflgをtrueにするためである．
	 */
	lds		r24,p_runtsk+0
	lds		r25,p_runtsk+1
	movw	ZL,r24
	lds		r22,dspflg					/* dspflgがfalseならret_int_4へ */
	tst		r22
	breq	ret_int_4

	lds		r22,p_schedtsk+0			/* p_runtskとp_schedtskが同じなら */
	lds		r23,p_schedtsk+1
	cp		r22,r24
	brne	0f

	cp		r23,r25
	brne	0f

	movw	XL,ZL
	rjmp	ret_int_4					/*                    ret_int_4へ */

0:
	in		r0,_SFR_IO_ADDR(SREG)		/* 残りのレジスタを保存 */
	push	r0
;
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
;
	push	r28
	push	r29

	in		r24,_SFR_IO_ADDR(SPL)		/* タスクスタックを保存 */
	std		Z+TCB_sp+0,r24
	in		r24,_SFR_IO_ADDR(SPH)
	std		Z+TCB_sp+1,r24
	ldi		r24,lo8(gs(ret_int_r))		/* 実行再開番地を保存 */
	std		Z+TCB_pc+0,r24
	ldi		r24,hi8(gs(ret_int_r))
	std		Z+TCB_pc+1,r24

	rjmp	dispatcher

ret_int_r:
	pop		r29							/* レジスタを復帰 */
	pop		r28
;
	pop		r17
	pop		r16
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r7
	pop		r6
	pop		r5
	pop		r4
	pop		r3
	pop		r2
;
	pop		r0		;status reg.
	out		_SFR_IO_ADDR(SREG),r0

ret_int_4:
	/*
	 *  enatexがtrueで，texptnが0でなく，ipmflgがtrueであれば，タスク
	 *  例外処理ルーチンを呼び出す．
	 *  ret_int_3とdispatcherから呼び出されるため，TCBのアドレスはXに入っている
	 */
	movw	ZL,XL
	ldi		r24,TCB_enatex_bit
	ldi		r25,1
1:
	lsl		r25
	dec		r24
	brne	1b

	ldd		r24,Z+TCB_enatex
	and		r24,r25
	breq	ret_int_5					/* enatexがfalseならret_int_5へ */

	ldd		r24,Z+TCB_texptn
	tst		r24
	breq	ret_int_5					/* texptnが0ならret_int_5へ */

	call	call_texrtn					/* タスク例外処理ルーチンの呼出し */

ret_int_5:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよ
	 *  う準備する．割込み優先度マスクは，RTE命令により元の値に戻るた
	 *  め，lock_flagをfalseにしておけばよい．
	 */
	clr		r1							/* CPUロック解除の準備 */
	sts		lock_flag,r1

	pop		r31							/* スクラッチレジスタを復帰 */
	pop		r30
;
	pop		r27
	pop		r26
	pop		r25
;	pop		r24
	pop		r23
	pop		r22
	pop		r21
	pop		r20
	pop		r19
	pop		r18
;
	pop		r0
	out		_SFR_IO_ADDR(SREG),r0
	pop		r0
	pop		r1

	pop		r24

	reti

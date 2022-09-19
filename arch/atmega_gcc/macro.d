; ----------- macro definition --------------------------------------

.macro xexit
	rjmp	_exit
.endm
;
; used	Y,Ltmp,Lparm1
.macro sleepng, ticks
	ldi	Lparm1,ticks	;ticks
	rcall	_sleep		;(Lparm1=ticks)rtn Y=tcb
	rcall	schd		;(Y=tcb)jump to scheduler 
.endm
;
; timer 1
;  
.macro sleepTim1,channel
	ldi	Lparm1,channel	;'A' 'B'
	rcall	_sleepTim1	;(Lparm1=ch)rtn Y with tcb address
	rcall	schd		;jump to scheduler (Y=tcb)
.endm

.macro wait
	rcall	_wait		;rtn Y with tcb address
	rcall	schd		;jump to scheduler (Y=tcb)
.endm
;

; ----------- macro definition --------------------------------------
;
;wait for msg
;  waimsg MSGCODE
.macro waimsg,evntID
	rcall	mytcb		;() rtn/w Y=TCB
	ldi	Lparm1,evntID	;msg
	std	Y+tcbWAIT,Lparm1	;set wait flag
	rcall	_waimsg		;msg in tcbPARM
.endm
;
;send msg to target
;  sndmsg targetID, EVNTCODE, msgID
.macro sndmsgi,trgtID,evntID,msg
	ldi	YL,trgtID	;targetID
	rcall	gettcb		;(YL=trgtID) rtn/w Y=TCB
    ;set event info.
	ldd	Ltmp,Y+tcbEVNT	;get current EVNT code of target
	ori	Ltmp,evntID	;EVNT code
	std	Y+tcbEVNT,Ltmp	;write back
    ;set msg
	ldi	Ltmp,msg		;EVNT code
	std	Y+tcbPARM,Ltmp	;write back
    ;wake-up msg waiting task
	rcall	wakeMsg		;(Y=targetTCB)
	rcall	mytcb		;restore TCB here
.endm
;
;send msg to target
;  sndmsg targetID, EVNTCODE
;	msd in r0
.macro sndmsg,trgtID,evntID
	mov	Lparm1,r0
	ldi	YL,trgtID	;targetID
	rcall	gettcb		;(YL=trgtID) rtn/w Y=TCB
    ;set event info.
	ldd	Ltmp,Y+tcbEVNT	;get current EVNT code of target
	ori	Ltmp,evntID	;EVNT code
	std	Y+tcbEVNT,Ltmp	;write back
    ;set msg
;	ldi	Ltmp,msgID		;EVNT code
	std	Y+tcbPARM,Lparm1	;write back
    ;wake-up msg waiting task
	rcall	wakeMsg		;(Y=targetTCB)
	rcall	mytcb		;restore TCB here
.endm

; semaphore
.macro aquire,semID
;	__label__ success
	cli	;disable INT
	lds	Ltmp,sema0	;load from SRAM
	sbrc	Ltmp,semID	;skip if bit of reg. cleared
	rjmp	0f	;success
    ;resource unavailable, then goto sleep
	rcall	mytcb		;() rtn/w Y=TCB of myself
	ldi	Ltmp,semID
	std	Y+tcbPARM,Ltmp	;save semaphore ID
	ld	Ltmp,Y		;tcbSTATUS
	sbr	Ltmp,1<<SEMFLG
	cbr	Ltmp,1<<RDYFLG
	st	Y,Ltmp		;write back
	sei	;enable INT
	rcall	schd		;(Y=tcb)
;success:
0:
	cli	;disable INT
	lds	Ltmp,sema0
	cbr	Ltmp,1<<semID	;clear bits in reg.
	sts	sema0,Ltmp
	sei	;enable INT
.endm

.macro release,semID
	cli	;disable INT
	ldi	Lparm1,semID
	rcall	_semaphore	;(Uparm1=semaID)
	rcall	mytcb
	lds	Ltmp,sema0	;load from SRAM
	sbr	Ltmp,1<<semID	;set bits in reg.
	sts	sema0,Ltmp	;store to SRAM
	sei	;enable INT
.endm

.macro snd2LCD
	ldi	YL,taskLCD	;targetID
	rcall	gettcb		;(YL=trgtID) rtn/w Y=TCB
    ;set event info.
	ldd	Ltmp,Y+tcbEVNT	;get current EVNT code of target
	ori	Ltmp,MSGLCD	;EVNT code
	std	Y+tcbEVNT,Ltmp	;write back
    ;wake-up msg waiting task
	rcall	wakeMsg		;(Y=targetTCB)
	rcall	mytcb		;restore my TCB here
.endm

;
;wait for ADC completion
;
.macro waiadc
	rcall	mytcb		;() rtn/w Y=TCB
	rcall	_waiadc		;(Y=TCB)
.endm
	
;
; LCD
;
#define LCDPORT	PORTA
#define LCDDDR	DDRA
#define LCDPIN	PINA
;4bits interface (PB7-4 -> DB7-4)
MSKEXTDB=0b11110000	;mask to extract DB in LCD
MSKCLRDB=0b00001111	;mask to clear DB in LCD

bitE=3
bitRW=2
bitRS=1
	
.macro dataReg
	sbi	LCDPORT,bitRS	;set bit I/O
.endm

.macro cmdReg
	cbi	LCDPORT,bitRS	;clear bit I/O
.endm

.macro setE
	sbi	LCDPORT,bitE	;set bit I/O
.endm

.macro clrE
	cbi	LCDPORT,bitE	;clear bit I/O
.endm

.macro RDmode
	sbi	LCDPORT,bitRW	;set bit I/O
.endm

.macro WRmode
	cbi	LCDPORT,bitRW	;clear bit I/O
.endm

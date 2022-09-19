$
$ 		パス2のターゲット依存テンプレート（Arduino Mega2560用）
$

$
$  有効な割込み番号，割込みハンドラ番号
$
$INTNO_VALID = { 1,2,...,56 }$
$INHNO_VALID = INTNO_VALID$

$
$  ATT_ISRで使用できる割込み番号とそれに対応する割込みハンドラ番号
$
$INTNO_ATTISR_VALID = INTNO_VALID$
$INHNO_ATTISR_VALID = INHNO_VALID$

$
$  DEF_INT／DEF_EXCで使用できる割込みハンドラ番号／CPU例外ハンドラ番号
$
$INHNO_DEFINH_VALID = INHNO_VALID$

$
$  CFG_INTで使用できる割込み番号と割込み優先度
$
$INTNO_CFGINT_VALID = INTNO_VALID$
$INTPRI_CFGINT_VALID = { -7,-6,...,-1 }$

$
$  標準テンプレートファイルのインクルード
$
$INCLUDE "kernel/kernel.tf"$

/*$NL$
$SPC$*  Target-dependent Definitions (Arduino Mega2560)$NL$
$SPC$*/$NL$
$NL$

$
$   CFG_INTのターゲット依存のエラーチェックと_kernel_bitpat_cfgintの生成
$
$bitpat_cfgint = 0$
const uint32_t	_kernel_bitpat_cfgint = UINT32_C($FORMAT("0x%08x", bitpat_cfgint)$);
$NL$

$NL$

$FOREACH inhno INTNO_VALID$
extern void $FORMAT("_kernel_int_handler_%d(void);", +inhno)$$NL$
asm(".text \n\t"$NL$
$FORMAT("\"_kernel_int_handler_%d: \\n\\t\"", +inhno)$$NL$
"	push r24 \n\t"$NL$
$FORMAT("\"	ldi r24,%d \\n\\t\"", +inhno)$$NL$
"	jmp inthdr_entry \n\t");$NL$
$NL$
$END$

$NL$
FP _kernel_exc_tbl[] = $NL$
{$NL$
$TAB$(FP)0,$NL$
$FOREACH inhno INTNO_VALID$
	$IF LENGTH(INH.INHNO[inhno])$
		$TAB$(FP)($INH.INTHDR[inhno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_int_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
};$NL$

$NL$
asm(".section .vectors \n\t"$NL$
"jmp start \n\t"$NL$
$FOREACH inhno INTNO_VALID$
$FORMAT("\"jmp _kernel_int_handler_%d \\n\\t\"", +inhno)$$NL$
$END$
".section .text \n\t"$NL$
);$NL$


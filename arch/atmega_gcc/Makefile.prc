#
#		Makefileのプロセッサ依存部（ATMega用）
#

#
#  GNU開発環境のターゲットアーキテクチャの定義
#
GCC_TARGET = avr
CPU	= atmega2560
CSTANDARD = -std=gnu99

#
#  プロセッサ依存部ディレクトリ名の定義
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  コンパイルオプション
#
COPTS := $(COPTS) -mmcu=$(CPU) -D__atmega__ $(CSTANDARD)
#LDFLAGS := $(LDFLAGS) -mmcu=$(CPU) -cref,-u,Reset_Handler -nostartfiles
LDFLAGS := $(LDFLAGS)

#
#  カーネルに関する定義
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o

#
#  コンフィギュレータ関係の変数の定義
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  オフセットファイル生成のための定義
#
OFFSET_TF = $(PRCDIR)/prc_offset.tf

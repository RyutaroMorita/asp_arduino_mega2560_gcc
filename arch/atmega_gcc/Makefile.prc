#
#		Makefile�̃v���Z�b�T�ˑ����iATMega�p�j
#

#
#  GNU�J�����̃^�[�Q�b�g�A�[�L�e�N�`���̒�`
#
GCC_TARGET = avr
CPU	= atmega2560
CSTANDARD = -std=gnu99

#
#  �v���Z�b�T�ˑ����f�B���N�g�����̒�`
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  �R���p�C���I�v�V����
#
COPTS := $(COPTS) -mmcu=$(CPU) -D__atmega__ $(CSTANDARD)
#LDFLAGS := $(LDFLAGS) -mmcu=$(CPU) -cref,-u,Reset_Handler -nostartfiles
LDFLAGS := $(LDFLAGS)

#
#  �J�[�l���Ɋւ����`
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o

#
#  �R���t�B�M�����[�^�֌W�̕ϐ��̒�`
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  �I�t�Z�b�g�t�@�C�������̂��߂̒�`
#
OFFSET_TF = $(PRCDIR)/prc_offset.tf

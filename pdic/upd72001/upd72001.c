/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: upd72001.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		��PD72001�p �Ȉ�SIO�h���C�o
 */

#include <sil.h>
#include "target_syssvc.h"
#include "upd72001.h"

/*
 *  �f�o�C�X���W�X�^�̃A�N�Z�X�Ԋu���ԁinsec�P�ʁj
 *
 *  200�Ƃ����l�ɂ��܂荪���͂Ȃ��D
 */
#define	UPD72001_DELAY	200U

/*
 *  ��PD72001�̃��W�X�^�̔ԍ�
 */
#define	UPD72001_CR0	0x00U		/* �R���g���[�����W�X�^ */
#define	UPD72001_CR1	0x01U
#define	UPD72001_CR2	0x02U
#define	UPD72001_CR3	0x03U
#define	UPD72001_CR4	0x04U
#define	UPD72001_CR5	0x05U
#define	UPD72001_CR10	0x0aU
#define	UPD72001_CR12	0x0cU
#define	UPD72001_CR14	0x0eU
#define	UPD72001_CR15	0x0fU

#define	UPD72001_SR0	0x00U		/* �X�e�[�^�X���W�X�^ */

/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
#define CR_RESET	0x18U		/* �|�[�g���Z�b�g�R�}���h */

#define CR0_EOI		0x38U		/* EOI�iEnd of Interrupt�j*/

#define CR1_DOWN	0x00U		/* �S�����݂��֎~ */
#define CR1_RECV	0x10U		/* ��M�����݋��r�b�g */
#define CR1_SEND	0x02U		/* ���M�����݋��r�b�g */

#define CR3_DEF		0xc1U		/* �f�[�^ 8bit�C��M�C�l�[�u�� */
#define CR4_DEF		0x44U		/* �X�g�b�v�r�b�g 1bit�C�p���e�B�Ȃ� */
#define CR5_DEF		0xeaU		/* �f�[�^ 8bit�C���M�C�l�[�u�� */

#define CR10_DEF	0x00U		/* NRZ */
#define CR14_DEF	0x07U		/* �{�[���[�g�W�F�l���[�^�C�l�[�u�� */
#define CR15_DEF	0x56U		/* �{�[���[�g�W�F�l���[�^�g�p */

#define SR0_RECV	0x01U		/* ��M�ʒm�r�b�g */
#define SR0_SEND	0x04U		/* ���M�\�r�b�g */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	void		*data;			/* �f�[�^���W�X�^�̔Ԓn */
	void		*ctrl;			/* �R���g���[�����W�X�^�̔Ԓn */

	uint8_t		cr3_def;		/* CR3�̐ݒ�l�i��M�r�b�g���j*/
	uint8_t		cr4_def;		/* CR4�̐ݒ�l�i�X�g�b�v�r�b�g�C�p���e�B�j*/
	uint8_t		cr5_def;		/* CR5�̐ݒ�l�i���M�r�b�g���j*/
	uint8_t		brg1_def;		/* �{�[���[�g��ʂ̐ݒ�l */
	uint8_t		brg2_def;		/* �{�[���[�g���ʂ̐ݒ�l */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
struct sio_port_control_block {
	const SIOPINIB *p_siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	intptr_t	exinf;			/* �g����� */
	bool_t		openflag;		/* �I�[�v���ς݃t���O */
	uint8_t		cr1;			/* CR1�̐ݒ�l�i�����݋��j*/
	bool_t		getready;		/* ��������M������� */
	bool_t		putready;		/* �����𑗐M�ł����� */
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (void *) TADR_UPD72001_DATAA, (void *) TADR_UPD72001_CTRLA,
					CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF },
	{ (void *) TADR_UPD72001_DATAB, (void *) TADR_UPD72001_CTRLB,
					CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF }
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  �f�o�C�X���W�X�^�ւ̃A�N�Z�X�֐�
 */
Inline uint8_t
upd72001_read_reg(void *addr)
{
	uint8_t	val;

	val = upd72001_reb_reg(addr);
	sil_dly_nse(UPD72001_DELAY);
	return(val);
}

Inline void
upd72001_write_reg(void *addr, uint8_t val)
{
	upd72001_wrb_reg(addr, val);
	sil_dly_nse(UPD72001_DELAY);
}

Inline uint8_t
upd72001_read_ctrl(void *addr, uint8_t reg)
{
	upd72001_write_reg(addr, reg);
	return(upd72001_read_reg(addr));
}

Inline void
upd72001_write_ctrl(void *addr, uint8_t reg, uint8_t val)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
}

Inline void
upd72001_write_brg(void *addr, uint8_t reg, uint8_t val,
									uint8_t brg2, uint8_t brg1)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
	upd72001_write_reg(addr, brg2);
	upd72001_write_reg(addr, brg1);
	(void) upd72001_read_reg(addr);		/* �_�~�[���[�h */
}

/*
 *  ��Ԃ̓Ǐo���iSR0�̓Ǐo���j
 *
 *  ��PD72001�́C��ԁiSR0�j����x�ǂނƎ�M�ʒm�r�b�g�������Ă��܂���
 *  �߁C��Ԃ�ǂݏo���֐���݂��C�V���A��I/O�|�[�g�Ǘ��u���b�N����
 *  getready�Ɏ�M�ʒm��ԁCputready�ɑ��M�\��Ԃ�ۑ����Ă���i���M
 *  �\��Ԃ̕ۑ��͕s�v��������Ȃ��j�D
 *  ��ԃ��W�X�^��ǂ�ł���M�ʒm�r�b�g�������Ȃ��f�o�C�X�i�����炪��
 *  �ʂƎv����j�ł́C���̊֐��͕K�v�Ȃ��D
 */
static void
upd72001_get_stat(SIOPCB *p_siopcb)
{
	uint8_t	sr0;

	sr0 = upd72001_read_ctrl(p_siopcb->p_siopinib->ctrl, UPD72001_SR0);
	if ((sr0 & SR0_RECV) != 0) {
		p_siopcb->getready = true;
	}
	if ((sr0 & SR0_SEND) != 0) {
		p_siopcb->putready = true;
	}
}

/*
 *  ��������M�ł��邩�H
 */
Inline bool_t
upd72001_getready(SIOPCB *p_siopcb)
{
	upd72001_get_stat(p_siopcb);
	return(p_siopcb->getready);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline bool_t
upd72001_putready(SIOPCB *p_siopcb)
{
	upd72001_get_stat(p_siopcb);
	return(p_siopcb->putready);
}

/*
 *  ��M���������̎�o��
 */
Inline char
upd72001_getchar(SIOPCB *p_siopcb)
{
	p_siopcb->getready = false;
	return((char) upd72001_read_reg(p_siopcb->p_siopinib->data));
}

/*
 *  ���M���镶���̏�����
 */
Inline void
upd72001_putchar(SIOPCB *p_siopcb, char c)
{
	p_siopcb->putready = false;
	upd72001_write_reg(p_siopcb->p_siopinib->data, (uint8_t) c);
}

/*
 *  EOI�iEnd Of Interrupt�j���s
 */
Inline void
upd72001_eoi(void)
{
	upd72001_write_ctrl((void *) TADR_UPD72001_CTRLA, UPD72001_CR0, CR0_EOI);
}

/*
 *  SIO�h���C�o�̏�����
 */
void
upd72001_initialize(void)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (i = 0; i < TNUM_SIOP; i++) {
		p_siopcb = &(siopcb_table[i]);
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->openflag = false;
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
bool_t
upd72001_openflag(void)
{
	return(siopcb_table[0].openflag || siopcb_table[1].openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
upd72001_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB		*p_siopcb;
	const SIOPINIB	*p_siopinib;

	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;

	upd72001_write_reg(p_siopinib->ctrl, CR_RESET);
	if (!upd72001_openflag()) {
		upd72001_write_ctrl((void *) TADR_UPD72001_CTRLA, UPD72001_CR2, 0x18);
		upd72001_write_ctrl((void *) TADR_UPD72001_CTRLB, UPD72001_CR2, 0x00);
	}
	p_siopcb->cr1 = CR1_DOWN;
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR1, p_siopcb->cr1);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR4, p_siopinib->cr4_def);
	upd72001_write_brg(p_siopinib->ctrl, UPD72001_CR12, 0x01U,
							p_siopinib->brg2_def, p_siopinib->brg1_def);
	upd72001_write_brg(p_siopinib->ctrl, UPD72001_CR12, 0x02U,
							p_siopinib->brg2_def, p_siopinib->brg1_def);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR15, CR15_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR14, CR14_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR10, CR10_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR3, p_siopinib->cr3_def);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR5, p_siopinib->cr5_def);
	p_siopcb->exinf = exinf;
	p_siopcb->getready = false;
	p_siopcb->putready = false;
	p_siopcb->openflag = true;
	return(p_siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
upd72001_cls_por(SIOPCB *p_siopcb)
{
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl, UPD72001_CR1, CR1_DOWN);
	p_siopcb->openflag = false;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
bool_t
upd72001_snd_chr(SIOPCB *p_siopcb, char c)
{
	if (upd72001_putready(p_siopcb)) {
		upd72001_putchar(p_siopcb, c);
		return(true);
	}
	return(false);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
int_t
upd72001_rcv_chr(SIOPCB *p_siopcb)
{
	if (upd72001_getready(p_siopcb)) {
		return((int_t)(uint8_t) upd72001_getchar(p_siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
upd72001_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint8_t	cr1_bit;

	switch (cbrtn) {
	case SIO_RDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_RDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	default:
		cr1_bit = 0U;
		break;
	}
	p_siopcb->cr1 |= cr1_bit;
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl,
									UPD72001_CR1, p_siopcb->cr1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
upd72001_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint8_t	cr1_bit;

	switch (cbrtn) {
	case SIO_RDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_RDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	default:
		cr1_bit = 0U;
		break;
	}
	p_siopcb->cr1 &= ~cr1_bit;
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl,
									UPD72001_CR1, p_siopcb->cr1);
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
upd72001_isr_siop(SIOPCB *p_siopcb)
{
	if ((p_siopcb->cr1 & CR1_RECV) != 0U) {
		if (upd72001_getready(p_siopcb)) {
			/*
			 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
			 */
			upd72001_irdy_rcv(p_siopcb->exinf);
		}
	}
	if ((p_siopcb->cr1 & CR1_SEND) != 0U) {
		if (upd72001_putready(p_siopcb)) {
			/*
			 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
			 */
			upd72001_irdy_snd(p_siopcb->exinf);
		}
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
upd72001_isr(void)
{
	if (siopcb_table[0].openflag) {
		upd72001_isr_siop(&(siopcb_table[0]));
	}
	if (siopcb_table[1].openflag) {
		upd72001_isr_siop(&(siopcb_table[1]));
	}
	upd72001_eoi();
}

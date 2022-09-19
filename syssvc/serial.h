/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: serial.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�V���A���C���^�t�F�[�X�h���C�o
 */

#ifndef TOPPERS_SERIAL_H
#define TOPPERS_SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̗p����p�P�b�g
 */
typedef struct {
	uint_t		reacnt;			/* ��M�o�b�t�@���̕����� */
	uint_t		wricnt;			/* ���M�o�b�t�@���̕����� */
} T_SERIAL_RPOR;

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̏��������[�`��
 */
extern void		serial_initialize(intptr_t exinf) throw();

/*
 *  �V���A���C���^�t�F�[�X�h���C�o����̖����M�����̎�o��
 */
extern bool_t	serial_get_chr(ID portid, char *p_c) throw();

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̃T�[�r�X�R�[��
 */
extern ER		serial_opn_por(ID portid) throw();
extern ER		serial_cls_por(ID portid) throw();
extern ER_UINT	serial_rea_dat(ID portid, char *buf, uint_t len) throw();
extern ER_UINT	serial_wri_dat(ID portid, const char *buf, uint_t len) throw();
extern ER		serial_ctl_por(ID portid, uint_t ioctl) throw();
extern ER		serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor) throw();

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̓��쐧��p�̂��߂̒萔
 *
 *  �ȉ��̒萔�́C�r�b�g���ɘ_���a���Ƃ��ėp����D
 */
#define	IOCTL_NULL	0U			/* �w��Ȃ� */
#define	IOCTL_ECHO	0x0001U		/* ��M�����������G�R�[�o�b�N */
#define	IOCTL_CRLF	0x0010U		/* LF�𑗐M����O��CR��t�� */
#define	IOCTL_FCSND	0x0100U		/* ���M�ɑ΂��ăt���[������s�� */
#define	IOCTL_FCANY	0x0200U		/* �ǂ̂悤�ȕ����ł����M�ĊJ */
#define	IOCTL_FCRCV	0x0400U		/* ��M�ɑ΂��ăt���[������s�� */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_SERIAL_H */

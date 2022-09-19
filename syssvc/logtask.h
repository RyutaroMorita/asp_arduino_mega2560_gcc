/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: logtask.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�V�X�e�����O�^�X�N
 */

#ifndef TOPPERS_LOGTASK_H
#define TOPPERS_LOGTASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "target_syssvc.h"

/*
 *  �V�X�e�����O�^�X�N�֘A�̒萔�̃f�t�H���g�l�̒�`
 */ 
#ifndef LOGTASK_PRIORITY
#define LOGTASK_PRIORITY	3		/* �����D��x */
#endif /* LOGTASK_PRIORITY */

#ifndef LOGTASK_STACK_SIZE
#define LOGTASK_STACK_SIZE	1024	/* �X�^�b�N�̈�̃T�C�Y */
#endif /* LOGTASK_STACK_SIZE */

#ifndef LOGTASK_PORTID
#define LOGTASK_PORTID		1		/* �V�X�e�����O�p�̃V���A���|�[�g�ԍ� */
#endif /* LOGTASK_PORTID */

#ifndef LOGTASK_INTERVAL
#define LOGTASK_INTERVAL	10U		/* �V�X�e�����O�^�X�N�̓���Ԋu�i�~���b�j*/
#endif /* LOGTASK_INTERVAL */

#ifndef LOGTASK_FLUSH_WAIT
#define LOGTASK_FLUSH_WAIT	1U		/* �t���b�V���҂��̒P�ʎ��ԁi�~���b�j*/
#endif /* LOGTASK_FLUSH_WAIT */

/*
 *  �V�X�e�����O�o�͂̑҂����킹
 *
 *  ���O�o�b�t�@���̃��O�̐���count�ȉ��ɂȂ�܂ő҂Dcount��0�̏ꍇ��
 *  �́C�V���A���o�b�t�@����ɂȂ�̂��҂D
 */
extern ER	logtask_flush(uint_t count) throw();

/*
 *  �V�X�e�����O�^�X�N�̖{��
 */
extern void	logtask_main(intptr_t exinf) throw();

/*
 *  �V�X�e�����O�^�X�N�̏I������
 */
extern void	logtask_terminate(intptr_t exinf) throw();

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_LOGTASK_H */

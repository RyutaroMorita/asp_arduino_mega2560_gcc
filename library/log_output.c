/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
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
 *  @(#) $Id: log_output.c 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		�V�X�e�����O�̃t�H�[�}�b�g�o��
 */

#include <t_stddef.h>
#include <t_syslog.h>
#include <log_output.h>

/*
 *  ���l�𕶎���ɕϊ�
 */
#define CONVERT_BUFLEN	((sizeof(uintptr_t) * CHAR_BIT + 2) / 3)
										/* uintptr_t�^�̐��l�̍ő啶���� */
static void
convert(uintptr_t val, uint_t radix, const char *radchar,
			uint_t width, bool_t minus, bool_t padzero, void (*putc)(char))
{
	char	buf[CONVERT_BUFLEN];
	uint_t	i, j;

	i = 0U;
	do {
		buf[i++] = radchar[val % radix];
		val /= radix;
	} while (i < CONVERT_BUFLEN && val != 0);

	if (minus && width > 0) {
		width -= 1;
	}
	if (minus && padzero) {
		(*putc)('-');
	}
	for (j = i; j < width; j++) {
		(*putc)(padzero ? '0' : ' ');
	}
	if (minus && !padzero) {
		(*putc)('-');
	}
	while (i > 0U) {
		(*putc)(buf[--i]);
	}
}

/*
 *  �����񐮌`�o��
 */
static const char raddec[] = "0123456789";
static const char radhex[] = "0123456789abcdef";
static const char radHEX[] = "0123456789ABCDEF";

void
syslog_printf(const char *format, const intptr_t *p_args, void (*putc)(char))
{
	char		c;
	uint_t		width;
	bool_t		padzero;
	intptr_t	val;
	const char	*str;

	while ((c = *format++) != '\0') {
		if (c != '%') {
			(*putc)(c);
			continue;
		}

		width = 0U;
		padzero = false;
		if ((c = *format++) == '0') {
			padzero = true;
			c = *format++;
		}
		while ('0' <= c && c <= '9') {
			width = width * 10U + c - '0';
			c = *format++;
		}
		if (c == 'l') {
			c = *format++;
		}
		switch (c) {
		case 'd':
			val = (intptr_t)(*p_args++);
			if (val >= 0) {
				convert((uintptr_t) val, 10U, raddec,
										width, false, padzero, putc);
			}
			else {
				convert((uintptr_t)(-val), 10U, raddec,
										width, true, padzero, putc);
			}
			break;
		case 'u':
			val = (intptr_t)(*p_args++);
			convert((uintptr_t) val, 10U, raddec, width, false, padzero, putc);
			break;
		case 'x':
		case 'p':
			val = (intptr_t)(*p_args++);
			convert((uintptr_t) val, 16U, radhex, width, false, padzero, putc);
			break;
		case 'X':
			val = (intptr_t)(*p_args++);
			convert((uintptr_t) val, 16U, radHEX, width, false, padzero, putc);
			break;
		case 'c':
			(*putc)((char)(intptr_t)(*p_args++));
			break;
		case 's':
			str = (const char *)(*p_args++);
			while ((c = *str++) != '\0') {
				(*putc)(c);
			}
			break;
		case '%':
			(*putc)('%');
			break;
		case '\0':
			format--;
			break;
		default:
			break;
		}
	}
}

/*
 *  ���O���̏o��
 */
void
syslog_print(const SYSLOG *p_syslog, void (*putc)(char))
{
	switch (p_syslog->logtype) {
	case LOG_TYPE_COMMENT:
		syslog_printf((const char *)(p_syslog->loginfo[0]),
								&(p_syslog->loginfo[1]), putc);
		break;
	case LOG_TYPE_ASSERT:
		syslog_printf("%s:%u: Assertion `%s' failed.",
								&(p_syslog->loginfo[0]), putc);
		break;
	default:
		/*
		 *  ���̎�ʂ̃��O���ɂ͑Ή����Ă��Ȃ��D
		 */
		break;
	}
}

/*
 *  ���O���r�����b�Z�[�W�̏o��
 */
void
syslog_lostmsg(uint_t lostlog, void (*putc)(char))
{
	intptr_t	lostinfo[1];

	lostinfo[0] = (intptr_t) lostlog;
	syslog_printf("%d messages are lost.", lostinfo, putc);
	(*putc)('\n');
}

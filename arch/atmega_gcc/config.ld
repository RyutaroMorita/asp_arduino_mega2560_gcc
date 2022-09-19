/*
 *  @(#) $Id: m68kelf.ld 127 2007-06-19 07:23:10Z hiro $
 */

/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-avr","elf32-avr","elf32-avr")
OUTPUT_ARCH(avr:6)
STARTUP(start.o)

MEMORY
{
  ROM (rx)      : ORIGIN = 0x000000, LENGTH = 256K
  RAM (rw!x)    : ORIGIN = 0x800200, LENGTH = 16K
  EEPROM (rw!x) : ORIGIN = 0x810000, LENGTH = 1K
}

PROVIDE(hardware_init_hook = 0);
PROVIDE(software_init_hook = 0);
PROVIDE(software_term_hook = 0);

SECTIONS
{
	.text :
	{
		*(.vectors)
		KEEP(*(.vectors))

		*(.progmem.*)
		. = ALIGN(2);

		__trampolines_start = . ;
		/* The jump trampolines for the 16-bit limited relocs will reside here.  */
		*(.trampolines)
		*(.trampolines*)
		__trampolines_end = . ;

		*(.text)
		*(.text.*)			/* .text.libgcc */
		__ctors_start = . ;
		*(.ctors)
		__ctors_end = . ;
		__dtors_start = . ;
		*(.dtors)
		__dtors_end = . ;
		_etext = . ;
	}  > ROM

	__idata_start = .;
	.data : AT (__idata_start)
	{
		__data_start = .;
		/* *(.rodata) */
		/* *(.rodata.*) */
		*(.data)
		*(.data*)
		__data_end = .;
	}  > RAM
	__idata_end = __idata_start + SIZEOF(.data);

	.bss :
	{
		__bss_start  = .;
		*(.bss)
		*(.bss*)
		*(COMMON)
	}  > RAM
	__bss_end = .;
}

ENTRY(reset)

MEMORY
{
	Mem (rwx):ORIGIN = 0x00000000 , LENGTH = 64M	
}

SECTIONS{
	. = 0x10000;
	.bolis_startup . :
	{
		 startup.o(.text)
	}> Mem

	.bolis_text_rodata :
	{
		*(.text) *(.rodata)
	}> Mem
	
	.bolis_data :
	{
		*(.data)
	}> Mem

	.bolis_bss :
	{
		*(.bss)
	}> Mem

	. = . + 0x1000;
	stack_top = . ;
}
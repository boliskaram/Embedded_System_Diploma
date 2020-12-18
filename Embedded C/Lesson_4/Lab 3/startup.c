// Bolis Karam

#include <stdint.h>

void Reset_handler(void);
extern int main(void);
extern unsigned int _stack_top;
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Default_Handler()
{
	Reset_handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void H_Fault_handler(void) __attribute__((weak,alias("Default_Handler")));

static unsigned long Stack_top[256];

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = 
{
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_handler,
	&NMI_Handler,
	&H_Fault_handler
};


void Reset_handler(void)
{
	// copy data sectio from FLASH to RAM
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_data;
	for (int i = 0; i < data_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}

	// init bss sectio in sram with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for (int i = 0; i < bss_size; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}

	// jump to main
	main();
}
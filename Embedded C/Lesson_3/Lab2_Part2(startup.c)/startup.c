// Bolis Karam

#include <stdint.h>
void Reset_handler(void);
extern int main(void);
extern unsigned int _stack_top;
void Default_Handler()
{
	Reset_handler();
}
void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void H_Fault_handler(void) __attribute__((weak,alias("Default_Handler")));
void MM_Fault_handler(void) __attribute__((weak,alias("Default_Handler")));
void Bus_Fault_handler(void) __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_handler(void) __attribute__((weak,alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_handler,
	(uint32_t) &MM_Fault_handler,
	(uint32_t) &Bus_Fault_handler,
	(uint32_t) &Usage_Fault_handler,
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

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
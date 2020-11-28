#include "Uart.h"
unsigned char const string_name2[100]="Bolis Karam Soliman";
unsigned char string_name[100]="Bolis Karam Soliman";
void main()
{
	UART_Send_String(string_name);
}

 
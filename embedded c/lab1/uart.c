#include "uart.h"
#define UART0DR  *((volatile unsigned int *)(0x101f1000))
void uart_send_string(unsigned char* p_tx_String)
{
	while(*p_tx_String != '\0')
	{
		UART0DR=(unsigned int)(*p_tx_String);
		p_tx_String++;
	}
}
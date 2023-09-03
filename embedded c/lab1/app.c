#include "uart.h"

unsigned char string_buffer[100]="Learn_In_Depth:salah_ali";
unsigned char const string_buffer2[100]="Learn_In_Depth:salah_ali";
void main(void)
{
	uart_send_string(string_buffer);
}

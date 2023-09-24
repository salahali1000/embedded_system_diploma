#include "LCD.h"
#include "KEYPAD.h"

void delay_ms(uint32_t time) ;
int main(void)
{
	uint8_t read = 0;
	RCC_GPIOA_CLK_EN() ;
	RCC_GPIOB_CLK_EN() ;
	LCD_INIT() ;
	KEYPAD_VINIT() ;


	while(1)
	{		do
		{
			read = KEYPAD_VREAD() ;
		}while(read ==NOT_PRESSED);
		LCD_WRITE_CHAR(read) ;
		delay_ms(100);

	}

}

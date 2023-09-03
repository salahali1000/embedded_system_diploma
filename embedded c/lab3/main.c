/**
 ******************************************************************************
 * @file           : main.c
 * @author         : eng salah ali
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * eng salah ali
 *
 ******************************************************************************
 */
#define SYSCTL_RCGC2_R        *((volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DIR_R      *((volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R      *((volatile unsigned long*)(0x4002551c))
#define GPIO_PORTF_DATA_R     *((volatile unsigned long*)(0x400253fc))


int main()
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20 ;
	// delay to make sure the GPIOF is up and running
	for(delay_count = 0 ; delay_count < 200 ; delay_count++ );
	GPIO_PORTF_DIR_R |= (1<<3); //DIR is output (pin 3 PORT F)
	GPIO_PORTF_DEN_R |= (1<<3); //enabe pin 3 PORT F
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3) ;
		for(delay_count = 0 ; delay_count < 200000 ; delay_count++ );
		GPIO_PORTF_DATA_R &= ~(1<<3) ;
		for(delay_count = 0 ; delay_count < 200000 ; delay_count++ );
	}
	
	return 0;
}

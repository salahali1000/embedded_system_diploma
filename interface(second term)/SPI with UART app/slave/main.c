/**
 ******************************************************************************
 * @file           : main.c
 * @author         : eng salah ali
 */

#include "SPI.h"
#include "UART.h"

//#define SPI_Act_As_Master
#define SPI_Act_As_Slave

uint8_t ch ;

void SPI_CallBack(struct S_IRQ_SRC irq_src)
{
#ifdef SPI_Act_As_Slave
	if(irq_src.RXNE)
	{
		ch = 0xf ;
		MCAL_SPI_TX_RX(SPI1, &ch , disable_SPI) ;
		MCAL_UART_SendData(USART1, &ch, enable) ;
	}
#endif
}

void UART_Handler(void)
{
#ifdef SPI_Act_As_Master
	MCAL_UART_ReceiveData(USART1, (uint16_t*)&ch , disable) ;
	MCAL_UART_SendData(USART1, (uint16_t*) &ch, enable) ;
	//Send to SPI
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET) ;
	MCAL_SPI_TX_RX(SPI1,  (uint16_t*) &ch, enable_SPI) ;
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET) ;
#endif
}
int main(void)
{
	GPIO_PinConfig_t GPIO_Config ;
	RCC_GPIOA_CLK_EN() ;
	RCC_GPIOB_CLK_EN() ;
	RCC_AFIO_CLK_EN() ;
	//UART Configuration
	UART_Config_t Uart_Config ;
	Uart_Config.BaudRte = UART_BaudRate_115200 ;
	Uart_Config.HWFlowCTL = UART_FlowCTL_NONE ;
	Uart_Config.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	Uart_Config.LoadLength = UART_LoadLength_8B ;
	Uart_Config.P_IRQ_CallBack = UART_Handler ;
	Uart_Config.StopBits = UART_StopBits_1 ;
	Uart_Config.USART_mode = UART_Mode_TX_RX ;
	Uart_Config.parity = UART_Parity_NONE ;
	MCAL_UART_Init(USART1, &Uart_Config) ;
	MCAL_UART_GPIO_Set_Pins(USART1) ;

	//SPI Configuration

	//Common configuration
	SPI_Config_t Spi_Config ;
	Spi_Config.CLKPhase = SPI_CLKPhase_2EDGE_FIRST ;
	Spi_Config.CLKPolarity = SPI_CLKPolarity_IDLE1 ;
	Spi_Config.Data_Size = SPI_DataSize_8B ;
	Spi_Config.Frame_Format = SPI_Frame_Format_MSB_FIRST ;
	//Assume the pclk2 = 8MHZ (default)
	Spi_Config.BaudRate_Scaler = SPI_BaudRate_Scaler_8 ;
	Spi_Config.Communication_Mode = SPI_DIRECTION_2LINES ;

#ifdef SPI_Act_As_Master
	Spi_Config.Device_Mode = SPI_Device_Mode_Master ;
	Spi_Config.IRQ_Enable = SPI_IRQ_Enable_NONE ;
	Spi_Config.NSS = SPI_NSS_Soft_Set ;
	Spi_Config.P_IRQ_CallBack = NULL ;
	//configure SS on GPIO PORT A PIN 4
		GPIO_Config.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
		GPIO_Config.GPIO_Output_Speed = GPIO_SPEED_10M ;
		GPIO_Config.GPIO_PinNumber = GPIO_PIN_4 ;
		MCAL_GPIO_Init(GPIOA, &GPIO_Config) ;

		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET) ;
#endif

#ifdef SPI_Act_As_Slave
	Spi_Config.Device_Mode = SPI_Device_Mode_Slave ;
	Spi_Config.IRQ_Enable = SPI_IRQ_Enable_RXNEIE ;
	Spi_Config.NSS = SPI_NSS_Hard_Slave ;
	Spi_Config.P_IRQ_CallBack = SPI_CallBack ;

#endif
	MCAL_SPI_Init(SPI1, &Spi_Config) ;
	MCAL_SPI_GPIO_Set_Pins(SPI1) ;



	while(1)
	{

	}
}

#include "SWM201.h"

void SerialInit(void);

int main(void)
{
	uint16_t mul1, mul2;
	uint16_t dividend, divisor;
	
	SystemInit();
	
	SerialInit();
   	
	CORDIC_Init(CORDIC);
	
	CORDIC_Init(CORDIC);
	
	mul1 = 1.25 * 16384;
	mul2 = 1.25 * 16384;
	CORDIC_Mul(mul1, mul2);
	while(CORDIC_Mul_IsDone() == 0) __NOP();
	printf("1.25 * 1.25 = %f\r\n", CORDIC_Mul_Result()/16384.0);
	
	dividend = 1.25 * 16384;
	divisor  = 0.6  * 16384;
	CORDIC_Div(dividend, divisor);
	while(CORDIC_Div_IsDone() == 0) __NOP();
	printf("1.25 / 0.6 = %f\r\n", CORDIC_Div_Result()/16384.0);
	
	while(1==1)
	{
	}
}

void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTA, PIN0, PORTA_PIN0_UART0_RX, 1);	//GPIOA.0配置为UART0 RXD
	PORT_Init(PORTA, PIN1, PORTA_PIN1_UART0_TX, 0);	//GPIOA.1配置为UART0 TXD
 	
 	UART_initStruct.Baudrate = 57600;
	UART_initStruct.DataBits = UART_DATA_8BIT;
	UART_initStruct.Parity = UART_PARITY_NONE;
	UART_initStruct.StopBits = UART_STOP_1BIT;
	UART_initStruct.RXThreshold = 3;
	UART_initStruct.RXThresholdIEn = 0;
	UART_initStruct.TXThreshold = 3;
	UART_initStruct.TXThresholdIEn = 0;
	UART_initStruct.TimeoutTime = 10;
	UART_initStruct.TimeoutIEn = 0;
 	UART_Init(UART0, &UART_initStruct);
	UART_Open(UART0);
}

/****************************************************************************************************************************************** 
* 函数名称: fputc()
* 功能说明: printf()使用此函数完成实际的串口打印动作
* 输    入: int ch		要打印的字符
*			FILE *f		文件句柄
* 输    出: 无
* 注意事项: 无
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}

#include "SWM201.h"


RTC_AlarmStructure RTC_AlarmStruct;

volatile uint32_t F_Second = 0,
                  F_Alarm  = 0;


void SerialInit(void);

int main(void)
{
	RTC_DateTime dateTime;
	RTC_InitStructure RTC_initStruct;
	
	SystemInit();
	
	SerialInit();
	
	RTC_initStruct.clksrc = RTC_CLKSRC_LRC32K;
	RTC_initStruct.Year = 2016;
	RTC_initStruct.Month = 5;
	RTC_initStruct.Date = 5;
	RTC_initStruct.Hour = 15;
	RTC_initStruct.Minute = 5;
	RTC_initStruct.Second = 5;
	RTC_initStruct.SecondIEn = 1;
	RTC_initStruct.MinuteIEn = 0;
	RTC_Init(RTC, &RTC_initStruct);
	
	RTC_AlarmStruct.Days = RTC_SUN | RTC_MON | RTC_TUE | RTC_WED | RTC_THU | RTC_FRI | RTC_SAT;
	RTC_AlarmStruct.Hour = RTC_initStruct.Hour;
	RTC_AlarmStruct.Minute = RTC_initStruct.Minute;
	RTC_AlarmStruct.Second = RTC_initStruct.Second + 5;
	RTC_AlarmStruct.AlarmIEn = 1;
	RTC_AlarmSetup(RTC, &RTC_AlarmStruct);
	
	RTC_Start(RTC);
	
	while(1==1)
	{
		if(F_Second)
		{
			F_Second = 0;
			
			RTC_GetDateTime(RTC, &dateTime);
			printf("Second: %d Minute %d Second\r\n", dateTime.Minute, dateTime.Second);
		}
		
		if(F_Alarm)
		{
			F_Alarm = 0;
			
			RTC_GetDateTime(RTC, &dateTime);
			printf("Alarm : %d Minute %d Second\r\n", dateTime.Minute, dateTime.Second);
		}
	}
}


void RTC_Handler(void)
{
	RTC_DateTime dateTime;
	
	if(RTC_IntSecondStat(RTC))
	{
		RTC_IntSecondClr(RTC);
		
		F_Second = 1;
	}
	
	if(RTC_IntAlarmStat(RTC))
	{
		/* Alarm中断会持续1秒钟，可关掉Alarm中断、或更新定时值解决此问题 */
		RTC_IntAlarmClr(RTC);
		
		RTC_GetDateTime(RTC, &dateTime);
		if(dateTime.Second + 5 < 60)
		{
			RTC_AlarmStruct.Second = dateTime.Second + 5;
		}
		else
		{
			RTC_AlarmStruct.Minute = dateTime.Minute + 1;
			RTC_AlarmStruct.Second = dateTime.Second + 5 - 60;
		}
		RTC_AlarmSetup(RTC, &RTC_AlarmStruct);
		
		F_Alarm = 1;
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
	UART_initStruct.RXThresholdIEn = 0;
	UART_initStruct.TXThresholdIEn = 0;
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

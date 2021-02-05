#include "SWM201.h"


int main(void)
{	
	SystemInit();
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//输出，接LED
	
	TIMR_Init(BTIMR0, TIMR_MODE_TIMER, CyclesPerUs*100, 10000, 1);	//每1秒钟触发一次中断
	
	TIMR_Start(BTIMR0);
	
	while(1==1)
	{
	}
}

void BTIMR0_Handler(void)
{	
	TIMR_INTClr(BTIMR0);
	
	GPIO_InvBit(GPIOA, PIN5);	//反转LED亮灭状态
}

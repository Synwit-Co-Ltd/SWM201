#include "SWM201.h"


int main(void)
{	
	SystemInit();
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//GPIOA.5 => LED
	
	PORTA->PULLU |= (1 << PIN14);
	PORT_Init(PORTA, PIN14, PORTA_PIN14_TIMR0_IN, 1);
	
	TIMR_Init(TIMR0, TIMR_MODE_COUNTER, 1, 3, 1);	//每计3个边沿进入中断
	
	TIMR_Start(TIMR0);
	
	while(1==1)
	{
	}
}

void TIMR0_Handler(void)
{
	TIMR_INTClr(TIMR0);
	
	GPIO_InvBit(GPIOA, PIN5);
}

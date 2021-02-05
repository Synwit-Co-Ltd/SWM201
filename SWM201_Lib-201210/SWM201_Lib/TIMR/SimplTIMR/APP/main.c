#include "SWM201.h"


int main(void)
{	
	SystemInit();
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//�������LED
	
	TIMR_Init(TIMR0, TIMR_MODE_TIMER, CyclesPerUs*4, 50000, 1);		//ÿ200���봥��һ���ж�
	
	TIMR_Start(TIMR0);
	
	while(1==1)
	{
	}
}

void TIMR0_Handler(void)
{
	TIMR_INTClr(TIMR0);
	
	GPIO_InvBit(GPIOA, PIN5);	//��תLED����״̬
}
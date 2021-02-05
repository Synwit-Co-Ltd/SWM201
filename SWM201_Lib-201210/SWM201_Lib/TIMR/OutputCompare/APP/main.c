#include "SWM201.h"


int main(void)
{	
	SystemInit();
	
	PORT_Init(PORTA, PIN14, PORTA_PIN14_TIMR0_OUT, 0);
	
	TIMR_Init(TIMR0, TIMR_MODE_OC, CyclesPerUs, 10000, 0);	//100Hz
	
	TIMR_OC_Init(TIMR0, 7500, 0, 1);						//7500/10000 = 75%
	
	TIMR_Start(TIMR0);
	
	while(1==1)
	{
	}
}

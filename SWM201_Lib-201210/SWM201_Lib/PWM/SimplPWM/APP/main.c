#include "SWM201.h"


int main(void)
{
	uint32_t i;
	PWM_InitStructure  PWM_initStruct;
	
	SystemInit();
	
	PORT_Init(PORTA, PIN3, PORTA_PIN3_PWM0A,  0);
	PORT_Init(PORTA, PIN2, PORTA_PIN2_PWM0AN, 0);
	PORT_Init(PORTA, PIN6, PORTA_PIN6_PWM0B,  0);
	PORT_Init(PORTA, PIN7, PORTA_PIN7_PWM0BN, 0);
	
	PORT_Init(PORTA, PIN5, PORTA_PIN5_PWM1A,  0);
	PORT_Init(PORTM, PIN4, PORTM_PIN4_PWM1AN, 0);
	PORT_Init(PORTA, PIN4, PORTA_PIN4_PWM1B,  0);
	PORT_Init(PORTM, PIN5, PORTM_PIN5_PWM1BN, 0);
	
	PWM_initStruct.Mode = PWM_EDGE_ALIGNED;
	PWM_initStruct.Clkdiv = 6;					//F_PWM = 30M/6 = 5M	
	PWM_initStruct.Period = 10000;				//5M/10000 = 500Hz�����ĶԳ�ģʽ��Ƶ�ʽ��͵�250Hz
	PWM_initStruct.HdutyA =  2500;				//2500/10000 = 25%
	PWM_initStruct.DeadzoneA = 50;				//50/5M = 10us
	PWM_initStruct.IdleLevelA = 0;
	PWM_initStruct.IdleLevelAN= 0;
	PWM_initStruct.OutputInvA = 0;
	PWM_initStruct.OutputInvAN= 0;
	PWM_initStruct.HdutyB =  7500;				//5000/10000 = 50%
	PWM_initStruct.DeadzoneB = 50;				//50/5M = 10us
	PWM_initStruct.IdleLevelB = 0;
	PWM_initStruct.IdleLevelBN= 0;
	PWM_initStruct.OutputInvB = 0;
	PWM_initStruct.OutputInvBN= 0;
	PWM_initStruct.UpOvfIE    = 0;
	PWM_initStruct.DownOvfIE  = 0;
	PWM_initStruct.UpCmpAIE   = 0;
	PWM_initStruct.DownCmpAIE = 0;
	PWM_initStruct.UpCmpBIE   = 0;
	PWM_initStruct.DownCmpBIE = 0;
	PWM_Init(PWM0, &PWM_initStruct);
	PWM_Init(PWM1, &PWM_initStruct);
	
	PWM_Start(PWM0_MSK | PWM1_MSK);
	
	/* ɲ����Brake������ */
#if 0
	PORT_Init(PORTB, PIN14, PORTB_PIN14_PWM_BRK0, 1);	//PB14�л�ΪPWM_BRK0���ܣ��ҿ�������
	PORTB->PULLU |= (1 << PIN14);
	PORT_Init(PORTB, PIN6, PORTB_PIN6_PWM_BRK1, 1);		//PB6�л�ΪPWM_BRK1���ܣ��ҿ�������
	PORTB->PULLU |= (1 << PIN6);
	
	PWM_BrkInPolarity(PWM_BRK0 | PWM_BRK1, 0);			//PWM_BRK0��PWM_BRK1 �͵�ƽɲ��
	PWM_BrkConfig(PWM0, PWM_CH_A, PWM_BRK0 | PWM_BRK1, 0, 1, 1);	// PWM0ͨ��A ��ɲ������ PWM_BRK0��PWM_BRK1 ����
	PWM_BrkConfig(PWM0, PWM_CH_B, PWM_BRK0 | PWM_BRK1, 0, 1, 1);	// PWM0ͨ��B ��ɲ������ PWM_BRK0��PWM_BRK1 ����

	/* ���ɲ����Software Brake������ */
#if 0
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//����ָʾ����
	
	while(1)
	{
		GPIO_SetBit(GPIOA, PIN5);
		PWMG->SWBRK |= (PWMG_SWBRK_PWM0A_Msk |		//�������PWM0A��PWM0B��ɲ������
						PWMG_SWBRK_PWM0B_Msk);
		for(i = 0; i < 300000; i++) __NOP();
		
		GPIO_ClrBit(GPIOA, PIN5);
		PWMG->SWBRK &=~(PWMG_SWBRK_PWM0A_Msk |		//����PWM0A��PWM0B�����ɲ�����ָ��������
						PWMG_SWBRK_PWM0B_Msk);
		for(i = 0; i < 900000; i++) __NOP();
	}
#endif
#endif

	while(1==1)
	{
	}
}

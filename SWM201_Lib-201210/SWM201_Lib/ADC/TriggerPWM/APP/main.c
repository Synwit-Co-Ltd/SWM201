#include "SWM201.h"

void SerialInit(void);
void PWM0AInit(void);

int main(void)
{
	ADC_InitStructure ADC_initStruct;
	
	SystemInit();
	
	SerialInit();
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);
	
	PORT_Init(PORTA, PIN14, PORTA_PIN14_ADC0_CH0, 0);		//PA.14 => ADC0.CH0
	PORT_Init(PORTA, PIN13, PORTA_PIN13_ADC0_CH1, 0);		//PA.13 => ADC0.CH1
	PORT_Init(PORTA, PIN12, PORTA_PIN12_ADC0_CH2, 0);		//PA.12 => ADC0.CH2
	PORT_Init(PORTA, PIN11, PORTA_PIN11_ADC0_CH3, 0);		//PA.11 => ADC0.CH3
	PORT_Init(PORTB, PIN6,  PORTB_PIN6_ADC0_CH4,  0);		//PB.6  => ADC0.CH4
	PORT_Init(PORTB, PIN5,  PORTB_PIN5_ADC0_CH5,  0);		//PB.5  => ADC0.CH5
	PORT_Init(PORTB, PIN4,  PORTB_PIN4_ADC0_CH6,  0);		//PB.4  => ADC0.CH6
	PORT_Init(PORTA, PIN8,  PORTA_PIN8_ADC0_CH7,  0);		//PA.8  => ADC0.CH7
	PORT_Init(PORTB, PIN9,  PORTB_PIN9_ADC0_CH8,  0);		//PB.9  => ADC0.CH8
	PORT_Init(PORTB, PIN7,  PORTB_PIN7_ADC0_CH9,  0);		//PB.7  => ADC0.CH9
	PORT_Init(PORTM, PIN9,  PORTM_PIN9_ADC0_CH10, 0);		//PM.9  => ADC0.CH10
	PORT_Init(PORTM, PIN8,  PORTM_PIN8_ADC0_CH11, 0);		//PM.8  => ADC0.CH11
	
	ADC_initStruct.clk_src = ADC_CLKSRC_HRC_DIV8;
	ADC_initStruct.clk_div = 15;
	ADC_initStruct.ref_src = ADC_REFSRC_VDD;
	ADC_initStruct.channels = ADC_CH0;
	ADC_initStruct.samplAvg = ADC_AVG_SAMPLE1;
	ADC_initStruct.trig_src = ADC_TRIGGER_PWM0;
	ADC_initStruct.Continue = 0;						//������ģʽ��������ģʽ
	ADC_initStruct.EOC_IEn = ADC_CH0;	
	ADC_initStruct.OVF_IEn = 0;
	ADC_Init(ADC0, &ADC_initStruct);					//����ADC
	
	ADC0->CHSEL = (ADC_CH0 << ADC_CHSEL_PWM_Pos);
	
	ADC_Open(ADC0);										//ʹ��ADC
	
	PWM0AInit();
	
	while(1==1)
	{
		while(!ADC_IsEOC(ADC0, ADC_CH0)) __NOP();
		
		printf("%4d,", ADC_Read(ADC0, ADC_CH0));
	}
}


void ADC0_Handler(void)
{
	GPIO_InvBit(GPIOA, PIN5);
	
	ADC_IntEOCClr(ADC0, ADC_CH0);
}


void PWM0AInit(void)
{
	PWM_InitStructure PWM_initStruct;
	
	PORT_Init(PORTA, PIN3, PORTA_PIN3_PWM0A,  0);
	PORT_Init(PORTA, PIN2, PORTA_PIN2_PWM0AN, 0);
	PORT_Init(PORTA, PIN6, PORTA_PIN6_PWM0B,  0);
	PORT_Init(PORTA, PIN7, PORTA_PIN7_PWM0BN, 0);
	
	PWM_initStruct.Mode = PWM_CENTER_ALIGNED;
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
	
	
	/* Mask */
	PWM_CmpTrigger(PWM0, 1500, PWM_DIR_UP, 40, PWM_TRG_1, 7);	//PWM0���ϼ�������ֵ����1500ʱ����һ�������źţ������źŷ��͵� trigger1
	
	PWM_OutMask(PWM0, PWM_CH_A, PWM_EVT_1, 0, PWM_EVT_1, 1);	//PWM0A��PWM0AN��event1Ϊ��ʱ�ֱ����0��1
	PWM_OutMask(PWM0, PWM_CH_B, PWM_EVT_1, 0, PWM_EVT_1, 1);	//PWM0B��PWM0BN��event1Ϊ��ʱ�ֱ����0��1
}


void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTA, PIN0, PORTA_PIN0_UART0_RX, 1);	//GPIOA.0����ΪUART0 RXD
	PORT_Init(PORTA, PIN1, PORTA_PIN1_UART0_TX, 0);	//GPIOA.1����ΪUART0 TXD
 	
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
* ��������: fputc()
* ����˵��: printf()ʹ�ô˺������ʵ�ʵĴ��ڴ�ӡ����
* ��    ��: int ch		Ҫ��ӡ���ַ�
*			FILE *f		�ļ����
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
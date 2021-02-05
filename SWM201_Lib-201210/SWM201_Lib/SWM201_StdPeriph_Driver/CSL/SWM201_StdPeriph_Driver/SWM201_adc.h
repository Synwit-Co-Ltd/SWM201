#ifndef __SWM201_ADC_H__
#define	__SWM201_ADC_H__

typedef struct {
	uint8_t  clk_src;		//ADCת��ʱ��Դ��ADC_CLKSRC_HRC_DIV32��ADC_CLKSRC_XTAL_DIV32��...
	uint8_t  clk_div;		//ADCת��ʱ�ӷ�Ƶ��ȡֵ1--31
	uint8_t  ref_src;		//ADCת���ο�Դ��ADC_REFSRC_VREFP��ADC_REFSRC_VDD
	uint16_t channels;		//ADCת��ͨ��ѡ�У�ADC_CH0��ADC_CH1��... ... ��ADC_CH11������ϣ�������λ�����㣩
	uint8_t  samplAvg;		//����ȡƽ������������ADCת����ADC��һ��ͨ��������������ת����Σ��������ǵ�ƽ��ֵ��Ϊ��ͨ��ת�����
	uint16_t trig_src;		//ADC������ʽ��ADC_TRIGGER_SW��ADC_TRIGGER_TIMR2��ADC_TRIGGER_TIMR3��ADC_TRIGGER_PWM0A��...
	uint8_t  Continue;		//����������ģʽ�£�1 ����ת��ģʽ��������һֱ������ת����ֱ���������STARTλ
							//                  0 ����ת��ģʽ��ת����ɺ�STARTλ�Զ����ֹͣת��
	uint16_t EOC_IEn;		//EOC�ж�ʹ�ܣ������ÿ��ͨ�����ã�����ЧֵΪADC_CH0��ADC_CH1��... ... ��ADC_CH11������ϣ�������λ�����㣩
	uint16_t OVF_IEn;		//OVF�ж�ʹ�ܣ������ÿ��ͨ�����ã�����ЧֵΪADC_CH0��ADC_CH1��... ... ��ADC_CH11������ϣ�������λ�����㣩
} ADC_InitStructure;

#define ADC_CH0		0x001
#define ADC_CH1		0x002
#define ADC_CH2		0x004
#define ADC_CH3		0x008
#define ADC_CH4		0x010
#define ADC_CH5		0x020
#define ADC_CH6		0x040
#define ADC_CH7		0x080
#define ADC_CH8		0x100
#define ADC_CH9		0x200
#define ADC_CH10	0x400
#define ADC_CH11	0x800

#define ADC_CLKSRC_HRC_DIV8		((0 << 2) | 0)
#define ADC_CLKSRC_XTAL_DIV8	((0 << 2) | 1)
#define ADC_CLKSRC_HRC_DIV32	((2 << 2) | 0)
#define ADC_CLKSRC_XTAL_DIV32	((2 << 2) | 1)
#define ADC_CLKSRC_HRC_DIV64	((3 << 2) | 0)
#define ADC_CLKSRC_XTAL_DIV64	((3 << 2) | 1)

#define ADC_REFSRC_VREFP		0	//Vrefp ����
#define ADC_REFSRC_VDD			1	//оƬVDD

#define ADC_AVG_SAMPLE1			0	
#define ADC_AVG_SAMPLE2			1	//һ����������������ת��2�Σ����������ν����ƽ��ֵ��Ϊת�����
#define ADC_AVG_SAMPLE4			3
#define ADC_AVG_SAMPLE8			7
#define ADC_AVG_SAMPLE16		15

#define ADC_TRIGGER_SW			0	//������������ADC->START.GOд1����ת��
#define ADC_TRIGGER_TIMR0		2
#define ADC_TRIGGER_TIMR1		3
#define ADC_TRIGGER_PWM0		0x1001
#define ADC_TRIGGER_PWM1		0x1004


void ADC_Init(ADC_TypeDef * ADCx, ADC_InitStructure * initStruct);		//ADCģ��ת������ʼ��
uint32_t ADC_Calibrate(ADC_TypeDef * ADCx);
void ADC_Open(ADC_TypeDef * ADCx);							//ADC����������������������Ӳ������ADCת��
void ADC_Close(ADC_TypeDef * ADCx);							//ADC�رգ��޷�������������Ӳ������ADCת��
void ADC_Start(ADC_TypeDef * ADCx);							//����ָ��ADC����ʼģ��ת��
void ADC_Stop(ADC_TypeDef * ADCx);							//�ر�ָ��ADC��ֹͣģ��ת��

uint32_t ADC_Read(ADC_TypeDef * ADCx, uint32_t chn);		//��ָ��ͨ����ȡת�����
uint32_t ADC_IsEOC(ADC_TypeDef * ADCx, uint32_t chn);		//ָ��ͨ���Ƿ�End Of Conversion

void ADC_ChnSelect(ADC_TypeDef * ADCx, uint32_t chns);

void ADC_IntEOCEn(ADC_TypeDef * ADCx, uint32_t chn);		//ת������ж�ʹ��
void ADC_IntEOCDis(ADC_TypeDef * ADCx, uint32_t chn);		//ת������жϽ�ֹ
void ADC_IntEOCClr(ADC_TypeDef * ADCx, uint32_t chn);		//ת������жϱ�־���
uint32_t ADC_IntEOCStat(ADC_TypeDef * ADCx, uint32_t chn);	//ת������ж�״̬

void ADC_IntOVFEn(ADC_TypeDef * ADCx, uint32_t chn);		//��������ж�ʹ��
void ADC_IntOVFDis(ADC_TypeDef * ADCx, uint32_t chn);		//��������жϽ�ֹ
void ADC_IntOVFClr(ADC_TypeDef * ADCx, uint32_t chn);		//��������жϱ�־���
uint32_t ADC_IntOVFStat(ADC_TypeDef * ADCx, uint32_t chn);	//��������ж�״̬


#endif //__SWM201_ADC_H__
#ifndef __SWM201_I2C_H__
#define __SWM201_I2C_H__

typedef struct {
	uint8_t  Master;		//1 主机模式    0 从机模式
	uint32_t MstClk;		//主机传输时钟频率
	
	uint8_t  Addr10b;		//1 10位地址模式     0 7位地址模式
	uint16_t SlvAddr;		//从机地址
	uint16_t SlvAddrMsk;
	
	uint8_t  TXEmptyIEn;	//发送寄存器空中断使能
	uint8_t  RXNotEmptyIEn;	//接收寄存器非空中断使能
	uint8_t  SlvSTADetIEn;	//从机检测到起始中断使能
	uint8_t  SlvSTODetIEn;	//从机检测到终止中断使能
} I2C_InitStructure;


void I2C_Init(I2C_TypeDef * I2Cx, I2C_InitStructure * initStruct);

void I2C_Open(I2C_TypeDef * I2Cx);
void I2C_Close(I2C_TypeDef * I2Cx);

uint8_t I2C_Start(I2C_TypeDef * I2Cx, uint8_t addr);
void I2C_Stop(I2C_TypeDef * I2Cx);
uint8_t I2C_Write(I2C_TypeDef * I2Cx, uint8_t data);
uint8_t I2C_Read(I2C_TypeDef * I2Cx, uint8_t ack);


#endif //__SWM201_I2C_H__

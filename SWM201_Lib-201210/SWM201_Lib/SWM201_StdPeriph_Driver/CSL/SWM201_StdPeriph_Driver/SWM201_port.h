#ifndef __SWM201_PORT_H__
#define __SWM201_PORT_H__

void PORT_Init(PORT_TypeDef * PORTx, uint32_t n, uint32_t func, uint32_t digit_in_en);	//端口引脚功能选择，其可取值如下：


#define PORTA_PIN0_GPIO         0
#define PORTA_PIN0_I2C0_SCL     1
#define PORTA_PIN0_UART0_RX     2
#define PORTA_PIN0_PWM0AN       3
#define PORTA_PIN0_PWM1AN       4
#define PORTA_PIN0_PWM0A        5

#define PORTA_PIN1_GPIO         0
#define PORTA_PIN1_I2C0_SDA     1
#define PORTA_PIN1_UART0_TX     2
#define PORTA_PIN1_PWM1BN       3
#define PORTA_PIN1_PWM1B        4

#define PORTA_PIN2_GPIO         0
#define PORTA_PIN2_PWM1AN       1
#define PORTA_PIN2_PWM0AN       2
#define PORTA_PIN2_PWM1A        3

#define PORTA_PIN3_GPIO         0
#define PORTA_PIN3_PWM0A        1
#define PORTA_PIN3_PWM1AN       2
#define PORTA_PIN3_PWM0AN       3

#define PORTA_PIN4_GPIO         0
#define PORTA_PIN4_UART1_TX     1
#define PORTA_PIN4_PWM1B        2
#define PORTA_PIN4_PWM1BN       3

#define PORTA_PIN5_GPIO         0
#define PORTA_PIN5_UART1_RX     1
#define PORTA_PIN5_PWM1A        2
#define PORTA_PIN5_PWM0AN       3
#define PORTA_PIN5_PWM1AN       4

#define PORTA_PIN6_GPIO         0
#define PORTA_PIN6_I2C0_SCL     1
#define PORTA_PIN6_PWM0B        2

#define PORTA_PIN7_GPIO         0
#define PORTA_PIN7_I2C0_SDA     1
#define PORTA_PIN7_PWM0BN       2

#define PORTA_PIN8_GPIO         0
#define PORTA_PIN8_UART1_CTS    1
#define PORTA_PIN8_ADC0_CH7     7
#define PORTA_PIN8_OPA1_OUT     7

#define PORTA_PIN9_GPIO         0
#define PORTA_PIN9_OPA1_INP     7

#define PORTA_PIN10_GPIO        0
#define PORTA_PIN10_PWM_BRK2    1
#define PORTA_PIN10_OPA1_INN    7

#define PORTA_PIN11_GPIO        0
#define PORTA_PIN11_PWM_CLK1    1
#define PORTA_PIN11_ADC0_CH3    7
#define PORTA_PIN11_OPA0_OUT    7

#define PORTA_PIN12_GPIO        0
#define PORTA_PIN12_ADC0_CH2    7
#define PORTA_PIN12_OPA0_INP    7

#define PORTA_PIN13_GPIO        0
#define PORTA_PIN13_ADC0_CH1    7
#define PORTA_PIN13_OPA0_INN    7

#define PORTA_PIN14_GPIO        0
#define PORTA_PIN14_TIMR0_IN    1
#define PORTA_PIN14_TIMR0_OUT   2
#define PORTA_PIN14_ADC0_CH0    7
#define PORTA_PIN14_ACMP3_INP   7

#define PORTA_PIN15_GPIO        0

#define PORTB_PIN0_GPIO         0
#define PORTB_PIN0_UART0_RTS    1
#define PORTB_PIN0_ACMP2_INN    7

#define PORTB_PIN1_GPIO         0
#define PORTB_PIN1_UART0_CTS    1
#define PORTB_PIN1_ACMP1_INN    7

#define PORTB_PIN2_GPIO         0
#define PORTB_PIN2_UART0_TX     1
#define PORTB_PIN2_ACMP0_INN    7

#define PORTB_PIN3_GPIO         0
#define PORTB_PIN3_UART0_RX     1
#define PORTB_PIN3_RTC_1HZ      2

#define PORTB_PIN4_GPIO         0
#define PORTB_PIN4_I2C0_SCL     1
#define PORTB_PIN4_HALL_IN0     2
#define PORTB_PIN4_FILTER0      3
#define PORTB_PIN4_ADC0_CH6     7
#define PORTB_PIN4_ACMP2_INP    7

#define PORTB_PIN5_GPIO         0
#define PORTB_PIN5_I2C0_SDA     1
#define PORTB_PIN5_HALL_IN1     2
#define PORTB_PIN5_TIMR1_IN     3
#define PORTB_PIN5_TIMR1_OUT    4
#define PORTB_PIN5_FILTER0      5
#define PORTB_PIN5_ADC0_CH5     7
#define PORTB_PIN5_ACMP1_INP    7

#define PORTB_PIN6_GPIO         0
#define PORTB_PIN6_PWM_BRK1     1
#define PORTB_PIN6_HALL_IN2     2
#define PORTB_PIN6_TIMR0_IN     3
#define PORTB_PIN6_TIMR0_OUT    4
#define PORTB_PIN6_FILTER0      5
#define PORTB_PIN6_ADC0_CH4     7
#define PORTB_PIN6_ACMP0_INP    7

#define PORTB_PIN7_GPIO         0
#define PORTB_PIN7_UART1_TX     1
#define PORTB_PIN7_TIMR1_IN     2
#define PORTB_PIN7_TIMR1_OUT    3
#define PORTB_PIN7_ADC0_CH9     7
#define PORTB_PIN7_OPA2_INP     7

#define PORTB_PIN8_GPIO         0
#define PORTB_PIN8_UART1_RX     1
#define PORTB_PIN8_OPA2_INN     7

#define PORTB_PIN9_GPIO         0
#define PORTB_PIN9_UART1_RTS    1
#define PORTB_PIN9_ADC0_CH8     7
#define PORTB_PIN9_OPA2_OUT     7

#define PORTB_PIN10_GPIO        0
#define PORTB_PIN10_PWM0AN      1
#define PORTB_PIN10_TIMR0_IN    2
#define PORTB_PIN10_TIMR0_OUT   3

#define PORTB_PIN11_GPIO        0
#define PORTB_PIN11_UART0_TX    1
#define PORTB_PIN11_PWM0BN      2
#define PORTB_PIN11_TIMR1_IN    3
#define PORTB_PIN11_TIMR1_OUT   4
#define PORTB_PIN11_XTAL_IN     7

#define PORTB_PIN12_GPIO        0
#define PORTB_PIN12_UART0_RX    1
#define PORTB_PIN12_PWM0B       2
#define PORTB_PIN12_TIMR0_IN    3
#define PORTB_PIN12_TIMR0_OUT   4
#define PORTB_PIN12_XTAL_OUT    7

#define PORTB_PIN13_GPIO        0
#define PORTB_PIN13_PWM0A       1

#define PORTB_PIN14_GPIO        0
#define PORTB_PIN14_UART0_TX    1
#define PORTB_PIN14_PWM_BRK0    2
#define PORTB_PIN14_FILTER0     3
#define PORTB_PIN14_ACMP3_INN   7

#define PORTB_PIN15_GPIO        0
#define PORTB_PIN15_UART0_RX    1

#define PORTM_PIN0_GPIO         0
#define PORTM_PIN0_SWCLK        1
#define PORTM_PIN0_UART1_TX     2
#define PORTM_PIN0_PWM_CLK0     3

#define PORTM_PIN1_GPIO         0
#define PORTM_PIN1_SWDIO        1
#define PORTM_PIN1_UART1_RX     2
#define PORTM_PIN1_TIMR1_IN     3
#define PORTM_PIN1_TIMR1_OUT    4

#define PORTM_PIN2_GPIO         0
#define PORTM_PIN2_PWM1BN       1
#define PORTM_PIN2_PWM1B        2
#define PORTM_PIN2_HALL_IN0     3
#define PORTM_PIN2_RTC_1HZ      4
#define PORTM_PIN2_FILTER1      6

#define PORTM_PIN3_GPIO         0
#define PORTM_PIN3_I2C0_SCL     1
#define PORTM_PIN3_UART0_TX     2
#define PORTM_PIN3_PWM1B        3
#define PORTM_PIN3_PWM0A        4
#define PORTM_PIN3_PWM1BN       5
#define PORTM_PIN3_HALL_IN1     6
#define PORTM_PIN3_FILTER1      7

#define PORTM_PIN4_GPIO         0
#define PORTM_PIN4_I2C0_SDA     1
#define PORTM_PIN4_UART0_RX     2
#define PORTM_PIN4_PWM1AN       3
#define PORTM_PIN4_PWM1A        4
#define PORTM_PIN4_HALL_IN2     5
#define PORTM_PIN4_FILTER1      6

#define PORTM_PIN5_GPIO         0
#define PORTM_PIN5_PWM1A        1
#define PORTM_PIN5_PWM1BN       2
#define PORTM_PIN5_PWM1AN       3

#define PORTM_PIN6_GPIO         0
#define PORTM_PIN6_PWM0AN       1
#define PORTM_PIN6_PWM0A        2
#define PORTM_PIN6_FILTER1      3

#define PORTM_PIN7_GPIO         0
#define PORTM_PIN7_PWM0A        1
#define PORTM_PIN7_PWM1AN       2
#define PORTM_PIN7_PWM0AN       3

#define PORTM_PIN8_GPIO         0
#define PORTM_PIN8_PWM0BN       1
#define PORTM_PIN8_TIMR0_IN     2
#define PORTM_PIN8_TIMR0_OUT    3
#define PORTM_PIN8_ADC0_CH11    7

#define PORTM_PIN9_GPIO         0
#define PORTM_PIN9_PWM0B        1
#define PORTM_PIN9_TIMR1_IN     2
#define PORTM_PIN9_TIMR1_OUT    3
#define PORTM_PIN9_ADC0_CH10    7

#define PORTM_PIN10_GPIO        0

#define PORTM_PIN11_GPIO        0

#endif //__SWM201_PORT_H__

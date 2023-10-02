//#include "stm32f10x.h"
//#include "usart.h"
//#include "delay.h"
//#include "string.h"
//
//
//int TRUE=1;
//int main(void)
//{
//    uart_init(115200);
//    delay_init();
//    while(TRUE){
//        USART_SEND(USART1,"Hello World!\n");
//        delay_ms(1000);
//    }
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//    return 0;
//}
#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    while (1)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
        delay_ms(500);

        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
        delay_ms(500);

        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
        delay_ms(500);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
        delay_ms(500);

        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
        delay_ms(500);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
        delay_ms(500);
    }
}

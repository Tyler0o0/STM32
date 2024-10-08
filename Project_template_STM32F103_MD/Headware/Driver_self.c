#include "stm32f10x.h"
//A B端口初始化
void Init_GPIOA(uint32_t GPIO_Mode_x,uint32_t GPIO_Pin_x,uint32_t GPIO_Speed_x)
{
    //开启PB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct_x;
        GPIO_InitStruct_x.GPIO_Mode = GPIO_Mode_x;
        GPIO_InitStruct_x.GPIO_Pin = GPIO_Pin_x;
        GPIO_InitStruct_x.GPIO_Speed = GPIO_Speed_x;

    //设置输出模式
    GPIO_Init(GPIOA,&GPIO_InitStruct_x);
}

void Init_GPIOB(uint32_t GPIO_Mode_x,uint32_t GPIO_Pin_x,uint32_t GPIO_Speed_x)
{
    //开启PB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct_x;
        GPIO_InitStruct_x.GPIO_Mode = GPIO_Mode_x;
        GPIO_InitStruct_x.GPIO_Pin = GPIO_Pin_x;
        GPIO_InitStruct_x.GPIO_Speed = GPIO_Speed_x;

    //设置输出模式
    GPIO_Init(GPIOB,&GPIO_InitStruct_x);
}

void Delay_ms(uint32_t MHZ,uint32_t ms,uint32_t cycle)
{
    SystemCoreClock = MHZ;
    for(uint32_t i = 0;i<cycle;i++)
    {
     //SysTickick初始化
        SysTick->LOAD = (SystemCoreClock/1000)*ms-1;
        SysTick->VAL = 0;
        SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Pos|
                        SysTick_CTRL_ENABLE_Msk;
        while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0)
        {
            ;
        }
    }
    SysTick->CTRL = SysTick_CTRL_ENABLE_Pos;
}

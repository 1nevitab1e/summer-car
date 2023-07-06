/*
 * Measure.c
 *
 *  Created on: 2023年5月13日
 *      Author: 86131
 */

#include "Measure.h"

#define IC A6 //TIM3_CHANNEL1

void IC_Init()
{
    timer_clock_enable(TIM_3);
    gpio_init(IC, GPI, 0, GPI_PULL_UP);

    TIM_InternalClockConfig(TIM3);
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = 12-1;// 144/12=12MHz
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // 设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM向上计数模式
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;                            // 重复计数器设置为0
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_ICInitTypeDef TIM3_ICInitStructure;
    TIM3_ICInitStructure.TIM_Channel = TIM_Channel_1; //选择输入端 IC1 映射到 TI1 上
    TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //上升沿捕获
    TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到 TI1 上
    TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; //配置输入分频,不分频
    TIM3_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
    TIM_ICInit(TIM2, &TIM3_ICInitStructure);


    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);//主从自动清零
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);

    TIM_Cmd(TIM3, ENABLE);
}

u16 GetNum()//rps=12MHz/7/n,rpm=rps*60
{
    return 12000000 / TIM_GetCapture1(TIM3)/7;
}

/*TODO*/
u8 Measure()
{

}

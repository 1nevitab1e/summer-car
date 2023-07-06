/*
 * PWM.c
 *
 *  Created on: 2023Äê3ÔÂ28ÈÕ
 *      Author: 86131
 */
#include "zf_common_headfile.h"

void PWM_Init()
{
    RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    gpio_init(A8, GPO, GPIO_LOW, GPO_AF_PUSH_PULL);
    TIM_InternalClockConfig(TIM1);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;
    TIM_TimeBaseInitStruct.TIM_Prescaler=720-1;
    TIM_TimeBaseInitStruct.TIM_Period=100-1;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);

    TIM_OCInitTypeDef TIMOC;
    TIM_OCStructInit(&TIMOC);
    TIMOC.TIM_OCMode=TIM_OCMode_PWM1;
    TIMOC.TIM_OCPolarity=TIM_OCPolarity_High;
    TIMOC.TIM_OutputState=TIM_OutputState_Enable;
    TIMOC.TIM_Pulse=50;//CCR
    TIM_OC1Init(TIM1, &TIMOC);
    TIM_OC2Init(TIM1, &TIMOC);
    TIM_OC3Init(TIM1, &TIMOC);
    TIM_OC4Init(TIM1, &TIMOC);

    TIM_Cmd(TIM1, ENABLE);
}


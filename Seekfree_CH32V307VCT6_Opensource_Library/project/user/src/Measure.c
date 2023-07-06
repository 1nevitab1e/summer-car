/*
 * Measure.c
 *
 *  Created on: 2023��5��13��
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
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // ����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM���ϼ���ģʽ
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;                            // �ظ�����������Ϊ0
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_ICInitTypeDef TIM3_ICInitStructure;
    TIM3_ICInitStructure.TIM_Channel = TIM_Channel_1; //ѡ������� IC1 ӳ�䵽 TI1 ��
    TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //�����ز���
    TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽 TI1 ��
    TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; //���������Ƶ,����Ƶ
    TIM3_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
    TIM_ICInit(TIM2, &TIM3_ICInitStructure);


    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);//�����Զ�����
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

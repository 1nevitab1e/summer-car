/*
 * daojishi.c
 *
 *  Created on: 2023年4月7日
 *      Author: 86131
 */
#include "zf_common_headfile.h"
#include "KEY.h"
extern uint16_t Num;
extern uint16_t Lim;
extern int i;

void timer_init()//对于TIM6
{
    timer_start(TIM_6, TIMER_MS);//修改后一次计时50ms
    TIM_SetAutoreload(TIM6,500-1);
    TIM_PrescalerConfig(TIM6,14400-1,TIM_PSCReloadMode_Immediate);

    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
    TIM_ITConfig(TIM6 , TIM_IT_Update, ENABLE);//更新中断

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置NVIC以配置中断
    NVIC_InitTypeDef NVIC_InitS;
    NVIC_InitS.NVIC_IRQChannel=TIM6_IRQn;
    NVIC_InitS.NVIC_IRQChannelCmd=ENABLE;
    NVIC_InitS.NVIC_IRQChannelPreemptionPriority=2;
    NVIC_InitS.NVIC_IRQChannelSubPriority=1;
    NVIC_Init(&NVIC_InitS);
}

void timer_settime()
{
    i=0;
    int flag=1;
    while(i != 4 && flag)
    {
        i=Key_Get();
        if(i==1)
        {
            Lim=60;
            oled_show_uint(40, 2, Lim, 3);
        }
        if(i==2)
        {
            Lim+=10;
            oled_show_uint(40, 2, Lim, 3);
        }
        if(i==3)
        {
            Lim-=10;
            oled_show_uint(40, 2, Lim, 3);
        }
        if(Lim < Num)
        {
            Num=0;
            flag=0;
        }
    }
    oled_show_string(0, 2, "                  ");
}


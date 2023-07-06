 /*
 * LED.c
 *
 *  Created on: 2023Äê3ÔÂ24ÈÕ
 *      Author: 86131
 */
#include "zf_common_headfile.h"
#include "PWM.h"
#include "KEY.h"

extern int i;
extern uint j;

void LED_Init()
{
    gpio_init(A8, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(A9, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(A10, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(A11, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(A12, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(A15, GPO, GPIO_LOW, GPO_PUSH_PULL);

}

void LED_Clear()
{
    gpio_set_level(A8,1);
    gpio_set_level(A9,1);
    gpio_set_level(A10,1);
    gpio_set_level(A11,1);
    gpio_set_level(A12,1);
    gpio_set_level(A13,1);
}

void LED_Mode1()
{
    system_delay_ms(100);
    gpio_toggle_level(A8);
    system_delay_ms(100);
    gpio_toggle_level(A9);
    system_delay_ms(100);
    gpio_toggle_level(A10);
    system_delay_ms(100);
    gpio_toggle_level(A11);
    system_delay_ms(100);
    gpio_toggle_level(A12);
    system_delay_ms(100);
    gpio_toggle_level(A15);
}

void LED_Mode2()
{
    system_delay_ms(200);
    gpio_toggle_level(A8);
    gpio_toggle_level(A9);
    system_delay_ms(200);
    gpio_toggle_level(A10);
    gpio_toggle_level(A11);
    system_delay_ms(200);
    gpio_toggle_level(A12);
    gpio_toggle_level(A15);
}

void LED_Mode3_Init()
{
    LED_Clear();
    pwm_init(TIM1_PWM_CH3_A10, 1000, 5000);
    pwm_init(TIM1_PWM_CH4_A11, 1000, 5000);
    pwm_init(TIM1_PWM_CH1_A8, 1000, 5000);
    pwm_init(TIM1_PWM_CH2_A9, 1000, 5000);
}

void LED_Mode3()
{
    uint32 i;
    for(i=100;i<10000;i+=100)
        {
            pwm_set_duty(TIM1_PWM_CH1_A8,i);
            pwm_set_duty(TIM1_PWM_CH2_A9,i);
            pwm_set_duty(TIM1_PWM_CH3_A10,i);
            pwm_set_duty(TIM1_PWM_CH4_A11,i);
            system_delay_ms(10);
        }
    for(i=9800;i>0;i-=100)
        {
            pwm_set_duty(TIM1_PWM_CH1_A8,i);
            pwm_set_duty(TIM1_PWM_CH2_A9,i);
            pwm_set_duty(TIM1_PWM_CH3_A10,i);
            pwm_set_duty(TIM1_PWM_CH4_A11,i);
            system_delay_ms(10);
        }
}

void LED_Mode(int i)
{
    if(i==1) LED_Mode1();
    else if(i==2) LED_Mode2();
    else LED_Mode3();
}

void LED_Blink(int flag)
{
   i=1;
   if(!flag)
   {
       i=3;
   }
   while(i!=4)
   {
    if(i == 1 && flag)
    {
        i=0;
        LED_Init();
        LED_Clear();
        j=1;
    }

    if(i == 2 && flag)
    {
        i=0;
        LED_Init();
        LED_Clear();
        j=2;
     }

     if(i == 3 && !flag)
     {
        i=0;
        LED_Mode3_Init();
        j=3;
     }
     LED_Mode(j);
     i=Key_Get();
    }
}

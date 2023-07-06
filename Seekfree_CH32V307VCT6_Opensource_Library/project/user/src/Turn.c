/*
 * Turn.c
 *
 *  Created on: 2023年5月27日
 *      Author: 86131
 */

#include "Turn.h"
#include "duin0.h"

extern u8 State;

static void RightTurn()
{
    pwm_set_duty(TIM1_PWM_CH1_A8, 1000);
    pwm_set_duty(TIM1_PWM_CH2_A9, 0);
    pwm_set_duty(TIM1_PWM_CH4_A11, 1000);
}

static void LeftTurn()
{
    pwm_set_duty(TIM1_PWM_CH1_A8, 0);
    pwm_set_duty(TIM1_PWM_CH3_A10, 1000);
    pwm_set_duty(TIM1_PWM_CH2_A9, 1000);
}

/*
 * 直角弯判断和处理
 * 右边 左边和T字同一类弯原地差速转弯
 * 十字直走
 * 起点和终点的判断
 * 调头路原地差速转弯
 * */
void RightAngle()
{
    u8 flag=0;//0是起点，1是终点

    if(State == 0x00011111)//right
        {
            while(!(State == 0x00011000))
            {
                RightTurn();
            }
        }
    else if(State == 0x11111000)//left
        {
            while(!(State == 0x00011000))
            {
                LeftTurn();
            }
        }
    else if(State == 0x11111111)//直走或者调头判断
        {

            while(!(State == 0x11111111));

            if(State & 0x00011000);//直走
            else if(!State)//调头
            {
                while(!(State == 0x00011000))
                {
                    LeftTurn();
                }
            }
            else if(State == 0x01111110)
            {
                if(flag)
                {
                    pwm_set_duty(TIM1_PWM_CH3_A10, 0);
                    pwm_set_duty(TIM1_PWM_CH4_A11, 0);
                    pwm_set_duty(TIM1_PWM_CH1_A8, 0);
                    pwm_set_duty(TIM1_PWM_CH2_A9, 0);
                }
                flag = 1;
            }


        }
    pwm_set_duty(TIM1_PWM_CH3_A10, 0);
    pwm_set_duty(TIM1_PWM_CH4_A11, 0);
    pwm_set_duty(TIM1_PWM_CH1_A8, 2000);
    pwm_set_duty(TIM1_PWM_CH2_A9, 2000);
}

/*锐角弯判断和处理
 * 就原地转弯 可能会有一点问题在的 这一个
 * */
void AcuteAngle()
{
    //u8 StateTemp[2];
    if(State == 0x00011001) //right
    {
        while(!(State == 0x00011100));

        while(!(State == 0x00011000))
        {
            RightTurn();
        }
    }
    else if(State == 0x10011000) //right
    {
        while(!(State == 0x00111000));

        while(!(State == 0x00011000))
        {
            LeftTurn();
        }
    }
    pwm_set_duty(TIM1_PWM_CH3_A10, 0);
    pwm_set_duty(TIM1_PWM_CH4_A11, 0);
    pwm_set_duty(TIM1_PWM_CH1_A8, 2000);
    pwm_set_duty(TIM1_PWM_CH2_A9, 2000);
}

/*钝角弯判断和处理
 *两个或者一个检测到轨道可以认定是钝角弯
 * */
void ObtuseAngle()
{
    if((State == 0x00001100) || (State == 0x00001000))//right
    {
        while(!(State == 0x00011000))
        {
            RightTurn();
        }
    }
    else if((State == 0x00110000) || (State == 0x00010000))//left
    {
        while(!(State == 0x00011000))
        {
            LeftTurn();
        }
    }

    pwm_set_duty(TIM1_PWM_CH3_A10, 0);
    pwm_set_duty(TIM1_PWM_CH4_A11, 0);
    pwm_set_duty(TIM1_PWM_CH1_A8, 2000);
    pwm_set_duty(TIM1_PWM_CH2_A9, 2000);
}

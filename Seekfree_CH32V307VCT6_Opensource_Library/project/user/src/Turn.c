/*
 * Turn.c
 *
 *  Created on: 2023��5��27��
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
 * ֱ�����жϺʹ���
 * �ұ� ��ߺ�T��ͬһ����ԭ�ز���ת��
 * ʮ��ֱ��
 * �����յ���ж�
 * ��ͷ·ԭ�ز���ת��
 * */
void RightAngle()
{
    u8 flag=0;//0����㣬1���յ�

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
    else if(State == 0x11111111)//ֱ�߻��ߵ�ͷ�ж�
        {

            while(!(State == 0x11111111));

            if(State & 0x00011000);//ֱ��
            else if(!State)//��ͷ
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

/*������жϺʹ���
 * ��ԭ��ת�� ���ܻ���һ�������ڵ� ��һ��
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

/*�۽����жϺʹ���
 *��������һ����⵽��������϶��Ƕ۽���
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

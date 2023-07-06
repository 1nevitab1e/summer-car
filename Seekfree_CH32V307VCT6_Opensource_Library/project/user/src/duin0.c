/*
 * duin0.c
 *
 *  Created on: 2023年5月27日
 *      Author: 86131
 */
#include "duin0.h"

//浅色出0，深色出1
//PD0~7

u8 StateCheck[5];
u8 State;

void duin0_init()
{

    gpio_init(D0, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D1, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D2, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D3, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D4, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D5, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D6, GPI, 0, GPI_PULL_DOWN);
    gpio_init(D7, GPI, 0, GPI_PULL_DOWN);
}

u8 State_Check()
{
    u8 State = 0x00000000;

    if(gpio_get_level(D0) == 1) State |= (0x00000001);
    if(gpio_get_level(D1) == 1) State |= (0x00000001 << 1);
    if(gpio_get_level(D2) == 1) State |= (0x00000001 << 2);
    if(gpio_get_level(D3) == 1) State |= (0x00000001 << 3);
    if(gpio_get_level(D4) == 1) State |= (0x00000001 << 4);
    if(gpio_get_level(D5) == 1) State |= (0x00000001 << 5);
    if(gpio_get_level(D6) == 1) State |= (0x00000001 << 6);
    if(gpio_get_level(D7) == 1) State |= (0x00000001 << 7);

    return State;
}

void Forward()
{

    if(State & 0x00011100 == 1)
    {
        pwm_set_duty(TIM1_PWM_CH1_A8, 1500);//left
    }
    else if(State & 0x00111000 == 1)
    {
        pwm_set_duty(TIM1_PWM_CH2_A9, 1500);//right
    }
    else
    {
        pwm_set_duty(TIM1_PWM_CH1_A8, 2000);
        pwm_set_duty(TIM1_PWM_CH2_A9, 2000);
    }

}

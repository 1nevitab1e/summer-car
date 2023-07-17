/*
 * Wheel.c
 *
 *  Created on: 2023Äê7ÔÂ12ÈÕ
 *      Author: 86131
 */
#include "Wheel.h"

void Wheel_Init()
{
    pwm_init(m1,Hz,0);
    pwm_init(m2,Hz,0);
    pwm_init(m3,Hz,0);
    pwm_init(m4,Hz,0);
    pwm_init(m5,Hz,0);
    pwm_init(m6,Hz,0);
    pwm_init(m7,Hz,0);
    pwm_init(m8,Hz,0);
}

void Wheel_Forge()
{
    pwm_set_duty(m1, 1000);
    pwm_set_duty(m2, 1000);
    pwm_set_duty(m3, 0);
    pwm_set_duty(m4, 0);
    pwm_set_duty(m5, 1000);
    pwm_set_duty(m6, 1000);
    pwm_set_duty(m7, 0);
    pwm_set_duty(m8, 0);
}

void Wheel_reverse()
{
    pwm_set_duty(m2, 1000);
    pwm_set_duty(m1, 1000);
    pwm_set_duty(m4, 0);
    pwm_set_duty(m3, 0);
    pwm_set_duty(m7, 1000);
    pwm_set_duty(m8, 1000);
    pwm_set_duty(m5, 0);
    pwm_set_duty(m6, 0);
}

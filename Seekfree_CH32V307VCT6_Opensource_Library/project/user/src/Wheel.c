/*
 * Wheel.c
 *
 *  Created on: 2023��7��12��
 *      Author: 86131
 */
#include "Wheel.h"

void Wheel_Init()
{
    pwm_init(m1,100,0);
    pwm_init(m2,100,0);
    pwm_init(m3,100,0);
    pwm_init(m4,100,0);
    pwm_init(m5,100,0);
    pwm_init(m6,100,0);
    pwm_init(m7,100,0);
    pwm_init(m8,100,0);
}

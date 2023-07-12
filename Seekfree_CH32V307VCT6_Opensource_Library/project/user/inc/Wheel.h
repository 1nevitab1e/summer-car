/*
 * Wheel.h
 *
 *  Created on: 2023Äê7ÔÂ12ÈÕ
 *      Author: 86131
 */

#ifndef WHEEL_H_
#define WHEEL_H_

#define m8 TIM5_PWM_MAP0_CH4_A3
#define m7 TIM5_PWM_MAP0_CH3_A2
#define m6 TIM5_PWM_MAP0_CH2_A1
#define m5 TIM5_PWM_MAP0_CH1_A0
#define m4 TIM4_PWM_MAP1_CH1_D12
#define m3 TIM4_PWM_MAP1_CH2_D13
#define m2 TIM4_PWM_MAP1_CH3_D14
#define m1 TIM4_PWM_MAP1_CH4_D15

#include "zf_common_headfile.h"

void Wheel_Init();


#endif /* WHEEL_H_ */

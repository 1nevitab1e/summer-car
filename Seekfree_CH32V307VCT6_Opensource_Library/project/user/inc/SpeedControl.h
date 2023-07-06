/*
 * SpeedControl.h
 *
 *  Created on: 2023Äê4ÔÂ28ÈÕ
 *      Author: 86131
 */

#ifndef SPEEDCONTROL_H_
#define SPEEDCONTROL_H_

#include "zf_common_headfile.h"


void Wave_Dis(u16 A);
void Encoder_Init();
uint16_t Get_Encoder();
void PID_Init();
int16_t PID_Inc();

#endif /* SPEEDCONTROL_H_ */

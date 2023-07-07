/*
 * Filter.c
 *
 *  Created on: 2023Äê7ÔÂ7ÈÕ
 *      Author: 86131
 */

#include "Filter.h"

u16 Filter(int16 angle ,int16 gyro ,int16 acc)
{
    float angle_o;

        angle_o=K*acc+(1.0-K)*(angle+dt*gyro);


    return (int16)angle_o;
}

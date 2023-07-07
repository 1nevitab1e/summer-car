/*
 * Filter.c
 *
 *  Created on: 2023Äê7ÔÂ7ÈÕ
 *      Author: 86131
 */

#include "Filter.h"

u16 Filter(u16 angle ,u16 gyro ,u16 acc)
{
    float angle_o;

        angle_o=K*acc+(1.0-K)*(angle+dt*gyro);


    return (u16)angle_o;
}

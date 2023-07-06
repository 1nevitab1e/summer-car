/*
 * Feed.c
 *
 *  Created on: 2023Äê7ÔÂ6ÈÕ
 *      Author: 86131
 */

#include"Feed.h"


void HaveDog()
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(IWDG_Prescaler_64);
    IWDG_SetReload(625);
    IWDG_ReloadCounter();
    IWDG_Enable();
}

void FeedDog()
{
    IWDG_ReloadCounter();
}

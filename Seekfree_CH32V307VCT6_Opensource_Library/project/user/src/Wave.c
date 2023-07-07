/*
 * Wave.c
 *
 *  Created on: 2023Äê7ÔÂ7ÈÕ
 *      Author: 86131
 */
#include "Wave.h"

void WaveSend(u8 n,u16 *Data)
{
    u8 i,cnt=0;
    u8 DataBuff[2*n+6];
    u8 sumcheck=0,addcheck=0;

    DataBuff[cnt++]=0xAA;
    DataBuff[cnt++]=0xFF;
    DataBuff[cnt++]=0xF1;
    DataBuff[cnt++]=2*n;

    for (i = 0; i < n; ++i)
    {
        DataBuff[cnt++] = BYTE0(Data[i]);
        DataBuff[cnt++] = BYTE1(Data[i]);
    }

    for(i = 0; i < cnt; i++)
    {
        sumcheck += DataBuff[i];
        addcheck += sumcheck;
    }

    DataBuff[cnt++]=sumcheck;
    DataBuff[cnt++]=addcheck;

    uart_write_buffer(UART_3, DataBuff, 2*n+6);
}

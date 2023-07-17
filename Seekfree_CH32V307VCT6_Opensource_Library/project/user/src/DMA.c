/*
 * DMA.c
 *
 *  Created on: 2023Äê7ÔÂ15ÈÕ
 *      Author: 86131
 */

#include "DMA.h"

extern u32 Buffer[120];

void MyDma()
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2,ENABLE);
    DMA_InitTypeDef MyDma;
    MyDma.DMA_MemoryBaseAddr=Buffer;
    MyDma.DMA_PeripheralBaseAddr=&(UART7->DATAR);
    MyDma.DMA_DIR=DMA_DIR_PeripheralSRC;
    MyDma.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    MyDma.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
    MyDma.DMA_BufferSize=10;
    MyDma.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
    MyDma.DMA_MemoryInc=DMA_MemoryInc_Enable;
    MyDma.DMA_Mode = DMA_Mode_Normal;
    MyDma.DMA_Priority=DMA_Priority_VeryHigh;

    DMA_Init(DMA2_Channel9, &MyDma);
    DMA_ITConfig(DMA2_Channel9,DMA_IT_TC,ENABLE);
    NVIC_SetPriority(DMA2_Channel9_IRQn,0);
    NVIC_EnableIRQ(DMA2_Channel9_IRQn);
    DMA_Cmd(DMA2_Channel9,ENABLE);
    USART_DMACmd(UART7,USART_DMAReq_Rx,ENABLE);
}

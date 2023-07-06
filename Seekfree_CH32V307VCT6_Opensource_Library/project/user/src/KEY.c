/*
 * KEY.c
 *
 *  Created on: 2023年3月24日
 *      Author: 86131
 */

#include "zf_common_headfile.h"

#define SW E0
#define VRY ADC_IN3_A3
#define Up 17
#define Down 18

int16 AdcConvert;

void KEY_Init()
{
    gpio_init(C2, GPI, GPIO_HIGH, GPI_PULL_UP);
    gpio_init(C1, GPI, GPIO_HIGH, GPI_PULL_UP);
    gpio_init(C3, GPI, GPIO_HIGH, GPI_PULL_UP);
    gpio_init(C4, GPI, GPIO_HIGH, GPI_PULL_UP);
}

int Key_Get()
{
    int i=0;

    if(gpio_get_level(C2) == 0)
        {
            system_delay_ms(10);
            while(gpio_get_level(C2) == 0);
            system_delay_ms(10);
            i=1;
        }
    if(gpio_get_level(C1) == 0)
        {
            system_delay_ms(10);
            while(gpio_get_level(C1) == 0);
            system_delay_ms(10);
            i=2;
        }
    if(gpio_get_level(C3) == 0)
        {
            system_delay_ms(10);
            while(gpio_get_level(C3) == 0);
            system_delay_ms(10);
            i=3;
        }
    if(gpio_get_level(C4) == 0)
        {
            system_delay_ms(10);
            while(gpio_get_level(C4) == 0);
            system_delay_ms(10);
            i=4;
        }
    return i;
}

void Key_S_Init(void)
{
    adc_init(VRY);
//    DMA_InitTypeDef DMA_InitStructure;
//
//    /* DMA channel1 configuration */
//        DMA_DeInit(DMA1_Channel1);
//        DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;     //ADC地址
//        DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue;//内存地址
//        DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
//        DMA_InitStructure.DMA_BufferSize = 2;
//        DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设地址固定
//        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  //内存地址固定
//        DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;    //半字
//        DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
//        DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;        //循环传输
//        DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//        DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
//        DMA_Init(DMA1_Channel1, &DMA_InitStructure);
//
//        /* Enable DMA channel1 */
//        DMA_Cmd(DMA1_Channel1, ENABLE);
}

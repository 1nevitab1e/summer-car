/*
 * simu_spi.c
 *
 *  Created on: 2023年4月12日
 *      Author: 86131
 */
#include "simu_spi.h"

void simu_spi_w_mosi(uint8 bit)
{
    gpio_set_level(simu_spi_MOSI,(BitAction)bit);
}

void simu_spi_w_sck(uint8 bit)
{
    gpio_set_level(simu_spi_SCK,(BitAction)bit);
}

void simu_spi_w_cs(uint8 bit)
{
    gpio_set_level(simu_spi_CS,(BitAction)bit);
}

uint8 simu_spi_r_miso(void)
{
    return gpio_get_level(simu_spi_MISO);
}

//sck低电平，第一个时钟边沿采集

void simu_spi_gpio_init()
{
    gpio_init(simu_spi_MOSI, GPO, 0, GPO_PUSH_PULL);
    gpio_init(simu_spi_MISO, GPI, 0, GPI_FLOATING_IN);
    gpio_init(simu_spi_CS, GPO, 1, GPO_PUSH_PULL);
    gpio_init(simu_spi_SCK, GPO, 0, GPO_PUSH_PULL);
    //gpio_init(simu_spi_MOSI, GPO, 0, GPO_PUSH_PULL);

    simu_spi_w_cs(1);
    simu_spi_w_sck(0);
}

void simu_spi_start()
{
    simu_spi_w_cs(0);
}

void simu_spi_stop()
{
    simu_spi_w_cs(1);
}

uint8 simu_spi_swapbyte(uint8 ByteSend)
{
    uint8 i;

    for(i=0;i<8;i++)
    {
        simu_spi_w_mosi(ByteSend & 0x80);
        ByteSend <<= 1;
        simu_spi_w_sck(1);

        if(simu_spi_r_miso()==1)
        {
            ByteSend |= 0x01;
        }

        simu_spi_w_sck(0);
    }
    return ByteSend;
}

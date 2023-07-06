/*
 * DS18B20.c
 *
 *  Created on: 2023Äê5ÔÂ13ÈÕ
 *      Author: 86131
 */

#include "DS18B20.h"

#define OneWire_DQ A1

#define SkipRom 0xcc
#define Convert_T 0x44
#define ScratchPad 0xbe

/*OneWire*/

u8 OneWire_Init()
{
    u8 ACKBIT;
    gpio_init(OneWire_DQ, GPO, 1, GPO_PUSH_PULL);
    gpio_set_level(OneWire_DQ, 1);
    system_delay_us(20);
    gpio_set_level(OneWire_DQ, 0);
    system_delay_us(480);
    gpio_set_level(OneWire_DQ, 1);
    system_delay_us(50);
    ACKBIT=gpio_get_level(OneWire_DQ);
    system_delay_us(240);
    return ACKBIT;
}

void OneWire_SendBit(u8 Bit)
{
    gpio_set_level(OneWire_DQ, 0);
    system_delay_us(10);
    gpio_set_level(OneWire_DQ, Bit);
    system_delay_us(50);
    gpio_set_level(OneWire_DQ, 1);
}

u8 OneWire_ReceiveBit()
{
    u8 Bit;
    gpio_init(OneWire_DQ, GPO, 0, GPO_PUSH_PULL);
    gpio_set_level(OneWire_DQ, 0);
    system_delay_us(5);
    gpio_set_level(OneWire_DQ, 1);
    gpio_init(OneWire_DQ,GPI,1,GPI_PULL_UP);
    system_delay_us(5);
    Bit=gpio_get_level(OneWire_DQ);
    system_delay_us(50);
    return Bit;
}

void OneWire_SendByte(u8 Byte)
{
  u8 i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(Byte&(0x01<<i));
    }

}

u8 OneWire_ReceiveByte()
{
    u8 Byte=0x00;
    u8 i;
    for(i=0;i<8;i++)
    {
        if(OneWire_ReceiveBit())
        {
            Byte|=(0x01<<i);
        }
    }
    return Byte;
}

/*DS18B20*/

void DS18B20_Convert_T()
{
    OneWire_Init();
    OneWire_SendByte(SkipRom);
    OneWire_SendByte(Convert_T);
}

float DS18B20_ReadT()
{
    u8 TLSB,TMSB;
    u16 temp;
    float T;

    OneWire_Init();
    OneWire_SendByte(SkipRom);
    OneWire_SendByte(ScratchPad);
    TLSB=OneWire_ReceiveByte();
    TMSB=OneWire_ReceiveByte();
    temp=(TMSB<<8)|TLSB;
    T=temp/16.0;

    return T;
}


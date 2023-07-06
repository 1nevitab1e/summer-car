/*
 * SD.c
 *
 *  Created on: 2023年7月6日
 *      Author: 86131
 */

#include "SD.h"

/*
函数功能：SD卡底层接口,通过SPI时序向SD卡读写一个字节
函数参数：data是要写入的数据
返 回 值：读到的数据
*/
u8 SDCardReadWriteOneByte(u8 DataTx)
{
    u8 i;
    u8 data=0;
    for(i=0;i<8;i++)
    {
        gpio_set_level(SCK, 0);
        //system_delay_us(6);
        if(DataTx&0x80)gpio_set_level(MOSI, 1);
        else gpio_set_level(MOSI,0);
        gpio_set_level(SCK, 1);
        //system_delay_us(6);
        DataTx<<=1;

        data<<=1;
        if(gpio_get_level(MISO))data|=0x01;
    }
    return data;
}

/*
函数功能：向SD卡发送一个命令
函数参数：
                u8 cmd   命令
                u32 arg  命令参数
                u8 crc   crc校验值
返回值:SD卡返回的响应
*/
u8 SendSDCardCmd(u8 cmd, u32 arg, u8 crc)
{
    u8 r1;
    u8 wait=0xff;
    gpio_set_level(CS, 1);
    SDCardReadWriteOneByte(0xFF);
    gpio_set_level(CS, 0);
    while ((SDCardReadWriteOneByte(0xFF)!=0xFF)&&wait)
    {
        wait--;
    }
    if(wait == 0)
    {
        wait=0xff;
        oled_show_int(0, 0, wait, 3);
    }

    SDCardReadWriteOneByte(cmd | 0x40);//分别写入命令
    SDCardReadWriteOneByte(arg >> 24);
    SDCardReadWriteOneByte(arg >> 16);
    SDCardReadWriteOneByte(arg >> 8);
    SDCardReadWriteOneByte(arg);
    SDCardReadWriteOneByte(crc);

    if(cmd==SDCard_CMD12)SDCardReadWriteOneByte(0xff);//Skip a stuff byte when stop reading
    do
    {
        r1=SDCardReadWriteOneByte(0xFF);
        wait--;
    }while((r1&0x80) && wait);      //等待响应，或超时退出

//    oled_show_int(0, 0, r1, 3);
    return r1;
}

/*
函数功能： 初始化SD卡
返 回 值： 成功0；失败1
*/
u8 SD_Init()
{
    u8 r1=0;      // 存放SD卡的返回值
    u8 data;
    u16 i;

    gpio_init(MISO, GPI, 1, GPI_PULL_UP);
    gpio_init(MOSI, GPO, 1, GPO_PUSH_PULL);
    gpio_init(CS, GPO, 1, GPO_PUSH_PULL);
    gpio_init(SCK, GPO, 1, GPO_PUSH_PULL);

    for(i=0;i<10;i++)SDCardReadWriteOneByte(0xFF);

    do
    {
        r1=SendSDCardCmd(SDCard_CMD0,0,0x95);
    }while(r1!=0x01);

    if(SendSDCardCmd(SDCard_CMD8,0x1AA,0x87)==0x01)
        {
                do
                {
                    SendSDCardCmd(SDCard_CMD55,0,0x01);     //发送SDCard_CMD55
                    r1=SendSDCardCmd(SDCard_CMD41,0x40000000,0x01);//发送SDCard_CMD41
                }while(r1);

                if(SendSDCardCmd(SDCard_CMD58,0,0x01)==0)//鉴别SD2.0卡版本开始
                {
                    data=SDCardReadWriteOneByte(0xFF);//得到OCR值
                    if(data&0x40)
                    {
                            r1=0; //高速卡
                    }
                }
        }

    gpio_set_level(CS,1);//取消片选
    SDCardReadWriteOneByte(0xff);//提供额外的8个时钟
    return r1;          //其他错误

}

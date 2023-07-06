/*
 * SD.c
 *
 *  Created on: 2023��7��6��
 *      Author: 86131
 */

#include "SD.h"

/*
�������ܣ�SD���ײ�ӿ�,ͨ��SPIʱ����SD����дһ���ֽ�
����������data��Ҫд�������
�� �� ֵ������������
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
�������ܣ���SD������һ������
����������
                u8 cmd   ����
                u32 arg  �������
                u8 crc   crcУ��ֵ
����ֵ:SD�����ص���Ӧ
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

    SDCardReadWriteOneByte(cmd | 0x40);//�ֱ�д������
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
    }while((r1&0x80) && wait);      //�ȴ���Ӧ����ʱ�˳�

//    oled_show_int(0, 0, r1, 3);
    return r1;
}

/*
�������ܣ� ��ʼ��SD��
�� �� ֵ�� �ɹ�0��ʧ��1
*/
u8 SD_Init()
{
    u8 r1=0;      // ���SD���ķ���ֵ
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
                    SendSDCardCmd(SDCard_CMD55,0,0x01);     //����SDCard_CMD55
                    r1=SendSDCardCmd(SDCard_CMD41,0x40000000,0x01);//����SDCard_CMD41
                }while(r1);

                if(SendSDCardCmd(SDCard_CMD58,0,0x01)==0)//����SD2.0���汾��ʼ
                {
                    data=SDCardReadWriteOneByte(0xFF);//�õ�OCRֵ
                    if(data&0x40)
                    {
                            r1=0; //���ٿ�
                    }
                }
        }

    gpio_set_level(CS,1);//ȡ��Ƭѡ
    SDCardReadWriteOneByte(0xff);//�ṩ�����8��ʱ��
    return r1;          //��������

}

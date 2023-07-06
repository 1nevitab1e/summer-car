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
void SD_SPI_GPIO_Init()
{
    gpio_init(MISO, GPI, 0, GPI_PULL_UP);
    gpio_init(MOSI, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(CS, GPO, 1, GPIO_PIN_CONFIG);
    gpio_init(SCK, GPO, 0, GPIO_PIN_CONFIG);
}

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
�� �� ֵ�� �ɹ� 0��ʧ�� ��0
*/
u8 SD_Init()
{
    u8 r1=1;      // ���SD���ķ���ֵ
    u8 data;
    u16 i;
    u8 wait=200;

    SD_SPI_GPIO_Init();

    for(i=0;i<10;i++)SDCardReadWriteOneByte(0xFF);

    do
    {
        r1=SendSDCardCmd(SDCard_CMD0,0,0x95);
    }while(r1!=0x01&&wait--);

    if(SendSDCardCmd(SDCard_CMD8,0x1AA,0x87)==0x01)
        {
            wait=200;
                do
                {
                    SendSDCardCmd(SDCard_CMD55,0,0x01);     //����SDCard_CMD55
                    r1=SendSDCardCmd(SDCard_CMD41,0x40000000,0x01);//����SDCard_CMD41
                }while(r1&&wait--);
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

/*
�������ܣ���sd����ȡһ�����ݰ���16�ֽڣ�������
����������
                buf:���ݻ�����
                len:Ҫ��ȡ�����ݳ���.
����ֵ��
            0,�ɹ�;����,ʧ��;
*/
u8 SDCardRecvData(u8*buf,u16 len)
{
        while(SDCardReadWriteOneByte(0xFF)!=0xFE){}//�ȴ�SD������������ʼ����0xFE
    while(len--)//��ʼ��������
    {
        *buf=SDCardReadWriteOneByte(0xFF);
        buf++;
    }
    //������2��αCRC��dummy CRC��
    SDCardReadWriteOneByte(0xFF);
    SDCardReadWriteOneByte(0xFF);
    return 0;//��ȡ�ɹ�
}

/*
�������ܣ���sd��д��һ�����ݰ������� 512�ֽ�
����������
                    buf ���ݻ�����
                    cmd ָ��
�� �� ֵ��0��ʾ�ɹ�;����ֵ��ʾʧ��;
*/
u8 SDCardSendData(u8*buf,u8 cmd)
{
    u16 t;
        while(SDCardReadWriteOneByte(0xFF)!=0xFF){}  //�ȴ�æ״̬
        SDCardReadWriteOneByte(cmd);
        if(cmd!=0xFD)//���ǽ���ָ��
        {
              for(t=0;t<512;t++)SDCardReadWriteOneByte(buf[t]);//����ٶ�,���ٺ�������ʱ��
            SDCardReadWriteOneByte(0xFF); //����crc
            SDCardReadWriteOneByte(0xFF);
              SDCardReadWriteOneByte(0xFF); //������Ӧ
        }
      return 0;//д��ɹ�
}

/*
�������ܣ���ȡSD����������������������
�� �� ֵ��
                0��ʾ��������������ֵ��ʾSD��������(������/512�ֽ�)
˵   ����
                ÿ�������ֽ�����Ϊ512�ֽڣ��������512�ֽڣ����ʼ������ͨ��.
*/
u32 GetSDCardSectorCount(void)
{
    u8 csd[16];
    u32 Capacity=0;
      u16 csize;
        //��ȡSD����CSD��Ϣ�������������ٶ���Ϣ,���CID���ڴ�,����16Byte
        SendSDCardCmd(SDCard_CMD9,0,0x01);//��SDCard_CMD9�����CSD
      SDCardRecvData(csd,16);//����16���ֽڵ�����

        gpio_set_level(CS,1);//ȡ��Ƭѡ
        SDCardReadWriteOneByte(0xff);//�ṩ�����8��ʱ��
    if((csd[0]&0xC0)==0x40)  //SDHC�����������淽ʽ����
    {
            csize=csd[9]+(csd[8]<<8)+1;
            Capacity=csize<<10;//�õ�������
    }
    return Capacity;
}

/*
�������ܣ���SD��
����������
                buf:���ݻ�����
                sector:����
                cnt:������
˵  ����
                SD��һ��������С512�ֽ�
*/
void SDCardReadData(u8*buf,u32 sector,u32 cnt)
{
    u32 i=0;
    if(cnt==1)
    {
        SendSDCardCmd(SDCard_CMD17,sector,0x01);//������
        SDCardRecvData(buf,512);            //����512���ֽ�
    }
    else
    {
        SendSDCardCmd(SDCard_CMD18,sector,0x01);//����������
        for(i=0;i<cnt;i++)
        {
            SDCardRecvData(buf,512);//����512���ֽ�
            buf+=512;
        }
        SendSDCardCmd(SDCard_CMD12,0,0x01); //ֹͣ���ݴ���
    }
    gpio_set_level(CS,1);//ȡ��Ƭѡ
    SDCardReadWriteOneByte(0xff);//�ṩ�����8��ʱ��();
}


/*
�������ܣ���SD��д����
����������
                buf:���ݻ�����
                sector:��ʼ����
                cnt:������
˵  ����
                SD��һ��������С512�ֽ�
*/
void SDCardWriteData(u8*buf,u32 sector,u32 cnt)
{
    u32 i=0;
    if(cnt==1)
    {
        SendSDCardCmd(SDCard_CMD24,sector,0x01);//д��������
        SDCardSendData(buf,0xFE);//д512���ֽ�
    }
    else
    {
        SendSDCardCmd(SDCard_CMD55,0,0x01);
        SendSDCardCmd(SDCard_CMD23,cnt,0x01);   //���ö�����д��ǰԤ�Ȳ���N��block
        SendSDCardCmd(SDCard_CMD25,sector,0x01);//д�������
        for(i=0;i<cnt;i++)
        {
            SDCardSendData(buf,0xFC);//д512���ֽ�
            buf+=512;
        }
        SDCardSendData(0,0xFD);//д����ָ��
    }
    gpio_set_level(CS,1);//ȡ��Ƭѡ
    SDCardReadWriteOneByte(0xff);//�ṩ�����8��ʱ��
}

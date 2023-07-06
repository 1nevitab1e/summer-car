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
返 回 值： 成功 0；失败 非0
*/
u8 SD_Init()
{
    u8 r1=1;      // 存放SD卡的返回值
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
                    SendSDCardCmd(SDCard_CMD55,0,0x01);     //发送SDCard_CMD55
                    r1=SendSDCardCmd(SDCard_CMD41,0x40000000,0x01);//发送SDCard_CMD41
                }while(r1&&wait--);
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

/*
函数功能：从sd卡读取一个数据包（16字节）的内容
函数参数：
                buf:数据缓存区
                len:要读取的数据长度.
返回值：
            0,成功;其他,失败;
*/
u8 SDCardRecvData(u8*buf,u16 len)
{
        while(SDCardReadWriteOneByte(0xFF)!=0xFE){}//等待SD卡发回数据起始令牌0xFE
    while(len--)//开始接收数据
    {
        *buf=SDCardReadWriteOneByte(0xFF);
        buf++;
    }
    //下面是2个伪CRC（dummy CRC）
    SDCardReadWriteOneByte(0xFF);
    SDCardReadWriteOneByte(0xFF);
    return 0;//读取成功
}

/*
函数功能：向sd卡写入一个数据包的内容 512字节
函数参数：
                    buf 数据缓存区
                    cmd 指令
返 回 值：0表示成功;其他值表示失败;
*/
u8 SDCardSendData(u8*buf,u8 cmd)
{
    u16 t;
        while(SDCardReadWriteOneByte(0xFF)!=0xFF){}  //等待忙状态
        SDCardReadWriteOneByte(cmd);
        if(cmd!=0xFD)//不是结束指令
        {
              for(t=0;t<512;t++)SDCardReadWriteOneByte(buf[t]);//提高速度,减少函数传参时间
            SDCardReadWriteOneByte(0xFF); //忽略crc
            SDCardReadWriteOneByte(0xFF);
              SDCardReadWriteOneByte(0xFF); //接收响应
        }
      return 0;//写入成功
}

/*
函数功能：获取SD卡的总扇区数（扇区数）
返 回 值：
                0表示容量检测出错，其他值表示SD卡的容量(扇区数/512字节)
说   明：
                每扇区的字节数必为512字节，如果不是512字节，则初始化不能通过.
*/
u32 GetSDCardSectorCount(void)
{
    u8 csd[16];
    u32 Capacity=0;
      u16 csize;
        //获取SD卡的CSD信息，包括容量和速度信息,存放CID的内存,至少16Byte
        SendSDCardCmd(SDCard_CMD9,0,0x01);//发SDCard_CMD9命令，读CSD
      SDCardRecvData(csd,16);//接收16个字节的数据

        gpio_set_level(CS,1);//取消片选
        SDCardReadWriteOneByte(0xff);//提供额外的8个时钟
    if((csd[0]&0xC0)==0x40)  //SDHC卡，按照下面方式计算
    {
            csize=csd[9]+(csd[8]<<8)+1;
            Capacity=csize<<10;//得到扇区数
    }
    return Capacity;
}

/*
函数功能：读SD卡
函数参数：
                buf:数据缓存区
                sector:扇区
                cnt:扇区数
说  明：
                SD卡一个扇区大小512字节
*/
void SDCardReadData(u8*buf,u32 sector,u32 cnt)
{
    u32 i=0;
    if(cnt==1)
    {
        SendSDCardCmd(SDCard_CMD17,sector,0x01);//读扇区
        SDCardRecvData(buf,512);            //接收512个字节
    }
    else
    {
        SendSDCardCmd(SDCard_CMD18,sector,0x01);//连续读命令
        for(i=0;i<cnt;i++)
        {
            SDCardRecvData(buf,512);//接收512个字节
            buf+=512;
        }
        SendSDCardCmd(SDCard_CMD12,0,0x01); //停止数据传输
    }
    gpio_set_level(CS,1);//取消片选
    SDCardReadWriteOneByte(0xff);//提供额外的8个时钟();
}


/*
函数功能：向SD卡写数据
函数参数：
                buf:数据缓存区
                sector:起始扇区
                cnt:扇区数
说  明：
                SD卡一个扇区大小512字节
*/
void SDCardWriteData(u8*buf,u32 sector,u32 cnt)
{
    u32 i=0;
    if(cnt==1)
    {
        SendSDCardCmd(SDCard_CMD24,sector,0x01);//写单个扇区
        SDCardSendData(buf,0xFE);//写512个字节
    }
    else
    {
        SendSDCardCmd(SDCard_CMD55,0,0x01);
        SendSDCardCmd(SDCard_CMD23,cnt,0x01);   //设置多扇区写入前预先擦除N个block
        SendSDCardCmd(SDCard_CMD25,sector,0x01);//写多个扇区
        for(i=0;i<cnt;i++)
        {
            SDCardSendData(buf,0xFC);//写512个字节
            buf+=512;
        }
        SDCardSendData(0,0xFD);//写结束指令
    }
    gpio_set_level(CS,1);//取消片选
    SDCardReadWriteOneByte(0xff);//提供额外的8个时钟
}

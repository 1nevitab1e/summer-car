/*
 * my_sd_card.c
 *
 *  Created on: 2021��11��29��
 *      Author: hxy
 */


#include "zf_common_headfile.h"
#include "my_sd_card.h"

uint8 SD_Type = 1;
//SPIx����֮��ע����
void SPI_CS_HIGH(void)
{
    gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);
}
//�ȴ���׼����
//����ֵ:0,׼������;����,�������
static uint8 SdWaitReady(void)
{
    uint32 t=0;
    do
    {
        if(sd_spiReadWrite(0XFF)==0XFF)return 0;//OK
        t++;
    }while(t<0XFFFFFF);//�ȴ�
    return 1;
}

//���õ�����ģʽ  ���ڳ�ʼ�������spi�ٶ�Ϊ400k
void SdSpiSpeedLow(void)
{
    spi_init(SD_SPI_NUM, SPI_MODE0, 300000 , SD_SCLK, SD_MOSI, SD_MISO, SD_CS);
}

//SD������������ʱ��,���Ը�����
static void SdSpiSpeedHigh(void)
{
    spi_init(SD_SPI_NUM, SPI_MODE0, 10000000 , SD_SCLK, SD_MOSI, SD_MISO, SD_CS);
}

//ȡ��ѡ��,�ͷ�SPI����  �ڲ�����
void SD_DisSelect(void)
{
    gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);
    sd_spiReadWrite(0xff);//�ṩ�����8��ʱ��
}

//��д����
uint8 sd_spiReadWrite(uint8 data)
{
    uint8 res = 0;
    spi_transfer_8bit(SD_SPI_NUM, (uint8*)&data, &res, 1);
    return res;
}

//ѡ��sd��,���ҵȴ���׼��OK   ����ֵ:0,�ɹ�;1,ʧ��       �ڲ�ʹ��
uint8 SdSelect(void)
{
    gpio_low(SD_CS);//SPI_CSInternalSelected(SPI2, ENABLE);
    if(SdWaitReady()==0)return 0;//�ȴ��ɹ�
    SD_DisSelect();
    return 1;//�ȴ�ʧ��
}

//�ȴ�SD����Ӧ Response:Ҫ�õ��Ļ�Ӧֵ
//����ֵ:0,�ɹ��õ��˸û�Ӧֵ
//����,�õ���Ӧֵʧ��    �ڴ��õ��Ļ�Ӧֵ
SDHCRES SdGetResponse(uint8 Response)
{
    uint16 Count=0xFFF;//�ȴ�����
    while ((sd_spiReadWrite(0XFF)!=Response)&&Count)Count--;//�ȴ��õ�׼ȷ�Ļ�Ӧ
    if (Count==0)return MSD_RESPONSE_FAILURE;//�õ���Ӧʧ��
    else return MSD_RESPONSE_NO_ERROR;//��ȷ��Ӧ
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������
//  param       cmd ����
//  param       arg �������
//  param       crc У��ֵ
//  @return     ״̬
//  @since      v1.0
//  Sample usage:       �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
SDHCRES sd_sendcmd(uint8 cmd, uint32 arg, uint8 crc)
{
    uint8 r1;
    uint8 Retry=0;
    SD_DisSelect();//ȡ���ϴ�Ƭѡ
    if(SdSelect())return 0XFF;//ƬѡʧЧ
    //����
    sd_spiReadWrite(cmd | 0x40);//�ֱ�д������
    sd_spiReadWrite((arg >> 24) & 0xFF);
    sd_spiReadWrite((uint8)(arg >> 16) & 0xFF);
    sd_spiReadWrite((uint8)(arg >> 8) & 0xFF);
    sd_spiReadWrite((uint8)(arg) & 0xFF);
    sd_spiReadWrite(crc);
    if(cmd==CMD12)sd_spiReadWrite(0xff);//Skip a stuff uint8 when stop reading
    //�ȴ���Ӧ����ʱ�˳�
    Retry=0X1F;
    do
    {
        r1=sd_spiReadWrite(0xFF);//��ȡ������Ϣ
    }while((r1&0X80) && Retry--);//��ʱ������������ ��ȷ���ش�����Ϣ    ��λ����0
    //����״ֵ̬
    return r1;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʼ��
//  @return     ״̬
//  @since      v1.0
//  Sample usage:       �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
uint8 sd_init(void)
{
  uint8 r1 = 0;
  uint8 buf[4];
  uint16 i=0;
  SdSpiSpeedLow();//�����õ���
  for(i=0;i<10;i++)   sd_spiReadWrite(0xff);

  uint16 retry=20;
  do
  {
      r1=sd_sendcmd(CMD0,0,0x95);//����IDLE״̬
  }while((r1!=0X01) && retry--);
  SD_Type=0;//Ĭ���޿�
if(r1==0X01)
  {
          if(sd_sendcmd(CMD8,0x1AA,0x87)==1)//SD V2.0
          {
                  for(i=0;i<4;i++)    buf[i]=sd_spiReadWrite(0XFF);   //Get trailing return value of R7 resp
                  if(buf[2]==0X01&&buf[3]==0XAA)//���Ƿ�֧��2.7~3.6V
                  {
                          retry=0XFFFE;
                          do
                          {
                                  sd_sendcmd(CMD55,0,0X01);   //����CMD55
                                  r1=sd_sendcmd(CMD41,0x40000000,0X01);//����CMD41
                          }while(r1&&retry--);
                          if(retry&&sd_sendcmd(CMD58,0,0X01)==0)//����SD2.0���汾��ʼ
                          {
                                  for(i=0;i<4;i++)buf[i]=sd_spiReadWrite(0XFF);//�õ�OCRֵ
                                  if(buf[0]&0x40)SD_Type=SD_TYPE_V2HC;    //���CCS
                                  else SD_Type=SD_TYPE_V2;
                          }
                  }
          }else//SD V1.x/ MMC V3
          {
                  sd_sendcmd(CMD55,0,0X01);       //����CMD55
                  r1=sd_sendcmd(CMD41,0,0X01);    //����CMD41
                  if(r1<=1)
                  {
                          SD_Type=SD_TYPE_V1;
                          retry=0XFFFE;
                          do //�ȴ��˳�IDLEģʽ
                          {
                                  sd_sendcmd(CMD55,0,0X01);   //����CMD55
                                  r1=sd_sendcmd(CMD41,0,0X01);//����CMD41
                          }while(r1&&retry--);
                  }else
                  {
                          SD_Type=SD_TYPE_MMC;//MMC V3
                          retry=0XFFFE;
                          do //�ȴ��˳�IDLEģʽ
                          {
                                  r1=sd_sendcmd(CMD1,0,0X01);//����CMD1
                          }while(r1&&retry--);
                  }
                  if(retry==0||sd_sendcmd(CMD16,512,0X01)!=0)SD_Type=SD_TYPE_ERR;//����Ŀ�
          }
  }
      SD_DisSelect();//ȡ��Ƭѡ
      SdSpiSpeedHigh();//����
//        spi_init(SD_SPI_NUM, SD_SCLK, SD_MOSI, SD_MISO, SD_CS, 0, 20*100*100);
      if(SD_Type)return MSD_RESPONSE_NO_ERROR;
      else if(r1)return r1;
      return MSD_RESPONSE_FAILURE;//��������
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      д��512���ֽ�
//  @param      ������
//  @param      ָ��
//  @return     0 �ɹ�        else ʧ��
//  @since      v1.0
//  Sample usage:       �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
uint8 sd_SendBlockData(uint8 *buf, uint8 cmd)
{
    uint16 t;
    if(SdWaitReady())return 1;//�ȴ�׼��ʧЧ
    sd_spiReadWrite(cmd);
    if(cmd!=0XFD)//���ǽ���ָ��
    {
        for(t=0;t<512;t++, buf++)
        {
            sd_spiReadWrite(*buf);
//          if (!buf)
//          {
//              sd_spiReadWrite(*buf);//����ٶ�,���ٺ�������ʱ��
//              buf++;
//          }
//          else    sd_spiReadWrite(0xFF);
        }
        sd_spiReadWrite(0xff);//����crc
        sd_spiReadWrite(0xff);
        t=sd_spiReadWrite(0xFF);//������Ӧ
        if((t&0x1F)!=0x05)  return 2;//��Ӧ����
    }
    return 0;//д��ɹ�
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡ����
//  @param      ������
//  @param      ����
//  @return     0 �ɹ�        else ʧ��
//  @since      v1.0
//  Sample usage:       �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
SDHCRES sd_ReceiveData(uint8 *buf,uint16 len)
{
    if(SdGetResponse(0xFE)) return 1;//�ȴ�SD������������ʼ����0xFE
    while(len--)//��ʼ��������
    {
        *buf=sd_spiReadWrite(0xFF);
//        printf("%d\n", *buf);
        buf++;
    }
    //������2��αCRC��dummy CRC��
    sd_spiReadWrite(0xFF);
    sd_spiReadWrite(0xFF);
    return MSD_RESPONSE_NO_ERROR;//��ȡ�ɹ�
}


//��ȡSD����CID��Ϣ��������������Ϣ
//����: u8 *cid_data(���CID���ڴ棬����16uint8��
//����ֵ:0��NO_ERR
//       1������
uint8 SdGetCID(uint8 *cid_data)
{
    uint8 r1;
    //��CMD10�����CID
    r1=sd_sendcmd(CMD10,0,0x01);
    if(r1==0x00)
    {
        r1=sd_ReceiveData(cid_data,16);//����16���ֽڵ�����
    }
    SD_DisSelect();//ȡ��Ƭѡ
    if(r1)return 1;
    else return 0;
}

//��ȡSD����CSD��Ϣ�������������ٶ���Ϣ
//����:u8 *cid_data(���CID���ڴ棬����16uint8��
//����ֵ:0��NO_ERR
//       1������
uint8 SdGetCSD(uint8 *csd_data)
{
    uint8 r1;
    r1=sd_sendcmd(CMD9,0,0x01);//��CMD9�����CSD
    if(r1==0)
    {
        r1=sd_ReceiveData(csd_data, 16);//����16���ֽڵ�����
    }
    SD_DisSelect();//ȡ��Ƭѡ
    if(r1)return 1;
    else return 0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡSD����������������������
//  @return     0 ����        else ������
//  @since      v1.0
//  Sample usage:       �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
uint32 sd_GetSectorCount(void)
{
    uint8 csd[16];
    uint32 Capacity;
    uint8 n;
    uint16 csize;
    //ȡCSD��Ϣ������ڼ��������0
    if(SdGetCSD(csd)!=0) return 0;
    //���ΪSDHC�����������淽ʽ����
    if((csd[0]&0xC0)==0x40)  //V2.00�Ŀ�
    {
        csize = csd[9] + ((uint16)csd[8] << 8) + 1;
        Capacity = (uint32)csize << 10;//�õ�������
    }else//V1.XX�Ŀ�
    {
        n = (csd[5] & 15) + ((csd[10] & 128) >> 7) + ((csd[9] & 3) << 1) + 2;
        csize = (csd[8] >> 6) + ((uint16)csd[7] << 2) + ((uint16)(csd[6] & 3) << 10) + 1;
        Capacity= (uint32)csize << (n - 9);//�õ�������
    }
    return Capacity;
}

//��SD��
//buf:���ݻ�����
//sector:����
//cnt:������
//����ֵ:0,ok;����,ʧ��.
SDHCRES sd_ReadDisk(uint8 *buf,uint32 sector,uint8 cnt)
{
    uint8 r1;
    if(SD_Type!=SD_TYPE_V2HC)sector <<= 9;//ת��Ϊ�ֽڵ�ַ
    if(cnt==1)
    {
        r1=sd_sendcmd(CMD17,sector,0X01);//������
        if(r1==0)//ָ��ͳɹ�
        {
            r1=sd_ReceiveData(buf,512);//����512���ֽ�
        }
    }else
    {
        r1=sd_sendcmd(CMD18,sector,0X01);//����������
        do
        {
            r1=sd_ReceiveData(buf,512);//����512���ֽ�
            buf+=512;
        }while(--cnt && r1==0);
        sd_sendcmd(CMD12,0,0X01);   //����ֹͣ����
    }
    SD_DisSelect();//ȡ��Ƭѡ
    return r1;//
}

//дSD��
//buf:���ݻ�����
//sector:��ʼ����
//cnt:������
//����ֵ:0,ok;����,ʧ��.
SDHCRES sd_WriteDisk(uint8 *buf,uint32 sector,uint8 cnt)
{
    uint8 r1;
//    uint16 retry;
    if(SD_Type!=SD_TYPE_V2HC)sector *= 512;//ת��Ϊ�ֽڵ�ַ
    if(cnt==1)
    {
        r1=sd_sendcmd(CMD24,sector,0X01);//������
//        printf("%d\n", r1);
        if(r1==0)//ָ��ͳɹ�
        {
            r1=sd_SendBlockData(buf, 0xFE);//д512���ֽ�
        }
    }
        else
        {
        if(SD_Type!=SD_TYPE_MMC)
        {
            sd_sendcmd(CMD55,0,0X01);
                        sd_sendcmd(CMD23,cnt,0X01);//����ָ��
        }
        r1=sd_sendcmd(CMD25,sector,0X01);//����д����
        if(r1==0)
        {
            do
            {
                r1=sd_SendBlockData(buf,0xFC);//����512���ֽ�
                buf+=512;
            }while(--cnt && r1==0);
            r1=sd_SendBlockData(0,0xFD);//����512���ֽ�
        }
    }
    SD_DisSelect();//ȡ��Ƭѡ
    return r1;//
}


//��SD��һ��������ȡ����
//�������1   ��ȡ������ַ
//�������2   �洢��ȡ��512�����ݵ�����
//�������3   ��ȡ�����ĸ���
//����ֵ�Ƕ�ȡ�ɹ����ǲ��ɹ�
uint8  SD_read_sector_data(uint8 data[], uint32 sector, uint32 count)
{
   uint16 i;
   uint32 j;
   uint32 add=0;
   gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);//SPI_CS_HIGH();  //��Ч��һ��Ƭѡ
   sd_spiReadWrite(0xff);//spi_write_uint8(0xff);

   if(count == 1)
   {
       //����17�������һ����������
       //������ӦӦ��Ϊ0x00
       if(sd_sendcmd(17,sector,0xff))//if(SD_write_command(17,sector,0xff))
       {
           gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);//SPI_CS_HIGH();  //��ЧƬѡ
           return 0xff;//return READ_SECTOR_DATA_ERROR;
       }
   }
   else
   {
       //����18������������������
       //������ӦӦ��Ϊ0x00
       if(sd_sendcmd(18,sector,0xff))//if(SD_write_command(18,sector,0xff))
       {
           gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);//SPI_CS_HIGH();  //��ЧƬѡ
           return 0xff;//return READ_SECTOR_DATA_ERROR;
       }
   }

   for(j=1; ; j++)
   {
        //�ȴ�����Ӧ����
        while(sd_spiReadWrite(0xff) != 0xfe);//while(spi_write_uint8(0xff) != 0xfe);
        for(i=0; i<512; i++)
        {
          data[add+i] = sd_spiReadWrite(0xff);//data[add+i] = spi_write_uint8(0xff);
        }
        //��ȡCRC��
        sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
        sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
        if(j == count )
        {
           //��������ֹͣ������
           if(count != 1) sd_sendcmd(12,0,0xff);//SD_write_command(12,0,0xff);
           break;
        }
        else
           add += 512;
   }
   gpio_high(SD_CS);//SPI_CSInternalSelected(SPI2, DISABLE);//SPI_CS_HIGH();  //��ЧƬѡ

   //Ƭѡ��Ч֮���ڷ���8��ʱ��
   sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
   return 0;
}

//��SD�е�һ������д����
//�������1  д��������ַ
//�������2  �洢512��д�����ݵ�����
//�������3  д�������ĸ���
//����ֵ��д��ɹ����ǲ��ɹ�
uint8  SD_write_sector_data(uint8 data[], uint32 sector, uint32 count)
{
   uint16 i;
   uint8 response;
   uint32 j;
   uint32 add=0;
    SPI_CS_HIGH();  //��Ч��һ��Ƭѡ
    sd_spiReadWrite(0xff);//spi_write_uint8(0xff);

   if(count == 1)  //������������д��
   {
      //����24�����д��������
      //������ӦӦ��Ϊ0x00
       if(sd_sendcmd(24,sector,0xff))//if(SD_write_command(24,sector,0xff))
       {
          SPI_CS_HIGH();  //��ЧƬѡ
          return 0xff;//return WRITE_SECTOR_DATA_ERROR;
       }
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       //д������ʼ����
       sd_spiReadWrite(0xff);//spi_write_uint8(0xfe);//�������ݿ��־0xfe
       for(i=0; i<512; i++)
       {
         sd_spiReadWrite(data[add + i]);//spi_write_uint8(data[add + i]);
       }
       //����CRC��
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       for(i=0; ; i++)
       {
         response = sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
         if((response & 0x0f) == 0x05)
            break;
         if(i==100)
         {
            SPI_CS_HIGH();  //��ЧƬѡ
            return 0xff;//return WRITE_SECTOR_DATA_ERROR;
         }
       }
   }
   else      //�����������д��
   {
       //����25�����д�����������
       //������ӦӦ��Ϊ0x00
       if(sd_sendcmd(25,sector,0xff))//if(SD_write_command(25,sector,0xff))
       {
          SPI_CS_HIGH();  //��ЧƬѡ
          return 0xff;//return WRITE_SECTOR_DATA_ERROR;
       }

   for(j=1; ; j++)
   {
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       //д������ʼ����
       sd_spiReadWrite(0xfc);//spi_write_uint8(0xfc);//�������ݿ��־0xfc
       for(i=0; i<512; i++)
       {
         sd_spiReadWrite(data[add + i]);//spi_write_uint8(data[add + i]);
       }
       //����CRC��
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
       for(i=0; ; i++)
       {
         response = sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
         if((response & 0x0f) == 0x05)
            break;
         if(i==100)
         {
            SPI_CS_HIGH();  //��ЧƬѡ
            return 0xff;//return WRITE_SECTOR_DATA_ERROR;
         }
       }
       while(sd_spiReadWrite(0xff) != 0xff);//while(spi_write_uint8(0xff) != 0xff);
       add += 512;
       if(j == count)
       {
           sd_spiReadWrite(0xFD);//spi_write_uint8(0xFD);
           break;
       }
   }
   }
   SPI_CS_HIGH();  //��ЧƬѡ
   sd_spiReadWrite(0xff);//spi_write_uint8(0xff);
   return 0;
}




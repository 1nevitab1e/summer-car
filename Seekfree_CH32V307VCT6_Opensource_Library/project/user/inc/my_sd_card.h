/*
 * my_sd_card.h
 *
 *  Created on: 2021��11��29��
 *      Author: hxy
 */

#ifndef CORE_HDU_LIBRARIES_MY_SD_CARD_H_
#define CORE_HDU_LIBRARIES_MY_SD_CARD_H_


#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"

//��������
#define SD_SPI_NUM      SPI_2
#define SD_SCLK         SPI2_MAP0_SCK_B13
#define SD_MOSI         SPI2_MAP0_MOSI_B15
#define SD_MISO         SPI2_MAP0_MISO_B14
#define SD_CS           D9

#define CS_PIN          D9     //�ֶ���

// SD�����Ͷ���
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06

// SD��ָ���
#define CMD0    0       //����λ
#define CMD1    1
#define CMD8    8       //����8 ��SEND_IF_COND
#define CMD9    9       //����9 ����CSD����
#define CMD10   10      //����10����CID����
#define CMD12   12      //����12��ֹͣ���ݴ���
#define CMD16   16      //����16������SectorSize Ӧ����0x00
#define CMD17   17      //����17�������� sector
#define CMD18   18      //����18�������� sector
#define CMD23   23      //����23�����ö�sectorд��ǰԤ�Ȳ���N��block
#define CMD24   24      //����24��дsector
#define CMD25   25      //����25��д���� sector
#define CMD41   41      //����41��Ӧ����0x00
#define CMD55   55      //����55��Ӧ����0x01
#define CMD58   58      //����58����OCR��Ϣ
#define CMD59   59      //����59��ʹ��/��ֹCRC��Ӧ����0x00

//�ٶ�����
#define SPI_LOW_SPEED           400000              //400k
#define SPI_HIGH_SPEED          25000000            //10M

typedef enum {
     MSD_RESPONSE_NO_ERROR                  = 0x00,             //�޴���
     MSD_IN_IDLE_STATE,                                         //����״̬
     MSD_ERASE_RESET,                                           //��������
     MSD_ILLEGAL_COMMAND                    = 0x04,             //�������
     MSD_COM_CRC_ERROR                      = 0x08,             //CRCͨ�Ŵ���
     MSD_ERASE_SEQUENCE_ERROR               = 0x10,             //�����������
     ADDRESS_ERROR                          = 0x20,             //��ַ����
     MSD_PARAMETER_ERROR                    = 0x40,             //��������
     MSD_OTHER_ERROR                        = 0xaa,             //��������
     MSD_RESPONSE_FAILURE                   = 0xFF              //������������ʧ�ܵģ�û���κλ�Ӧ
}SDHCRES;

uint8 sd_init(void);
void SdSpiSpeedLow(void);
//uint8 sd_SendBlockData(uint8 *buf, uint8 cmd);
//SDHCRES sd_ReceiveData(uint8 *buf,uint16 len);    //�ڲ�����
uint8 SdGetCID(uint8 *cid_data);
SDHCRES sd_ReadDisk(uint8 *buf,uint32 sector,uint8 cnt);
SDHCRES sd_WriteDisk(uint8 *buf,uint32 sector,uint8 cnt);
uint8 sd_spiReadWrite(uint8 data);
uint8  SD_read_sector_data(uint8 data[], uint32 sector, uint32 count);
uint8  SD_write_sector_data(uint8 data[], uint32 sector, uint32 count);

#endif /* CORE_HDU_LIBRARIES_MY_SD_CARD_H_ */

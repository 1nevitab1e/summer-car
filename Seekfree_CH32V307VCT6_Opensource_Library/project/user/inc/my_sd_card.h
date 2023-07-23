/*
 * my_sd_card.h
 *
 *  Created on: 2021年11月29日
 *      Author: hxy
 */

#ifndef CORE_HDU_LIBRARIES_MY_SD_CARD_H_
#define CORE_HDU_LIBRARIES_MY_SD_CARD_H_


#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"

//引脚设置
#define SD_SPI_NUM      SPI_2
#define SD_SCLK         SPI2_MAP0_SCK_B13
#define SD_MOSI         SPI2_MAP0_MOSI_B15
#define SD_MISO         SPI2_MAP0_MISO_B14
#define SD_CS           D9

#define CS_PIN          D9     //手动调

// SD卡类型定义
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06

// SD卡指令表
#define CMD0    0       //卡复位
#define CMD1    1
#define CMD8    8       //命令8 ，SEND_IF_COND
#define CMD9    9       //命令9 ，读CSD数据
#define CMD10   10      //命令10，读CID数据
#define CMD12   12      //命令12，停止数据传输
#define CMD16   16      //命令16，设置SectorSize 应返回0x00
#define CMD17   17      //命令17，读单个 sector
#define CMD18   18      //命令18，读连续 sector
#define CMD23   23      //命令23，设置多sector写入前预先擦除N个block
#define CMD24   24      //命令24，写sector
#define CMD25   25      //命令25，写连续 sector
#define CMD41   41      //命令41，应返回0x00
#define CMD55   55      //命令55，应返回0x01
#define CMD58   58      //命令58，读OCR信息
#define CMD59   59      //命令59，使能/禁止CRC，应返回0x00

//速度设置
#define SPI_LOW_SPEED           400000              //400k
#define SPI_HIGH_SPEED          25000000            //10M

typedef enum {
     MSD_RESPONSE_NO_ERROR                  = 0x00,             //无错误
     MSD_IN_IDLE_STATE,                                         //空闲状态
     MSD_ERASE_RESET,                                           //擦除错误
     MSD_ILLEGAL_COMMAND                    = 0x04,             //命令错误
     MSD_COM_CRC_ERROR                      = 0x08,             //CRC通信错误
     MSD_ERASE_SEQUENCE_ERROR               = 0x10,             //擦除次序错误
     ADDRESS_ERROR                          = 0x20,             //地址错误
     MSD_PARAMETER_ERROR                    = 0x40,             //参数错误
     MSD_OTHER_ERROR                        = 0xaa,             //其他错误
     MSD_RESPONSE_FAILURE                   = 0xFF              //这次命令根本是失败的，没有任何回应
}SDHCRES;

uint8 sd_init(void);
void SdSpiSpeedLow(void);
//uint8 sd_SendBlockData(uint8 *buf, uint8 cmd);
//SDHCRES sd_ReceiveData(uint8 *buf,uint16 len);    //内部调用
uint8 SdGetCID(uint8 *cid_data);
SDHCRES sd_ReadDisk(uint8 *buf,uint32 sector,uint8 cnt);
SDHCRES sd_WriteDisk(uint8 *buf,uint32 sector,uint8 cnt);
uint8 sd_spiReadWrite(uint8 data);
uint8  SD_read_sector_data(uint8 data[], uint32 sector, uint32 count);
uint8  SD_write_sector_data(uint8 data[], uint32 sector, uint32 count);

#endif /* CORE_HDU_LIBRARIES_MY_SD_CARD_H_ */

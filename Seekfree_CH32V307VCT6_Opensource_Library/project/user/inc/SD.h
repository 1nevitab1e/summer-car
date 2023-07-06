/*
 * SD.h
 *
 *  Created on: 2023年7月6日
 *      Author: 86131
 */

#ifndef SD_H_
#define SD_H_
#include"zf_common_headfile.h"

#define SDCard_CMD0 0 //卡复位

#define SDCard_CMD8 8 //命令8 ，SEND_IF_COND

#define SDCard_CMD9 9 //命令9 ，读CSD数据

#define SDCard_CMD12 12 //命令12，停止数据传输

#define SDCard_CMD13 16 //命令16，设置扇区大小 应返回0x00

#define SDCard_CMD17 17 //命令17，读扇区

#define SDCard_CMD18 18 //命令18，读多个扇区

#define SDCard_CMD23 23 //命令23，设置多扇区写入前预先擦除block

#define SDCard_CMD24 24 //命令24，写扇区

#define SDCard_CMD25 25 //命令25，写多个扇区

#define SDCard_CMD41 41 //命令41，应返回0x00

#define SDCard_CMD55 55 //命令55，应返回0x01

#define SDCard_CMD58 58 //命令58，读OCR信息

#define CS E0
#define SCK E1
#define MOSI E2
#define MISO E3

#define DEFAULTSECTOR 100

void SD_SPI_GPIO_Init();
u8 SDCardReadWriteOneByte(u8 DataTx);
u8 SendSDCardCmd(u8 cmd, u32 arg, u8 crc);
u8 SD_Init();
u8 SDCardRecvData(u8*buf,u16 len);
u8 SDCardSendData(u8*buf,u8 cmd);
u32 GetSDCardSectorCount(void);
void SDCardReadData(u8*buf,u32 sector,u32 cnt);
void SDCardWriteData(u8*buf,u32 sector,u32 cnt);
#endif /* SD_H_ */

/*
 * SD.h
 *
 *  Created on: 2023��7��6��
 *      Author: 86131
 */

#ifndef SD_H_
#define SD_H_
#include"zf_common_headfile.h"

#define SDCard_CMD0 0 //����λ

#define SDCard_CMD8 8 //����8 ��SEND_IF_COND

#define SDCard_CMD9 9 //����9 ����CSD����

#define SDCard_CMD12 12 //����12��ֹͣ���ݴ���

#define SDCard_CMD13 16 //����16������������С Ӧ����0x00

#define SDCard_CMD17 17 //����17��������

#define SDCard_CMD18 18 //����18�����������

#define SDCard_CMD23 23 //����23�����ö�����д��ǰԤ�Ȳ���block

#define SDCard_CMD24 24 //����24��д����

#define SDCard_CMD25 25 //����25��д�������

#define SDCard_CMD41 41 //����41��Ӧ����0x00

#define SDCard_CMD55 55 //����55��Ӧ����0x01

#define SDCard_CMD58 58 //����58����OCR��Ϣ

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

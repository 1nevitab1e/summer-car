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

#define CS E2
#define SCK C1
#define MOSI C3
#define MISO C0

u8 SDCardReadWriteOneByte(u8 DataTx);
u8 SendSDCardCmd(u8 cmd, u32 arg, u8 crc);
u8 SD_Init();

#endif /* SD_H_ */

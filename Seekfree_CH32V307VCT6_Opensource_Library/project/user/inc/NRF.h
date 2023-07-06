/*
 * NRF.h
 *
 *  Created on: 2023��4��14��
 *      Author: 86131
 */

#ifndef NRF_H_
#define NRF_H_

#include "zf_common_headfile.h"
#include "simu_spi.h"

void NRF24L01_Init(void);       //��ʼ��
void NRF24L01_RX_Mode(void);    //����Ϊ����ģʽ
void NRF24L01_TX_Mode(void);    //����Ϊ����ģʽ
u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 u8s);    //д������
u8 NRF24L01_Read_Buf(u8 reg, u8 *pBuf, u8 u8s);    //��������
u8 NRF24L01_Read_Reg(u8 reg);               //���Ĵ���
u8 NRF24L01_Write_Reg(u8 reg, u8 value);    //д�Ĵ���
u8 NRF24L01_Check(void);                    //���24L01�Ƿ����
u8 NRF24L01_TxPacket(u8 *txbuf);            //����һ����������
u8 NRF24L01_RxPacket(u8 *rxbuf);            //����һ����������


#endif /* NRF_H_ */

/*
 * NRF.h
 *
 *  Created on: 2023年4月14日
 *      Author: 86131
 */

#ifndef NRF_H_
#define NRF_H_

#include "zf_common_headfile.h"
#include "simu_spi.h"

void NRF24L01_Init(void);       //初始化
void NRF24L01_RX_Mode(void);    //配置为接收模式
void NRF24L01_TX_Mode(void);    //配置为发送模式
u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 u8s);    //写数据区
u8 NRF24L01_Read_Buf(u8 reg, u8 *pBuf, u8 u8s);    //读数据区
u8 NRF24L01_Read_Reg(u8 reg);               //读寄存器
u8 NRF24L01_Write_Reg(u8 reg, u8 value);    //写寄存器
u8 NRF24L01_Check(void);                    //检查24L01是否存在
u8 NRF24L01_TxPacket(u8 *txbuf);            //发送一个包的数据
u8 NRF24L01_RxPacket(u8 *rxbuf);            //接收一个包的数据


#endif /* NRF_H_ */

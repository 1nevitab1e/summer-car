/*
 * my_imagetransfer.h
 *
 *  Created on: 2021��11��30��
 *      Author: hxy
 */

#ifndef CORE_HDU_LIBRARIES_MY_IMAGETRANSFER_H_
#define CORE_HDU_LIBRARIES_MY_IMAGETRANSFER_H_


#include "my_sd_card.h"
#include "zf_driver_uart.h"
#include "ch32v30x_dma.h"
#include "zf_device_mt9v03x_dvp.h"
//#define gray
#define bin

#define TRANSFOR_UARST                      UART_3
#define TRANSFOR_UARST_RX                   UART7_RX_C3
#define TRANSFOR_UARST_TX                   UART3_RX_B11

struct Byte8_Struct
{
 uint8_t bit1:1;
 uint8_t bit2:1;
 uint8_t bit3:1;
 uint8_t bit4:1;
 uint8_t bit5:1;
 uint8_t bit6:1;
 uint8_t bit7:1;
 uint8_t bit8:1;
};

typedef struct//���߽ṹ��
{
//  uint8_t LEnd;
//  uint8_t REnd;
//  uint8_t LStart;
    uint8_t RStart;
    uint8_t left;
    uint8_t right;
    uint8_t center;
}My_LCR;

typedef struct //����ṹ��
{
    uint8_t Verific[8];//У��λ
    uint8_t Pixels_width;//ͼ���� 186
    uint8_t Pixels_height;//ͼ��߶� 70
    uint8_t Coefficient_Num;//datanum 50
    uint8_t Parameter_Num;  //parnum 1
    uint8_t Data_Con[50*4*2];//���� data_give
    uint8_t Par_Con[1*8];//����
    My_LCR Lcr[70];//����
    #if defined gray
    uint8_t Pixels[186*70];//�Ҷ�ͼ��
    #elif defined bin
    uint8_t Pixels[1628];//ѹ��ͼ��
    #endif
}My_Data_Type;

//�����С����
#define Verific_Len (12)
#if defined gray//�Ҷ�ͼ���
#define Pixels_Len  (186*70)
#elif defined bin//��ֵͼ��С
#define Pixels_Len  (1628)
#endif
#define Data_Len        (50*4*2)
#define Lcr_Len         (70*7)
#define Fix_Len         (10)
//�����ܳ���
#define Send_Data_Len   (Verific_Len+Pixels_Len+Data_Len+Lcr_Len+Fix_Len)//14895    2538

extern My_Data_Type My_Send_Data;
extern float Accelerate_Hor;
extern float my_car_data[60];
//�ӿں���
void My_Tranfer_Init(void);//�����ʼ��
void My_SdCard_Init(void);//��ʼ��sd��������ȡ
void My_SdCard_Save(void);//sd�������ֵͼ������
void My_SdCard_Read(void);//��ȡsd��������
void Get_SendData();//��䴫��ṹ��

#endif /* CORE_HDU_LIBRARIES_MY_IMAGETRANSFER_H_ */

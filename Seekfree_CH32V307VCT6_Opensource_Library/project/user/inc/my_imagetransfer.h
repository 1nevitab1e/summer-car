/*
 * my_imagetransfer.h
 *
 *  Created on: 2021年11月30日
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

typedef struct//传线结构体
{
//  uint8_t LEnd;
//  uint8_t REnd;
//  uint8_t LStart;
    uint8_t RStart;
    uint8_t left;
    uint8_t right;
    uint8_t center;
}My_LCR;

typedef struct //传输结构体
{
    uint8_t Verific[8];//校验位
    uint8_t Pixels_width;//图像宽度 186
    uint8_t Pixels_height;//图像高度 70
    uint8_t Coefficient_Num;//datanum 50
    uint8_t Parameter_Num;  //parnum 1
    uint8_t Data_Con[50*4*2];//数据 data_give
    uint8_t Par_Con[1*8];//不用
    My_LCR Lcr[70];//三线
    #if defined gray
    uint8_t Pixels[186*70];//灰度图像
    #elif defined bin
    uint8_t Pixels[1628];//压缩图像
    #endif
}My_Data_Type;

//传输大小计算
#define Verific_Len (12)
#if defined gray//灰度图像大
#define Pixels_Len  (186*70)
#elif defined bin//二值图像小
#define Pixels_Len  (1628)
#endif
#define Data_Len        (50*4*2)
#define Lcr_Len         (70*7)
#define Fix_Len         (10)
//传输总长度
#define Send_Data_Len   (Verific_Len+Pixels_Len+Data_Len+Lcr_Len+Fix_Len)//14895    2538

extern My_Data_Type My_Send_Data;
extern float Accelerate_Hor;
extern float my_car_data[60];
//接口函数
void My_Tranfer_Init(void);//传输初始化
void My_SdCard_Init(void);//初始化sd卡储存或读取
void My_SdCard_Save(void);//sd卡储存二值图及参数
void My_SdCard_Read(void);//读取sd卡并传输
void Get_SendData();//填充传输结构体

#endif /* CORE_HDU_LIBRARIES_MY_IMAGETRANSFER_H_ */

/*
 * SpeedControl.c
 *
 *  Created on: 2023年4月28日
 *      Author: 86131
 */

#include "SpeedControl.h"
#include <math.h>

#define StaticDif_Err 10
#define outPutLimit 700

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

extern int16_t Speed;
float alpha=0.8;
float kiIndex=0;
extern int16 setspeed;

struct PIDINIT
{
    int16_t nowVal;
    int16_t setGoal;
    int16_t errNow;
    int16_t errLast;//err-1
    int16_t errLastLast;//err-2
    float kp;
    float ki;
    float kd;


    float OutInc;

    int16_t outPut;

}pid;

u8 BUFF[30]={0};

void Wave_Dis(u16 A)
{
        int i;
        u8 sumcheck = 0;
        u8 addcheck = 0;
        u8 _cnt=0;
        BUFF[_cnt++]=0xAA;//帧头
        BUFF[_cnt++]=0xFF;//目标地址
        BUFF[_cnt++]=0XF1;//功能码
        BUFF[_cnt++]=0x04;//数据长度
        BUFF[_cnt++]=BYTE0(A);//数据内容,小段模式，低位在前
        BUFF[_cnt++]=BYTE1(A);//需要将字节进行拆分，调用上面的宏定义即可。
      BUFF[_cnt++] = BYTE0(setspeed);
        BUFF[_cnt++] = BYTE1(setspeed);
        for(i=0;i<BUFF[3]+4;i++)
        {
            sumcheck+=BUFF[i];
            addcheck+=sumcheck;
        }
        BUFF[_cnt++]=sumcheck;
        BUFF[_cnt++]=addcheck;
        uart_write_buffer(UART_3,BUFF, _cnt);
}

void PID_Init()
{
    pid.setGoal=100;
    pid.nowVal=0;
    pid.errNow=100;
    pid.errLast=0;
    pid.errLastLast=0;

    pid.kp=200;
    pid.ki=0;
    pid.kd=0;

    pid.outPut=0;
}

void Encoder_Init()
{
    encoder_init_dir(TIM3_ENCOEDER,TIM3_CH1_ENCOEDER_A6,TIM3_CH2_ENCOEDER_A7);

    gpio_init(A0, GPO, 1, GPO_PUSH_PULL);
    gpio_init(A1, GPO, 0, GPO_PUSH_PULL);
    TIM_ICInitTypeDef TIM_ICInitStruct;
    TIM_ICStructInit(&TIM_ICInitStruct);
    TIM_ICInitStruct.TIM_Channel=TIM_Channel_1;
    TIM_ICInitStruct.TIM_ICFilter=0xf;
    TIM_ICInit(TIM3, &TIM_ICInitStruct);
    TIM_ICInitStruct.TIM_Channel=TIM_Channel_2;
    TIM_ICInitStruct.TIM_ICFilter=0xf;
    TIM_ICInit(TIM3, &TIM_ICInitStruct);

    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

    TIM_Cmd(TIM3, ENABLE);

}

uint16_t Get_Encoder()
{
    uint16_t temp;
    temp=TIM_GetCounter(TIM3);
    TIM_SetCounter(TIM3, 0);
    return temp;
}

//void Dma_Uart_Init()
//{
//    DMA_InitTypeDef DMA_InitStructure;
//    NVIC_InitTypeDef  NVIC_InitStructure;
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
//
//    /*DMA配置*/
//
//    DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)(&USART3->DATAR);//串口数据寄存器地址
//    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&Speed; //内存地址(要传输的变量的指针)
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST; //方向(从内存到外设)
//    DMA_InitStructure.DMA_BufferSize = 1; //传输内容的大小
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //外设地址不增
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; //内存地址自增
//    DMA_InitStructure.DMA_PeripheralDataSize =
//    DMA_PeripheralDataSize_Byte ; //外设数据单位
//    DMA_InitStructure.DMA_MemoryDataSize =
//    DMA_MemoryDataSize_Byte ; //内存数据单位
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ; //DMA模式：一次传输，循环
//    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium ; //优先级：高
//    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //禁止内存到内存的传输
//
//    DMA_Init(DMA1_Channel2, &DMA_InitStructure); //配置DMA1的2通道
//
//    //DMA_SetCurrDataCounter(DMA1_Channel2,1);//DMA通道的DMA缓存的大小
//    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);//配置DMA发送完成后产生中断
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//
//    DMA_ITConfig(DMA1_Channel2, DMA_IT_TC, ENABLE);  //使能DMA传输完成中断
//    DMA_Cmd(DMA1_Channel2,ENABLE);
//
//}
//
//void Dma_Disp()
//{
//
//}
//
//void DMA1_Channel2_IRQHandler(void)
//{
//    if(DMA_GetFlagStatus(DMA1_FLAG_TC2)==SET)
//        {
//
//            DMA_ClearFlag(DMA1_FLAG_TC2);
//        }
//}

int16_t PID_Inc()
{
    pid.nowVal = Speed;
    pid.errNow = pid.setGoal - pid.nowVal;

        /*误差小消除 or 死区*/
        if(fabs(pid.errNow)<StaticDif_Err)
        {
            pid.errNow=0;
        }

        kiIndex=0;
        /*三段积分分离*/
//        if (fabs(pid.errNow) > 350)
//        {
//            kiIndex = 0.000f;
//        }
//        else if(fabs(pid.errNow) > 150 && fabs(pid.errNow) < 350)
//        {
//            kiIndex = 0.600f;
//        }
//        else
//        {
//            kiIndex = 1.000f;
//        }

        pid.OutInc = pid.kp * (pid.errNow - pid.errLast)+kiIndex*pid.ki * pid.errNow+pid.kd * (pid.errNow - 2.000f * pid.errLast + pid.errLastLast);
        pid.outPut += (int16_t)pid.OutInc;
        /*我tm直接阈值限定*/
//        if(fabs(pid.OutInc)>750)
//        {
//            if(pid.outPut>0)
//            pid.outPut=750;
//            if(pid.outPut<0)
//            pid.outPut=-750;
//        }

//        /*抗饱和捏*/
//        if(pid.outPut<outPutLimit || (pid.outPut>outPutLimit && pid.OutInc <0))
//        {
//            pid.outPut += (int16_t)pid.OutInc;
//        }

        pid.errLast = pid.errNow;
        pid.errLastLast = pid.errLast;

        return pid.outPut;
}

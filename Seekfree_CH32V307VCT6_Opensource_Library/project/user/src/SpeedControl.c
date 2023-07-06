/*
 * SpeedControl.c
 *
 *  Created on: 2023��4��28��
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
        BUFF[_cnt++]=0xAA;//֡ͷ
        BUFF[_cnt++]=0xFF;//Ŀ���ַ
        BUFF[_cnt++]=0XF1;//������
        BUFF[_cnt++]=0x04;//���ݳ���
        BUFF[_cnt++]=BYTE0(A);//��������,С��ģʽ����λ��ǰ
        BUFF[_cnt++]=BYTE1(A);//��Ҫ���ֽڽ��в�֣���������ĺ궨�弴�ɡ�
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
//    /*DMA����*/
//
//    DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)(&USART3->DATAR);//�������ݼĴ�����ַ
//    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&Speed; //�ڴ��ַ(Ҫ����ı�����ָ��)
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST; //����(���ڴ浽����)
//    DMA_InitStructure.DMA_BufferSize = 1; //�������ݵĴ�С
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; //�ڴ��ַ����
//    DMA_InitStructure.DMA_PeripheralDataSize =
//    DMA_PeripheralDataSize_Byte ; //�������ݵ�λ
//    DMA_InitStructure.DMA_MemoryDataSize =
//    DMA_MemoryDataSize_Byte ; //�ڴ����ݵ�λ
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ; //DMAģʽ��һ�δ��䣬ѭ��
//    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium ; //���ȼ�����
//    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //��ֹ�ڴ浽�ڴ�Ĵ���
//
//    DMA_Init(DMA1_Channel2, &DMA_InitStructure); //����DMA1��2ͨ��
//
//    //DMA_SetCurrDataCounter(DMA1_Channel2,1);//DMAͨ����DMA����Ĵ�С
//    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);//����DMA������ɺ�����ж�
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//
//    DMA_ITConfig(DMA1_Channel2, DMA_IT_TC, ENABLE);  //ʹ��DMA��������ж�
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

        /*���С���� or ����*/
        if(fabs(pid.errNow)<StaticDif_Err)
        {
            pid.errNow=0;
        }

        kiIndex=0;
        /*���λ��ַ���*/
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
        /*��tmֱ����ֵ�޶�*/
//        if(fabs(pid.OutInc)>750)
//        {
//            if(pid.outPut>0)
//            pid.outPut=750;
//            if(pid.outPut<0)
//            pid.outPut=-750;
//        }

//        /*��������*/
//        if(pid.outPut<outPutLimit || (pid.outPut>outPutLimit && pid.OutInc <0))
//        {
//            pid.outPut += (int16_t)pid.OutInc;
//        }

        pid.errLast = pid.errNow;
        pid.errLastLast = pid.errLast;

        return pid.outPut;
}

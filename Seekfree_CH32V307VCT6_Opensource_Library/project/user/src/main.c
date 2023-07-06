/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file             main
* @company          �ɶ���ɿƼ����޹�˾
 * @author          ��ɿƼ�(QQ790875685)
* @version          �鿴doc��version�ļ� �汾˵��
* @Software         MounRiver Studio V1.51
* @Target core      CH32V307VCT6
* @Taobao           https://seekfree.taobao.com/
* @date             2021-11-25
********************************************************************************************************************/



#include "zf_common_headfile.h"
//#include "LED.h"
//#include "KEY.h"
#include "daojishi.h"
#include "SpeedControl.h"
//#include "character.h"
#include "menu.h"
//#include "game_bird.h"
//#include "snake.h"
#include "DS18B20.h"
//#include "NRF_Config.h"

uint16_t Num;
uint16_t Lim;
uint8 i;
uint j=1;
uint8 uart_flag;
uint8 grade;
int16_t Speed=0x34;

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

#define M2        TIM4_PWM_CH4_B9

u8 BUFF[30];
void sent_data(u16 A);

int16 setspeed=3600;
float kp=1.2;
float ki=0.5;
float kd=0.1;
int main(void)
{

    u8 tem_buf_rx[33]={1,1,1,1,1,1};
    uint8 sel=0;
    interrupt_global_disable();             // �ر����ж�
    clock_init(SYSTEM_CLOCK_144M);          // ��ر���������ϵͳʱ�ӡ�
    debug_init();                           // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    // �˴���д�û�����(���磺�����ʼ�������)
    //pit_init_ms(TIM3_PIT,20);
    uart_init(UART_1, 115200, UART1_TX_A9, UART1_RX_A10);
    uart_rx_interrupt(UART_1,ENABLE);
    interrupt_global_enable();              // ���ж������
    while(1)
    {
//        send_data(12);
    }
}

void sent_data(u16 A)
{
    int i;
    u8 sumcheck = 0;
    u8 addcheck = 0;
    u8 _cnt=0;
    BUFF[_cnt++]=0xAA;//֡ͷ
    BUFF[_cnt++]=0xFF;//Ŀ���ַ
    BUFF[_cnt++]=0XF1;//������
    BUFF[_cnt++]=0x02;//���ݳ���
    BUFF[_cnt++]=BYTE0(A);//��������,С��ģʽ����λ��ǰ
    BUFF[_cnt++]=BYTE1(A);//��Ҫ���ֽڽ��в�֣���������ĺ궨�弴�ɡ�

    for(i=0;i<BUFF[3]+4;i++)
    {
        sumcheck+=BUFF[i];
        addcheck+=sumcheck;
    }
    BUFF[_cnt++]=sumcheck;
    BUFF[_cnt++]=addcheck;
    uart_write_buffer(UART_1,BUFF, _cnt);
}








/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,逐飞科技
* All rights reserved.
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file             main
* @company          成都逐飞科技有限公司
 * @author          逐飞科技(QQ790875685)
* @version          查看doc内version文件 版本说明
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
    interrupt_global_disable();             // 关闭总中断
    clock_init(SYSTEM_CLOCK_144M);          // 务必保留，设置系统时钟。
    debug_init();                           // 务必保留，本函数用于初始化MPU 时钟 调试串口

    // 此处编写用户代码(例如：外设初始化代码等)
    //pit_init_ms(TIM3_PIT,20);
    uart_init(UART_1, 115200, UART1_TX_A9, UART1_RX_A10);
    uart_rx_interrupt(UART_1,ENABLE);
    interrupt_global_enable();              // 总中断最后开启
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
    BUFF[_cnt++]=0xAA;//帧头
    BUFF[_cnt++]=0xFF;//目标地址
    BUFF[_cnt++]=0XF1;//功能码
    BUFF[_cnt++]=0x02;//数据长度
    BUFF[_cnt++]=BYTE0(A);//数据内容,小段模式，低位在前
    BUFF[_cnt++]=BYTE1(A);//需要将字节进行拆分，调用上面的宏定义即可。

    for(i=0;i<BUFF[3]+4;i++)
    {
        sumcheck+=BUFF[i];
        addcheck+=sumcheck;
    }
    BUFF[_cnt++]=sumcheck;
    BUFF[_cnt++]=addcheck;
    uart_write_buffer(UART_1,BUFF, _cnt);
}








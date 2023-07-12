/*********************************************************************************************************************
* CH32V307VCT6 Opensourec Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ���CH32V307VCT6 ��Դ���һ����
*
* CH32V307VCT6 ��Դ�� ��������
* �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
* �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          main
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MounRiver Studio V1.8.1
* ����ƽ̨          CH32V307VCT6
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����                                      ����                             ��ע
* 2022-09-15        ��W            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"
#include "MyHead.h"


struct page p0,p1,p2;
uint8 state,buff[1][1];
uint32 test=9,sectornum;
float testf=0.8;
int i,j;
u16 angle=0;

int main (void)
{

    clock_init(SYSTEM_CLOCK_144M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();    // ��ʼ��Ĭ�� Debug UART

    // �˴���д�û����� ���������ʼ�������
    menu_key_init();
    oled_init();
    oled_clear();

    oled_show_string(0, 1, "KI");
    system_delay_ms(1000);
    oled_show_string(0, 1,"  ");
    state=SD_Init();
    oled_show_int(0, 2, state, 3);
    sectornum=GetSDCardSectorCount();
    oled_show_int(0, 3, sectornum, 10);
//    uart_init(UART_3, 115200, UART3_MAP0_TX_B10, UART3_MAP0_RX_B11);
//    uart_rx_interrupt(UART_3,ZF_ENABLE);
//    pit_ms_init(TIM4_PIT,10);//IMU
//    //pit_ms_init(TIM3_PIT,10);//adc
    // �˴���д�û����� ���������ʼ�������

    while(1)
    {

        // �˴���д��Ҫѭ��ִ�еĴ���
        if((gpio_get_level(KEY_4)==1)&&(gpio_get_level(KEY_1)==1)&&(gpio_get_level(KEY_2)==1)&&(gpio_get_level(KEY_3)==1)&&(gpio_get_level(KEY_7)==1))
        {
            oled_show_string(0, 0, "ON ");
        }
        else
        {
            oled_show_string(0, 0, "OFF");
        }
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}


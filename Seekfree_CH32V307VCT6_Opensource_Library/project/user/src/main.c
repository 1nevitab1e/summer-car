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
#include "menu.h"
#include "Feed.h"
#include "SD.h"
struct page p0,p1,p2;
uint8 state;
uint32 test=9;
float testf=0.8;
int i;

int main (void)
{

    clock_init(SYSTEM_CLOCK_144M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();    // ��ʼ��Ĭ�� Debug UART

    // �˴���д�û����� ���������ʼ�������
    uart_init(UART_3, 115200, UART3_MAP0_TX_B10, UART3_MAP0_RX_B11);
    uart_rx_interrupt(UART_3,ZF_ENABLE);

//    state=mt9v03x_init();
//    if(state)
//        {
//            oled_show_string(1, 1, "Error");
//        }
//    mt9v03x_set_exposure_time(90);
    gpio_init(MISO, GPI, 1, GPI_PULL_UP);
    gpio_init(MOSI, GPO, 1, GPO_PUSH_PULL);
    gpio_init(CS, GPO, 1, GPO_PUSH_PULL);
    gpio_init(SCK, GPO, 1, GPO_PUSH_PULL);

    oled_init();
    oled_clear();
    //state=SDCardReadWriteOneByte(0xff);
//    for(i=0;i<10;i++)SDCardReadWriteOneByte(0xFF);
//    state=SendSDCardCmd(SDCard_CMD0,0,0x95);
    state=SD_Init();
    oled_show_int(0, 1, state, 4);
//    MyMenu_Init();
//    menu_key_init();
    //pit_ms_init(TIM4_PIT,5);
    //pit_ms_init(TIM3_PIT,10);

    // �˴���д�û����� ���������ʼ�������

    while(1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
//        oled_displayimage03x(mt9v03x_image[0], 200);
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}


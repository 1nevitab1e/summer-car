/*********************************************************************************************************************
* CH32V307VCT6 Opensourec Library 即（CH32V307VCT6 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是CH32V307VCT6 开源库的一部分
*
* CH32V307VCT6 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          main
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MounRiver Studio V1.8.1
* 适用平台          CH32V307VCT6
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期                                      作者                             备注
* 2022-09-15        大W            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"
#include "menu.h"
#include "Feed.h"
#include "SD.h"
struct page p0,p1,p2;
uint8 state,buff[1][1];
uint32 test=9,sectornum;
float testf=0.8;
int i,j;

int main (void)
{

    clock_init(SYSTEM_CLOCK_144M);                                              // 初始化芯片时钟 工作频率为 144MHz
    debug_init();    // 初始化默认 Debug UART

    // 此处编写用户代码 例如外设初始化代码等
    oled_init();
    oled_clear();
    uart_init(UART_3, 115200, UART3_MAP0_TX_B10, UART3_MAP0_RX_B11);
    uart_rx_interrupt(UART_3,ZF_ENABLE);

    state=mt9v03x_init();
    if(state)oled_show_string(1, 1, "Error");
    mt9v03x_set_exposure_time(90);

    state=SD_Init();
    oled_show_int(0, 1, state, 4);
    sectornum=GetSDCardSectorCount();
    oled_show_int(0, 0, sectornum, 10);
    system_delay_ms(1000);
//    SDCardWriteData(mt9v03x_image[0], DEFAULTSECTOR, 1);
//    SDCardReadData(read, DEFAULTSECTOR, 1);
//    oled_show_string(0, 0, read);
//    MyMenu_Init();
//    menu_key_init();
    //pit_ms_init(TIM4_PIT,5);
    //pit_ms_init(TIM3_PIT,10);

    // 此处编写用户代码 例如外设初始化代码等

    while(1)
    {
        // 此处编写需要循环执行的代码
        oled_displayimage03x(mt9v03x_image[0], 200);
        if(j==0)i++;
        if(i==200)
        {
            SDCardWriteData(mt9v03x_image[0], DEFAULTSECTOR, 45);
            j=1;
            i=0;
        }
        // 此处编写需要循环执行的代码
    }
}


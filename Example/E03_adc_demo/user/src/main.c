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

// *************************** ����Ӳ������˵�� ***************************
// ʹ����ɿƼ� WCH-LINK ��������������
//      ֱ�ӽ���������ȷ�����ں��İ�ĵ������ؽӿڼ���
//
// ʹ�� USB-TTL ģ������
//      ģ��ܽ�            ��Ƭ���ܽ�
//      USB-TTL-RX          �鿴 zf_common_debug.h �ļ��� DEBUG_UART_TX_PIN �궨������� Ĭ�� B10
//      USB-TTL-TX          �鿴 zf_common_debug.h �ļ��� DEBUG_UART_RX_PIN �궨������� Ĭ�� B11
//      USB-TTL-GND         ���İ��Դ�� GND
//      USB-TTL-3V3         ���İ� 3V3 ��Դ

// *************************** ���̲���˵�� ***************************
// 1.���İ���¼��ɱ����̣�����ʹ�ú��İ���������������� USB-TTL ģ�飬�ڶϵ�������������
//
// 2.���������������� USB-TTL ģ�����ӵ��ԣ�����ϵ�
//
// 3.������ʹ�ô������ִ򿪶�Ӧ�Ĵ��ڣ����ڲ�����Ϊ zf_common_debug.h �ļ��� DEBUG_UART_BAUDRATE �궨�� Ĭ�� 115200�����İ尴�¸�λ����
//
// 4.�����ڴ��������Ͽ������´�����Ϣ��
//      ADC channel 1 convert data is x.
//      ...
//      ADC channel 1 mean filter convert data is x.
//      ...
//
// 5.�� ADC_CHANNELx �궨���Ӧ�����ŷֱ�ӵ� 3V3/GND �ٶ�Ӧ����Ϣ�ῴ�����ݱ仯
//
// �������������˵�����ز��� ����ձ��ļ����·� ���̳�������˵�� �����Ų�


// **************************** �������� ****************************
#define CHANNEL_NUMBER          (4)

#define ADC_CHANNEL1            (ADC1_IN7_A7)
#define ADC_CHANNEL2            (ADC1_IN9_B1)
#define ADC_CHANNEL3            (ADC1_IN10_C0)
#define ADC_CHANNEL4            (ADC1_IN11_C1)

uint8 channel_index = 0;
adc_channel_enum channel_list[CHANNEL_NUMBER] =
{
    ADC_CHANNEL1, ADC_CHANNEL2, ADC_CHANNEL3, ADC_CHANNEL4,
};



int main(void)
{
    clock_init(SYSTEM_CLOCK_144M);      // ��ر���������ϵͳʱ�ӡ�

    debug_init();                       // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    // �˴���д�û����� ���������ʼ�������
    adc_init(ADC_CHANNEL1, ADC_12BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
    adc_init(ADC_CHANNEL2, ADC_12BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
    adc_init(ADC_CHANNEL3, ADC_10BIT);                                           // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
    adc_init(ADC_CHANNEL4, ADC_8BIT);                                           // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����

                                                                                // ������ᷢ�����ȫ�� 8bit ����
                                                                                // ��Ϊ�ⶼ��ͬһ�� ADC ģ�������
                                                                                // ���Ի������һ����ʼ������Ϊ׼
    // �˴���д�û����� ���������ʼ�������

    while(1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        for(channel_index = 0; channel_index < CHANNEL_NUMBER; channel_index ++)
        {
            printf(
                "ADC channel %d convert data is %d.\r\n",
                channel_index + 1,
                adc_convert(channel_list[channel_index]));                      // ѭ���������ת�����
        }
        system_delay_ms(1000);

        for(channel_index = 0; channel_index < CHANNEL_NUMBER; channel_index ++)
        {
            printf(
                "ADC channel %d mean filter convert data is %d.\r\n",
                channel_index + 1,
                adc_mean_filter_convert(channel_list[channel_index], 10));      // ѭ����� 10 �ξ�ֵ�˲�ת�����
        }
        system_delay_ms(1000);
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}
// **************************** �������� ****************************

// *************************** ���̳�������˵�� ***************************
// ��������ʱ�밴�������������б���
//
// ����1������û������
//      �鿴�������ִ򿪵��Ƿ�����ȷ�Ĵ��ڣ����򿪵� COM ���Ƿ��Ӧ���ǵ������������� USB-TTL ģ��� COM ��
//      �����ʹ����ɿƼ� WCH-LINK �������������ӣ���ô������������Ƿ��ɶ��������İ崮�������Ƿ��Ѿ����ӣ��������߲鿴���İ�ԭ��ͼ�����ҵ�
//      �����ʹ�� USB-TTL ģ�����ӣ���ô��������Ƿ������Ƿ��ɶ���ģ�� TX �Ƿ����ӵĺ��İ�� RX��ģ�� RX �Ƿ����ӵĺ��İ�� TX
//
// ����2��������������
//      �鿴�����������õĲ������Ƿ����������һ�£������� zf_common_debug.h �ļ��� DEBUG_UART_BAUDRATE �궨��Ϊ debug uart ʹ�õĴ��ڲ�����






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

// *************************** ���̲���˵�� ***************************
// 1.���İ���¼��ɱ����̣�����ϵ�
//
// 2.���Կ������İ�����ɫ LED ��˸
//
// 3.����ͨ�����ߵ��Եķ�ʽ�鿴gpio_status���� ���鿴��ǰD0���ŵ�״̬


uint8 gpio_status;
#define LED1_PIN E2
#define LED2_PIN E9
#define INPUT_PIN  B2
int main(void)
{


    clock_init(SYSTEM_CLOCK_144M);      // ��ر���������ϵͳʱ�ӡ�

    debug_init();                       // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    // �˴���д�û����� ���������ʼ�������

    // ��ʼ��GPIO B9 Ϊ��� Ĭ������͵�ƽ
    gpio_init(LED1_PIN, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED2_PIN, GPO, 0, GPO_PUSH_PULL);

    // ��ʼ��GPIO D0 D1 Ϊ��������
    gpio_init(INPUT_PIN, GPI, 0, GPI_PULL_UP);

    // �˴���д�û����� ���������ʼ�������

    while(1)
    {
        gpio_set_level(LED1_PIN, 1);                // �������ŵ�ƽΪ�ߵ�ƽ
        system_delay_ms(100);
        gpio_set_level(LED1_PIN, 0);                // �������ŵ�ƽΪ�͵�ƽ
        system_delay_ms(100);

        gpio_toggle_level(LED2_PIN);                // ��ת���ŵ�ƽ
        system_delay_ms(100);

        gpio_status = gpio_get_level(INPUT_PIN);      // ��ȡ���ŵ�ƽ
        system_delay_ms(100);
    }
}







/*
 * NRF.c
 *
 *  Created on: 2023��4��14��
 *      Author: 86131
 */

#include "NRF.h"
#include "NRF_Config.h"

const u8 TX_ADDRESS[TX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01}; //���͵�ַ
const u8 RX_ADDRESS[RX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01}; //���͵�ַ



void NRF24L01_Init(void)
{
    simu_spi_gpio_init();
    //system_delay_us()
    gpio_set_level(NRF24L01_CE,0);//ʹ��NRF
    simu_spi_stop();//spi��ͣ����
}

//���24L01�Ƿ����
//����ֵ:0���ɹ�;1��ʧ��
u8 NRF24L01_Check(void)
{
    u8 buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
    u8 i;
    NRF24L01_Write_Buf(NRF_WRITE_REG+TX_ADDR,buf,5);//д��5���ֽڵĵ�ַ.
    NRF24L01_Read_Buf(TX_ADDR,buf,5); //����д��ĵ�ַ
    for(i=0;i<5;i++)if(buf[i]!=0XA5)break;
    if(i!=5)return 1;//���24L01����
    return 0;        //��⵽24L01
}

//��ָ��λ��дָ�����ȵ�����
//reg:�Ĵ���(λ��)
//*pBuf:����ָ��
//len:���ݳ���
//����ֵ,�˴ζ�����״̬�Ĵ���ֵ
u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 len)
{
    u8 status,u8_ctr;
    simu_spi_start();          //ʹ��SPI����
    status = simu_spi_swapbyte(reg);//���ͼĴ���ֵ(λ��),����ȡ״ֵ̬
    for(u8_ctr=0; u8_ctr<len; u8_ctr++)simu_spi_swapbyte(*pBuf++); //д������
    simu_spi_stop();      //�ر�SPI����
    return status;          //���ض�����״ֵ̬
}

//��ָ��λ�ö���ָ�����ȵ�����
//reg:�Ĵ���(λ��)
//*pBuf:����ָ��
//len:���ݳ���
//����ֵ,�˴ζ�����״̬�Ĵ���ֵ
u8 NRF24L01_Read_Buf(u8 reg,u8 *pBuf,u8 len)
{
    u8 status,u8_ctr;
    simu_spi_start();           //ʹ��SPI����
    status=simu_spi_swapbyte(reg);//���ͼĴ���ֵ(λ��),����ȡ״ֵ̬
    for(u8_ctr=0;u8_ctr<len;u8_ctr++)pBuf[u8_ctr]=simu_spi_swapbyte(0XFF);//��������
    simu_spi_stop();      //�ر�SPI����
    return status;        //���ض�����״ֵ̬
}

//SPIд�Ĵ���
//reg:ָ���Ĵ�����ַ
//value:д���ֵ
u8 NRF24L01_Write_Reg(u8 reg,u8 value)
{
    u8 status;
    simu_spi_start();                 //ʹ��SPI����
    status =simu_spi_swapbyte(reg);//���ͼĴ�����
    simu_spi_swapbyte(value);      //д��Ĵ�����ֵ
    simu_spi_stop();                //��ֹSPI����
    return status;                 //����״ֵ̬
}

//��ȡSPI�Ĵ���ֵ
//reg:Ҫ���ļĴ���
u8 NRF24L01_Read_Reg(u8 reg)
{
    u8 reg_val;
    simu_spi_start();         //ʹ��SPI����
    simu_spi_swapbyte(reg);   //���ͼĴ�����
    reg_val=simu_spi_swapbyte(0XFF);//��ȡ�Ĵ�������
    simu_spi_stop();          //��ֹSPI����
    return reg_val;           //����״ֵ̬
}

//����NRF24L01����һ������
//txbuf:�����������׵�ַ
//����ֵ:�������״��
u8 NRF24L01_TxPacket(u8 *txbuf)
{
    u8 sta;
    simu_spi_start();
    gpio_set_level(NRF24L01_CE,0);//ʹ������
    NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);//д���ݵ�TX BUF  32���ֽ�
    gpio_set_level(NRF24L01_CE,1);//��������
    while(gpio_get_level(NRF24L01_IRQ)!=0)//�ȴ��������
    {
        //oled_show_int(0, 3, 1, 1);
    }
//    oled_show_string(0, 4, "amd");
    sta=NRF24L01_Read_Reg(STATUS);  //��ȡ״̬�Ĵ�����ֵ
    NRF24L01_Write_Reg(NRF_WRITE_REG+STATUS,sta); //���TX_DS��MAX_RT�жϱ�־
    if(sta&MAX_TX)//�ﵽ����ط�����,û�յ�ACK
    {
        NRF24L01_Write_Reg(FLUSH_TX,0xff);//���TX FIFO�Ĵ���
        return MAX_TX;
    }
    if(sta&TX_OK)//�������
    {
        return TX_OK;
    }
//    return 0xff;//����ԭ����ʧ��
}

//����NRF24L01����һ������
//txbuf:�����������׵�ַ
//����ֵ:0��������ɣ��������������
u8 NRF24L01_RxPacket(u8 *rxbuf)
{
    u8 sta;
    sta=NRF24L01_Read_Reg(STATUS);  //��ȡ״̬�Ĵ�����ֵ

    NRF24L01_Write_Reg(NRF_WRITE_REG+STATUS,sta); //���TX_DS��MAX_RT�жϱ�־
    oled_show_int(0,5,sta,2);
    if(sta&RX_OK)//���յ�����
    {
        NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);//��ȡ����
        NRF24L01_Write_Reg(FLUSH_RX,0xff);//���RX FIFO�Ĵ���
        return 0;
    }
    return 1;//û�յ��κ�����
}

//�ú�����ʼ��NRF24L01��RXģʽ
//����RX��ַ,дRX���ݿ��,ѡ��RFƵ��,�����ʺ�LNA HCURR
//��CE��ߺ�,������RXģʽ,�����Խ���������
void NRF24L01_RX_Mode(void)
{
    gpio_set_level(NRF24L01_CE,0);
    NRF24L01_Write_Buf(NRF_WRITE_REG+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);//дRX�ڵ��ַ

    NRF24L01_Write_Reg(NRF_WRITE_REG+EN_AA,0x01);       //ʹ��ͨ��0���Զ�Ӧ��
    NRF24L01_Write_Reg(NRF_WRITE_REG+EN_RXADDR,0x01);   //ʹ��ͨ��0�Ľ��յ�ַ
    NRF24L01_Write_Reg(NRF_WRITE_REG+RF_CH,40);         //����RFͨ��Ƶ��
    NRF24L01_Write_Reg(NRF_WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);//ѡ��ͨ��0����Ч���ݿ��
    NRF24L01_Write_Reg(NRF_WRITE_REG+RF_SETUP,0x0f);
    //����TX�������,0db����,2Mbps,���������濪��

    NRF24L01_Write_Reg(NRF_WRITE_REG+CONFIG, 0x0f);
    //���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ

    gpio_set_level(NRF24L01_CE,1); //CEΪ��,�������ģʽ
}

//�ú�����ʼ��NRF24L01��TXģʽ
//����TX��ַ,дTX���ݿ��,����RX�Զ�Ӧ��ĵ�ַ,���TX��������,ѡ��RFƵ��,�����ʺ�LNA HCURR
//PWR_UP,CRCʹ��
//��CE��ߺ�,������RXģʽ,�����Խ���������
//CEΪ�ߴ���10us,����������.
void NRF24L01_TX_Mode(void)
{
    gpio_set_level(NRF24L01_CE,0);
    NRF24L01_Write_Buf(NRF_WRITE_REG+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);//дTX�ڵ��ַ
    NRF24L01_Write_Buf(NRF_WRITE_REG+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);
   //����TX�ڵ��ַ,��ҪΪ��ʹ��ACK

    NRF24L01_Write_Reg(NRF_WRITE_REG+EN_AA,0x01);     //ʹ��ͨ��0���Զ�Ӧ��
    NRF24L01_Write_Reg(NRF_WRITE_REG+EN_RXADDR,0x01); //ʹ��ͨ��0�Ľ��յ�ַ
    NRF24L01_Write_Reg(NRF_WRITE_REG+SETUP_RETR,0x1a);
    //�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:10��

    NRF24L01_Write_Reg(NRF_WRITE_REG+RF_CH,40);       //����RFͨ��Ϊ40
    NRF24L01_Write_Reg(NRF_WRITE_REG+RF_SETUP,0x0f);
    //����TX�������,0db����,2Mbps,���������濪��

    NRF24L01_Write_Reg(NRF_WRITE_REG+CONFIG,0x0e);
    //���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�

    gpio_set_level(NRF24L01_CE,1);//CEΪ��,10us����������
    system_delay_ms(1);
}

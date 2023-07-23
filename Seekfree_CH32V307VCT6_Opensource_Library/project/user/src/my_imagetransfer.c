/*
 * my_imagetransfer.c
 *
 *  Created on: 2021年11月30日
 *      Author: hxy
 */

#include "my_imagetransfer.h"
#include "zf_common_function.h"
#define uint8 uint8_t
#define uint32 uint32_t
extern uint8_t BinPixels[70][186];
//定义传输结构体
extern uint8_t LCenter[70], L_black[70], R_black[70]; //拟图三线
//extern uint8_t mt9v03x_image_dvp[MT9V03X_DVP_H][MT9V03X_DVP_W];
My_Data_Type My_Send_Data;
float my_car_data[60];
extern int dj_pwm;
extern int hl_l_pwm;
extern int hl_r_pwm;
extern int road_judge;
extern int cross_flag;
extern uint8 lefty[2], righty[2];
extern int L_up_flag;
extern int R_up_flag;
extern int end_hang;
extern int speed;
extern int go_flag, pot;
extern int error;
extern uint8_t Ostu_Threshold;
extern SPEED hl_l, hl_r;

extern int huandao_flag;
extern int Read_Right_Speed;
extern int Read_Left_Speed;
extern int left_adcnum;
extern int right_adcnum;
extern int frame_num;
extern uint8 ramp_flag;
extern uint8 distance_flag;
extern uint8 circle_lefty[3];
extern uint8 circle_righty[3];
extern uint8 left_targetspeed;
extern uint8 right_targetspeed;
extern uint16_t distance_mm, dl1a_distance_mm;
extern uint8 garage_flag;
extern int sum_encoder;
extern uint8 garage_stop_flag;
extern uint8 beeakDisable;
extern uint8 roadblock_flag;
extern uint8 wandao_frame;
extern uint8 break_frame;
extern float MAX_BREAK_ACC;

extern float Kp2;
//extern int duk,distance_load;
//extern int16_t CZ,CS;
//extern int16_t Speed_Left,Speed_Right,dis_Leave_Last;
//extern uint8 Lose_line,flag_po,using_line;
//extern int Read_Left_Speed,Read_Right_Speed,increase_Left,increase_Right,output_Left,output_Right;
//extern int number_image,number_encoder;
//extern uint8 Left_L_point, Right_L_point, Left_H_point, Right_H_point,Left_mid_point,Right_mid_point,cnt_cirle,flag_slow;
//extern uint8 flag_cirle,flag_trigeminal,cnt_trigeminal,Ostu_Threshold,flag_garage,flag_stop,delay_cirle,delay_tri;
void My_Data_Give(void) //要上传上位机的参数
{
    //最大可储存50个参数
    my_car_data[0] = dj_pwm;
    my_car_data[1] = hl_l_pwm;
    my_car_data[2] = hl_r_pwm;
    my_car_data[3] = road_judge;
    my_car_data[4] = speed;
    my_car_data[5] = lefty[0];
    my_car_data[6] = righty[0];
    my_car_data[7] = lefty[2];
    my_car_data[8] = righty[2];
    my_car_data[9] = ramp_flag;
    my_car_data[10] = cross_flag;
    my_car_data[11] = circle_lefty[1];
    my_car_data[12] = circle_righty[1];
    my_car_data[13] = L_up_flag;
    my_car_data[14] = R_up_flag;
    my_car_data[15] = end_hang;
    my_car_data[16] = Ostu_Threshold;
    my_car_data[17] = huandao_flag;
    my_car_data[18] = Read_Left_Speed;
    my_car_data[19] = Read_Right_Speed;
    my_car_data[20] = distance_flag;
    my_car_data[21] = left_adcnum;
    my_car_data[22] = right_adcnum;
    my_car_data[23] = (int) (Kp2 * 1000);
    my_car_data[24] = left_targetspeed;
    my_car_data[25] = right_targetspeed;
    my_car_data[26] = (int) dl1a_distance_mm;
    my_car_data[27] = (int) hl_l.set_targetS;
    my_car_data[28] = (int) hl_r.set_targetS;
    my_car_data[29] = (int) MAX_BREAK_ACC;
    my_car_data[30] = (int) break_frame;
    my_car_data[31] = (int) (roadblock_flag);
    my_car_data[32] = (int) (garage_stop_flag);
    my_car_data[33] = (int) garage_flag;
//    my_car_data[29] = speed_sum;
//    my_car_data[30] = speed_gap;
//    my_car_data[31] = delay_cirle;
//    my_car_data[32] = dis_Leave_Last;
//    my_car_data[33] = distance_load;
//    my_car_data[34] = delay_tri;
}

//将float传输的函数
void My_floattoint32(uint8_t *p_int, uint8_t *p_float) {
    *p_int = *p_float;
    p_int++;
    p_float++;
    *p_int = *p_float;
    p_int++;
    p_float++;
    *p_int = *p_float;
    p_int++;
    p_float++;
    *p_int = *p_float;
}

void Get_SendData() //填充传输结构体
{
//传输头检验
    My_Send_Data.Verific[0] = 0x01;
    My_Send_Data.Verific[1] = 0x02;
    My_Send_Data.Verific[2] = 0x03;
    My_Send_Data.Verific[3] = 0x04;
    My_Send_Data.Verific[4] = 0x05;
    My_Send_Data.Verific[5] = 0x06;
    My_Send_Data.Verific[6] = 0x07;
    My_Send_Data.Verific[7] = 0x08;
    My_Send_Data.Pixels_width = 186;
    My_Send_Data.Pixels_height = 70;
    My_Send_Data.Coefficient_Num = 50;
    My_Send_Data.Parameter_Num = 1;
//图像获取

#if defined gray//灰度模式 不压缩
    uint8 *p_pixels = My_Send_Data.Pixels;
    uint8 *p_pixels_gray = &Pixels[0][0];
    for(uint32 i = 0;i<Pixels_Len;i++)
    {
        *p_pixels++ = *p_pixels_gray++;
    }
#elif defined bin//二值模式 将8压缩成1位
    uint8 *p_pixels = My_Send_Data.Pixels; //传输变量
    uint8_t *p_pixels_gray = &BinPixels[0][0]; //待压缩变量
    union //定义一个公用体
    {
        uint8 Byte;
        struct Byte8_Struct Byte_Bit;
    } BIT;
    for (uint32 i = 0; i < 1628/*Pixels_Len*/; i++) {
        //将8位压缩成1位
        BIT.Byte_Bit.bit8 = *p_pixels_gray++;
        BIT.Byte_Bit.bit7 = *p_pixels_gray++;
        BIT.Byte_Bit.bit6 = *p_pixels_gray++;
        BIT.Byte_Bit.bit5 = *p_pixels_gray++;
        BIT.Byte_Bit.bit4 = *p_pixels_gray++;
        BIT.Byte_Bit.bit3 = *p_pixels_gray++;
        BIT.Byte_Bit.bit2 = *p_pixels_gray++;
        BIT.Byte_Bit.bit1 = *p_pixels_gray++;
        //将这一位传输到里面
        *p_pixels++ = BIT.Byte;
    }
#endif
//运行参数
    int32_t *p_data = (int32_t*) My_Send_Data.Data_Con;
    for (uint16_t i = 0; i < 50; i++) {
        My_floattoint32((uint8 *) p_data, (uint8 *) &my_car_data[i]);
        *(int32_t *) (p_data + 1) = ~(*(int32_t *) p_data);
        p_data += 2;
    }
//拟图
    My_LCR *my_Lcr = (My_LCR *) My_Send_Data.Lcr; //传拟图所需定义
    for (uint8 i = 0; i < 70; i++) {
        my_Lcr[i].left = (uint8) L_black[i];
        my_Lcr[i].right = (uint8) R_black[i];
        my_Lcr[i].center = (uint8) LCenter[i];
    }

}
static uint32_t my_blockNum = 0;
void My_Tranfer_Init() //传输初始化
{
    uart_init(TRANSFOR_UARST, 640000, TRANSFOR_UARST_TX, TRANSFOR_UARST_RX);
}

/********************************sd卡储存部分****************************************/
void My_SdCard_Init(void) //初始化sd卡储存或读取
{
    sd_init();
    my_blockNum = 0;
    My_Tranfer_Init();
}

#if defined gray//灰度模式 不压缩
static uint8_t Pixels_zip[13020];
#elif defined bin//二值模式 将8压缩成1位
static uint8_t Pixels_zip[2048];
#endif
void My_Lines_Pack() //给出7条线 7*70=490 一个扇区
{
    for (uint8_t i = 0; i < 70; i++) {
        Pixels_zip[1628 + i] = L_black[i];
        Pixels_zip[1628 + i + 70] = LCenter[i];
        Pixels_zip[1628 + i + 140] = R_black[i];
    }
}
void My_Lines_UnPack() //解压三线
{
    for (uint8_t i = 0; i < 70; i++) {
        L_black[i] = Pixels_zip[1628 + i];
        LCenter[i] = Pixels_zip[1628 + i + 70];
        R_black[i] = Pixels_zip[1628 + i + 140];
    }
}
void My_data_Pack(void) {
    union {
        uint8_t data_uint8[4];
        float data_float;
    } data;
    uint8_t *data_define = &Pixels_zip[1838];

    for (uint8_t i = 0; i < 50; i++) {
        data.data_float = my_car_data[i];
        for (uint8_t j = 0; j < 4; j++) {
            *data_define++ = data.data_uint8[j];
        } //写入4个字节
    }
}
void My_data_UnPack(void) {
    union {
        uint8_t data_uint8[4];
        float data_float;
    } data;
    uint8_t *data_define = &Pixels_zip[1838];
    for (uint8_t i = 0; i < 50; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            data.data_uint8[j] = *data_define++;
        }
        my_car_data[i] = data.data_float;
    }
}
uint8 ans = 0;

void My_SdCard_Save() //sd卡储存灰度图及参数
{
    My_Data_Give(); //将参数写入数组
////    My_Lines_Pack();//将三线合一储存以节省扇区

//图像压缩
    uint8_t *p_pixels = Pixels_zip; //传输变量
    uint8_t *p_pixels_gray = &BinPixels[0][0]; //待压缩变量
    union //定义一个公用体
    {
        uint8 Byte;
        struct Byte8_Struct Byte_Bit;
    } BIT;
    for (uint32 i = 0; i < 1628/*Pixels_Len*/; i++) {
        //将8位压缩成1位
        BIT.Byte_Bit.bit8 = *p_pixels_gray++;
        BIT.Byte_Bit.bit7 = *p_pixels_gray++;
        BIT.Byte_Bit.bit6 = *p_pixels_gray++;
        BIT.Byte_Bit.bit5 = *p_pixels_gray++;
        BIT.Byte_Bit.bit4 = *p_pixels_gray++;
        BIT.Byte_Bit.bit3 = *p_pixels_gray++;
        BIT.Byte_Bit.bit2 = *p_pixels_gray++;
        BIT.Byte_Bit.bit1 = *p_pixels_gray++;
        //将这一位传输到里面
        *p_pixels++ = BIT.Byte;
    }
    My_Lines_Pack();
    My_data_Pack();
    ans = sd_WriteDisk(Pixels_zip, my_blockNum, 4); //不管怎样 都存储大图
    my_blockNum += 4;
}
uint8 cmd_mode = 0;
void My_SdCard_Read() //读取sd卡并传输
{

    ans = SD_read_sector_data(Pixels_zip, my_blockNum, 4);
    if (cmd_mode == 0)
        my_blockNum += 4;
//    char cmd=key_scan(50);
//    if(cmd!=0){
//        if(cmd_mode==0) cmd_mode=1;
//        switch(cmd){
//        case 3:my_blockNum+=4;break;
//        case 4:my_blockNum-=4;break;
//        case 1:my_blockNum+=40;break;
//        case 2:my_blockNum=(my_blockNum-40>0?my_blockNum-40:0);break;
//        case 0:break;
//        default :cmd_mode=(cmd_mode==0);
//        }
//    }
    uint8_t *p_pixels = Pixels_zip; //传输变量
    uint8_t *p_pixels_gray = &BinPixels[0][0]; //待压缩变量
    union //定义一个公用体
    {
        uint8 Byte;
        struct Byte8_Struct Byte_Bit;
    } BIT;
    for (uint32 i = 0; i < 1628; i++) {
        //读取解压图像
        BIT.Byte = *p_pixels++;
        //将8位压缩成1位
        *p_pixels_gray++ = BIT.Byte_Bit.bit8;
        *p_pixels_gray++ = BIT.Byte_Bit.bit7;
        *p_pixels_gray++ = BIT.Byte_Bit.bit6;
        *p_pixels_gray++ = BIT.Byte_Bit.bit5;
        *p_pixels_gray++ = BIT.Byte_Bit.bit4;
        *p_pixels_gray++ = BIT.Byte_Bit.bit3;
        *p_pixels_gray++ = BIT.Byte_Bit.bit2;
        *p_pixels_gray++ = BIT.Byte_Bit.bit1;
    }
    My_Lines_UnPack(); //解压三线
//解压自定义数据
    My_data_UnPack();
//传输---------------------------------------------------
    Get_SendData();    //填充传输结构体
    uart_write_buffer(TRANSFOR_UARST, (uint8_t*) &My_Send_Data, Send_Data_Len);
}

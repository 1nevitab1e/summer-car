/*
 * menu.h
 *
 *  Created on: 2021年12月1日
 *      Author: hxy
 */

#ifndef CORE_HDU_LIBRARIES_MENU_H_
#define CORE_HDU_LIBRARIES_MENU_H_

#include "zf_device_oled.h"
//#include "my_flash.h"
#include "zf_common_headfile.h"

//结构体定义
struct item                                     //菜单选项
{
    enum
    {
        subpage=1,                      //页面类型 有子页
        value,
        switc,
        func,
        value_float,
        value_int32,
        title
    }type;

    int32 dlt;                          //每次改动的差值 试用于value
    float dlt_float;
    void *addr;                             //输出在oled上的值 若为子页类型 则为地址
    void (*chf);                              //返回上一级地址

    char name[20];
};
struct huan
{
  int16_t  number;
};
struct pd
{
  float p;
  float p_out;
  float d;
  float d_out;
  float cs;
  float cs_out;
  float sd;
};

struct page
{
    uint8 rpos;                          //第一行位置
    uint8 pos;                           //光标位置
    uint8 count;
    uint8 dymantic_page;                 //动态页

    struct item itemlist[35];
};

//按键
/********************************************My*****************************************************/
#define KEY_1       E4                      //up
#define KEY_2       E6                     //down
#define KEY_3       C13                     //add
#define KEY_4       E5                     //sub
#define KEY_5       D9                     //enter
#define KEY_6       A9                     //leave
#define KEY_7       A8
#define KEY_8       A10
/***************************************************************************************************/
//#define KEY_1       C7                    //up
//#define KEY_2       D14                      //down
//#define KEY_3       C6                     //add
//#define KEY_4       D15                     //sub
//#define KEY_5       D13                     //enter
//#define KEY_6       D12                      //leave

//#define KEY_7       D10                      //一键发车
//#define KEY_8       C6                      //
#define KEY_DelayTime   100                     //按键扫描延时时间
extern uint32 cntpage;//页数
extern struct page *navigate[32];//指针

//函数声明待补充
//函数声明
void add_subpage(struct page * tg, char * name, struct page * v);
void add_value(struct page * tg, char * name, int * v, int16 dt, void (*changedCallBack)());
void add_value_uint8(struct page * tg, char * name, uint8 * v, uint8 dt, void (*changedCallBack)());
void add_value_float(struct page * tg, char * name, float * v, float dt, void (*changedCallBack)());
void add_switc(struct page * tg, char * name, int16 * v, void (*operate)());
void add_func(struct page * tg, char * name, void (*v)());
void add_value_int32(struct page * tg, char * name, int32 * v, int32 dt, void (*changedCallBack)());
void add_title(struct page * tg, char * name, char length);
void MenuRender(char full_update);
void OLED_BeginUpdate(void);
void MenuCmd(char cmd);
void menu_key_init(void);//按键初始化
char key_scan(void);
void MenuInit(struct page *mainpage);
void OLED_EndUpdate(void);
void MyMenu_Init();

#endif /* CORE_HDU_LIBRARIES_MENU_H_ */

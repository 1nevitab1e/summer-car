/*
 * menu.c
 *
 *  Created on: 2023Äê4ÔÂ2ÈÕ
 *      Author: 86131
 */
#include "menu.h"
#include "zf_common_headfile.h"
#include "LED.h"
#include "daojishi.h"
#include "game_bird.h"
#include "snake.h"

extern const MenuInit menu[7];
extern uint8 grade;
//extern uint16_t Lim;
void Menu_Decide(int *sel)
{
    switch (*sel)
    {
        case 1:
            timer_init();
            timer_settime();
            TIM_Cmd(TIM2,DISABLE);
            break;
        case 3:
            game_snake();
            break;
        case 4:
            show_grade();
            break;
        case 5:
            LED_Init();
            LED_Blink(0);
            LED_Clear();
            break;
        case 6:
            LED_Init();
            LED_Blink(1);
            LED_Clear();
            break;
        default:
            break;
    }
}

void Menu_Sel(int *i,int *sel)
{
    if(*i==1)
    {
       *sel=menu[*sel].LNode;
       oled_show_string(1, 1, "      ");
       oled_show_string(1, 1, menu[*sel].content);
       *i=0;
    }
    if(*i==2)
    {
       *sel=menu[*sel].RNode;
       oled_show_string(1, 1, "      ");
       oled_show_string(1, 1, menu[*sel].content);
       *i=0;
    }
    if(*i==3)
    {
       *sel=menu[*sel].FaNode;
       oled_show_string(1, 1, "      ");
       oled_show_string(1, 1, menu[*sel].content);
       *i=0;
    }
    if(*i==4)
    {
       oled_show_string(1, 1, "      ");
       Menu_Decide(sel);
       oled_show_string(1, 0, "we choose");
       oled_show_string(1, 1, menu[*sel].content);
       *i=0;
    }
}

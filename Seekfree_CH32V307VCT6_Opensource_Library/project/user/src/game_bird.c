/*
 * game_bird.c
 *
 *  Created on: 2023年4月10日
 *      Author: 86131
 */

#include "zf_common_headfile.h"
#include "game_bird.h"
#include "KEY.h"

FlappyBird bird={20,12};
ShowProp pillar;

uint8 BirdPos[][16]={{0xff,0xff,0xcb,0xcb,0xff,0xff,0xff,0xff},
                     {0x00,0x00,0xff,0xff,0xcb,0xcb,0xff,0xff,0xff,0xff,0x00,0x00},
                     {0x00,0x00,0x00,0x00,0xff,0xff,0xcb,0xcb,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00},
                     {0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xcb,0xcb,0xff,0xff,0xff,0xff,0x00,0x00},
                     {0}

};
uint8 Brisk;
extern uint8 grade;

void Pillar_Create()
{
    uint16_t Temt;
    timer_start(TIM_2, TIMER_MS);
    Temt=TIM_GetCounter(TIM2);
    pillar.x=30+Temt%10;
    pillar.y=1+Temt%5;
}

//void Bird_Move(uint8 begin,uint8 end,int dir)
//{
//    int i;
//
//    if(dir == -1)
//    {
//        for (i = begin; i >= end; --i)
//        {
//            oled_bird_move(20,i,-1,i%8,bird,BirdPos);
//            system_delay_ms(50);
//        }
//    }
//    if (dir == 1)
//    {
//        for (i = begin; i <= end; ++i)
//        {
//            oled_bird_move(20,i,1,i%8,bird,BirdPos);
//            system_delay_ms(50);
//        }
//    }
//}

void Drop()
{
    bird.y+=2;
    oled_bird_down(bird.x,bird.y-2,BirdPos,bird.y);
}

void Bounce()
{
    int i=0;
    i=Key_Get();
    int sel;
    sel=(bird.y%8)/2;
    if(i == 0)
    {
        bird.y-=6;
        while(i*8+sel*2 >= 0)
                    {
                            oled_show_binary_image(bird.x+10, i, BirdPos[sel], 8, 16, 8, 16);
                            sel--;
                            system_delay_ms(100);
                            if(sel==-1)
                            {
                                i--;
                                sel=3;
                                Bird_Clear(bird.x,i+1);
                            }
                    }
    }
}

uint8 Check()
{
    if((bird.y/8) <= (pillar.y + 1)  && (bird.y/8) >= pillar.y )return 0;
    else return 1;
}


void Game()
{
    uint8 flag,by=0;
    oled_clear();
    Pillar_Create();
    Bird_Create(bird,BirdPos);
    while(1)
    {
        Drop();//自然掉落
        Bounce();//小鸟弹跳

                /*柱子位移*/
                pillar.x-=1;
                oled_wall_clear(pillar.x,pillar.y);
                oled_wall(pillar.x,pillar.y);
                system_delay_ms(50);
                flag=Check();
                if( pillar.x == 10)
                {
                    by=0;
                    oled_wall_clear(pillar.x-7,pillar.y);
                    Pillar_Create();
                }

                    if(bird.x == 119 || (flag!=0 && bird.x <= (pillar.x + 7) && bird.x >= pillar.x-6))//撞到墙则gg并且显示分数和排行
                        {

                            oled_clear();
                            oled_show_string(0, 0, "Grade:");
                            oled_show_uint(14,1,grade,2);

                            while(Key_Get()!=4);
                            oled_clear();
                            oled_show_string(1, 0, "we choose");
                            return;
                        }
                    else if(pillar.x<13 && by==0)//判断加分
                        {
                            by++;
                            grade++;
                        }
    }
}

void Grade()
{
    int i;
    if(grade==0)
    {
        oled_show_string(0, 3, "ERROR:No Record");
    }
    else
    {
        oled_show_string(0, 3, "Congratulation!");
        oled_show_uint(0, 4, grade, 2);
    }
    while((i=Key_Get())!=4);
    oled_show_string(0, 3, "                 ");
    oled_show_string(0, 4, "  ");
}

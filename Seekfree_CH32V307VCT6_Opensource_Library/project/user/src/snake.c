/*
 * snake.c
 *
 *  Created on: 2023年4月16日
 *      Author: 86131
 */
#include "snake.h"
#include "zf_common_headfile.h"
#include "stdlib.h"
#include <time.h>

struct snake  //结构体，用于储存蛇身的位置；
{
 unsigned char x;
 unsigned char y;
} ;
struct snake Pos[20]; //蛇的身体坐标数据；
struct snake food ;//食物的坐标位置；


const unsigned char body[8]={0xFF,0xFF,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF};
const unsigned char wall[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

u8 moveflag=0,foodflag=0,giveup=0,start=0,fun=0;//giveup是食物被舍弃标志位，foodflag是食物刷新标志位，moveflag是移动标志位；
u8 yanshi=60,count=0,page=0,mode=0,point=1;//page用于显示不同的页面，比如游戏结束页面，开始页面等；mode用于识别蛇的运动状态；
u8 head=3,tail=0;//蛇身长度；
uint16_t tim=150;
extern uint16_t Num;
extern uint8 grade;

void show_grade()
{
    oled_show_string(16, 3, "Back Again?");
    oled_show_uint(16, 4, grade, 2);
    while(Key_Get()!=4);
    oled_clear();
    oled_show_string(1, 0, "we choose");
}

void Food_Init()    //食物初始化函数；
{
    u8 i;
    u16 count;
    //timer_start(TIM_2, TIMER_MS);
    while(!foodflag)
    {
      count=rand();
      food.x=count%16;
      food.y=count%8;
      for(i=0;i<head;i++)
      {
          if((food.x==Pos[i].x&&food.y==Pos[i].y)||food.x>=15||food.y>=7||food.x<=1||food.y<=1)//一旦满足这个条件，这个食物
              //数据就应该被舍弃，因为在蛇身或者在地图上；
              giveup=1;
      }
      if(giveup==1)
      {
          foodflag=0;
           giveup=0;
      }
      else
      {
          foodflag=1;
          OLED_SnakeBody(food.x,food.y);
          giveup=0;
          break;
      }
    }
}

void GameLeft()
{
    u8 i=0;
    while((i=Key_Get())!=4);
    oled_clear();
}

void Snake_Init()        //蛇初始化函数；
{
u8 i;
   Pos[0].x=6;
   Pos[0].y=3;
   Pos[1].x=7;
   Pos[1].y=3;
   Pos[2].x=8;
   Pos[2].y=3;
   for(i=0;i<head;i++)
   {
     OLED_SnakeBody(Pos[i].x,Pos[i].y);
   }
}

void Snake_Over()//蛇死亡函数，在死亡之后显示game over,同时不断检测复原键是否被按下;
{
   if(page==2)
   {
      mode=0;//必须清零，否则就会在下一次游戏开始时造成蛇的乱移动；
      timer_stop(TIM_4);//关闭定时器；
      oled_clear();//先清屏；
      while(page==2)
      {
          oled_show_string(16, 3, "game over");
          oled_show_uint(16, 4, head-3, 2);
          system_delay_ms(10000);
          page=0;
          oled_clear();
      }
    }
}

void leftkey()
 {
    if(left==1&&mode!=1&&mode!=2)
        mode=1;
 }
void rightkey()
 {
    if(right==2&&mode!=1&&mode!=2)
        mode=2;
 }
void upkey()
 {
    if(up==3&&mode!=3&&mode!=4)
        mode=3;
 }
void downkey()
 {
    if(down==4&&mode!=3&&mode!=4)
        mode=4;
 }

void  keypros()
{
    leftkey();
    rightkey();
    upkey();
    downkey();
}

void modeleft()
{
   u8 i,j;
   if(mode==1)
   {
      //首先判断是否撞墙；
      if(Pos[head-1].x==0)
      {
        page=2;
      }
      //再判断是否咬到自己的身体；
      if(page==1)
      {

          for(i=0;i<head-1;i++) //这里要注意，千万不要把头部坐标也挤上去，省一点时间；
          {
              if((Pos[head-1].x-1)==Pos[i].x&&Pos[head-1].y==Pos[i].y)
                 page=2;
          }
          //如果既没有撞墙也没有咬到自己  ，那就考虑吃到食物和没有吃到的情况；
      }
      if(page==1)
      {
      //吃到食物的情况；
        if((Pos[head-1].x-1)==food.x&&Pos[head-1].y==food.y)
        {
          head++;//长度加一；
          foodflag=0;//刷新下一次食物；
          Pos[head-1].x=Pos[head-2].x-1;   //改变头部之后，把之前头部的位置运算之后进行赋值；
          Pos[head-1].y=Pos[head-2].y;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新的狗头，就完事了；
        }
        else     //没吃到食物的情况‘
        {
           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//砍断旧尾巴；
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].x--;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新狗头；不能先点亮狗头，不然会造成数据丢失；
        }
      }

   }
}
void moderight()
{
   u8 i,j;
   if(mode==2)
   {
      //首先判断是否撞墙；
      if(Pos[head-1].x==15)
      {
          page=2;
      }
      //再判断是否咬到自己的身体；
      if(page==1)
      {
          for(i=0;i<head-1;i++) //这里要注意，千万不要把头部坐标也挤上去，省一点时间；
          {
              if((Pos[head-1].x+1)==Pos[i].x&&Pos[head-1].y==Pos[i].y)
                                                                  page=2;
          }
       }    //如果既没有撞墙也没有咬到自己  ，那就考虑吃到食物和没有吃到的情况；
      if(page==1)
      {
      //吃到食物的情况；
        if((Pos[head-1].x+1)==food.x&&Pos[head-1].y==food.y)
        {
          head++;//长度加一；
          foodflag=0;//刷新下一次食物；
          Pos[head-1].x=Pos[head-2].x+1;   //改变头部之后，把之前头部的位置运算之后进行赋值；
          Pos[head-1].y=Pos[head-2].y;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新的狗头，就完事了；
        }
        else     //没吃到食物的情况‘
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//砍断旧尾巴；
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].x++;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新狗头；不能先点亮狗头，不然会造成数据丢失；
        }
      }

   }
}
void modeup()
{
   u8 i,j;
   if(mode==3)
   {
      //首先判断是否撞墙；
      if(Pos[head-1].y==0)
      page=2;
      //再判断是否咬到自己的身体；
      if(page==1)
          for(i=0;i<head-1;i++) //这里要注意，千万不要把头部坐标也挤上去，省一点时间；
          {
              if((Pos[head-1].x)==Pos[i].x&&Pos[head-1].y-1==Pos[i].y)
                                                                  page=2;
          }
          //如果既没有撞墙也没有咬到自己  ，那就考虑吃到食物和没有吃到的情况；
      if(page==1)
      {
      //吃到食物的情况；
        if(Pos[head-1].x==food.x&&(Pos[head-1].y-1)==food.y)
        {
          head++;//长度加一；
          foodflag=0;//刷新下一次食物；
          Pos[head-1].x=Pos[head-2].x;   //改变头部之后，把之前头部的位置运算之后赋值给新头部；
          Pos[head-1].y=Pos[head-2].y-1;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新的狗头，就完事了；
        }
        else     //没吃到食物的情况‘
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//砍断旧尾巴；
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].y--;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新狗头；不能先点亮狗头，不然会造成数据丢失；
        }
      }

   }
}
void modedown()
{
   u8 i,j;
   if(mode==4)
   {
      //首先判断是否撞墙；
      if(Pos[head-1].y==7)
      page=2;
      //再判断是否咬到自己的身体；
      if(page==1)
          for(i=0;i<head-1;i++) //这里要注意，千万不要把头部坐标也挤上去，省一点时间；
          {
              if((Pos[head-1].x)==Pos[i].x&&Pos[head-1].y+1==Pos[i].y)
                                                                  page=2;
          }
          //如果既没有撞墙也没有咬到自己  ，那就考虑吃到食物和没有吃到的情况；
      if(page==1)
      {
      //吃到食物的情况；
        if(Pos[head-1].x==food.x&&(Pos[head-1].y+1)==food.y)
        {
          head++;//长度加一；
          foodflag=0;//刷新下一次食物；
          Pos[head-1].x=Pos[head-2].x;   //改变头部之后，把之前头部的位置运算之后赋值给新头部；
          Pos[head-1].y=Pos[head-2].y+1;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新的狗头，就完事了；
        }
        else     //没吃到食物的情况‘
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//砍断旧尾巴；
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].y++;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//点亮新狗头；不能先点亮狗头，不然会造成数据丢失；
        }
      }

   }
}

void modepros()
{
  modeup();
  modeleft();
  modedown();
  moderight();
}

u8 choice()
{
    u8 i=0;
   if(left==1)
   {
       point++;
       if(point>2)
           point=1;
   }
   if(Key_Get()==2)
       i=2;
   return i;
}

void page0()
{
    u8 i;
    oled_show_string(10,0,"greedy snake");
    oled_show_string(20,2,"difficult");
    oled_show_string(20,4,"normal");
    //oled_show_string(20,6,"easy") ;
    while(i!=2)
    {
        if(point==1)
        {
            oled_show_string(10,2,">");
            oled_show_string(10,4," ");
            oled_show_string(10,6," ");
            tim=90;
            page=1;
            start=1;
            foodflag=0;
        }
        if(point==2)
        {
            oled_show_string(10,2," ");
            oled_show_string(10,4,">");
            oled_show_string(10,6," ");
            tim=150;
            page=1;
            start=1;
            foodflag=0;
        }
        i=choice();
    }
}

void makewall()
{
    int x,y;
    for(x=0;x<16;x++)
    {
        if(x==0 || x==15)
        {
            for(y=0;y<8;y++)
            {
                OLED_Wall(x, y);
            }
        }
        else
        {
            OLED_Wall(x, 0);
            OLED_Wall(x, 7);
        }
    }
}

void game_snake()
{
    srand(time(0));
    oled_clear();
    while(1)
      {
        tim=150;
        page=1;
        start=1;
        foodflag=0;
//         while(page==0)
//         {
//           page0();
//         }
          while(page==1)
          {
           if(start==1)
             {
               oled_clear();
               //makewall();
               pit_init_ms(TIM4_PIT,4);
                head=3;
               Snake_Init();
               start=0;
             }
           Food_Init();
           keypros();
          }
          while(page==2)
          {
              pit_disable(TIM4_PIT);
              Num=0;
              Snake_Over();
          }
          break;
      }
}

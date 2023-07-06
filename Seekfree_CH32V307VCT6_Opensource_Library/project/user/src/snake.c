/*
 * snake.c
 *
 *  Created on: 2023��4��16��
 *      Author: 86131
 */
#include "snake.h"
#include "zf_common_headfile.h"
#include "stdlib.h"
#include <time.h>

struct snake  //�ṹ�壬���ڴ��������λ�ã�
{
 unsigned char x;
 unsigned char y;
} ;
struct snake Pos[20]; //�ߵ������������ݣ�
struct snake food ;//ʳ�������λ�ã�


const unsigned char body[8]={0xFF,0xFF,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF};
const unsigned char wall[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

u8 moveflag=0,foodflag=0,giveup=0,start=0,fun=0;//giveup��ʳ�ﱻ������־λ��foodflag��ʳ��ˢ�±�־λ��moveflag���ƶ���־λ��
u8 yanshi=60,count=0,page=0,mode=0,point=1;//page������ʾ��ͬ��ҳ�棬������Ϸ����ҳ�棬��ʼҳ��ȣ�mode����ʶ���ߵ��˶�״̬��
u8 head=3,tail=0;//�����ȣ�
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

void Food_Init()    //ʳ���ʼ��������
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
          if((food.x==Pos[i].x&&food.y==Pos[i].y)||food.x>=15||food.y>=7||food.x<=1||food.y<=1)//һ������������������ʳ��
              //���ݾ�Ӧ�ñ���������Ϊ����������ڵ�ͼ�ϣ�
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

void Snake_Init()        //�߳�ʼ��������
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

void Snake_Over()//������������������֮����ʾgame over,ͬʱ���ϼ�⸴ԭ���Ƿ񱻰���;
{
   if(page==2)
   {
      mode=0;//�������㣬����ͻ�����һ����Ϸ��ʼʱ����ߵ����ƶ���
      timer_stop(TIM_4);//�رն�ʱ����
      oled_clear();//��������
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
      //�����ж��Ƿ�ײǽ��
      if(Pos[head-1].x==0)
      {
        page=2;
      }
      //���ж��Ƿ�ҧ���Լ������壻
      if(page==1)
      {

          for(i=0;i<head-1;i++) //����Ҫע�⣬ǧ��Ҫ��ͷ������Ҳ����ȥ��ʡһ��ʱ�䣻
          {
              if((Pos[head-1].x-1)==Pos[i].x&&Pos[head-1].y==Pos[i].y)
                 page=2;
          }
          //�����û��ײǽҲû��ҧ���Լ�  ���ǾͿ��ǳԵ�ʳ���û�гԵ��������
      }
      if(page==1)
      {
      //�Ե�ʳ��������
        if((Pos[head-1].x-1)==food.x&&Pos[head-1].y==food.y)
        {
          head++;//���ȼ�һ��
          foodflag=0;//ˢ����һ��ʳ�
          Pos[head-1].x=Pos[head-2].x-1;   //�ı�ͷ��֮�󣬰�֮ǰͷ����λ������֮����и�ֵ��
          Pos[head-1].y=Pos[head-2].y;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����µĹ�ͷ���������ˣ�
        }
        else     //û�Ե�ʳ��������
        {
           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//���Ͼ�β�ͣ�
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].x--;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����¹�ͷ�������ȵ�����ͷ����Ȼ��������ݶ�ʧ��
        }
      }

   }
}
void moderight()
{
   u8 i,j;
   if(mode==2)
   {
      //�����ж��Ƿ�ײǽ��
      if(Pos[head-1].x==15)
      {
          page=2;
      }
      //���ж��Ƿ�ҧ���Լ������壻
      if(page==1)
      {
          for(i=0;i<head-1;i++) //����Ҫע�⣬ǧ��Ҫ��ͷ������Ҳ����ȥ��ʡһ��ʱ�䣻
          {
              if((Pos[head-1].x+1)==Pos[i].x&&Pos[head-1].y==Pos[i].y)
                                                                  page=2;
          }
       }    //�����û��ײǽҲû��ҧ���Լ�  ���ǾͿ��ǳԵ�ʳ���û�гԵ��������
      if(page==1)
      {
      //�Ե�ʳ��������
        if((Pos[head-1].x+1)==food.x&&Pos[head-1].y==food.y)
        {
          head++;//���ȼ�һ��
          foodflag=0;//ˢ����һ��ʳ�
          Pos[head-1].x=Pos[head-2].x+1;   //�ı�ͷ��֮�󣬰�֮ǰͷ����λ������֮����и�ֵ��
          Pos[head-1].y=Pos[head-2].y;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����µĹ�ͷ���������ˣ�
        }
        else     //û�Ե�ʳ��������
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//���Ͼ�β�ͣ�
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].x++;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����¹�ͷ�������ȵ�����ͷ����Ȼ��������ݶ�ʧ��
        }
      }

   }
}
void modeup()
{
   u8 i,j;
   if(mode==3)
   {
      //�����ж��Ƿ�ײǽ��
      if(Pos[head-1].y==0)
      page=2;
      //���ж��Ƿ�ҧ���Լ������壻
      if(page==1)
          for(i=0;i<head-1;i++) //����Ҫע�⣬ǧ��Ҫ��ͷ������Ҳ����ȥ��ʡһ��ʱ�䣻
          {
              if((Pos[head-1].x)==Pos[i].x&&Pos[head-1].y-1==Pos[i].y)
                                                                  page=2;
          }
          //�����û��ײǽҲû��ҧ���Լ�  ���ǾͿ��ǳԵ�ʳ���û�гԵ��������
      if(page==1)
      {
      //�Ե�ʳ��������
        if(Pos[head-1].x==food.x&&(Pos[head-1].y-1)==food.y)
        {
          head++;//���ȼ�һ��
          foodflag=0;//ˢ����һ��ʳ�
          Pos[head-1].x=Pos[head-2].x;   //�ı�ͷ��֮�󣬰�֮ǰͷ����λ������֮��ֵ����ͷ����
          Pos[head-1].y=Pos[head-2].y-1;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����µĹ�ͷ���������ˣ�
        }
        else     //û�Ե�ʳ��������
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//���Ͼ�β�ͣ�
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].y--;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����¹�ͷ�������ȵ�����ͷ����Ȼ��������ݶ�ʧ��
        }
      }

   }
}
void modedown()
{
   u8 i,j;
   if(mode==4)
   {
      //�����ж��Ƿ�ײǽ��
      if(Pos[head-1].y==7)
      page=2;
      //���ж��Ƿ�ҧ���Լ������壻
      if(page==1)
          for(i=0;i<head-1;i++) //����Ҫע�⣬ǧ��Ҫ��ͷ������Ҳ����ȥ��ʡһ��ʱ�䣻
          {
              if((Pos[head-1].x)==Pos[i].x&&Pos[head-1].y+1==Pos[i].y)
                                                                  page=2;
          }
          //�����û��ײǽҲû��ҧ���Լ�  ���ǾͿ��ǳԵ�ʳ���û�гԵ��������
      if(page==1)
      {
      //�Ե�ʳ��������
        if(Pos[head-1].x==food.x&&(Pos[head-1].y+1)==food.y)
        {
          head++;//���ȼ�һ��
          foodflag=0;//ˢ����һ��ʳ�
          Pos[head-1].x=Pos[head-2].x;   //�ı�ͷ��֮�󣬰�֮ǰͷ����λ������֮��ֵ����ͷ����
          Pos[head-1].y=Pos[head-2].y+1;
          OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����µĹ�ͷ���������ˣ�
        }
        else     //û�Ե�ʳ��������
        {

           OLED_CLR_Body(Pos[tail].x,Pos[tail].y);//���Ͼ�β�ͣ�
           for(j=0;j<head-1;j++)
           {
             Pos[j].x=Pos[j+1].x;
             Pos[j].y=Pos[j+1].y;
           }
            Pos[head-1].y++;
           OLED_SnakeBody(Pos[head-1].x,Pos[head-1].y);//�����¹�ͷ�������ȵ�����ͷ����Ȼ��������ݶ�ʧ��
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

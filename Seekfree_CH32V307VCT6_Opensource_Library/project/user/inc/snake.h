/*
 * snake.h
 *
 *  Created on: 2023��4��16��
 *      Author: 86131
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include "zf_common_headfile.h"
#include "KEY.h"

#define left Key_Get()
#define right Key_Get()
#define up Key_Get()
#define down Key_Get()

void show_grade();
void Food_Init();    //ʳ���ʼ��������
void GameLeft();//����4�뿪
void Snake_Init();
void Snake_Over();//������������������֮����ʾgame over,ͬʱ���ϼ�⸴ԭ���Ƿ񱻰���;
void leftkey();
void rightkey();
void upkey();
void downkey();
void keypros();
void modeleft();
void moderight();
void modeup();
void modedown();
void modepros();
u8 choice();
void page0();
void makewall();
void game_snake();

#endif /* SNAKE_H_ */

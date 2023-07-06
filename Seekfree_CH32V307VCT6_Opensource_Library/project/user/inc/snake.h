/*
 * snake.h
 *
 *  Created on: 2023年4月16日
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
void Food_Init();    //食物初始化函数；
void GameLeft();//按下4离开
void Snake_Init();
void Snake_Over();//蛇死亡函数，在死亡之后显示game over,同时不断检测复原键是否被按下;
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

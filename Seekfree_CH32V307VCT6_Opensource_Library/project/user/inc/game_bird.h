/*
 * game_bird.h
 *
 *  Created on: 2023Äê4ÔÂ10ÈÕ
 *      Author: 86131
 */

#ifndef GAME_BIRD_H_
#define GAME_BIRD_H_

typedef struct Prop
{
    uint8 x;
    uint8 y;
}ShowProp;

typedef struct Bird
{
    uint8 x;
    uint8 y;
}FlappyBird;

void Pillar_Create();
//void Bird_Move(uint8 begin,uint8 end,int dir);
void Drop();
void Bounce();
uint8 Check();
void Game();
void Grade();
#endif /* GAME_BIRD_H_ */

/*
 * menu.h
 *
 *  Created on: 2023��4��2��
 *      Author: 86131
 */

#ifndef MENU_H_
#define MENU_H_

typedef struct Menu
{
  unsigned char FaNode;//��һ��
  const char *content;
  unsigned char LNode;//ͬһ������һ��
  unsigned char RNode;//��һ��
}MenuInit;

void Menu_Decide(int *sel);
void Menu_Sel(int *i,int *sel);

#endif /* MENU_H_ */

/*
 * menu.h
 *
 *  Created on: 2023年4月2日
 *      Author: 86131
 */

#ifndef MENU_H_
#define MENU_H_

typedef struct Menu
{
  unsigned char FaNode;//上一个
  const char *content;
  unsigned char LNode;//同一级的下一个
  unsigned char RNode;//下一级
}MenuInit;

void Menu_Decide(int *sel);
void Menu_Sel(int *i,int *sel);

#endif /* MENU_H_ */

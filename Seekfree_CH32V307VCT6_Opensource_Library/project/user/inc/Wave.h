/*
 * Wave.h
 *
 *  Created on: 2023��7��7��
 *      Author: 86131
 */

#ifndef WAVE_H_
#define WAVE_H_

#include "zf_common_headfile.h"

#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //ȡ��int�ͱ����ĵ��ֽ�
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))     //    ȡ�洢�ڴ˱�����һ�ڴ��ֽڵ����ݣ����ֽ�
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

void WaveSend(u8 n,u16 *Data);

#endif /* WAVE_H_ */

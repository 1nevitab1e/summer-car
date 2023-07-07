/*
 * Wave.h
 *
 *  Created on: 2023年7月7日
 *      Author: 86131
 */

#ifndef WAVE_H_
#define WAVE_H_

#include "zf_common_headfile.h"

#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //取出int型变量的低字节
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))     //    取存储在此变量下一内存字节的内容，高字节
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

void WaveSend(u8 n,u16 *Data);

#endif /* WAVE_H_ */

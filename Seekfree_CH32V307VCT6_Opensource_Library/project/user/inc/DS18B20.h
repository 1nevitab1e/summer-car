/*
 * DS18B20.h
 *
 *  Created on: 2023Äê5ÔÂ13ÈÕ
 *      Author: 86131
 */

#ifndef DS18B20_H_
#define DS18B20_H_

#include "zf_common_headfile.h"

/*OneWire*/

u8 OneWire_Init();
void OneWire_SendBit(u8 Bit);
u8 OneWire_ReceiveBit();
void OneWire_SendByte(u8 Byte);
u8 OneWire_ReceiveByte();

/*DS18B20*/

void DS18B20_Convert_T();
float DS18B20_ReadT();

#endif /* DS18B20_H_ */

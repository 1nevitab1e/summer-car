/*
 * Filter.h
 *
 *  Created on: 2023Äê7ÔÂ7ÈÕ
 *      Author: 86131
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "zf_common_headfile.h"

#define K 0.3
#define dt 0.1

u16 Filter(int16 angle ,int16 gyro ,int16 acc);

#endif /* FILTER_H_ */

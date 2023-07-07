/*
 * Filter.h
 *
 *  Created on: 2023Äê7ÔÂ7ÈÕ
 *      Author: 86131
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "zf_common_headfile.h"

#define K 0.97
#define dt 0.01

u16 Filter(u16 angle ,u16 gyro ,u16 acc);

#endif /* FILTER_H_ */

/*
 * Current.c
 *
 *  Created on: 2023Äê5ÔÂ14ÈÕ
 *      Author: 86131
 */

#include "Current.h"

#define CurrentIO ADC_IN9_B1
#define R_cur 10.0

float Get_AveCur()
{
    float result;
        result=R_cur*adc_mean_filter(CurrentIO,ADC_12BIT,5)/4096.0;
        oled_show_string(0, 0, "Current:");
        oled_show_float(70, 0, result, 2, 2);
        oled_show_string(111, 0, "mA");
    return result;
}

#ifndef _ADC_H
#define _ADC_H

#include "types.h"

void Init_ADC(void);
void Read_ADC(u32 CHNO,u32 *AdcDval,f32 *eAR);

#endif
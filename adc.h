
#ifndef ADC_H_
#define ADC_H_

#include "main.h"

//uint8_t adc_h, adc_l;
//uint16_t adc_hl;

void ADC_Init(void);
uint16_t ADC_Convert(uint8_t h, uint8_t l);



#endif /* ADC_H_ */
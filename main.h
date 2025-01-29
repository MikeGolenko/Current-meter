


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "tm1637.h"
#include "adc.h"
#include "sound.h"

#define LED 4
#define KAD -4


volatile uint8_t cnt1,cnt2,cnt3,cnt4;



#endif /* MAIN_H_ */
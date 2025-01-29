#include "adc.h"

void ADC_Init(){
	ADMUX = 0;
	ADCSRA = 0;
	ADCSRB = 0;
	
	ADMUX|= (0 << ADLAR);//|(1 << MUX0);//�������� � ADCH
	ADCSRA |= (1<<ADEN) // ���������� ������������� ���
	|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//�������� 128 = 64 ���
	DIDR0 = 1;
}

uint16_t ADC_Convert(uint8_t h, uint8_t l){
	uint16_t hl = 0;
	hl = ((hl|h)<<8)|l;
	return hl;
}

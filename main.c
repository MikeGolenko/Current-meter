#include "main.h"

void timer2_init(void){
	TCCR2A |=(1<<WGM21);
	TCCR2B |=(1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK2 |=(1<<OCIE2A);//|(1<<OCIE2B);
	OCR2A = 77;//2*1024*(1+38)/8000000=0.01
	//OCR2B = 77;
}
void USART_init(void){
	UBRR0H = 0;
	UBRR0L = 51;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<USBS0)|(1<<UCSZ00);
}
void USART_transmit(uint8_t d){
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0 = d;
}

ISR (TIMER2_COMPA_vect){
	if(cnt1) cnt1--;
	if(cnt2) cnt2--;
	if(cnt3) cnt3--;
	if(cnt4) cnt4--;
}



uint16_t a,a1,a2,a3,a0 = 0;
uint8_t adc_h, adc_l;
uint16_t adc_hl;
uint8_t flag_alarm1;
int8_t K_adc;

int main(void)
{
	timer2_init();
	TM1637_init();
	ADC_Init();
	USART_init();
	DDRD |=(1<<LED);
	DDRD |=(1<<5);

	TM1637_setSegments((uint8_t[]) { 0, 0, 0, TM1637_0 }, 4, 0);
	TM1637_turnOnAndSetBrightness(1);
	sei();
						    ADCSRA |= (1 << ADSC);        //starting the conversion
						    while(ADCSRA & (1 << ADSC));  //checking whether the analog-to-digital conversion is completed
						    adc_l = ADCL;
						    adc_h = ADCH;
						    adc_hl = ADC_Convert(adc_h,adc_l);
	K_adc = 512 - adc_hl;//Zero correction factor
	
	melody_01();
	
    while (1) 
    {
				if(cnt2==0){PORTD ^= (1<<LED);
					//flag_dot = !flag_dot;
				cnt2=100;}
				
				if(cnt1==0){
					    ADCSRA |= (1 << ADSC);        //starting the conversion
					    while(ADCSRA & (1 << ADSC));  //checking whether the analog-to-digital conversion is completed
					    adc_l = ADCL;
						adc_h = ADCH;
						adc_hl = ADC_Convert(adc_h,adc_l);
						if((adc_hl>=(507-K_adc))&&(adc_hl<=(517-K_adc))){a=0;};//near-zero zone
						if(adc_hl<(507-K_adc)){a=((512-K_adc)-adc_hl)*7;flag_dot = !flag_dot;};//positive zone
						if(adc_hl>(517-K_adc)){a=(adc_hl-(512-K_adc))*7;flag_dot = 1;};	//negative zone
					a3=a2;//updating data on three dimensions
					a2=a1;
					a1=a;
					a0 = (a1+a2+a3)/3;//average the data over three dimensions
					if((a0 > 1000)&&(a0 <= 1500)){flag_alarm1=1;cnt3=5;}//10À-15À alarm 5/50
					else if((a0 > 1500)&&(a0 <= 2000)){flag_alarm1=1;cnt3=20;}//15A-20A alarm 20/50
							else if(a0 > 2000){flag_alarm1=1;cnt3=50;}//>20A alarm 50/50
						else{flag_alarm1=0;}
							USART_transmit(a0);
					TM1637_displayNumber(a0);
					cnt1=50;
				}
				
				if(flag_alarm1==1){ while(cnt3){sound(2, MI);}flag_alarm1=0;}
				
    }
}


#include "sound.h"

void del_us(uint16_t i){while(--i){asm("NOP");asm("NOP");asm("NOP");asm("NOP");}}//delay 1 us

void sound(uint8_t time, uint16_t fs){cnt4=time;while(cnt4){PORTD^=(1<<pin_sound);del_us(fs);}}

void pause (uint8_t time){cnt4=time;while(cnt4){PORTD&=~(1<<5);}}

		void melody_01(){
			for(uint8_t i=1;i<=14;i++){
				switch(i){
					case 1: sound(30, MI); break;
					case 2:pause(10); break;
					case 3: sound(30, DO); break;
					case 4:pause(10); break;
					case 5: sound(30, MI); break;
					case 6:pause(10); break;
					case 7: sound(30, DO); break;
					case 8:pause(10); break;
					case 9: sound(30, FA); break;
					case 10:pause(10); break;
					case 11: sound(30,MI); break;
					case 12:pause(10); break;
					case 13: sound(30,RE); break;
					case 14:pause(10); break;
				}}}

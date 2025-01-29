
#ifndef SOUND_H_
#define SOUND_H_

#include "main.h"

#define pin_sound 5

//the duration of the half-cycle for each note
#define CI_0    2041
#define DO      1908
#define DO_dz   1805
#define RE      1701
#define RE_dz   1608
#define MI      1515
#define FA      1433
#define FA_dz   1351
#define SOL     1275
#define SOL_dz  1205
#define LA      1136
#define LA_dz   1073
#define CI      1012
#define DO_2    956
#define DO_2_dz 903
#define RE_2    852
#define RE_2_ds 804
#define MI_2    759
#define FA_2    716

void del_us(uint16_t i);//1us delay
void sound (uint8_t time, uint16_t fs);//note function
void pause (uint8_t time);//pause function
void melody_01();



#endif /* SOUND_H_ */
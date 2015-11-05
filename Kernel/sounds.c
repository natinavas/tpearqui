#include "sounds.h"

extern void _int_start_sound();


void beep(){
	_int_start_sound();
}

void piano(uint8_t frec){
	_int_play_sound(frec);
}
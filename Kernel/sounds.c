#include "sounds.h"
#include <stdint.h>




void play_sound(uint32_t nFrequence); 

extern void outb(uint8_t, uint8_t);
extern uint8_t inb(uint8_t);



//extern void _int_start_sound();
//extern void beep();
extern void _int_start_sound(uint32_t nFrequence);
extern void _int_end_sound();
//extern void nosound();

 void beep() {
 	 play_sound(440);
 	 //timer_wait(10);
 	 nosound();
     //set_PIT_2(old_frequency);
 }

 void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
    //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0xb6, 0x43);
 	outb((uint8_t) (Div), 0x42);
 	outb((uint8_t) (Div >> 8), 0x42);
 
    //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(tmp | 3, 0x61);
 	}
 }
 
 //make it shutup
 void nosound() {
 	uint8_t tmp = inb(0x61) & 0xFC;
 
 	outb(tmp, 0x61);
 }


void playPiano(uint8_t frec){
		if(frec == 0){
			_int_end_sound();
		}else{
			_int_start_sound(frec);
		}
}
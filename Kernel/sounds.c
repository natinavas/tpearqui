#include "sounds.h"
#include <stdint.h>




void play_sound(uint32_t nFrequence); 

extern void outb(uint8_t, uint8_t);
extern uint8_t inb(uint8_t);



//extern void _int_start_sound();
//extern void beep();
//extern void play_sound(uint32_t nFrequence);
//extern void nosound();

 void beep() {
 	 play_sound(2000);
 	 //timer_wait(10);
 	 nosound();
          //set_PIT_2(old_frequency);
 }

 void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8_t) (Div) );
 	outb(0x42, (uint8_t) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }
 
 //make it shutup
 void nosound() {
 	uint8_t tmp = inb(0x61) & 0xFC;
 
 	outb(0x61, tmp);
 }


void piano(uint8_t frec){
	while(1){
		if(frec == 8){
			break;
		}
		if(frec == 0){
			_int_end_sound();
		}else{
			_int_start_sound(frec);
		}
	
	}
	

	print_message("ya me fui aprete enter", 0xFF);
}
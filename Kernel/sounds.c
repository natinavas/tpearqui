#include "sounds.h"
#include <stdint.h>

void play_sound(uint32_t nFrequence); 

extern void outb(uint8_t, uint8_t);
extern uint8_t inb(uint8_t);
extern void _song_note(uint32_t frec, uint32_t length);


//extern void _int_start_sound();
//extern void beep();
extern void _int_start_sound(uint32_t nFrequence);
extern void _int_end_sound();
//extern void nosound();

void read_song(uint64_t songNum){
	if(songNum == 1){
		uint32_t arraySong[12] = {C4, F4S, G5, C4, A5, A4, B5, B4, G5, C4, A5, A4};
		uint32_t lengths[12] = {400,25, 320, 400, 564, 234,543,766,234,300,400,500};
		play_song(arraySong, lengths, 12);
	}else if(songNum == 2 ){
		uint32_t arraySong2[3] = {C4, F4S, G5};
		uint32_t lengths2[3] = {200,250, 520};
		play_song(arraySong2, lengths2, 3);
	}
}


void play_song(uint32_t freqs[], uint32_t lengths[], uint32_t size){
	
	uint32_t i = 0;
	
	for(int i=0; i<size; i++){
		if(i%2 == 0)
			_song_note(freqs[i], lengths[i]);
		else
			_song_note(freqs[i], lengths[i]);
	}	
}


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


void playPiano(uint32_t frec){
		if(frec == 0){
			_int_end_sound();
		}else{
			_int_start_sound(frec);
		}
}
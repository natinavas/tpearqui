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

//1600 negra

void read_song(uint64_t songNum){
	if(songNum == 1){
		uint32_t arraySong[73] = 	{C4S, G4S, C5S, E5, C5S, G4S, E4, G4S, 
									C4S, G4S, C5S, E5, C5S, G4S, E4, G4S,
									D4S, A4, C5S, D5S, C5S, A4, E4, F4S,
									D4S, G4S, C5, D5S, C5, G4S, G3S, G4S,
									A3, A4, C5S, E5, C5S, A4, E4, A4,
									C4S, G4S, C5S, E5, C5S, G4S, G3S, G4S,
									A3, G4, C5S, G5, C5S, G4, E4, G4,
									A3, G4, C5S, F5S,
									D4, A4, D5, F5S, D5, A4, F4S, A4,
									D4, G4S, D5, F5S, F5};
		
		uint32_t lengths[73] = 		{1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 
									1200, 1200, 1200, 4800,
									1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
									1200, 1200, 1200, 1200, 3600};
		play_song(arraySong, lengths, 73);
	}else if(songNum == 2 ){
		uint32_t arraySong2[28] =  {G4S, A4S, C5S, A4S, F5,  F5,  D5S,
									G4S, A4S, C5S, A4S, D5S, D5S, C5S, C5, A4S,
									G4S, A4S, C5S, A4S, C5S, D5S, C5,  C5, A4S, G4S, D5S, C5S};
		uint32_t lengths2[28] =	   {400, 400, 400, 400, 1200, 1200, 2400,
									400, 400, 400, 400, 1200, 1200, 2000, 800, 800,
									400, 400, 400, 400, 1600, 800, 1600, 400, 800, 800, 1200, 3200};
		play_song(arraySong2, lengths2, 28);
	}
}


void play_song(uint32_t freqs[], uint32_t lengths[], uint32_t size){
	
	//uint32_t i = 0;
	
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
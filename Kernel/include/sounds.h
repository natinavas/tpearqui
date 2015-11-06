#ifndef SOUNDS_H
#define SOUNDS_H

#define C4 9121
#define C4S 8609
#define D4 8126
#define D4S 7670
#define E4 7239
#define F4 6833
#define F4S 6449 
#define G4 6087
#define G4S 5743
#define A4 5423
#define AS 5119
#define B4 4831
#define C5 4560
#define C5S 4304
#define D5 4063
#define D5S 3834
#define E5 3619
#define F5 3416
#define F5S 3224
#define G5 3043
#define G5S 2873
#define A5 2711
#define A5S 2559
#define B5 2415
#define C5 2280
 
 
#include <stdint.h>

void beep();
void play_sound(uint32_t nFrequence);
void nosound();
void playPiano(uint32_t frec);
void play_song(uint32_t freqs[], uint32_t lengths[], uint32_t size);

#endif
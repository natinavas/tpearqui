#ifndef SOUNDS_H
#define SOUNDS_H

#include <stdint.h>

void beep();
void play_sound(uint32_t nFrequence);
void nosound();
void playPiano(uint8_t frec);

#endif
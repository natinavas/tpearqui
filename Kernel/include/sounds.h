#ifndef SOUNDS_H
#define SOUNDS_H

#include <stdint.h>

void beep();
void play_sound(uint32_t nFrequence);
void nosound();
void playPiano(uint32_t frec);
void play_song(uint32_t freqs[], uint32_t size);

#endif
#include <stdint.h>
#include "include/handlers.h"


static int time = 0;
uint16_t sleep_time = 0;
uint32_t screensaver_time = 5 * 1000 / 55;


C	130.81	9121 	q
C#	138.59	8609	2
D	146.83	8126	w
D#	155.56	7670	3
E	164.81	7239	e
F	174.61	6833	r
F#	185.00	6449	5
G	196.00	6087	t
G#	207.65	5746	6
A	220.00	5423	y
A#	233.08	5119	7
B	246.94	4831	u
C	261.63	4560	o					Middle C
C#	277.18	4304	0
D	293.66	4063	z
D#	311.13	3834	s
E	329.63	3619	x
F	349.23	3416	c
F#	369.99	3224	f
G	391.00	3043	v
G#	415.30	2873	g
A	440.00	2711	b
A#	466.16	2559	h
B	493.88	2415	n
C	523.25	2280	m



	unsigned char kbdus[128] =
	{
    0,  27, '1', 8609, 7670, '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  9121, 8126, 7239, 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    '?',	/* Up Arrow */
    0,	/* Page Up */
  '-',
   '<',	/* Left Arrow */
    0,
   '>',	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    '!',	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};



void timer_handler(){
	time++;
	sleep_time++;
	if(sleep_time >= screensaver_time){
		if(sleep_time < screensaver_time + 10){
			save_screen();
			sleep_time = screensaver_time + 10;
		}
		if((sleep_time % 10) == 0){
			show_screensaver();
		}
	}else{
		if(time >= 10){
			print_standby();
			time = 0;
		}
	}
}

void keyboard_handler(uint8_t scancode){
	if(scancode != 250){
		
		if(sleep_time >= screensaver_time){
			restore_screen();
		}else{
			if(check_special_key(scancode)){
				if(keyboard_set_key(scancode_to_char(scancode)))
					sys_write(scancode_to_char(scancode),0xFF);
			}
		}
		sleep_time = 0;
	}

}

void piano_handler(uint8_t scancode){
	
	if(sleep_time >= screensaver_time){
		restore_screen();
	
	
	}else{
		piano(kdbus[scancode]);
	
	}
	
	sleep_time = 0;
	return;
}



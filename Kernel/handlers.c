#include <stdint.h>
#include "include/handlers.h"

static int time = 0;
uint16_t sleep_time = 0;
uint32_t screensaver_time = 5 * 1000 / 55;

	unsigned char kbdus[128] =
	{
    0,  27, 0, 8609, 7670, 0, 6449, 5746, 5119, 0,	/* 9 */
  	0, 4304, 0, 0, 0,	/* Backspace */
    0,			/* Tab */
 	9121, 8126, 7239, 6833,	/* 19 */
 	6087, 5423, 4831, 0, 4560, 0, 0, 0, 8,	/* Enter key */
    0,			/* 29   - Control */
	0, 3834, 0, 3224, 2873, 2559, 0, 0, 0, 0,	/* 39 */
	0, 0,   0,		/* Left shift */
 	0, 4063, 3619, 3416, 3043, 2711, 2415,			/* 49 */
 	2280, 0, 0, 0,   0,				/* Right shift */
  	0,
    0,	/* Alt */
  	8,	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  	0,
  	0,	/* Left Arrow */
    0,
   	0,	/* Right Arrow */
  	0,
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
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
		print_number(kbdus[scancode]);
		if(scancode != 250){
			
		print_message("entro a piano_handler", 0xFF);
		 if(sleep_time >= screensaver_time){
	 		restore_screen();
	
	 	}else{
	 		piano(kbdus[scancode]);
	 	}

	 	sleep_time = 0;
	}
 	return;
}



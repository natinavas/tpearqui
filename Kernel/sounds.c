#include "sounds.h"
#include <stdint.h>

extern void _int_start_sound();


void beep(){
	_int_start_sound();
}

void piano(uint8_t frec){
	
	while(frec != 9121){
		
		if(frec == 0){
			_int_end_sound();
		}else{
			_int_start_sound(frec);
		}
	
	}

	print_message("ya me fui aprete enter", 0xFF);
}
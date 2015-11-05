#include <stdint.h>
#include "keyboard.h"

uint8_t left_shift = 0;
uint8_t right_shift = 0;
uint8_t caps_lock = 0;

uint8_t keyboard[90][3] = {
	{0,0,0},//000
	{0,0,8},//001 ESCAPE
	{'1','!',0},	//002
	{'2','@',0},	//003
	{'3','#',0},	//004
	{'4','$',0},	//005
	{'5','%',0},	//006
	{'6','^',0},	//007
	{'7','&',0},	//008
	{'8','*',0},	//009
	{'9','(',0},	//010
	{'0',')',0},	//011
	{'-','_',0},	//012
	{'=','+',0},	//013
	{'\b','\b',0},	//014 BACKSPACE
	{'\t','\t',0},	//015 TAB
	{'q','Q',9121},	//016
	{'w','W',8126},	//017
	{'e','E',7239},	//018
	{'r','R',6833},	//019
	{'t','T',6087},	//020
	{'y','Y',5423},	//021
	{'u','U',4831},	//022
	{'i','I',4560},	//023
	{'o','O',0},	//024
	{'p','P',0},	//025
	{'[','{',0},	//026
	{']','}',0},	//027
	{'\n','\n',0},	//028
	{0,0,0},//029 CTRL IZQ
	{'a','A',0},	//030
	{'s','S',3834},	//031
	{'d','D',0},	//032
	{'f','F',3224},	//033
	{'g','G',2873},	//034
	{'h','H',2559},	//035
	{'j','J',0},	//036
	{'k','K',0},	//037
	{'l','L',0},	//038
	{';',':',0},	//039
	{'\'','\"',0},	//040
	{'`','~',0},	//041
	{0,0,0},//042 SHIFT IZQ
	{'\\','|',0},	//043
	{'z','Z',4063},	//044
	{'x','X',3619},	//045
	{'c','C',3416},	//046
	{'v','V',3043},	//047
	{'b','B',2711},	//048
	{'n','N',2415},	//049
	{'m','M',2280},	//050
	{',','<',0},	//051
	{'.','>',0},	//052
	{'/','?',0},	//053 
	{0,0,0},//054 SHIFT DER
	{'*','*',0},	//055 KEY *
	{0,0,0},//056 ALT IZQ
	{' ',' ',0},	//057 SPACE
	{0,0,0},//058 CAPSLOCK
	{0,0,0},//059 F1
	{0,0,0},//060 F2
	{0,0,0},//061 F3
	{0,0,0},//062 F4
	{0,0,0},//063 F5
	{0,0,0},//064 F6
	{0,0,0},//065 F7
	{0,0,0},//066 F8
	{0,0,0},//067 F9
	{0,0,0},//068 F10
	{0,0,0},//069 NUM LOCK
	{0,0,0},//070 SCROLL LOCK
	{'7','7',5119},	//071 KEY 7
	{'8','8',0},	//072 KEY 8
	{'9','9',4304},	//073 KEY 9
	{'-','-',0},	//074 KEY -
	{'4','4',0},	//075 KEY 4
	{'5','5',6449},	//076 KEY 5
	{'6','6',5746},	//077 KEY 6
	{'+','+',0},	//078 KEY +
	{'1','1',0},	//079 KEY 1
	{'2','2',8609},	//080 KEY 2
	{'3','3',7670},	//081 KEY 3
	{'0','0',0},	//082 KEY 0
	{'.','.',0},	//083 KEY .
	{0,0,0},//084 SYS REQ (AT)
	{'+','*',0},	//085
	{'+','*',0},	//086
	{0,0,0},//087 F11
	{0,0,0},//088 F12
	{'+','*',0},	//089
};
uint8_t check_special_key(uint8_t c){
	if(c == 58){
		if(caps_lock){
			caps_lock = 0;
		}else{
			caps_lock = 1;
		}
		return 0;
	}else if(c == 54){
		right_shift = 1;
		return 0;
	}else if(c == 42){
		left_shift = 1;
		return 0;
	}else if(c == 54 + 0x80){
		right_shift = 0;
		return 0;
	}else if(c == 42 + 0x80){
		left_shift = 0;
		return 0;
	}else if(c > 90){
		return 0;
	}
	return 1;
}
int is_alpha(unsigned char scancode){
	return ( (keyboard[scancode][0] >= (unsigned char)'a')  && (keyboard[scancode][0] <= (unsigned char)'z') );
}

int getFrec(uint8_t scancode){
	return keyboard[scancode][2];
}

uint8_t scancode_to_char(uint8_t c) {
	int key;
	
	//Con este if determino si imprimo en Mayuscula o Minuscula
	if( caps_lock == 0 ){
		if( left_shift || right_shift ){
			key = 1;
		} else {
			key = 0;
		}
	} else {
		if( left_shift || right_shift ) {
			if( is_alpha(c) ){
				key = 0;
			} else {
				key = 1;
			}
		}else{
			if( is_alpha(c) ){
				key = 1;
			} else {
				key = 0;
			}
		}
	}
	return keyboard[c][key];
}
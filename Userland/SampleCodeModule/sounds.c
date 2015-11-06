#include "sounds.h"
#include "lib.h"

void beep(){
	_call_int80(INT_BEEP);
}

void songs(){
	int flag = 1;
	print_message("Choose the number of the masterpiece you wish to hear: \n",0xFF);
	print_message("1. song1\n", 0xFF);
	print_message("2. song2\n", 0xFF);
	print_message("3. song3\n", 0xFF);
	print_message("4. song4\n", 0xFF);
	char aux[10];
	
	while(flag){
		readKeyboard(aux);
		uint64_t value = atoi(aux); 
		if(value >= 0 && value <=4){
			flag = 0;
			_call_int80(INT_SONGS, value);
		}
	}
}
	

	void piano(){
	
		print_message(" _______________________________________ \n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  |2| |3|  |  |5| |6| |7|  |  |9| | |  |\n",0xFF);
		print_message("|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |\n",0xFF);
		print_message("|   |   |   |   |   |   |   |   |   |   |\n",0xFF);
		print_message("| Q | W | E | R | T | Y | U | I |   |   |\n",0xFF);
		print_message("|___|___|___|___|___|___|___|___|___|___|\n\n ",0xFF);
	
	
		print_message(" _______________________________________ \n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
		print_message("|  | | |S|  |  |F| |G| |H|  |  | | | |  |\n",0xFF);
		print_message("|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |\n",0xFF);
		print_message("|   |   |   |   |   |   |   |   |   |   |\n",0xFF);
		print_message("|   | Z | X | C | V | B | N | M |   |   |\n",0xFF);
		print_message("|___|___|___|___|___|___|___|___|___|___|\n\n ",0xFF);
	
		_call_int80(INT_PIANO);
	
	}
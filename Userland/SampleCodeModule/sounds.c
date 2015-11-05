#include "sounds.h"
#include "lib.h"

void beep(){
	_call_int80(INT_BEEP);
}

void songs(){
	print_message("Choose the masterpiece you wish to hear: \n",0xFF);

}

void piano(){
	print_message(" _______________________________________ \n",0xFF);
	print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
	print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
	print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
	print_message("|  | | | |  |  | | | | | |  |  | | | |  |\n",0xFF);
	print_message("|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |\n",0xFF);
	print_message("|   |   |   |   |   |   |   |   |   |   |\n",0xFF);
	print_message("|   |   |   |   |   |   |   |   |   |   |\n",0xFF);
	print_message("|___|___|___|___|___|___|___|___|___|___|\n\n ",0xFF);
	
	
}
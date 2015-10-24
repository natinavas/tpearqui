#include "screensaver.h"

void show_screensaver(){
	erase_screen();
	reset_current_video();
	maggie();
}

int validateScreenTime(int time){
	if(time <= 0){		// Error for invalid value
		return 0;
	}
	if(time > MINSCRSAVERTIME){ // If the time is too big, it is set to a default value
		time = MINSCRSAVERTIME;
	}
	screensaver_time = time * 1000 / 55;
	return 1;
}

void maggie(){
	print_message(" _______  _______  _______  _______ _________ _______ \n",0xFF);
	print_message("(       )(  ___  )(  ____ \\(  ____ \\\\__   __/(  ____ \\ \n",0xFF);
	print_message("| () () || (   ) || (    \\/| (    \\/   ) (   | (    \\/ \n",0xFF);
	print_message("| || || || (___) || |      | |         | |   | (__  \n",0xFF);
	print_message("| |(_)| ||  ___  || | ____ | | ____    | |   |  __)   \n",0xFF);
	print_message("| |   | || (   ) || | \\_  )| | \\_  )   | |   | (   \n",0xFF);
	print_message("| )   ( || )   ( || (___) || (___) |___) (___| (____/\\ \n",0xFF);
	print_message("|/     \\||/     \\|(_______)(_______)\\_______/(_______/ \n",0xFF);
}
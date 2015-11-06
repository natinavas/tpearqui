#include "screensaver.h"

void show_screensaver(){
	//erase_screen();
	reset_current_video();
	alien();
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

void alien(){
	print_message("############.`::::::::::::::::::::::::::::::::::::::::::::::::'.#############\n",0xFF);
	print_message("############# :::::'#######`::::::::::::::::::::'#######`::::: ##############\n",0xFF);
	print_message("############# ::::'##.S$S.##`::::::::::::::::::'##.S$S.##`:::: ##############\n",0xFF);
	print_message("############'.:::'##.$$$$$.##`::::::::::::::::'##.$$$$$.##`:::.`#############\n",0xFF);
	print_message("############ :::'##.$$$$$$$.##`::::::::::::::'##.$$$$$$$.##`::: #############\n",0xFF);
	print_message("############ :'##.$$$$$$$$$$$.##`::::::::::'##.$$$$$$$$$$$.##`: #############\n",0xFF);
	print_message("############ :.##`$$$$$$$$$$$$.##`::::::::'##.$$$$$$$$$$$$'##.: #############\n",0xFF);
	print_message("############ ::.##`$$$$$$$$$$$$.##`::::::'##.$$$$$$$$$$$$'##.:: #############\n",0xFF);
	print_message("############ :::.##`$$$$$$$$$$$$.##`::::'##.$$$$$$$$$$$$'##.::: #############\n",0xFF);
	print_message("############.`:::.##`$$$$$$$$$$$$.##`::'##.$$$$$$$$$$$$'##.:::'.#############\n",0xFF);
	print_message("############# ::::.##`S$$$$$$$$$$S.##::##.S$$$$$$$$$$S'##.:::: ##############\n",0xFF);
	print_message("############# :::::.#################::#################.::::: ##############\n",0xFF);
	print_message("#############.`::::::::::::::::::::::::::::::::::::::::::::::'.##############\n",0xFF);
	print_message("##############.`::::::::::::::::::::::::::::::::::::::::::::'.###############\n",0xFF);
	print_message("###############.`::::::::::::::::::::::::::::::::::::::::::'.################\n",0xFF);
	print_message("################.`::::::::::::::::::::::::::::::::::::::::'.#################\n",0xFF);
	print_message("#################.`::::::::::::::::::::::::::::::::::::::'.##################\n",0xFF);
	print_message("##################.`::::::::::::::::::::::::::::::::::::'.###################\n",0xFF);
	print_message("###################.`::::::::::::::::::::::::::::::::::'.####################\n",0xFF);
	print_message("####################.`::::::::::::::::::::::::::::::::'.#####################\n",0xFF);
	print_message("#####################.`::::::::::::::::::::::::::::::'.######################\n",0xFF);
	print_message("######################.`::::::::############::::::::'.#######################\n",0xFF);
	print_message("#######################.`:::::::############:::::::'.########################\n",0xFF);
	print_message("########################.`::::::::::::::::::::::::'.#########################\n",0xFF);
	print_message("#########################.`:::::::::::::::::::::::'.#########################\n",0xFF);
	print_message("##########################.`:::::::::::::::::::::'.##########################\n",0xFF);
}
#include "stdint.h"
#include "00shell.h"
#include "call80.h"
#include "lib.h"
#include "sounds.h"


Command commands[11];
char comm[20];
int number_of_commands = 11;
char aux;
char name[20] = {0};


extern char bss;
extern char endOfBinary;
extern uint8_t data;
extern uint8_t text;
extern uint8_t rodata;


int main(){
	memset(&bss, 0, &endOfBinary - &bss);
	shell_erase_screen();
	
	print_message("########  ####    ###    ##    ## #### ########          #######   ######  \n", 0xFF);
	print_message("##     ##  ##    ## ##   ###   ##  ##     ##            ##     ## ##    ## \n", 0xFF);
	print_message("##     ##  ##   ##   ##  ####  ##  ##     ##            ##     ## ##       \n", 0xFF);
	print_message("########   ##  ##     ## ## ## ##  ##     ##    ####### ##     ##  ######  \n", 0xFF);
	print_message("##         ##  ######### ##  ####  ##     ##            ##     ##       ## \n", 0xFF);
	print_message("##         ##  ##     ## ##   ###  ##     ##            ##     ## ##    ## \n", 0xFF);
	print_message("##        #### ##     ## ##    ## ####    ##             #######   ######  \n\n", 0xFF);
	
	
	
	init_commands(0,"clear", clear_str ,&shell_erase_screen);
	init_commands(1,"time", time_str , &showRTC);
	init_commands(2,"help" , help_str, &shell_show_commands);
	init_commands(3,"change time", change_time_str , &changeTime);
	init_commands(4, "whoami", whoami_str , &whoami);
	init_commands(5, "keyboard" , keyboard_str, &show_keyboard);
	init_commands(6, "colors" ,modi_str, &modify_colors);
	init_commands(7, "screen time", saver_str, &set_screensaver_time);
	init_commands(8,"piano",piano_str,&piano);
	init_commands(9,"songs",songs_str,&songs);
	init_commands(10,"beep", beep_str,&beep);
	while(1){
		shell_command();
	}
}

void init_commands(unsigned char index, char * name, char* description, void (*function)()){
	commands[index].name = name;
	commands[index].description = description;
	commands[index].function = function;
}

void shell_command(){
	char valid_command = 0;
	unsigned char c = 0,j = 0;
	while((c = get_char()) != '\n'){
		comm[j++] = c;
	}

	comm[j] = 0;

	for(int i = 0;i<number_of_commands;i++){
		if(strcmp(comm,commands[i].name) == 0){
			commands[i].function();
			valid_command = 1;
		}
	}
	if(valid_command == 0){
		printf("Invalid command \"%s\" \n",0xFF, comm);
	}

}

void shell_show_commands(){
	for(int i=0 ;i<number_of_commands;i++){
		print_message(commands[i].name, 0xFF);
		print_message(" - ", 0xFF);
		print_message(commands[i].description, 0xFF);
		print_message("\n",0xFF);
	}
}

void shell_erase_screen(){
	_call_int80(INT_ERASE_SCR);
}

void showRTC(){
	unsigned char seg = _call_int80(INT_RTC_READ,0);
	unsigned char min = _call_int80(INT_RTC_READ,1);
	unsigned char hora = _call_int80(INT_RTC_READ,2);
	unsigned char dia = _call_int80(INT_RTC_READ,3);
	unsigned char mes = _call_int80(INT_RTC_READ,4);
	unsigned char anio = _call_int80(INT_RTC_READ,5);
	printf("Day: %d Month: %d Year: %d\n", 0xFF, dia,mes,anio);
	printf("Time: %d:%d:%d \n", 0xFF,hora,min,seg);
}

void whoami(){
	if(name[0] == 0){
		unsigned char c = 0,i = 0;
		print_message("No se... Quien sos?\n",0xFF);
		while((c = get_char()) != '\n' && i<19){
			name[i++] = c;
		}
		if(i==19)
			flush_buffer();
	}else{
		printf("%s \n",0xFF,name);
	}
}


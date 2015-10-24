#ifndef SHELL_H_

#define SHELL_H_

typedef struct {
  char* name;
  char* description;
  void(* function)();
  
} Command;


void * memset(void * destiny, int32_t c, uint64_t length);
void init_commands(unsigned char index, char * name, char* description, void (*function)());
void showRTC();
void shell_command();
void shell_erase_screen();
void _shutdown_asm();
void changeTime();
void shell_show_commands();
void shell_exit();
void whoami();
void show_keyboard();
void modifie_colors();
void set_screensaver_time();

char* time_str = "Shows the time and the date";
char* help_str = "shows all available commands";
char* change_time_str = "change time and date";
char* whoami_str = "who am i?";
char* keyboard_str = "shows the keyboard distribution graphically";
char* modi_str = "change the console set of colours";
char* clear_str = "clear the screen";
char* saver_str = "change the time till the screensaver appears";

#endif
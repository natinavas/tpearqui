#include "sounds.h"
#include <stdint.h>

void play_sound(uint32_t nFrequence); 

static uint8_t * const songsDirections[2] = {BECAUSE,RICKROLL};

extern void outb(uint8_t, uint8_t);
extern uint8_t inb(uint8_t);
extern void _song_note(uint32_t frec, uint32_t length);


//extern void _int_start_sound();
//extern void beep();
extern void _int_start_sound(uint32_t nFrequence);
extern void _int_end_sound();
//extern void nosound();

uint32_t notes[26] = {11492, 10847, 9121, 8609, 8126, 7670, 7239, 6833, 6449, 6087,
					  5743, 5423, 5119, 4831, 4560, 4304, 4063, 3834, 3619, 3416,
					  3224, 3043, 2873, 2711, 2559, 2416};

void read_song(uint64_t songNum){
	if(songNum == 1){
		print_message("   ////\\     //||\\     //\\|\\      ///||\\\n",0xFF);
 		print_message(" /`O-O'     ` @ @\\     //o o//       a a\n",0xFF);
 		print_message("    ]          >        ) | (         _)\n",0xFF);
 		print_message("    -          -          -           ~\n",0xFF);
 		print_message("  John        Paul      George      Ringo\n",0xFF);
	
		play_song2(0,1200);
	}
	if(songNum == 2){
		erase_screen();
		reset_current_video();
		print_message("\n\n ............................... .......,-~~'''''''~~--,,_\n",0xFF);
		print_message(" ..................................,-~''-,:::::::::::::::::::''-,\n",0xFF);
		print_message(" .............................,~''::::::::',::::::: :::::::::::::|',\n",0xFF);
		print_message(" .............................|::::::,-~'''___''''~~--~''':}\n",0xFF);
		print_message(" .............................'|:::::|: : : : : : : : : : : : : : :|\n",0xFF);
		print_message(" .............................|:::::|: : :-~~---: : : -----: |\n",0xFF);
		print_message(" ...NEVER GONNA GIVE U UP....(_''~-': : : :o: : :|: :o: : : :|\n",0xFF);
		print_message(" ............................'''~-,|: : : : : : ~---': : : :,'--\n",0xFF);
		print_message(" .................................|,: : : : : :-~~--: : ::/ ----- \n",0xFF);
		print_message(" ............................,-''\':\\: :'~,,_: : : : : _,-'\n",0xFF);
		print_message(" ......................__,-';;;;;\\:''-,: : : :'~---~''/|\n",0xFF);
		print_message(" .............__,-~'';;;;;;/;;;;;;;\\: :\\: : :____/: :',__\n",0xFF);
		print_message(" .,-~~~''''_;;;;;;;;;;;;;;;;;;;;;;;;;',. .''-,:|:::::::|. . |;;;;''-,__\n",0xFF);

		play_song2(1,400);
		
		erase_screen();
		reset_current_video();
	}
}


void play_song(uint32_t freqs[], uint32_t lengths[], uint32_t size){

	//if(song == 1){
		// print_message("   ////\\     //||\\     //\\|\\      ///||\\\n",0xFF);
// 		print_message(" /`O-O'     ` @ @\\     //o o//       a a\n",0xFF);
// 		print_message("    ]          >        ) | (         _)\n",0xFF);
// 		print_message("    -          -          -           ~\n",0xFF);
// 		print_message("  John        Paul      George      Ringo\n",0xFF);
		//}

	int rick = 0;
	//if(song == 2){
		rick = 1;
	//}


	//uint32_t i = 0;
	if(rick == 1){
		erase_screen();
		reset_current_video();
		print_message("\n\n ............................... .......,-~~'''''''~~--,,_\n",0xFF);
		print_message(" ..................................,-~''-,:::::::::::::::::::''-,\n",0xFF);
		print_message(" .............................,~''::::::::',::::::: :::::::::::::|',\n",0xFF);
		print_message(" .............................|::::::,-~'''___''''~~--~''':}\n",0xFF);
		print_message(" .............................'|:::::|: : : : : : : : : : : : : : :|\n",0xFF);
		print_message(" .............................|:::::|: : :-~~---: : : -----: |\n",0xFF);
		print_message(" ...NEVER GONNA GIVE U UP....(_''~-': : : :o: : :|: :o: : : :|\n",0xFF);
		print_message(" ............................'''~-,|: : : : : : ~---': : : :,'--\n",0xFF);
		print_message(" .................................|,: : : : : :-~~--: : ::/ ----- \n",0xFF);
		print_message(" ............................,-''\':\\: :'~,,_: : : : : _,-'\n",0xFF);
		print_message(" ......................__,-';;;;;\\:''-,: : : :'~---~''/|\n",0xFF);
		print_message(" .............__,-~'';;;;;;/;;;;;;;\\: :\\: : :____/: :',__\n",0xFF);
		print_message(" .,-~~~''''_;;;;;;;;;;;;;;;;;;;;;;;;;',. .''-,:|:::::::|. . |;;;;''-,__\n",0xFF);
	}

	for(int i=0; i<size; i++){
		if( i == 7 && rick == 1){
			erase_screen();
			//reset_current_video();
			print_message("\n\n ............................... .......,-~~'''''''~~--,,_\n",0xFF);
			print_message(" ..................................,-~''-,:::::::::::::::::::''-,\n",0xFF);
			print_message(" .............................,~''::::::::',::::::: :::::::::::::|',\n",0xFF);
			print_message(" .............................|::::::,-~'''___''''~~--~''':}\n",0xFF);
			print_message(" .............................'|:::::|: : : : : : : : : : : : : : :|\n",0xFF);
			print_message(" .............................|:::::|: : :-~~---: : : -----: |\n",0xFF);
			print_message(" ...NEVER GONNA LET U DOWN....(_''~-': : : :o: : :|: :o: : : :|\n",0xFF);
			print_message(" ...........................'''~-,|: : : : : : ~---': : : :,'--\n",0xFF);
			print_message(" .................................|,: : : : : :-~~--: : ::/ ----- \n",0xFF);
			print_message(" ............................,-''\':\\: :'~,,_: : : : : _,-'\n",0xFF);
			print_message(" ......................__,-';;;;;\\:''-,: : : :'~---~''/|\n",0xFF);
			print_message(" .............__,-~'';;;;;;/;;;;;;;\\: :\\: : :____/: :',__\n",0xFF);
			print_message(" .,-~~~''''_;;;;;;;;;;;;;;;;;;;;;;;;;',. .''-,:|:::::::|. . |;;;;''-,__\n",0xFF);
		}
		if( i == 15 && rick == 1){
			erase_screen();
			reset_current_video();
			print_message("\n\n ............................... .......,-~~'''''''~~--,,_\n",0xFF);
			print_message(" ..................................,-~''-,:::::::::::::::::::''-,\n",0xFF);
			print_message(" .............................,~''::::::::',::::::: :::::::::::::|',\n",0xFF);
			print_message(" .............................|::::::,-~'''___''''~~--~''':}\n",0xFF);
			print_message(" .............................'|:::::|: : : : : : : : : : : : : : :|\n",0xFF);
			print_message(" .............................|:::::|: : :-~~---: : : -----: |\n",0xFF);
			print_message(" ...NEVER GONNA TURN AROUND....(_''~-': : : :o: : :|: :o: : : :|\n",0xFF);
			print_message(" ...........................'''~-,|: : : : : : ~---': : : :,'--\n",0xFF);
			print_message(" .................................|,: : : : : :-~~--: : ::/ ----- \n",0xFF);
			print_message(" ............................,-''\':\\: :'~,,_: : : : : _,-'\n",0xFF);
			print_message(" ......................__,-';;;;;\\:''-,: : : :'~---~''/|\n",0xFF);
			print_message(" .............__,-~'';;;;;;/;;;;;;;\\: :\\: : :____/: :',__\n",0xFF);
			print_message(" .,-~~~''''_;;;;;;;;;;;;;;;;;;;;;;;;;',. .''-,:|:::::::|. . |;;;;''-,__\n",0xFF);
		}
		if(i == 23 && rick == 1){
			erase_screen();
			print_message(" ............................... .......,-~~'''''''~~--,,_\n",0xFF);
			print_message(" ..................................,-~''-,:::::::::::::::::::''-,\n",0xFF);
			print_message(" .............................,~''::::::::',::::::: :::::::::::::|',\n",0xFF);
			print_message(" .............................|::::::,-~'''___''''~~--~''':}\n",0xFF);
			print_message(" .............................'|:::::|: : : : : : : : : : : : : : :|\n",0xFF);
			print_message(" .............................|:::::|: : :-~~---: : : -----: |\n",0xFF);
			print_message(" ...AND DESERT YOU............(_''~-': : : :o: : :|: :o: : : :|\n",0xFF);
			print_message(" ...........................'''~-,|: : : : : : ~---': : : :,'--\n",0xFF);
			print_message(" .................................|,: : : : : :-~~--: : ::/ ----- \n",0xFF);
			print_message(" ............................,-''\':\\: :'~,,_: : : : : _,-'\n",0xFF);
			print_message(" ......................__,-';;;;;\\:''-,: : : :'~---~''/|\n",0xFF);
			print_message(" .............__,-~'';;;;;;/;;;;;;;\\: :\\: : :____/: :',__\n",0xFF);
			print_message(" .,-~~~''''_;;;;;;;;;;;;;;;;;;;;;;;;;',. .''-,:|:::::::|. . |;;;;''-,__\n",0xFF);
		}
			_song_note(freqs[i], lengths[i]);
	}	
	if(rick == 1){
		erase_screen();
		reset_current_video();
	}

}

void play_song2(uint8_t song, uint32_t tempo){
		int i = 0;
		while(songsDirections[song][i] != '0'){
			uint32_t notePos = songsDirections[song][i] - 'A';
			uint32_t note = notes[notePos];
			uint8_t len = songsDirections[song][i+1] - '0';
			uint32_t aux = tempo * len;
			_song_note(note, aux);
			i+=2;
		}
}

 void beep() {
 	 play_sound(440);
 	 //timer_wait(10);
 	 nosound();
     //set_PIT_2(old_frequency);
 }

 void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
    //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0xb6, 0x43);
 	outb((uint8_t) (Div), 0x42);
 	outb((uint8_t) (Div >> 8), 0x42);
 
    //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(tmp | 3, 0x61);
 	}
 }
 
 //make it shutup
 void nosound() {
 	uint8_t tmp = inb(0x61) & 0xFC;
 	outb(tmp, 0x61);
 }


void playPiano(uint32_t frec){
		if(frec == 0){
			_int_end_sound();
		}else{
			_int_start_sound(frec);
		}
}
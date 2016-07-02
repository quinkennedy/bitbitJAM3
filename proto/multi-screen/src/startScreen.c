/**
 * startScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/startScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"

void startScreen_enter(){
  font_t ibm_font;

  //load the font we want to use
  font_init();
  ibm_font = font_load(font_ibm);
  //turn off scrolling
  mode(get_mode() | M_NO_SCROLL);

  font_set(ibm_font);
  //write our title
  printf("\n\n\n\n\n\
    Her\n\
     Sovereign\n\
          Virus");
}

void startScreen_update(){
  if (joypad() & J_START){
    screen_data.state = GAME;
  }
}

void startScreen_draw(){}

/**
 * startScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef START_SCREEN_C
#define START_SCREEN_C

#include "include/startScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"

void startScreen_enter(){
  font_t ibm_font;

  HIDE_SPRITES;
  BGP_REG = 0xE4U;
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
          Virus\
\n\n\n\n\n\n\n\n\n\n");
  startScreen_data.showStart = 120;
}

void startScreen_update(){
  if (joypad() & J_START){
    screen_data.state = GAME;
  } else {
    if (startScreen_data.showStart != 0){
      if (startScreen_data.showStart == 1){
        printf("\
        press START");
      }
      startScreen_data.showStart--;
    }
  }
}

void startScreen_draw(){}

#endif

/**
 * screen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef SCREEN_C
#define SCREEN_C

#include "include/screen.h"
#include <gb/gb.h>
#include "startScreen.c"
#include "gameScreen.c"
#include "dialogScreen.c"
//#include "controlScreen.c"

void screen_update(){
  //cache the current state so we know if it changes
  ScreenState prev_state = screen_data.state;

  my_sys_time++;

  //call the appropriate update function
  (*screen_updates[screen_data.state])();

  //if the current state has changed, 
  // then initialize the new state
  if (prev_state != screen_data.state){
    (*screen_enters[screen_data.state])();
  }
}

void screen_setup(){
  my_sys_time = 0;
  //start initial setup of everything
  // start with the screen off and interrupts disabled so we can
  // power through setup without weird glitches on the screen
  disable_interrupts();
  LCDC_REG = 0x47U;//01000111
  /**
   * LCD        = Off
   * WindowBank = 0x9C00 - 0x9FFF
   * Window     = Off
   * BG Chr     = 0x8800 - 0x97FF
   * BG Bank    = 0x9800 - 0x9BFF
   * OBJ        = 8x16
   * OBJ        = On
   * BG         = On
   */

  //default to a standard 3-2-1-0 palette
  BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;

  // Setup all function arrays for switch-less logic
  screen_updates[BOOT] = dialogScreen_update;
  screen_updates[START] = startScreen_update;
  screen_updates[DIALOG] = dialogScreen_update;
  screen_updates[GAME] = gameScreen_update;
  screen_updates[WIN] = dialogScreen_update;
  screen_updates[LOSE] = dialogScreen_update;
//  screen_updates[CONTROLS] = controlScreen_update;

  screen_enters[BOOT] = dialogScreen_enter;
  screen_enters[START] = startScreen_enter;
  screen_enters[DIALOG] = dialogScreen_enter;
  screen_enters[GAME] = gameScreen_enter;
  screen_enters[WIN] = dialogScreen_enter;
  screen_enters[LOSE] = dialogScreen_enter;
//  screen_enters[CONTROLS] = controlScreen_enter;

  // initialize the first screen
  screen_data.state = BOOT;//START;
  (*screen_enters[screen_data.state])();

  //turn on the display and interrupts now that we are done with setup
  DISPLAY_ON;
  enable_interrupts();
}

#endif

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
#include "tiles/splash-data.c"

void startScreen_blackBottom(){
  UBYTE x,y;
  for(y=16; y != 32; y++){
    for(x=0; x != 20; x++){
      set_bkg_tiles(x, y, 1, 1, &splash_black);
    }
  }
}

void startScreen_startBottom(){
  set_bkg_tiles(0, 16, 20, 2, splash_tiles + (20 * 16));
}

void startScreen_splash(){
  set_bkg_data(0x00, SPLASH_DATA_SIZE, splash_sprite_data);
  set_bkg_tiles(0, 0, 20, 16, splash_tiles);
  startScreen_blackBottom();
  //set_bkg_tiles(0, 14, 20, 4, splash_blank_tiles);
}

void startScreen_enter(){
  DISPLAY_OFF;
  HIDE_SPRITES;
  NR52_REG = 0x00;// TURN SOUND OFF
  BGP_REG = 0xFF;
  SCX_REG = SCY_REG = 0;
  //initialize graphic
  startScreen_splash();
  //no font, text is burned into the splash screen
  startScreen_data.showStart = 255;
  DISPLAY_ON;
}

void startScreen_update(){
  if (joypad() & J_START){
    startScreen_blackBottom();
    startScreen_data.showStart = 0;
  } else if (joypad() & J_SELECT){
    //screen_data.state = CONTROLS;
  } else {
    if (startScreen_data.showStart != 0){
      switch(startScreen_data.showStart){
        case 210:
          BGP_REG = 0xFA;
          break;
        case 160:
          BGP_REG = 0xE5;
          break;
        case 110:
          BGP_REG = 0xE4;
          break;
        case 50:
          startScreen_blackBottom();
          //for(y=14; y != 18; y++){
          //  for(x=0; x != 20; x++){
          //    set_bkg_tiles(x, y, 20, 2
          //set_bkg_tiles(0, 16, 20, 2, splash_blank_tiles);
          break;
        case 1:
          startScreen_startBottom();
          //set_bkg_tiles(0, 16, 20, 2, splash_tiles + (20 * 16));
          startScreen_data.showStart = 100;//119;
          break;
      }
      startScreen_data.showStart--;
    } else {
      if (SCY_REG == 112){
        BGP_REG = 0xFF;
        screen_data.state = DIALOG;
      } else {
        SCY_REG += 2;
      }
    }
  }
}

#endif

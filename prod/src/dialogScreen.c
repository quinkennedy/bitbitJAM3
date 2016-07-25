/**
 * dialogScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_C
#define DIALOG_SCREEN_C

#include "include/dialogScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include <gb/drawing.h>
#include <gb/console.h>
#include "include/screen.h"
#include "tiles/portrait-data.c"
#include "include/input.h"

void showDialog(DialogEntry *dialog){
  UBYTE i, j, index, cell;
  //turn off scrolling
  mode(get_mode() | M_NO_SCROLL);

  //reset to beginning of text
  dialogScreen_data.nextCharacter = 0;

  if (dialog->speaker == 0){
    //when there is no speaker, we show full-screen text
    //don't show any portraits
    HIDE_SPRITES;
    //set background to text-only mode
    for(i = 0; i < 20; i++){
      cell = copy_bg_tiles[i] + 93;
      set_bkg_tiles(i, 0,
                    1, 1,
                    &cell);
    }
    //top graphic extends to first pixel on second line
    cell = copy_bg_tiles[i] + 93;
    set_bkg_tiles(0, 1,
                  1, 1,
                  &cell);
    //start copy down a bit
    gotoxy(0,1);
  } else {
    SHOW_SPRITES;
    //set background for left portrait
    for(i = 0, index = 0; i < 6; i++){
      for(j = 0; j < 6; j++, index++){
        cell = portrait_frame_tiles[index] + 93;
        set_bkg_tiles(j, i, 1, 1, &cell);
      }
    }
    //set background for right portrait
    for(i = 0, index = 0; i < 6; i++){
      for(j = 14; j < 20; j++, index++){
        cell = portrait_frame_tiles[index] + 93;
        set_bkg_tiles(j, i, 1, 1, &cell);
      }
    }
    //set copy background
    for(i = 6, index = 0; i < 18; i++){
      for(j = 0; j < 20; j++, index++){
        cell = portrait_copy_tiles[index] + 93;
        set_bkg_tiles(j, i, 1, 1, &cell);
      }
    }
    //skip over the portraits
    gotoxy(2, 8);

    //and change sprite palette based on who is talking
    if (dialog->speaker == 1){
      OBP0_REG = DIALOG_SPEAKER_PALETTE;
      OBP1_REG = DIALOG_LISTENER_PALETTE;

    } else if (dialog->speaker == 2){
      OBP1_REG = DIALOG_SPEAKER_PALETTE;
      OBP0_REG = DIALOG_LISTENER_PALETTE;
    }
  }

  //write our dialog
  while(printDialogChar());
  //printf(dialog->text);
  //show key prompt after 1 second
  dialogScreen_data.dialogTime = 60;
}

UBYTE printDialogChar(){
  char currChar = dialog[dialogScreen_data.dialogNum].
                    text[dialogScreen_data.nextCharacter];
  if (currChar == NULL){
    //not printing any character
    return 0;
  } else{
   putchar(currChar);
   if (currChar == '\n' && 
       dialog[dialogScreen_data.dialogNum].speaker != 0){
     gotoxy(2, posy());
   }
   dialogScreen_data.nextCharacter++;
   return 1;
  }
}

void dialogScreen_enter(){
  font_t font;
  UBYTE i,j,spriteIndex,tileOffset;
  DISPLAY_OFF;
  //change all sprites to 8x8
  SPRITES_8x8;

  //load the font we want to use
  font_init();
  color(WHITE, DKGREY, SOLID);
  // 93 tiles -- based on code comments in gbdk/gbdk-lib/examples/gb/fonts.c
  font = font_load(font_italic);
  font_set(font);

  // load portrait sprites
  set_sprite_data(0, PORTRAIT_DATA_SIZE, portrait_sprite_data);
  // load in-game sprites
  //set_sprite_data(PORTRAIT_DATA_SIZE
  // load background data for text and dialog screens
  set_bkg_data(93, DIALOG_FRAMES_DATA_SIZE, dialog_bg_tile_data);
  // load dkgrey as background tile 0
  set_bkg_data(0, 1, dialog_bg_tile_data + DIALOG_FRAMES_DKGREY);
  //clear screen
  //place portrait 1 on the left
  spriteIndex = 0;
  for( i = 0, tileOffset = 0; i != 32; i+=8){
    for( j = 0; j != 32; j+=8, spriteIndex++, tileOffset++){
      set_sprite_tile(spriteIndex, portrait_tiles[tileOffset + 0x10]);
      move_sprite(spriteIndex, 16 + j, 24 + i);
      set_sprite_prop(spriteIndex, 0x00);//use palette 0
    }
  }
  //place portrait 2 on the right
  for( i=0, tileOffset = 0; i != 32; i+=8){
    for( j=0; j != 32; j+=8, spriteIndex++, tileOffset++){
      set_sprite_tile(spriteIndex, portrait_tiles[tileOffset + 0x20]);
      move_sprite(spriteIndex, 128 + j, 24 + i);
      set_sprite_prop(spriteIndex, 0x10);//use palette 1
    }
  }
  //move unused sprites offscreen
  for( ; spriteIndex != 40; spriteIndex++){
    set_sprite_tile(spriteIndex, 0);
    move_sprite(spriteIndex, 0, 0);
  }
  //reset background palette and position
  BGP_REG = 0xE4U;
  SCX_REG = SCY_REG = 0;

  dialogScreen_data.dialogNum = 0;
  showDialog(&(dialog[0]));
  DISPLAY_ON;
}

void dialogScreen_update(){
  input_update();

  //if the A key
  if ((input_data.flags & J_A) &&
      (input_data.aFrames == 0)){
    dialogScreen_data.dialogNum++;
    if (dialogScreen_data.dialogNum == DIALOG_LENGTH){
      screen_data.state = GAME;
    } else {
      showDialog(&(dialog[dialogScreen_data.dialogNum]));
    }
  } else {
    if (dialogScreen_data.dialogTime != 0){
      if (dialogScreen_data.dialogTime == 1){
        printf(dialog[dialogScreen_data.dialogNum].speaker == 0 ?
"            press A" :
"         press A");

      }
      dialogScreen_data.dialogTime--;
    }
  }
}

void dialogScreen_draw(){}

#endif

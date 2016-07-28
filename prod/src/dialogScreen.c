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
#include "tiles/dialog-data.c"
#include "include/input.h"
#include "tiles/custom-font.c"
//#define NUM_FONT_TILES 93

void renderBackgroundSquare(UBYTE frame[], 
                            UBYTE start_x, UBYTE start_y, 
                            UBYTE w, UBYTE h, UBYTE fill){
  UBYTE x, y;
  //NOTE: these loops iterate backwards 
  //  so that we are not calculating end conditions every loop
  
  //start with the bottom row
  x = start_x + w + 1;
  y = start_y + h + 1;
  set_bkg_tiles(start_x + w + 1, y, 1, 1, (frame + 8));
  for(x--; x != start_x; x--){
    set_bkg_tiles(x, y, 1, 1, (frame + 7));
  }
  set_bkg_tiles(x, y, 1, 1, (frame + 6));

  //then all the middle rows
  for(y--; y != start_y; y--){
    x = start_x + w + 1;
    set_bkg_tiles(x, y, 1, 1, frame+5);
    if (fill){
      for(x--; x != start_x; x--){
        set_bkg_tiles(x, y, 1, 1, frame+4);
      }
    } else {
      x = start_x;
    }
    set_bkg_tiles(x, y, 1, 1, frame+3);
  }

  //and finally the top row
  x = start_x + w + 1;
  set_bkg_tiles(x, y, 1, 1, frame+2);
  for(x--; x != start_x; x--){
    set_bkg_tiles(x, y, 1, 1, frame+1);
  }
  set_bkg_tiles(x, y, 1, 1, frame);
}

void showDialog(DialogEntry *dialog){
  UBYTE x, y, cell;
  int index;
  //turn off scrolling
  //mode(get_mode() | M_NO_SCROLL);

  //reset to beginning of text
  dialogScreen_data.nextCharacter = 0;

  if (!isPortraitDialogScreen()){
    //when there is no speaker, we show full-screen text
    //don't show any portraits
    HIDE_SPRITES;
    //set background to text-only mode
    y = 0;
    cell = 0x9A + NUM_FONT_TILES + 1;
    set_bkg_tiles(0, 0, 1, 1, &cell);
    cell++;
    set_bkg_tiles(1, 0, 1, 1, &cell);
    cell++;
    for(x = 2; x != 18; x++){
      set_bkg_tiles(x, y, 1, 1, &cell);
    }
    cell++;
    set_bkg_tiles(18, 0, 1, 1, &cell);
    cell++;
    set_bkg_tiles(19, 0, 1, 1, &cell);
    //header uses one tile on second row
    cell++;
    set_bkg_tiles(0, 1, 1, 1, &cell);
    //start copy down a bit
    gotoxy(1,1);
  } else {
    SHOW_SPRITES;
    //set left portrait frame
    if (dialog->speaker == LEFT_SPEAKER){
      renderBackgroundSquare(nine_slice_thick_frame, 0, 0, 4, 4, 
                             dialog->leftPortrait == NO_CHARACTER);
    } else {
      renderBackgroundSquare(nine_slice_thin_frame, 0, 0, 4, 4,
                             dialog->leftPortrait == NO_CHARACTER);
    }
    //set right portrait frame
    if (dialog->speaker == RIGHT_SPEAKER){
      renderBackgroundSquare(nine_slice_thick_frame, 14, 0, 4, 4,
                             dialog->rightPortrait == NO_CHARACTER);
    } else {
      renderBackgroundSquare(nine_slice_thin_frame, 14, 0, 4, 4,
                             dialog->rightPortrait == NO_CHARACTER);
    }
    //set left portrait
    if (dialog->leftPortrait != NO_CHARACTER){
      for(y = 1, index = (dialog->leftPortrait << 4); y != 5; y++){
        for(x = 1; x != 5; x++, index++){
          cell = dialog_tiles[index] + NUM_FONT_TILES + 1;
          set_bkg_tiles(x, y, 1, 1, &cell);
        }
      }
    }
    //set right portrait
    if (dialog->rightPortrait != NO_CHARACTER){
      for(y = 1, index = (dialog->rightPortrait << 4); y != 5; y++){
        for(x = 15; x != 19; x++, index++){
          cell = dialog_tiles[index] + NUM_FONT_TILES + 1;
          set_bkg_tiles(x, y, 1, 1, &cell);
        }
      }
    }
    //set black between portraits
    cell = DIALOG_BLACK + NUM_FONT_TILES + 1;
    for(y = 0; y != 6; y++){
      for(x = 6; x != 14; x++){
        set_bkg_tiles(x, y, 1, 1, &cell);
      }
    }
    //set text frame
    renderBackgroundSquare(nine_slice_thick_frame, 0, 6, 18, 10, 1);
    
    //set background to dialog mode
//    for(y = 0, index = DIALOG_SCREEN_TILES_START; y != 18; y++){
//      for(x = 0; x != 20; x++, index++){
//        cell = dialog_tiles[index] + 93;
//        set_bkg_tiles(x, y,
//                      1, 1,
//                      &cell);
//      }
//    }
//    //set left portrait
//    for(y = 1, index = (dialog->leftPortrait << 4); y != 5; y++){
//      for(x = 1; x != 5; x++, index++){
//        cell = dialog_tiles[index] + 93;
//        set_bkg_tiles(x, y,
//                      1, 1,
//                      &cell);
//      }
//    }
//    //set right portrait
//    for(y = 1, index = (dialog->rightPortrait << 4); y != 5; y++){
//      for(x = 15; x != 19; x++, index++){
//        cell = dialog_tiles[index] + 93;
//        set_bkg_tiles(x, y,
//                      1, 1,
//                      &cell);
//      }
//    }
    //skip over the portraits
    gotoxy(2, 8);

/*    //and change sprite palette based on who is talking
    if (dialog->speaker == 1){
      OBP0_REG = DIALOG_SPEAKER_PALETTE;
      OBP1_REG = DIALOG_LISTENER_PALETTE;

    } else if (dialog->speaker == 2){
      OBP1_REG = DIALOG_SPEAKER_PALETTE;
      OBP0_REG = DIALOG_LISTENER_PALETTE;
    }
    */
  }
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
  UBYTE spriteIndex;
  DISPLAY_OFF;
  //change all sprites to 8x8
  SPRITES_8x8;

  // load dkgrey as background tile 0
  set_bkg_data(0, 1, dialog_data + (DIALOG_DKGREY << 4));
  // load dialog background data
  set_bkg_data(NUM_FONT_TILES + 1, DIALOG_DATA_SIZE, dialog_data);
  // load in-game sprites
  //set_sprite_data(0, PORTRAIT_DATA_SIZE, portrait_sprite_data);
  //set_bkg_data(0, 1, dialog_bg_tile_data + DIALOG_FRAMES_DKGREY);
  //clear screen

  //load the font we want to use
  font_init();
  color(WHITE, DKGREY, SOLID);
  // 93 tiles -- based on code comments in gbdk/gbdk-lib/examples/gb/fonts.c
  font = font_load(alpha_num_italic_font);
  font_set(font);
  
  //move all sprites offscreen
  spriteIndex = 0;
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

UBYTE isPortraitDialogScreen(){
  return (dialog[dialogScreen_data.dialogNum].speaker != NO_SPEAKER);
}

UBYTE hasPrintedLastCharacter(){
  return (dialog[dialogScreen_data.dialogNum].
            text[dialogScreen_data.nextCharacter] == NULL);
}

void dialogScreen_update(){
  UBYTE cell;
  input_update();

  //if the A key
  if ((input_data.flags & J_A) &&
      (input_data.aFrames == 0)){
    //if we have shown all of the text
    if (hasPrintedLastCharacter()){
      //then go to the next dialog excerpt
      dialogScreen_data.dialogNum++;
      //if we have shown all the dialog pieces, then play the game
      if (dialogScreen_data.dialogNum == DIALOG_LENGTH){
        screen_data.state = GAME;
      } else {
        showDialog(&(dialog[dialogScreen_data.dialogNum]));
      }
    } 
    //otherwise display all the text
    else {
      while(printDialogChar());
    }
  } 
  //if no key pressed, just handle the text/prompt output
  else {
    //if we are no longer printing characters, animate the "next" prompt
    if(!printDialogChar()){

      //blink the down arrow
      cell = NEXT_TILES_START + NUM_FONT_TILES + 1;
      if (sys_time & 0x10){
        cell++;
      }

      //put the cursor in the bottom right
      if (isPortraitDialogScreen()){
        set_bkg_tiles(17, 15, 1, 1, &cell);
      } else {
        set_bkg_tiles(19, 17, 1, 1, &cell);
      }
    }
  }
}

void dialogScreen_draw(){}

#endif

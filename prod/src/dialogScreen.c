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
#include "tiles/minimized-font.c"
#include "include/npc.h"
#include "include/player.h"

//#define SHOW_MEMORY
//#define SKIP_DIALOG

void renderBackgroundSquare(UBYTE frame[], 
                            UBYTE start_x, UBYTE start_y, 
                            UBYTE w, UBYTE h, UBYTE fill){
  UBYTE x, y, cell;
  //NOTE: these loops iterate backwards 
  //  so that we are not calculating end conditions every loop
  
  //start with the bottom row
  x = start_x + w + 1;
  y = start_y + h + 1;
  cell = frame[8] + NUM_FONT_TILES + 32 + 1;
  set_bkg_tiles(start_x + w + 1, y, 1, 1, &cell);
  for(x--; x != start_x; x--){
    cell = frame[7] + NUM_FONT_TILES + 32 + 1;
    set_bkg_tiles(x, y, 1, 1, &cell);
  }
  cell = frame[6] + NUM_FONT_TILES + 32 + 1;
  set_bkg_tiles(x, y, 1, 1, &cell);

  //then all the middle rows
  for(y--; y != start_y; y--){
    x = start_x + w + 1;
    cell = frame[5] + NUM_FONT_TILES + 32 + 1;
    set_bkg_tiles(x, y, 1, 1, &cell);
    if (fill){
      for(x--; x != start_x; x--){
        cell = frame[4] + NUM_FONT_TILES + 32 + 1;
        set_bkg_tiles(x, y, 1, 1, &cell);
      }
    } else {
      x = start_x;
    }
    cell = frame[3] + NUM_FONT_TILES + 32 + 1;
    set_bkg_tiles(x, y, 1, 1, &cell);
  }

  //and finally the top row
  x = start_x + w + 1;
  cell = frame[2] + NUM_FONT_TILES + 32 + 1;
  set_bkg_tiles(x, y, 1, 1, &cell);
  for(x--; x != start_x; x--){
    cell = frame[1] + NUM_FONT_TILES + 32 + 1;
    set_bkg_tiles(x, y, 1, 1, &cell);
  }
  cell = frame[0] + NUM_FONT_TILES + 32 + 1;
  set_bkg_tiles(x, y, 1, 1, &cell);
}

void renderBlackSquare(UBYTE start_x, UBYTE start_y,
                       UBYTE w, UBYTE h){
  UBYTE x, y, cell;

  //move start positions back one for end conditions
  start_x--;
  start_y--;

  //sprite number of black tile
  cell = DIALOG_BLACK + NUM_FONT_TILES + 1 + 32;

  //set all cells to black
  //iterate backward
  for(y = start_y + h; y != start_y; y--){
    for(x = start_x + w; x != start_x; x--){
      set_bkg_tiles(x, y, 1, 1, &cell);
    }
  }
}

#ifdef SHOW_MEMORY
void renderMemory(){
  UBYTE x, y, i;
  for(y = 0, i = 0; y != 18; y++){
    for(x = 0; x != 20; x++, i++){
      set_bkg_tiles(x,y,1,1,&i);
    }
  }
}
#endif

void displayPortrait(UBYTE x, UBYTE y, UBYTE index, UBYTE offset, UBYTE talks){
  UBYTE end_x, end_y, cell;
  end_x = x + 4;
  end_y = y + 4;

  if (talks && (sys_time & 0x8)){
    index += 16;
  }

  //set portrait
  for( ; y != end_y; y++){ 
    for(x = end_x - 4; x != end_x; x++, index++){
      cell = dialog_tiles[index] + offset;
      set_bkg_tiles(x, y, 1, 1, &cell);
    }
  }
}

void showDialog(DialogEntry *dialog){
#ifndef SHOW_MEMORY
  UBYTE x, y, cell;
#endif
  //turn off scrolling
  //mode(get_mode() | M_NO_SCROLL);

  //reset to beginning of text
  dialogScreen_data.nextCharacter = 0;

  if (!isPortraitDialogScreen()){
#ifdef SHOW_MEMORY
    renderMemory();
#else
    //when there is no speaker, we show full-screen text
    //don't show any portraits
    HIDE_SPRITES;
    //set background to text-only mode
    y = 0;
    cell = TEXT_SCREEN_TILES_START + NUM_FONT_TILES + 1 + 32;
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
    //clear rest of screen
    cell = 1;//space character
    x = 1;
    for(y = 1; y != 18; y++){
      for( ; x != 20; x++){
        set_bkg_tiles(x, y, 1, 1, &cell);
      }
      x = 0;
    }
    //start copy down a bit
    gotoxy(1,1);
#endif
  } else {
    SHOW_SPRITES;
    //set left portrait frame
    if (dialog->leftPortrait == NO_CHARACTER){
      renderBlackSquare(0, 0, 6, 6);
    } else {
      set_bkg_data(
          NUM_FONT_TILES + 1,
          (dialog_info[dialog->leftPortrait].dataLength),
          dialog_data + dialog_info[dialog->leftPortrait].dataStart);
      if (dialog->speaker == LEFT_SPEAKER){
        renderBackgroundSquare(nine_slice_thick_frame, 0, 0, 4, 4, 0);
      } else {
        renderBackgroundSquare(nine_slice_thin_frame, 0, 0, 4, 4, 0);
      }
      //set left portrait
      displayPortrait(1, 
                      1, 
                      dialog_info[dialog->leftPortrait].tileStart, 
                      NUM_FONT_TILES + 1,
                      dialog->speaker == LEFT_SPEAKER && 
                        dialog_info[dialog->leftPortrait].frames > 1);
    }
    //set right portrait frame
    if (dialog->rightPortrait == NO_CHARACTER){
      renderBlackSquare(14, 0, 6, 6);
    } else {
      set_bkg_data(
          255u - 32u,
          dialog_info[dialog->rightPortrait].dataLength,
          dialog_data + dialog_info[dialog->rightPortrait].dataStart);
      if (dialog->speaker == RIGHT_SPEAKER){
        renderBackgroundSquare(nine_slice_thick_frame, 14, 0, 4, 4, 0);
      } else {
        renderBackgroundSquare(nine_slice_thin_frame, 14, 0, 4, 4, 0);
      }
      //set right portrait
      displayPortrait(15, 
                      1, 
                      dialog_info[dialog->rightPortrait].tileStart, 
                      255u - 32u,
                      dialog->speaker == RIGHT_SPEAKER && 
                        dialog_info[dialog->rightPortrait].frames > 1);
    }
#ifdef SHOW_MEMORY
    renderMemory();
#else
    //set black between portraits
    renderBlackSquare(6, 0, 8, 6);
    //set text frame
    renderBackgroundSquare(nine_slice_thick_frame, 0, 6, 18, 10, 1);

    //initialize sprites
    //set left sprite
    if (dialog->leftPortrait == NO_CHARACTER){
      dialogScreen_data.left.visibility = NONE;
      move_sprite(0, 0, 0);
      move_sprite(1, 0, 0);
    } else {
      dialogScreen_data.left.type = dialog_info[dialog->leftPortrait].eType;
      //if (dialog->leftPortrait == KING_CHARACTER){
      //  dialogScreen_data.left.type = VIRUS;
      //} else {
      //  dialogScreen_data.left.type = dialog->leftPortrait;
      //}
      dialogScreen_data.left.position.z = 0;
      dialogScreen_data.left.animMask = 7;
      dialogScreen_data.left.animFrame = 0;
      dialogScreen_data.left.position.x.b.h = 64;
      dialogScreen_data.left.position.y.b.h = 48;
      dialogScreen_data.left.speed.x.w = 0;
      dialogScreen_data.left.speed.y.w = 0;
      dialogScreen_data.left.visibility = FULL;
      set_sprite_prop(0, 0);
      set_sprite_prop(1, 0);
      tileSprite(0, 
                 entity_tiles_ref[dialogScreen_data.left.type][0], 
                 dialogScreen_data.left.type);
      placeSprite(0, &(dialogScreen_data.left));
    }
    //set right sprite
    if (dialog->rightPortrait == NO_CHARACTER){
      dialogScreen_data.right.visibility = NONE;
      move_sprite(2, 0, 0);
      move_sprite(3, 0, 0);
    } else {
      dialogScreen_data.right.type = dialog_info[dialog->rightPortrait].eType;
      //if (dialog->rightPortrait == KING_CHARACTER){
      //  dialogScreen_data.right.type = VIRUS;
      //} else {
      //  dialogScreen_data.right.type = dialog->rightPortrait;
      //}
      dialogScreen_data.right.position.z = 0;
      dialogScreen_data.right.animMask = 7;
      dialogScreen_data.right.animFrame = 0;
      dialogScreen_data.right.position.x.b.h = 108;
      dialogScreen_data.right.position.y.b.h = 48;
      dialogScreen_data.right.speed.x.w = 0;
      dialogScreen_data.right.speed.y.w = 0;
      dialogScreen_data.right.visibility = FULL;
      set_sprite_prop(2, 0);
      set_sprite_prop(3, 0);
      tileSprite(2, 
                 entity_tiles_ref[dialogScreen_data.right.type][0], 
                 dialogScreen_data.right.type);
      placeSprite(2, &(dialogScreen_data.right));
    }
    
    //skip over the portraits
    gotoxy(2, 8);
#endif
  }
}

UBYTE printDialogChar(DialogEntry *dialog){
  char currChar = dialog->text[dialogScreen_data.nextCharacter];
  if (currChar == NULL){
    //not printing any character
    return 0;
  } else{
   putchar(currChar);
   if (currChar == '\n' && 
       dialog->speaker != NO_SPEAKER){
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
  SPRITES_8x16;

  // load in-game sprites first, so un-used end sprites will be overwritten
  //set_sprite_data(0, SPRITE_DATA_SIZE - (5 << 2) - (7 << 2), sprite_tile_data);
  loadNPCSpriteData();

  // load dkgrey as background tile 0
  set_bkg_data(0, 1, dialog_data + (DIALOG_DKGREY << 4));
  // load dialog background data
  set_bkg_data(NUM_FONT_TILES + 1 + 32, NUM_BG_TILES, dialog_data + (DIALOG_DATA_SIZE << 4) - (NUM_BG_TILES << 4));

  //load the font we want to use
  font_init();
  color(WHITE, DKGREY, SOLID);
  font = font_load(minimized_font);
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
  OBP0_REG = 0x90U;

  dialogScreen_data.dialogNum = 0;
  showDialog(dialogs + dialogSet[screen_data.state].start);
  DISPLAY_ON;
}

UBYTE isPortraitDialogScreen(){
  return (dialogs[dialogSet[screen_data.state].start + 
                  dialogScreen_data.dialogNum].
            speaker != NO_SPEAKER);
}

void dialogScreen_update(){
#ifndef SHOW_MEMORY
  UBYTE cell;
#endif
  DialogEntry *dialogEntry;
  dialogEntry = (dialogs + 
                 dialogSet[screen_data.state].start + 
                 dialogScreen_data.dialogNum);
  input_update();

  //if the A key
  if ((input_data.flags & J_A) &&
      (input_data.aFrames == 0)){
#ifdef SKIP_DIALOG
    screen_data.state = GAME;
#endif
#ifndef SHOW_MEMORY
    //if we have shown all of the text
    if (dialogEntry->text[dialogScreen_data.nextCharacter] == NULL){
#endif
      //then go to the next dialog excerpt
      dialogScreen_data.dialogNum++;
      dialogEntry++;
      //if we have shown all the dialog pieces, then play the game
      if (dialogScreen_data.dialogNum == dialogSet[screen_data.state].count){
        if (screen_data.state == DIALOG){
          screen_data.state = GAME;
        } else {
          screen_data.state = START;
        }
      } else {
        showDialog(dialogEntry);
      }
#ifndef SHOW_MEMORY
    } 
    //otherwise display all the text
    else {
      while(printDialogChar(dialogEntry));
    }
#endif
  } 
#ifndef SHOW_MEMORY
  //if no key pressed, just handle the text/prompt output
  else {
    if (isPortraitDialogScreen()){
      //animate the sprites
      if (dialogScreen_data.left.visibility == FULL){
        animate(0, &(dialogScreen_data.left));
      }
      if (dialogScreen_data.right.visibility == FULL){
        animate(2, &(dialogScreen_data.right));
      }
      if (dialogEntry->speaker == LEFT_SPEAKER &&
          dialog_info[dialogEntry->leftPortrait].frames > 1){
        displayPortrait(1,
                        1,
                        dialog_info[dialogEntry->leftPortrait].tileStart,
                        NUM_FONT_TILES + 1,
                        TRUE);
      } else if (dialogEntry->speaker == RIGHT_SPEAKER &&
          dialog_info[dialogEntry->rightPortrait].frames > 1){
        displayPortrait(15,
                        1,
                        dialog_info[dialogEntry->rightPortrait].tileStart,
                        255u-32u,
                        TRUE);
      }
//      //animate the talking
//      //set left portrait
//      displayPortrait(1, 
//                      1, 
//                      dialog_info[dialog[dialogScreen_data.dialogNum].
//                        leftPortrait].tileStart, 
//                      NUM_FONT_TILES + 1,
//                      dialog_info[dialog[dialogScreen_data.dialogNum].
//                        leftPortrait].frames > 1);
//      //set right portrait
//      displayPortrait(15, 
//                      1, 
//                      dialog_info[dialog[dialogScreen_data.dialogNum].
//                        rightPortrait].tileStart, 
//                      255u - 32u,
//                      dialog_info[dialog[dialogScreen_data.dialogNum].
//                        rightPortrait].frames > 1);
    }
    
    //if we are no longer printing characters, animate the "next" prompt
    if(!printDialogChar(dialogEntry)){

      //blink the down arrow
      cell = NEXT_TILES_START + NUM_FONT_TILES + 1 + 32;
      if (sys_time & 0x10){
        cell++;
      }

      //put the cursor in the bottom right
      if (isPortraitDialogScreen()){
        set_bkg_tiles(17, 15, 1, 1, &cell);
      } else {
        set_bkg_tiles(18, 16, 1, 1, &cell);
      }
    }
  }
#endif //SHOW_MEMORY
}

#endif //pragma once

/**
 * gameScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/gameScreen.h"
#include "tiles/sprite-data.c"
#include "player.c"
#include "background.c"
#include "include/screen.h"
#include "npc.c"
#include <gb/gb.h>

void gameScreen_enter(){
  //load game sprites into VRAM
  set_sprite_data(0x00, SPRITE_DATA_SIZE, sprite_tile_data);
  //set up the sprite registers to be different
  OBP0_REG = 0xE4U;//3-2-1-0
  OBP1_REG = 0x1BU;//0-1-2-3

  player_init();
  npc_init();
  background_init();
}

void gameScreen_update(){
  player_update();
  npc_update();
  background_update();
}

void gameScreen_draw(){
  //player_draw();
  //background_draw();
}

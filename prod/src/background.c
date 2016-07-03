/**
 * background.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/background.h"
#include "tiles/background-data.c"
#include <gb/gb.h>
#include <rand.h>

void background_init(){
  UBYTE i, j;
  SHOW_BKG;
  BGP_REG = background_palettes[player_data.position.z];

  /* Initialize the background */
  // load background tiles into VRAM
  set_bkg_data(0x00, BACKGROUND_DATA_SIZE, background_sprite_data);

  // create a random background
  for(i = 0; i < 32; i++){
    for(j = 0; j < 32; j++){
      set_bkg_tiles(i, j, 
                    1, 1, 
                    background_tiles + 
                      (rand() % BACKGROUND_DATA_SIZE));
    }
  }

  //start at 0,0
  background_data.position.x.w = 0;
  background_data.position.y.w = 0;
  SCX_REG = 0;
  SCY_REG = 0;
}

void background_update(){
  background_data.position.x.w += (player_data.speed.x.w >> 2);
  background_data.position.y.w += (player_data.speed.y.w >> 2);
  SCX_REG = background_data.position.x.b.h;
  SCY_REG = background_data.position.y.b.h;
  BGP_REG = background_palettes[player_data.position.z];
}

/**
 * background.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/background.h"
#include "tiles/background-data.c"
#include "include/player.h"
#include <gb/gb.h>
#include <rand.h>

void background_init(){
  UBYTE i, j, k;
  SHOW_BKG;
  BGP_REG = background_palettes[player_data.position.z];

  /* Initialize the background */
  // load background tiles into VRAM
  set_bkg_data(0x00, BACKGROUND_DATA_SIZE, background_sprite_data);

  background_data.speed.straight.w = player_data.speed.straight.w >> 2;
  background_data.speed.diagonal.w = player_data.speed.diagonal.w >> 2;
  background_data.speed.decelerate.w = player_data.speed.decelerate.w >> 2;
  background_data.speed.x.w = 0;
  background_data.speed.y.w = 0;

  // create a random background
  for(i = 0, k=0; i != 32; i++){
    for(j = 0; j != 32; j++){
      k++;
      if (k == BACKGROUND_DATA_SIZE){
        k = 0;
      }
      set_bkg_tiles(i, j, 
                    1, 1, 
                    background_tiles +
                      (((UBYTE)rand()) % BACKGROUND_DATA_SIZE));
    }
  }

  //start at 0,0
  background_data.position.x.w = 0;
  background_data.position.y.w = 0;
  SCX_REG = 0;
  SCY_REG = 0;
}

void background_update(){
  if (input_data.flags & J_DPAD){
    moveToward(input_data.direction, &background_data);
  } else {
    slowDown(&background_data);
  }
  if (player_data.speed.x.w == 0){
    background_data.speed.x.w = 0;
  }
  if (player_data.speed.y.w == 0){
    background_data.speed.y.w = 0;
  }
  background_data.position.x.w += background_data.speed.x.w;
  background_data.position.y.w += background_data.speed.y.w;
 // background_data.position.x.w += (player_data.speed.x.w);
 // background_data.position.y.w += (player_data.speed.y.w);
  //background_data.position.x.w += (((WORD)player_data.speed.x.w) >> 2);
  //background_data.position.y.w += (((WORD)player_data.speed.y.w) >> 2);
  SCX_REG = background_data.position.x.b.h;
  SCY_REG = background_data.position.y.b.h;
//  BGP_REG = background_palettes[player_data.position.z];
}

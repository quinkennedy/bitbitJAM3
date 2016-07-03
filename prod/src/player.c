/**
 * player.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef PLAYER_C
#define PLAYER_C

#include "include/player.h"
#include "tiles/sprite-data.c"
#include <gb/gb.h>
#include "include/input.h"
#include "entity.c"

void player_init(){
  set_sprite_tile(0, virus_tiles[0]);
  //set_sprite_prop(0, 0)//use palette 0
  //for now we are always a virus
  player_data.type = VIRUS;
  // set up variables
  player_data.speed.straight.w = 0x0010;
  player_data.speed.diagonal.w = 0x0010;
  player_data.speed.decelerate.w = 0x0004;
  player_data.animMask = 1;//magic number
  player_data.animFrame = 0;
  // center player on screen
  player_data.position.x.w = 0x5000;
  player_data.position.y.w = 0x5000;
  player_data.position.z = 2;
  player_data.speed.x.w = 0x0000;
  player_data.speed.y.w = 0x0000;
  // set registers
  move_sprite(0, player_data.position.x.b.h, player_data.position.y.b.h);
}

void player_update(){
  input_update();

  //if any of the d-pad buttons are pressed
  if (input_data.flags & J_DPAD){
    moveToward(input_data.direction, &player_data);
  } 
  // otherwise you are decelerating
  else {
    slowDown(&player_data);
  }
  animate(0, &player_data);
}

#endif

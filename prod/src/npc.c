/**
 * npc.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/npc.h"
#include "tiles/sprite-data.c"
#include <gb/gb.h>
#include <types.h>
#include <rand.h>
#include "include/player.h"

void placeDoubleSprite(UBYTE index, Position *pos){
  move_sprite(index++, pos->x.b.h, pos->y.b.h);
  move_sprite(index++, pos->x.b.h+8, pos->y.b.h);
}

void placeSingleSprite(UBYTE index, Position *pos){
  move_sprite(index, pos->x.b.h, pos->y.b.h);
}

void createNPC(UBYTE index, EntityType type){
  UBYTE spriteIndex = (index << 1) + 1;
  EntityData *npc = &(npc_data[index]);
  npc->type = type;
  //place at a random location off-screen
  npc->position.x.b.h = ((UBYTE)rand()) % 80 + 160;//(160,239)
  npc->position.y.b.h = ((UBYTE)rand()) % 96 + 144;//(144,239)
  //random height
  npc->position.z = ((UBYTE)rand()) % 5;//(0,4)
  //TEMP start with random speed
  npc->speed.x.b.l = ((UBYTE)rand()) & 0xF;//(0,15)
  npc->speed.y.b.l = ((UBYTE)rand()) & 0xF;//(0,15)
  //initialize sprite tile reference register
  set_sprite_tile(spriteIndex, *entity_tiles_ref[type]);
  set_sprite_tile(spriteIndex+1, (*entity_tiles_ref[type]) + 2);
  if (type == VIRUS){
    placeSingleSprite(spriteIndex, &(npc->position));
  } else {
    placeDoubleSprite(spriteIndex, &(npc->position));
  }
}

void npc_init(){
  UBYTE i;
  
  for( i=0; i != MAX_NUM_NPC; i++){
    switch(((UBYTE)rand()) % 3){
      case 0:
        createNPC(i, IMMUNE);
        break;
      case 1:
        createNPC(i, SKIN);
        break;
      case 2:
        createNPC(i, NEURON);
        break;
    }
  }
}

void npc_update(){
  UBYTE i, j;
  EntityData *npc;
  for( i=0, j=1; i != MAX_NUM_NPC; i++, j+=2){
    npc = &(npc_data[i]);
    //move based on the player's speed
    npc->position.x.w = 
      npc->position.x.w + 
      npc->speed.x.w - 
      player_data.speed.x.w;
    npc->position.y.w = 
      npc->position.y.w + 
      npc->speed.y.w - 
      player_data.speed.y.w;
    //update the sprite's location -- move to draw?
    placeDoubleSprite(j, &(npc->position));
  }
}

void npc_draw(){
}

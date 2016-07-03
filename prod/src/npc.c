/**
 * npc.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef NPC_C
#define NPC_C

#include "include/npc.h"
#include "tiles/sprite-data.c"
#include <gb/gb.h>
#include <types.h>
#include <rand.h>
#include "include/player.h"

void placeSprite(UBYTE index, EntityData *entity){
  move_sprite(index, entity->position.x.b.h, entity->position.y.b.h);
  if (entity->type != VIRUS){
    move_sprite(index+1, entity->position.x.b.h + 8, entity->position.y.b.h);
  }
}

void tileSprite(UBYTE index, const unsigned char tile, EntityType type){
  set_sprite_tile(index, tile);
  if (type != VIRUS){
    set_sprite_tile(index+1, tile + 2);
  }
}

void createNPC(UBYTE index, EntityType type){
  UBYTE spriteIndex = (index + 1) << 1;
  EntityData *npc = &(npc_data[index]);

  //TODO: figure out why this doesn't work??!?
  //npc->type = type;

  //place at a random location off-screen
  npc->position.x.b.h = ((UBYTE)rand()) % 80 + 168;//(168,247)
  npc->position.y.b.h = ((UBYTE)rand()) % 96 + 160;//(160,255)
  //random height
  npc->position.z = ((UBYTE)rand()) % 5;//(0,4)
  //TEMP start with random speed
  npc->speed.x.b.l = (((UBYTE)rand()) & 0xF) - 8;//(-8,7)
  npc->speed.y.b.l = (((UBYTE)rand()) & 0xF) - 8;//(-8,7)
  //initialize sprite tile reference register
  tileSprite(spriteIndex, entity_tiles_ref[type][0], type);
  placeSprite(spriteIndex, npc);

  npc->animMask = ((UBYTE)rand()) ^ index;
  npc->animFrame = 0;
}

void npc_init(){
  UBYTE i;
  
  for( i=0; i != 5/*MAX_NUM_NPC*/; i++){
    npc_data[i].type = ((UBYTE)rand()) % 3;
    createNPC(i, npc_data[i].type);
  }
}

void npc_update(){
  UBYTE i, j;
  EntityData *npc;
  for( i=0, j=2; i != 5/*MAX_NUM_NPC*/; i++, j+=2){
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
    placeSprite(j, npc);
    animate(j, npc);
  }
}

void npc_draw(){
}

#endif

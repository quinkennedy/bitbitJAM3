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
  
  for( i=0; i != MAX_NUM_NPC; i++){
    npc_data[i].type = ((UBYTE)rand()) % 3;
    createNPC(i, npc_data[i].type);
  }
  //update NPC visibility
  npc_playerChangedLayer();
}

void npc_playerChangedLayer(){
  UBYTE i, j;
  EntityData *npc;
  for( i=0, j=2; i != MAX_NUM_NPC; i++, j+=2){
    npc = &(npc_data[i]);
    //if we are one layer off from the player, 
    // we will be showing the shadow
    if ((npc->position.z == (player_data.position.z + 1)) ||
        ((npc->position.z + 1) == player_data.position.z)){
      npc->visibility = SHADOW;
      //cheaper than doing a Modulo
      npc->animFrame = npc->animFrame & (SHADOW_FRAMES - 1);
      tileSprite(j, shadow_tiles[npc->animFrame], npc->type);
    } else if (npc->position.z != player_data.position.z){
      npc->visibility = NONE;
      //hide the sprite
      move_sprite(j, 0, 0);
      move_sprite(j+1, 0, 0);
    } else {
      npc->visibility = FULL;
      tileSprite(j, entity_tiles_ref[npc->type][npc->animFrame], npc->type);
    }
  }
}

void npc_update(){
  UBYTE i, j;
  EntityData *npc;
  for( i=0, j=2; i != MAX_NUM_NPC; i++, j+=2){
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
    if (npc->visibility != NONE){
      placeSprite(j, npc);
      animate(j, npc);
    }
  }
}

void npc_draw(){
}

#endif

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
#include "include/screen.h"

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

void npc_setVisibility(EntityData *npc, UBYTE spriteIndex){
  //if we are one layer off from the player, 
  // we will be showing the shadow
  if ((npc->position.z == (player_data.position.z + 1)) ||
      ((npc->position.z + 1) == player_data.position.z)){
    npc->visibility = SHADOW;
    //cheaper than doing a Modulo
    npc->animFrame = npc->animFrame & (SHADOW_FRAMES - 1);
    tileSprite(spriteIndex, shadow_tiles[npc->animFrame], npc->type);
  } else if (npc->position.z != player_data.position.z){
    npc->visibility = NONE;
    //hide the sprite
    move_sprite(spriteIndex, 0, 0);
    move_sprite(spriteIndex+1, 0, 0);
  } else {
    npc->visibility = FULL;
    tileSprite(spriteIndex, 
               entity_tiles_ref[npc->type][npc->animFrame], 
               npc->type);
  }
}

void createNPC(UBYTE index, EntityType type){
  fixed r;
  UBYTE spriteIndex = (index + 1) << 1;
  EntityData *npc = &(npc_data[index]);
  npc_counts[type]++;

  //TODO: figure out why this doesn't work??!?
  //npc->type = type;

  //place at a random location off-screen
  r.w = rand();
  npc->position.x.b.h = r.b.l % 80 + 168;//(168,247)
  npc->position.y.b.h = r.b.h % 96 + 160;//(160,255)
  //random height
  r.w = rand();
  //use first 3 bits for z
  npc->position.z = (r.b.l & 0x7) % 5;//(0,4)
  r.w = r.w >> 3;
  //TEMP start with random speed
  //next 3 for x speed
  npc->speed.x.w = (r.b.l & 0x7) - 3;//(-3,4)
  r.w = r.w >> 2;
  //last 3 for y speed (speeds share a bit)
  npc->speed.y.w = (r.b.l & 0x7) - 3;//(-3,4)
  //initialize sprite tile reference register
  //make sure sprite is in front of background
  set_sprite_prop(spriteIndex, 0);
  set_sprite_prop(spriteIndex + 1, 0);
  tileSprite(spriteIndex, entity_tiles_ref[type][0], type);
  placeSprite(spriteIndex, npc);

  r.w = rand();
  npc->animMask = 7;//magic number
  npc->animFrame = r.b.l & entity_anim_frames[type];

  npc_setVisibility(npc, spriteIndex);
}

void npc_init(){
  UBYTE i;

  for( i=0; i != 4; i++){
    npc_counts[i] = 0;
  }
  
  for( i=0; i != MAX_NUM_NPC; i++){
    //start with half immune cells and half skin cells
    npc_data[i].type = i & 1;
    createNPC(i, npc_data[i].type);
  }
  //update NPC visibility
  npc_playerChangedLayer();
}

void npc_playerChangedLayer(){
  UBYTE i, j;
  for( i=0, j=2; i != MAX_NUM_NPC; i++, j+=2){
    npc_setVisibility(&(npc_data[i]), j);
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
      if (player_checkCollision(npc)){
        switch (npc->type){
          case NEURON:
            screen_data.state = WIN;
            return;
          case IMMUNE:
            screen_data.state = LOSE;
            return;
          case SKIN:
            npc_counts[SKIN]--;
            if (npc_counts[SKIN] == 0){
              npc_data[i].type = NEURON;
            } else {
              //randomly create another SKIN or IMMUNE cell
              npc_data[i].type = ((UBYTE)rand()) & 1;
            }
            createNPC(i, npc_data[i].type);
        }
      }
      placeSprite(j, npc);
      animate(j, npc);
    }
  }
}

void npc_draw(){
}

#endif

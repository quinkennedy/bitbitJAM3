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
#include "include/sound.h"

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
  //evenly distribute to various layers
  //Ideally we would have more on 0 & 5 
  //  so # visible AND shadow NPCs are consistent between layer
  npc->position.z = index % 5;//(0,4)
  //TEMP start with random speed
  r.w = rand();
  //first 3 for x speed
  npc->speed.x.w = (r.b.l & 0x7) - 3;//(-3,4)
  r.w = r.w >> 2;
  //another 3 for y speed (speeds share a bit)
  npc->speed.y.w = (r.b.l & 0x7) - 3;//(-3,4)
  r.w = r.w >> 2;
  //initialize sprite tile reference register
  //make sure sprite is in front of background
  set_sprite_prop(spriteIndex, 0);
  set_sprite_prop(spriteIndex + 1, 0);
  tileSprite(spriteIndex, entity_tiles_ref[type][0], type);
  placeSprite(spriteIndex, npc);

  npc->animMask = 7;//magic number
  //last 4 for randomizing animation start point (nice-to-have)
  npc->animFrame = r.b.l & entity_anim_frames[type];

  npc_setVisibility(npc, spriteIndex);
}

void npc_init(){
  UBYTE i;

  for( i=0; i != 4; i++){
    npc_counts[i] = 0;
  }
  //the first 3 NPCs are saved for VIRUS
  for( i = 0; i != 3; i++){
    npc_data[i].type = VIRUS;
    //place virus on a layer it will always be hidden
    npc_data[i].position.z = 6;
    npc_data[i].animMask = 1;//match players animation speed
    npc_setVisibility(&(npc_data[i]), (i+1) << 1);
  }
  for( ; i != MAX_NUM_NPC; i++){
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

void npc_activateVirus(){
  UBYTE i;
  EntityData *npc;
  for( i = 0; i != 3; i++){
    npc = &(npc_data[i]);
    npc->position.z = player_data.position.z;
    npc->position.x.w = player_data.position.x.w;
    npc->position.y.w = player_data.position.y.w;
    switch(((UBYTE)sys_time) & 7){
      case N:
        npc->speed.x.w = 0;
        npc->speed.y.w = -0x100;//-(player_data.speed.straight.w << 3);
        break;
      case NE:
        npc->speed.x.w = 0xA0;//(player_data.speed.diagonal.w << 3);
        npc->speed.y.w = -0xA0;//-(player_data.speed.diagonal.w << 3);
        break;
      case E:
        npc->speed.x.w = 0x100;//(player_data.speed.straight.w << 2);
        npc->speed.y.w = 0;
        break;
      case SE:
        npc->speed.x.w = 0xA0;//(player_data.speed.diagonal.w << 2);
        npc->speed.y.w = 0xA0;//(player_data.speed.diagonal.w << 2);
        break;
      case S:
        npc->speed.x.w = 0;
        npc->speed.y.w = 0x100;//(player_data.speed.diagonal.w << 2);
        break;
      case SW:
        npc->speed.x.w = -0xA0;//-(player_data.speed.diagonal.w << 2);
        npc->speed.y.w = 0xA0;//(player_data.speed.diagonal.w << 2);
        break;
      case W:
        npc->speed.x.w = -0x100;//-(player_data.speed.straight.w << 2);
        npc->speed.y.w = 0;
        break;
      default:
        npc->speed.x.w = -0xA0;//-(player_data.speed.diagonal.w << 2);
        npc->speed.y.w = -0xA0;//-(player_data.speed.diagonal.w << 2);
        break;
    }
    npc_setVisibility(npc, (i+1) << 1);
  }
}

void npc_update(){
  UBYTE i, j, is_player_speed_negative;
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
      if (npc->type == VIRUS){
        if ((npc->position.x.b.h > 168) ||
            (npc->position.y.b.h > 152)){
          npc->position.z = 6;
          npc_setVisibility(npc, (i+1) << 1);
        }
      } else {
        if (player_checkCollision(npc)){
          switch (npc->type){
            case NEURON:
              screen_data.state = WIN;
              return;
            case IMMUNE:
              screen_data.state = LOSE;
              return;
            case SKIN:
              // hmm, doesn't seem to add much, and tanks framerate
              ////explode with virus cells
              //npc_activateVirus();
              //cut the player's speed in half
              is_player_speed_negative = 
                (player_data.speed.x.b.h & 0x80U);
              player_data.speed.x.w = player_data.speed.x.w >> 1;
              if (is_player_speed_negative){
                player_data.speed.x.b.h = player_data.speed.x.b.h | 0x80U;
              }
              is_player_speed_negative = 
                (player_data.speed.y.b.h & 0x80U);
              player_data.speed.y.w = player_data.speed.y.w >> 1;
              if (is_player_speed_negative){
                player_data.speed.y.b.h = player_data.speed.y.b.h | 0x80U;
              }
              //now one fewer skin cell
              npc_counts[SKIN]--;
              //if that was the last skin cell, start the endgame!
              if (npc_counts[SKIN] == 0){
                npc_data[i].type = NEURON;
              } else {
                //randomly create another SKIN or IMMUNE cell
                npc_data[i].type = ((UBYTE)rand()) & 1;
              }
              createNPC(i, npc_data[i].type);
          }
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

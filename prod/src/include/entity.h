/**
 * entity.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef ENTITY_H
#define ENTITY_H

#define NUM_LAYERS 5
#define MAX_LAYER 4

#include <types.h>
#include "input.h"
#include "../tiles/sprite-data.c"

typedef enum EntityType{
  IMMUNE = 0, 
  SKIN = 1, 
  NEURON = 2, 
  VIRUS = 3,
  KING = 4
} EntityType;

typedef enum Visibility{
  NONE, SHADOW, FULL
} Visibility;

typedef struct Position{
  fixed x;
  fixed y;
  UBYTE z;
} Position;

typedef struct Speed{
  fixed x;
  fixed y;
  fixed straight;
  fixed diagonal;
  fixed decelerate;
} Speed;

typedef struct EntityData{
  Position position;
  Speed speed;
  EntityType type;
  Visibility visibility;
  UBYTE animMask;
  UBYTE animFrame;
  UBYTE dying;
} EntityData;

UBYTE entity_anim_frames[] = {8, 11, 10, 13, 13};
const unsigned char* entity_tiles_ref[] = 
  {immunity_tiles, skin_tiles, neuron_tiles, virus_tiles, king_tiles};

void moveToward(DPAD_DIR direction, EntityData *data);
void slowDown(EntityData *data);
void animate(UBYTE spriteIndex, EntityData *data);

#endif

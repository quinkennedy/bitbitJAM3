/**
 * entity.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef ENTITY
#define ENTITY

#include <types.h>
#include "input.h"
#include "../tiles/sprite-data.c"

typedef enum EntityType{
  IMMUNE, SKIN, NEURON, VIRUS
} EntityType;

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
  UBYTE animMask;
} EntityData;

UBYTE entity_anim_frames[4] = {8, 11, 10, 1};
const unsigned char *entity_tiles_ref[4] = 
  {immunity_tiles, skin_tiles, neuron_tiles, virus_tiles};

void moveToward(DPAD_DIR direction, EntityData *data);
void slowDown(EntityData *data);

#endif

/**
 * entity.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/entity.h"

void moveToward(DPAD_DIR direction, EntityData *data){
  switch(direction){
    case N:
      data->speed.y.w -= data->speed.straight.w;
      break;
    case NE:
      data->speed.y.w -= data->speed.diagonal.w;
      data->speed.x.w += data->speed.diagonal.w;
      break;
    case E:
      data->speed.x.w += data->speed.straight.w;
      break;
    case SE:
      data->speed.y.w += data->speed.diagonal.w;
      data->speed.x.w += data->speed.diagonal.w;
      break;
    case S:
      data->speed.y.w += data->speed.straight.w;
      break;
    case SW:
      data->speed.y.w += data->speed.diagonal.w;
      data->speed.x.w -= data->speed.diagonal.w;
      break;
    case W:
      data->speed.x.w -= data->speed.straight.w;
      break;
    case NW:
      data->speed.y.w -= data->speed.diagonal.w;
      data->speed.x.w -= data->speed.diagonal.w;
      break;
  }
}

void slowDown(EntityData *data){
  if (data->speed.x.w != 0){
    if ((WORD)data->speed.x.w > 0){
      if (data->speed.x.w < data->speed.decelerate.w){
        data->speed.x.w = 0;
      } else {
        data->speed.x.w -= data->speed.decelerate.w;
      }
    } else {
      data->speed.x.w += data->speed.decelerate.w;
    }
  }
  if (data->speed.y.w != 0){
    if ((WORD)data->speed.y.w > 0){
      if (data->speed.y.w < data->speed.decelerate.w){
        data->speed.y.w = 0;
      } else {
        data->speed.y.w -= data->speed.decelerate.w;
      }
    } else {
      data->speed.y.w += data->speed.decelerate.w;
    }
  }
}

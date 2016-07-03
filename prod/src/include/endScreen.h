/**
 * endScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <types.h>

typedef struct EndScreenData{
  UBYTE endtime;
} EndScreenData;

EndScreenData endScreen_data;

void endScreen_enter();
void endScreen_update();
void endScreen_draw();

#endif

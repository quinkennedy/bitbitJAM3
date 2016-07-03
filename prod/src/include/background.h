/**
 * background.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"

//typedef struct BackgroundData{
//  Position position;
//} BackgroundData;

EntityData background_data;
UBYTE background_palettes[NUM_LAYERS] = {0x40U,0x90U,0xE4U,0xF9U,0xFEU};

void background_init();
void background_update();

#endif

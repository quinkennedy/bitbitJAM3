/**
 * sound.c
 * Integrating some bytebeat-inspired sound by Vivek Vimal!
 *
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef SOUND_C
#define SOUND_C

#include "include/sound.h"
#include <gb/hardware.h>
#include "include/player.h"
#include "include/background.h"

static void sound_init(){
	NR52_REG = 0x80U;	// TURN SOUND ON
	NR51_REG = 0x11;	// ENABLE SOUND CHANNELS
	NR50_REG = 0x44;//0x1F;	// VOLUME MAX = 0x77, MIN = 0x00	
}

static void sound_update(){
  if (player_data.speed.x.w == 0 || 
      player_data.speed.y.w == 0){
    NR50_REG = 0x22;
  } else {
    NR50_REG = 0x11;
  }

  switch (input_data.direction){
    case N:
    case NW:
    case W:
    case SW:
      NR11_REG = 0x9f;
		  NR12_REG = 0x7f;
		  NR13_REG = 0x09 + SCY_REG;
		  NR14_REG = 0x6a + SCY_REG;
      break;
    default:
      NR11_REG = 0x62;
      NR12_REG = 0x74;
      NR13_REG = 0x22 + SCX_REG;
      NR14_REG = 0x69 + SCX_REG - 250;
      break;
  }
}

static void sound_stop(){
  NR52_REG = 0x00;// TURN SOUND OFF
}

#endif

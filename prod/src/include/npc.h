/**
 * npc.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef NPC
#define NPC

//the player takes 1 sprite slot, 
// and most NPCs (except NPC viruses) take two sprite slots
// so we can support ((40 - 1) / 2) = 18 NPCs
#define MAX_NUM_NPC 18

#include "entity.h"

EntityData npc_data[MAX_NUM_NPC];

void npc_init();
void npc_update();
void npc_draw();

#endif

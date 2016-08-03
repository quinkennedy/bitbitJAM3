/**
 * dialogScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_H
#define DIALOG_SCREEN_H

#include <types.h>
#include <gb/gb.h>
#include "entity.h"
#include "dialogs.h"

typedef struct DialogScreenData{
  UBYTE dialogNum;
  UBYTE nextCharacter;
  EntityData right;
  EntityData left;
} DialogScreenData;

DialogScreenData dialogScreen_data;

void dialogScreen_enter();
void dialogScreen_update();

UBYTE printDialogChar(DialogEntry *dialog);
UBYTE isPortraitDialogScreen();

#endif

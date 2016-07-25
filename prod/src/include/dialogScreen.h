/**
 * dialogScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_H
#define DIALOG_SCREEN_H

#include <types.h>
#include <gb/gb.h>

typedef struct DialogScreenData{
  UBYTE dialogNum;
  UBYTE dialogTime;
  UBYTE nextCharacter;
} DialogScreenData;

DialogScreenData dialogScreen_data;

void dialogScreen_enter();
void dialogScreen_update();
void dialogScreen_draw();

UBYTE printDialogChar();

typedef struct DialogEntry{
  char * text;
  UBYTE speaker;//0 = no portraits
} DialogEntry;

#define DIALOG_LENGTH 5
#define DIALOG_SPEAKER_PALETTE 0xE4U
#define DIALOG_LISTENER_PALETTE 0xF8U

DialogEntry dialog[] = {
  {"\
  60,000 years ago, \n\
    during great    \n\
      turmoil,      \n\
    His Magesty,    \n\
   King Simplex I,  \n\
    spoke with his  \n\
     daughter...\n\n\n", 0},
  {"\
Father,\n\n\
You are weak\n\n\
You are corrupt\n\n\n", 1},
  {"\
There is no\n\n\
  greatness in\n\n\
the Kingdom.\n\n\n", 1},
  {"\
Your existence\n\n\
  is stagnant\n\n\
Your soul is a\n\n\
  cesspool\n", 1},
  {"\
My Daughter,\n\
You are my\n\
  living wound\n\
That bleeds\n\
  flowing sorrow\n\
\n\
 I am Ultimate.\n\
 The Kingdom\n\
  exists only to\n\
 Feed my HUNGER\n\n", 2},
  {"\
 I am leaving,\n\
 I will create\n\
  a Kingdom\n\
 That will span\n\
  the world. \n\
\n\
 I will be the \n\
 First to infect\n\
 To Conquer\n\
 The HUMANS\n\n", 1},
  {"\
\n\
 I will\n\
 Pull dreams\n\
  from the Heavens\n\
\n\
\n\
 And deliver them\n\
  into our Reality\n\
\n\
\n\n", 1}
};

#endif

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
  UBYTE nextCharacter;
} DialogScreenData;

DialogScreenData dialogScreen_data;

void dialogScreen_enter();
void dialogScreen_update();
void dialogScreen_draw();

UBYTE printDialogChar();
UBYTE isPortraitDialogScreen();
UBYTE hasPrintedLastCharacter();

typedef enum PortraitSpeaker{
  NO_SPEAKER, LEFT_SPEAKER, RIGHT_SPEAKER
} PortraitSpeaker;

typedef enum PortraitCharacter{
  NO_CHARACTER = -1,
  KING_CHARACTER = 0, 
  PRINCESS_CHARACTER = 1,
  IMMUNE_CHARACTER = 3,
  CELL_CHARACTER = 5,
  NEURON_CHARACTER = 7
} PortraitCharacter;

typedef struct DialogEntry{
  char * text;
  PortraitSpeaker speaker;
  PortraitCharacter leftPortrait;
  PortraitCharacter rightPortrait;
} DialogEntry;

#define DIALOG_LENGTH 12
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
     daughter...\n\n\n", 
   NO_SPEAKER, NO_CHARACTER, NO_CHARACTER},
  {"\
Father,\n\n\
You are weak\n\n\
You are corrupt\n\n\n", 
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
There is no\n\n\
  greatness in\n\n\
the Kingdom.\n\n\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
Your existence\n\n\
  is stagnant\n\n\
Your soul is a\n\n\
  cesspool\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
My Daughter,\n\n\
You are my\n\n\
  living wound\n\n\n",
   RIGHT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
A wound\n\n\
  in my heart\n\n\
That bleeds\n\n\
  flowing sorrow\n",
   RIGHT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I am Ultimate.\n\n\
The Kingdom\n\n\
  exists only to\n\n\
Feed my HUNGER\n", 
   RIGHT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I am leaving,\n\n\
I will create\n\n\
  a Kingdom\n\n\
Of my own\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
A Kingdom\n\n\
  that will span\n\n\
The world.\n\n\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I will be the \n\n\
First to infect\n\n\
To Conquer\n\n\
The HUMANS\n", 
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I will\n\n\
Pull dreams from\n\n\
  the Heavens\n\n\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER},
  {"\
And deliver them\n\n\
  into our Reality\n\n\n\n\n",
   LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER}
};

#endif

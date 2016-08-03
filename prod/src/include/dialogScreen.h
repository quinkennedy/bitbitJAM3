/**
 * dialogScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_H
#define DIALOG_SCREEN_H

#include <types.h>
#include <gb/gb.h>
#include "entity.h"

typedef struct DialogScreenData{
  UBYTE dialogNum;
  UBYTE nextCharacter;
  EntityData right;
  EntityData left;
} DialogScreenData;

DialogScreenData dialogScreen_data;

typedef enum PortraitSpeaker{
  NO_SPEAKER, LEFT_SPEAKER, RIGHT_SPEAKER
} PortraitSpeaker;

typedef enum PortraitCharacter{
  NO_CHARACTER = -1,
  IMMUNE_CHARACTER = 0,
  CELL_CHARACTER = 1,
  NEURON_CHARACTER = 2,
  PRINCESS_CHARACTER = 3,
  KING_CHARACTER = 4
} PortraitCharacter;

typedef struct DialogEntry{
  char * text;
  PortraitSpeaker speaker;
  PortraitCharacter leftPortrait;
  PortraitCharacter rightPortrait;
} DialogEntry;

void dialogScreen_enter();
void dialogScreen_update();

UBYTE printDialogChar(DialogEntry *dialog);
UBYTE isPortraitDialogScreen();

#define DIALOG_LENGTH 21

DialogEntry dialog[] = {
  {"\
60,000 years ago,\n\n\
  during great\n\n\
  turmoil,\n\n\
 His Magesty,\n\n\
  King Simplex I,\n\n\
  spoke with his\n\n\
  daughter...", 
   NO_SPEAKER, NO_CHARACTER, NO_CHARACTER},
  {"\
Father,\n\n\
You are weak\n\n\
You are corrupt", 
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
Your existence\n\n\
  is stagnant\n\n\
Your soul is a\n\n\
  cesspool",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
My Daughter,\n\n\
You are my\n\n\
  living wound",
   RIGHT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
A wound\n\n\
  in my heart\n\n\
That bleeds\n\n\
  flowing sorrow",
   RIGHT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I am leaving,\n\n\
I will create\n\n\
  a Kingdom\n\n\
Of my own",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
A Kingdom\n\n\
  that will span\n\n\
The world.",
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I will be the \n\n\
First to infect\n\n\
To Conquer\n\n\
The HUMANS", 
   LEFT_SPEAKER, PRINCESS_CHARACTER, KING_CHARACTER},
  {"\
I will\n\n\
Pull dreams from\n\n\
  the Heavens",
   LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER},
  {"\
And deliver them\n\n\
  into our\n\n\
  Reality",
   LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER},
  {"\
Her Royal Princess\n\n\
  has managed to\n\n\
  duck\n\
       dodge\n\
             sneak\n\n\
 Through enemy\n\n\
  defenses",
  NO_SPEAKER, NO_CHARACTER, NO_CHARACTER},
  {"\
Greetings be\n\n\
  to you my\n\n\
  fair lady",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, CELL_CHARACTER},
  {"\
A warm welcome\n\n\
  bid to you\n\n\
On this fair\n\n\
  day",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, CELL_CHARACTER},
  {"\
I may as yet\n\n\
  make use\n\n\
Of your\n\n\
  generosity",
  LEFT_SPEAKER, PRINCESS_CHARACTER, CELL_CHARACTER},
  {"\
Such naivety\n\n\
  does cause\n\n\
The unwitting\n\n\
  to be caught",
   LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER},
  {"\
Slow your pace\n\n\
Still your fangs\n\n\
I can see your\n\n\
  evil plans",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, IMMUNE_CHARACTER},
  {"\
She aims for me\n\n\
To seed\n\n\
  corruption",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, NEURON_CHARACTER},
  {"\
Through my\n\n\
  downfall\n\n\
She will gain\n\n\
  her throne",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, NEURON_CHARACTER},
  {"\
We will chase\n\n\
You will hide\n\n\
We will track\n\n\
You will die",
  RIGHT_SPEAKER, PRINCESS_CHARACTER, IMMUNE_CHARACTER},
  {"\
I can duck\n\n\
  I can dodge\n\n\
You will miss\n\n\
  My every move",
  LEFT_SPEAKER, PRINCESS_CHARACTER, IMMUNE_CHARACTER},
  {"\
I will claim my\n\n\
  deserved throne\n\n\
You will serve as\n\n\
  a perfect home",
  LEFT_SPEAKER, PRINCESS_CHARACTER, NO_CHARACTER}
};

#endif

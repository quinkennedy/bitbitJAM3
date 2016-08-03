/**
 * fontFilter.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef FONT_FILTER_H
#define FONT_FILTER_H

#include "../src/include/dialogs.h"
#include "../src/tiles/custom-font.c"
#include <stdio.h>

unsigned int chars[128] = { 0 };
unsigned char numUnique = 0;

int printForFile(){
  unsigned char i, j, k;
  printf("\
/*\n\
 * minimized-font.c\n\
 * This file was automagically produced by fontFilter\n\
 * Based on GBDK's italic font\n\
 * and the characters required in all dialogs\n\
 */\n\
#ifndef MINIMIZED_FONT\n\
#define MINIMIZED_FONT\n\
\n\
#define NUM_FONT_TILES %d\n\
\n\
const unsigned char minimized_font[] = {\n\
 0x05 // 1+4 -> 128 char encoding, compressed\n\
,%d // number characters defined\n\
// character mappings\n\
", numUnique, numUnique);

  for(i = 0, j = 0; i != 128; i++){
    if (!chars[i]){
      printf(", 0");
    } else {
      //this depends on space being the first unique character encountered
      printf(",%2d", j);
      j++;
    }
    
    //8 mappings per line
    if (i % 8 == 7){
      printf("\n");
    }
  }

  printf("// characters\n");

  for(i = 0; i != 128; i++){
    //for each unique character
    if (chars[i]){
      //get the index for the character in the source font
      j = alpha_num_italic_font[i+2];
      //copy character data over
      for(k = 0; k != 8; k++){
        printf(",0x%02X", alpha_num_italic_font[(j << 3) + 2 + 128 + k]);
      }
      printf("\n");
    }
  }

  printf("\
};\n\
\n\
#endif\n\
");
}

int main(){
  unsigned char totalLength = 0;
  unsigned char i, j;


  for(i = 0; i != 3; i++){
    totalLength += dialogSet[i].count;
  }

  for(i = 0; i != totalLength; i++){
    for(j = 0; dialogs[i].text[j]; j++){
      //don't count newlines
      if (dialogs[i].text[j] == '\n'){
        continue;
      }
      if (!chars[dialogs[i].text[j]]){
        numUnique++;
      }
      chars[dialogs[i].text[j]]++;
    }
  }

  printForFile();
  
  //printf("numUnique: %d\n", numUnique);
  //for(i = 0; i != 128; i++){
  //  printf("%c: %d\n", i, chars[i]);
  //}
  
  return 0;
}

#endif

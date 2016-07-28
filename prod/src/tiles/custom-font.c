/*
 * custom-font.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef CUSTOM_FONT
#define CUSTOM_FONT

#define NUM_FONT_TILES 65

// adapted from gbdk/gbdk-lib/build/small/asxxxx/gb/f_italic.lst
const unsigned char alpha_num_italic_font[] = {
  0x05, // 1+4 -> 128 char encoding, compressed
  65, // 10 numbers, 26 lowercase letters, 26 uppercase, space, period, comma
  // character mappings
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // actual space here
  0, 0, 0, 0, 1, 0, 2, 0, // comma and period here
  3, 4, 5, 6, 7, 8, 9, 10,// numbers 0-7
  11,12,0, 0, 0, 0, 0, 0, // numbers 8-9
  0, 13,14,15,16,17,18,19,// capital A-G
  20,21,22,23,24,25,26,27,// capital H-O
  28,29,30,31,32,33,34,35,// capital P-W
  36,37,38,0, 0, 0, 0, 0, // capital X-Z
  0, 39,40,41,42,43,44,45,// lower a-g
  46,47,48,49,50,51,52,53,// lower h-o
  54,55,56,57,58,59,60,61,// lower p-w
  62,63,64,0, 0, 0, 0, 0, // lower x-z
  // characters
  // space
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  // , (comma)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x10,
  // . (period)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00,
  // 0
  0x00, 0x1C, 0x26, 0x4A, 0x54, 0xA4, 0xC8, 0x70,
  // 1
  0x00, 0x18, 0x28, 0x08, 0x10, 0x20, 0x20, 0xF8,
  // 2
  0x00, 0x3C, 0x42, 0x04, 0x18, 0x60, 0x80, 0xFC,
  // 3
  0x00, 0x3C, 0x42, 0x02, 0x0C, 0x02, 0x84, 0x78,
  // 4
  0x00, 0x0C, 0x34, 0x44, 0x88, 0xFE, 0x10, 0x10,
  //5
  0x00, 0x3E, 0x20, 0x40, 0x78, 0x04, 0x84, 0x78,
  //6
  0x00, 0x1C, 0x22, 0x40, 0x78, 0x84, 0x84, 0x78,
  //7
  0x00, 0x3E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20,
  //8
  0x00, 0x3C, 0x42, 0x3C, 0x42, 0x84, 0x84, 0x78,
  //9
  0x00, 0x3C, 0x42, 0x42, 0x3C, 0x04, 0x08, 0xF0,
  //A
  0x00, 0x1C, 0x22, 0x22, 0x7C, 0x44, 0x88, 0x88,
  //B
  0x00, 0x3C, 0x22, 0x3C, 0x42, 0x42, 0x84, 0xF8,
  //C
  0x00, 0x1C, 0x22, 0x40, 0x40, 0x80, 0x84, 0x78,
  //D
  0x00, 0x38, 0x24, 0x22, 0x42, 0x44, 0x88, 0xF0,
  //E
  0x00, 0x3E, 0x20, 0x40, 0x78, 0x40, 0x80, 0xF8, 
  //F
  0x00, 0x3E, 0x20, 0x40, 0x78, 0x40, 0x80, 0x80, 
  //G
  0x00, 0x1C, 0x22, 0x40, 0x40, 0x8E, 0x84, 0x78, 
  //H
  0x00, 0x22, 0x22, 0x44, 0x7C, 0x44, 0x88, 0x88, 
  //I
  0x00, 0x3E, 0x08, 0x08, 0x10, 0x20, 0x20, 0xF8, 
  //J
  0x00, 0x02, 0x02, 0x04, 0x04, 0x88, 0x88, 0x70, 
  //K
  0x00, 0x22, 0x24, 0x48, 0x70, 0x48, 0x88, 0x84, 
  //L
  0x00, 0x20, 0x20, 0x40, 0x40, 0x40, 0x80, 0xFC, 
  //M
  0x00, 0x36, 0x2A, 0x54, 0x54, 0x44, 0x88, 0x88, 
  //N
  0x00, 0x22, 0x32, 0x54, 0x54, 0x54, 0x98, 0x88, 
  //O
  0x00, 0x1C, 0x22, 0x42, 0x44, 0x84, 0x88, 0x70, 
  //P
  0x00, 0x3C, 0x22, 0x42, 0x7C, 0x40, 0x80, 0x80, 
  //Q
  0x00, 0x1C, 0x22, 0x42, 0x44, 0x94, 0x88, 0x74, 
  //R
  0x00, 0x3C, 0x22, 0x42, 0x7C, 0x48, 0x84, 0x84, 
  //S
  0x00, 0x1E, 0x20, 0x20, 0x18, 0x04, 0x84, 0x78, 
  //T
  0x00, 0xFE, 0x10, 0x20, 0x20, 0x20, 0x40, 0x40, 
  //U
  0x00, 0x22, 0x22, 0x44, 0x44, 0x88, 0x88, 0x70, 
  //V
  0x00, 0x42, 0x42, 0x44, 0x44, 0x88, 0x90, 0xE0, 
  //W
  0x00, 0x22, 0x22, 0x44, 0x54, 0xA8, 0xA8, 0x50, 
  //X
  0x00, 0x42, 0x24, 0x28, 0x10, 0x28, 0x48, 0x84, 
  //Y
  0x00, 0x42, 0x24, 0x28, 0x10, 0x10, 0x20, 0x20, 
  //Z
  0x00, 0x7E, 0x04, 0x08, 0x10, 0x20, 0x40, 0xFC, 
  //a
  0x00, 0x00, 0x00, 0x1C, 0x02, 0x3E, 0x44, 0x3C, 
  //b
  0x00, 0x10, 0x10, 0x20, 0x3C, 0x22, 0x44, 0x78, 
  //c
  0x00, 0x00, 0x00, 0x1E, 0x20, 0x40, 0x40, 0x3C, 
  //d
  0x00, 0x02, 0x02, 0x04, 0x3C, 0x44, 0x48, 0x38, 
  //e
  0x00, 0x00, 0x00, 0x1C, 0x22, 0x7C, 0x40, 0x38, 
  //f
  0x00, 0x0E, 0x10, 0x10, 0x38, 0x20, 0x40, 0x40, 
  //g
  0x00, 0x00, 0x1E, 0x22, 0x44, 0x3C, 0x04, 0x78, 
  //h
  0x00, 0x10, 0x10, 0x20, 0x3C, 0x22, 0x44, 0x44, 
  //i
  0x00, 0x08, 0x00, 0x18, 0x08, 0x10, 0x20, 0x70, 
  //j
  0x00, 0x04, 0x00, 0x04, 0x04, 0x48, 0x48, 0x30, 
  //k
  0x00, 0x10, 0x10, 0x20, 0x24, 0x38, 0x44, 0x44, 
  //l
  0x00, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x18, 
  //m
  0x00, 0x00, 0x00, 0x34, 0x2A, 0x2A, 0x54, 0x54, 
  //n
  0x00, 0x00, 0x00, 0x3C, 0x22, 0x22, 0x44, 0x44, 
  //o
  0x00, 0x00, 0x00, 0x1C, 0x22, 0x44, 0x44, 0x38,
  //0x00, 0x00, 0x1C, 0x22, 0x22, 0x44, 0x44, 0x38, 
  //p
  0x00, 0x00, 0x1C, 0x12, 0x22, 0x3C, 0x40, 0x40, 
  //q
  0x00, 0x00, 0x1E, 0x22, 0x24, 0x1C, 0x08, 0x0C, 
  //r
  0x00, 0x00, 0x00, 0x0E, 0x10, 0x10, 0x20, 0x20, 
  //s
  0x00, 0x00, 0x00, 0x1E, 0x20, 0x18, 0x04, 0x78, 
  //t
  0x00, 0x08, 0x08, 0x1C, 0x08, 0x10, 0x10, 0x20, 
  //u
  0x00, 0x00, 0x00, 0x22, 0x22, 0x44, 0x44, 0x38, 
  //v
  0x00, 0x00, 0x00, 0x22, 0x22, 0x44, 0x48, 0x30, 
  //w
  0x00, 0x00, 0x00, 0x22, 0x2A, 0x54, 0x54, 0x28, 
  //x
  0x00, 0x00, 0x00, 0x24, 0x28, 0x18, 0x24, 0x44, 
  //y
  0x00, 0x00, 0x00, 0x22, 0x22, 0x1C, 0x04, 0x78, 
  //z
  0x00, 0x00, 0x00, 0x3E, 0x04, 0x18, 0x20, 0x7C 
};

#endif

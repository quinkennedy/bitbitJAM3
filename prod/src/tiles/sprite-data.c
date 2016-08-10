/**
 * sprite-data.c
 *
 * Art created by David Frankel and Party Skeleton.
 * Converted to byte arrays with the help of this lovely web-based tool:
 *  http://www.chrisantonellis.com/gameboy/gbtdg/
 *
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef SPRITE_DATA
#define SPRITE_DATA

/*
const unsigned char allcombined_map_data[] ={
  // Virus
  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,0x10,0x0E,0x12,0x14,0x16,
  // King
                                                                   0x18,0x1A,0x1C,
  0x1E,0x20,0x22,0x24,0x26,0x26,0x26,0x28,0x2A,0x2C,
  // Immune cell
                                                    0x2E,0x30,0x32,0x34,0x36,0x38,
  0x3A,0x3C,0x3E,0x40,0x42,0x44,0x46,0x48,0x4A,0x4C,
  // Susceptible cell
                                                    0x4E,0x50,0x52,0x54,0x56,0x58,
  0x5A,0x5C,0x5E,0x60,0x62,0x64,0x66,0x68,0x6A,0x6C,0x6E,0x70,0x72,0x74,0x76,0x78,
  // Neuron
  0x7A,0x7C,0x7E,0x80,0x82,0x84,0x86,0x88,0x8A,0x8C,0x8E,0x90,0x92,0x94,0x96,0x98,
  0x9A,0x9C,0x9E,0xA0,
  // Shadow
                      0xA2,0xA4,0xA6,0xA8,0xAA,0xAC,0xAE,0xB0,0xB2,0xB4,
  // Susceptible death
                                                                        0x4E,0x50,
  0xB6,0xB8,0xBA,0xBC,0xBE,0xC0,0xC2,0xC4,0xC6,0xC8,0xCA,0xCC,0xCE,0xCE,
  // Virus death
                                                                        0xD0,0xD2,
  0xD4,0xD6,0xD8,0xCE,
  // Black
                      0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA,0xDA
};
*/

const unsigned char virus_tiles[] ={
  // standard animation
  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,0x10,0x0E,0x12,0x14,0x16/*,
  // death animation
  0x18,0x1A,0x1C,0x1E,0x20,0x22*/
  //TODO: implement death animation -- beware: sprite 0xCE was removed
};

const unsigned char king_tiles[] = {
  0x18,0x1A,0x1C,0x1E,0x20,0x22,0x24,0x26,0x26,0x26,0x28,0x2A,0x2C
};

const unsigned char immunity_tiles[] ={
  // standard animation
  0x2E,0x32,0x36,0x3A,0x3E,0x42,0x46,0x4A
};

const unsigned char neuron_tiles[] ={
  // standard animation
  0x7A,0x7E,0x82,0x86,0x8A,0x8E,0x92,0x96,0x9A,0x9E
};

const unsigned char skin_tiles[] ={
  // standard animation
  0x4E,0x52,0x56,0x5A,0x5E,0x62,0x66,0x6A,0x6E,0x72,0x76,
  // death animation
  0xCA,0x4E,0xB6,0xBA,0xBE,0xC2,0xC6,0xCA
};

#define NUM_SKIN_DEATH_FRAMES 8

const unsigned char shadow_tiles[] ={
  // standard animation
  0xA2,0xA6,0xAA,0xAE,0xB2
};

#define NUM_SHADOW_FRAMES 5

// 4*8 + 4*11 + 4*10 + 4*5 + 4*6
#define LG_SPRITE_DATA_SIZE 160

/*
const unsigned char white_tile[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
*/

//  virus + king + immune + cell   + neuron + shadow + partial skin death
// (12    + 11   + (4×8)  + (4×11) + (4×10) + (4×5)  + (4×5)+1           ) * 16
#define SPRITE_WHITE_INDEX 2880

const unsigned char sprite_tile_data[] = {
  /**
   * Virus
   * 13 frames (12 unique)
   * 8x8 pixels which will be expanded to 8x16 with 8x8 white bottom
   */
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x5C,0x64,0x38,0x38,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x30,0x30,0x78,0x48,0x34,0x2C,0x18,0x18,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x20,0x20,0x50,0x70,0x78,0x48,0x34,0x2C,0x18,0x18,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x30,0x30,0x78,0x48,0x34,0x2C,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x38,0x38,0x5C,0x64,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x0C,0x1E,0x12,0x1E,0x12,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x04,0x04,0x0E,0x1A,0x0E,0x0A,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x0C,0x1E,0x12,0x1E,0x12,0x14,0x1C,0x08,0x08,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x08,0x08,0x14,0x1C,0x1E,0x12,0x1C,0x14,0x08,0x08,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x1C,0x1C,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * King
   * 13 frames (11 unique)
   * 8x8 pixels which will be expanded to 8x16 using 8x8 white bottom
   */
  0x00,0x00,0x00,0x54,0x10,0x6C,0x7C,0x44,0x7C,0x7C,0x3C,0x24,0x3C,0x24,0x18,0x18,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x54,0x10,0x6C,0x7C,0x44,0x7C,0x7C,0x18,0x18,0x3C,0x24,0x5C,0x64,0x38,0x38,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x54,0x10,0x6C,0x7C,0x44,0x7C,0x7C,0x30,0x30,0x78,0x48,0x34,0x2C,0x18,0x18,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x54,0x10,0x6C,0x7C,0x44,0x7C,0x7C,0x50,0x70,0x78,0x48,0x34,0x2C,0x18,0x18,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x54,0x10,0x6C,0x7C,0x44,0x7C,0x7C,0x78,0x48,0x34,0x2C,0x38,0x38,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x5C,0x64,0x3C,0x24,0x18,0x18,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x1E,0x12,0x1E,0x12,0x0C,0x0C,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x1E,0x12,0x1E,0x12,0x14,0x1C,0x08,0x08,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x14,0x1C,0x1E,0x12,0x1C,0x14,0x08,0x08,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x2A,0x08,0x36,0x3E,0x22,0x3E,0x3E,0x3C,0x24,0x3C,0x24,0x18,0x18,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * Immune
   * 8 frames
   * 16x16 pixels, uses 2 sprites per frame
   */
  // frame 1
  0x01,0x01,0x23,0x22,0x73,0x52,0x3F,0x2E,0x1D,0x12,0x0F,0x08,0x0F,0x08,0x0D,0x0B,
  0x17,0x19,0x7E,0x71,0x7D,0x42,0x3B,0x3C,0x0B,0x0D,0x0E,0x0A,0x1C,0x14,0x08,0x08,
  0x80,0x80,0xC0,0x40,0xC6,0x46,0xBF,0x79,0xDF,0x21,0xFA,0x06,0xFC,0xE4,0x14,0xFC,
  0x0A,0xFE,0x8F,0xF9,0xFF,0x71,0xFE,0x02,0x7A,0x86,0xBC,0xC4,0x7C,0x74,0x08,0x08,
  // frame 2
  0x00,0x00,0x01,0x01,0x73,0x72,0xFF,0xCC,0x3E,0x21,0x1F,0x10,0x0D,0x0A,0x0F,0x09,
  0x0F,0x09,0x3E,0x31,0x7F,0x40,0x7B,0x5C,0x2B,0x2D,0x0E,0x0A,0x04,0x04,0x00,0x00,
  0x00,0x00,0xC2,0xC2,0xE7,0x25,0xDF,0x39,0xEE,0x12,0xFC,0x04,0xFC,0xE4,0x1C,0xF4,
  0x1E,0xF2,0x9F,0xF1,0xFB,0x67,0xF4,0x0C,0xBC,0xC4,0x7C,0x64,0x1C,0x14,0x18,0x18,
  // frame 3
  0x00,0x00,0x01,0x01,0x03,0x02,0x3F,0x3C,0xDF,0xE0,0xFE,0xB1,0x4F,0x49,0x09,0x0F,
  0x0E,0x09,0x3E,0x31,0x5F,0x60,0x7F,0x58,0x7D,0x5B,0x26,0x26,0x00,0x00,0x00,0x00,
  0x00,0x00,0x86,0x86,0xEF,0x69,0xD6,0x36,0xF8,0x08,0xF8,0xC8,0x34,0xEC,0x1C,0xF4,
  0x9C,0xF4,0x6E,0xF2,0x9F,0x65,0x6A,0x9A,0xF8,0xC8,0x38,0x28,0x38,0x28,0x30,0x30,
  // frame 4
  0x00,0x00,0x00,0x00,0x03,0x03,0x1F,0x1C,0x2F,0x30,0x7D,0x4B,0x7A,0x4F,0x3E,0x3B,
  0x0F,0x09,0x3E,0x31,0x5E,0x61,0x7B,0x5C,0xE7,0xA7,0x40,0x40,0x00,0x00,0x00,0x00,
  0x02,0x02,0x07,0x05,0xC2,0xC2,0x20,0xE0,0xD0,0x30,0xF0,0xD0,0x28,0xF8,0x38,0xE8,
  0x24,0xFC,0xCC,0xF4,0xBA,0x46,0xFF,0x0D,0x73,0x93,0xF0,0xD0,0xD0,0xB0,0x60,0x60,
  // frame 5
  0x00,0x00,0x00,0x00,0x07,0x07,0x3F,0x38,0x7F,0x40,0x77,0x4B,0x7C,0x47,0x3C,0x37,
  0x1E,0x13,0x37,0x29,0xFE,0xC1,0xDD,0xBA,0xEF,0xEB,0x06,0x06,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0x40,0xA0,0x60,0xF0,0xD0,0x20,0xF0,0x38,0xE8,
  0x4C,0xF4,0xF6,0x8E,0xDD,0x23,0xFF,0x0F,0xF0,0x90,0xB0,0xD0,0x78,0x48,0x30,0x30,
  // frame 6
  0x00,0x00,0x01,0x01,0x23,0x22,0x7F,0x5C,0x3F,0x20,0x3F,0x23,0x0C,0x17,0x1C,0x17,
  0x1C,0x17,0x9E,0x93,0xFF,0x61,0xDF,0xB0,0x6B,0x6D,0x0E,0x0A,0x04,0x04,0x00,0x00,
  0x00,0x00,0x80,0x80,0xC0,0x40,0xE0,0x20,0xF0,0x10,0xB0,0x70,0xF8,0xD8,0x28,0xF8,
  0x2A,0xFA,0x77,0xCD,0xFD,0x83,0x7E,0x8E,0xB0,0xD0,0x58,0x68,0x38,0x28,0x10,0x10,
  // frame 7
  0x00,0x00,0x01,0x01,0x33,0x32,0x6C,0x5F,0x3F,0x30,0x0E,0x09,0x07,0x07,0x0C,0x0F,
  0x14,0x1F,0x1E,0x13,0x2E,0x33,0x77,0x59,0x2D,0x2B,0x0E,0x0A,0x0C,0x0C,0x00,0x00,
  0x00,0x00,0xE0,0xE0,0xD0,0x30,0xF0,0x10,0xF0,0x10,0xA8,0x58,0x78,0x88,0xD8,0xE8,
  0x2C,0xF4,0x3E,0xE2,0x7E,0xC2,0xFC,0x84,0xE8,0x18,0xF4,0x8C,0x58,0x68,0x30,0x30,
  // frame 8
  0x01,0x01,0x03,0x02,0x33,0x32,0x2F,0x3E,0x1B,0x14,0x0F,0x08,0x0B,0x0D,0x0A,0x0F,
  0x16,0x1B,0x3F,0x31,0x7C,0x43,0x3B,0x3C,0x0F,0x09,0x0E,0x0A,0x1C,0x14,0x08,0x08,
  0x00,0x00,0xC0,0xC0,0xE6,0x26,0x6F,0xA9,0xF7,0x39,0xDE,0x22,0xFC,0xC4,0x3C,0xE4,
  0x1C,0xF4,0x1A,0xF6,0xFE,0xE2,0xFE,0x02,0x7C,0x84,0xB4,0xCC,0x78,0x68,0x10,0x10,
  /**
   * Skin
   * 11 frames
   * 16x16 pixels, uses 2 sprites per frame
   */
  //1
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x07,0x04,0x1F,0x18,0x37,0x28,0x3F,0x23,
  0x3C,0x27,0x3C,0x27,0x7C,0x47,0x7F,0x43,0x7F,0x40,0x57,0x68,0x3F,0x3F,0x00,0x00,
  0x00,0x00,0x00,0x00,0xC0,0xC0,0xF0,0x30,0xE8,0x18,0xF8,0x08,0xF8,0x08,0xFC,0xC4,
  0xBC,0x64,0x3A,0xE6,0x7E,0xC2,0xFE,0x82,0xFC,0x04,0xFC,0x04,0x78,0x88,0xF0,0xF0,
  //2
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x33,0x32,0x6F,0x5C,0x7F,0x40,0x7F,0x41,
  0x36,0x2B,0x3E,0x23,0x3A,0x27,0x7D,0x43,0x7F,0x40,0x5F,0x67,0x38,0x38,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x70,0xF8,0x88,0xD8,0x28,0xFC,0x04,0xFC,0x04,0xF8,0xC8,
  0xF8,0x48,0x78,0xC8,0xF8,0x88,0xFC,0x04,0xFC,0x04,0xFC,0x04,0xB8,0xC8,0x70,0x70,
  //3
  0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x31,0x7F,0x4E,0x77,0x48,0x7F,0x40,0x7F,0x41,
  0x3E,0x23,0x3E,0x23,0x3B,0x25,0x7E,0x41,0xFF,0x80,0xDF,0xA7,0x78,0x78,0x00,0x00,
  0x00,0x00,0x60,0x60,0xF0,0x90,0xD8,0x28,0xFC,0x04,0xFC,0x04,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0x78,0xC8,0xF0,0x90,0xFC,0x0C,0xFC,0x04,0xBC,0x44,0xF8,0x98,0x60,0x60,
  //4
  0x00,0x00,0x00,0x00,0x31,0x31,0x79,0x49,0xF7,0x8E,0xFF,0x80,0xFF,0x83,0x7C,0x47,
  0x3C,0x27,0x3E,0x23,0x3F,0x21,0x5D,0x62,0xFF,0x80,0xFF,0x86,0x79,0x49,0x30,0x30,
  0x00,0x00,0xE0,0xE0,0xF8,0x18,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x68,0xD8,
  0xF8,0x48,0x70,0xD0,0xF0,0x90,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xD8,0x38,0xE0,0xE0,
  //5
  0x00,0x00,0x00,0x00,0x01,0x01,0x3F,0x3E,0x7F,0x40,0xEF,0x93,0xFC,0x87,0x7C,0x47,
  0x3C,0x27,0x3F,0x23,0x3F,0x20,0x7E,0x41,0x77,0x48,0x7F,0x40,0x3F,0x3E,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0xF0,0x10,0xFC,0x0C,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0xF0,0x90,0xB8,0x48,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xF8,0x38,0xC0,0xC0,
  //6
  0x00,0x00,0x00,0x00,0x01,0x01,0x1F,0x1E,0x3F,0x20,0x7F,0x47,0x78,0x4F,0x78,0x4F,
  0x3C,0x27,0x3F,0x23,0x3F,0x20,0x7F,0x40,0x7B,0x44,0x3F,0x20,0x1F,0x1E,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0xF0,0x10,0xFC,0x0C,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0xB8,0xC8,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xFC,0x04,0xF8,0x38,0xC0,0xC0,
  //7
  0x00,0x00,0x01,0x01,0x03,0x02,0x1F,0x1C,0x3F,0x20,0x3F,0x23,0x5C,0x67,0x7C,0x47,
  0x7C,0x47,0x5F,0x63,0x7F,0x40,0x7F,0x40,0x7F,0x40,0x3F,0x30,0x0D,0x0E,0x03,0x03,
  0xC0,0xC0,0xE0,0x20,0xF0,0x10,0xFC,0x0C,0xEE,0x12,0xFE,0x02,0xFE,0x82,0x7C,0xC4,
  0xF8,0x08,0xF8,0x08,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xEC,0x1C,0xF0,0x30,0xC0,0xC0,
  //8
  0x00,0x00,0x01,0x01,0x07,0x06,0x1F,0x18,0x3F,0x20,0x1F,0x10,0x3F,0x23,0x7C,0x47,
  0x7F,0x43,0xFD,0x82,0xDE,0xA1,0xFF,0x80,0x7F,0x70,0x0F,0x08,0x07,0x04,0x03,0x03,
  0xE0,0xE0,0xF0,0x10,0xF0,0x10,0xFC,0x0C,0xF6,0x0A,0xFE,0x02,0xFE,0x02,0xFC,0x84,
  0xF8,0x08,0xF8,0x08,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x1C,0xE0,0x20,0xC0,0xC0,
  //9
  0x00,0x00,0x00,0x00,0x03,0x03,0x0F,0x0C,0x1F,0x10,0x1F,0x10,0x3F,0x23,0x3D,0x27,
  0x7D,0x47,0x6F,0x52,0xFF,0x80,0xFF,0x80,0x7F,0x60,0x1B,0x1C,0x06,0x07,0x01,0x01,
  0x60,0x60,0xF0,0x90,0xF0,0x10,0x78,0x88,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x04,
  0xB4,0x4C,0xFC,0x04,0xFA,0x06,0xFE,0x02,0xFE,0x02,0xFC,0x0C,0xD0,0x30,0xE0,0xE0,
  //10
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x1F,0x18,0x1F,0x10,0x3F,0x21,0x3E,0x23,
  0x7C,0x47,0x7C,0x47,0xEF,0x93,0xFF,0x80,0x7F,0x40,0x37,0x38,0x0E,0x0F,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0x70,0x90,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xF4,0x0C,0xFC,0x84,
  0xF4,0x0C,0xFC,0x84,0xFA,0x06,0xFE,0x02,0xFE,0x02,0xFC,0x04,0xD8,0x38,0xE0,0xE0,
  //11
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x0F,0x08,0x1F,0x10,0x3F,0x20,0x3F,0x23,
  0x3C,0x27,0x6C,0x57,0x7F,0x43,0x7F,0x40,0x7F,0x40,0x3F,0x30,0x0F,0x0F,0x00,0x00,
  0x00,0x00,0x00,0x00,0xE0,0xE0,0xF0,0x10,0xF8,0x08,0xE8,0x18,0xFC,0x04,0xFC,0x84,
  0xFC,0x44,0x7E,0xC2,0xFE,0x82,0xFE,0x02,0xFC,0x04,0xEC,0x14,0xB8,0x58,0xE0,0xE0,
  /**
   * Neuron
   * 10 frames
   * 16x16 pixels, uses 2 sprites per frame
   */
  //1
  0xC0,0xC0,0xE1,0xA1,0x63,0x52,0x3B,0x24,0x2F,0x31,0x3E,0x41,0xD7,0x98,0xCF,0xC9,
  0x0F,0x16,0x19,0x29,0x71,0x51,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x60,0x60,0x70,0x90,0xE0,0x60,0x80,0x80,0x00,0x00,0xE0,0xE0,0xF8,0x18,0xDC,0xE4,
  0x98,0x98,0xC0,0x40,0xC0,0x40,0xE0,0xA0,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //2
  0x20,0x20,0x70,0x51,0x6B,0x5A,0x3F,0x25,0x1F,0x11,0x3E,0x61,0xF7,0x98,0x6F,0x69,
  0x0F,0x0A,0x0F,0x16,0x19,0x29,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0xC0,0xE0,0x20,0xC0,0xC0,0x00,0x00,0x00,0x00,0xE0,0xF0,0xF0,0x08,0xFC,0xF4,
  0x88,0x88,0x80,0x80,0xC0,0x40,0xE0,0xA0,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //3
  0x1D,0x13,0x37,0x2E,0x3B,0x2D,0x0B,0x15,0x1F,0x11,0x1E,0x71,0xF7,0x88,0x7F,0x79,
  0x0F,0x0A,0x17,0x3A,0x3D,0x25,0x19,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0x20,0x80,0xC0,0x00,0x00,0x00,0x00,0x60,0x70,0xF0,0x88,0xFC,0x74,0x88,0x88,
  0x80,0x80,0x80,0x80,0xC0,0x40,0xC0,0x40,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //4
  0x0D,0x13,0x17,0x2E,0x1B,0x16,0x1B,0x15,0x5E,0x51,0x5F,0xB0,0x3F,0x49,0x3F,0x39,
  0x17,0x1A,0x17,0x2C,0x0F,0x12,0x0D,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0x40,0x80,0x80,0x80,0x80,0xC0,0xC0,0xC0,0x20,0xE0,0xD0,0x30,0x28,0x38,0x28,
  0x90,0x90,0x80,0x80,0x80,0x80,0xC0,0x40,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //5
  0x1D,0x38,0x7E,0x25,0x0F,0x25,0x1B,0x0D,0x7E,0x0F,0x7F,0xE7,0x3F,0x5E,0x1F,0x0E,
  0x3B,0x15,0x1F,0x0D,0x0F,0x1C,0x05,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0x80,0xC0,0x80,0x80,0x00,0xC0,0x00,0xC0,0xE0,0xE0,0x30,0x60,0x30,0xC0,0x60,
  0xC0,0x00,0x80,0x00,0xC0,0x80,0xC0,0x80,0xF8,0x40,0x7C,0x30,0xF0,0x68,0xA0,0x40,
  //6
  0x79,0x49,0x7F,0x56,0x3F,0x26,0x1B,0x14,0x7E,0x61,0xFF,0x80,0x7F,0x78,0x1F,0x1C,
  0x1F,0x12,0x0F,0x0A,0x1F,0x17,0x09,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0x20,0xE0,0x20,0xC0,0xC0,0x80,0x80,0xC0,0x40,0xE0,0x20,0xF0,0xD0,0x70,0x50,
  0x20,0x20,0x80,0x80,0xC0,0x40,0xC0,0x40,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //7
  0x71,0x20,0xD9,0x73,0xEF,0x7A,0x6B,0x3E,0x27,0x1E,0x3F,0x7F,0x6F,0xDF,0x76,0x1F,
  0x37,0x19,0x1F,0x09,0x19,0x30,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0x40,0xB0,0xE0,0xA0,0x00,0x00,0x00,0x00,0x00,0xC0,0x20,0xF0,0xE0,0xF0,0x10,
  0x90,0x00,0x80,0x00,0xC0,0x80,0xC0,0x80,0xF8,0x40,0x7C,0x30,0xF0,0x68,0xA0,0x40,
  //8
  0x01,0x62,0x77,0x95,0xFE,0x8A,0xEE,0x92,0x7F,0x79,0x1F,0x60,0x6F,0x90,0x56,0x69,
  0x77,0x56,0x73,0x52,0x31,0x29,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0x40,0xE0,0xA0,0x40,0x40,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xE0,0x60,
  0xE0,0x90,0x60,0xE0,0xC0,0x40,0xE0,0xA0,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //9
  0x63,0x63,0xF7,0x96,0xFF,0x89,0x5D,0x63,0x3F,0x31,0x3F,0x20,0x17,0x18,0x77,0x79,
  0x3F,0x22,0x39,0x29,0x39,0x29,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0xE0,0xD0,0x30,0xE0,0xE0,0x00,0x00,0x00,0x00,0x88,0x88,0xFC,0x74,0xF8,0x08,
  0xF0,0xF0,0xC0,0x40,0xC0,0x40,0xE0,0xA0,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  //10
  0x60,0x61,0xF3,0x92,0xDB,0xAA,0x7B,0x65,0x1F,0x11,0x3E,0x61,0x77,0x98,0x6F,0x69,
  0x0F,0x16,0x19,0x29,0x39,0x29,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0xE0,0xF0,0x10,0xE0,0xE0,0x00,0x00,0x08,0x08,0xFC,0xF4,0xF0,0x08,0xE0,0xF0,
  0x80,0x80,0xC0,0x40,0xC0,0x40,0xE0,0xA0,0xF8,0xB8,0x7C,0x4C,0xF0,0x98,0xA0,0xE0,
  /**
   * Shadow
   * 5 frames
   * 16x16 pixels, uses 2 sprites per frame
   */
  //1
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x01,0x0B,0x0A,0x1E,
  0x04,0x05,0x02,0x07,0x08,0x0E,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x60,0x00,0xC8,0xC0,0x80,
  0x00,0xA0,0x20,0xC8,0x00,0x90,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //2
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x04,0x00,0x02,0x02,0x16,
  0x05,0x25,0x00,0x05,0x0A,0x0C,0x00,0x01,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x40,0x00,0x60,0x40,0xC8,0x00,0x00,
  0x00,0xA0,0x00,0x80,0x00,0x90,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //3
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,
  0x00,0x24,0x08,0x09,0x00,0x02,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x60,0x00,0x80,0x00,0x40,
  0x80,0xA0,0x00,0x80,0x40,0x80,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //4
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x04,
  0x00,0x01,0x05,0x07,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0xC0,0x00,0x00,
  0x80,0x80,0x00,0x80,0x00,0x90,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //5
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0B,0x0A,0x1E,
  0x00,0x01,0x02,0x07,0x08,0x0E,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x40,0x00,0xC8,0xC0,0x80,
  0x00,0x80,0x00,0xC8,0x00,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * Skin Death
   * 7 frames (6 unique)
   * 16x16 pixels, uses 2 sprites per frame
   */
  //1
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x07,0x06,0x1F,0x1B,0x3C,0x27,
  0x38,0x2F,0x08,0x1F,0x3C,0x27,0x3E,0x23,0x1F,0x19,0x07,0x06,0x01,0x01,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xE0,0x20,0xF0,0x90,0x70,0xD0,
  0xB8,0x68,0x3C,0xE4,0x3C,0xE4,0x78,0xD8,0xF0,0x90,0xE0,0x60,0x80,0x80,0x00,0x00,
  //2
  0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x02,0x0A,0x0B,0x1E,0x17,0x08,0x0F,0x38,0x3F,
  0x30,0x2F,0x10,0x1F,0x18,0x1F,0x30,0x2F,0x13,0x1F,0x1E,0x12,0x0C,0x0C,0x00,0x00,
  0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0x40,0x58,0xD8,0x78,0xE8,0x1C,0xFC,
  0x0C,0xF4,0x18,0xF8,0x1C,0xEC,0x6C,0xF4,0xDE,0x52,0x8C,0x8C,0x00,0x00,0x00,0x00,
  //3
  0x00,0x00,0x01,0x01,0x21,0x21,0x60,0x60,0x00,0x10,0x00,0x08,0x22,0x22,0x30,0x30,
  0x80,0xF8,0x00,0x06,0x00,0x18,0x00,0x02,0x1C,0x1C,0x24,0x3C,0x3C,0x3C,0x00,0x00,
  0x80,0x80,0x40,0xC0,0x80,0x80,0x00,0x80,0x0C,0x8C,0x04,0x0C,0x20,0xB0,0x02,0x02,
  0x00,0x10,0x00,0x80,0x80,0xA4,0xC0,0xD2,0x0F,0x0F,0x09,0x0F,0x09,0x0F,0x06,0x06,
  //4
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x10,0x00,0x00,0x00,0x00,0x20,0x20,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x00,0x00,
  0x40,0x40,0x80,0x80,0x00,0x80,0x00,0x80,0x04,0x04,0x04,0x0C,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x92,0x00,0x08,0x03,0x03,0x07,0x07,0x06,0x06,
  //5
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x00,0x00,
  0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,
  //6
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,
  /**
   * Virus Death
   * 6 frames (5 unique)
   */
  0x68,0x4C,0x6E,0x82,0xE6,0x80,0x30,0x20,0x13,0x20,0xC5,0x03,0xA6,0xC6,0x60,0x60,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x42,0x42,0x81,0x00,0x20,0x20,0x40,0x00,0x00,0x00,0x00,0x42,0x81,0x00,0x42,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x42,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x02,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * Black
   */
//0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

#endif

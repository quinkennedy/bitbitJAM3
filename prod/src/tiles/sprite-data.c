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

const unsigned char virus_tiles[] ={
  // standard animation
  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,0x10,0x12,0x14,0x16,
  // death animation
  0x18,0x1A,0x1C,0x1E,0x20,0x22
};

const unsigned char immunity_tiles[] ={
  // standard animation
  0x24,0x28,0x2C,0x30,0x34,0x38,0x3C,0x40
};

const unsigned char neuron_tiles[] ={
  // standard animation
  0x44,0x48,0x4C,0x50,0x54,0x58,0x5C,0x60,0x64,0x68
};

const unsigned char skin_tiles[] ={
  // standard animation
  0x6C,0x70,0x74,0x78,0x7C,0x80,0x84,0x88,0x8C,0x90,0x94
};

const unsigned char shadow_tiles[] ={
  // standard animation
  0x98,0x9A,0xA0,0xA4,0xA8
};

// 12*2 + 6*2 + 8*4 + 10*4 + 11*4 + 5*4
#define SPRITE_DATA_SIZE 172

const unsigned char sprite_tile_data[] ={
  /**
   * Virus Sprite
   * 12 8x16 frames
   */
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x5C,0x64,0x38,0x38,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x30,0x30,0x78,0x48,0x34,0x2C,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x20,0x20,0x50,0x70,0x78,0x48,0x34,0x2C,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x30,0x30,0x78,0x48,0x34,0x2C,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x38,0x38,0x5C,0x64,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x0C,0x1E,0x12,0x1E,0x12,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x04,0x04,0x0E,0x1A,0x0E,0x0A,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x0C,0x1E,0x12,0x1E,0x12,0x14,0x1C,0x08,0x08,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x08,0x08,0x14,0x1C,0x1E,0x12,0x1C,0x14,0x08,0x08,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x1C,0x1C,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * Virus death animation
   * 6 8x16 frames
   */
  0x68,0x4C,0x6E,0x82,0xE6,0x80,0x30,0x20,0x13,0x20,0xC5,0x03,0xA6,0xC6,0x60,0x60,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x42,0x42,0x81,0x00,0x20,0x20,0x40,0x00,0x00,0x00,0x00,0x42,0x81,0x00,0x42,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x42,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  /**
   * Immunity cell animation
   * 8 16x16 frames
   */
  // Frame 0
  0x01,0x01,0x22,0x23,0x52,0x73,0x4E,0x7F,0x32,0x3F,0x08,0x0F,0x08,0x0F,0x0B,0x0F,
  0x19,0x1F,0x71,0x7F,0x42,0x7F,0x3C,0x3F,0x0D,0x0F,0x0A,0x0E,0x14,0x1C,0x08,0x08,
  0x80,0x80,0x40,0xC0,0x46,0xC6,0x79,0xFF,0x21,0xFF,0x06,0xFE,0xE4,0xFC,0xFC,0xFC,
  0xFE,0xFE,0xF9,0xFF,0x71,0xFF,0x02,0xFE,0x86,0xFE,0xC4,0xFC,0x74,0x7C,0x08,0x08,
  // Frame 1
  0x00,0x00,0x01,0x01,0x72,0x73,0x8C,0xFF,0x61,0x7F,0x10,0x1F,0x0A,0x0F,0x09,0x0F,
  0x09,0x0F,0x31,0x3F,0x40,0x7F,0x5C,0x7F,0x2D,0x2F,0x0A,0x0E,0x04,0x04,0x00,0x00,
  0x00,0x00,0xC2,0xC2,0x25,0xE7,0x39,0xFF,0x12,0xFE,0x04,0xFC,0xE4,0xFC,0xF4,0xFC,
  0xF2,0xFE,0xF1,0xFF,0x67,0xFF,0x0C,0xFC,0xC4,0xFC,0x64,0x7C,0x14,0x1C,0x18,0x18,
  // Frame 2
  0x00,0x00,0x01,0x01,0x02,0x03,0x3C,0x3F,0xE0,0xFF,0xB1,0xFF,0x49,0x4F,0x0F,0x0F,
  0x09,0x0F,0x31,0x3F,0x60,0x7F,0x58,0x7F,0x5B,0x7F,0x26,0x26,0x00,0x00,0x00,0x00,
  0x00,0x00,0x86,0x86,0x69,0xEF,0x36,0xF6,0x08,0xF8,0xC8,0xF8,0xEC,0xFC,0xF4,0xFC,
  0xF4,0xFC,0xF2,0xFE,0x65,0xFF,0x9A,0xFA,0xC8,0xF8,0x28,0x38,0x28,0x38,0x30,0x30,
  // Frame 3
  0x00,0x00,0x00,0x00,0x03,0x03,0x1C,0x1F,0x30,0x3F,0x4B,0x7F,0x4F,0x7F,0x3B,0x3F,
  0x09,0x0F,0x31,0x3F,0x61,0x7F,0x5C,0x7F,0xA7,0xE7,0x40,0x40,0x00,0x00,0x00,0x00,
  0x02,0x02,0x05,0x07,0xC2,0xC2,0xE0,0xE0,0x30,0xF0,0xD0,0xF0,0xF8,0xF8,0xE8,0xF8,
  0xFC,0xFC,0xF4,0xFC,0x46,0xFE,0x0D,0xFF,0x93,0xF3,0xD0,0xF0,0xB0,0xF0,0x60,0x60,
  // Frame 4
  0x00,0x00,0x00,0x00,0x07,0x07,0x08,0x0F,0x08,0x0F,0x1B,0x1F,0x27,0x3F,0x1F,0x1F,
  0x0B,0x0F,0x19,0x1F,0x61,0x7F,0xBA,0xFF,0x6B,0x6F,0x04,0x04,0x00,0x00,0x00,0x00,
  0x01,0x01,0x00,0x00,0x00,0x00,0xC0,0xC0,0x60,0xE0,0xD0,0xF0,0xF8,0xF8,0xE8,0xF8,
  0xF8,0xF8,0x8E,0xFE,0x23,0xFF,0x0E,0xFE,0x10,0xF0,0xD0,0xF0,0x60,0x60,0x00,0x00,
  // Frame 5
  0x00,0x00,0x1C,0x1C,0x62,0x7E,0x81,0xFF,0x80,0xFF,0x83,0xFF,0x77,0x7F,0x17,0x1F,
  0x17,0x1F,0x93,0x9F,0x61,0xFF,0xB0,0xFF,0x6D,0x6F,0x0A,0x0E,0x04,0x04,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0x60,0xE0,0xD0,0xF0,0xF8,0xF8,
  0xFA,0xFA,0xCD,0xFF,0x83,0xFF,0x8E,0xFE,0xD0,0xF0,0x68,0x78,0x28,0x38,0x10,0x10,
  // Frame 6
  0x00,0x00,0x01,0x01,0x32,0x33,0x5F,0x7F,0x30,0x3F,0x09,0x0F,0x07,0x07,0x0F,0x0F,
  0x1F,0x1F,0x13,0x1F,0x33,0x3F,0x59,0x7F,0x2B,0x2F,0x0A,0x0E,0x0C,0x0C,0x00,0x00,
  0x00,0x00,0xE0,0xE0,0x30,0xF0,0x10,0xF0,0x10,0xF0,0x58,0xF8,0x88,0xF8,0xE8,0xF8,
  0xF4,0xFC,0xE2,0xFE,0xC2,0xFE,0x84,0xFC,0x18,0xF8,0x8C,0xFC,0x68,0x78,0x30,0x30,
  // Frame 7
  0x00,0x00,0x02,0x02,0x35,0x37,0x5A,0x7B,0x34,0x3F,0x08,0x0F,0x0D,0x0F,0x0F,0x0F,
  0x1B,0x1F,0x31,0x3F,0x43,0x7F,0x3C,0x3F,0x09,0x0F,0x0A,0x0E,0x14,0x1C,0x08,0x08,
  0x00,0x00,0x00,0x00,0x86,0x86,0xC9,0xCF,0x39,0xFF,0x22,0xFE,0xC4,0xFC,0xE4,0xFC,
  0xF4,0xFC,0xF6,0xFE,0xE2,0xFE,0x02,0xFE,0x84,0xFC,0xCC,0xFC,0x68,0x78,0x10,0x10,
  /**
   * Neuron animation
   * 10 16x16 frames
   */
  // Frame 0
  0xC0,0xC0,0xA1,0xE1,0x52,0x73,0x24,0x3F,0x31,0x3F,0x41,0x7F,0x98,0xDF,0xC9,0xCF,
  0x16,0x1F,0x29,0x39,0x51,0x71,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x60,0x60,0x90,0xF0,0x60,0xE0,0x80,0x80,0x00,0x00,0xE0,0xE0,0x18,0xF8,0xE4,0xFC,
  0x98,0x98,0x40,0xC0,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 1
  0x20,0x20,0x51,0x71,0x5A,0x7B,0x25,0x3F,0x11,0x1F,0x61,0x7F,0x98,0xFF,0x69,0x6F,
  0x0A,0x0F,0x16,0x1F,0x29,0x39,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0xC0,0x20,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0xF0,0xF0,0x08,0xF8,0xF4,0xFC,
  0x88,0x88,0x80,0x80,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 2
  0x13,0x1F,0x2E,0x3F,0x2D,0x3F,0x15,0x1F,0x11,0x1F,0x71,0x7F,0x88,0xFF,0x79,0x7F,
  0x0A,0x0F,0x3A,0x3F,0x25,0x3D,0x19,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x20,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x70,0x70,0x88,0xF8,0x74,0xFC,0x88,0x88,
  0x80,0x80,0x80,0x80,0x40,0xC0,0x40,0xC0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 3
  0x13,0x1F,0x2E,0x3F,0x16,0x1F,0x15,0x1F,0x51,0x5F,0xB0,0xFF,0x49,0x7F,0x39,0x3F,
  0x1A,0x1F,0x2C,0x3F,0x12,0x1F,0x0D,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x40,0xC0,0x80,0x80,0x80,0x80,0xC0,0xC0,0x20,0xE0,0xD0,0xF0,0x28,0x38,0x28,0x38,
  0x90,0x90,0x80,0x80,0x80,0x80,0x40,0xC0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 4
  0x25,0x3D,0x5B,0x7F,0x2A,0x2F,0x16,0x1F,0x71,0x7F,0x98,0xFF,0x61,0x7F,0x11,0x1F,
  0x2E,0x3F,0x12,0x1F,0x13,0x1F,0x0D,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x40,0xC0,0x40,0xC0,0x80,0x80,0xC0,0xC0,0x20,0xE0,0xD0,0xF0,0x50,0x70,0xA0,0xE0,
  0xC0,0xC0,0x80,0x80,0x40,0xC0,0x40,0xC0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 5
  0x26,0x3F,0x5A,0x7F,0x5B,0x7F,0x36,0x3F,0x78,0x7F,0x88,0xFF,0x70,0x7F,0x11,0x1F,
  0x26,0x3F,0x1A,0x1F,0x25,0x3D,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x80,0x80,0x80,0x80,0x40,0xC0,0x40,0xC0,0xE0,0xE0,0x90,0xF0,0x90,0xF0,0x60,0xE0,
  0x80,0x80,0x80,0x80,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 6
  0x51,0x71,0xAA,0xFB,0x95,0xFF,0x55,0x7F,0x39,0x3F,0x40,0x7F,0xB0,0xFF,0x69,0x7F,
  0x2E,0x3F,0x16,0x1F,0x29,0x39,0x11,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xA0,0xE0,0x50,0xF0,0xA0,0xA0,0x00,0x00,0x00,0x00,0xE0,0xE0,0x10,0xF0,0xE0,0xF0,
  0x90,0x90,0x80,0x80,0x40,0xC0,0x40,0xC0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 7
  0x62,0x63,0x95,0xF7,0x8A,0xFE,0x92,0xFE,0x79,0x7F,0x60,0x7F,0x90,0xFF,0x69,0x7F,
  0x56,0x77,0x52,0x73,0x29,0x39,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x40,0xC0,0xA0,0xE0,0x40,0x40,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x60,0xE0,
  0x90,0xF0,0xE0,0xE0,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 8
  0x61,0x61,0x92,0xF3,0x4D,0xFF,0xA5,0xFF,0x59,0x5F,0x70,0x7F,0x89,0xFF,0x71,0x7F,
  0x2E,0x3F,0x29,0x39,0x15,0x1D,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x20,0xE0,0xD0,0xF0,0x20,0x20,0x00,0x00,0x80,0x80,0x40,0xC0,0xA0,0xE0,0x50,0x70,
  0xD0,0xF0,0x60,0xE0,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  // Frame 9
  0x61,0x61,0x92,0xF3,0xAA,0xFB,0x65,0x7F,0x11,0x1F,0x61,0x7F,0x98,0xFF,0x69,0x6F,
  0x16,0x1F,0x29,0x39,0x29,0x39,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0xE0,0x10,0xF0,0xE0,0xE0,0x00,0x00,0x08,0x08,0xF4,0xFC,0x08,0xF8,0xF0,0xF0,
  0x80,0x80,0x40,0xC0,0x40,0xC0,0xA0,0xE0,0xB8,0xF8,0x4C,0x7C,0x98,0xF8,0xE0,0xE0,
  /**
   * Skin cell animation
   * 11 16x16 frames
   */
  // Frame 0
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x07,0x04,0x1F,0x18,0x37,0x28,0x3F,0x23,
  0x3C,0x27,0x3C,0x27,0x7C,0x47,0x7F,0x43,0x7F,0x40,0x57,0x68,0x3F,0x3F,0x00,0x00,
  0x00,0x00,0x00,0x00,0xC0,0xC0,0xF0,0x30,0xE8,0x18,0xF8,0x08,0xF8,0x08,0xFC,0xC4,
  0xBC,0x64,0x3A,0xE6,0x7E,0xC2,0xFE,0x82,0xFC,0x04,0xFC,0x04,0x78,0x88,0xF0,0xF0,
  // Frame 1
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x33,0x32,0x6F,0x5C,0x7F,0x40,0x7F,0x41,
  0x36,0x2B,0x3E,0x23,0x3A,0x27,0x7D,0x43,0x7F,0x40,0x5F,0x67,0x38,0x38,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x70,0xF8,0x88,0xD8,0x28,0xFC,0x04,0xFC,0x04,0xF8,0xC8,
  0xF8,0x48,0x78,0xC8,0xF8,0x88,0xFC,0x04,0xFC,0x04,0xFC,0x04,0xB8,0xC8,0x70,0x70,
  // Frame 2
  0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x31,0x7F,0x4E,0x77,0x48,0x7F,0x40,0x7F,0x41,
  0x3E,0x23,0x3E,0x23,0x3B,0x25,0x7E,0x41,0xFF,0x80,0xDF,0xA7,0x78,0x78,0x00,0x00,
  0x00,0x00,0x60,0x60,0xF0,0x90,0xD8,0x28,0xFC,0x04,0xFC,0x04,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0x78,0xC8,0xF0,0x90,0xFC,0x0C,0xFC,0x04,0xBC,0x44,0xF8,0x98,0x60,0x60,
  // Frame 3
  0x00,0x00,0x00,0x00,0x31,0x31,0x79,0x49,0xF7,0x8E,0xFF,0x80,0xFF,0x83,0x7C,0x47,
  0x3C,0x27,0x3E,0x23,0x3F,0x21,0x5D,0x62,0xFF,0x80,0xFF,0x86,0x79,0x49,0x30,0x30,
  0x00,0x00,0xE0,0xE0,0xF8,0x18,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x68,0xD8,
  0xF8,0x48,0x70,0xD0,0xF0,0x90,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xD8,0x38,0xE0,0xE0,
  // Frame 4
  0x00,0x00,0x00,0x00,0x01,0x01,0x3F,0x3E,0x7F,0x40,0xEF,0x93,0xFC,0x87,0x7C,0x47,
  0x3C,0x27,0x3F,0x23,0x3F,0x20,0x7E,0x41,0x77,0x48,0x7F,0x40,0x3F,0x3E,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0xF0,0x10,0xFC,0x0C,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0xF0,0x90,0xB8,0x48,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xF8,0x38,0xC0,0xC0,
  // Frame 5
  0x00,0x00,0x00,0x00,0x01,0x01,0x1F,0x1E,0x3F,0x20,0x7F,0x47,0x78,0x4F,0x78,0x4F,
  0x3C,0x27,0x3F,0x23,0x3F,0x20,0x7F,0x40,0x7B,0x44,0x3F,0x20,0x1F,0x1E,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0xF0,0x10,0xFC,0x0C,0xFE,0x02,0xFE,0x02,0xFC,0x84,0x78,0xC8,
  0xF8,0x48,0xB8,0xC8,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xFC,0x04,0xF8,0x38,0xC0,0xC0,
  // Frame 6
  0x00,0x00,0x01,0x01,0x03,0x02,0x1F,0x1C,0x3F,0x20,0x3F,0x23,0x5C,0x67,0x7C,0x47,
  0x7C,0x47,0x5F,0x63,0x7F,0x40,0x7F,0x40,0x7F,0x40,0x3F,0x30,0x0D,0x0E,0x03,0x03,
  0xC0,0xC0,0xE0,0x20,0xF0,0x10,0xFC,0x0C,0xEE,0x12,0xFE,0x02,0xFE,0x82,0x7C,0xC4,
  0xF8,0x08,0xF8,0x08,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xEC,0x1C,0xF0,0x30,0xC0,0xC0,
  // Frame 7
  0x00,0x00,0x01,0x01,0x07,0x06,0x1F,0x18,0x3F,0x20,0x1F,0x10,0x3F,0x23,0x7C,0x47,
  0x7F,0x43,0xFD,0x82,0xDE,0xA1,0xFF,0x80,0x7F,0x70,0x0F,0x08,0x07,0x04,0x03,0x03,
  0xE0,0xE0,0xF0,0x10,0xF0,0x10,0xFC,0x0C,0xF6,0x0A,0xFE,0x02,0xFE,0x02,0xFC,0x84,
  0xF8,0x08,0xF8,0x08,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x1C,0xE0,0x20,0xC0,0xC0,
  // Frame 8
  0x00,0x00,0x00,0x00,0x03,0x03,0x0F,0x0C,0x1F,0x10,0x1F,0x10,0x3F,0x23,0x3D,0x27,
  0x7D,0x47,0x6F,0x52,0xFF,0x80,0xFF,0x80,0x7F,0x60,0x1B,0x1C,0x06,0x07,0x01,0x01,
  0x60,0x60,0xF0,0x90,0xF0,0x10,0x78,0x88,0xFC,0x04,0xFE,0x02,0xFE,0x02,0xFC,0x04,
  0xB4,0x4C,0xFC,0x04,0xFA,0x06,0xFE,0x02,0xFE,0x02,0xFC,0x0C,0xD0,0x30,0xE0,0xE0,
  // Frame 9
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x1F,0x18,0x1F,0x10,0x3F,0x21,0x3E,0x23,
  0x7C,0x47,0x7C,0x47,0xEF,0x93,0xFF,0x80,0x7F,0x40,0x37,0x38,0x0E,0x0F,0x01,0x01,
  0x00,0x00,0xE0,0xE0,0x70,0x90,0xF8,0x08,0xFC,0x04,0xFC,0x04,0xF4,0x0C,0xFC,0x84,
  0xF4,0x0C,0xFC,0x84,0xFA,0x06,0xFE,0x02,0xFE,0x02,0xFC,0x04,0xD8,0x38,0xE0,0xE0,
  // Frame 10
  0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x04,0x0F,0x08,0x1F,0x10,0x3F,0x20,0x3F,0x23,
  0x3C,0x27,0x6C,0x57,0x7F,0x43,0x7F,0x40,0x7F,0x40,0x3F,0x30,0x0F,0x0F,0x00,0x00,
  0x00,0x00,0x00,0x00,0xE0,0xE0,0xF0,0x10,0xF8,0x08,0xE8,0x18,0xFC,0x04,0xFC,0x84,
  0xFC,0x44,0x7E,0xC2,0xFE,0x82,0xFE,0x02,0xFC,0x04,0xEC,0x14,0xB8,0x58,0xE0,0xE0,
  /**
   * Generic cell shadow animation
   * 5 16x16 frames
   */
  // Frame 0
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x01,0x0B,0x0A,0x1E,
  0x04,0x05,0x02,0x07,0x08,0x0E,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x60,0x00,0xC8,0xC0,0x80,
  0x00,0xA0,0x20,0xC8,0x00,0x90,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // Frame 1
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x04,0x00,0x02,0x02,0x16,
  0x05,0x25,0x00,0x05,0x0A,0x0C,0x00,0x01,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x40,0x00,0x60,0x40,0xC8,0x00,0x00,
  0x00,0xA0,0x00,0x80,0x00,0x90,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // Frame 2
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,
  0x00,0x24,0x08,0x09,0x00,0x02,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x60,0x00,0x80,0x00,0x40,
  0x80,0xA0,0x00,0x80,0x40,0x80,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // Frame 3
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x04,
  0x00,0x01,0x05,0x07,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0xC0,0x00,0x00,
  0x80,0x80,0x00,0x80,0x00,0x90,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // Frame 4
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0B,0x0A,0x1E,
  0x00,0x01,0x02,0x07,0x08,0x0E,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x40,0x00,0xC8,0xC0,0x80,
  0x00,0x80,0x00,0xC8,0x00,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif

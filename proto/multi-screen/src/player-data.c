
const unsigned char player_tiles[] = {
  0x00,0x02,
  0x04,0x06,
  0x08,0x0A,
  0x0C,0x0E,
  0x10,0x12,
  0x14,0x16
};

const unsigned char player_sprite_data[] = {
  // Frame 1
  0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x7F,0x27,0x78,0x1A,0x67,0x50,0x6F,0x6F,0x5F,
  0x6F,0x58,0x3B,0xD4,0xDF,0xB0,0x5D,0x6A,0x2F,0x34,0x17,0x1B,0x0B,0x0C,0x05,0x07,
  0x00,0x00,0x00,0x00,0xC0,0xC0,0xA0,0x60,0x50,0xB0,0xA8,0xD8,0x94,0xEC,0xAA,0xF6,
  0xC6,0x7A,0xF8,0x34,0x6C,0xB4,0xF4,0x2C,0xF0,0xCC,0xC8,0x3C,0x60,0xFC,0x80,0x80,
  // Frame 2
  0x00,0x00,0x00,0x00,0x01,0x01,0x0F,0x7E,0x26,0x79,0x1A,0x67,0x50,0x6F,0x69,0x5F,
  0x63,0x5E,0x27,0xDE,0xA3,0xDE,0x53,0x6F,0x28,0x37,0x15,0x1B,0x0B,0x0C,0x05,0x07,
  0x00,0x00,0xE0,0xE0,0x50,0xB0,0xA8,0x58,0x54,0xEC,0x0A,0xF6,0x75,0xFB,0xFB,0x9D,
  0xDC,0x2A,0x7E,0x8A,0xDE,0x2A,0xFA,0x96,0x78,0xE6,0x64,0x9E,0xB0,0x7E,0xC0,0xC0,
  // Frame 3
  0x00,0x00,0x00,0x00,0x07,0x3F,0x13,0x3C,0x0D,0x33,0x28,0x37,0x34,0x2F,0x31,0x2F,
  0x11,0x6F,0x65,0x5F,0x51,0x6F,0x29,0x37,0x14,0x1B,0x0A,0x0D,0x05,0x06,0x02,0x03,
  0x00,0x00,0x60,0x60,0x50,0xB0,0xA8,0x58,0x54,0xEC,0x7A,0xF6,0xFD,0x8B,0xDF,0x25,
  0xFC,0x0A,0xDE,0x2A,0xBE,0x4A,0xFA,0x16,0xF8,0xE6,0xE4,0x9E,0xB0,0x7E,0xC0,0xC0,
  // Frame 4
  0x00,0x00,0x00,0x00,0x07,0x3F,0x13,0x3C,0x0D,0x33,0x29,0x37,0x37,0x2E,0x33,0x2E,
  0x13,0x6E,0x67,0x5E,0x51,0x6F,0x29,0x37,0x14,0x1B,0x0A,0x0D,0x05,0x06,0x02,0x03,
  0x00,0x00,0x60,0x60,0x50,0xB0,0xA8,0x58,0x54,0xEC,0xEA,0xF6,0xF5,0x1B,0x73,0x9D,
  0xFC,0x1A,0x56,0xBA,0xE6,0x3A,0xEA,0xF6,0x18,0xE6,0xE4,0x9E,0xB0,0x7E,0xC0,0xC0,
  // Frame 5
  0x00,0x00,0x0E,0x7F,0x27,0x78,0x1F,0x67,0x5F,0x68,0x7B,0x54,0x7F,0x50,0x3D,0xD2,
  0xCF,0xB8,0xA7,0xDF,0x52,0x6F,0x29,0x37,0x14,0x1B,0x0A,0x0D,0x05,0x06,0x02,0x03,
  0xC0,0xC0,0xA0,0x60,0x50,0xB0,0xA8,0xD8,0x94,0xEC,0xEA,0x76,0xF5,0x3B,0x73,0xBD,
  0xEC,0x3A,0xC6,0xFA,0x46,0xFA,0x2A,0xF6,0x18,0xE6,0xE4,0x9E,0xB0,0x7E,0xC0,0xC0,
  // Frame 6
  0x00,0x00,0x0E,0x7F,0x27,0x78,0x1A,0x67,0x57,0x6F,0x6F,0x58,0x6B,0x5C,0x3F,0xD0,
  0xDD,0xB2,0xBF,0xD0,0x5F,0x6F,0x28,0x37,0x15,0x1B,0x0B,0x0C,0x05,0x07,0x00,0x00,
  0xC0,0xC0,0xA0,0x60,0x50,0xB0,0xA8,0xD8,0x14,0xEC,0xEA,0xF6,0xE6,0x3A,0xF8,0x34,
  0x6C,0xB4,0xEC,0x34,0xD4,0xEC,0x30,0xCC,0xC8,0x3C,0x60,0xFC,0x80,0x80,0x00,0x00
};


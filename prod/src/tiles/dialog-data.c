/**
 * portrait-data.c
 *
 * Art created by David Frankel and Party Skeleton.
 * Converted to byte arrays with the help of this lovely web-based tool:
 *  http://www.chrisantonellis.com/gameboy/gbtdg/
 *
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_DATA
#define DIALOG_DATA

#include <types.h>
#include "../include/entity.h"

#define DIALOG_DATA_SIZE 160
#define DIALOG_SCREEN_TILES_START 144
#define NEXT_TILES_START 18
#define TEXT_SCREEN_TILES_START 20
#define DIALOG_BLACK 3
#define DIALOG_DKGREY 0x93
#define NUM_BG_TILES 26

const unsigned char nine_slice_thin_frame[] = {
//  0x86, 0x87, 0x88,
//  0x8A, 0x89, 0x8B,
//  0x8C, 0x8D, 0x8E
  0, 1, 2,
  4, 3, 5,
  6, 7, 8
//  the below numbers are pre-offset to account for the loaded font
//  200, 201, 202,
//  204, 203, 205,
//  206, 207, 208
};

const unsigned char nine_slice_thick_frame[] = {
//  0x8F, 0x90, 0x91,
//  0x92, 0x93, 0x94,
//  0x95, 0x96, 0x97
  9, 10, 11,
  12, 13, 14,
  15, 16, 17
//  the below numbers are pre-offset to account for the loaded font
//  209, 210, 211,
//  212, 213, 214,
//  215, 216, 217
};
/*
const unsigned char text_only_header[] = {
  0x9A,0x9B,0x9C,0x9C,0x9C,0x9C,0x9C,
  0x9C,0x9C,0x9C,0x9C,0x9C,0x9C,0x9C,
  0x9C,0x9C,0x9C,0x9C,0x9D,0x9E,0x9F
};
*/

const unsigned char dialog_tiles[] = {
  // Immunity
//0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,
//0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x33,0x43,0x44,0x45,0x37,0x46,0x39,0x3A,
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
  0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x08,0x18,0x19,0x1A,0x0C,0x1B,0x0E,0x0F,
  // Cell
//0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55,0x56,
//0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x63,0x64,0x65,0x66,
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
  0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
  // Neuron
//0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x73,0x74,0x75,0x76,
//0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,0x80,0x71,0x81,0x82,0x83,0x84,0x85,
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
  0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x0A,0x1A,0x1B,0x1C,0x1D,0x1E,
  // Princess
//0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
//0x10,0x20,0x12,0x13,0x21,0x22,0x23,0x24,0x18,0x19,0x25,0x26,0x27,0x28,0x29,0x2A,
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
  0x00,0x10,0x02,0x03,0x11,0x12,0x13,0x14,0x08,0x09,0x15,0x16,0x17,0x18,0x19,0x1A,
  // Skeletor
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F
};

typedef struct PortraitDataInfo {
  UINT16 dataStart;
  UINT8  dataLength;
  UINT8  frames;
  UINT8  tileStart;
  EntityType eType;
} PortraitDataInfo;

const PortraitDataInfo dialog_info[] = {
  // Immunity
  { 688, 28, 2, 0, IMMUNE},
  // Cell
  { 1136, 32, 2, 32, SKIN},
  // Neuron
  { 1648, 31, 2, 64, NEURON},
  // Princess
  { 256, 27, 2, 96, VIRUS},
  // Skeletor
  { 0, 16, 1, 128, VIRUS}
};

const unsigned char dialog_data[] = {
  // Skeletor
  0xFC,0xFF,0xE1,0xFE,0xE0,0xFE,0xE0,0xF8,0x80,0xF8,0xD0,0xE1,0xE8,0xF4,0xF5,0xF8,
  0x9F,0xE0,0x7F,0xC0,0xBF,0x60,0x5F,0xB0,0x3D,0x13,0x6A,0x36,0x66,0x3C,0xDE,0x68,
  0xFF,0x00,0xFF,0x00,0xFF,0x00,0x7D,0xFE,0x9B,0x83,0x11,0x00,0x79,0x78,0xF7,0x8E,
  0xC7,0x3F,0xE3,0x1F,0xF3,0x0F,0xF1,0x0F,0xB9,0xC7,0x58,0x67,0x2C,0x33,0xBC,0x13,
  0xEB,0xFD,0xEE,0xFF,0xDE,0xED,0xFC,0xC8,0xF4,0xDA,0xF8,0xD6,0xF8,0xD2,0xF8,0xD0,
  0x9B,0xE1,0x12,0xC2,0x92,0x82,0x54,0x44,0x34,0x24,0x34,0x24,0x36,0x26,0x71,0x61,
  0x0D,0x03,0x03,0x01,0x02,0x21,0x01,0x30,0x01,0x20,0x01,0x00,0x1E,0x1F,0xE8,0xE7,
  0xB8,0x13,0xA8,0x03,0xA8,0x83,0xA8,0x83,0xE8,0x83,0x69,0x87,0x6B,0x87,0x37,0xCF,
  0xEB,0xD3,0xEF,0xF4,0xE8,0xFE,0xE7,0xFF,0xE7,0xFF,0xE7,0xFF,0xEF,0xFF,0xEF,0xFF,
  0x91,0x80,0x91,0x10,0x91,0x10,0xA9,0x38,0xB1,0x90,0x93,0x80,0xD7,0xC7,0xF9,0x79,
  0xE6,0x01,0xA7,0x01,0x25,0x03,0x24,0x03,0x2E,0x01,0x2E,0x0F,0x3F,0x33,0xE7,0xE6,
  0x7F,0xFF,0xFF,0xFF,0xE1,0xFF,0xD8,0xE7,0xDE,0xE1,0x7C,0xC3,0xEB,0xC7,0xEF,0xC7,
  0xEF,0xFF,0xEF,0xFF,0xFF,0xFF,0xEF,0xFF,0xEF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0xFF,
  0xDB,0x53,0xDA,0x52,0xFE,0xFE,0xD3,0x93,0xF9,0xD1,0x7F,0xBF,0x5C,0x80,0xDC,0xC0,
  0x66,0x24,0x6F,0x2E,0xFF,0xFB,0x5F,0x4A,0x7F,0x2B,0xFE,0xFE,0x0C,0x00,0x05,0x00,
  0x4F,0xC7,0xC7,0xCF,0x47,0xCF,0x5F,0xCF,0x9F,0xCF,0x3F,0xDF,0x3F,0xFF,0xFF,0xFF,
  // Princess
  0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFE,0x00,0xED,0x00,0xDB,0x00,0xB7,0x01,0xFE,0x03,
  0xEE,0x03,0x9D,0x06,0x3A,0x0C,0xF4,0x18,0xE8,0x70,0x91,0xE1,0x62,0x82,0xC2,0x02,
  0xAD,0x18,0x3F,0x08,0x17,0x0C,0x17,0x0C,0xFF,0xFD,0x0F,0x05,0xDF,0xDE,0xDF,0xDE,
  0xEF,0xC5,0xBF,0xE5,0xBF,0xE2,0xB7,0xF2,0x97,0x72,0xDF,0x31,0xDB,0x39,0x5F,0x39,
  0xFD,0x0F,0xF3,0x1C,0xEF,0x30,0xFF,0x27,0xDF,0x64,0xFC,0x44,0xBE,0xC2,0xFF,0x81,
  0x82,0x02,0xE1,0xC1,0xF9,0x21,0x7C,0x98,0xDF,0xE6,0xF7,0x39,0x3E,0x0F,0x0F,0x09,
  0x06,0x02,0x5C,0x54,0xFD,0xFC,0x03,0x01,0x27,0x02,0xE7,0xC4,0x81,0x03,0xC7,0xC6,
  0x5F,0x3B,0xFF,0x3B,0xFF,0xDB,0xDF,0x37,0xBF,0x7F,0xFB,0xCF,0xCB,0x8F,0x9B,0x9F,
  0x7F,0x80,0x77,0x88,0xFF,0x00,0x70,0x85,0xF0,0xC0,0x38,0x20,0x98,0x90,0xD8,0xF0,
  0x89,0x88,0xE1,0x61,0x1E,0x1E,0x00,0x00,0x00,0x21,0x00,0x80,0x00,0x00,0x00,0x00,
  0xCE,0x44,0x8E,0x8E,0x0D,0x0D,0x0C,0x04,0x0C,0x04,0x04,0x04,0x06,0x02,0x1E,0x0E,
  0x9B,0x9F,0x2B,0x3F,0xFB,0xCF,0x1B,0x2F,0x1B,0xAF,0x3B,0x1F,0x37,0x1F,0x17,0x37,
  0xD4,0xD8,0x9A,0xFC,0x25,0xFE,0xE3,0xFF,0x20,0xFF,0x28,0xF7,0x51,0xEA,0x60,0xD5,
  0x00,0x00,0x00,0x01,0x00,0x02,0x80,0x07,0xA0,0xC3,0x68,0xF0,0x1D,0xFE,0x83,0x7F,
  0x00,0x00,0x00,0xF8,0x01,0x08,0x02,0xF9,0x05,0xF3,0x0A,0x07,0x0D,0x1E,0xF3,0xFC,
  0x77,0x37,0xA7,0x7F,0x4B,0xFF,0xF3,0xFF,0x03,0xFF,0xFB,0x07,0xBD,0x03,0xAD,0x03,
  0xEE,0x03,0x9D,0x06,0x3A,0x0C,0xF4,0x18,0xE8,0x70,0x91,0xE1,0x62,0x82,0xC2,0x82,
  0xFD,0x0E,0xF3,0x1C,0xEF,0x30,0xFF,0x27,0xDF,0x64,0xFC,0x44,0xBE,0xC2,0xFF,0x81,
  0xE2,0x42,0xF1,0x21,0xF9,0x11,0xBE,0xCC,0xEF,0x72,0xFD,0x1F,0x3F,0x03,0x0F,0x08,
  0x06,0x02,0x5C,0x54,0xFD,0xFC,0x03,0x01,0x6F,0x46,0xED,0x87,0x47,0x82,0xC6,0xC4,
  0x7F,0x3B,0xFF,0x5B,0xDF,0xBB,0xBF,0x77,0x7F,0xDF,0xFB,0x8F,0xCB,0x0F,0x9B,0x9F,
  0xCC,0x44,0x8E,0x8E,0x0D,0x0D,0x0C,0x04,0x0C,0x04,0x04,0x04,0x06,0x02,0x1E,0x0E,
  0x9B,0x9F,0x2B,0x3F,0xFB,0xCF,0x1B,0x2F,0x1B,0xBF,0x3B,0x1F,0x37,0x1F,0x17,0x37,
  0xD4,0xD8,0x9A,0xFC,0x26,0xFF,0xE1,0xFF,0x20,0xFF,0x2A,0xF5,0x51,0xEA,0x60,0xD5,
  0x00,0x00,0x00,0x01,0x80,0x02,0x40,0x83,0xA0,0xC7,0x68,0xF1,0x14,0xF8,0x8C,0x7E,
  0x00,0xE0,0x00,0x18,0x00,0x08,0x01,0x18,0x02,0xF1,0x05,0xE3,0x0A,0x07,0x1C,0x0F,
  0x77,0x37,0xA7,0x7F,0x4B,0xFF,0xF3,0xFF,0x83,0xFF,0x3B,0xC7,0x7D,0x83,0xAD,0x03,
  // Immunity
  0xFF,0x3F,0x7F,0x0F,0x7B,0x07,0xBE,0x81,0xAF,0x80,0x87,0x80,0xDF,0xDE,0xDF,0xC9,
  0xCF,0xC1,0xE6,0xE1,0xE6,0xE1,0xCE,0xC1,0x0F,0xF0,0xFF,0x00,0xFD,0x02,0xFD,0x82,
  0xFC,0xFC,0xF9,0xF8,0x73,0xF0,0x07,0xC0,0x1F,0xE1,0xFF,0x02,0xFE,0x04,0xFC,0x08,
  0x5F,0x00,0xFC,0x03,0xEC,0x1F,0xF0,0x7F,0xF1,0x9F,0x91,0x1F,0x13,0x1F,0x13,0x1F,
  0xF9,0xE8,0xE8,0xE8,0xE8,0xE8,0xDC,0xC4,0xD4,0xC4,0xA3,0x83,0x67,0x00,0xFF,0x00,
  0xFC,0x67,0x75,0x1F,0x74,0x5F,0x5E,0x4F,0x0C,0x07,0x88,0x8F,0xF3,0x7C,0xFF,0x01,
  0xF8,0x10,0x7C,0x94,0xF4,0xE4,0x63,0xC3,0x7C,0xDF,0x61,0xE0,0xCF,0x0F,0xF0,0xF0,
  0x11,0x1F,0x10,0x1F,0x78,0x7F,0x84,0xFF,0x62,0x9F,0xF8,0x07,0xFC,0x03,0xDC,0xE3,
  0xFF,0x00,0x8F,0x70,0x73,0xFC,0xF9,0xFE,0xFD,0xFE,0xFF,0xFC,0xFF,0xFC,0xFF,0xF8,
  0xFE,0x06,0xF8,0x18,0xE0,0x20,0xC3,0x43,0xCF,0x8F,0xDF,0x9F,0xDF,0x9F,0xFF,0xDF,
  0x00,0x00,0x00,0x00,0x7D,0x7C,0xFF,0xFD,0xFF,0xFF,0xFF,0xE0,0xF9,0xC6,0xA6,0xDF,
  0x68,0x37,0xE0,0x3F,0xF1,0xFF,0x3E,0xCF,0xDC,0xE7,0xEF,0x77,0xEE,0x33,0xF6,0x3B,
  0xFE,0xF9,0xFF,0xF1,0xEE,0xF2,0xE2,0xFE,0xC4,0xFC,0xC8,0xF8,0xC8,0xF8,0xD0,0xF0,
  0xFC,0xFF,0x79,0x7F,0x73,0x7F,0x7E,0x7E,0x58,0x78,0x61,0xE3,0x06,0xCF,0x18,0x1F,
  0x99,0xFF,0x61,0xE3,0x86,0x8F,0x1A,0x3F,0x63,0xFF,0xA0,0xFF,0x43,0xFF,0x8F,0xFF,
  0x76,0x9B,0x76,0x9B,0x2E,0xF3,0x6F,0xF1,0x97,0xF8,0x0B,0xFC,0xC7,0xFF,0xE0,0xFF,
  0xFF,0x3F,0x7F,0x0F,0x7B,0x07,0xBE,0x81,0xAF,0x80,0x87,0x80,0xDF,0xDC,0xDF,0xCB,
  0xCF,0xC1,0xE6,0xE1,0xE6,0xE1,0xCE,0xC1,0x0F,0xF0,0xFF,0x00,0xFD,0x02,0xFD,0x02,
  0xFC,0xFC,0xF9,0xF8,0x73,0xF0,0x07,0xC0,0x1F,0xE0,0xFF,0x01,0xFF,0x02,0xFE,0x04,
  0x5F,0x00,0xFC,0x03,0xE2,0x1F,0xFC,0x3F,0xF1,0xDF,0xD1,0x1F,0x13,0x1F,0x13,0x1F,
  0xFB,0xE8,0xE8,0xE8,0xE8,0xE8,0xDC,0xC4,0xD4,0xC4,0xA3,0x83,0x67,0x00,0xFF,0x00,
  0xFC,0xC7,0xF5,0x2F,0x74,0x5F,0x5E,0x4F,0x0C,0x07,0x08,0x0F,0xF3,0xFC,0xFF,0x00,
  0xFC,0x08,0x7C,0x94,0xF4,0xE4,0x60,0xC0,0x4F,0xCF,0x71,0xF0,0xCF,0x00,0xFF,0x0F,
  0x11,0x1F,0x10,0x1F,0x10,0x1F,0xF8,0xFF,0x06,0xFF,0xC0,0x3F,0xF8,0x07,0x7C,0x83,
  0xFF,0x01,0xFE,0x06,0xF8,0x18,0xE0,0x20,0xC0,0x40,0x81,0x81,0xB7,0xB2,0xFE,0xCE,
  0xF0,0xF0,0x00,0x00,0x00,0x00,0x67,0x07,0xFF,0xDF,0xFF,0x60,0xF9,0x46,0xA6,0xDF,
  0xC8,0xF7,0x20,0x3F,0xF1,0xFF,0x3E,0xCF,0xDC,0xE7,0xEF,0x77,0xEE,0x33,0xF6,0x3B,
  0xC1,0xC0,0x73,0x71,0x4F,0x7F,0x46,0x7E,0x58,0x78,0x61,0xE3,0x06,0xCF,0x18,0x1F,
  // Cell
  0x00,0x00,0x03,0x03,0x04,0x04,0x04,0x04,0x09,0x08,0x0B,0x08,0x0B,0x08,0x17,0x10,
  0xF8,0xF8,0x07,0x07,0x1B,0x00,0x0F,0x00,0x9F,0x00,0xF7,0x00,0xFF,0x00,0xFF,0xE0,
  0x00,0x00,0xC0,0xC0,0xFE,0x3E,0xFD,0x03,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x38,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x60,0xE0,0xD0,0x30,0xE8,0x18,0xF4,0x0C,
  0x17,0x11,0x27,0x22,0x2E,0x22,0x2E,0x24,0x4C,0x44,0x5C,0x44,0x5C,0x44,0x9C,0x84,
  0xFF,0x18,0x1F,0x08,0x0F,0x08,0x0F,0x0D,0x8F,0x85,0x87,0x85,0x07,0x05,0x05,0x07,
  0xFF,0xC4,0xC7,0x82,0x83,0x82,0x83,0x81,0xA1,0x21,0x21,0x21,0x01,0x01,0x01,0x01,
  0xEC,0x14,0xF6,0x0A,0xFA,0x06,0xF6,0x0A,0xFB,0x05,0xF5,0x0B,0xFB,0x05,0xFD,0x03,
  0x96,0x8E,0xBF,0x81,0xBF,0x80,0xBF,0x80,0xBF,0x80,0x9F,0x81,0x5F,0x41,0x5F,0x41,
  0x08,0x0F,0xFF,0xF0,0xFF,0x00,0xFF,0x00,0xFF,0xC0,0xBF,0x30,0x8F,0x0F,0x80,0x00,
  0x83,0x83,0xFC,0x7F,0xFF,0x00,0xFF,0x0C,0xF7,0x32,0xC7,0xC2,0x07,0x02,0x0D,0x06,
  0xFB,0x05,0x7D,0x83,0x7A,0x85,0xB4,0x4B,0xFA,0x05,0xF4,0x0B,0xEB,0x15,0xD5,0x2B,
  0x5F,0x40,0x3F,0x20,0x7F,0x7E,0x43,0x46,0x42,0x5F,0x42,0x5F,0x27,0x2F,0x18,0x18,
  0xE0,0xC0,0x3F,0xFF,0xC0,0x3F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xBA,0xC5,0x75,0x7A,
  0x1B,0x1C,0xE7,0xF8,0x1F,0xE0,0xFD,0x02,0xFA,0x05,0xD4,0x2B,0xA0,0x5F,0x47,0xBF,
  0xA9,0x57,0x55,0xAB,0xA9,0x57,0x42,0xBE,0x82,0x7E,0x0C,0xFC,0xF0,0xF0,0x00,0x00,
  0x00,0x00,0x20,0x00,0x00,0x00,0x03,0x03,0x04,0x04,0x04,0x04,0x49,0x08,0xEB,0x08,
  0x00,0x00,0x02,0x00,0xF8,0xF8,0x07,0x07,0x1B,0x00,0x0F,0x00,0x9F,0x00,0xF7,0x00,
  0x01,0x00,0x01,0x00,0x00,0x00,0xC0,0xC0,0xFE,0x3E,0xFD,0x03,0xFF,0x00,0xFF,0x00,
  0x87,0x00,0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x60,0xE0,0xD0,0x30,
  0x4B,0x08,0x17,0x10,0x17,0x11,0x27,0x22,0x2E,0x22,0x2E,0x24,0x4C,0x44,0x5C,0x44,
  0xFF,0x00,0xFF,0xE0,0xFF,0x18,0x1F,0x08,0x0F,0x08,0x0F,0x0D,0x87,0x85,0x87,0x85,
  0xFF,0x00,0xFF,0x38,0xFF,0xC4,0xC7,0x82,0x83,0x82,0x83,0x81,0x21,0x21,0x21,0x21,
  0xE9,0x18,0xF4,0x0C,0xEC,0x14,0xF6,0x0A,0xFA,0x06,0xF6,0x0A,0xFB,0x05,0xF5,0x0B,
  0x5C,0x44,0x97,0x8F,0x97,0x88,0xBF,0x80,0xBF,0x81,0x9F,0x81,0x3F,0x01,0x3F,0x01,
  0x07,0x05,0x85,0x87,0x78,0xFF,0xFF,0x00,0xFF,0x80,0xFF,0x60,0x9F,0x1F,0xC0,0xC0,
  0x01,0x01,0x0F,0x0F,0xF7,0xF8,0xFF,0x00,0xFF,0x0F,0xF3,0x71,0x83,0x81,0x0F,0x0E,
  0xFB,0x05,0x7D,0x83,0xBB,0x45,0xBD,0x43,0xFA,0x05,0xF4,0x0B,0xFA,0x05,0xF4,0x0B,
  0x1E,0x01,0x9F,0x80,0xFF,0xFE,0xC3,0xC6,0xC2,0xDF,0x42,0x5F,0x64,0x6F,0x3F,0x3F,
  0xFF,0xFF,0xFF,0xFF,0xFC,0x7F,0xB0,0x7F,0xEF,0x1F,0xF0,0x0F,0x3A,0xC5,0x05,0xFA,
  0xFF,0xFE,0xFD,0xFE,0x0F,0xFC,0x75,0xFA,0x8A,0xF5,0x54,0xAB,0xA0,0x5F,0x40,0xBF,
  0xEA,0x15,0xD4,0x2B,0xA8,0x57,0x40,0xBF,0x81,0x7F,0x01,0xFF,0x06,0xFE,0x38,0xF8,
  // Neuron
  0xFE,0xF0,0x0F,0xFC,0xC3,0xFF,0xF0,0x3F,0x7E,0x0F,0x1F,0x01,0xFF,0x0F,0xF0,0x7F,
  0xCF,0x7C,0xE3,0x3E,0xF1,0x9F,0x78,0xFF,0x0C,0xFF,0x80,0xFF,0x06,0xFF,0x3E,0xFF,
  0x73,0x1E,0xE7,0x3C,0xCF,0x78,0x9F,0xFF,0x80,0xFF,0x03,0xFF,0x38,0xFF,0x3E,0xFF,
  0x0F,0x00,0xFF,0x07,0xF8,0xFF,0x07,0xFF,0x3F,0xF8,0xFC,0xC0,0xFC,0xC0,0x3F,0xF8,
  0xBF,0xFF,0xFF,0xC3,0xEF,0x07,0x0F,0x00,0x01,0x00,0x07,0x00,0x3F,0x07,0x7F,0x3C,
  0xFE,0xFF,0xFC,0xE7,0xFC,0x07,0xFF,0xFF,0xED,0x81,0xD9,0x81,0xB3,0x81,0xE7,0x81,
  0x3F,0xFF,0x1F,0xF3,0x1F,0xF0,0x1F,0xFF,0x1C,0xF0,0xF9,0xF0,0xB3,0xF0,0x16,0xF0,
  0xC7,0xFF,0xFF,0xFC,0xFE,0x70,0xF8,0xC0,0xE0,0x40,0xE0,0x40,0x60,0x40,0xE0,0x40,
  0x7D,0x20,0x70,0x20,0x20,0x00,0x00,0x00,0x01,0x00,0x03,0x11,0x06,0x23,0x0C,0x67,
  0xFF,0xFF,0xFC,0x07,0x1C,0x07,0xFF,0x1F,0xE0,0xFF,0x0F,0xFF,0x7F,0xF2,0xFA,0xA2,
  0x1F,0xFF,0x1F,0xF0,0x1E,0xF0,0x1F,0xFE,0x01,0xFF,0xFC,0xFF,0xFF,0x23,0x27,0x22,
  0xE0,0xC0,0xC0,0x00,0x00,0x00,0x80,0x00,0xC0,0x80,0x60,0xC0,0xB0,0xE4,0xF0,0x62,
  0x0D,0x67,0x4D,0xA7,0x4C,0xA7,0x06,0x43,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE3,0x23,0xAE,0x2F,0xF0,0xFF,0x03,0xFF,0xFA,0xFF,0xFD,0x0F,0x1A,0x0F,0x1D,0x0F,
  0xFE,0xFE,0x01,0xFF,0xFC,0xFF,0xFF,0xE3,0xB3,0xE0,0x70,0xE0,0xB0,0xE0,0x70,0xE0,
  0xF0,0x63,0xF2,0xE5,0x32,0xE5,0xE0,0xC2,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x9E,0xF8,0x87,0xFE,0xE1,0x7F,0xF8,0x1F,0x3E,0x07,0x1F,0x01,0xFF,0x0F,0xF0,0x7F,
  0x67,0x3C,0xE3,0x3E,0xF1,0x9F,0x78,0xFF,0x0C,0xFF,0x80,0xFF,0x06,0xFF,0x1E,0xFF,
  0xE6,0x3C,0xC7,0x7C,0xCF,0x79,0x9E,0xFF,0x80,0xFF,0x03,0xFF,0x30,0xFF,0x3C,0xFF,
  0x3F,0x03,0xFC,0x1F,0xE1,0xFF,0x0F,0xFE,0x7F,0xF0,0xF8,0xC0,0xFC,0xC0,0x3F,0xF8,
  0x9D,0xFF,0x7F,0xE3,0xFF,0x87,0xCF,0x00,0x01,0x00,0x07,0x00,0x3F,0x07,0x7F,0x3C,
  0xFE,0xFF,0xFC,0xF7,0xFC,0x87,0xFF,0xFF,0xED,0x81,0xD9,0x81,0xB3,0x81,0xE7,0x81,
  0x3F,0xFF,0x1F,0xF7,0x1F,0xF0,0x1F,0xFF,0x1C,0xF0,0xF9,0xF0,0xB3,0xF0,0x16,0xF0,
  0x87,0xFE,0xF9,0xFF,0xFF,0xF7,0xFF,0xC0,0xE0,0x40,0xE0,0x40,0x60,0x40,0xE0,0x40,
  0x7D,0x20,0x70,0x20,0x20,0x06,0x00,0x08,0x01,0x00,0x03,0x01,0x06,0x03,0x0C,0x07,
  0xFF,0xFF,0xFC,0x07,0x1C,0x07,0xFF,0x1F,0xE0,0xFF,0x0F,0xFF,0x7F,0xF2,0xF2,0xA2,
  0xE0,0xC0,0xC0,0x08,0x00,0x06,0x80,0x02,0xC0,0x80,0x60,0xC0,0xB0,0xE0,0xF0,0x60,
  0x0D,0x07,0x0D,0x07,0x0D,0x07,0x0D,0x07,0x0C,0x07,0x06,0x03,0x03,0x01,0x01,0x00,
  0xE2,0x22,0xA2,0x22,0xA3,0x23,0xAE,0x2F,0xF0,0xFF,0x03,0xFF,0xFA,0xFF,0xFD,0x0F,
  0x26,0x22,0x26,0x22,0xFE,0xFE,0x01,0xFF,0xFC,0xFF,0xFF,0xE3,0xB3,0xE0,0x70,0xE0,
  0xD8,0x70,0xD8,0x70,0xD8,0x70,0xD8,0xF0,0x30,0xE0,0xE0,0xC0,0xC0,0x00,0x00,0x00,
  // background tiles
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xFD,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0xFF,0xBF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,
  0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,
  0xFD,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xBF,0xFF,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xF8,0xFB,0xF8,0xFB,0xF9,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x1F,0xDF,0x1F,0xDF,0x9F,
  0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,0xFB,0xF9,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,0xDF,0x9F,
  0xFB,0xF9,0xFB,0xF8,0xF8,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xDF,0x9F,0xDF,0x1F,0x1F,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0xFF,0x41,0x80,0x63,0xC1,0x36,0xE3,0x1C,0xF7,0x08,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x41,0x80,0x63,0xC1,0x36,0xE3,0x1C,0xF7,0x08,0xFF,
  0xFF,0xFF,0xFD,0xFF,0x39,0xFF,0x38,0xFF,0x30,0xFF,0x30,0xFF,0x10,0xFF,0x10,0xFF,
  0xFF,0xFF,0xE8,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0xFF,0xFF,0x20,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0xFF,0xFF,0x06,0xFF,0x02,0xFF,0x00,0xFF,0x00,0xFF,0x02,0xFF,0x00,0xFF,0x00,0xFF,
  0x10,0xFF,0x10,0xFF,0x00,0xFF,0x00,0xFF,0x10,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF
};

#endif
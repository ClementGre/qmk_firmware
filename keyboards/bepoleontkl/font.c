#include "progmem.h"

static const unsigned char font[] PROGMEM = {
    0xFE, 0xFF, 0x03, 0x03, 0x03, 0x03, 0xFF, 0xFE,
    0x03, 0x7F, 0x7F, 0x7E, 0x7E, 0x7F, 0x7F, 0x03,
    0x00, 0x1E, 0x3E, 0x7C, 0x7C, 0x3E, 0x1E, 0x00,
    0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x00, 0x1C, 0x57,
    0x7D, 0x57, 0x1C, 0x00, 0x1C, 0x5E, 0x7F, 0x5E,
    0x1C, 0x00, 0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
    0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00, 0x00, 0x18,
    0x24, 0x18, 0x00, 0x00, 0xFF, 0xE7, 0xDB, 0xE7,
    0xFF, 0x00, 0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
    0x26, 0x29, 0x79, 0x29, 0x26, 0x00, 0x40, 0x7F,
    0x05, 0x05, 0x07, 0x00, 0x40, 0x7F, 0x05, 0x25,
    0x3F, 0x00, 0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 0x00,
    0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00, 0x08, 0x1C,
    0x1C, 0x3E, 0x7F, 0x00, 0x14, 0x22, 0x7F, 0x22,
    0x14, 0x00, 0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
    0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00, 0x00, 0x66,
    0x89, 0x95, 0x6A, 0x00, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x00, 0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
    0x08, 0x04, 0x7E, 0x04, 0x08, 0x00, 0x10, 0x20,
    0x7E, 0x20, 0x10, 0x00, 0x08, 0x08, 0x2A, 0x1C,
    0x08, 0x00, 0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
    0x1E, 0x10, 0x10, 0x10, 0x10, 0x00, 0x0C, 0x1E,
    0x0C, 0x1E, 0x0C, 0x00, 0x30, 0x38, 0x3E, 0x38,
    0x30, 0x00, 0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5F, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07,
    0x00, 0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00,
    0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, 0x23, 0x13,
    0x08, 0x64, 0x62, 0x00, 0x36, 0x49, 0x56, 0x20,
    0x50, 0x00, 0x00, 0x08, 0x07, 0x03, 0x00, 0x00,
    0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, 0x00, 0x41,
    0x22, 0x1C, 0x00, 0x00, 0x2A, 0x1C, 0x7F, 0x1C,
    0xA9, 0x03, 0x23, 0x23, 0xFB, 0x23, 0x23, 0x01,
    0x00, 0x00, 0xC2, 0xC2, 0x02, 0x02, 0x20, 0x20,
    0x22, 0x22, 0x20, 0x00, 0x00, 0x00, 0x82, 0x82,
    0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00,
    0xF8, 0x44, 0x24, 0x14, 0xF8, 0x00, 0x00, 0x08,
    0xFC, 0x00, 0x00, 0x00, 0xC8, 0x24, 0x24, 0x24,
    0x18, 0x00, 0x84, 0x04, 0x24, 0x34, 0xCC, 0x00,
    0x60, 0x50, 0x48, 0xFC, 0x40, 0x00, 0x9C, 0x14,
    0x14, 0x14, 0xE4, 0x00, 0xF0, 0x28, 0x24, 0x24,
    0xC4, 0x00, 0x04, 0x84, 0x44, 0x24, 0x1C, 0x00,
    0xD8, 0x24, 0x24, 0x24, 0xD8, 0x00, 0x18, 0x24,
    0x24, 0xA4, 0x78, 0x00, 0x00, 0x00, 0x50, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x50, 0x88, 0x04, 0x00, 0x50, 0x50,
    0x50, 0x50, 0x50, 0x00, 0x00, 0x04, 0x88, 0x50,
    0x20, 0x00, 0x08, 0x04, 0x64, 0x24, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x80,
    0x40, 0x80, 0x00, 0x00, 0xC0, 0x40, 0x40, 0x40,
    0x80, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00,
    0xC0, 0x40, 0x40, 0x40, 0x80, 0x00, 0xC0, 0x40,
    0x40, 0x40, 0x40, 0x00, 0xC0, 0x40, 0x40, 0x40,
    0x40, 0x00, 0x80, 0x40, 0x40, 0x40, 0xC0, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x40,
    0xC0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0,
    0x40, 0x00, 0xC0, 0x00, 0x00, 0x80, 0x40, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x80,
    0x00, 0x80, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0x00,
    0xC0, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00,
    0xC0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40,
    0x40, 0x40, 0x80, 0x00, 0xC0, 0x40, 0x40, 0x40,
    0x80, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00,
    0xC0, 0x40, 0xC0, 0x40, 0xC0, 0x00, 0xC0, 0x00,
    0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x00, 0x00, 0xC0, 0x00, 0x40, 0x40, 0x40, 0x40,
    0xC0, 0x00, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x40, 0x40, 0xC0, 0x00, 0x00, 0x80, 0x40, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x0F, 0x10, 0x17, 0x16, 0x13, 0x00, 0x1F, 0x04,
    0x04, 0x04, 0x1F, 0x00, 0x1F, 0x12, 0x12, 0x12,
    0x0D, 0x00, 0x0F, 0x10, 0x10, 0x10, 0x08, 0x00,
    0x1F, 0x10, 0x10, 0x10, 0x0F, 0x00, 0x1F, 0x12,
    0x12, 0x12, 0x10, 0x00, 0x1F, 0x02, 0x02, 0x02,
    0x00, 0x00, 0x0F, 0x10, 0x10, 0x14, 0x1C, 0x00,
    0x1F, 0x02, 0x02, 0x02, 0x1F, 0x00, 0x00, 0x10,
    0x1F, 0x10, 0x00, 0x00, 0x08, 0x10, 0x10, 0x0F,
    0x00, 0x00, 0x1F, 0x02, 0x05, 0x08, 0x10, 0x00,
    0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 0x1F, 0x00,
    0x07, 0x00, 0x1F, 0x00, 0x1F, 0x01, 0x02, 0x04,
    0x1F, 0x00, 0x0F, 0x10, 0x10, 0x10, 0x0F, 0x00,
    0x1F, 0x02, 0x02, 0x02, 0x01, 0x00, 0x0F, 0x10,
    0x14, 0x08, 0x17, 0x00, 0x1F, 0x02, 0x06, 0x0A,
    0x11, 0x00, 0x09, 0x12, 0x12, 0x12, 0x0C, 0x00,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x0F, 0x10,
    0x10, 0x10, 0x0F, 0x00, 0x07, 0x08, 0x10, 0x08,
    0x07, 0x00, 0x0F, 0x10, 0x0E, 0x10, 0x0F, 0x00,
    0x18, 0x05, 0x02, 0x05, 0x18, 0x00, 0x00, 0x01,
    0x1E, 0x01, 0x00, 0x00, 0x18, 0x16, 0x12, 0x13,
    0x10, 0x00, 0x00, 0x1F, 0x10, 0x10, 0x10, 0x00,
    0x00, 0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x10,
    0x10, 0x10, 0x1F, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x08, 0x15,
    0x15, 0x1E, 0x10, 0x00, 0x1F, 0x0A, 0x11, 0x11,
    0x0E, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0A, 0x00,
    0x0E, 0x11, 0x11, 0x0A, 0x1F, 0x00, 0x0E, 0x15,
    0x15, 0x15, 0x06, 0x00, 0x00, 0x02, 0x1F, 0x02,
    0x00, 0x00, 0x06, 0x09, 0x09, 0x07, 0x1E, 0x00,
    0x1F, 0x02, 0x01, 0x01, 0x1E, 0x00, 0x00, 0x11,
    0x1F, 0x10, 0x00, 0x00, 0x08, 0x10, 0x10, 0x0F,
    0x00, 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00,
    0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, 0x7C, 0x04,
    0x78, 0x04, 0x78, 0x00, 0x7C, 0x08, 0x04, 0x04,
    0x78, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7C, 0x18, 0x24, 0x24, 0x18, 0x00, 0x18, 0x24,
    0x24, 0x18, 0x7C, 0x00, 0x7C, 0x08, 0x04, 0x04,
    0x08, 0x00, 0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
    0x04, 0x04, 0x3F, 0x44, 0x24, 0x00, 0x3C, 0x40,
    0x40, 0x20, 0x7C, 0x00, 0x1C, 0x20, 0x40, 0x20,
    0x1C, 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x4C, 0x90,
    0x90, 0x90, 0x7C, 0x00, 0x44, 0x64, 0x54, 0x4C,
    0x44, 0x00, 0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
    0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x00, 0x41,
    0x36, 0x08, 0x00, 0x00, 0x02, 0x01, 0x02, 0x04,
    0x02, 0x00, 0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x00,
    0x00, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0xF0, 0xF0, 0xE0, 0x00, 0x10, 0x00, 0x00, 0x80,
    0xC0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x30, 0x70,
    0xD0, 0x10, 0xE0, 0x10, 0x10, 0x10, 0x60, 0x50,
    0x10, 0x40, 0x80, 0x00, 0xC0, 0x70, 0x10, 0x10,
    0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x60, 0x40, 0x80, 0x70, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x80, 0x80,
    0xC0, 0x40, 0x40, 0x20, 0x20, 0x20, 0x00, 0x10,
    0x10, 0x80, 0x00, 0x00, 0x00, 0x10, 0x00, 0xC0,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x30, 0x00,
    0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xE0, 0x00, 0xE0,
    0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE0, 0xB0, 0xF0, 0xB0, 0xE0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0x70, 0xE0, 0xE0,
    0xE0, 0x70, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x00, 0x00, 0xF0,
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0xF0, 0xF0,
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0x70, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0,
    0xF0, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xC0,
    0xC0, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x40, 0x00,
    0x00, 0x00, 0x08, 0x06, 0x03, 0xC0, 0xCF, 0xC0,
    0x47, 0x0F, 0x0F, 0x0F, 0x0F, 0x4F, 0xCF, 0xCF,
    0xCF, 0x0F, 0x07, 0xC0, 0xC0, 0xC8, 0x4F, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xC0,
    0xCF, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0E, 0x0E,
    0x0E, 0x00, 0x01, 0x0F, 0x07, 0x04, 0xC6, 0xC6,
    0xC6, 0xC6, 0xC6, 0xC6, 0xC2, 0xC2, 0xC0, 0x80,
    0x00, 0x00, 0xCF, 0xCE, 0xCE, 0xCC, 0x0C, 0xCE,
    0xCE, 0xCE, 0xCE, 0xC0, 0xC0, 0x01, 0x0F, 0xCC,
    0xCC, 0x0E, 0x06, 0x02, 0x0A, 0x02, 0x0C, 0xC8,
    0xC0, 0x0F, 0xC4, 0x04, 0xCC, 0xC8, 0xCA, 0xCD,
    0xC2, 0xCE, 0xCE, 0x0E, 0xCE, 0x0E, 0x0C, 0x08,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F,
    0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x07,
    0x02, 0x00, 0x07, 0x07, 0x07, 0x07, 0x00, 0x07,
    0x87, 0xC7, 0x07, 0x47, 0xC7, 0x80, 0xC0, 0x08,
    0xCC, 0x0E, 0x47, 0x45, 0x44, 0x45, 0xCF, 0x8C,
    0x80, 0x00, 0x0C, 0x00, 0x0D, 0xCD, 0x0D, 0x0D,
    0x0D, 0x0D, 0x0D, 0x00, 0x0C, 0x00, 0x00, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xC0, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x8F, 0xCF, 0x0F, 0x0F, 0x0E, 0x00, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xC8, 0x8F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x8F, 0xCF, 0x0F, 0x01,
    0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x4F,
    0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x3F,
    0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F,
    0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x27, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x27, 0x37, 0x37,
    0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07,
    0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07,
    0x03, 0x00, 0x07, 0x07, 0x07, 0x0F, 0x00, 0x0F,
    0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x00, 0x0C, 0x1E,
    0x1F, 0x1E, 0x0C, 0x08, 0x08, 0x0C, 0x1E, 0x1F,
    0x0E, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x03, 0x03,
    0x03, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0C, 0x07,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F,
    0x0F, 0x38, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x1D, 0x07, 0x00, 0x00, 0x20, 0x01, 0x02, 0x04,
    0x04, 0x0C, 0x08, 0x08, 0x08, 0x08, 0x00, 0x20,
    0x3F, 0x20, 0x3F, 0x10, 0x10, 0x10, 0x10, 0x08,
    0x08, 0x08, 0x08, 0x0E, 0x3A, 0x24, 0x24, 0x24,
    0x24, 0x26, 0x02, 0x02, 0x02, 0x22, 0x22, 0x20,
    0x30, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x01, 0x03,
    0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x20,
    0x20, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

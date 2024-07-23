#pragma once

#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9

#define I2C2_SCL_PIN B10
#define I2C2_SDA_PIN B11

#define I2C_DRIVER I2CD1

#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 5

#define OLED_FONT_H "font.c"

//#define OLED_SCROLL_TIMEOUT 5000
#define OLED_TIMEOUT 0

//#define OLED_SCROLL_SPEED 100
#define OLED_DISPLAY_HEIGHT 32
#define OLED_DISPLAY_WIDTH 128
#define OLED_BRIGHTNESS 128

//#define DEBUG_MATRIX_SCAN_RATE

#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 0

#define LEADER_TIMEOUT 200
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define WPM_SAMPLE_SECONDS 10
#define WPM_SAMPLE_PERIODS 50
#define WPM_LAUNCH_CONTROL

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)
#define MAGIC_KEY_DEBUG I // BP_D
#define MAGIC_KEY_DEBUG_MATRIX C // BP_X
#define MAGIC_KEY_DEBUG_KBD B // BP_K
#define MAGIC_KEY_DEBUG_MOUSE QUOT // BP_M
#define MAGIC_KEY_CONSOLE H // BP_C
#define MAGIC_KEY_VERSION U // BP_V
#define MAGIC_KEY_STATUS K // BP_S
#define MAGIC_KEY_HELP DOT // BP_H
#define MAGIC_KEY_HELP_ALT EQL // BP_PERC
#define MAGIC_KEY_LAYER0 0
#define MAGIC_KEY_LAYER0_ALT GRV // BP_DL
#define MAGIC_KEY_LAYER1 1
#define MAGIC_KEY_LAYER2 2
#define MAGIC_KEY_LAYER3 3
#define MAGIC_KEY_LAYER4 4
#define MAGIC_KEY_LAYER5 5
#define MAGIC_KEY_LAYER6 6
#define MAGIC_KEY_LAYER7 7
#define MAGIC_KEY_LAYER8 8
#define MAGIC_KEY_LAYER9 9
#define MAGIC_KEY_BOOTLOADER Q // BP_B
#define MAGIC_KEY_BOOTLOADER_ALT ESC
#define MAGIC_KEY_LOCK CAPS
#define MAGIC_KEY_EEPROM F // BP_E
#define MAGIC_KEY_EEPROM_CLEAR BSPC
#define MAGIC_KEY_NKRO SCLN // BP_N
#define MAGIC_KEY_SLEEP_LED LBRC // BP_Z

// VIA Config

#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
#define EEPROM_VERSION 0x08
#define EEPROM_VERSION_ADDR 34

#define DYNAMIC_KEYMAP_EEPROM_ADDR 35

#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR 392    // 35 + (3*17*7**2)
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 632    // 1024 - 392
#define DYNAMIC_KEYMAP_MACRO_COUNT 16

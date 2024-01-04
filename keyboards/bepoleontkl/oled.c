#include "oled.h"
#include "quantum.h"
#include "i2c_master.h"
#include <time.h>
#include <stdlib.h>

static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
void i2c_init(void) {
    static bool is_initialised = false;
    if (!is_initialised) {
        is_initialised = true;

        // Try releasing special pins for a short time
        palSetLineMode(I2C1_SCL_PIN, PAL_MODE_INPUT);
        palSetLineMode(I2C1_SDA_PIN, PAL_MODE_INPUT);
        palSetLineMode(I2C2_SCL_PIN, PAL_MODE_INPUT);
        palSetLineMode(I2C2_SDA_PIN, PAL_MODE_INPUT);

        chThdSleepMilliseconds(10);

        palSetLineMode(I2C1_SCL_PIN, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
        palSetLineMode(I2C1_SDA_PIN, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
        palSetLineMode(I2C2_SCL_PIN, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
        palSetLineMode(I2C2_SDA_PIN, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
    }
}

void oled_idling() {
    oled_scroll_off(true);
    oled_scroll_off(false);
    oled_clear(true);
    oled_clear(false);
    oled_off(true);
    oled_off(false);
}

bool    is_last_spotify  = false;
uint8_t last_call_count  = 0;
bool    invert_positions = true;

/* ********************* *
 * LS <================>            (Music bar over 18 chars)
 * MUSIC (scroll)
 * SONG (scroll)
 *                                  (Pull everything down half of the time for burn in)
 * ********************* */
void render_spotify(uint8_t *data) {
    // [1] : filled blocked count (from 0 to 17)
    // [2] : Liked status (0x00 = not liked, 0x01 = liked)
    // [3] : Shuffle status (0x00 = not shuffling, 0x01 = shuffling)
    // [4:25] : song if [0] = 0x01, singer if [0] = 0x02
    static uint8_t last_song[22];
    static uint8_t last_singer[22];
    static uint8_t last_progress = 255;
    static bool    last_liked    = false;
    static bool    last_shuffle  = false;
    if (!is_last_spotify) {
        last_call_count  = 0;
        invert_positions = true; // Will be inverted at the first call
        is_last_spotify  = true;
        oled_scroll_off(true);
        oled_scroll_set_speed(true, 2);
        oled_clear(true);
        memset(last_song, 0, sizeof(last_song));
        memset(last_singer, 0, sizeof(last_singer));
    }

    // Song name/Singer
    uint8_t content_text[22]; // 25 - 4 + 1 = 22 elements in the subarray
    for (int i = 4; i <= 25; i++) {
        content_text[i - 4] = data[i];
    }
    content_text[21] = '\0';

    bool update_text = false;
    if (data[0] == 0x01) { // Song name
        if (memcmp(last_song, content_text, sizeof(content_text)) != 0) {
            memcpy(last_song, content_text, sizeof(content_text));
            // Since calls are doubled, only clear and invert when song name changes
            oled_clear(true);
            invert_positions = !invert_positions;
            update_text      = true;
        }
    } else { // Singer
        if (memcmp(last_singer, content_text, sizeof(content_text)) != 0) {
            memcpy(last_singer, content_text, sizeof(content_text));
            update_text = true;
        }
    }
    if (update_text) {
        oled_scroll_off(true);
        oled_scroll_set_area(true, invert_positions ? 0 : 2, invert_positions ? 1 : 3);

        if (data[0] == 0x01) { // Song name
            oled_set_cursor(true, 0, invert_positions ? 0 : 2);
        } else { // Singer
            oled_set_cursor(true, 0, invert_positions ? 1 : 3);
        }
        oled_write(true, (const char *)content_text, false);
    }

    oled_set_cursor(true, 0, invert_positions ? 3 : 0);

    if (update_text || last_progress != data[1] || last_liked != (data[2] == 0x01) || last_shuffle != (data[3] == 0x01)){
        oled_scroll_off(true);

        last_progress = data[1];
        last_liked    = data[2] == 0x01;
        last_shuffle  = data[3] == 0x01;

        // Song liked status
        if (data[2] == 0x01) {
            oled_write(true, (const char[]){0x08, 0x09, 0x00}, false);
        } else {
            oled_write(true, (const char[]){0x06, 0x07, 0x00}, false);
        }
        // Song shuffle status
        if (data[3] == 0x01) {
            oled_write(true, (const char[]){0x0C, 0x00}, false);
        } else {
            oled_write(true, (const char[]){0x0B, 0x00}, false);
        }
        // Playing bar
        for (int i = 0; i < 18; i++) {
            if (i <= data[1]) {
                if (i == 0)
                    oled_write(true, (const char[]){0x01, 0x00}, false);
                else if (i == 17)
                    oled_write(true, (const char[]){0x03, 0x00}, false);
                else
                    oled_write(true, (const char[]){0x05, 0x00}, false);
            } else {
                if (i == 0)
                    oled_write(true, (const char[]){0x00, 0x00}, false);
                else if (i == 17)
                    oled_write(true, (const char[]){0x02, 0x00}, false);
                else
                    oled_write(true, (const char[]){0x04, 0x00}, false);
            }
        }
    }
}

/* ********************* *
 * CPU: 89.5%    67.6 °C            (Invert these lines and alignment for burn in)
 * MEM: 40%      12.3 GB
 *    /-----\__
 *---/         \__------            (3x loads over 21*10 = 3.5 last minutes)
 * ********************* */
void render_perfs(uint8_t *data) {
    // [1] : CPU % usage
    // [2] : CPU usage decimal (0 to 9)
    // [3] : CPU temperature (0 to 255)
    // [4] : CPU temperature decimal (0 to 9)
    // [5] : RAM % usage
    // [6] : RAM % usage decimal
    // [7] : RAM usage in GB (0 to 32 or more)
    // [8] : RAM usage decimal (0 to 9)
    if (is_last_spotify) {
        last_call_count  = 0;
        invert_positions = false;
        is_last_spotify  = false;
        oled_scroll_off(true);
        oled_scroll_set_speed(true, 2);
        oled_clear(true);
    } else if (last_call_count == 126) {
        oled_pan(true, true);
    }

    // CPU :

    oled_set_cursor(true, 0, 0);

    char cpu_str1[10];
    sprintf(cpu_str1, "CPU: %d.", data[1]);
    oled_write(true, cpu_str1, false);
    char cpu_str2[6];
    sprintf(cpu_str2, "%d %%", data[2]);
    oled_write(true, cpu_str2, false);

    oled_set_cursor(true, 13, 0);
    if (data[3] < 10) {
        oled_write(true, "  ", false);
    } else if (data[3] < 100) {
        oled_write(true, " ", false);
    }
    char cpu_str3[5];
    sprintf(cpu_str3, "%d.", data[3]);
    oled_write(true, cpu_str3, false);
    char cpu_str4[6];
    sprintf(cpu_str4, "%d \x1f", data[4]);
    oled_write(true, cpu_str4, false);
    oled_write(true, "C", false);

    // RAM
    oled_set_cursor(true, 0, 1);

    char ram_str1[10];
    sprintf(ram_str1, "RAM: %d.", data[5]);
    oled_write(true, ram_str1, false);
    char ram_str2[6];
    sprintf(ram_str2, "%d %%", data[6]);
    oled_write(true, ram_str2, false);

    oled_set_cursor(true, 14, 1);
    if (data[7] < 10) {
        oled_write(true, "  ", false);
    }
    char ram_str3[5];
    sprintf(ram_str3, "%d.", data[7]);
    oled_write(true, ram_str3, false);
    char ram_str4[7];
    sprintf(ram_str4, "%d GB", data[8]);
    oled_write(true, ram_str4, false);

    // Graph
    oled_write_pixel(true, last_call_count, 32 - (data[1] * 10 + data[2]) * 16 / 1000, true);
    if (last_call_count < 126) {
        last_call_count += 1;
    }
}

/* ********************* *
 * 00:00:00     00:00:00            (Time and Time since boot)
 *
 * XX XX XX                         (Alternate wpm lines)
 * XX XX XX      106 wpm            (CAPS, INSERT, SCROLL)
 * ********************* */
void render_screen_1(void) {
    static bool init      = false;
    static bool caps_lock = false;
    if (!init) {
        init = true;
        return;
    }
    // oled_scroll_off(false);

    uint8_t wpm = get_current_wpm();
    char    buf[9];
    snprintf(buf, 9, "WPM: %d", wpm);
    oled_write(false, buf, false);

    oled_advance_page(false, true);

    oled_scroll_set_area(false, 0, 2);
    oled_scroll_left(false);
    //        char str[5];
    //        sprintf(str, "%ld", counter);
    //        write_1(PSTR(str), false);

    led_t led_state = host_keyboard_led_state();
    oled_write(false, led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write(false, led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write(false, led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    if (caps_lock != led_state.caps_lock) {
        caps_lock = led_state.caps_lock;
        oled_set_brightness(false, led_state.caps_lock ? 255 : 128);
        oled_set_brightness(true, led_state.caps_lock ? 255 : 128);
    }
}
void render_screen_2(void) {
    static bool init = false;
    if (init) {
        int r = rand() / (RAND_MAX / 100);
        printf("r: %d\n", r);
        int r2 = rand();
        printf("r2: %d\n", r2);
        if (r == 1) oled_pan(true, true);

        oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
        return;
    }

    oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
    oled_advance_page(true, true);
    oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
    init = true;
}

bool oled_task_kb(bool screen) {
    static bool is_initial_render = true;
    if (!screen)
        render_screen_1();
    else {
        if (is_last_spotify) oled_scroll_left(true);

        if (is_initial_render) {
            oled_write(true, qmk_logo, false);
            oled_write(true, "Start B\x0EpoleonDesktop", false);
            is_initial_render = false;
        }
    }
    return true;
}

void oled_render_boot(bool bootloader) {
    printf("oled_render_boot\n");
    oled_scroll_off(true);
    oled_scroll_off(false);
    oled_clear(true);
    oled_clear(false);

    oled_write(true, qmk_logo, false);
    oled_write(false, qmk_logo, false);

    if (bootloader) {
        oled_write(true, PSTR("Awaiting new software"), false);
        oled_write(false, "   stm32 bootloader", false);
    } else {
        oled_write(true, "      Rebooting", false);
        oled_write(false, "      Rebooting", false);
    }
    oled_render_dirty(false, true);
    oled_render_dirty(true, true);
}
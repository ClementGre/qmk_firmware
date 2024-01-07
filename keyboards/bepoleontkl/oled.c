#include "oled.h"
#include "quantum.h"
#include "keycode_to_string.h"
#include "i2c_master.h"
#include <time.h>
#include <stdlib.h>

static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};
static uint32_t           timer;
static bool               screen1_disabled = false;
static bool               screen2_disabled = false;

#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
void i2c_init(void) {
    static bool is_initialised = false;
    if (!is_initialised) {
        timer          = timer_read32();
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

enum screen2s { NONE, SPOTIFY, PERFS };
enum screen2s last_screen2s = NONE;

/* ********************* *
 * LS <================>            (Music bar over 18 chars)
 * MUSIC (scroll)
 * SONG (scroll)
 *                                  (Pull everything down half of the time for burn in)
 * ********************* */
void render_spotify(uint8_t *data) {
    if (screen2_disabled) return;
    // [1] : filled blocked count (from 0 to 17)
    // [2] : Liked status (0x00 = not liked, 0x01 = liked)
    // [3] : Shuffle status (0x00 = not shuffling, 0x01 = shuffling)
    // [4:25] : song if [0] = 0x01, singer if [0] = 0x02
    static bool    invert_positions = true;
    static uint8_t last_song[22];
    static uint8_t last_singer[22];
    static uint8_t last_progress = 255;
    static bool    last_liked    = false;
    static bool    last_shuffle  = false;
    if (last_screen2s != SPOTIFY) {
        last_screen2s    = SPOTIFY;
        invert_positions = true; // Will be inverted at the first call
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

    if (update_text || last_progress != data[1] || last_liked != (data[2] == 0x01) || last_shuffle != (data[3] == 0x01)) {
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
static uint8_t cpu_graph_min = 255;
static uint8_t cpu_graph_max = 0;
uint8_t        value_on_min_max(uint8_t val) {
    return (uint8_t)(((uint16_t)(val - cpu_graph_min)) * 16 / (uint16_t)(cpu_graph_max - cpu_graph_min));
}
void render_perfs(uint8_t *data) {
    if (screen2_disabled) return;
    // [1] : CPU % usage
    // [2] : CPU usage decimal (0 to 9)
    // [3] : CPU temperature (0 to 255)
    // [4] : CPU temperature decimal (0 to 9)
    // [5] : RAM % usage
    // [6] : RAM % usage decimal
    // [7] : RAM usage in GB (0 to 32 or more)
    // [8] : RAM usage decimal (0 to 9)
    static uint8_t last_call_count = 0;
    static bool    invert_pos      = false;
    static uint8_t cpu_graph[63]; // values between 0 and 255
    static uint8_t cpu_graph_index = 0;

    if (last_screen2s != PERFS) {
        last_screen2s   = PERFS;
        last_call_count = 0;
        cpu_graph_index = 0;
        oled_scroll_off(true);
        oled_clear(true);
        invert_pos = false;
    }
    bool redraw_graph = false;
    if (last_call_count == 62) {
        last_call_count = 0;
        invert_pos      = !invert_pos;
        redraw_graph    = true;
    }
    if (cpu_graph_index == 62) {
        oled_pan(true, true);
        oled_pan(true, true);
        for (int i = 0; i <= cpu_graph_index; ++i) {
            cpu_graph[i] = cpu_graph[i + 1];
        }
    }

    // Graph
    cpu_graph[cpu_graph_index] = (uint8_t)(((uint16_t)(data[1] * 10) + (uint16_t)data[2]) * 255 / 1000);
    if (cpu_graph_min > cpu_graph[cpu_graph_index] || cpu_graph_max < cpu_graph[cpu_graph_index]) {
        cpu_graph_min = 255;
        cpu_graph_max = 0;
        for (int i = 0; i <= cpu_graph_index; ++i) {
            if (cpu_graph[i] < cpu_graph_min) cpu_graph_min = cpu_graph[i];
            if (cpu_graph[i] > cpu_graph_max) cpu_graph_max = cpu_graph[i];
        }
        redraw_graph = true;
    } else {
        uint8_t min = 255;
        uint8_t max = 0;
        for (int i = 0; i <= cpu_graph_index; ++i) {
            if (cpu_graph[i] < min) min = cpu_graph[i];
            if (cpu_graph[i] > max) max = cpu_graph[i];
        }
        if (cpu_graph_min != min || cpu_graph_max != max) {
            cpu_graph_min = min;
            cpu_graph_max = max;
            redraw_graph  = true;
        }
    }

    if (redraw_graph) {
        oled_clear(true);

        for (int i = 0; i <= cpu_graph_index; ++i) {
            uint8_t val = (invert_pos ? 15 : 31) - value_on_min_max(cpu_graph[i]);
            oled_write_pixel(true, i * 2 + 1, val, true);
            if (i > 0) {
                uint8_t val_old = (invert_pos ? 15 : 31) - value_on_min_max(cpu_graph[i - 1]);
                oled_write_pixel(true, i * 2, (uint8_t)((((uint16_t)val_old) + ((uint16_t)val)) / 2), true);
            } else {
                oled_write_pixel(true, i * 2, val, true);
            }
        }
    } else {
        uint8_t val = (invert_pos ? 15 : 31) - value_on_min_max(cpu_graph[cpu_graph_index]);
        oled_write_pixel(true, cpu_graph_index * 2 + 1, val, true);
        if (cpu_graph_index > 0) {
            uint8_t val_old = (invert_pos ? 15 : 31) - value_on_min_max(cpu_graph[cpu_graph_index - 1]);
            oled_write_pixel(true, cpu_graph_index * 2, (uint8_t)((((uint16_t)val_old) + ((uint16_t)val)) / 2), true);
        } else {
            oled_write_pixel(true, cpu_graph_index * 2, val, true);
        }
    }

    if (last_call_count < 62) {
        last_call_count += 1;
    }

    if (cpu_graph_index < 62) {
        cpu_graph_index += 1;
    }

    // CPU :
    oled_set_cursor(true, 0, invert_pos ? 2 : 0);

    char cpu_str1[10];
    sprintf(cpu_str1, "CPU: %d.", data[1]);
    oled_write(true, cpu_str1, false);
    char cpu_str2[8];
    sprintf(cpu_str2, "%d %%  ", data[2]);
    oled_write(true, cpu_str2, false);

    oled_set_cursor(true, 12, invert_pos ? 2 : 0);
    if (data[3] < 10) {
        oled_write(true, "  ", false);
    } else if (data[3] < 100) {
        oled_write(true, " ", false);
    }
    char cpu_str3[6];
    sprintf(cpu_str3, " %d.", data[3]);
    oled_write(true, cpu_str3, false);
    char cpu_str4[6];
    sprintf(cpu_str4, "%d \x1f", data[4]);
    oled_write(true, cpu_str4, false);
    oled_write(true, "C", false);

    // RAM
    oled_set_cursor(true, 0, invert_pos ? 3 : 1);

    char ram_str1[10];
    sprintf(ram_str1, "RAM: %d.", data[5]);
    oled_write(true, ram_str1, false);
    char ram_str2[8];
    sprintf(ram_str2, "%d %%  ", data[6]);
    oled_write(true, ram_str2, false);

    oled_set_cursor(true, 13, invert_pos ? 3 : 1);
    if (data[7] < 10) {
        oled_write(true, " ", false);
    }
    char ram_str3[6];
    sprintf(ram_str3, " %d.", data[7]);
    oled_write(true, ram_str3, false);
    char ram_str4[7];
    sprintf(ram_str4, "%d GB", data[8]);
    oled_write(true, ram_str4, false);

    oled_set_cursor(true, 11, invert_pos ? 2 : 0);
    char str1[6];
    sprintf(str1, "%d", cpu_graph_max);
    oled_write(true, str1, false);
    oled_set_cursor(true, 11, invert_pos ? 3 : 1);
    char str2[6];
    sprintf(str2, "%d", cpu_graph_min);
    oled_write(true, str2, false);
}

/* ********************* *
 * 00:00:00     00:00:00            (Time and Time since boot)
 *
 * XX XX XX                         (Alternate wpm lines)
 * XX XX XX      106 wpm            (CAPS, INSERT, SCROLL)
 * ********************* */
void print_4chars_icon(uint8_t root, uint8_t x, uint8_t y) {
    oled_set_cursor(false, x, y);
    oled_write(false, (const char[]){root, root + 1, 0x00}, false);
    oled_set_cursor(false, x, y + 1);
    oled_write(false, (const char[]){root + 32, root + 33, 0x00}, false);
}
void empty_4chars_icon(uint8_t x, uint8_t y) {
    oled_set_cursor(false, x, y);
    oled_write(false, "  ", false);
    oled_set_cursor(false, x, y + 1);
    oled_write(false, "  ", false);
}
void render_screen_1(void) {
    if (screen1_disabled) return;
    static bool init = false;
    if (!init) {
        init = true;
        oled_clear(false);
        return;
    }

    uint32_t elapsed = timer_elapsed(timer) / 1000;
    uint8_t  hours   = elapsed / 3600;
    elapsed -= hours * 3600;
    uint8_t minutes = elapsed / 60;
    elapsed -= minutes * 60;

    char    time[13];
    uint8_t pos = 0;
    pos += sprintf(&time[pos], "%02d", hours);
    pos += sprintf(&time[pos], ":%02d", minutes);
    sprintf(&time[pos], ":%02ld", elapsed);
    oled_write(false, time, false);

    oled_set_cursor(false, 0, 2);

    if (leader_sequence_active()) {
        oled_write(false, "Leader", false);
        oled_set_cursor(false, 0, 3);
        oled_write(false, ":", false);
        for (uint8_t i = 0; i < leader_sequence_size; i++) {
            char *str = keycode_to_string(leader_sequence[i]);
            oled_write(false, str, false);
        }
    } else {
        led_t led_state = host_keyboard_led_state();
        if (led_state.caps_lock)
            print_4chars_icon(0x97, 0, 2);
        else
            empty_4chars_icon(0, 2);
        if (led_state.scroll_lock)
            print_4chars_icon(0x99, 2, 2);
        else
            empty_4chars_icon(2, 2);
    }
    oled_set_cursor(false, 12, 3);
    uint8_t wpm = get_current_wpm();
    char    wpm_str[9];
    snprintf(wpm_str, 9, "WPM: %d", wpm);
    oled_write(false, wpm_str, false);
}

static bool s2_initial_render = true;
bool        oled_task_kb(bool screen) {
    if (!screen) {
        render_screen_1();
    } else {
        if (screen2_disabled) return true;
        if (last_screen2s == SPOTIFY) oled_scroll_left(true);

        if (s2_initial_render) {
            oled_write(true, qmk_logo, false);
            oled_write(true, "Start B\x0EpoleonDesktop", false);
            s2_initial_render = false;
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

static uint8_t brightness = 0;

void brightness_up(void) {
    brightness = oled_get_brightness(true);
    if (brightness > 240)
        brightness = 255;
    else
        brightness += 10;
    oled_set_brightness(true, brightness);
    oled_set_brightness(false, brightness);
}
void brightness_down(void) {
    brightness = oled_get_brightness(true);
    if (brightness < 10)
        brightness = 0;
    else
        brightness -= 10;
    oled_set_brightness(true, brightness);
    oled_set_brightness(false, brightness);
}

void swap_disable_screen(bool screen) {
    if ((screen && !screen2_disabled) || (!screen && !screen1_disabled)) {
        oled_scroll_off(screen);
        oled_clear(screen);
        oled_off(screen);
        if (screen) {
            screen2_disabled = true;
            last_screen2s    = NONE;
        } else
            screen1_disabled = true;
    } else {
        oled_on(screen);
        if (screen) {
            screen2_disabled  = false;
            s2_initial_render = true;
        } else
            screen1_disabled = false;
    }
}
void oled_idling() {
    // no need to change oledx_disabled because oled task won't be called again until sleep is over
    oled_scroll_off(true);
    oled_scroll_off(false);
    oled_clear(true);
    oled_clear(false);
    oled_off(true);
    oled_off(false);
    last_screen2s = NONE;
}
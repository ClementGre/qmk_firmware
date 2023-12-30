#include "oled.h"
#include "quantum.h"
#include "i2c_master.h"
#include <time.h>
#include <stdlib.h>

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

/* ********************* *
 * 00:00:00     00:00:00            (Time and Time since boot)
 *
 * XX XX XX                         (Alternate wpm lines)
 * XX XX XX      106 wpm            (CAPS, INSERT, SCROLL)
 * ********************* */
/* ********************* *
 * M <=================>            (Music bar over 19 chars : 114 - 2 = 112 pixels and from 6 to 18 different chars to use)
 * ARTIST (scroll)
 * MUSIC (scroll)
 *                                  (Pull everything down half of the time for burn in)
 * ********************* */
/* ********************* *
 * CPU: 100% | GPU: 100%            (Invert these lines and alignment for burn in)
 * MEM: 40% 12.3 GB
 *    /-----\__
 *---/         \__------            (3x loads over 21*10 = 3.5 last minutes)
 * ********************* */
void render_screen_1(void) {
    static bool init = false;
    static bool caps_lock = false;
    if(!init){
        init = true;
        return ;
    }
    oled_scroll_off(false);

    oled_write(false, "Wicked Games (Feat the) - Piera For Cuva", false);
    oled_advance_page(false, true);

//        oled_scroll_set_area(false, 0, 2);
//        char str[5];
//        sprintf(str, "%ld", counter);
//        write_1(PSTR(str), false);


    led_t led_state = host_keyboard_led_state();
    write_1(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    write_1(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    write_1(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    if(caps_lock != led_state.caps_lock){
        caps_lock = led_state.caps_lock;
        oled_set_brightness(false, led_state.caps_lock ? 255 : 128);
        oled_set_brightness(true, led_state.caps_lock ? 255 : 128);
    }
}
void render_screen_2(void){
    static bool init = false;
    if(init){
        int r = rand() / (RAND_MAX / 100);
        printf("r: %d\n", r);
        int r2 = rand();
        printf("r2: %d\n", r2);
        if(r == 1)
            oled_pan(true, true);

        oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
        return ;
    }


    oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
    oled_advance_page(true, true);
    oled_write(true, "Wicked Games (Feat the) - Piera For Cuva", false);
    init = true;

//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
//
//    write_2(qmk_logo, false);
}

bool oled_task_kb(bool screen) {
    if (screen) render_screen_1();
    else render_screen_2();
    return true;
}

void oled_render_boot(bool bootloader) {
    printf("oled_render_boot\n");
    oled_scroll_off(true);
    oled_scroll_off(false);
    oled_clear(true);
    oled_clear(false);
    if (bootloader) {
        write_1(PSTR("Awaiting new software..."), false);
    } else {
        write_1(PSTR("Rebooting..."), false);
    }
    oled_render_dirty(false, true);
    oled_render_dirty(true, true);
}
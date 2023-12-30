#include "oled.h"
#include "quantum.h"
#include "i2c_master.h"

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


bool render_screen_1(void) {
    static int32_t counter = 0;
    counter++;
    write_1(PSTR("test"), false);
    char str[5];
    sprintf(str, "%ld", counter);
    write_1(PSTR(str), false);

    led_t led_state = host_keyboard_led_state();
    write_1(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    write_1(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    write_1(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return true;
}
bool render_screen_2(void){

    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    write_2(qmk_logo, false);

    return false;
}

bool oled_task_kb(bool screen) {
    if (screen) {
        return render_screen_1();
    } else {
        return render_screen_2();
    }
}
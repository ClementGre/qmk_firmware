#include "quantum.h"
#include "bepoleontkl.h"
#include "i2c_master.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_ESC) {
        // eeconfig_init();
    }
    return true;
}


bool skip_encoder0 = false;
bool skip_encoder1 = true;
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        skip_encoder0 = !skip_encoder0;
        if (skip_encoder0) {
            return true;
        }
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        skip_encoder1 = !skip_encoder1;
        if (skip_encoder1) {
            return true;
        }
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

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
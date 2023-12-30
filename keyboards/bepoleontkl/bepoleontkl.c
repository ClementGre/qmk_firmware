#include "quantum.h"
#include "bepoleontkl.h"
#include "oled.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_ESC) {
        reset_keyboard();
    }

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

bool shutdown_kb(bool jump_to_bootloader) {
    if (!shutdown_user(jump_to_bootloader)) {
        return false;
    }
    oled_render_boot(jump_to_bootloader);
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
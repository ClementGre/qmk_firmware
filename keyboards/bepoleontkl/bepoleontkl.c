#include "quantum.h"
#include "bepoleontkl.h"
#include "oled.h"
#include "keycode_to_string.h"
#include "os_detection.h"
#include "keymap_bepo.h"

static uint32_t keystroke_count     = 0;
static uint32_t keystroke_all_count = 0;

bool insert_enabled = false;
bool is_insert_enabled(void) {
    return insert_enabled;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        keystroke_count++;
        keystroke_all_count++;
        if(keystroke_all_count % 10000 == 0) {
            save_keystroke_count();
        }
    }
    switch (keycode) {
        case KC_INSERT:
            if (record->event.pressed) {
                insert_enabled = !insert_enabled;
            }
            break;
        case M_SPS:
            if (record->event.pressed) {
                // TODO
            }
            break;
        case M_CPS:
            if (record->event.pressed) {
                // TODO
            }
            break;
        case KC_NUBS: // invert KC_NUBS and KC_GRV on MacOS
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code(KC_GRV);
                } else {
                    unregister_code(KC_GRV);
                }
                return false;
            }
            break;
        case KC_GRV: // invert KC_NUBS and KC_GRV on MacOS
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code(KC_NUBS);
                } else {
                    unregister_code(KC_NUBS);
                }
                return false;
            }
            break;
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

void suspend_power_down_kb(void) {
    oled_idling();
}

void encoder_up(void) {
    if (get_mods() & MOD_MASK_SHIFT) {
        brightness_up();
    } else if (get_mods() & MOD_MASK_CTRL) {
        tap_code(KC_BRIU);
    } else {
        tap_code(KC_VOLU);
    }
}
void encoder_down(void) {
    if (get_mods() & MOD_MASK_SHIFT) {
        brightness_down();
    } else if (get_mods() & MOD_MASK_CTRL) {
        tap_code(KC_BRID);
    } else {
        tap_code(KC_VOLD);
    }
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
            encoder_down();
        } else {
            encoder_up();
        }
    } else if (index == 1) { /* Second encoder */
        skip_encoder1 = !skip_encoder1;
        if (skip_encoder1) {
            return true;
        }
        if (clockwise) {
            encoder_down();
        } else {
            encoder_up();
        }
    }
    return true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // [0] : 0x00 = Screen1, 0x01 = Spotify with song title, 0x02 = Spotify with singer, 0x03 = Perfs
    if (data[0] == 0x01 || data[0] == 0x02) {
        render_spotify(data);
    } else if (data[0] == 0x03) {
        render_perfs(data);
    } else {
        render_screen_1();
    }
}

void leader_start_user(void) {}

void leader_end_user(void) {
    if (leader_sequence_two_keys(BP_B, BP_O)) {
        reset_keyboard();
    } else if (leader_sequence_one_key(KC_F8)) {
        swap_disable_screen(false);
    } else if (leader_sequence_one_key(KC_F5)) {
        swap_disable_screen(true);
    }else if (leader_sequence_two_keys(BP_S, BP_K)) {
        save_keystroke_count();
        keystroke_count = 0;
    }
}

void keyboard_post_init_kb(void) {
    keystroke_all_count = eeconfig_read_kb();
}
void save_keystroke_count(void) {
    eeconfig_update_kb(keystroke_all_count);
}

uint32_t get_keystroke_count(void) {
    return keystroke_count;
}
uint32_t get_keystroke_all_count(void) {
    return keystroke_all_count;
}
void reset_keystroke_count(void) {
    keystroke_count = 0;
}

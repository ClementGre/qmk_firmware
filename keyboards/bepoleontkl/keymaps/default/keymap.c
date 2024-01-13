#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "oled.h"
#include "bepoleontkl.h"

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT(
//                                    QK_BOOT, EE_CLR,  KC_GT,                                                         KC_MPRV, KC_MPLY, KC_MNXT,
//         KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
//         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    C, KC_EQL,      KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,
//         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_ENT,        KC_DEL,  KC_END,  KC_PGDN,
//         KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
//         KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                             KC_UP,
//         KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT
//         )
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(M_CPS, QK_LEAD, M_SPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, BP_DLR, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, BP_EQL, BP_PERC, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_TAB, BP_B, BP_EACU, BP_P, BP_O, BP_EGRV, BP_DCIR, BP_V, BP_D, BP_L, BP_J, BP_Z, BP_W, KC_ENT, KC_DEL, KC_END, KC_PGDN, KC_CAPS, BP_A, BP_U, BP_I, BP_E, BP_COMM, BP_C, BP_T, BP_S, BP_R, BP_N, BP_M, BP_CCED, KC_LSFT, BP_ECIR, BP_AGRV, BP_Y, BP_X, BP_DOT, BP_K, BP_QUOT, BP_Q, BP_G, BP_H, BP_F, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT)};

const uint16_t PROGMEM combo_bootl[]  = {KC_SPC, KC_ENT, BP_B, COMBO_END};
combo_t                key_combos[]   = {
    COMBO(combo_bootl, QK_BOOT),
};

void suspend_power_down_user(void) {
    oled_idling();
    reset_keystroke_count();
}
void suspend_wakeup_init_user(void) {
    oled_wakeup();
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case BP_B:
        case BP_EACU:
        case BP_P:
        case BP_O:
        case BP_EGRV:
        case BP_V:
        case BP_D:
        case BP_L:
        case BP_J:
        case BP_Z:
        case BP_W:
        case BP_A:
        case BP_U:
        case BP_I:
        case BP_E:
        case BP_C:
        case BP_T:
        case BP_S:
        case BP_R:
        case BP_N:
        case BP_M:
        case BP_CCED:
        case BP_ECIR:
        case BP_AGRV:
        case BP_Y:
        case BP_X:
        case BP_K:
        case BP_Q:
        case BP_G:
        case BP_H:
        case BP_F:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to key.
            return true;

        case BP_EQL:
        case BP_PERC:
        case KC_BSPC:
        case KC_DEL:
            return true;
        case KC_SPC:
            if (get_mods() == MOD_BIT(KC_RALT)) return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

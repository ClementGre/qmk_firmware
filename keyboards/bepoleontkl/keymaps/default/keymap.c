#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "oled.h"

//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    [0] = LAYOUT(
//                                   QK_BOOT, EE_CLR,  KC_GT,                                                         KC_MPRV, KC_MPLY, KC_MNXT,
//        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
//        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,      KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,
//        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_ENT,        KC_DEL,  KC_END,  KC_PGDN,
//        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
//        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                             KC_UP,
//        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT
//        )
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                                            QK_BOOT, QK_LEAD, EE_CLR,                                                KC_MPRV, KC_MPLY, KC_MNXT,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
        BP_DLR,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BP_EQL,  BP_PERC,     KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,    BP_W,        KC_ENT,        KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,    BP_CCED,
        KC_LSFT, BP_ECIR, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    KC_RSFT,                             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT
        )
};

const uint16_t PROGMEM combo_bootl[] = {KC_SPC, KC_ENT, BP_B, COMBO_END};
const uint16_t PROGMEM combo_eeinit[] = {KC_SPC, KC_ENT, BP_E, COMBO_END};
const uint16_t PROGMEM combo_lead[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_bootl, QK_BOOT),
    COMBO(combo_eeinit, EE_CLR),
    COMBO(combo_lead, QK_LEAD),
};

void suspend_power_down_user(void) {
    oled_idling();
}

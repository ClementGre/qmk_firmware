#include "keycode_to_string.h"
#include "quantum.h"
#include "keymap_bepo.h"

/*LAYOUT(
QK_BOOT, QK_LEAD, EE_CLR,                                                KC_MPRV, KC_MPLY, KC_MNXT,
KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
BP_DLR,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BP_EQL,  BP_PERC,     KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,
KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,    BP_W,        KC_ENT,        KC_DEL,  KC_END,  KC_PGDN,
KC_CAPS, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,    BP_CCED,
KC_LSFT, BP_ECIR, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    KC_RSFT,                             KC_UP,
KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT
)*/

char *keycode_to_string(uint16_t key) {
    switch (key) {
        case BP_B:
            return "b";
        case BP_EACU:
            return "\x0E";
        case BP_P:
            return "p";
        case BP_O:
            return "o";
        case BP_EGRV:
            return "e";
        case BP_DCIR:
            return "^";
        case BP_V:
            return "v";
        case BP_D:
            return "d";
        case BP_L:
            return "l";
        case BP_J:
            return "j";
        case BP_Z:
            return "z";
        case BP_W:
            return "w";
        case BP_A:
            return "a";
        case BP_U:
            return "u";
        case BP_I:
            return "i";
        case BP_E:
            return "e";
        case BP_COMM:
            return ",";
        case BP_C:
            return "c";
        case BP_T:
            return "t";
        case BP_S:
            return "s";
        case BP_R:
            return "r";
        case BP_N:
            return "n";
        case BP_M:
            return "m";
        case BP_CCED:
            return "c";
        case BP_ECIR:
            return "e";
        case BP_AGRV:
            return "a";
        case BP_Y:
            return "y";
        case BP_X:
            return "x";
        case BP_DOT:
            return ".";
        case BP_K:
            return "k";
        case BP_QUOT:
            return "'";
        case BP_Q:
            return "q";
        case BP_G:
            return "g";
        case BP_H:
            return "h";
        case BP_F:
            return "f";
        case KC_1:
            return "1";
        case KC_2:
            return "2";
        case KC_3:
            return "3";
        case KC_4:
            return "4";
        case KC_5:
            return "5";
        case KC_6:
            return "6";
        case KC_7:
            return "7";
        case KC_8:
            return "8";
        case KC_9:
            return "9";
        case KC_0:
            return "0";
        case BP_DLR:
            return "$";
        case BP_EQL:
            return "=";
        case BP_PERC:
            return "%";
        case KC_F1:
            return "F1";
        case KC_F2:
            return "F2";
        case KC_F3:
            return "F3";
        case KC_F4:
            return "F4";
        case KC_F5:
            return "F5";
        case KC_F6:
            return "F6";
        case KC_F7:
            return "F7";
        case KC_F8:
            return "F8";
        case KC_F9:
            return "F9";
        case KC_F10:
            return "F10";
        case KC_F11:
            return "F11";
        case KC_F12:
            return "F12";
    }
    return "!";
}
// Copyright 2023 Clément Grennerat (@ClementGre)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

bool is_insert_enabled(void);

enum custom_keycodes {
    M_SPS = QK_KB_0,
    M_CPS
};

uint32_t get_keystroke_count(void);
uint32_t get_keystroke_all_count(void);
void reset_keystroke_count(void);
void save_keystroke_count(void);

void send_spotify_control_command(uint8_t);
void request_screens_update(void);

void toggle_nkro(void);

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

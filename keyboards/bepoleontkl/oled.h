#pragma once

void oled_render_boot(bool bootloader);

void render_spotify(uint8_t *data);
void render_perfs(uint8_t *data);
void render_screen_1(void);

void oled_idling(void);

void brightness_up(void);
void brightness_down(void);

void swap_disable_screen(bool screen);
#pragma once

#define write_1(data, invert) oled_write_P(false, data, invert)
#define write_2(data, invert) oled_write_P(true, data, invert)
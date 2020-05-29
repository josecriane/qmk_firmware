/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2017 Erin Call <hello@erincall.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1308
#define DEVICE_VER      0x0001
#define MANUFACTURER    Josecriane
#define PRODUCT         67Manuform

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 6
#define MATRIX_COLS 14
#define COL_EXPANDED { true, true, true, true, true, true, true, false, false, false, false, false, false, false}
#define MATRIX_ONBOARD_ROW_PINS { F0, F1, F4, F5, F6, F7 }
#define MATRIX_ONBOARD_COL_PINS { 0, 0, 0, 0, 0, 0, 0, B0, B1, B2, B3, D2, D3, C6 }
#define EXPANDER_COL_REGISTER GPIOA
#define EXPANDER_ROW_REGISTER GPIOB
#define MATRIX_EXPANDER_COL_PINS {0, 1, 2, 3, 4, 5, 6}
#define MATRIX_EXPANDER_ROW_PINS {0, 1, 2, 3, 4, 5}

#define MOUSEKEY_INTERVAL     20
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_TIME_TO_MAX  60
#define MOUSEKEY_MAX_SPEED    7
#define MOUSEKEY_WHEEL_DELAY  0

#define DEBOUNCE 15

#define TAPPING_TOGGLE  1

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 300000
#endif

#define OLED_FONT_END 127

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    get_mods() == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) || \
    get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) \
)


#define USB_MAX_POWER_CONSUMPTION 500

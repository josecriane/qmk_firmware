#include QMK_KEYBOARD_H
#include "67manuform.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap: Dvorak
 *
 *        ,------------------------------------------------.                ,------------------------------------------------.
 *        |  LY  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 *        |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 *        | ESC  |   1  |   2  |   7  |   4  |   5  |  `   |                |   ~  |   6  |   7  |   8  |   9  |   0  |  =   |
 *        |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 *        | TAB  |   '  |   ,  |   .  |   p  |   y  |   \  |                |   /  |   f  |   g  |   c  |   r  |   l  |  -   |
 *        |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 *        |   [  |   a  |   o  |   e  |   u  |   i  |  NC  |                |  NC  |   d  |   h  |   t  |   n  |   s  |  ]   |
 *        |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 *        |   (  |   ;  |   q  |   j  |   k  |   x  |  {   |                |   }  |   b  |   m  |   w  |   v  |   z  |  )   |
 *        `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                             | CTRL | SHFT | BSPC |                              |SPACE | W_MOD| LGUI |
 *                             `--------------------'                              `--------------------'
 *                                                  ,-------------.  ,-------------.
 *                                                  | COPY |  CUT |  | WH_U | ALT |
 *                                                  |------+------|  |------+------.
 *                                                  |  DEL |PASTE |  | WH_D |ENTER |
 *                                                  `-------------'  `-------------'
 */
 [DVORAK] = LAYOUT_67manuform_pretty(
 MO(CH),   KC_NO, KC_LGUI,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                            KC_NO,   KC_NO,     KC_NO, KC_LEFT,TO(M_DVORAK),TO(DVORAK),  TO(GAME),
 KC_ESC,    KC_1,    KC_2,    KC_3,     KC_4,     KC_5,   KC_GRV,                         KC_TILDE,    KC_6,      KC_7,    KC_8,        KC_9,      KC_0,    KC_EQL,
 KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,     KC_P,     KC_Y,  KC_BSLS,                          KC_SLSH,    KC_F,      KC_G,    KC_C,        KC_R,      KC_L,   KC_MINS,
KC_LBRC,    KC_A,    KC_O,    KC_E,     KC_U,     KC_I,  KC_LCBR,                          KC_RCBR,    KC_D,      KC_H,    KC_T,        KC_N,      KC_S,   KC_RBRC,
KC_LPRN, KC_SCLN,    KC_Q,    KC_J,     KC_K,     KC_X,  KC_LGUI,                          MO(ARR),    KC_B,      KC_M,    KC_W,        KC_V,      KC_Z,   KC_RPRN,
                           KC_LCTL,  KC_LSFT,  KC_BSPC,                                              KC_SPC,   MO(MOD), MO(ARR),
                                                         MO(ARR), KC_NO,          KC_WH_U,  KC_LALT,
                                                           KC_DEL, KC_NO,          KC_WH_D,   KC_ENT
),

/* Keymap: Change layers
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |   á  |   ó  |   é  |   ú  |   í  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |   ñ  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  NC  |  NC  |  NC  |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  NC  |  LY  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
[MOD] = LAYOUT_67manuform_pretty(
 MO(CH),    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 DF(DVORAK),KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,  _A_TILD,  _O_TILD,  _E_TILD,   _U_TILD,   _I_TILD,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   _ENHE,   KC_NO,   KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                              DF(MOD),     KC_NO,     KC_NO,                                       KC_SPC,   KC_NO,    KC_NO,
                                                               KC_NO,    KC_NO,   KC_NO,  KC_ENT,
                                                               KC_NO,    KC_NO,   KC_NO,   KC_NO
),

/* Keymap: Arrow
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  NC  |  NC  |  NC  |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
 [ARR] = LAYOUT_67manuform_pretty(
     MO(CH),    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,   KC_F6,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 DF(DVORAK),    KC_F7,      KC_F8,      KC_F9,     KC_F10,    KC_F11,  KC_F12,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,    KC_NO, LCTL(KC_C), LCTL(KC_V), LCTL(KC_X),     KC_NO,   KC_NO,                          KC_NO,   KC_NO, KC_LEFT,   KC_DOWN,  KC_UP, KC_RGHT,   KC_NO,
      KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      DF(ARR),      KC_NO,    KC_DEL,                                           KC_SPC,   KC_NO,    KC_NO,
                                                                   LCTL(KC_C), LCTL(KC_X),    KC_NO,   KC_ENT,
                                                                        KC_NO, LCTL(KC_V),    KC_NO,   KC_NO
 ),

[M_DVORAK] = LAYOUT_67manuform_pretty(
MO(CH),   KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                            KC_NO,   KC_NO,     KC_NO, KC_LEFT,   TO(M_DVORAK),  TO(DVORAK),   TO(GAME),
KC_ESC,    KC_1,    KC_2,    KC_3,     KC_4,     KC_5,   KC_GRV,                         KC_TILDE,    KC_6,      KC_7,    KC_8,      KC_9,   KC_0,   KC_EQL,
KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,     KC_P,     KC_Y,  KC_BSLS,                          KC_SLSH,    KC_F,      KC_G,    KC_C,      KC_R,   KC_L,  KC_MINS,
KC_LBRC,    KC_A,    KC_O,    KC_E,     KC_U,     KC_I,  KC_LCBR,                          KC_RCBR,    KC_D,      KC_H,    KC_T,      KC_N,   KC_S,  KC_RBRC,
KC_LPRN, KC_SCLN,    KC_Q,    KC_J,     KC_K,     KC_X, KC_LCTL,                          MO(M_ARR),    KC_B,      KC_M,    KC_W,      KC_V,   KC_Z,  KC_RPRN,
                          KC_LGUI,  KC_LSFT,  KC_BSPC,                                              KC_SPC, MO(M_MOD), MO(M_ARR),
                                                        MO(M_ARR), KC_NO,          KC_WH_U,  KC_LALT,
                                                          KC_DEL, KC_NO,          KC_WH_D,   KC_ENT
),

[M_MOD] = LAYOUT_67manuform_pretty(
MO(CH),    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
DF(M_DVORAK),KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO,_A_TILD_M,_O_TILD_M,_E_TILD_M, _U_TILD_M, _I_TILD_M,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO, _ENHE_M,   KC_NO,   KC_NO,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           TO(M_MOD),     KC_NO,     KC_NO,                                       KC_SPC,   KC_NO,    KC_NO,
                                                              KC_NO,    KC_NO,   KC_NO,  KC_ENT,
                                                              KC_NO,    KC_NO,   KC_NO,   KC_NO
),

[M_ARR] = LAYOUT_67manuform_pretty(
    MO(CH),    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,   KC_F6,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
DF(M_DVORAK),    KC_F7,      KC_F8,      KC_F9,     KC_F10,    KC_F11,  KC_F12,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,    KC_NO, LGUI(KC_C), LGUI(KC_V), LGUI(KC_X),     KC_NO,   KC_NO,                          KC_NO,   KC_NO, KC_LEFT,   KC_DOWN,  KC_UP, KC_RGHT,   KC_NO,
     KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                     KC_LCTL,      KC_NO,    KC_DEL,                                           KC_SPC,   KC_NO,    KC_NO,
                                                                  LGUI(KC_C), LGUI(KC_X),    KC_NO,   KC_ENT,
                                                                       KC_NO, LGUI(KC_V),    KC_NO,   KC_NO
),

/* Keymap: Gaming
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  NC  |  NC  |  NC  |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
[GAME] = LAYOUT_67manuform_pretty(
 MO(CH),    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,TO(M_DVORAK),TO(DVORAK),  TO(GAME),
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TAB,   KC_NO,    KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_NO,    KC_NO,    KC_A,    KC_S,    KC_D,     KC_F,     KC_G,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_NO,  KC_LSFT,    KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
                            KC_LALT, KC_LCTL,   KC_SPC,                                              KC_TRNS,   KC_TRNS,    KC_TRNS,
                                                          KC_NO,   KC_NO,     KC_TRNS,  KC_TRNS,
                                                          KC_ENT,  KC_NO,     KC_TRNS,  KC_TRNS
),

/* Keymap: Change layers
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |DVORAK| GAME |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  NC  |  NC  |  NC  |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
[CH] = LAYOUT_67manuform_pretty(
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,                      TO(DVORAK),   TO(GAME),   KC_TRNS,    KC_TRNS, TO(M_DVORAK),   KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,                         KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,                         KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,                         KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,                         KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,
                                      KC_TRNS,     KC_TRNS,     KC_TRNS,                                                 KC_TRNS,   KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,   KC_TRNS,               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,   KC_TRNS,               KC_TRNS,  KC_TRNS
),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _A_TILD ... _ENHE:
      windows_tildes(keycode, record);
      return false;
    case _A_TILD_M ... _ENHE_M:
      mac_tildes(keycode, record);
      return false;
  }
	return true;
}

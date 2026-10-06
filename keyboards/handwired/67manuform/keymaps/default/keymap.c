// Copyright 2020 josecriane
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    DVORAK,
    MOD,
    ARR,
    GAME,
    DOTA,
    M_DVORAK,
    M_MOD,
    M_ARR,
};

enum custom_keycodes {
    _A_TILD = SAFE_RANGE,
    _O_TILD,
    _E_TILD,
    _U_TILD,
    _I_TILD,
    _ENHE,
    _A_TILD_M,
    _O_TILD_M,
    _E_TILD_M,
    _U_TILD_M,
    _I_TILD_M,
    _ENHE_M,
};

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
 *        |   [  |   a  |   o  |   e  |   u  |   i  |  {   |                |   }  |   d  |   h  |   t  |   n  |   s  |  ]   |
 *        |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 *        |   (  |   ;  |   q  |   j  |   k  |   x  | LGUI |                | L_AR |   b  |   m  |   w  |   v  |   z  |  )   |
 *        `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                             | CTRL | SHFT | BSPC |                              |SPACE | W_MOD| L_AR |
 *                             `--------------------'                              `--------------------'
 *                                                  ,-------------.  ,-------------.
 *                                                  | L_AR |  NC  |  | WH_U | ALT |
 *                                                  |------+------|  |------+------.
 *                                                  |  DEL |  NC  |  | WH_D |ENTER |
 *                                                  `-------------'  `-------------'
 */
 [DVORAK] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                         TO(DOTA),   KC_NO,     KC_NO,   KC_NO,TO(M_DVORAK),TO(DVORAK),  TO(GAME),
 KC_ESC,    KC_1,    KC_2,    KC_3,     KC_4,     KC_5,   KC_GRV,                         KC_TILDE,    KC_6,      KC_7,    KC_8,        KC_9,      KC_0,    KC_EQL,
 KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,     KC_P,     KC_Y,  KC_BSLS,                          KC_SLSH,    KC_F,      KC_G,    KC_C,        KC_R,      KC_L,   KC_MINS,
KC_LBRC,    KC_A,    KC_O,    KC_E,     KC_U,     KC_I,  KC_LCBR,                          KC_RCBR,    KC_D,      KC_H,    KC_T,        KC_N,      KC_S,   KC_RBRC,
KC_LPRN, KC_SCLN,    KC_Q,    KC_J,     KC_K,     KC_X,  KC_LGUI,                          MO(ARR),    KC_B,      KC_M,    KC_W,        KC_V,      KC_Z,   KC_RPRN,
                           KC_LCTL,  KC_LSFT,  KC_BSPC,                                              KC_SPC,   MO(MOD), MO(ARR),
                                                         MO(ARR), KC_NO,          MS_WHLU,  KC_LALT,
                                                          KC_DEL, KC_NO,          MS_WHLD,   KC_ENT
),

/* Keymap: Mod layers
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
[MOD] = LAYOUT(
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,  _A_TILD,  _O_TILD,  _E_TILD,   _U_TILD,   _I_TILD,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   _ENHE,   KC_NO,   KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                KC_NO,     KC_NO,     KC_NO,                                       KC_SPC,   KC_NO,    KC_NO,
                                                               KC_NO,    KC_NO,   KC_NO,  KC_ENT,
                                                               KC_NO,    KC_NO,   KC_NO,   KC_NO
),

/* Keymap: Arrow
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  NC  |  F1  |  F2  |  F3  |  F4  |  F5  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  | COPY | PASTE|  CUT |  NC  |  NC  |                |  NC  |  NC  | LEFT | DOWN |  UP  | RGHT |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |  NC  | UNDO |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  NC  |  NC  |  NC  |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
 [ARR] = LAYOUT(
      KC_NO,    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_F6,    KC_F7,      KC_F8,      KC_F9,     KC_F10,    KC_F11,  KC_F12,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,    KC_NO, LCTL(KC_C), LCTL(KC_V), LCTL(KC_X),     KC_NO,   KC_NO,                          KC_NO,   KC_NO, KC_LEFT,   KC_DOWN,  KC_UP, KC_RGHT,   KC_NO,
      KC_NO,    KC_NO,      KC_NO, LCTL(KC_Z),      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_NO,      KC_NO,     KC_NO,                                            KC_NO,   KC_NO,    KC_NO,
                                                                        KC_NO,  KC_NO,    KC_NO,   KC_NO,
                                                                        KC_NO,  KC_NO,    KC_NO,   KC_NO
 ),

[M_DVORAK] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                            KC_NO,   KC_NO,     KC_NO,  KC_LEFT,TO(M_DVORAK),TO(DVORAK), TO(GAME),
 KC_ESC,    KC_1,    KC_2,    KC_3,     KC_4,     KC_5,   KC_GRV,                         KC_TILDE,    KC_6,      KC_7,     KC_8,        KC_9,      KC_0,   KC_EQL,
 KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,     KC_P,     KC_Y,  KC_BSLS,                          KC_SLSH,    KC_F,      KC_G,     KC_C,        KC_R,      KC_L,  KC_MINS,
KC_LBRC,    KC_A,    KC_O,    KC_E,     KC_U,     KC_I,  KC_LCBR,                          KC_RCBR,    KC_D,      KC_H,     KC_T,        KC_N,      KC_S,  KC_RBRC,
KC_LPRN, KC_SCLN,    KC_Q,    KC_J,     KC_K,     KC_X, KC_LCTL,                         MO(M_ARR),    KC_B,      KC_M,     KC_W,        KC_V,      KC_Z,  KC_RPRN,
                           KC_LGUI,  KC_LSFT,  KC_BSPC,                                              KC_SPC, MO(M_MOD),MO(M_ARR),
                                                        MO(M_ARR), KC_NO,          MS_WHLU,  KC_LALT,
                                                           KC_DEL, KC_NO,          MS_WHLD,   KC_ENT
),

[M_MOD] = LAYOUT(
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO,_A_TILD_M,_O_TILD_M,_E_TILD_M, _U_TILD_M, _I_TILD_M,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO, _ENHE_M,   KC_NO,   KC_NO,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           TO(M_MOD),     KC_NO,     KC_NO,                                       KC_SPC,   KC_NO,    KC_NO,
                                                              KC_NO,    KC_NO,   KC_NO,  KC_ENT,
                                                              KC_NO,    KC_NO,   KC_NO,   KC_NO
),

[M_ARR] = LAYOUT(
     KC_NO,    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_F6,    KC_F7,      KC_F8,      KC_F9,     KC_F10,    KC_F11,  KC_F12,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,    KC_NO, LGUI(KC_C), LGUI(KC_V), LGUI(KC_X),     KC_NO,   KC_NO,                          KC_NO,   KC_NO, KC_LEFT,   KC_DOWN,  KC_UP, KC_RGHT,   KC_NO,
     KC_NO,    KC_NO,      KC_NO, LGUI(KC_Z),      KC_NO,     KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                       KC_NO,      KC_NO,     KC_NO,                                            KC_NO,   KC_NO,    KC_NO,
                                                                       KC_NO,  KC_NO,    KC_NO,   KC_NO,
                                                                       KC_NO,  KC_NO,    KC_NO,   KC_NO
),

/* Keymap: Gaming
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  F1  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  ESC |   1  |   2  |   3  |   4  |   5  |   6  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  TAB |  NC  |   Q  |   W  |   E  |   R  |   T  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |  NC  |   A  |   S  |   D  |   F  |   G  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |   M  |  SFT |   Z  |   X  |   C  |   V  |   B  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  ALT | CTRL | SPCE |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  ENT |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
[GAME] = LAYOUT(
  KC_F1,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,TO(M_DVORAK),TO(DVORAK),  TO(GAME),
 KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
 KC_TAB,   KC_NO,    KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_NO,   KC_NO,    KC_A,    KC_S,    KC_D,     KC_F,     KC_G,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
   KC_M, KC_LSFT,    KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
                           KC_LALT, KC_LCTL,   KC_SPC,                                              KC_TRNS,   KC_TRNS,    KC_TRNS,
                                                          KC_NO,  KC_NO,      KC_TRNS,  KC_TRNS,
                                                         KC_ENT,  KC_NO,      KC_TRNS,  KC_TRNS
),
/* Keymap: Dota
 *
 * ,------------------------------------------------.                ,------------------------------------------------.
 * |  F1  |  NC  |  NC  |  NC  |  NC  |  NC  |SCREEN|                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  ESC |  NC  |  F2  |  F3  |  F4  |  F5  |  NC  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  TAB |  NC  |   1  |   2  |   3  |   P  |   T  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |  NC  |   Q  |   W  |   E  |   R  |   J  |   U  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * |------+------+------+------+------+------+------|                |------+------+------+------+------+------+------|
 * |   M  |   A  |   4  |   5  |   6  |   M  |   B  |                |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |  NC  |
 * `------+------+------+------+------+------+------'                `------+------+------+------+------+------+------'
 *                      |  ALT | CTRL |  SFT |                              |  NC  |  NC  |  NC  |
 *                      `--------------------'                              `--------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |  NC  |  NC  |  |  NC  |  NC  |
 *                                           |------+------|  |------+------.
 *                                           |  ENT |  NC  |  |  NC  |  NC  |
 *                                           `-------------'  `-------------'
 */
[DOTA] = LAYOUT(
  KC_F1,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,TO(M_DVORAK),TO(DVORAK),  TO(GAME),
 KC_ESC,   KC_NO,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_NO,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
 KC_TAB,   KC_NO,    KC_1,    KC_2,    KC_3,     KC_P,     KC_T,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_J,     KC_U,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
   KC_M,    KC_A,    KC_4,    KC_5,    KC_6,     KC_M,     KC_B,                        KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
                           KC_LALT, KC_LCTL,  KC_LSFT,                                              KC_TRNS,   KC_TRNS,    KC_TRNS,
                                                          KC_NO,  KC_NO,      KC_TRNS,  KC_TRNS,
                                                         KC_ENT,  KC_NO,      KC_TRNS,  KC_TRNS
),
};


static void windows_tildes(uint16_t keycode) {
    switch (keycode) {
        case _A_TILD: SEND_STRING(SS_ALGR("a")); break;
        case _O_TILD: SEND_STRING(SS_ALGR("o")); break;
        case _E_TILD: SEND_STRING(SS_ALGR("e")); break;
        case _U_TILD: SEND_STRING(SS_ALGR("u")); break;
        case _I_TILD: SEND_STRING(SS_ALGR("i")); break;
        case _ENHE: SEND_STRING(SS_ALGR("n")); break;
    }
}

static void mac_tildes(uint16_t keycode) {
    bool is_shift_pressed = get_mods() & MOD_BIT(KC_LSFT);

    if (is_shift_pressed) { unregister_code(KC_LSFT); }

    switch (keycode) {
        case _A_TILD_M ... _I_TILD_M: SEND_STRING(SS_LALT("e")); break;
        case _ENHE_M: SEND_STRING(SS_LALT("n")); break;
    }

    if (is_shift_pressed) { register_code(KC_LSFT); }

    switch (keycode) {
        case _A_TILD_M: SEND_STRING(SS_TAP(X_A)); break;
        case _O_TILD_M: SEND_STRING(SS_TAP(X_O)); break;
        case _E_TILD_M: SEND_STRING(SS_TAP(X_E)); break;
        case _U_TILD_M: SEND_STRING(SS_TAP(X_U)); break;
        case _I_TILD_M: SEND_STRING(SS_TAP(X_I)); break;
        case _ENHE_M: SEND_STRING(SS_TAP(X_N)); break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _A_TILD ... _ENHE:
            if (record->event.pressed) { windows_tildes(keycode); }
            return false;
        case _A_TILD_M ... _ENHE_M:
            if (record->event.pressed) { mac_tildes(keycode); }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_layer(void) {
    uint8_t layer = get_highest_layer(layer_state);

    oled_set_cursor(0, 1);
    oled_write_ln_P(PSTR("Layer:"), false);
    oled_write_P(PSTR("----------"), false);

    switch (layer) {
        case DVORAK:
        case M_DVORAK: oled_write_ln_P(PSTR(" DVORAK"), false); break;
        case MOD:
        case M_MOD: oled_write_ln_P(PSTR(" MODS"), false); break;
        case ARR:
        case M_ARR: oled_write_ln_P(PSTR(" ARROWS"), false); break;
        case GAME: oled_write_ln_P(PSTR(" GAMING"), false); break;
        case DOTA: oled_write_ln_P(PSTR(" DOTA"), false); break;
        default: oled_write_ln_P(PSTR(" ?"), false); break;
    }

    oled_write_ln_P(layer >= M_DVORAK ? PSTR(" MAC") : PSTR(""), false);
}

static void render_mod(char name, bool active) {
    oled_write_char(' ', false);
    oled_write_char(name, active);
}

static void render_mods(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(0, 6);
    oled_write_ln_P(PSTR("Mods:"), false);
    oled_write_P(PSTR("----------"), false);
    render_mod('C', mods & MOD_MASK_CTRL);
    render_mod('S', mods & MOD_MASK_SHIFT);
    render_mod('A', mods & MOD_MASK_ALT);
    render_mod('G', mods & MOD_MASK_GUI);
}

static void render_locks(void) {
    led_t leds = host_keyboard_led_state();

    oled_set_cursor(0, 10);
    oled_write_P(PSTR("CAPS"), leds.caps_lock);
    oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR("NUM"), leds.num_lock);
}

static void render_wpm(void) {
    oled_set_cursor(0, 11);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

bool oled_task_user(void) {
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }

    render_layer();
    render_mods();
    render_locks();
    render_wpm();
    return false;
}
#endif

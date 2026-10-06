// Copyright 2026 josecriane
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    DVORAK,
    MOD,
    ARR,
    GAME,
};

enum custom_keycodes {
    _A_TILD = SAFE_RANGE,
    _O_TILD,
    _E_TILD,
    _U_TILD,
    _I_TILD,
    _ENHE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DVORAK] = LAYOUT_ergodox_80(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_GRV,
    KC_TAB,     KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_BSLS,
    KC_LBRC,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,
    KC_LPRN,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_LCBR,
    KC_NO,      KC_NO,      KC_NO,      KC_LCTL,    KC_LSFT,
    KC_LGUI,    KC_NO,
    KC_NO,      KC_LALT,    MO(ARR),
    KC_BSPC,    KC_DEL,     KC_NO,

    KC_TILD,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    KC_SLSH,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_MINS,
    KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_RBRC,
    KC_RCBR,    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_RPRN,
    MO(MOD),    MO(ARR),    KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_LGUI,
    KC_PGUP,    KC_RALT,    KC_NO,
    KC_PGDN,    KC_ENT,     KC_SPC
),

[MOD] = LAYOUT_ergodox_80(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      _A_TILD,    _O_TILD,    _E_TILD,    _U_TILD,    _I_TILD,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,

    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      TO(DVORAK), TO(GAME),
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      _ENHE,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_NO,      KC_NO,
    KC_SPC,     KC_NO,      KC_NO,
    KC_NO,      KC_ENT,     KC_NO
),

[ARR] = LAYOUT_ergodox_80(
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      LCTL(KC_A), LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), KC_NO,
    KC_NO,      KC_NO,      KC_NO,      LCTL(KC_Z), KC_NO,      KC_NO,      KC_NO,
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,
    KC_NO,      KC_TRNS,
    KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,

    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO
),

[GAME] = LAYOUT_ergodox_80(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
    KC_TAB,     KC_NO,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
    KC_G,       KC_NO,      KC_A,       KC_S,       KC_D,       KC_F,
    KC_M,       KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
    KC_F1,      KC_NO,      KC_NO,      KC_NO,      KC_LSFT,
    KC_NO,      KC_NO,
    KC_NO,      KC_LALT,    KC_NO,
    KC_SPC,     KC_ENT,     KC_NO,

    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
)
};

static void tildes(uint16_t keycode) {
    bool is_shift_pressed = get_mods() & MOD_MASK_SHIFT;

    if (is_shift_pressed) { unregister_code(KC_LSFT); }

    switch (keycode) {
        case _A_TILD ... _I_TILD: SEND_STRING(SS_TAP(X_QUOTE)); break;
        case _ENHE: SEND_STRING("~"); break;
    }

    if (is_shift_pressed) { register_code(KC_LSFT); }

    switch (keycode) {
        case _A_TILD: SEND_STRING(SS_TAP(X_A)); break;
        case _O_TILD: SEND_STRING(SS_TAP(X_O)); break;
        case _E_TILD: SEND_STRING(SS_TAP(X_E)); break;
        case _U_TILD: SEND_STRING(SS_TAP(X_U)); break;
        case _I_TILD: SEND_STRING(SS_TAP(X_I)); break;
        case _ENHE: SEND_STRING(SS_TAP(X_N)); break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _A_TILD ... _ENHE:
            if (record->event.pressed) { tildes(keycode); }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

static void render_layer(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case DVORAK: oled_write_ln_P(PSTR("DVORAK"), false); break;
        case MOD: oled_write_ln_P(PSTR("MODS"), false); break;
        case ARR: oled_write_ln_P(PSTR("ARROWS"), false); break;
        case GAME: oled_write_ln_P(PSTR("GAMING"), false); break;
        default: oled_write_ln_P(PSTR("?"), false); break;
    }

    oled_write_P(PSTR("---------------------"), false);
}

static void render_mod(char name, bool active) {
    oled_write_char(name, active);
    oled_write_char(' ', false);
}

static void render_mods(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(0, 2);
    oled_write_P(PSTR("Mods:  "), false);
    render_mod('C', mods & MOD_MASK_CTRL);
    render_mod('S', mods & MOD_MASK_SHIFT);
    render_mod('A', mods & MOD_MASK_ALT);
    render_mod('G', mods & MOD_MASK_GUI);
    oled_advance_page(true);
}

static void render_wpm(void) {
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("WPM:   "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

bool oled_task_user(void) {
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }

    render_layer();
    render_mods();
    render_wpm();
    return false;
}
#endif

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
}
#endif

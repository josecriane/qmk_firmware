#include QMK_KEYBOARD_H
#include "67manuform.h"
#include "util.h"

void windows_tildes(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    bool is_shift_pressed = false;
    is_shift_pressed = (get_mods() & MOD_BIT(KC_LSFT));

    if (is_shift_pressed) { unregister_code(KC_LSHIFT); }

    switch (keycode) {
        case _A_TILD ... _I_TILD: SEND_STRING(SS_TAP(X_QUOTE)); break;
        case _ENHE: SEND_STRING("~"); break;
    }

    if (is_shift_pressed) { register_code(KC_LSHIFT); }

    switch (keycode) {
        case _A_TILD: SEND_STRING(SS_TAP(X_A)); break;
        case _O_TILD: SEND_STRING(SS_TAP(X_O)); break;
        case _E_TILD: SEND_STRING(SS_TAP(X_E)); break;
        case _U_TILD: SEND_STRING(SS_TAP(X_U)); break;
        case _I_TILD: SEND_STRING(SS_TAP(X_I)); break;
        case _ENHE: SEND_STRING(SS_TAP(X_N)); break;
    }
  }
}

void mac_tildes(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
     bool is_shift_pressed = false;
     is_shift_pressed = (get_mods() & MOD_BIT(KC_LSFT));

     if (is_shift_pressed) { unregister_code(KC_LSHIFT); }

     switch (keycode) {
         case _A_TILD_M ... _I_TILD_M:
           SEND_STRING(SS_LALT("e"));
           break;
         case _ENHE_M:
           SEND_STRING(SS_LALT("n"));
           break;
    }

    if (is_shift_pressed) { register_code(KC_LSHIFT); }

    switch (keycode) {
        case _A_TILD_M: SEND_STRING(SS_TAP(X_A)); break;
        case _O_TILD_M: SEND_STRING(SS_TAP(X_O)); break;
        case _E_TILD_M: SEND_STRING(SS_TAP(X_E)); break;
        case _U_TILD_M: SEND_STRING(SS_TAP(X_U)); break;
        case _I_TILD_M: SEND_STRING(SS_TAP(X_I)); break;
        case _ENHE_M: SEND_STRING(SS_TAP(X_N)); break;
    }
  }
}

// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

enum layers {
    DVRK,
    MOD,
    ARR,
    EMPTY,
};

enum custom_keycodes {
	_A_TILD = SAFE_RANGE,
	_O_TILD,
	_E_TILD,
	_U_TILD,
	_I_TILD,
	_ENHE,
};

void mac_tildes(uint16_t keycode, keyrecord_t *record);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap DVRK
 *
 * ,--------------------------------------------------.         ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |   `  |         |   ~  |   6  |   7  |   8  |   9  |   0  |    =   |
 * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
 * |  Tab   |   '  |   ,  |   .  |   P  |   Y  |   \  |         |   /  |   F  |   G  |   C  |   R  |   L  |    -   |
 * |--------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
 * |   [    |   A  |   O  |   E  |   U  |   I  |------|         |------|   D  |   H  |   T  |   N  |   S  |    ]   |
 * |--------+------+------+------+------+------|   {  |         |   }  |------+------+------+------+------+--------|
 * |   (    |   ;  |   Q  |   J  |   K  |   X  |      |         |      |   B  |   M  |   W  |   V  |   Z  |    )   |
 * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
 *   |      |      | CTRL |  GUI | SHFT |                                     |-> MOD|-> ARR|      |      |      |
 *   `----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |-> ARR|      |       |      |  Alt  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 | BACK |  DEL |------|       |------| ENTR | SPCE |
 *                                 |      |      |      |       |PgDwn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVRK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
        KC_TAB,      KC_QUOT,      KC_COMM, KC_DOT,   KC_P,   KC_Y,  KC_BSLS,
       KC_LBRC,         KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
       KC_LPRN,      KC_SCLN,         KC_Q,   KC_J,   KC_K,   KC_X,  KC_LCBR,
        KC_NO,         KC_NO,      KC_LCTL,KC_LGUI,KC_LSFT,
                                                                     MO(ARR),  KC_NO,
                                                                               KC_NO,
                                                        KC_BSPACE, KC_DELETE,  KC_NO,
        // right hand
             KC_TILDE,     KC_6,   KC_7,    KC_8,   KC_9,         KC_0,     KC_EQL,
              KC_SLSH,     KC_F,   KC_G,    KC_C,   KC_R,         KC_L,    KC_MINS,
                           KC_D,   KC_H,    KC_T,   KC_N,         KC_S,    KC_RBRC,
              KC_RCBR,     KC_B,   KC_M,    KC_W,   KC_V,         KC_Z,    KC_RPRN,
                                MO(MOD), MO(ARR),  KC_NO,        KC_NO,      KC_NO,
    KC_NO,    KC_LALT,
  KC_PGUP,
  KC_PGDN,   KC_ENTER, KC_SPACE
),
/* Keymap 1: MOD
 *
 * ,--------------------------------------------------.         ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |         |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |         |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
 * |        |   Á  |   Ó  |   É  |   Ú  |   Í  |------|         |------|      |      |      |  Ñ   |      |        |
 * |--------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |         |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOD] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
         KC_NO, _A_TILD, _O_TILD,_E_TILD, _U_TILD, _I_TILD,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                                              KC_TRNS,   KC_TRNS,
                                                                         KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,   KC_TRNS,
       // right hand
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           KC_NO,   KC_NO,   KC_NO,   _ENHE,   KC_NO,   KC_NO,
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 1: Arrow
 *
 * ,---------------------------------------------------.        ,--------------------------------------------------.
 * |        |  F1   |  F2  |  F3  |  F4  |  F5  |      |        |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+-------+------+------+------+-------------|        |------+------+------+------+------+------+--------|
 * |        | LEFT  | DOWN |  UP  | RGHT |      |      |        |      |      |      |      |      |      |  F12   |
 * |--------+-------+------+------+------+------|      |        |      |------+------+------+------+------+--------|
 * |        |SEL ALL| COPY |PASTE |  CUT |      |------|        |------|      | LEFT | DOWN |  UP  | RGHT |        |
 * |--------+-------+------+------+------+------|      |        |      |------+------+------+------+------+--------|
 * |        |       |      | UNDO |      |      |      |        |      |      |CTL+E |      |      |CTL+A |        |
 * `--------+-------+------+------+------+-------------'        `-------------+------+------+------+------+--------'
 *   |      |       |      |      |      |                                    |      |      |      |      |      |
 *   `-----------------------------------'                                    `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARR] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,      KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS,    KC_LEFT,    KC_DOWN,      KC_UP,   KC_RIGHT,   KC_NO,   KC_TRNS,
       KC_TRNS, LGUI(KC_A), LGUI(KC_C), LGUI(KC_V), LGUI(KC_X),   KC_NO,
       KC_TRNS,      KC_NO,      KC_NO, LGUI(KC_Z),      KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,      KC_NO,    KC_TRNS,      KC_NO,      KC_NO,
                                                              KC_TRNS,   KC_TRNS,
                                                                         KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,   KC_TRNS,
       // right hand
                KC_TRNS,   KC_F6,      KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,
                KC_TRNS,   KC_NO,      KC_NO,    KC_NO,   KC_NO,      KC_NO,   KC_F12,
                           KC_NO,    KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,   KC_NO,
                KC_TRNS,   KC_NO, LCTL(KC_E),    KC_NO,   KC_NO, LCTL(KC_A),   KC_NO,
                                       KC_NO,    KC_NO,   KC_NO,      KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 1: EMPTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[EMPTY] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,   KC_NO, KC_TRNS,  KC_NO,   KC_NO,
                                                              KC_TRNS,   KC_TRNS,
                                                                         KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,   KC_TRNS,
       // right hand
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = get_highest_layer(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case DVRK:
      ergodox_right_led_1_on();
      break;
    case MOD:
      ergodox_right_led_2_on();
      break;
    case ARR:
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _A_TILD ... _ENHE:
      mac_tildes(keycode, record);
      return false;
  }
	return true;
};

// Private functions

void mac_tildes(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
     bool is_shift_pressed = false;
     is_shift_pressed = (get_mods() & MOD_BIT(KC_LSFT));

     if (is_shift_pressed) { unregister_code(KC_LSHIFT); }

     switch (keycode) {
         case _A_TILD ... _I_TILD:
           SEND_STRING(SS_LALT("e"));
           break;
         case _ENHE:
           SEND_STRING(SS_LALT("n"));
           break;
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
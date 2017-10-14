#include "manuformpad.h"

#define KEYMAP( \
    k00, k01, k02, k03, k04, \
    k10, k11, k12, k13, k14, \
    k20, k21, k22, k23, k24, \
         k31, k32, k33, k34, \
                            k43, k44, \
                            k41, k42 \
) \
{ \
    { k00, k01, k02, k03, k04 }, \
    { k10, k11, k12, k13, k14 }, \
    { k20, k21, k22, k23, k24 }, \
    { KC_NO, k31, k32, k33, k34 }, \
    { KC_NO, k41, k42, k43, k44 } \
}

#define _A          KC_A
#define _B          KC_B
#define _C          KC_C
#define _D          KC_D
#define _E          KC_E
#define _F          KC_F
#define _H          KC_H
#define _I          KC_I
#define _J          KC_J
#define _K          KC_K
#define _L          KC_L
#define _M          KC_M
#define _N          KC_N
#define _O          KC_O
#define _P          KC_P
#define _Q          KC_Q
#define _R          KC_R
#define _S          KC_S
#define _T          KC_T
#define _U          KC_U
#define _V          KC_V
#define _W          KC_W
#define _X          KC_X
#define _Y          KC_Y
#define _Z          KC_Z
#define _SHIFT      KC_LSHIFT
#define _CTL        KC_LCTL
#define _ALT        KC_LALT
#define _TAB        KC_TAB
#define _ESC        KC_ESC
#define _F2         KC_F2

#define _______             KC_TRNS
#define XXXXXXX             KC_NO

/* Macros */
enum macros_id {
    _F2_COPY,
    _F2_PASTE,
};

#define M_FCOPY           M(_F2_COPY)
#define M_FPASTE          M(_F2_PASTE)


/* Layers */
enum layers_id {
    _UTIL,
    _GAME,
    _TABLETOP,
    _ARROW,
    _FACTORIO,
    _RIM1,
    _RIM2,
    _GW2,
    _FUNCTION,
};

#define MO_FUNC            MO(_FUNCTION)
#define MO_RIM2            MO(_RIM2)

/*
[LAYER] = KEYMAP(                \
  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______, \
            _______,  _______,  _______,  _______, \
                                                _______,  _______, \
                                                _______,  _______  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_UTIL] = KEYMAP(                 \
     _ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  M_FCOPY, M_FPASTE, \
  XXXXXXX,  XXXXXXX,  XXXXXXX, LCTL(_C), LCTL(_V), \
             KC_FN1,   KC_FN2,   KC_ENT, LCTL(_Z), \
                                               LCTL(_S),  MO_FUNC, \
                                                XXXXXXX, LGUI(_L)  ),

[_GAME] = KEYMAP(                \
     _ESC,     KC_1,     KC_2,     KC_3,     KC_4, \
     _TAB,       _Q,     KC_W,       _E,       _R, \
   _SHIFT,     KC_A,     KC_S,     KC_D,       _F, \
            XXXXXXX,  XXXXXXX,     _CTL,   KC_SPC, \
                                                 KC_ENT,  MO_FUNC, \
                                                XXXXXXX,  XXXXXXX  ),

[_TABLETOP] = KEYMAP(                \
     KC_1,     KC_2,     KC_3,     KC_4,     KC_5, \
 LCTL(_Z),  XXXXXXX,     KC_W,       _F,  XXXXXXX, \
  XXXXXXX,     KC_A,     KC_S,     KC_D,  XXXXXXX, \
            XXXXXXX,  XXXXXXX,   KC_ENT,     _ALT, \
                                                XXXXXXX,  MO_FUNC, \
                                                XXXXXXX,   KC_SPC  ),

[_ARROW] = KEYMAP(                \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX,  XXXXXXX,    KC_UP,  XXXXXXX,  XXXXXXX, \
  XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RIGHT,  XXXXXXX, \
            XXXXXXX,  XXXXXXX,  _______,   KC_SPC, \
                                                XXXXXXX,  MO_FUNC, \
                                                XXXXXXX,  XXXXXXX  ),

[_FACTORIO] = KEYMAP(                \
     _ESC,       _Q,  XXXXXXX,  XXXXXXX,       _T, \
  XXXXXXX,       _E,       _W,       _R,       _F, \
   _SHIFT,       _A,       _S,       _D,       _Z, \
            XXXXXXX,  XXXXXXX,     _CTL,   KC_SPC, \
                                                 KC_ENT,  MO_FUNC, \
                                                   _ALT,     _TAB  ),

[_RIM1] = KEYMAP(                \
     _ESC,  KC_PAST,  XXXXXXX,       _R,       _F, \
     _TAB,       _Q,       _W,       _E,       _C, \
  MO_RIM2,       _A,       _S,       _D,       _X, \
           KC_COMMA,   KC_DOT,  XXXXXXX,   KC_SPC, \
                                                 KC_ENT,  MO_FUNC, \
                                                KC_PGUP,KC_PGDOWN  ),

[_RIM2] = KEYMAP(                \
  XXXXXXX,       _B,       _H,       _Y,       _N, \
  XXXXXXX,       _J,       _U,       _M,       _K, \
  _______,       _I,       _L,       _O,       _P, \
            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
                                                XXXXXXX,  MO_FUNC, \
                                                XXXXXXX,  XXXXXXX  ),

[_GW2] = KEYMAP(                \
     KC_5,     KC_1,     KC_2,     KC_3,     KC_4, \
    KC_F1,    KC_F2,     KC_W,    KC_F3,    KC_F4, \
 KC_MINUS,     KC_A,     KC_S,     KC_D,       _F, \
            XXXXXXX,    KC_F5,  XXXXXXX,   KC_SPC, \
                                                     _H,  MO_FUNC, \
                                                     _I,       _M  ),

[_FUNCTION] = KEYMAP(                \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   KC_FN0,   KC_FN2,   KC_FN6,  XXXXXXX,  XXXXXXX, \
             KC_FN1,   KC_FN3,   KC_FN4,   KC_FN5, \
                                                XXXXXXX,  _______, \
                                                XXXXXXX,  XXXXXXX  ),

};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_CLEAR(true),
    [1] = ACTION_LAYER_SET(_GAME, true),
    [2] = ACTION_LAYER_SET(_TABLETOP, true),
    [3] = ACTION_LAYER_SET(_ARROW, true),
    [4] = ACTION_LAYER_SET(_FACTORIO, true),
    [5] = ACTION_LAYER_SET(_RIM1, true),
    [6] = ACTION_LAYER_SET(_GW2, true),
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case _F2_COPY:
                return MACRO(T(F2), D(LCTL), T(C), U(LCTL), T(ENT), END);
            case _F2_PASTE:
                return MACRO(T(F2), D(LCTL), T(V), U(LCTL), T(ENT), END);
        }
    }
    return MACRO_NONE;
};

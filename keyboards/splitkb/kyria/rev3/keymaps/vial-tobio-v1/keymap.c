/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers { _BASE = 0, _NAV, _SYM, _FUNCTION, _ADJUST };

// Aliases for readability

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: COLEMAK-DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  !     |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |  - _   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ?     |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |   ' "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | CapsLk |   Z  |   X  |   C  |   D  |   V  | LALT |  &   |  |   `  | LCTL |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LSFT | Del  | Bksp | Esc  |  | Enter| Space| Tab  | LGUI | Menu |
 *                        `----------------------------------'  '----------------------------------'
 */
    [_BASE] = LAYOUT(
     LSFT(KC_1)     , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                               KC_J   ,   KC_L ,  KC_U ,   KC_Y ,  KC_SCLN , KC_MINS,
     LSFT(KC_SLSH)  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                               KC_M   ,   KC_N ,  KC_E ,   KC_I ,  KC_O    , CTL_QUOT,
     KC_CAPS        , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LALT ,KC_AMPR,         KC_GRV   , KC_LCTL, KC_K   ,   KC_H ,KC_COMM, KC_DOT ,  KC_SLSH , KC_GRV  ,
                                       ADJUST , KC_LSFT, KC_DEL , KC_BSPC , KC_ESC,         KC_ENT   , KC_SPC , KC_TAB , KC_LGUI, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                                 KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL,            _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  >   |  ]   |  }   |  )   |  |   |                              |   -  |  7   |  8   |  9   |  :   |    _   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  <   |  [   |  {   |  (   |  @   |                              |   =  |  4   |  5   |  6   |  %   |    `   |
 * |--------+------+------+------+------+------+-------------.  ,------+-------------+------+------+------+------+--------|
 * |        |  ^   |  ~   |  $   |  &   |  #   |      |      |  |      |      |   +  |  1   |  2   |  3   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     _______ , LSFT(KC_DOT) , KC_RBRC     , LSFT(KC_RBRC), LSFT(KC_0) , LSFT(KC_BSLS),                                               KC_MINS,   KC_7 ,   KC_8 ,   KC_9 , LSFT(KC_SCLN) , LSFT(KC_MINS), 
     _______ , LSFT(KC_COMM), KC_LBRC     , LSFT(KC_LBRC), LSFT(KC_9) , LSFT(KC_2)   ,                                               KC_EQL ,   KC_4 ,   KC_5 ,   KC_6 , LSFT(KC_5)    , KC_GRV       , 
     _______ , LSFT(KC_6)   , LSFT(KC_GRV), LSFT(KC_4)   , LSFT(KC_7) , LSFT(KC_3)   , _______, _______,           _______, _______, KC_PLUS,   KC_1 ,   KC_2 ,   KC_3 , KC_SLSH       , KC_QUES      ,
                                            _______      , _______    , _______      , _______, _______,           _______, _______, KC_0   , _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LALT | LGUI | LSFT | LCTL |      |                              |      |  F5  |  F6  |  F7  |  F8  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F4  |        |
 * `--------+------+------+--------------------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______,  _______, _______,                                               _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,
      _______, LALT   , LGUI   , LSFT   ,  LCTL   , _______,                                               _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,
      _______, _______, _______, _______,  _______, _______, _______, _______,           _______, _______, _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,
                                 _______,  _______, _______, _______, _______,           _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                               _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                               RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
    )
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

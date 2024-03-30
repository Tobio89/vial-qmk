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
#include "oled_images.h"

enum layers { _BASE = 0, _NAV, _SYM, _FUNCTION, _ADJUST, _MACRO };

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
 * | CapsLk |   Z  |   X  |   C  |   D  |   V  | LALT | LGUI |  |   &  | LCTL |   K  |   H  | ,  < | . >  | /  ? |   `    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| ESC  | Del  | Bksp | LSFT |  | RSFT | Space| Tab  | Enter| Menu |
 *                        `----------------------------------'  '----------------------------------'
 */
    [_BASE] = LAYOUT(
     LSFT(KC_1)     , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                               KC_J   ,   KC_L ,  KC_U ,   KC_Y ,  KC_SCLN , KC_MINS,
     LSFT(KC_SLSH)  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                               KC_M   ,   KC_N ,  KC_E ,   KC_I ,  KC_O    , CTL_QUOT,
     KC_CAPS        , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LALT ,KC_LGUI,         KC_AMPR  , KC_LCTL, KC_K   ,   KC_H ,KC_COMM, KC_DOT ,  KC_SLSH , KC_GRV  ,
                                       ADJUST , KC_ESC , KC_DEL , KC_BSPC ,KC_LSFT,         KC_RSFT  , KC_SPC , KC_ENT , KC_TAB , FKEYS
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                                 KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  >   |  ]   |  }   |  )   |  #   |                              |   -  |  7   |  8   |  9   |  :   |    _   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  <   |  [   |  {   |  (   |  @   |                              |   =  |  4   |  5   |  6   |  %   |    `   |
 * |--------+------+------+------+------+------+-------------.  ,------+-------------+------+------+------+------+--------|
 * |        |  ^   |  ~   |  $   |  &   |  |   |      |      |  |      |      |   +  |  1   |  2   |  3   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     _______ , LSFT(KC_DOT) , KC_RBRC     , LSFT(KC_RBRC), LSFT(KC_0) , LSFT(KC_3),                                               KC_MINS,   KC_7 ,   KC_8 ,   KC_9 , LSFT(KC_SCLN) , LSFT(KC_MINS), 
     _______ , LSFT(KC_COMM), KC_LBRC     , LSFT(KC_LBRC), LSFT(KC_9) , LSFT(KC_2)   ,                                               KC_EQL ,   KC_4 ,   KC_5 ,   KC_6 , LSFT(KC_5)    , KC_GRV       , 
     _______ , LSFT(KC_6)   , LSFT(KC_GRV), LSFT(KC_4)   , LSFT(KC_7) , LSFT(KC_BSLS)   , _______, _______,           _______, _______, KC_PLUS,   KC_1 ,   KC_2 ,   KC_3 , KC_SLSH       , KC_QUES      ,
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
      _______, KC_LCTL, KC_LALT, KC_LGUI,  KC_LSFT, _______,                                               _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,
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
    ),

/*
 * Macro Layer: Blank, set up in VIAL
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
    [_MACRO] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                               _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                               _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,  _______, _______,
                                 _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [5] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("\nTobio\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case 1:
                oled_write_P(PSTR("NAV\n"), false);
                break;
            case 2:
                oled_write_P(PSTR("NUM && SYM\n"), false);
                break;
            case 3:
                oled_write_P(PSTR("Fn\n"), false);
                break;
            case 4:
                oled_write_P(PSTR("KB Adjust\n"), false);                
                break;
            case 5:
                oled_write_P(PSTR("MACRO\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Host Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        oled_write_raw_P(atlas_logo, sizeof(atlas_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

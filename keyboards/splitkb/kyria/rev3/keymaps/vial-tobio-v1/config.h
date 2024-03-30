/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define VIAL_KEYBOARD_UID {0x21, 0xAA, 0xCA, 0xEC, 0x85, 0xE8, 0x27, 0xE5}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 6, 6 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
 
#define VIAL_TAP_DANCE_ENTRIES 20
#define VIAL_COMBO_ENTRIES 20

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define SPLIT_MODS_ENABLE

#define NO_MUSIC_MODE

#define RGBLIGHT_SPLIT
#define RGBLIGHT_SLEEP


// Limit brightness of LEDs to limit voltage
#define RGBLIGHT_LIMIT_VAL 80

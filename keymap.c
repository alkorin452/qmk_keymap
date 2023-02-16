/* Copyright 2022 splitkb.com <support@splitkb.com>
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


enum layers {
    _DEFAULT = 0,
    _NAV = 1,
    _NUM = 2,
    _BEAKL=3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer 0: Colemak-DH / OU
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    Q   |   A  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   O  |   Y  |  ;:  |  -  _  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   A  |   R  |   S  |   T  |   G  |                              |   K  |   N  |   E  |   I  |  U   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   D  |   V  |  ;:  |  =+  |  |  F12 | Esc  |   M  |   H  | ,  < | . >  | /  ? |  + =   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTRL |Option| CMD  | Bspc |L(Num)|  |L(Nav)|Space | Enter|      |      |
 *                        |      |      |      |      |      |  |      |Shift |      |      |  ESC |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DEFAULT] = LAYOUT(
      KC_Q,     KC_A,   KC_W,   KC_F,   KC_P,    KC_B,                                                     KC_J,    KC_L,    KC_O,    KC_Y,   KC_SCLN, KC_MINUS,
      KC_TAB,   KC_A,   KC_R,   KC_S,   KC_T,    KC_G,                                                     KC_K,    KC_N,    KC_E,    KC_I,   KC_U,    KC_QUOT,
      KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_D,    KC_V,        KC_SCLN,  KC_EQUAL,     KC_F12, KC_ESC,      KC_M,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_EQUAL,
                         KC_LEFT_CTRL,  KC_LOPT, KC_LEFT_GUI, KC_BSPC,  MO(_NUM),     MO(_NAV), RSFT_T(KC_SPC), KC_ENT ,  XXXXXXX,  XXXXXXX
    ),

/*
 * Navigation Layer 1: 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |      |      | Undo |      |      |                              |      | Copy |  UP  |Paste |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    | Ctrl |Option| Cmd  |Shift |      |                              |Begln | Left | Down |Right |Endln |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |      |      |      |      |      |      |      |  |      | Esc  |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTRL |Option| CMD  | Bspc |L(Num)|  |L(Nav)|Space | Enter|      |      |
 *                        |      |      |      |      |      |  |      |Shift |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______,  _______,  _______,  KC_UNDO,  _______,  _______,                                                      _______,       LCMD(KC_C),KC_UP,  LCMD(KC_V), _______,       _______,
      _______,  KC_LEFT_CTRL,  KC_LOPT,  KC_LEFT_GUI,   KC_LSFT,  _______,                                            LCMD(KC_LEFT),  KC_LEFT,  KC_DOWN, KC_RIGHT,  LCMD(KC_RIGHT), _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
                             _______, _______, _______, _______,  _______,             _______, _______, _______,  _______,  _______
    ),


/*
 * Numbers and Symbols Layer 3: 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |  1!  |  2@  |  3#  |  4$  |  5%  |                              |   6^ |  7&  |  8*  |  9(  |  0)  |   |\   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |  <   |  >   |   { |   }   |      |                              |  `~  |   (  |   )  |   [  |  ]   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |      |      |      |      |      |      |      |  |      | Esc  |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTRL |Option| CMD  | Bspc |L(Num)|  |L(Nav)|Space | Enter|      |      |
 *                        |      |      |      |      |      |  |      |Shift |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                  KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
      _______,  KC_LABK,  KC_RABK,  KC_LCBR,  KC_RCBR,  _______,                                               KC_GRAVE,  KC_LPRN,  KC_RPRN,  KC_LBRC,  KC_RBRC,  _______,  
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______, _______, _______,  _______,  _______,  _______,   _______,  _______,  
                                    _______,  _______,  _______,  _______,  _______,         _______, _______, _______,  _______,  _______
    ),

/*
 * Beakl: 4
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   H  |   O  |   U  |   X  |                              |   G  |   C  |   M  |   R  |  V   |  -  _  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   Y  |   I  |   E  |   A  | . >  |                              |   D  |   S  |   T  |   N  |  B   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |      |  ,<  |   J  |   K  |  /?  |      |  ;:  |  |   =+ | Esc  |   W  |   F  |   L  |   P  |  Z   |  + =   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTRL |Option| CMD  | Bspc |L(Num)|  |L(Nav)|Space | Enter|      |      |
 *                        |      |      |      |      |      |  |      |Shift |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BEAKL] = LAYOUT(
      KC_ESC,   KC_Q,   KC_H,   KC_O,   KC_U,    KC_X,                                                     KC_G,    KC_C,    KC_M,    KC_R,   KC_V, KC_MINUS,
      KC_TAB,   KC_Y,   KC_I,   KC_E,   KC_A,    KC_DOT,                                                   KC_D,    KC_S,    KC_T,    KC_N,   KC_B, KC_QUOT,
      KC_LSFT,XXXXXXX,  KC_COMM,KC_J,   KC_K,    KC_SLSH,   _______,  KC_SCLN,         KC_EQUAL, XXXXXXX,  KC_W, KC_F,    KC_L,    KC_P,    KC_Z,   KC_EQUAL,
                         KC_LEFT_CTRL,  KC_LOPT, KC_LEFT_GUI, KC_BSPC,  MO(_NUM),     MO(_NAV), RSFT_T(KC_SPC), KC_ENT ,  XXXXXXX,  XXXXXXX
    )

};



#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        tap_code(KC_0);
    } else if (index == 1) {
        tap_code(KC_1);
    }

    if (clockwise) {
        tap_code16(KC_PLUS);
    } else {
        tap_code(KC_MINUS);
    }

    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x64 OLED rotated 180 degrees is 21 characters wide and 8 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?/,.|abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?/,.|");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif

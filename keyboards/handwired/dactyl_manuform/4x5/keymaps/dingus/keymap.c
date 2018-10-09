#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Fillers to make layering more clear
#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | PAUSE|   ~  |                                                         | QUOT | ENT  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | CTRL | RAISE|                             | LOWER|  ALT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | TAB  | BSPC | | SPACE| FANCE|
 *                                    '------+------' '------+------'
 *                                    | Menu |  ESC | | GUI  |   \  |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
              KC_PAUSE, KC_GRV,                                                  KC_QUOT, KC_ENT,                    \
                                     KC_LCTRL, KC_LSFT,   LOWER,   KC_LALT,                                          \
                                     KC_BSPC,  KC_TAB,    KC_SPC,  RAISE,                                            \
                                     KC_ESC,   KC_MENU,   KC_LGUI, KC_SLSH
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  RGB_M_K, ____,    RGB_MOD,  RGB_RMOD,  RGB_TOG,                   KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  MAGIC_TOGGLE_NKRO, KC_LEFT, RGB_HUI, RGB_SAI,  RGB_VAI,                    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDOWN, \
  RGB_M_T, RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD,                    KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        ____,    ____,                                                          ____,    ____,                \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_GRV,   KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,                           KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_PGDN, \
           KC_F11, KC_F12,                                                               ____,    ____,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/* Copyright 2015-2017 Jack Humbert
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
 * You should have received a copy of the GNU Genera~l Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,
 MACRO_TROLL,
 MACRO_LOOK,
 MACRO_OO,
 MACRO_SMILE,
 MACRO_ME,
 MACRO_SPACEDOUT,
 MACRO_HMM,
 MACRO_SHRUG,
 MACRO_FLIP,
 MACRO_GBP,
 MACRO_ASTRX,
 RSBR,
 LSBR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC/~|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | :;   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | HYPER|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   "" | ENTER|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   UP | Shift
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CLPBRD| Ctrl |BKMRKS| GUI  |Lower |    Space    |Raise | / ?  | LEFT |  Down|Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN,  \
  KC_CAPSLOCK,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, RSFT_T(KC_SLSH),  \
  LGUI(KC_O), KC_LCTL, LGUI(KC_J), KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   LGUI(KC_K), KC_LEFT, KC_DOWN, KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,  \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   &  |   *  |   (  |  )   |   -  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |      |   #  |   $  | TROLL|   ^  |   _  |   *  |   (  |   _  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |FLIP  | SHRUG|  F3  | FAVES|  F5  |  ಠ_ಠ |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 | FAVES|  F12 | /me  |   {  |   }  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   	MACRO_GBP, 	KC_DLR,      KC_PERC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_PLUS, \
  KC_TILD, KC_EXLM, _______,   KC_HASH, 	KC_DLR,  	 MACRO_TROLL, KC_CIRC, KC_UNDS, LSBR, RSBR, KC_UNDS, KC_DEL,  \
  KC_DEL,  MACRO_FLIP,   MACRO_SHRUG,KC_F3, LCTL(KC_F),  KC_F5,   MACRO_HMM,  KC_UNDS, KC_PLUS, MACRO_LOOK, KC_RCBR, KC_EQL, \
  _______, KC_F7,   KC_F8,   	KC_F9,   	KC_F10,  	 LCTL(KC_F),  KC_F12, MACRO_ME, KC_LCBR, KC_RCBR, KC_VOLU, _______, \
  _______, _______, _______, 	_______, 	_______, 	 KC_MPLY,   KC_MPLY, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_PLUS,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
     
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
          
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;

          case MACRO_TROLL: // when you hit your macro key, look at this case
      if (record->event.pressed)
      {
        SEND_STRING(":troll:");
      }
      return false;
      break;

  case MACRO_LOOK: // when you hit your macro key, look at this case
      if (record->event.pressed)
      {
        SEND_STRING(":looking:");
      }
      return false;
      break;

      case MACRO_OO: // o_O face
      if (record->event.pressed)
      {
        SEND_STRING("o_O");
      }
      return false;
      break;

      case MACRO_SMILE: // :) face
      if (record->event.pressed)
      {
        SEND_STRING(":)");
      }
      return false;
      break;

   case MACRO_ME: // /me 
      if (record->event.pressed)
      {
        SEND_STRING("/me");
      }
      return false;
      break;

  case MACRO_SPACEDOUT: // some kind of smiley face
      if (record->event.pressed)
      {
        SEND_STRING((SS_LALT("U+2742 U+203F U+2742")));
      }
      return false;
      break;

 case MACRO_HMM: // ಠ_ಠ
      if (record->event.pressed)
      {
        SEND_STRING(SS_LALT("U+0CA0"));
        SEND_STRING("_");
        SEND_STRING(SS_LALT("U+0CA0"));
      }
      return false;
      break;

  case MACRO_SHRUG: // ¯\_(ツ)_/¯
      if (record->event.pressed)
      {
        SEND_STRING(SS_LALT("U+00AF"));
        SEND_STRING("\\");
        SEND_STRING("_");
        SEND_STRING("(");
        SEND_STRING(SS_LALT("U+30C4"));
        SEND_STRING(")");
        SEND_STRING("_");
        SEND_STRING("/");
        SEND_STRING(SS_LALT("U+00AF"));
      }
      return false;
      break;    

        case MACRO_FLIP: // (╯°□°）╯︵┻━┻
      if (record->event.pressed)
      {
        SEND_STRING("(");
SEND_STRING(SS_LALT("U+256F U+00B0 U+25A1 U+00B0 U+FF09 U+256F U+FE35 U+253B U+2501 U+253B"));
      }
      return false; 
  break;  
        case MACRO_GBP: // £
      if (record->event.pressed)
      {
        SEND_STRING(SS_LALT("U+00A3"));
      }
      return false;
      break;  

  case LSBR: // [
      if (record->event.pressed)
      {
        SEND_STRING("[");
      }
      return false;
      break;  

  case RSBR: // ]
      if (record->event.pressed)
      {
        SEND_STRING("]");
      }
      return false;
      break;  
  }
  return true;

};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


  



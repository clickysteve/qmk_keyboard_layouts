#include QMK_KEYBOARD_H

// Sets aliases for certain keys to make the layouts easier to read.

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Gives the layers nicer names. 

#define _QWERTY 0
#define _SHORTCUTS 1
#define _MEDIA 2
#define _COLEMAK 4

// Defines the custom keycodes that I use, primarily for macros.

enum custom_keycodes {
 MACRO_TROLL = SAFE_RANGE,
 MACRO_LOOK,
 MACRO_OO,
 MACRO_SMILE,
 MACRO_ME,
 MACRO_SPACEDOUT,
 MACRO_HMM,
 MACRO_SHRUG, 
 MACRO_FLIP
};

// Layer keybord layouts below.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, LSFT(KC_F5), KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SCLN, 
    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, LCA(KC_NO), LGUI(KC_J), KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LGUI(KC_V), LGUI(KC_O), KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, RSFT_T(KC_SLSH), 
    MO(2), KC_LCTL, KC_LALT, MO(1), KC_LGUI, MO(1), LGUI(KC_C), KC_ENT, KC_SPC, LGUI(KC_K), LALT(KC_3), KC_LEFT, KC_DOWN, KC_RGHT),

  [1] = LAYOUT(BL_ON, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, MACRO_SMILE, KC_LBRC, KC_RBRC, KC_BSPC, 
    _______, _______, _______, _______, _______, MACRO_TROLL, _______, _______, _______, _______, _______, MACRO_OO, _______, _______, 
    _______, _______, MACRO_SHRUG, _______, MACRO_FLIP, _______, _______, _______, MACRO_HMM, _______, _______, MACRO_LOOK, KC_COLN, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MACRO_ME, LCTL(KC_F1), LCTL(KC_F2), KC_QUES, KC_BSLS, 
    _______, KC_LCTL, _______, KC_TRNS, _______, _______, _______, _______, KC_MPLY, LGUI(KC_O), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

  [2] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_LBRC, KC_BSPC, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, LSFT(KC_F5), KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SCLN, 
    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, LCA(KC_NO), LGUI(KC_J), KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LGUI(KC_V), RALT(KC_SLSH), KC_N, KC_M, LCTL(KC_F1), LCTL(KC_F2), KC_VOLU, KC_RSFT, 
    KC_TRNS, KC_LCTL, KC_LALT, KC_TRNS, KC_LGUI, KC_TRNS, LGUI(KC_C), KC_ENT, KC_MPLY, LGUI(KC_K), KC_SLSH, KC_MPRV, KC_VOLD, KC_MNXT),

  [4] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_LBRC, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, LSFT(KC_F5), LGUI(KC_K), KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, HYPR(KC_NO), KC_A, KC_R, KC_S, KC_T, KC_D, LCA(KC_NO), LGUI(KC_J), KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LSFT, RALT(KC_SLSH), KC_K, KC_M, KC_COMM, KC_DOT, KC_UP, KC_QUOT, KC_TRNS, KC_LCTL, KC_LALT, MO(1), KC_LGUI, KC_ENT, KC_NO, KC_ENT, KC_SPC, KC_LGUI, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT),

};  

// No idea what this does but it seems important. 


void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb_yellow();
};

// Sets underglow colour to reflect the currently active state

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _QWERTY:
      rgblight_setrgb_yellow();
      break;
    case _SHORTCUTS:
      rgblight_setrgb_springgreen();
      break;
    case _MEDIA:
      rgblight_setrgb_red();
      break;
    case _COLEMAK:
      rgblight_setrgb_purple();
      break;
  }
  return state;
};


// Macro section. Used mostly for quick access to emojis etc.


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
 
  }
return true;
}



#include QMK_KEYBOARD_H

// Gives the layers nicer names. 

#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _ADJUST 3

// Sets the default values for the RGB LEDs.

uint8_t prev = _BASE;
uint32_t desiredmode = 9;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 250;

// Does something to grab the RGB LED values to retain when switching layers.

void get_hsv(void) {
   hue = rgblight_get_hue();
   sat = rgblight_get_sat();
   val = rgblight_get_val();
}

void reset_hsv(void) {
   rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_mode(desiredmode);
   rgblight_enable();
   reset_hsv();
}

// Defines the custom keycodes that I sometimes use, primarily for macros.

enum custom_keycodes {
 MACRO_OO,
};


// Macro section. Used mostly for quick access to emojis etc.


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
           case MACRO_OO: // o_O face
      if (record->event.pressed)
      {
        SEND_STRING("o_O");
      }
      return false;
      break;
        
return false;
    break;
  }
    return true;
};


// KEYMAPS

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ base                                                      ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃   TAB   ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃    Y    ┃    U    ┃    I    ┃    O    ┃    P    ┃  BCKSP  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  GESC   ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┃    H    ┃    J    ┃    K    ┃    L    ┃    "    ┃   ENT   ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┃    N    ┃    M    ┃    ,    ┃    .    ┃    ;    ┃    /    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  COPY   ┃  CTRL   ┃   ALT   ┃   GUI   ┃ LAYER 1 ┃       SPACE       ┃ LAYER 2 ┃  ALFRED ┃CLIPBOARD┃  SHIORI ┃  PASTE  ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_planck_mit(

		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_GESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SCLN, RSFT_T(KC_SLSH), 
		LGUI(KC_C), KC_LCTL, KC_LALT, KC_LGUI, TT(1), KC_SPC, LT(2,KC_HASH), LGUI(KC_K), LGUI(KC_O), LGUI(KC_J), LGUI(KC_V)

		),



/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ layer one - symbols                                       ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃         ┃    !    ┃    @    ┃    $    ┃    %    ┃    ^    ┃    &    ┃    *    ┃    (    ┃    )    ┃    =    ┃  BCKSP  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃ LAYER 0 ┃         ┃         ┃         ┃         ┃         ┃         ┃    _    ┃    [    ┃    ]    ┃    `    ┃    :    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃    <    ┃    >    ┃    UP   ┃JAPANESE ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃ SCRNSHOT┃  CTRL   ┃   ALT   ┃   GUI   ┃         ┃       SPACE       ┃ LAYER 3 ┃   CUT   ┃   LEFT  ┃   DOWN  ┃  RIGHT  ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */


	[1] = LAYOUT_planck_mit(

		KC_NO, KC_EXLM, KC_AT, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL, KC_BSPC, 
		TG(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_MINS), KC_LBRC, KC_RBRC, KC_GRV, LSFT(KC_SCLN), 
		KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_MINS), KC_LT, KC_GT, KC_UP, LALT(KC_J), 
		SGUI(KC_4), KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC, MO(3), LGUI(KC_X), KC_LEFT, KC_DOWN, KC_RGHT
		),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ layer two - numbers                                       ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃         ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃  BCKSP  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃    _    ┃    -    ┃    +    ┃    \    ┃   ENT   ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃    {    ┃    }    ┃  VOLUP  ┃ ENGLISH ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  PLAY   ┃  CTRL   ┃   ALT   ┃   GUI   ┃         ┃       SPACE       ┃         ┃   MUTE  ┃PREVTRACK┃ VOLDOWN ┃NEXTTRACK┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */



	[2] = LAYOUT_planck_mit(

		KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_MINS), KC_PLUS, KC_BSLS, KC_ENT, 
		KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_VOLU, LALT(KC_E), 
		KC_MPLY, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_SPC, KC_TRNS, KC_MUTE, KC_MPRV, KC_VOLD, KC_MNXT
		
		),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ layer three - adjust                                      ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  RESET  ┃         ┃         ┃ COPYURL ┃ ROOTURL ┃ RGBSAT- ┃ RGBSAT+ ┃RGBTOGGLE┃RGBMODE- ┃RGBMODE+ ┃ COLOUR -┃ COLOUR +┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃RGBBRGHT-┃RGBBRGHT+┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */



	[3] = LAYOUT_planck_mit(

		RESET, KC_NO, KC_NO, LALT(KC_3), LALT(KC_4), RGB_SAD, RGB_SAI, RGB_TOG, RGB_MODE_REVERSE, RGB_MODE_FORWARD, RGB_HUD, RGB_HUI, 
		RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

};

// Section to change RGB LED colours and animation when activating layer 1 and 2, and then go back to the default, which I can change on the fly.

uint32_t layer_state_set_user(uint32_t state) 
{
  uint8_t layer = biton32(state);
  if (prev!=_ADJUST) {
      switch (layer) {
        case _BASE:
          rgblight_mode(desiredmode);
          reset_hsv();
          break;
        case _NUMBERS:
          rgblight_mode(0);
          rgblight_sethsv(HSV_CYAN);
          break;
        case _SYMBOLS:
          rgblight_mode(0);
          rgblight_sethsv(HSV_GREEN);
          break;  
          case _ADJUST:
          rgblight_mode(desiredmode);
          reset_hsv();
          break;
      }
  } else {
      desiredmode = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}


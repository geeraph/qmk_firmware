#include QMK_KEYBOARD_H

bool is_ctrl_pressed;
bool is_alt_pressed;
bool mute_toggle;
bool caps_lock;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_ansi(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, RGUI_T(KC_LEFT), LT(1,KC_DOWN), RCTL_T(KC_RIGHT)),
	[1] = LAYOUT_60_ansi(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_VOLU, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_HOME, KC_PGUP, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_END, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS, KC_TRNS),
	[2] = LAYOUT_60_ansi(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, BL_TOGG, BL_INC, BL_DEC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case 0:
        if (mute_toggle) {
			rgblight_setrgb(255,0,0);
		} else {
		rgblight_setrgb_range(255,20,147,0,7);
        rgblight_setrgb_range(0,255,255,7,14);
		}
        break;
    case 1:
        rgblight_setrgb(0,255,255);	
        break;
    case 2:
        rgblight_setrgb(255,20,147);
        break;
    /*default: //  for any other layers, or the default layer       
        rgblight_setrgb_range(255,20,147,0,7);
		rgblight_setrgb_range(0,255,255,7,14);		
		break;*/
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  //static bool mute_toggle;
  switch (keycode) {
  case KC_MUTE:
    if (!record -> event.pressed) {
      mute_toggle = !mute_toggle;
    }
    if (mute_toggle) {
      rgblight_setrgb(255, 0, 0);
    } else {
      //normal rgb code
	  rgblight_setrgb_range(255,20,147,0,7);
      rgblight_setrgb_range(0,255,255,7,14);
    }
    return true;
  case KC_CAPS:
    if (!record -> event.pressed) {
	  caps_lock = !caps_lock;
	}
	if (caps_lock) {
		rgblight_mode_noeeprom(RGBLIGHT_EFFECT_RAINBOW_SWIRL + 5);
	} else {
	  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	  rgblight_setrgb_range(255,20,147,0,7);
      rgblight_setrgb_range(0,255,255,7,14);
    }
    return true;
  case KC_LCTRL:
  if (record -> event.pressed) {
    is_ctrl_pressed = true;
  } else {
    is_ctrl_pressed = false;
  }
return true;
case KC_LALT:
  if (record -> event.pressed) {
    is_alt_pressed = true;
  } else {
    is_alt_pressed = false;
  }
return true;
case KC_4:
  if (record -> event.pressed) {
    if (is_alt_pressed && !is_ctrl_pressed) {
      register_code(KC_F4);
      unregister_code(KC_F4);
    }
  }
return true;
case KC_5:
  if (record -> event.pressed) {
    if (is_alt_pressed && !is_ctrl_pressed) {
      unregister_code(KC_LALT);
	  register_code(KC_F5);
      unregister_code(KC_F5);
    }
  }
return true;
case KC_BSPACE:
  if (record -> event.pressed) {
    if (is_ctrl_pressed && is_alt_pressed) {
      register_code(KC_DEL);
      unregister_code(KC_DEL);
    }
  }
return true;
  default:
    return true;
  }
}
/*
enum combo_events {
  ALT_F4,
  CTRL_ALT_DEL,
  ALT_F5
};

const uint16_t PROGMEM alt_f4_combo[] = {KC_LALT, KC_4, COMBO_END};
const uint16_t PROGMEM ctrl_alt_del_combo[] = {KC_LCTRL, KC_LALT, KC_BSPACE, COMBO_END};
const uint16_t PROGMEM alt_f5_combo[] = {KC_LALT, KC_5, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ALT_F4] = COMBO_ACTION(alt_f4_combo),
  [CTRL_ALT_DEL] = COMBO_ACTION(ctrl_alt_del_combo),
  [ALT_F5] = COMBO_ACTION(alt_f5_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
   case ALT_F4:
      if (pressed) {
        tap_code16(LALT(KC_F4));
      }
      break;
    case CTRL_ALT_DEL:
      if (pressed) {
        tap_code16(LCTL(LALT(KC_DEL)));
      }
      break;
    case ALT_F5:
      if (pressed) {
        tap_code16(KC_F5);
     }
      break;
  }
}*/
//[0] = LAYOUT_60_ansi(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(1), KC_LCTL),
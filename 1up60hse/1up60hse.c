/* Copyright 2018 MechMerlin
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
#include "1up60hse.h"
//#include "rgbstuff.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up	
	//matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	//matrix_scan_user();
}

void matrix_scan_user(void) {
	//rgblight_setrgb_range(255,20,147,0,6); this actually works
    //rgblight_setrgb_range(0,255,255,7,13);
}
	

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	//led_set_user(usb_led);
}

void keyboard_post_init_user(void) {
    //rgblight_set_effect_range(1,3);
	//rgblight_setrgb(255,20,147);
	//rgblight_set();
	wait_ms(300);
	rgblight_setrgb_range(255,20,147,0,7);
    rgblight_setrgb_range(0,255,255,7,14);
	//rgblight_enable_noeeprom();
	//rgblight_set_clipping_range(3, 4); try this again
	//rgblight_set_effect_range(0, 4); //where 2nd parameter is number of leds THIS IS WORKING KINDA, the range flahes the right colour then stops
	//rgblight_setrgb_range(255,20,147,0,6);
	//rgblight_sethsv(0, 255, 255);
	//rgblight_set_effect_range(3, 6);
	//rgblight_sethsv(0, 255, 255);
	//rgblight_set_effect_range(7, 13);
	//rgblight_setrgb_range(255,20,147,7,13);
	//rgblight_sethsv(255, 73, 255);
	//rgblight_enable_noeeprom();
	//rgblight_set_clipping_range(3, 4);
	//rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
	//rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 2);
	//rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
}


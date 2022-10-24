#include QMK_KEYBOARD_H

int ENCODER1Mode = 0;
int ENCODER2Mode = 0;

enum custom_keycodes {
    CHESTER_EMAIL = SAFE_RANGE,
	ICON_EMAIL, CHESTER_C, SELECT_FROM, TABLE_SCHEMA, COLUMN_SCHEMA, TEST1234, TEST12345,
	CHESTER_LOGIN, ENCODER1SHIFT, ENCODER2SHIFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    ENCODER1SHIFT,          KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  ENCODER2SHIFT,
    KC_P9,   KC_P0,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    KC_P7,   KC_P8,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_P6,   KC_P5,   LT(1, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_P3,   KC_P4,   KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_P1,   KC_P2,  KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,           MO(1),   KC_SPC,  KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUSE, KC_PSCREEN, KC_INSERT, _______,
    RGB_HUI, RGB_HUD, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    RGB_SAI, RGB_SAD, RGB_TOG, TABLE_SCHEMA, KC_UP, COLUMN_SCHEMA,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_VAI, RGB_VAD, _______, KC_LEFT, KC_DOWN, KC_RGHT, ICON_EMAIL, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          SELECT_FROM, CHESTER_EMAIL, CHESTER_LOGIN, CHESTER_C, TEST1234, TEST12345, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, RESET, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	if (record->event.pressed) 
	{
        switch(keycode) 
		{
			case ENCODER1SHIFT:
			if (ENCODER1Mode == 0) {
			  ENCODER1Mode = 1;
			} else {
			  ENCODER1Mode = 0;
			}
			break;
			
			case ENCODER2SHIFT:
			if (ENCODER2Mode == 0) {
			  ENCODER2Mode = 1;
			} else {
			  ENCODER2Mode = 0;
			}
			break;
			
            case CHESTER_EMAIL:
                SEND_STRING("chestercristobal@gmail.com");
                return false; 
				break;
				
			case ICON_EMAIL:
                SEND_STRING("iconstellationi@gmail.com");     
				return false; 
				break;
				
            case CHESTER_C:
                SEND_STRING("chester.cristobal@ceridian.com");
                return false; 
				break;				
			
			case SELECT_FROM:
                SEND_STRING("select * from");     
				return false; 
				break;

			case TABLE_SCHEMA:
                SEND_STRING("select * from information_schema.tables where table_name like '%%' order by table_name asc");     
				return false; 
				break;

			case COLUMN_SCHEMA:
                SEND_STRING("select * from information_schema.columns where column_name like '%%' order by table_name asc");     
				return false; 
				break;

			case TEST1234:
                SEND_STRING("Test1234!");     
				return false; 
				break;				
				
			case TEST12345:
                SEND_STRING("Test12345!");     
				return false; 
				break;
				
			case CHESTER_LOGIN:
                SEND_STRING("chester.cristobal");     
				return false; 
				break;					
        }
    }
	
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
		if (index == 0 && ENCODER1Mode == 0) {
			if (clockwise) {
				tap_code(KC_PGDN);
			} else {
				tap_code(KC_PGUP);
			}
		}
		else if (index == 0 && ENCODER1Mode == 1) {
		if (clockwise) {
			tap_code(KC_MS_WH_DOWN);
		} else {
			tap_code(KC_MS_WH_UP);
		}
		}
		else if (index == 1 && ENCODER2Mode == 0) {
			if (clockwise) {
				tap_code(KC_MS_WH_RIGHT);
			} else {
				tap_code(KC_MS_WH_LEFT);
			}
		}
		else if (index == 1 && ENCODER2Mode == 1) {
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
		}
		return true;
}

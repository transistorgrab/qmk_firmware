#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]={
[0] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,   KC_F12,             KC_PSCR, KC_SLCK, KC_PAUSE,     KC_CALC,              KC_BSPC,\
    KC_GRAVE, KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   KC_MINUS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,      KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,\
        KC_TAB,        KC_A,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     KC_LBRC, KC_RBRC,   KC_DEL,  KC_END,  KC_PGDN,      KC_P7,   KC_P8,   KC_P9,   KC_PPLS,\
    KC_CAPS,  KC_NUBS, KC_Q,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN,  KC_QUOT, KC_NUHS,                                   KC_P4,   KC_P5,   KC_P6,\
        KC_LSHIFT,     KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, KC_ENT,             KC_UP,                 KC_P1,   KC_P2,   KC_P3,   KC_PENT,\
        KC_LCTRL,          KC_LWIN,  KC_LALT, KC_SPACE,     KC_SPACE,   KC_RALT, KC_APP, KC_RCTRL,                     KC_LEFT, KC_DOWN, KC_RIGHT,     KC_P0,            KC_PDOT,\
    KC__MUTE, KC_F13,  KC_F14, KC_F15, KC_F16, KC_F17,  BL_INC, BL_DEC, KC_F20, KC_F21, KC_F22\
)    
};

/**    KC__MUTE, KC_F13,  KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22 */

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
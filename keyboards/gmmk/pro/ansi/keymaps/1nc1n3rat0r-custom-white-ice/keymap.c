#include QMK_KEYBOARD_H
/*
Colors used to set RGBs using the driver directly MUST use RGB values
and do not have separate brightness APIs. To resolve this, we generate
our colors as HSVs and convert them to RGB using QMK's built-in
helper function. We can then decrease the HSV value property to affect brightness.

Hue values are 0 - 242 (degrees)  (color wheel restarts at 243)
    For online calculators that use 360 degress,
        Get the hue, divide by 360, then multiply by 255
Saturation and Value values are 0 - 255

To generate HSV from RGB, you can use something like https://www.rapidtables.com/convert/color/rgb-to-hsv.html
*/

#define _HSV_COLOR_CORAL 248, 199, 255
#define _HSV_COLOR_LIGHT_CORAL 248, 125, 255
#define _HSV_COLOR_WHITE 0, 0, 255
#define _HSV_LIGHT_MINT 107, 100, 233
#define _HSV_DARK_MINT 116, 255, 238


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_MEDIA_PLAY_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};

RGB get_rgb_from_hsv_values (int h, int s, int v){
    HSV hsv_color = {h, s, v};
    RGB rgb_result = hsv_to_rgb(hsv_color);
    return rgb_result;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
            

        } else {
            tap_code(KC_VOLD);
            
        }
    

    return true;
}

void keyboard_post_init_user(void) {
    // Call the post init code.
    // Enable RGB Matrix
    rgb_matrix_enable();
}

//rgb_matrix_indicators_user -- Run each cycle. This is best used for setting a particular color for a given cycle
void rgb_matrix_indicators_user(void) {

    RGB coral_color_rgb = get_rgb_from_hsv_values(_HSV_COLOR_CORAL);
    RGB light_coral_color_rgb = get_rgb_from_hsv_values(_HSV_COLOR_LIGHT_CORAL);
    RGB light_mint_color_rgb = get_rgb_from_hsv_values(_HSV_LIGHT_MINT);
    RGB dark_mint_color_rgb = get_rgb_from_hsv_values(_HSV_DARK_MINT);
    RGB white_color_rgb = get_rgb_from_hsv_values(_HSV_COLOR_WHITE);

    // Top two rows + top 4 side LEDs (2 each side)
    int coral_keys[] = { 6, 12, 18, 23, 28, 34, 39, 44, 50, 56, 61, 66, 69,
                         1, 7, 13, 19, 24, 29, 35, 40, 45, 51, 57, 62, 78, 85, 72,
                         67, 70, 68, 71
                       };
    // Next two rows + next 4 side LEDs (2 each side)
    int light_coral_keys[] = { 2, 8, 14, 20, 25, 30, 36, 41, 46, 52, 58, 63, 89, 93, 75,
                               73, 76, 74, 77
                             };

    // Next two rows + next 4 side LEDs (2 each side)
    int light_mint_keys[] = { 3, 9, 15, 21, 26, 31, 37, 42, 47, 53, 59, 64, 96,
                              80, 83, 81, 84
                            };

    // Next two rows + next 4 side LEDs (2 each side)
    int dark_mint_keys[] = { 
                        4, 10, 16, 22, 27, 32, 38, 43, 48, 54, 60, 90, 86,
                        94, 82, 
                        5, 11, 17, 33, 49, 55, 65, 95, 97, 79,
                        87, 91, 88, 92 
                      };

    // Escape key
    int white_keys[] = { 0 };

    // Left column of keys for capslock indicator
    int capslock_enabled_keys[] = { 0, 1, 2, 3, 4, 5 };

    /* For reference, LED indicies are defined here
    int left_leds_top_to_bottom[] = { 67, 70, 73, 76, 80, 83, 87, 91 };
    int right_leds_top_to_bottom[] = { 68, 71, 74, 77, 81, 84, 88, 92 };
    */

    // Set coral keys
    for(int i = 0; i < (sizeof(coral_keys)/sizeof(coral_keys[0])); i++){
        rgb_matrix_set_color(coral_keys[i], coral_color_rgb.r, coral_color_rgb.g, coral_color_rgb.b);

    }

    // Set light coral keys
    for(int i = 0; i < (sizeof(light_coral_keys)/sizeof(light_coral_keys[0])); i++){
        rgb_matrix_set_color(light_coral_keys[i], light_coral_color_rgb.r, light_coral_color_rgb.g, light_coral_color_rgb.b);

    }

    

    // Set light_mint_keys
    for(int i = 0; i < (sizeof(light_mint_keys)/sizeof(light_mint_keys[0])); i++){
        rgb_matrix_set_color(light_mint_keys[i], light_mint_color_rgb.r, light_mint_color_rgb.g, light_mint_color_rgb.b);

    }

    // Set dark_mint_keys
    for(int i = 0; i < (sizeof(dark_mint_keys)/sizeof(dark_mint_keys[0])); i++){
        rgb_matrix_set_color(dark_mint_keys[i], dark_mint_color_rgb.r, dark_mint_color_rgb.g, dark_mint_color_rgb.b);

    }


    // Set white_keys
    for(int i = 0; i < (sizeof(white_keys)/sizeof(white_keys[0])); i++){
        rgb_matrix_set_color(white_keys[i], white_color_rgb.r, white_color_rgb.g, white_color_rgb.b);

    }
    

    // Set specific keys of keyboard to a different color when capslock is enabled
    if (host_keyboard_led_state().caps_lock) {
        // Set capslock indicator keys
        for(int i = 0; i < (sizeof(capslock_enabled_keys)/sizeof(capslock_enabled_keys[0])); i++){
            rgb_matrix_set_color(capslock_enabled_keys[i], white_color_rgb.r, white_color_rgb.g, white_color_rgb.b);

        }
    
    }
}

/* 
Functions to suspend RGB when computer is off or sleeping
See: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
*/
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
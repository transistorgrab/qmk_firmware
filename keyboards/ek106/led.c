
#include "hal.h"
#include "led.h"
#include "printf.h"

#ifdef BACKLIGHT_ENABLE_OLD
#include "backlight.h"

void backlight_init_ports(void) {
    printf("backlight_init_ports()\n");

    palSetPadMode(GPIOC, 9, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOC, 9);
}

void backlight_set(uint8_t level) {
    printf("backlight_set(%d)\n", level);
    if (level == 0) {
        // Turn backlight off
        palSetPad(GPIOC, 9);
    } else {
        // Turn backlight on
        palClearPad(GPIOC, 9);
    }
}
#endif


void led_set_kb(uint8_t usb_led) {
    printf("led_set_kb(%d)\n", usb_led);
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        palSetPad(GPIOC, 8);
    } else {
        // Turn capslock off
        palClearPad(GPIOC, 8);
    }
        if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        // Turn capslock on
        palSetPad(GPIOC, 6);
    } else {
        // Turn capslock off
        palClearPad(GPIOC, 6);
    }
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // Turn capslock on
        palSetPad(GPIOC, 7);
    } else {
        // Turn capslock off
        palClearPad(GPIOC, 7);
    }

}

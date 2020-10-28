MCU = STM32F103

BOOTMAGIC_ENALBE   = full
AUDIO_ENABLE 	   = no
UNICODE_ENABLE 	   = yes
BACKLIGHT_ENABLE   = yes
BACKLIGHT_DRIVER   = pwm

## NKRO prevents Keyboard from working on system boot
NKRO_ENABLE 	   = no
## Console prevents keyboard from working on system boot
CONSOLE_ENABLE 	   = no


OLED_DRIVER_ENABLE = yes

WAIT_FOR_USB       = yes

SRC = led.c
LAYOUTS += default
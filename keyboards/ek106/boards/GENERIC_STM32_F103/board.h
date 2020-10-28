/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for a Generic STM32F103 board.
 */

/*
 * Board identifier.
 */
#define BOARD_GENERIC_STM32_F103
#define BOARD_NAME              "Generic STM32F103x board"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F103xB

/*
 * IO pins assignments
 */

/* on-board */

#define GPIOC_LED               8
#define GPIOD_OSC_IN            0
#define GPIOD_OSC_OUT           1

/* Backlighting */

#define GPIOC_BACKLIGHT_PIN     9

/* In case your board has a "USB enable" hardware
   controlled by a pin, define it here. (It could be just
   a 1.5k resistor connected to D+ line.)
*/
/*
#define GPIOB_USB_DISC          10
*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * PA0  - normal input
 * PA1  - normal input
 * PA2…7 - Output Rows
 * PA8  - not in use → input with pull up
 * PA9  - Alternate output  (USART1 TX).
 * PA10 - Normal input      (USART1 RX).
 * PA11 - USB_N
 * PA12 - USB_P
 * PA13…15 - not in use → input with pull up
 */
#define VAL_GPIOACRL            0x11111144      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x888884B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything normal input except:
 * PB6  - open drain output "I2C clock"
 * PB7  - open drain output "I2C data"
 * PB8  - Push Pull output  "audio 1"
 * PB9  - push pull ouput   "audio 2"
 */
#define VAL_GPIOBCRL            0x55444444      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x44444411      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything normal input except:
 * PC4     - push pull output row
 * PC6…9   - push pull output LEDs
 * PC13…15 - not in use → input with pull up
 */
#define VAL_GPIOCCRL            0x11414444      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88844411      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 * PD2  - Normal input
 */
#define VAL_GPIODCRL            0x88888444      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
/* The point is that most of the generic STM32F103* boards
   have a 1.5k resistor connected on one end to the D+ line
   and on the other end to some pin. Or even a slightly more
   complicated "USB enable" circuit, controlled by a pin.
   That should go here.

   However on some boards (e.g. one that I have), there's no
   such hardware. In which case it's better to not do anything.
*/
/*
#define usb_lld_connect_bus(usbp) palClearPad(GPIOB, GPIOB_USB_DISC)
*/
#define usb_lld_connect_bus(usbp) palSetPadMode(GPIOA, 12, PAL_MODE_INPUT);

/*
 * USB bus de-activation macro, required by the USB driver.
 */
/*
#define usb_lld_disconnect_bus(usbp) palSetPad(GPIOB, GPIOB_USB_DISC)
*/
#define usb_lld_disconnect_bus(usbp) palSetPadMode(GPIOA, 12, PAL_MODE_OUTPUT_PUSHPULL); palClearPad(GPIOA, 12);

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

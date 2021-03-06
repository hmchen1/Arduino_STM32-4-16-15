/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/maple_mini/board.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board file.
 */

#include <board/board.h>

#include <libmaple/gpio.h>
#include <libmaple/timer.h>

#include <wirish_debug.h>
#include <wirish_types.h>

/* Since we want the Serial Wire/JTAG pins as GPIOs, disable both SW
 * and JTAG debug support, unless configured otherwise. */
void boardInit(void) {
#ifndef CONFIG_MAPLE_MINI_NO_DISABLE_DEBUG
    disableDebugPorts();
#endif
}

// Note. See the enum of pin names in board.h

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {


    {GPIOA, TIMER2, ADC1,  0, 1,    0}, /* PA0 */
	{GPIOA, TIMER2, ADC1,  1, 2,    1}, /* PA1 */
    {GPIOA, TIMER2, ADC1,  2, 3,    2}, /* PA2 */	
    {GPIOA, TIMER2, ADC1,  3, 4,    3}, /* PA3 */
	{GPIOA,   NULL, ADC1,  4, 0,    4}, /* PA4 */
	{GPIOA,   NULL, ADC1,  5, 0,    5}, /* PA5 */
	{GPIOA, TIMER3, ADC1,  6, 1,    6}, /* PA6 */
	{GPIOA, TIMER3, ADC1,  7, 2,    7}, /* PA7 */
    {GPIOA, TIMER1, NULL,  8, 1, ADCx}, /* PA8 */	
    {GPIOA, TIMER1, NULL,  9, 2, ADCx}, /* PA9 */	
    {GPIOA, TIMER1, NULL, 10, 3, ADCx}, /* PA10 */
    {GPIOA, TIMER1, NULL, 11, 4, ADCx}, /* PA11 */
    {GPIOA,   NULL, NULL, 12, 0, ADCx}, /* PA12 */	
    {GPIOA,   NULL, NULL, 13, 0, ADCx}, /* PA13 */	
    {GPIOA,   NULL, NULL, 14, 0, ADCx}, /* PA14 */
    {GPIOA,   NULL, NULL, 15, 0, ADCx}, /* PA15 */
	
    {GPIOB, TIMER3, ADC1,  0, 3,    8}, /* PB0 */	
    {GPIOB, TIMER3, ADC1,  1, 4,    9}, /* PB1 */
    {GPIOB,   NULL, NULL,  2, 0, ADCx}, /* PB2 */
    {GPIOB,   NULL, NULL,  3, 0, ADCx}, /* PB3 */
    {GPIOB,   NULL, NULL,  4, 0, ADCx}, /* PB4 */
    {GPIOB,   NULL, NULL,  5, 0, ADCx}, /* PB5 */
    {GPIOB, TIMER4, NULL,  6, 1, ADCx}, /* PB6 */
    {GPIOB, TIMER4, NULL,  7, 2, ADCx}, /* PB7 */	
    {GPIOB, TIMER4, NULL,  8, 3, ADCx}, /* PB8 */	
	{GPIOB,   NULL, NULL,  9, 0, ADCx}, /* PB9 */	
    {GPIOB,   NULL, NULL, 10, 0, ADCx}, /* PB10 */	
    {GPIOB,   NULL, NULL, 11, 0, ADCx}, /* PB11 */
    {GPIOB,   NULL, NULL, 12, 0, ADCx}, /* PB12 */
    {GPIOB,   NULL, NULL, 13, 0, ADCx}, /* PB13 */
    {GPIOB,   NULL, NULL, 14, 0, ADCx}, /* PB14 */
    {GPIOB,   NULL, NULL, 15, 0, ADCx}, /* PB15 */

    {GPIOC,   NULL, NULL, 13, 0, ADCx}, /* PC13 */	
    {GPIOC,   NULL, NULL, 14, 0, ADCx}, /* PC14 */
    {GPIOC,   NULL, NULL, 15, 0, ADCx}, /* PC15 */



};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    PB0, PA7, PA6, PA3, PA2, PA1, PA0, PB7, PB6, PA10, PA9, PA8
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    PB0, PA7, PA6 , PA5 , PA4 , PA3 , PA2 , PA1 , PA0 
};

// Note. These defines are not really used by generic boards. They are for  Maple Serial USB
#define USB_DP PA12
#define USB_DM PA11

// NOte. These definitions are not really used for generic boards, they only relate to boards modified to behave like Maple boards
extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    BOARD_LED_PIN, BOARD_BUTTON_PIN, USB_DP, USB_DM
};

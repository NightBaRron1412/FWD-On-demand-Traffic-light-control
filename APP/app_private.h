/** @file app_private.h
 *
 * @brief A header file including private functions prototypes and defintions for app.c
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Dec 12, 2022
 *
 */

/* Include guard */
#ifndef APP_PRIVATE_H
#define APP_PRIVATE_H

/* F_osc definition for delay library */
#define F_CPU 8000000UL

/* Macros for LED interfacing */
#define CAR_GREEN LED_0
#define CAR_YELLOW LED_1
#define CAR_RED LED_2
#define PED_GREEN LED_3
#define PED_YELLOW LED_4
#define PED_RED LED_5
#define BOTH_YELLOW 101

/* Macros to define boolean values */
#define FALSE 0
#define TRUE 1

/*
 * Description: a function to preform yellow light blinking
 * Inputs: mode to indicate which yellow light to blink
 * Output: void
 */
void yellow_blink(u8 mode);

/*
 * Description: a function to check if the pedestrian button is pressed while green or yellow light is on
 * Inputs: void
 * Output: void
 */
void pedestrian_mode_green_yellow(void);

/*
 * Description: a function to check if the pedestrian button is pressed while red light is on
 * Inputs: void
 * Output: void
 */
void pedestrian_mode_red(void);

/*
 * Description: Timer0 callback function to set a timeup flag to indicate that time have passed
 * Inputs: void
 * Output: void
 */
void time_is_up(void);

/*
 * Description: a function to set delay for 5 seconds
 * Inputs: void
 * Output: void
 */
void delay_5sec(void);

/*
 * Description: a function to set delay for 500 milliseconds
 * Inputs: void
 * Output: void
 */
void delay_500msec(void);

/* ========================== Pedestrian Button ISR Function ========================== */
void pedestrian_buttonISR(void);

#endif /* APP_PRIVATE_H */

/*** end of file ***/
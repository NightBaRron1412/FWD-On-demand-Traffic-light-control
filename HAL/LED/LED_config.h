/** @file LED_config.h
 *
 * @brief A header file including init values and configs for LEDs.
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Dec 10, 2022
 *
 */

/* Include Guard */
#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/* the number of LEDs connected to the controller */
#define LED_NUM_OF_LEDS 6

/* LEDs ports                                         */
/* Range: LED_PORT_A                                  */
/*         LED_PORT_B                                 */
/*         LED_PORT_C                                 */
/*         LED_PORT_D                                 */
#define LED0_DIO_PORT LED_PORT_A
#define LED1_DIO_PORT LED_PORT_A
#define LED2_DIO_PORT LED_PORT_A
#define LED3_DIO_PORT LED_PORT_B
#define LED4_DIO_PORT LED_PORT_B
#define LED5_DIO_PORT LED_PORT_B

/* Array containing the ports connected to each configured led*/
u8 LED_Au8LedPort[LED_NUM_OF_LEDS] = {LED0_DIO_PORT, LED1_DIO_PORT, LED2_DIO_PORT, LED3_DIO_PORT, LED4_DIO_PORT, LED5_DIO_PORT};

/* LEDs pins                                */
/* Range: LED_PIN_0                         */
/*        LED_PIN_1                         */
/*        LED_PIN_2                         */
/*        LED_PIN_3                         */
/*        LED_PIN_4                         */
/*        LED_PIN_5                         */
/*        LED_PIN_6                         */
/*        LED_PIN_7                         */
#define LED0_DIO_PIN LED_PIN_0
#define LED1_DIO_PIN LED_PIN_1
#define LED2_DIO_PIN LED_PIN_2
#define LED3_DIO_PIN LED_PIN_0
#define LED4_DIO_PIN LED_PIN_1
#define LED5_DIO_PIN LED_PIN_2

/* Array containing the pins connected to each configured led*/
u8 LED_Au8LedPin[LED_NUM_OF_LEDS] = {LED0_DIO_PIN, LED1_DIO_PIN, LED2_DIO_PIN, LED3_DIO_PIN, LED4_DIO_PIN, LED5_DIO_PIN};

/* LEDs direction                            */
/* Range: LED_FORWARD                        */
/*        LED_REVERSE                        */
#define LED0_DIR LED_FORWARD
#define LED1_DIR LED_FORWARD
#define LED2_DIR LED_FORWARD
#define LED3_DIR LED_FORWARD
#define LED4_DIR LED_FORWARD
#define LED5_DIR LED_FORWARD

/*Array containing the direction of each led whether it is connected forward (active high) or reverse (active low)*/
u8 LED_Au8LedDirection[LED_NUM_OF_LEDS] = {LED0_DIR, LED1_DIR, LED2_DIR, LED3_DIR, LED4_DIR, LED5_DIR};

/* LEDs STATE                           */
/* Range: LED_ON                        */
/*        LED_OFF                       */
#define LED0_INIT_STATE LED_OFF
#define LED1_INIT_STATE LED_OFF
#define LED2_INIT_STATE LED_OFF
#define LED3_INIT_STATE LED_OFF
#define LED4_INIT_STATE LED_OFF
#define LED5_INIT_STATE LED_OFF

/*Array containing the init state of LED whether it's ON or OFF*/
u8 LED_Au8LedState[LED_NUM_OF_LEDS] = {LED0_INIT_STATE, LED1_INIT_STATE, LED2_INIT_STATE, LED3_INIT_STATE, LED4_INIT_STATE, LED5_INIT_STATE};

#endif /* LED_CONFIG_H */

/*** end of file ***/
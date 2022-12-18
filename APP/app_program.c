/** @file app.c
 *
 * @brief A traffic lights system with an on-demand crosswalk button
 *
 * @author Amir Shetaia
 * @version 2.0
 * @date Dec 18, 2022
 *
 */

/* ========================== Includes ========================== */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

#include "../UTILS/UTILS_DIO.h"
#include "../UTILS/UTILS_GIE.h"
#include "../UTILS/UTILS_TMR.h"
#include "../UTILS/UTILS_EXTI.h"

#include "../HAL/LED/LED_Interface.h"
#include "../HAL/BTN/BTN_Interface.h"

#include "app_private.h"
#include "app_interface.h"

/* ========================== Global Variables ========================== */

/* a variable to identify if the delay time is up */
volatile u8 timeisUp = FALSE;

/* variable to store the state of LEDs */
u8 carRedLEDState;
u8 carGreenLEDState;
u8 carYellowLEDState;

/* variable to store when the pedestrian button is pressed */
u8 pressedRedisOn = FALSE;
u8 pressedGreen_YellowisOn = FALSE;

/* flage to indicate if the yellow blinking loop should be reset */
u8 resetYellowBlinking = FALSE;

/* ========================== Application function ========================== */

void APP_VidStart(void)
{
    /* set the call back functions */
    EXTI_u8SetCallBack(TIMER_0, pedestrian_buttonISR);
    TMR_u8SetCallBack(TIMER_0, time_is_up);

    /* initialize the peripherals */
    DIO_VidInit();
    GIE_VidEnable();
    EXTI_VidInit();
    TMR_VidInit();
    LED_VidInit();
    BTN_VidInit();

    while (TRUE)
    {
        /* Turn on the car green LED for 5 secs*/
        LED_u8On(CAR_GREEN);

        /* wait until 5 seconds have passed or if the pedestrian button is pressed while green light was on */
        timeisUp = FALSE;
        TMR_u8SetDesiredTime(TIMER_0, 5 * SEC);
        while (timeisUp != TRUE && pressedGreen_YellowisOn != TRUE)
            ;

        /* Turn off pedestrian red light in case it was on */
        LED_u8Off(PED_RED);

        /* Check if pedestrian button is pressed while green light was on */
        pedestrian_mode_green_yellow();

        if (pressedGreen_YellowisOn)
        {
            /* reset the pressedGreen_YellowisOn variable */
            pressedGreen_YellowisOn = FALSE;

            /* go back to normal mode */
            continue;
        }

        /* blink the car yellow LED for 5 secs */
        yellow_blink(CAR_YELLOW);

        pedestrian_mode_green_yellow();

        if (pressedGreen_YellowisOn)
        {
            /* reset the pressedGreen_YellowisOn variable */
            pressedGreen_YellowisOn = FALSE;

            /* go back to normal mode */
            continue;
        }

        /* Turn on the car red LED for 5 secs */
        LED_u8On(CAR_RED);

        /* wait until 5 seconds have passed or if the pedestrian button is pressed while red light was on */
        timeisUp = FALSE;
        TMR_u8SetDesiredTime(TIMER_0, 5 * SEC);
        while (timeisUp != TRUE && pressedRedisOn != TRUE)
            ;

        /* Check if pedestrian button is pressed while green light was on */
        pedestrian_mode_red();

        if (pressedRedisOn)
        {
            /* reset the pressedRedisOn variable */
            pressedRedisOn = FALSE;

            /* go back to normal mode */
            continue;
        }
    }
}

/*
 * Description: a function to preform yellow light blinking
 * Inputs: mode to indicate which yellow light to blink
 * Output: void
 */
void yellow_blink(u8 mode)
{
    /* a flag to indicate that the yellow light is blinking */
    carYellowLEDState = HIGH;

    /* Blinking the yellow LEDs every second for 5 secs */
    for (u8 i = 1; i <= 5; i++)
    {
        LED_u8On(CAR_YELLOW);

        /* check if the pedestrian yellow light is required to be blinking */
        if (mode == BOTH_YELLOW)
        {
            LED_u8On(PED_YELLOW);
        }

        /* check if the yellow blinking loop should be reset */
        if (resetYellowBlinking)
        {
            /* reset the yellow blinking loop */
            resetYellowBlinking = FALSE;
            break;
        }

        delay_500msec();

        LED_u8Off(CAR_YELLOW);

        /* check if the pedestrian yellow light is required to be blinking */
        if (mode == BOTH_YELLOW)
        {
            LED_u8Off(PED_YELLOW);
        }

        /* check if the yellow blinking loop should be reset */
        if (resetYellowBlinking)
        {
            /* reset the yellow blinking loop */
            resetYellowBlinking = FALSE;
            break;
        }

        delay_500msec();
    }

    /* reset the yellow light state */
    carYellowLEDState = LOW;
}

/*
 * Description: a function to check if the pedestrian button is pressed while green or yellow light is on
 * Inputs: void
 * Output: void
 */
void pedestrian_mode_green_yellow(void)
{
    /* Check if the pedestrian button is pressed */
    switch (pressedGreen_YellowisOn)
    {
    case TRUE:
        /* Turn off the car green light */
        LED_u8Off(CAR_GREEN);

        /* Blinking both yellow LEDs for 5 secs */
        yellow_blink(BOTH_YELLOW);

        /* Turn on the pedestrian green light and the car red light for 5 sec */
        LED_u8Off(PED_RED);
        LED_u8On(PED_GREEN);
        LED_u8On(CAR_RED);
        delay_5sec();
        LED_u8Off(CAR_RED);

        /* Blinking both yellow LEDs for 5 secs while pedestrian green light is still on */
        yellow_blink(BOTH_YELLOW);

        /* Turn off the pedestrian green light and turn on the pedestrian red light */
        LED_u8Off(PED_GREEN);
        LED_u8On(PED_RED);

        break;

    case FALSE:
        /* Turn off the car green light */
        LED_u8Off(CAR_GREEN);

        break;
    }
}

/*
 * Description: a function to check if the pedestrian button is pressed while red light is on
 * Inputs: void
 * Output: void
 */
void pedestrian_mode_red(void)
{
    /* Check if the pedestrian button is pressed */
    switch (pressedRedisOn)
    {
    case TRUE:
        /* wait for 5 seconds while car red light and pedestrian green light is on */
        delay_5sec();

        /* Turn off the car red light and blink both yellow LEDs for 5 sec while pedestrian green light is still on */
        LED_u8Off(CAR_RED);
        yellow_blink(BOTH_YELLOW);

        /* Turn off the pedestrian green light and turn on the pedestrian red light */
        LED_u8Off(PED_GREEN);
        LED_u8On(PED_RED);

        break;

    case FALSE:
        /* Turn off the car red light and blink the car yellow LED for 5 sec */
        LED_u8Off(CAR_RED);
        yellow_blink(CAR_YELLOW);

        /* Check if pedestrian button is pressed while yellow light was blinking */
        pedestrian_mode_green_yellow();

        break;
    }
}

/*
 * Description: Timer0 callback function to set a timeup flag to indicate that time have passed
 * Inputs: void
 * Output: void
 */
void time_is_up(void)
{
    /* set the timeisUp flag to indicate that time have passed */
    timeisUp = TRUE;
}

/*
 * Description: a function to set delay for 5 seconds
 * Inputs: void
 * Output: void
 */
void delay_5sec(void)
{
    /* reset timeisUp flag */
    timeisUp = FALSE;

    /* set the timer to count for 5 seconds */
    TMR_u8SetDesiredTime(TIMER_0, 5 * SEC);

    /* wait until 5 seconds have passed */
    while (timeisUp != TRUE)
        ;
}

/*
 * Description: a function to set delay for 500 milliseconds
 * Inputs: void
 * Output: void
 */
void delay_500msec(void)
{
    /* reset timeisUp flag */
    timeisUp = FALSE;

    /* set the timer to count for 500 milliseconds */
    TMR_u8SetDesiredTime(TIMER_0, 500 * mSEC);

    /* wait until 500 milliseconds have passed */
    while (timeisUp != TRUE)
        ;
}

/* ========================== Pedestrian Button ISR Function ========================== */

void pedestrian_buttonISR(void)
{
    /* get the states of car LEDs */
    DIO_u8GetPinValue(PORT_A, PIN_0, &carGreenLEDState);
    DIO_u8GetPinValue(PORT_A, PIN_2, &carRedLEDState);

    /* check if the pedestrian button is pressed while red light is on */
    if (carRedLEDState == HIGH && pressedRedisOn == FALSE && pressedGreen_YellowisOn == FALSE)
    {
        LED_u8Off(PED_RED);
        LED_u8On(PED_GREEN);
        pressedRedisOn = TRUE;
    }

    /* check if the pedestrian button is pressed while green or yellow light is on */
    else if ((carGreenLEDState == HIGH || carYellowLEDState == HIGH) && pressedRedisOn == FALSE && pressedGreen_YellowisOn == FALSE)
    {
        pressedGreen_YellowisOn = TRUE;

        /* check if the yellow light is blinking */
        if (carYellowLEDState == HIGH)
        {
            /* reset the yellow blinking loop */
            resetYellowBlinking = TRUE;
        }
    }
}
/** @file GIE_program.c
 *
 * @brief A program that implements GIE functions
 *
 * @author Amir Shetaia
 * @version 1.2
 * @date Aug 22, 2021
 *
 */

#include "../../Lib/Std_Types.h"   /* Including standard types header */
#include "../../Lib/Bit_Math.h"    /* Includes bit math header functions */
#include "GIE_private.h"           /* Including header file including memory addresses for GIE port and BIT number */
#include "GIE_config.h"            /* Including header file for GIE configurations */
#include "../../UTILS/UTILS_GIE.h" /* Including header file for GIE Enable/Disable functions */

/*
 * Description: Function to enable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: void
 */
void GIE_VidEnable(void)
{
    SET_BIT(SREG, SREG_I_BIT);
}

/*
 * Description: Function to disable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: void
 */
void GIE_VidDisable(void)
{
    CLR_BIT(SREG, SREG_I_BIT);
}

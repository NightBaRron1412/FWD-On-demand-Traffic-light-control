/** @file UTILS_GIE.h
 * 
 * @brief A header file including APIs to enable or disable GIE 
 *
 * @author Amir Shetaia
 * @version 1.2
 * @date Dec 18, 2022       
 *
 */

/* include guard */
#ifndef UTILS_GIE_H
#define UTILS_GIE_H

/*
 * Description: Function to enable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: void
 */
void GIE_VidEnable(void);

/*
 * Description: Function to disable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: void
 */
void GIE_VidDisable(void);

#endif /* UTILS_GIE_H */

/*** end of file ***/
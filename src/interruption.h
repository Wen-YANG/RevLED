#include "utils.h"      // for the bool type

/*
 * interruption.h
 *
 *  Created on: 17 nov. 2017
 *      Author: Wen
 */
#ifndef INTERRUPTION_H_
#define INTERRUPTION_H_

extern bool buttonFlag;

//Turn off the LEDs if user touched the button.
__interrupt void TurnOffLED(void);

/*
 * Wait on Timer 0
 * param : on ms
 */
void waitTimer0(unsigned int time);

/*
 * Wait on Timer 1
 * param : on ms
 */
void waitTimer1(unsigned int time);

#endif /* INTERRUPTION_H_ */

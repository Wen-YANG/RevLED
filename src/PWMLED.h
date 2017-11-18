#include "utils.h"
/*
 * PWMLED.h
 *
 *  Created on: 17 nov. 2017
 *      Author: Wen
 */
//int intensity;      //Global variable
#ifndef PWMLED_H_
#define PWMLED_H_

extern bool buttonFlag;

/*
 * initPWM : initialize the PWM on P2.1 for LEDs
 */
void initPWM();

/*
 * LEDControl : change the LED brightness
 */
void LEDControl(int intensity);

/*
 * LEDLightUp : this function is not optimized and should only be used for testing
 */
void LEDLightUp();

/*
 * lightAdjust : adjust brightness with the alarmTime and buttonFlag.
 * This function turns on the LEDs
 */
void lightAdjust(int minute,int alarmTime);

#endif /* PWMLED_H_ */

/*
 * PWMLED.h
 *
 *  Created on: 17 nov. 2017
 *      Author: a.detrez.14
 */
int intensity;
#ifndef PWMLED_H_
#define PWMLED_H_

void initPWM();
void LEDControl(int intensity);
void LEDLightUp();

#endif /* PWMLED_H_ */

/*
 * PWMLED.c
 *
 *  Created on: 17 nov. 2017
 *      Author: a.detrez.14
 */
#include "PWMLED.h"
#include <msp430.h>

void initPWM()
{
	initSortie(1,BIT6); // PWM sur la LED
	P1SEL |= BIT6; 		// selection fonction Timer0_A3.TA1
	P1SEL2 &= ~BIT6; 	// selection fonction Timer0_A3.TA1

	TA0CTL = TASSEL_2 | MC_1 | ID_1; // source SMCLK pour le timer, mode UP, 2 times divider
	TA0CCTL1 |= OUTMOD_7; // activation mode de sortie 7 (PWM)

	TA0CCR0 = 100;
}

void LEDControl(int intensity){
	TA0CCR1 = intensity;
}
void LEDLightUp(){
	for(intensity = 0;intensity<100;intensity++){
		LEDControl(intensity);
		delay(10);
	}
}

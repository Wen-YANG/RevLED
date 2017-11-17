#include <msp430.h>
#include "PWMLED.h"
/*
 * interruption.c
 *
 *  Created on: 17 nov. 2017
 *      Author: a.detrez.14
 */

#pragma vector=PORT1_VECTOR
__interrupt void TurnOnLED(){
//	intensity ++;
//	if(intensity >= 100){
//		intensity = 0;
//	}else{
//	LEDLightUp();
	P1OUT ^= BIT6;
//	}
		//for testing
	TA0CTL &= ~TAIFG;//reset the flag
//	if ((P1IN & BIT3) == BIT3){
//		P1IES |= BIT3;
//	}else{
//		P1IES &= ~BIT3; // front montant
//	}
}

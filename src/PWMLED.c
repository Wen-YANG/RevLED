/*
 * PWMLED.c
 *
 *  Created on: 17 nov. 2017
 *      Author: Wen
 */
#include <msp430.h>
#include "PWMLED.h"
#include "interruption.h"
#include "utils.h"

bool buttonFlag;

void initPWM()
{
	initSortie(2,BIT1);                 // PWM sur la LED
	P2SEL |= BIT1; 		                // selection fonction Timer1
	P2SEL2 &= ~BIT1; 	                // selection fonction Timer1

	TA1CTL = TASSEL_2 | MC_1 | ID_1;    // source SMCLK pour le timer, mode UP, 2 times divider
	TA1CCTL1 |= OUTMOD_7;               // activation mode de sortie 7 (PWM)

	TA1CCR0 = 100;                      // Set the cycle to 100
}

void LEDControl(int intensity){
	TA1CCR1 = intensity;
}

void LEDLightUp(){
    int intensity;
	for(intensity = 0;intensity<100;intensity++){
		LEDControl(intensity);
		waitTimer1(10000);
	}
}

void lightAdjust(int minute,int alarmTime){
    volatile int intensity;
    intensity = minute - alarmTime;
    //in a new cycle, reset the flag to 0
    if(intensity == 0){
        buttonFlag = false;
    //if the user hasn't pushed the button
    }else if (intensity > 0 && buttonFlag == false){
        LEDControl(intensity);
    }else if (buttonFlag == true){
        LEDControl(0);
    }
}

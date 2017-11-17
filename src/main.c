#include <msp430.h> 
#include "PWMLED.h"
#include "utils.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    extern int intensity;
    initEntree(1,BIT3);
    initPWM();

    P1IE |= BIT3;
	P1IES |= BIT3;
	//PWM pour allumer la LED en doucheur
    __enable_interrupt();
    while(1){
//    	if((P1IN & BIT3) == 0){//if pushed the button
//			LEDControl(intensity);
////			delay(1000);
//			intensity ++;
//			delay(10);
//			if(intensity >= 100){
//				intensity = 0;
//			}
////			delay(1000);
//    	}
//    	else{
//			LEDControl(10);
////
//    	}

    }

	return 0;
}

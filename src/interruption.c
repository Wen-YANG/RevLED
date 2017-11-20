#include <msp430.h>
#include "utils.h"

bool buttonFlag;

/*
 * interruption.c
 *
 *  Created on: 17 nov. 2017
 *      Author: Wen
 */
#pragma vector=PORT1_VECTOR
__interrupt void TurnOffLED(){
    buttonFlag = true;      //set the global variable buttonFlag to 0
                            //so the lights can be turned off

    P1IFG &= ~(BIT3);       //reset the register flag
    P1IES ^= BIT3;         //change the interruption detection
}

#pragma vector = TIMER0_A1_VECTOR
void waitTimer0(unsigned int time){
    int i,j;
    for(i = 0;i<time;i++){
        j = 0;
        do{
            j++;
        }while(j<2420);
    }
}

#pragma vector = TIMER1_A1_VECTOR
void waitTimer1(unsigned int time){
    int i = 0;
    do{
        i++;
    }while(i<time);
}

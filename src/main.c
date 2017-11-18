#include <msp430.h> 
#include "PWMLED.h"
#include "utils.h"
#include "interruption.h"
#include "afficheur.h"
#include "test.h"   // for hardware and functional tests

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    /*
     * Global variables
     */
    volatile int minute = 0;            //The time in minutes
    volatile bool buttonFlag;           //button not pushed
    buttonFlag = false;                 //Initialize this buttonFlag to unpushed

    /*
     * Internal variables
     */
    int alarmTime = 360;                // Alarm in minutes

    /*
     * Initialization GPIO,PWM,Interruptions
     */
    initEntree(1,BIT3);                 // P1.3 as an input
    initButton();                       // initialize the interruption on touche button P1.3
    initPWM();                          // PWM on LEDs
    Aff_Init();                         // Initialize the display
    __enable_interrupt();

    while(1){
        if(minute >= 1440){             //1440 = 24 * 60 is above the max value of clock in minutes
            minute -= 1440;
        }
        showTime(minute);
        lightAdjust(minute,alarmTime);
        minute++;
        waitTimer0(5000);
    }

    return 0;
}

#include <msp430.h>
#include "PWMLED.h"
#include "afficheur.h"
/*
 * test.c
 *
 *  Created on: Nov 17, 2017
 *      Author: Wen
 */
/*
 * testLEDConnected : tests if the LED is connected without using interruption
 */
void testLEDConnected(){
    if((P1IN & BIT3) == 0){
          LEDLightUp();
      }
      else{
          LEDControl(10);
      }
}
/*
 * testAffConnected : tests if display works
 * this test should show 1234 on the display
 */
void testAffConnected(){
    Aff_valeur_decimal(1234);

}

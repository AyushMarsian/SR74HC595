/*  Copyright to AyushMarsian(Ankit Ghevariya)
 *  Licence GNU GPL V3
 *  
 *  Example for use shift register with Arduino UNO
 *  Written by Ankit Ghevariya, public domain
 *  
 *  You have to connect pin as written below 
 *  (74HC595) --------- (Arduino)
 *   Vcc      --------> 5v 
 *   MR       --------> 5v
 *   DS       --------> Digital 5
 *   SH_CP    --------> Digital 6
 *   ST_CP    --------> Digital 7
 *   OE       --------> Gnd
 *   Gnd      --------> Gnd
 */

#include <SR74HC595.h>

SR74HC595 SR(5,6,7); // Data :5, Clock :6, Latch :7

uint8_t count=0;

void setup() 
{
  SR.sendToShiftRegister(0x00); // Set all output pin of shift register to 0.
}

void loop() 
{
  count=0x01;
  for(uint8_t i=0;i<8;i++)
  {
    SR.sendToShiftRegister(count);
    count = (count<<1);
    delay(500);
  }
}

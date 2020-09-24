/*  Copyright to AyushMarsian(Ankit Ghevariya)
 *  Licence GNU GPL V3
 *  
 *  Example for use two shift register in Cascade wiring
 *  Written by Ankit Ghevariya, public domain
 *  
 *  You have to connect pin as written below for chip 1
 *  (74HC595) --------- (Arduino)
 *   Vcc      --------> 5v 
 *   MR       --------> 5v
 *   DS       --------> Digital 5
 *   SH_CP    --------> Digital 6
 *   ST_CP    --------> Digital 7
 *   OE       --------> Gnd
 *   Gnd      --------> Gnd

 *  You have to connect pin as written below for chip 2
 *  (74HC595) --------- (Arduino)
 *   Vcc      --------> 5v 
 *   MR       --------> 5v
 *   DS       --------> Q7' (Note you have to use Q7' pin of chip 1)
 *   SH_CP    --------> Digital 6
 *   ST_CP    --------> Digital 7
 *   OE       --------> Gnd
 *   Gnd      --------> Gnd
 */

#include <SR74HC595.h>

SR74HC595 SR(5,6,7); // Data :5, Clock :6, Latch :7

uint8_t count[2]={0x00,0x00};


void setup() 
{
  SR.sendToShiftRegister(count,2); // Set all output pin of shift register to 0.
}

void loop() 
{
  count[0] = 0x01;
  for(uint8_t j=0;j<8;j++)
  {
    count[1] = 0x01;
    for(uint8_t i=0;i<8;i++)
    {
      SR.sendToShiftRegister(count,2);
      count[1] = (count[1]<<1);
      delay(500);
    }
    count[0] = (count[0]<<1);
  }
}

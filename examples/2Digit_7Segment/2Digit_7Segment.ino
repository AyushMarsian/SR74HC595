/*  Copyright to AyushMarsian(Ankit Ghevariya)
 *  Licence GNU GPL V3
 *  
 *  Example for interface two digit 7 segment display with Arduino UNO using 74HC595
 *  Written by Ankit Ghevariya, public domain
 *  
 *  You have to connect pin as written below for IC 1
 *  (74HC595) --------- (Arduino)
 *   Vcc      --------> 5v 
 *   MR       --------> 5v
 *   DS       --------> Digital 5
 *   SH_CP    --------> Digital 6
 *   ST_CP    --------> Digital 7
 *   OE       --------> Gnd
 *   Gnd      --------> Gnd

 *  You have to connect pin as written below for IC 2
 *  (74HC595) --------- (Arduino)
 *   Vcc      --------> 5v 
 *   MR       --------> 5v
 *   DS       --------> Q7' (Note you have to use Q7' pin of IC 1)
 *   SH_CP    --------> Digital 6
 *   ST_CP    --------> Digital 7
 *   OE       --------> Gnd
 *   Gnd      --------> Gnd

 *  You have to connect Seven Segment display as mentioned below
 *  (Display)  -------- (74HC595)
 *  Segment A  -------> Q0 of IC 2
 *  Segment B  -------> Q1 of IC 2
 *  Segment C  -------> Q2 of IC 2
 *  Segment D  -------> Q3 of IC 2
 *  Segment E  -------> Q4 of IC 2
 *  Segment F  -------> Q5 of IC 2
 *  Segment G  -------> Q6 of IC 2
 *
 *  Common 1   -------> Q0 of IC 1
 *  Common 2   -------> Q1 of IC 1
 */

#include <SR74HC595.h>

SR74HC595 SR(5,6,7); // Data :5, Clock :6, Latch :7

uint8_t digit1[2]={0xFF,0xFF};
uint8_t digit2[2]={0xFF,0xFF};

//uint8_t segment[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // Common Cathode
uint8_t segment[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; // Common Anode

uint8_t count=0x00;

uint32_t countDelay=0;

void printDigit(uint8_t _data)
{
  digit1[1]=0x02;
  digit1[0]=segment[_data%10];
  digit2[1]=0x01;
  digit2[0]=segment[_data/10];
  SR.sendToShiftRegister(digit1,2);
  SR.sendToShiftRegister(digit2,2);
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("CPU come out from Reset");
  Serial.print("\r\nCount :");
  Serial.println(count);
}

void loop() 
{
  printDigit(count);

  if((millis()-countDelay)>1000)
  {
    countDelay = millis();
    count++;
    if(count>99)
    {
      count=0;
    }

    Serial.print("Count :");
    Serial.println(count);
  }
}

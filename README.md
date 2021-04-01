# SR74HC595
An Arduino Library for interface 74HC595, compatible with Arduino UNO, MEGA, DUO, ESP8266, ESP32

## Download and Install.
[Download](https://github.com/AyushMarsian/SR74HC595/archive/master.zip), then rename the uncompressed folder to **SR74HC595**. 

Go to arduino IDE Sketch >> Import Library >> add library... Select the folder SR74HC595

OR 

Place the SR74HC595 library folder into your \Documents\Arduino\libraries folder. 
You may need to create the libraries subfolder if its your first library. Restart the IDE.

## Encoragement

Encourage us by donating a penny

[![Donate](https://img.shields.io/badge/Donate-Paypal-blue.svg)](https://www.paypal.com/paypalme/Ayushmarsian)

## Connections & pinouts
Arduino UNO  |   74HC595   |    Notes  
-------------|-------------|------------
5v           | Vcc         | Power supply input
D5           | DS          | You can change this pin in example code as per your requirement 
D6           | SH_CP       | You can change this pin in example code as per your requirement
D7           | ST_CP       | You can change this pin in example code as per your requirement
GND          | GND         | Required common ground

## Methods and functions

Name   |Return |  Notes
-------|-------|-----------------------------------------------|
sendToShiftRegister(data)        |void|For send data to shift register and set output of it accordingly

## Basic wiring diagram
![alt text](https://github.com/AyushMarsian/SR74HC595/blob/master/Images/Single%20Shift%20Register.png "Basic_Circuit")

## Copyright and license

- Copyright (c) 2021 [Ankit Ghevariya](https://github.com/ayushmarsian)
- Licensed under GPL-3.0 ([LICENSE](https://github.com/AyushMarsian/SR74HC595/blob/master/LICENSE))

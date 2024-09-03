/*
   Example with 4 Flipdigits in series

   Created on: 3 Sept. 2024
   Author: TinyTronics
*/

#include <Arduino.h>
#include "FlipDigitDriver.h"


int latchPin = 5;     // Can be any output pin
int clockPin = 4;     // Can be any output pin
int dataPin = 2;      // Can be any output pin

int Digitwidth = 4;   // Change this to the number of digits being used


FlipDigitDriver display;

void setup()
{
  display.begin(latchPin, clockPin, dataPin, Digitwidth);
}

void loop()
{
  int frame_delay_simple = 1000;

  display.setDigits("0000");
  display.frameDelay(frame_delay_simple);
  display.setDigits("1111");
  display.frameDelay(frame_delay_simple);
  display.setDigits("2222");
  display.frameDelay(frame_delay_simple);
  display.setDigits("3333");
  display.frameDelay(frame_delay_simple);
  display.setDigits("4444");
  display.frameDelay(frame_delay_simple);
  display.setDigits("5555");
  display.frameDelay(frame_delay_simple);
  display.setDigits("6666");
  display.frameDelay(frame_delay_simple);
  display.setDigits("7777");
  display.frameDelay(frame_delay_simple);
  display.setDigits("8888");
  display.frameDelay(frame_delay_simple);
  display.setDigits("9999");
  display.frameDelay(frame_delay_simple);
}

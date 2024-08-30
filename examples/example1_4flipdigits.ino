#include <Arduino.h>
#include "FlipDigit.h"

//Example with 4 flipdigits in series

#if defined(ESP32)
int latchPin = 32;
int clockPin = 25;
int dataPin = 26;
#else // e.g. Arduino Uno or Arduino Mega
int latchPin = 6;
int clockPin = 5;
int dataPin = 4;
#endif


FlipDigit display;
int Digitwidth = 4;

void setup() 
{
 display.begin(latchPin, clockPin, dataPin, Digitwidth);
   display.setDigits("8888");
  delay(1000);
  display.setDigits("    ");
  delay(1000);

  display.setDigits("BY  ");
  delay(1000);
  display.setDigits("YUN ");
  delay(1000);

}

void loop() 
{

  int frame_delay_simple = 1000; 

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



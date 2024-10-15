/*
 * FlipDigitDriver.cpp
 *
 *  Created on: 9 aug. 2024
 *      Author: TinyTronics
 */
#include "FlipDigitDriver.h"
#include <Arduino.h>

const uint16_t FlipDigitDriver::SEGMENT_A     = 0x0200;
const uint16_t FlipDigitDriver::SEGMENT_A_INV = 0x0400;
const uint16_t FlipDigitDriver::SEGMENT_B     = 0x0800;
const uint16_t FlipDigitDriver::SEGMENT_B_INV = 0x1000;
const uint16_t FlipDigitDriver::SEGMENT_C     = 0x2000;
const uint16_t FlipDigitDriver::SEGMENT_C_INV = 0x4000;
const uint16_t FlipDigitDriver::SEGMENT_D     = 0x0004;
const uint16_t FlipDigitDriver::SEGMENT_D_INV = 0x0008;
const uint16_t FlipDigitDriver::SEGMENT_E     = 0x0040;
const uint16_t FlipDigitDriver::SEGMENT_E_INV = 0x0080;
const uint16_t FlipDigitDriver::SEGMENT_F     = 0x0010;
const uint16_t FlipDigitDriver::SEGMENT_F_INV = 0x0020;
const uint16_t FlipDigitDriver::SEGMENT_G     = 0x0001;
const uint16_t FlipDigitDriver::SEGMENT_G_INV = 0x0002;
const uint16_t FlipDigitDriver::TRIGGER       = 0x8000;

void FlipDigitDriver::begin(int latchPin, int clockPin, int dataPin, int DigitWidth) {
    _latchPin = latchPin;
    _clockPin = clockPin;
    _dataPin = dataPin;
    _DigitWidth = DigitWidth; 
    pinMode(_latchPin, OUTPUT);
    pinMode(_clockPin, OUTPUT);
    pinMode(_dataPin, OUTPUT);

    _segment_array = new uint16_t[_DigitWidth];
	for (int i = 0; i < _DigitWidth; i++) {
        _segment_array[i] = 0;
    }
}

FlipDigitDriver::FlipDigitDriver() {

}

FlipDigitDriver::~FlipDigitDriver() {
	delete[] _segment_array;
}

uint16_t FlipDigitDriver::getDigitByte(char digit) 
  {
  switch(digit) {
    case '0':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case '1':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G_INV;
    case '2':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case '3':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G    ;
    case '4':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case '5':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case '6':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case '7':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G_INV;
    case '8':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case '9':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case 'A':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'a':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case 'b':
      return SEGMENT_A_INV     + SEGMENT_B_INV    + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F + SEGMENT_G    ;
    case 'C':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'c':
      return SEGMENT_A+ SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F + SEGMENT_G_INV   ;
    case 'D':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case 'E':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'F':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'G':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'H':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'h':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'I':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'J':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G_INV;
    case 'L':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'N':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'n':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case 'O':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'o':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case 'P':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'Q':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C     + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case 'R':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'r':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case 'S':
      return SEGMENT_A     + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case 'T':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G    ;
    case 'U':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F     + SEGMENT_G_INV;
    case 'u':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C     + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G_INV;
    case 'Y':
      return SEGMENT_A_INV + SEGMENT_B     + SEGMENT_C     + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F     + SEGMENT_G    ;
    case 'Z':
      return SEGMENT_A     + SEGMENT_B     + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E     + SEGMENT_F_INV + SEGMENT_G    ;
    case '-':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G    ;
    case '_':
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D     + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G_INV;
    default:
      return SEGMENT_A_INV + SEGMENT_B_INV + SEGMENT_C_INV + SEGMENT_D_INV + SEGMENT_E_INV + SEGMENT_F_INV + SEGMENT_G_INV;
  }
}

void FlipDigitDriver::updateSegments(){
  digitalWrite(_latchPin, LOW);
  for (int k = 0; k < _DigitWidth; k++)
  {
    shiftOut(_dataPin, _clockPin, LSBFIRST, (byte)_segment_array[k]);
    shiftOut(_dataPin, _clockPin, LSBFIRST, (byte)(_segment_array[k] >> 8));
  }
  digitalWrite(_latchPin, HIGH);
  delay(3);
}

void FlipDigitDriver::resetSegmentsTrigger()
{
  digitalWrite(_latchPin, LOW);
  for (int k = 0; k < _DigitWidth; k++)
  {
    shiftOut(_dataPin, _clockPin, LSBFIRST, 0x00);
    shiftOut(_dataPin, _clockPin, LSBFIRST, 0x00);
  }
  digitalWrite(_latchPin, HIGH);
  delay(1);
}

void FlipDigitDriver::frameDelay(int delay_ms){
  if((delay_ms - 3 - 1) > 0) {
    delay((delay_ms - 3 - 1));
  }
}

void FlipDigitDriver::setDigits(char segmentDigits[])
{
  for (int k = 0; k < _DigitWidth; k++)
  {
    uint16_t digit_data = getDigitByte(segmentDigits[k]);
    _segment_array[k] = ((digit_data ^ _segment_array[k]) & digit_data) | TRIGGER;
  }

  updateSegments();
  resetSegmentsTrigger();
}

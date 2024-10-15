/*
 * FlipDigitDriver.cpp
 *
 *  Created on: 9 aug. 2024
 *      Author: TinyTronics
 */
// FlipDigitDriver.h

#ifndef FlipDigitDriver_H
#define FlipDigitDriver_H

#include <Arduino.h>

class FlipDigitDriver {
public:
    FlipDigitDriver();
    ~FlipDigitDriver();
    void begin(int latchPin, int clockPin, int dataPin,  int _DigitWidth );
    void clearDisplay(void);
    void setDigits(char segmentDigits[]);
     void frameDelay(int delay_ms); 

private:
    int _latchPin, _clockPin, _dataPin, _DigitWidth;
    uint16_t* _segment_array;
    uint16_t getDigitByte(char digit);
    void updateSegments();
    void resetSegmentsTrigger();
    static const uint16_t SEGMENT_A;
    static const uint16_t SEGMENT_A_INV;
    static const uint16_t SEGMENT_B;
    static const uint16_t SEGMENT_B_INV;
    static const uint16_t SEGMENT_C;
    static const uint16_t SEGMENT_C_INV;
    static const uint16_t SEGMENT_D;
    static const uint16_t SEGMENT_D_INV;
    static const uint16_t SEGMENT_E;
    static const uint16_t SEGMENT_E_INV;
    static const uint16_t SEGMENT_F;
    static const uint16_t SEGMENT_F_INV;
    static const uint16_t SEGMENT_G;
    static const uint16_t SEGMENT_G_INV;
    static const uint16_t TRIGGER;
};

#endif // FlipDigitDriver_H

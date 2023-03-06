#ifndef Track_h
#define Track_h

#include "Arduino.h"
#include "FastLED.h"

class Track
{
    public:
        CRGB *leds;

        Track();
        Track(CRGB *ledsPointer);
        ValidateLED();
};

#endif
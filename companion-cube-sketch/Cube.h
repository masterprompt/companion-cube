#ifndef Cube_h
#define Cube_h

#include "Arduino.h"
#include "FastLED.h"
#include "Track.h"

class Cube
{
    public:
        CRGB leds[10];
        Track *track;
        Cube();
        ValidateLED();
};

#endif
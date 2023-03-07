#ifndef Track_h
#define Track_h

#include "FastLED.h"

enum TrackPosition {
    CenterPosition = 0,
    EdgePosition = 1
};

class Track
{
    public:
        CRGB *leds[2];

        Track();
        AddLEDs(CRGB * ledsPointer);
        SetColor(TrackPosition position, CRGB color);
        SetColor(CRGB color);
};

#endif
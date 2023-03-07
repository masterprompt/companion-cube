#ifndef ColorRange_h
#define ColorRange_h

#include "FastLED.h"

class ColorRange
{
    public:
        CRGB colorStart;
        CRGB colorEnd;
        SetColors(CRGB c1, CRGB c2);
        CRGB Interpolate(float delta);
};

#endif
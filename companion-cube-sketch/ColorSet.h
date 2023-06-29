#ifndef ColorSet_h
#define ColorSet_h

#include "FastLED.h"

class ColorSet
{
    public:
        ColorSet();
        CRGB NextColor();
    private:
        int _max;
        int _index;
        CRGB _colors[3];
};

#endif
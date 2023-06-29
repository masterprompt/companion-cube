#include "ColorSet.h"
#include "FastLED.h"

ColorSet::ColorSet()
{
    _max = 3;
    _index = 0;
    _colors[0] = CRGB::Red;
    _colors[1] = CRGB::Blue;
    _colors[2] = CRGB::Green;
}

CRGB ColorSet::NextColor()
{
    CRGB color = _colors[_index];
    _index++;
    if (_index >= _max) {
        _index = 0;
    }
    return color;
}
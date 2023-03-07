#include "ColorRange.h"
#include "FastLED.h"
#include "math.h"

ColorRange::SetColors(CRGB c1, CRGB c2)
{
    colorStart = c1;
    colorEnd = c2;
}

CRGB ColorRange::Interpolate(float delta)
{
    if (delta < 0) {
        return colorStart;
    }
    if (delta > 1) {
        return colorEnd;
    }

    float r = colorEnd.r - colorStart.r;
    float g = colorEnd.g - colorStart.g;
    float b = colorEnd.b - colorStart.b;

    return CRGB( colorStart.r + ceil(r * delta), colorStart.g + ceil(g * delta), colorStart.b + ceil(b * delta));
}



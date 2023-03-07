#include "Track.h"
#include "FastLED.h"
#include "Arduino.h"

Track::Track()
{
}

Track::AddLEDs(CRGB *ledsPointer)
{
    leds[(int)TrackPosition::CenterPosition] = ledsPointer;
    leds[(int)TrackPosition::EdgePosition] = ledsPointer + 1;
}

Track::SetColor(TrackPosition position, CRGB color)
{
    CRGB *led = leds[(int)position];
    *led = color;
}

Track::SetColor(CRGB color)
{
    SetColor((int)TrackPosition::CenterPosition, color);
    SetColor((int)TrackPosition::EdgePosition, color);
}
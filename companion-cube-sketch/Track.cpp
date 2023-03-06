#include "Track.h"
#include "Arduino.h"
#include "FastLED.h"

Track::Track()
{

}

Track::Track(CRGB *ledsPointer)
{
    leds = ledsPointer;
}

Track::ValidateLED()
{
    Serial.println((long)leds);
}
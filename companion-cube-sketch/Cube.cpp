#include "Cube.h"
#include "FastLED.h"
#include "Arduino.h"
#include "Track.h"

Cube::Cube()
{
    track = new Track(&leds[4]);
}

Cube::ValidateLED()
{
   Serial.println((long)&leds[4]);
   track->ValidateLED();
}

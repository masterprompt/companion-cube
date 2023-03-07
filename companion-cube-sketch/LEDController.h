#ifndef LEDController_h
#define LEDController_h

#include "FastLED.h"

#define NUM_LEDS 48
#define DATA_PIN 2
#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define BRIGHTNESS 255
#define VOLTS 5
#define MAX_AMPS 3300

class LEDController
{
    public:
        CRGB leds[NUM_LEDS];
        LEDController();
        Setup();
        Update();
};

#endif
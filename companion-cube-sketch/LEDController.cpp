#include "LEDController.h"
#include "FastLED.h"

LEDController::LEDController()
{
}

LEDController::Setup()
{
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
    FastLED.show();
}

LEDController::Update()
{
    FastLED.show();
}

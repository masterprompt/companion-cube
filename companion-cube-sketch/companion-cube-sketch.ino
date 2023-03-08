#include "Cube.h"
#include "LEDController.h"
#include "Timer.h"
#include "FastLED.h"
#include "ColorRange.h"
#include "Breathe.h"
#include "Test.h"

Cube cube;
LEDController ledController;
Timer timer;
ColorRange colorRange;
Breathe breathe;
Test test;

void setup() {
  ledController.Setup();
  cube.AddLEDs(ledController.leds);
  breathe.Setup(&cube);
  test.Setup(&cube);
  Serial.begin(115200);
  timer.Start(7000);
  colorRange.SetColors(CRGB(0,0,0), CRGB::Red);
}

void loop() {
  //CRGB color = CRGB(random(0, 255), random(0, 255), random(0, 255));

  //cube.SetColor(colorRange.Interpolate(timer.Loop()));
  test.Loop();
  ledController.Update();
  delay(1);
}

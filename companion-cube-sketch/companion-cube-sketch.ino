#include "Cube.h"
#include "LEDController.h"
#include "Timer.h"
#include "FastLED.h"
#include "ColorRange.h"
#include "Breathe.h"

Cube cube;
LEDController ledController;
Timer timer;
ColorRange colorRange;

Breathe breathe;

void setup() {
  ledController.Setup();
  cube.AddLEDs(ledController.leds);
  breathe.Setup(cube);
  Serial.begin(115200);
  timer.Start(7000);
  colorRange.SetColors(CRGB(0,0,0), CRGB(200,0,0));
}

void loop() {
  //CRGB color = CRGB(random(0, 255), random(0, 255), random(0, 255));

  //cube.SetColor(colorRange.Interpolate(timer.Loop()));
  breathe.Loop();
  ledController.Update();
  delay(1);
}

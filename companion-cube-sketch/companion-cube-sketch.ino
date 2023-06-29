#include "Cube.h"
#include "LEDController.h"
#include "Timer.h"
#include "FastLED.h"
#include "ColorRange.h"
#include "Breathe.h"
#include "Test.h"
#include "Spin.h"
#include "Button.h"
#include "ColorSet.h"
#include "ModeController.h"
#include "LinkedList.h"
#include "LinkedPointerList.h"
#include "Mode.h"
#include "TwoColorCollection.h"

Cube cube;
LEDController ledController;
Timer timer;
ColorRange colorRange;
Breathe breathe;
Test test;
Spin spin;
Button colorButton;
Button modeButton;
ColorSet colorSet;
ModeController modeController;

const int colorPin = 4;
const int modePin = 3;

void setup() {
  colorButton.Setup(colorPin);
  modeButton.Setup(modePin);
  ledController.Setup();
  cube.AddLEDs(ledController.leds);
  breathe.Setup(&cube);
  spin.Setup(&cube);
  test.Setup(&cube);
  Serial.begin(115200);
  timer.Start(7000);
  colorRange.SetColors(CRGB(0,0,0), CRGB::Red);
  modeController.AddMode(&breathe);
  modeController.AddMode(&spin);
  modeController.AddMode(&test);
}

void loop() {
  
  if (colorButton.WasPressed()) {
    modeController.NextConfiguration();
  }
  
  if (modeButton.WasPressed()) {
    modeController.Next();
  }
  modeController.Loop();
  ledController.Update();
  modeButton.Loop();
  colorButton.Loop();
  delay(1);
}

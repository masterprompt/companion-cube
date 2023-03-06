#include "Cube.h"

Cube cube;

void setup() {
  Serial.begin(115200);
  cube = Cube();
}

void loop() {
  cube.ValidateLED();
  delay(1000);
}

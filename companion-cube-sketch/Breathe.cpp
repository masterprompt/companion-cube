#include "Timer.h"
#include "ColorRange.h"
#include "Breathe.h"
#include "Cube.h"
#include "Arduino.h"

Breathe::Breathe()
{
    _colorCollection.add(CRGB::Red, CRGB::Blue);
    _colorCollection.add(CRGB::Black, CRGB::Red);
    _colorCollection.add(CRGB::Black, CRGB::Green);
    _colorCollection.add(CRGB::Black, CRGB::Orange);
    _colorCollection.add(CRGB::Black, CRGB::Blue);
    _colorCollection.add(CRGB::Black, CRGB::MediumPurple);
    _colorCollection.add(CRGB::Black, CRGB::White);
    
    colorRange.SetColors(_colorCollection.c1, _colorCollection.c2);
    timer.Start(7000);
}

Breathe::Setup(Cube *cube)
{
    _cube = cube;
    timer.Reset();
}

void Breathe::Loop()
{
    Cube *cube = _cube;
    (*cube).SetColor(colorRange.Interpolate(timer.Loop()));
}

void Breathe::NextConfiguration()
{
    _colorCollection.nextColor();
    colorRange.SetColors(_colorCollection.c1, _colorCollection.c2);
}
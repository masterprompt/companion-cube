#include "Timer.h"
#include "ColorRange.h"
#include "Breathe.h"
#include "Cube.h"

Breathe::Breathe()
{
    colorRange.SetColors(CRGB(0,0,0), CRGB(200,0,0));
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
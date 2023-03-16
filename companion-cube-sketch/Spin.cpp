#include "Timer.h"
#include "ColorRange.h"
#include "Spin.h"
#include "Cube.h"
#include "Track.h"

Spin::Spin()
{
    
    _index = 0;
    colorRanges[0].SetColors(CRGB(0,0,0), CRGB(200,0,0));
    colorRanges[1].SetColors(CRGB(150,0,0), CRGB(40,0,0));
    colorRanges[2].SetColors(CRGB(40,0,0), CRGB(0,0,0));
    colorRanges[3].SetColors(CRGB(0,0,0), CRGB(0,0,0));
    fadeTimer.Start(50);
    _speedIncrement = 50;
    _speed = 100;
    _direction = 1;
}

Spin::Setup(Cube *cube)
{
    _cube = cube;
    fadeTimer.Reset();
    speedTimer.Start(10000);
}

void Spin::UpdateFaces(TrackDirection trackDirection, unsigned short index, float delta)
{
    if (index > 3) {
        index = index - 4;
    }
    Cube *cube = _cube;
    (*cube).SetColor(trackDirection, colorRanges[index].Interpolate(delta));
}

void Spin::Loop()
{
    float speedScale = speedTimer.Loop();

    float delta = fadeTimer.Delta();
    if (delta > 1) {
        fadeTimer.Start((speedScale * 1000) + 5);
        _index++;
        if (_index > 3) {
            _index = 0;
        }
        delta = 0;
    }
    UpdateFaces(TrackDirection::North, _index, delta);
    UpdateFaces(TrackDirection::East, _index + 1, delta);
    UpdateFaces(TrackDirection::South, _index + 2, delta);
    UpdateFaces(TrackDirection::West, _index + 3, delta);
}
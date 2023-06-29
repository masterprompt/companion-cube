#include "Timer.h"
#include "ColorRange.h"
#include "Spin.h"
#include "Cube.h"
#include "Track.h"

Spin::Spin()
{
    _colorCollection.add(CRGB::Red, CRGB::Blue);
    _colorCollection.add(CRGB::Black, CRGB::Red);
    _colorCollection.add(CRGB::Black, CRGB::Green);
    _colorCollection.add(CRGB::Black, CRGB::Orange);
    _colorCollection.add(CRGB::Black, CRGB::Blue);
    _colorCollection.add(CRGB::Black, CRGB::MediumPurple);
    _colorCollection.add(CRGB::Black, CRGB::White);

    _index = 0;
    _setupColoring();
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

void Spin::_setupColoring()
{
    ColorRange colorRange;
    colorRange.SetColors(_colorCollection.c1, _colorCollection.c2);
    colorRanges[0].SetColors(colorRange.Interpolate(0), colorRange.Interpolate(1));
    colorRanges[1].SetColors(colorRange.Interpolate(0.5), colorRange.Interpolate(0.15));
    colorRanges[2].SetColors(colorRange.Interpolate(0.15), colorRange.Interpolate(0));
    colorRanges[3].SetColors(colorRange.Interpolate(0), colorRange.Interpolate(0));
}

void Spin::NextConfiguration()
{
    _colorCollection.nextColor();
    _setupColoring();
}
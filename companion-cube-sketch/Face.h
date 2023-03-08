#ifndef Face_h
#define Face_h

#include "FastLED.h"
#include "Track.h"

enum TrackDirection {
    North = 0,
    East = 1,
    South = 2,
    West = 3
};

class Face
{
    public:
        Track tracks[4];
        Face();
        AddLEDs(CRGB * ledsPointer, int pattern);
        SetColor(TrackDirection trackDirection, CRGB color);
        SetColor(CRGB color);
        SetColor(CRGB colors[4]);
        Track GetTrack(TrackDirection trackDirection);
};

#endif
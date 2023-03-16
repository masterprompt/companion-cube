#ifndef Cube_h
#define Cube_h

#include "FastLED.h"
#include "Track.h"
#include "Face.h"

enum FaceDirection {
    Top = 0,
    Front = 1,
    Right = 2,
    Left = 3,
    Bottom = 4,
    Back = 5
};

class Cube
{
    public:
        Face faces[6];
        Cube();
        AddLEDs(CRGB * ledsPointer);
        SetColor(CRGB color);
        SetColor(FaceDirection faceDirection, CRGB color);
        SetColor(FaceDirection faceDirection, CRGB colors[4]);
        SetColor(FaceDirection faceDirection, TrackDirection trackDirection, CRGB color);
        SetColor(TrackDirection trackDirection, CRGB color);
        Face GetFace(FaceDirection faceDirection);
};

#endif
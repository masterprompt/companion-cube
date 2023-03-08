#include "Cube.h"
#include "FastLED.h"
#include "Track.h"
#include "Face.h"

Cube::Cube()
{
}

Cube::AddLEDs(CRGB * ledsPointer)
{
    faces[(int)FaceDirection::Front].AddLEDs(ledsPointer, 2);
    faces[(int)FaceDirection::Right].AddLEDs(ledsPointer + 8, 1);
    faces[(int)FaceDirection::Bottom].AddLEDs(ledsPointer + 16, 0);
    faces[(int)FaceDirection::Left].AddLEDs(ledsPointer + 24, 3);
    faces[(int)FaceDirection::Top].AddLEDs(ledsPointer + 32, 2);
    faces[(int)FaceDirection::Back].AddLEDs(ledsPointer + 40, 0);
}

Face Cube::GetFace(FaceDirection faceDirection)
{
    return faces[(int)faceDirection];
}

Cube::SetColor(FaceDirection faceDirection, CRGB color) {
    GetFace(faceDirection).SetColor(color);
}

Cube::SetColor(CRGB color)
{
    SetColor(FaceDirection::Top, color);
    SetColor(FaceDirection::Front, color);
    SetColor(FaceDirection::Right, color);
    SetColor(FaceDirection::Left, color);
    SetColor(FaceDirection::Bottom, color);
    SetColor(FaceDirection::Back, color);
}

Cube::SetColor(FaceDirection faceDirection, CRGB colors[4])
{
    GetFace(faceDirection).SetColor(colors);
}


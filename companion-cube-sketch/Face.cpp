#include "Face.h"
#include "FastLED.h"
#include "Track.h"

Face::Face()
{
}

Track Face::GetTrack(TrackDirection trackDirection)
{
    return tracks[(int)trackDirection];
}

Face::AddLEDs(CRGB *ledsPointer)
{
    tracks[(int)TrackDirection::North].AddLEDs(ledsPointer);
    tracks[(int)TrackDirection::East].AddLEDs(ledsPointer + 2);
    tracks[(int)TrackDirection::South].AddLEDs(ledsPointer + 4);
    tracks[(int)TrackDirection::West].AddLEDs(ledsPointer + 6);
}

Face::SetColor(TrackDirection trackDirection, CRGB color)
{
    GetTrack(trackDirection).SetColor(color);
}

Face::SetColor(CRGB color)
{
    SetColor(TrackDirection::North, color);
    SetColor(TrackDirection::East, color);
    SetColor(TrackDirection::South, color);
    SetColor(TrackDirection::West, color);
}


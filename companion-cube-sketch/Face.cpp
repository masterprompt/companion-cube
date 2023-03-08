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

Face::AddLEDs(CRGB *ledsPointer, int pattern)
{
    int maps[][4] = {
        {North, West, South, East},
        {East, North, West, South},
        {South, East, North, West},
        {West, South, East, North}
    };
    for(int i=0; i<4; i++)
    {
        int * map = maps[pattern];
        tracks[map[i]].AddLEDs(ledsPointer + (2 * i));
    }

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

Face::SetColor(CRGB colors[4])
{
    SetColor(TrackDirection::North, colors[0]);
    SetColor(TrackDirection::East, colors[1]);
    SetColor(TrackDirection::South, colors[2]);
    SetColor(TrackDirection::West, colors[3]);
}

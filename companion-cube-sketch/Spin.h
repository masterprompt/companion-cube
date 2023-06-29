#ifndef Spin_h
#define Spin_h

#include "Cube.h"
#include "Timer.h"
#include "ColorRange.h"
#include "Mode.h"
#include "Track.h"
#include "TwoColorCollection.h"

class Spin : public Mode
{
    public:
        Timer fadeTimer;
        Timer speedTimer;
        ColorRange colorRanges[4];
        Spin();
        Setup(Cube *cube);
        void Loop() override;
        void NextConfiguration() override;
        void UpdateFaces(TrackDirection trackDirection, unsigned short index, float delta);
    private:
        Cube * _cube;
        unsigned int _index;
        float _speed;
        signed int _direction;
        float _speedIncrement;
        TwoColorCollection _colorCollection;
        void _setupColoring();
};

#endif
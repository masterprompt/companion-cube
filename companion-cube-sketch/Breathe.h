#ifndef Breathe_h
#define Breathe_h

#include "Cube.h"
#include "Timer.h"
#include "ColorRange.h"


class Breathe
{
    public:
        Timer timer;
        ColorRange colorRange;
        Breathe();
        Setup(Cube *cube);
        Loop();
    private:
        Cube * _cube;
};

#endif
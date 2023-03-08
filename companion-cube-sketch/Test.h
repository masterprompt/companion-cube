#ifndef Test_h
#define Test_h

#include "Cube.h"
#include "FastLED.h"

class Test
{
    public:
        Test();
        Setup(Cube *cube);
        void Loop();
    private:
        Cube * _cube;
        CRGB _colors[4];
};

#endif
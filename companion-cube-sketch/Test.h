#ifndef Test_h
#define Test_h

#include "Cube.h"
#include "FastLED.h"
#include "Mode.h"

class Test : public Mode
{
    public:
        Test();
        Setup(Cube *cube);
        void Loop() override;
        void NextConfiguration() override;
    private:
        Cube * _cube;
        CRGB _colors[4];
};

#endif
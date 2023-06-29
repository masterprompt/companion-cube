#ifndef Breathe_h
#define Breathe_h

#include "Cube.h"
#include "Timer.h"
#include "ColorRange.h"
#include "Mode.h"
#include "TwoColorCollection.h"

class Breathe : public Mode
{
    public:
        Timer timer;
        ColorRange colorRange;
        Breathe();
        Setup(Cube *cube);
        void Loop() override;
        void NextConfiguration() override;
    private:
        Cube * _cube;
        TwoColorCollection _colorCollection;
};

#endif
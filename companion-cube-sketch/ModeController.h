#ifndef ModeController_h
#define ModeController_h

#include "Mode.h"
#include "LinkedList.h"

class ModeController
{
    public:
        ModeController();
        void AddMode(Mode* mode);
        void Loop();
        void Next();
        void NextConfiguration();
    public:
        LinkedList<Mode*> _modes;
        int _current { 0 };
};

#endif
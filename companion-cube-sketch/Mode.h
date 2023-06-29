#ifndef Mode_h
#define Mode_h

#include "Arduino.h"

class Mode
{
    public:
        virtual void Loop()        
        {}
        virtual void NextConfiguration()
        {}
        
};

#endif
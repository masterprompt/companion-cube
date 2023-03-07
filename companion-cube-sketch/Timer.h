#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer
{
    public:
        unsigned long length;
        Timer();
        Start(unsigned long timerLength);
        Reset();
        unsigned long Millis();
        float Delta();
        float Loop();
    private:
        unsigned long _lastSample;
        unsigned long _startMillis;
};

#endif
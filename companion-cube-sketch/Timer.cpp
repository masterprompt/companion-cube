#include "Timer.h"

Timer::Timer()
{
    _startMillis = millis();
    _lastSample = _startMillis;
}

unsigned long Timer::Millis()
{
    unsigned long currentTime = millis();
    if (currentTime < _lastSample) {
        //  rollover issue
        //  https://roboticsbackend.com/arduino-millis-vs-micros/
        _lastSample = currentTime;
        _startMillis = currentTime;
    }
    return currentTime - _startMillis;
}


Timer::Start(unsigned long timerLength)
{
    length = timerLength;
    _startMillis = millis();
}

Timer::Reset()
{
    _startMillis = millis();
}

float Timer::Delta()
{
    if (length<=0) {
        return 0;
    }
    return Millis() / (float)length;
}

float Timer::Loop()
{
    float delta = Delta();
    if (delta >= 1) {
        Reset();
        return 0;
    }
    delta = delta * 2;
    if (delta >= 1) {
        return 2 - delta;
    } else {
        return delta;
    }
}
#include "Mode.h"
#include "ModeController.h"
#include "LinkedList.h"
#include "Arduino.h"

ModeController::ModeController()
{
    //_modes = new LinkedList<Mode>();
}

void ModeController::AddMode(Mode* mode)
{
    _modes.add(mode);
}

void ModeController::Next()
{
    _current++;
    if (_current >= _modes.size())
    {
        _current = 0;
    }
    
}

void ModeController::Loop()
{
    int size = _modes.size();

    if (size == 0) {
        return;
    }
    Mode* mode = _modes.get(_current);
    
    (*mode).Loop();
}


void ModeController::NextConfiguration()
{
    int size = _modes.size();

    if (size == 0) {
        return;
    }
    Mode* mode = _modes.get(_current);
    
    (*mode).NextConfiguration();
}
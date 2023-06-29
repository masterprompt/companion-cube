#include "Button.h"
#include "Arduino.h"

Button::Button()
{
}

Button::Setup(int pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
}

void Button::Loop()
{
    _lastState = _state;
    _state = digitalRead(_pin);
}

bool Button::IsDown()
{
    return _state == HIGH;
}

bool Button::WasPressed()
{
    return _state == LOW && _lastState == HIGH;
}
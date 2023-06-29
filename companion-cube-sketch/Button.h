#ifndef Button_h
#define Button_h

class Button
{
    public:
        Button();
        Setup(int pin);
        void Loop();
        bool IsDown();
        bool WasPressed();
    private:
        int _pin;
        int _state;
        int _lastState;
};

#endif
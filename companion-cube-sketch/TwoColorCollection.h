#ifndef TwoColorCollection_h
#define TwoColorCollection_h

#include "FastLED.h"
#include "LinkedList.h"

class TwoColorCollection
{
    public:
        CRGB c1 { CRGB::Black };
        CRGB c2 { CRGB::Red };
        void add(CRGB a, CRGB b){
            _aColors.add(a);
            _bColors.add(b);
        }
        void nextColor()
        {
            _index++;
            if (_index >= _aColors.size() ) {
                _index = 0;
            }
            c1 = _aColors.get(_index);
            c2 = _bColors.get(_index);
        }
    private:
        LinkedList<CRGB> _aColors;
        LinkedList<CRGB> _bColors;
        int _index { 0 };
};

#endif
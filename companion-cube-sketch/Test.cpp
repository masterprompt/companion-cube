#include "Test.h"
#include "Cube.h"

Test::Test()
{
}

Test::Setup(Cube *cube)
{
    _cube = cube;
    _colors[0] = CRGB::Red;
    _colors[1] = CRGB::Green;
    _colors[2] = CRGB::Blue;
    _colors[3] = CRGB::Gold;
}

void Test::Loop()
{
    Cube *cube = _cube;
    (*cube).SetColor(FaceDirection::Back, _colors);
    (*cube).SetColor(FaceDirection::Top, _colors);
    (*cube).SetColor(FaceDirection::Front, _colors);
    (*cube).SetColor(FaceDirection::Left, _colors);
    (*cube).SetColor(FaceDirection::Right, _colors);
}

void Test::NextConfiguration()
{

}
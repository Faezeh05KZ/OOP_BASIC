#include "star.hpp"
#include <iostream>

using namespace std;


Star::Star(int x , int y , int brightness)
{
    if (x < 0 || x >= 20)
    {
        throw invalid_argument("X coordinate must be between 0 and 19!");
    }
    if (y < 0 || y >= 10)
    {
        throw invalid_argument ("Y coordinate must be between 0 and 9!");
    }
    if (brightness < 0 || brightness > 10)
    {
        throw invalid_argument ("Brightness must be between 0 and 10!");
    }

    this-> x = x;
    this-> y = y;
    this-> Brightness = brightness;
}
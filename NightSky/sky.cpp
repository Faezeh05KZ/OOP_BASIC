#include "sky.hpp"
#include <iostream>


using namespace std;

void Sky::Add_star(const Star& star)
{
    stars.push_back(star) ;
}

void Sky::display() const
{
    char g[HEIGHT][WIDTH] ;
    for (int i = 0 ; i < HEIGHT ; i++ )
    {
        for (int j = 0 ; j < WIDTH ; j++ )
        {
            g[i][j] = ' ' ;
        }
    }

    for (const Star& star : stars)
    {
        g[star.get_y()][star.get_x()] = '*' ;
    }

    for (int i = 0 ; i < HEIGHT ; i++ )
    {
        for (int j = 0 ; j < WIDTH ; j++ )
        {
            cout << g[i][j] << " " ;
        }
        cout << endl;
    }
}
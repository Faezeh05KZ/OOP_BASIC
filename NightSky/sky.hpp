#ifndef SKY_HPP
#define SKY_HPP

#include "star.hpp"
#include <vector>
#include <iostream>

class Sky
{
    public:

        void Add_star(const Star& star) ;
        void display() const ;

    private:

        std::vector<Star> stars ;
        static const int WIDTH = 20 ;
        static const int HEIGHT = 10 ;
};

#endif
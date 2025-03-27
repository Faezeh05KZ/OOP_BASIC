#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include "Event.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <vector>


class Calendar
{
    friend class Event;
    public:
        
        void Add_Event ( const std::string& name_of_Event , time_t ST , time_t ET);
        void Refresh () ;
        void Print_Events () const;
        ~Calendar();
    private:
    
        std :: vector <Event> events ;
        bool is_Interference ( const Event& new_Event ) const ;
        

};

#endif
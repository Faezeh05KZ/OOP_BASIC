#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <ctime>
#include <string>
#include<vector>

class Event 
{
    public :
        Event(const std:: string& name_of_Event , time_t ST , time_t ET) ;
        ~Event () ;

        std :: string get_Name() const { return Name ; }
        time_t get_Start_time()  const { return Start_Time ;}
        time_t get_End_time()    const { return End_Time ;}
        bool isExpired()         const ;
        
    private :

        std :: string Name ;
        time_t Start_Time ;
        time_t End_Time ;

};

#endif
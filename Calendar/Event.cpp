#include "Event.hpp"
#include <iostream>
#include <string>

using namespace std;


Event :: Event (const string& name_of_Event, time_t ST, time_t ET)
{
    if ( ST >= ET )
    {
        throw invalid_argument( "Start time should be before the End time !!!" ) ;
    }
    
    Name       = name_of_Event ;
    Start_Time = ST ;
    End_Time   = ET ;
    
}

Event :: ~Event ()
{
        cout << "Evnet " << (this->Name) << "has been deleted !!!" << endl ;
}

bool Event :: isExpired() const 
{
    time_t now = time (nullptr) ;

    return End_Time < now ;
}
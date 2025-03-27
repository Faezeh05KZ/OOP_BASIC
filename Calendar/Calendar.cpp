#include "Calendar.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool Calendar :: is_Interference(const Event& new_Event ) const 
{
    for (const Event& e : events)
    {
        if (new_Event.get_Start_time() == e.get_End_time() && new_Event.get_End_time() == e.get_Start_time())
        {
            return true ;
        }
    }

    return false ;
}

void Calendar :: Add_Event(const string &name_of_Event , time_t ST , time_t ET )
{
    try
    {
        Event new_Event (name_of_Event , ST , ET ) ;

        if (is_Interference (new_Event))
        {
            cout << "Can't add " << name_of_Event << " Event because the event times overlap !!! " << endl ;

            return ;
        }

        events.push_back (new_Event) ;
        cout << name_of_Event << "Event added successfully !!! " << endl ;
    }

    catch (const invalid_argument& e)
    {
        cout << " Error Adding Event !!! " <<e.what() << endl ; 
    }
}

void Calendar :: Refresh()
{
    size_t main_size = events.size() ;
    events.erase (remove_if (events.begin () , events.end () , [] (const Event& e) { return e.isExpired() ; }) , events.end()) ;
    if ( main_size > events.size ())
    {
        cout << " Expired Event !!! " << endl ;
        return ; 
    }
}

void Calendar :: Print_Events() const 
{
    if (events.empty())
    {
        cout << "There is no Event in Calender !!! " << endl ; 
        return ; 
    }

    cout << "The Event is already current !!! " << endl ;

    for ( const Event& e : events )
    {
        time_t Start = e.get_Start_time() ;
        time_t End   = e.get_End_time() ;

        cout << e.get_Name() << " " << ctime (&Start) << " to " << ctime (&End) << "  " << endl ; 
    }
}
Calendar::~Calendar(){
    this->Refresh();
}




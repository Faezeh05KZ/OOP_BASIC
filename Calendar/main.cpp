#include "Calendar.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string insensitive (string N)
{
    for (char &c : N )
    {
        c = towlower(c) ;
    }

    return N ;
}

int main() 
{
    Calendar my_calendar;

    time_t now = time(nullptr);

    cout << "\t *** Welcome to My Calendar ***\n";

    cout << "Current time : " << ctime(&now) << endl ;

    while (true) 
    {
        cout << " Enter your choice : ";
        
        cout << " 1. Show events" << endl ;
        cout << " 2. Add event " << endl ;
        cout << " 3. Refresh calendar" << endl ;
        cout << " 4. If you want to quit Enter the 'Exit'" << endl ;

        
        string choice ;
        getline(cin , choice) ;
        choice = insensitive(choice) ;

        if (choice == "Show Events" || choice == "1")
        {
            my_calendar.Print_Events();
        }
        
        else if (choice == "Add Events" || choice == "2") 
        {
            string name;
            int start_time , length ;

            cout << " Enter event name: ";
            getline(cin, name);

            cout << " Enter start time (Seconds from now): " << endl ;

            if (!(cin >> start_time))
            {
                cout << "Invalid Start time " << endl ;
                cin.ignore() ;
                
                continue;
            }

            cout << " Enter duration (seconds): ";
            
            if (!(cin >> length)) 
            {
                cout << "Invalid duration!" << endl ;
                cin.ignore();

                continue;
            }

            time_t Start = now + start_time ;
            time_t End   = Start + length ;

            try 
            {
                my_calendar.Add_Event(name, Start, End);
            }

            catch (const invalid_argument& e) 
            {
                cout << " Error: " << "{" << e.what() << " }" << endl;
            }

            cin.ignore() ;
            }

            else if (choice == "Refresh Calendar" || choice == "3")
            {
                my_calendar.Refresh();
                cout << " Calendar refreshed !!! \n";
            }

            else if (choice == "Exit" || choice == "4")
            {
                cout << " Exiting ... " << endl ;
                exit(0);
            }

            else
            {
                cout << " Invalid choice, try again !!!" << endl ;
            }
        }

    

    return 0;
}
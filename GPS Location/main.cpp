#include "gps.hpp"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int main() 
{

    vector <GPS> locations ;
    const string NameofFFile = "locations.txt" ; 

    while (true)
    {
        cout << "Enter your choice \n\n ";

        cout << " 1. Add a new location " << endl ;
        cout << " 2. List all locations " << endl ;
        cout << " 3. Save locations to file " << endl ;
        cout << " 4. Exit\n";

        int choice ;
        if (!(cin >> choice))
        {
            cout << "Invalid choice ";
            cin.clear();
            cin.ignore (numeric_limits <streamsize> ::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
         {
            double latitude , longitude ;

            cout << "Enter latitude " ;
            if (!(cin >> latitude))
            {
                cout << "Invalid latitude! \n"  ;
                cin.clear();
                cin.ignore (numeric_limits<streamsize> ::max() , '\n') ;
                continue;
            }

            cout << "Enter longitude : ";
            if (!(cin >> longitude))
            {
                cout << "Invalid longitude! \n";
                cin.clear();
                cin.ignore (numeric_limits<streamsize>:: max() , '\n') ;
                continue;
            }
            cin.ignore (numeric_limits<streamsize>:: max(), '\n') ;

            try
            {
                GPS new_location(latitude, longitude);
                locations.push_back(new_location);
                cout << "Location added successfully: " << new_location.convert() << endl;
            }
            
            catch (const invalid_argument& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }

        else if (choice == 2)
        {
            if (locations.empty())
            {
                cout << "No locations added " << endl ;
            }
            
            else
            {
                cout << "List of locations: " << endl ;

                for (size_t i = 0 ; i < locations.size() ; i++)
                {
                    cout << "Location " << (i + 1) << ": " << locations[i].convert () << endl;
                }
            }
        }

        else if (choice == 3)
        {
            GPS:: save_location (NameofFFile , locations) ;
        }

        else if (choice == 4)
        {
            GPS:: load (NameofFFile , locations) ;
        }

        else if (choice == 5)
        {
            cout << "Exiting...\n";
            break;
        }

        else
        {
            cout << " Please choose from thw list " << endl ;
        }
    }

    return 0;
}
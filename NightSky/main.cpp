#include "sky.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main()
{

    cout << "Add stars to the sky '*' \n\n" ;

    Sky sky;

    while (true)
    {

        cout << "\n\n Enter your choice \n\n" ;
        
        cout << "1. Add a new star" << endl ;
        cout << "2. Display the sky" << endl ;
        cout << "3. Exit" << endl ;
        

        int choice;

        if (!(cin >> choice))
        {
            cout << "Invalid choice " << endl ;
            cin.clear() ;
            cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n') ;

        if (choice == 1)
        {
            int x , y , brightness;

            cout << "Enter x : " << endl ;
            if (!(cin >> x))
            {
                cout << "Invalid x !!! " << endl ;
                cin.clear() ;
                cin.ignore (numeric_limits<streamsize>::max(), '\n') ;
                continue;
            }

            cout << "Enter y : ";
            if (!(cin >> y))
            {
                cout << "Invalid y !!!" << endl ;
                cin.clear() ;
                cin.ignore (numeric_limits<streamsize>::max(), '\n') ;
                continue ;
            }

            cout << "Enter brightness  :" << endl ;
            if (!(cin >> brightness))
            {
                cout << "Invalid brightness !!!" << endl ;
                cin.clear() ;
                cin.ignore (numeric_limits<streamsize>::max(), '\n') ;
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n') ;

            try
            {
                Star new_star(x, y, brightness);
                sky.Add_star(new_star);
                cout << " Star added successfully !!!" << endl ;
            }
            
            catch (const invalid_argument& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }

        else if (choice == 2)
        {
            cout << "Night Sky:" << endl ;
            sky.display();
        }

        else if (choice == 3)
        {
            cout << "Exiting..." << endl ;
            break;
        }

        else
        {
            cout << "Invalid choice !!!!" << endl ;
        }
        
    }

    return 0;
}
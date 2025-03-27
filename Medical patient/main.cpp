#include "hospital.hpp"
#include <iostream>
#include <string>
#include <limits> 

using namespace std;


string insensitive(string N)
{
    for (char &c : N)
    {
        c = tolower(c);
    }

    return N;
}


void clearInputBuffer()
{
    cin.clear();
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    Hospital hospital;
    const string NameofFile = "patients.txt" ;

    while (true)
    {
   
        cout << "\t\t *** Medical Patient Panel *** \n\n";
        cout << " Please Enter your choice: " << endl ;
        cout << " 1. Add patient" << endl ;
        cout << " 2. List of patients" << endl ;
        cout << " 3. Save patients " << endl ;
        cout << " 4. Load patients" << endl ;
        cout << " 5. Exit" << endl ;

        string choice;
        cout << " Enter your choice: ";
        getline(cin, choice);
        choice = insensitive(choice);

        if (choice == "add patient" || choice == "1")
        {
            string name;
            int age , HeartRate , Respiratory_rate , Blood_pressure ;
            double Temperature ;

            cout << "Enter patient name: ";
            getline(cin, name) ;

            cout << "Enter age: ";
            while (!(cin >> age))
            {
                cout << "Invalid age! Please try again " << endl ;
                clearInputBuffer();
            }

            cout << "Enter body temperature: ";
            while (!(cin >> Temperature))
            {
                cout << "Invalid temperature! Please try again " <<endl ;
                clearInputBuffer();
            }

            cout << "Enter heart rate: ";
            while (!(cin >> HeartRate))
            {
                cout << "Invalid heart rate! Please try again "  << endl ;
                clearInputBuffer();
            }

            cout << "Enter respiratory rate: ";
            while (!(cin >> Respiratory_rate))
            {
                cout << "Invalid respiratory rate! Please try again " << endl ;
                clearInputBuffer();
            }

            cout << "Enter blood pressure: " ;
            while (!(cin >> Blood_pressure))
            {
                cout << "Invalid blood pressure! Please try again " << endl ;
                clearInputBuffer();
            }

            hospital.Add_Patient(name, age, Temperature, HeartRate, Respiratory_rate, Blood_pressure);
            clearInputBuffer(); 
        } 

        else if (choice == "list of patients" || choice == "2")
        {
            hospital.Patients_List();
        } 

        else if (choice == "save patients" || choice == "3")
        {
            hospital.Save(NameofFile);
        } 

        else if (choice == "load patients" || choice == "4")
        {
            hospital.load(NameofFile);
        } 

        else if (choice == "exit" || choice == "5")
        {
            cout << "Exiting...\n";
            break;
        } 

        else
        {
            cout << "Invalid choice! Please choose from the list " << endl ;
        }
    }

    return 0;
}

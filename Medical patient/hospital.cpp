#include <iostream>
#include <fstream>
#include <sstream>
#include "hospital.hpp"

using namespace std;

void Hospital::Add_Patient(const string& name, int age, double temp, int hr, int respRate, int bloodp)
{    
    try 
    {
        Patient p(name, age, temp, hr, respRate, bloodp);
        patients.push_back(p);
        cout << "Patient " << name << " added successfully!" << endl;
    }
    
    catch (const invalid_argument& e)
    {
        cout << "Error adding patient -> " << e.what() << endl;
    }
}


void Hospital::Patients_List() const
{
    if (patients.empty())
    {
        cout << "There are no patients in the hospital !!!" << endl;
        return;
    }

    cout << "\n\t List of patients:" << endl ;
    for (const Patient& p : patients)
    {
        cout << " Name: " << p.get_Name() 
             << " / Age: " << p.get_Age()
             << " / Temp: " << p.get_Temperature() << " C"
             << " / Heart Rate: " << p.get_HeartRate() << " bpm"
             << " / Respiratory Rate: " << p.get_Respiratory_rate() << " breaths/min"
             << " / Blood Pressure: " << p.get_Blood_pressure() << endl;
    }
}


bool Hospital::Save(const string& NameofFile) const
{
    ofstream file(NameofFile);
    if (!file.is_open())
    {
        cout << "Error: Could not open file (" << NameofFile << ") for saving!" << endl;
        return false;
    }

    for (const Patient& p : patients)
    {
        file << p.get_Name() << endl
             << p.get_Age() << endl
             << p.get_Temperature() << endl
             << p.get_HeartRate() << endl
             << p.get_Respiratory_rate() << endl
             << p.get_Blood_pressure() << endl;
    }

    file.close();
    cout << "Patients saved to (" << NameofFile << ") successfully!" << endl;
    return true;
}


bool Hospital::load(const std::string& NameofFile) 
{
    ifstream file(NameofFile);
    if (!file.is_open())
    {
        cout << "Error: Could not open file (" << NameofFile << ") for loading!" << endl;
        return false;
    }

    patients.clear();
    string name, length ;

    while (getline(file, name))
    {
        int age, hr, respRate , bp;
        double temp;

        if (!getline (file , length) || !(istringstream (length) >> age)) break;
        if (!getline (file , length) || !(istringstream (length) >> temp)) break;
        if (!getline (file , length) || !(istringstream (length) >> hr)) break;
        if (!getline (file , length) || !(istringstream (length) >> respRate )) break;
        if (!getline (file , length) || !(istringstream (length) >> bp)) break;

        Add_Patient(name, age, temp, hr, respRate , bp) ;
    }

    file.close();
    cout << "Patients loaded successfully!" << endl ;

    return true;
}

      

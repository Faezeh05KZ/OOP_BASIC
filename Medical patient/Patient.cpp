#include "Patient.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

Patient::Patient(const string& name, int age, double temp, int hr, int respRate, int bp) {
    if (name.empty()) 
    {
        throw invalid_argument("Name cannot be empty!");
    }

    if (age <= 0) 
    {
        throw invalid_argument("Age cannot be negative or zero. Please provide a valid age!");
    }

    if (temp < 36.0 || temp > 37.5)
    {
        throw invalid_argument("Body temperature must be between 36.0 and 37.5 C !!!");
    }

    if (hr < 60 || hr > 100) 
    {
        throw invalid_argument("Heart rate must be between 60 and 100 bpm !!!");
    }

    if (age >= 18)
    {
        if (respRate < 16 || respRate > 20) 
        {
            throw invalid_argument( "Respiratory rate for adults must be between 16 and 20 breaths per minute !!!") ;
        }
    }
    
    else if (age >= 6)
    {
        if (respRate < 20 || respRate > 30) 
        {
            throw invalid_argument( " Respiratory rate for children (6-18 years) must be between 20 and 30 breaths per minute!");
        }
    }
    
    else
    {
        if (respRate < 30 || respRate > 50)
        {
            throw invalid_argument(" Respiratory rate for infants (0-6 years) must be between 30 and 50 breaths/min !!! ") ;  
        }
    }

    if (bp < 80 || bp > 120)
    {
        throw invalid_argument(" Blood pressure must be between 80 and 120!" ) ;
    }


    this-> Name = name ;
    this-> Age = age ;
    this-> Body_temperature = temp ;
    this-> HeartRate = hr ;
    this-> Respiratory_rate = respRate ;
    this-> Blood_pressure = bp ;
}


string Patient::EncryptDecrypt() const
{
    stringstream ss;

    ss << Name << ","
       << Age << ","
       << Body_temperature << ","
       << HeartRate << ","
       << Respiratory_rate << ","
       << Blood_pressure;

    string data = ss.str();
    char key = 'F'; 

    string encrypted = data;

    for (char& c : encrypted) 
    {
        c ^= key; 
    }

    return encrypted;
}


Patient::~Patient()
{
    Encrypted_data = EncryptDecrypt() ;

    cout << "Patient " << Name << "'s data encrypted: " << Encrypted_data << endl;
}

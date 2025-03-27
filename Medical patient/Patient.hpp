#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

class Patient 
{
    public:
        Patient(const std::string& name, int age, double temp, int heartRate, int respRate, int bp);

        ~Patient();

        std::string get_Name() const { return Name; }

        double get_Temperature() const { return Body_temperature; }

        int get_Age() const { return Age; }

        int get_HeartRate() const { return HeartRate; }

        int get_Respiratory_rate() const { return Respiratory_rate; }

        int get_Blood_pressure() const { return Blood_pressure; }

    private:
        std::string Name;
        std::string Encrypted_data;
        double Body_temperature; 
        int Age;
        int HeartRate; 
        int Respiratory_rate;          
        int Blood_pressure;             

        std::string EncryptDecrypt() const;
};

#endif

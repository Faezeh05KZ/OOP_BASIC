#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "Patient.hpp"
#include <vector>
#include <string>

class Hospital 
{
    public:

        void Add_Patient ( const std::string& name, int age, double temp, int hr, int respRate , int bp);
        void Patients_List () const;
        bool Save (const std::string& NameofFile) const;
        bool load(const std::string& NameofFile);
    
    private:
        std::vector<Patient> patients ;

};

#endif
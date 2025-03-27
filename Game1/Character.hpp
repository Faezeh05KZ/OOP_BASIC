#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>

class Character 
{
    public:

        Character (const std::string& name, int health, int power) ;
        void Add_skill(const std::string& skill_name, int level) ;

        const std:: vector <std:: pair <std:: string , int > >& get_skills() const { return Skills ; }
        std::string get_name() const { return Name ; }
        int         get_health() const { return Health ; }
        int         get_power() const { return Power ; }

    private:

        std::string Name ;
        int Health ; 
        int Power ;
        
        std:: vector <std:: pair <std:: string , int> > Skills ;

};

#endif
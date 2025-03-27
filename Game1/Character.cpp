#include "Character.hpp"
#include <iostream>


using namespace std;


Character::Character(const string& name , int health , int power) 
{
    if (name.empty()) 
    {
        throw invalid_argument("The Name cann't be empty !!! ") ;
    }

    if (health < 0) 
    {
        throw invalid_argument(" The Health must be positive !!!" ) ;
    }

    if (power < 0)
    {
        throw invalid_argument(" The Power must be positive !!!" ) ;
    }


    this-> Name   = name ;
    this-> Health = health ;
    this-> Power  = power ;

}

void Character:: Add_skill (const string& skill_name , int level )
{
    if (skill_name.empty())
    {
        throw invalid_argument (" Skill name cann't be empty !!!");
    }

    if (level < 0)
    {
        throw invalid_argument (" The Skill level must be positive !!!");
    }


    Skills.push_back ({skill_name, level}) ;
}
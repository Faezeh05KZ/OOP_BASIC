#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include <vector>
#include <string>

class Game
{
    public:

        void Add_character (const Character& character) ;
        void Characters_List () const;
        bool save_Character (const std::string& filename) const ;
        bool load_Character (const std::string& filename) ;
        void add_skill_to_character (const std::string& name , const std::string& skill_name , int skill_level) ;

    private:

        std:: vector <Character> characters ;
};

#endif
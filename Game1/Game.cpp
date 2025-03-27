#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Game::Add_character(const Character& character)
{
    characters.push_back(character);
    cout << character.get_name() << " added to the game successfully !!!" << endl;
}

void Game::Characters_List() const
{
    if (characters.empty())
    {
        cout << " There is No characters in the game !!!" << endl;
        return ;
    }

    cout << "List of characters:" << endl;
    for (const Character& c : characters)
    {
        cout << " Name : "   << c.get_name() << endl;
        cout << " Health : " << c.get_health() << endl;
        cout << " Power : "  << c.get_power() << endl;
        cout << " Skills : " << endl;

        const auto& skills = c.get_skills();
        if (skills.empty())
        {
            cout << " No Skills defined " << endl;
        }
        else
        {
            for (const auto& s : skills)
            {
                cout << "*" << s.first << " level :" << s.second << endl;
            }
        }
        cout << endl;
    }
}

void Game::add_skill_to_character(const std::string& name, const std::string& skill_name, int skill_level)
{
    bool found = false;
    for (Character& c : characters)
    {
        if (c.get_name() == name)
        {
            c.Add_skill(skill_name, skill_level);
            cout << "Skill added to " << name << " successfully !!!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "I couldn't find a character named " << name << endl;
    }
}

bool Game::save_Character(const string& NameofFile) const
{
    ofstream savech(NameofFile);
    if (!savech.is_open())
    {
        cout << " Error: Couldn't open file to save !!! " << endl ;
        return false;
    }

    for (const Character& c : characters)
    {
        savech << c.get_name() << endl << c.get_health() << endl << c.get_power() << endl   ;
        const auto& skills = c.get_skills();

        savech << skills.size() << endl;
        for (const auto& s : skills)
        {
            savech << s.first << endl << s.second << endl ;
        }
    }

    savech.close()  ;
    cout << "Characters saved successfully !!! " << endl ;
    return true ;
}

bool Game:: load_Character (const string& NameofFile)
{
    ifstream loadch(NameofFile) ;
    if (!loadch.is_open())
    {
        cout << "Error: Couldn't open file to load !!! " << endl;
        return false;
    }

    characters.clear();
    string name, length;

    while (getline(loadch , name ))
    {
        int health, power, num_of_skills;

        if (!getline(loadch , length))
        {
            cout << "Err! File is Expired ... " << endl;
            break;
        }
        stringstream(length) >> health ;

        if (!getline(loadch , length))
        {
            cout << "Err! File is Expired ... " << endl;
            break;
        }
        stringstream(length) >> power ;

        if (!getline(loadch, length))
        {
            cout << "Err! File is Expired ... " << endl;
            break;
        }

        stringstream(length) >> num_of_skills;

        try
        {
            Character c(name, health, power);
            for (int i = 0 ; i < num_of_skills ; i++ )
            {
                string skill_name;
                int skill_level;

                if (!getline(loadch, skill_name))
                {
                    cout << " Err! File is Expired ..." << endl;
                    break;
                }

                if (!getline(loadch, length))
                {
                    cout << " Err! File is Expired ... " << endl;
                    break;
                }

                stringstream(length) >> skill_level;
                c.Add_skill(skill_name, skill_level);
            }
            characters.push_back(c);
        }
        catch (const invalid_argument& e)
        {
            cout << "Error loading " << "( " << name << " )" << ": " << e.what() << endl;
        }
    }

    loadch.close();
    cout << "Characters loaded successfully !!! " << endl;
    return true;
}
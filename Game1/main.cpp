#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

string insensitive(string N)
{
    for (char &c : N)
    {
        c = tolower(c);
    }
    return N;
}

int main()
{
    Game game;
    const string NameofFile = "characters.txt";

    cout << " \n\n\t\t *** Create your game character *** \n\n " ;

    while (true)
    {
        cout << " Enter your choice \n\n ";


        cout << " 1. Add a new character " << endl;
        cout << " 2. List of characters " << endl;
        cout << " 3. Add a skill to one character " << endl;
        cout << " 4. Save characters " << endl;
        cout << " 5. Load characters " << endl;
        cout << " 6. If you want to quit enter the 'exit' " << endl;

        string choice;
        cout << " Enter your choice: ";
        getline(cin, choice);
        choice = insensitive(choice);

        if (choice == "add a new character" || choice == "1")
        {
            string name;
            int health, power;

            cout << "Enter the character's name: ";
            getline(cin, name);

            cout << "Enter the character's health: ";
            if (!(cin >> health))
            {
                cout << "Invalid health! Please enter a number." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cout << "Enter the character's power: ";
            if (!(cin >> power))
            {
                cout << "Invalid power! Please enter a number." << endl;
                cin.clear();
                cin.ignore();
                continue;
            }

            cin.ignore();

            try
            {
                Character new_character(name, health, power);
                game.Add_character(new_character);
            }

            catch (const invalid_argument& e)
            {
                cout << " Something went wrong :( " << e.what() << endl;
            }
        }

        else if (choice == "list of characters" || choice == "2")
        {
            game.Characters_List();
        }

        else if (choice == "add a skill to one character" || choice == "3")
        {
            string name, skill_name;
            int skill_level;

            cout << "Enter the name of the character: ";
            getline(cin, name);

            cout << "Enter the name of skill: ";
            getline(cin, skill_name);

            cout << "Enter the skill level: ";
            if (!(cin >> skill_level))
            {
                cout << "Invalid skill level! Please enter a number." << endl;
                cin.clear();
                cin.ignore();
                continue;
            }

            
            cin.ignore();

            try
            {
                game.add_skill_to_character (name, skill_name, skill_level) ;
            }

            catch (const invalid_argument& e)
            {
                cout << " Something went wrong :( " << e.what() << endl ;
            }
        }

        else if (choice == "save characters" || choice == "4")
        {
            game.save_Character(NameofFile);
        }

        else if (choice == "load characters" || choice == "5")
        {
            game.load_Character(NameofFile);
        }

        else if (choice == "exit" || choice == "6")
        {
            cout << " Exiting game ;)" << endl;
            break;
        }

        else
        {
            cout << " Invalid choice! Please choose from the list " << endl;
        }
    }

    return 0;
}
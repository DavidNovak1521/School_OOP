#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"

int main(int argc, char **argv)
{
    try
    {
        Warrior warrior1 = Warrior::parseFromFile("Blue", argv[1]);
        Warrior warrior2 = Warrior::parseFromFile("Red", argv[2]);

        std::cout << "Alive -> " << Warrior::getAliveWarriorNumber() << std::endl;

        fightTilDeath(warrior1, warrior2);

        std::cout << "Alive -> " << Warrior::getAliveWarriorNumber() << std::endl;
    }
    catch (FileNotFoundException exception)
    {
        std::cout << "Bad filename: " << exception.filename << std::endl;
        return 1;
    }
    catch (Warrior::BadFileFormatException exception)
    {
        std::cout << "Bad structure: " << exception.filename << std::endl;
        return 2;
    }

    return 0;
}
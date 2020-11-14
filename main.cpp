#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"
#include "Inventory.hpp"

int main(int argc, char **argv)
{
    Inventory inv;
    inv.put(Sword(1, 2, 1.2));
    inv.put(Sword(1, 3, 3.4));
    inv.put(Sword(1, 4, 5));
    std::cout << inv.count() << " - " << inv.getTotalWeight() << std::endl;
    inv.put(Sword(1, 5, 6));
    inv.put(Sword(1, 6, 7.2));
    std::cout << inv.count() << " - " << inv.getTotalWeight() << std::endl;

    inv.get(2).use();

    for (int i = 0; i < inv.count(); i++)
        std::cout << i << ". item -> " << inv.get(i).toString() << std::endl;

    std::cout << std::endl;
    try
    {
        while (true)
        {

            Sword dropped = inv.drop(0);
            std::cout << "Dropped sword: " << dropped.toString() << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < inv.count(); i++)
                std::cout << i << ". item -> " << inv.get(i).toString() << std::endl;
            std::cout << std::endl;
        }
    }
    catch (Inventory::WrongIndexException e)
    {
        std::cout << "Wrong index!" << std::endl;
    }
    /*
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
    */
    return 0;
}
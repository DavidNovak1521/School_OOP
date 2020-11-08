#include <iostream>

#include "Battle.hpp"

void printStatus(const Warrior &warrior1, const Warrior &warrior2)
{
    std::cout << warrior1.toString() << "   ---   " << warrior2.toString() << std::endl;
}

void fightTilDeath(Warrior &warrior1, Warrior &warrior2)
{
    while (warrior1.isAlive() && warrior2.isAlive())
    {
        printStatus(warrior1, warrior2);
        warrior1.attack(warrior2);
        if (warrior2.isAlive())
        {
            printStatus(warrior1, warrior2);
            warrior2.attack(warrior1);
        }
    }
}
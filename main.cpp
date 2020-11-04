#include <iostream>

#include "Warrior.hpp"
#include "Battle.hpp"

int main()
{
    Warrior warrior1, warrior2;
    warrior1 = readWarrior();
    warrior2 = readWarrior();

    fightTilDeath(warrior1, warrior2);

    printStatus(warrior1, warrior2);

    return 0;
}
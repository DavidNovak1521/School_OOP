#include <iostream>

#include "Warrior.hpp"
#include "Battle.hpp"

int main()
{
    Warrior warrior1, warrior2;
    warrior1.readFromKeyboard();
    warrior2.readFromKeyboard();

    fightTilDeath(warrior1, warrior2);

    printStatus(warrior1, warrior2);

    return 0;
}
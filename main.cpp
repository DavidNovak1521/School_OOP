#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"

int main(int argc, char **argv)
{
    Warrior warrior1(argv[1]);
    Warrior warrior2(argv[2]);

    fightTilDeath(warrior1, warrior2);

    printStatus(warrior1, warrior2);

    return 0;
}
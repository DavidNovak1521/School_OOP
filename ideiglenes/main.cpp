#include <iostream>
#include <string>

/*#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"
#include "Inventory.hpp"
#include "Belt.hpp"*/
#include "Sword.hpp"

int main(int argc, char **argv)
{
    Sword s(5, 6, 3);

    while (s.isUsable())
        std::cout << s.attack() << std::endl;

    return 0;
}
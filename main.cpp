#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"
#include "Inventory.hpp"
#include "Belt.hpp"

int main(int argc, char **argv)
{
    Inventory inv(6);
    inv.put(Sword(0, 3, 1.2));
    inv.put(Sword(1, 3, 3.4));
    inv.put(Sword(2, 3, 0.3));
    inv.put(Sword(3, 3, 1.2));
    inv.put(Sword(4, 3, 3.4));
    inv.put(Sword(5, 3, 0.3));

    std::cout << "------ INV" << std::endl;
    for (int i = 0; i < inv.count(); ++i)
        std::cout << inv.get(i).toString() << std::endl;

    Inventory inv2(inv);
    inv.clear();

    std::cout << "------ INV" << std::endl;
    for (int i = 0; i < inv.count(); ++i)
        std::cout << inv.get(i).toString() << std::endl;

    std::cout << "------ INV2" << std::endl;
    for (int i = 0; i < inv2.count(); ++i)
        std::cout << inv2.get(i).toString() << std::endl;

    return 0;
}
#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"
#include "Inventory.hpp"
#include "Belt.hpp"
#include "Sword.hpp"
#include "Shield.hpp"
#include "SpellBook.hpp"
#include "Printable.hpp"

int main(int argc, char **argv)
{
    Inventory inv(12);

    inv.put(new Sword(12, 3, 3.5));
    inv.put(new SpellScroll());
    inv.put(new Shield(12, 6, 5.5));

    auto book = new SpellBook(5);
    *book << "Varazslat1"
          << "Varazslat2";
    "Varazslat3" >> *book;
    inv.put(book);

    for (int i = 0; i < inv.count(); i++)
    {
        std::cout << "Item " << i << ": " << inv.get(i) << std::endl;
    }

    std::cout << "Total weight: " << inv.getTotalWeight()
              << "\n - Wearables: " << inv.getWeight<Wearable>()
              << "\n   - Sword w.: " << inv.getWeight<Sword>()
              << "\n   - Shield w.: " << inv.getWeight<Shield>()
              << "\n - SpellScroll w.: " << inv.getWeight<SpellScroll>() << std::endl;

    return 0;
}
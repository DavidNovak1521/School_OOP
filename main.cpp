#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Battle.hpp"
#include "FileNotFoundException.hpp"
#include "Inventory.hpp"
#include "Belt.hpp"
#include "List.hpp"

int main(int argc, char **argv)
{
    List<HealthPotion> my_hp_list;

    my_hp_list.put(HealthPotion{1});
    my_hp_list.put(HealthPotion{2});
    my_hp_list.put(HealthPotion{3});
    my_hp_list.put(HealthPotion{4});
    my_hp_list.put(HealthPotion{5});
    my_hp_list.put(HealthPotion{6});
    my_hp_list.put(HealthPotion{7});

    try
    {
        while (true)
        {
            for (int i = 0; i < my_hp_list.count(); i++)
                std::cout << i << ". potion: " << my_hp_list.get(i).health_points << std::endl;
            std::cout << std::endl;
            my_hp_list.pop(3);
        }
    }
    catch (WrongIndexException e)
    {
        std::cout << "Could not access element at index: " << e.index << "\n";
    }

    return 0;
}
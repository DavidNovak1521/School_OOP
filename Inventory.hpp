#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Sword.hpp"

class Inventory
{
public:
    Inventory(double weightLimit);

    //Inventory(const Inventory &) = delete;
    //Inventory &operator=(const Inventory &) = delete;

    double getTotalWeight() const;
    int count() const;
    const Sword &get(int index) const;
    bool put(const Sword &sword);
    Sword drop(int index);
    void clear();

private:
    std::vector<Sword> swords;
    double weightLimit;
};

#endif

#include "Inventory.hpp"

Inventory::Inventory(double weightLimit) : weightLimit(weightLimit) {}

double Inventory::getTotalWeight() const
{
    double totalWeight = 0;
    for (auto &sword : swords)
        totalWeight += sword.getWeight();
    return totalWeight;
}

int Inventory::count() const
{
    return swords.size();
}

const Sword &Inventory::get(int index) const
{
    return swords.at(index);
}

bool Inventory::put(const Sword &sword)
{
    if (getTotalWeight() + sword.getWeight() > weightLimit)
        return false;
    else
    {
        swords.push_back(sword);
        return true;
    }
}

Sword Inventory::drop(int index)
{
    Sword sword(swords.at(index));
    swords.erase(swords.begin() + index);
    return sword;
}

void Inventory::clear()
{
    swords.clear();
}
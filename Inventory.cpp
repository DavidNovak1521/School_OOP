#include "Inventory.hpp"

Inventory::Inventory(double weightLimit) : weightLimit(weightLimit) {}

Inventory::~Inventory() { clear(); }

double Inventory::getTotalWeight() const
{
    double totalWeight = 0;
    for (auto &item : items)
        totalWeight += item->getWeight();
    return totalWeight;
}

int Inventory::count() const
{
    return items.size();
}

const Item &Inventory::get(int index) const
{
    return *items.at(index);
}

bool Inventory::put(Item *item)
{
    if (getTotalWeight() + item->getWeight() > weightLimit)
        return false;
    else
    {
        items.push_back(item);
        return true;
    }
}

Item *Inventory::drop(int index)
{
    Item *item = items.at(index);
    items.erase(items.begin() + index);
    return item;
}

void Inventory::destroy(int index)
{
    Item *item = items.at(index);
    items.erase(items.begin() + index);
    delete item;
}

void Inventory::clear()
{
    for (auto pItem : items)
        delete pItem;
    items.clear();
}
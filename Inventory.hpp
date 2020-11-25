#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Item.hpp"

class Inventory
{
public:
    Inventory(double weightLimit);
    ~Inventory();

    Inventory(const Inventory &) = delete;
    Inventory &operator=(const Inventory &) = delete;

    double getTotalWeight() const;
    template <typename T>
    double getWeight() const
    {
        double totalWeight = 0;
        for (auto item : items)
        {
            T *pT = dynamic_cast<T *>(item);
            if (pT != nullptr)
                totalWeight += pT->getWeight();
        }
        return totalWeight;
    }
    int count() const;
    const Item &get(int index) const;
    bool put(Item *item);
    Item *drop(int index);
    void destroy(int index);
    void clear();

private:
    std::vector<Item *> items;
    const double weightLimit;
};

#endif

#include "Sword.hpp"

Sword::Sword(int damage, int durability, double weight)
    : damage(damage), max_durability(durability), current_durability(durability), weight(weight){};

int Sword::use()
{
    if (current_durability > 0)
    {
        --current_durability;
        return damage;
    }
    else
        return 0;
}

void Sword::repair()
{
    current_durability = max_durability;
}

double Sword::getWeight() const
{
    return weight;
}

std::string Sword::toString() const
{
    return "Sword dmg: " + std::to_string(damage) + ", dur: " + std::to_string(current_durability) + "/" + std::to_string(max_durability) + ", w: " + std::to_string(weight);
}
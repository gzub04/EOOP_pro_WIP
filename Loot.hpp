#ifndef LOOT_HPP
#define LOOT_HPP

#include "Weapon.hpp"
#include "Armour.hpp"
#include "Potion.hpp"
#include "Inventory.hpp"

#include <iostream>
#include <ctime>

class Loot
{
private:
    Inventory& eq;
    std::vector<Weapon*> allWeapons;
    std::vector<Armour*> allArmour;
    std::vector<Potion*> allPotions;
    int number_of_enemies, loot_rolls;
public:
    Loot(Inventory& eq, std::vector<Weapon*> allWeapons, std::vector<Armour*> allArmour, std::vector<Potion*> allPotions, int number_of_enemies);
    ~Loot();
    void getLoot();
};

#endif
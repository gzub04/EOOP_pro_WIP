#ifndef SHOP_HPP
#define SHOP_HPP

#include "Weapon.hpp"
#include "Armour.hpp"
#include "Potion.hpp"
#include "Inventory.hpp"

class Shop
{
private:
    Weapon weapon1, weapon2;
    Armour armour1, armour2;
    Potion potion1, potion2;
    Inventory& eq;

public:
    Shop(Weapon weapon1, Weapon weapon2, Armour armour1, Armour armour2, Potion potion1, Potion potion2, Inventory& eq);
    ~Shop();

    void sellmenu();
    void menu();
};

#endif
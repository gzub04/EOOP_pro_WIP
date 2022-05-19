#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Character.hpp"
#include "Weapon.hpp"
#include "Armour.hpp"
#include "Potion.hpp"

#include <vector>
#include <memory>

class Inventory
{
private:
    std::vector<Weapon> vWeapons;
    std::vector<Armour> vArmour;
    std::vector<Potion> vPotions;
    Weapon *equippedWeapon;
    Armour *equippedArmour;
    unsigned int money;

public:
    Inventory(Weapon firstWeapon, Armour firstArmour, Potion starting_potion1, Potion starting_potion2);
    ~Inventory();
    void addWeapon(Weapon newWeapon);
    void removeWeapon(Weapon weapon);
    void addArmour(Armour newArmour);
    void removeArmour(Armour armour);
    void addPotion(Potion newPotion);
    void removePotion(Potion potion);
    bool usePotion();   // false if cancelled, true if succeded
    //void equipWeapon(Weapon weapon);
    Weapon *getEquippedWeapon();
    //void equipArmour(Armour armour);
    Armour *getEquippedArmour();
    void listWeaponsWithPrices();   // ---- for shop ----
    void listArmourWithPrices();    //
    void listPotionsWithPrices();   //
    void sellWeapon(int i);         //
    void sellArmour(int i);         //
    void sellPotion(int i);         //      ------
    void BrowseInventory(); // choice: weapon, armour, potion; allows to change equipment
    void addMoney(unsigned int value);
    bool spendMoney(unsigned int value);
};

#endif
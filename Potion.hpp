#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"
#include "Character.hpp"
#include "Armour.hpp"
#include "Weapon.hpp"

class Potion : public Item
{
private:
    std::string purpose; // heal/manaRegen/buffRes%/buffAtk%
    int value;
    Character *MC;

public:
    Potion(std::string name, std::string purpose, int value, int price, Character *MC);
    ~Potion();
    //void setValue(int newValue);
    //int getValue() const;
    std::string getPurpose();
    bool heal();  // true - healed; false - failed
    bool manaRegen();
    bool buffRes(Armour *armour);
    bool buffAtk(Weapon *weapon);
};

#endif
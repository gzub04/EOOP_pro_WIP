#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"

class Weapon : public Item
{
private:
    int damage;
    int preBuffDamage;
    std::string damage_type; // physical/magical
    int StunChance = 0;

public:
    Weapon(std::string name, int damage, std::string damage_type, int price);
    ~Weapon();
    //void setDamage(int damage);
    int getDamage() const;
    std::string getDamageType() const;
    void setStunChance(int newStunChance);
    int getStunChance() const;
    void buffDamage(int value);
    void resetBuffs();
};

#endif
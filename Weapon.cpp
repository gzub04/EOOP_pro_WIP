#include "Weapon.hpp"

Weapon::Weapon(std::string name, int damage, std::string damage_type, int price) : damage(damage), preBuffDamage(damage), damage_type(damage_type)
{
    setName(name);
    setPrice(price);
}

Weapon::~Weapon() {}

int Weapon::getDamage() const
{
    return damage;
}

std::string Weapon::getDamageType() const
{
    return damage_type;
}

void Weapon::setStunChance(int newStunChance)
{
    StunChance = newStunChance;
}

int Weapon::getStunChance() const
{
    return StunChance;
}

void Weapon::buffDamage(int value)
{
    damage += damage * value/100;
}

void Weapon::resetBuffs()
{
    damage = preBuffDamage;
}
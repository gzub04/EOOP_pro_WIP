#include "Common_for_units.hpp"

Common_for_units::Common_for_units() {}

Common_for_units::~Common_for_units() {}

void Common_for_units::setMaxHealth(int newMaxHealth)
{
    MaxHealth = newMaxHealth;
}

int Common_for_units::getMaxHealth() const
{
    return MaxHealth;
}

void Common_for_units::setCurrentHealth(int newCurrentHealth)
{
    CurrentHealth = newCurrentHealth;
}

int Common_for_units::getCurrentHealth() const
{
    return CurrentHealth;
}

void Common_for_units::changeHealth(int value)
{
    if ((CurrentHealth + value) <= 0)
    {
        CurrentHealth = 0;
    }
    else if ((CurrentHealth + value) >= MaxHealth)
    {
        CurrentHealth = MaxHealth;
    }
    else
    {
        CurrentHealth += value;
    }
}

void Common_for_units::showHealth() const
{
    std::cout << "(" << CurrentHealth << "/" << MaxHealth << ")";
}

void Common_for_units::setPhysicalRes(int newPhysicalRes)
{
    PhysicalRes = newPhysicalRes;
}

void Common_for_units::setMagicRes(int newMagicRes)
{
    MagicRes = newMagicRes;
}

int Common_for_units::getResistance(std::string type_) const
{
    if(type_ == "physical")
    {
        return PhysicalRes;
    }
    else if(type_ == "magical")
    {
        return MagicRes;
    }
    else
    {
        std::cout << "Wrong Resistance name.\n";
        return 505;
    }
}

void Common_for_units::setDodgeChance(int newDodgeChance)
{
    DodgeChance = newDodgeChance;
}

int Common_for_units::getDodgeChance() const
{
    return DodgeChance;
}

void Common_for_units::stun()
{
    isStunned = true;
}

void Common_for_units::destun()
{
    isStunned = false;
}
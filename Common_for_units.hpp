#ifndef COMMON_UNIT_HPP
#define COMMON_UNIT_HPP

#include <iostream>

class Common_for_units
{
private:
    int MaxHealth;
    int CurrentHealth;
    int PhysicalRes = 0;
    int MagicRes = 0;
    int DodgeChance;
    bool isStunned = false;

public:
    Common_for_units();
    ~Common_for_units();
    void setMaxHealth(int MaxHealth);
    int getMaxHealth() const;
    void setCurrentHealth(int CurrentHealth);
    int getCurrentHealth() const;
    void changeHealth(int value);
    void showHealth() const;
    void setPhysicalRes(int newPhysicalRes);
    int getPhysicalRes() const;
    void setMagicRes(int newMagicRes);
    int getMagicRes() const;
    int getResistance(std::string type_) const;
    void setDodgeChance(int newDodgeChance);
    int getDodgeChance() const;
    void stun();
    void destun();
};

#endif
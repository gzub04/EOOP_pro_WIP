#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "Common_for_units.hpp"

#include <iostream>

class Character : public Common_for_units
{
private:
    int MaxMana;
    int CurrentMana = MaxMana;
    unsigned int level = 1;
    unsigned int CurrentXP = 0;
    unsigned int LevelUpReq = 20;

public:
    Character(int MaxHealth,int MaxMana, int DodgeChance);
    ~Character();
    //void setMaxMana(unsigned int newMaxMana);
    int getMaxMana() const;
    void setCurrentMana(int newCurrentMana);
    int getCurrentMana() const;
    void showMana() const;
    bool removeMana(int value); // returns true if changed, false if not enough mana
    void LevelUp();
    void gainXP(int addedXP);
    int getLevel() const;
};

#endif
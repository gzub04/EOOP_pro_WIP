#include "Character.hpp"

Character::Character(int MaxHealth, int MaxMana, int DodgeChance) : MaxMana(MaxMana), CurrentMana(MaxMana)
{
    setMaxHealth(MaxHealth);
    setCurrentHealth(MaxHealth);
    setDodgeChance(DodgeChance);
}
Character::~Character() {}

void Character::setCurrentMana(int newCurrentMana)
{
    CurrentMana = newCurrentMana;
}


int Character::getMaxMana() const
{
    return MaxMana;
}

int Character::getCurrentMana() const
{
    return CurrentMana;
}


void Character::showMana() const
{
    std::cout << CurrentMana << "/" << MaxMana;
}

bool Character::removeMana(int value)
{
    if (value > CurrentMana)
        return false;
    CurrentMana -= value;
    return true;
}

void Character::LevelUp()
{
    CurrentXP = 0;
    LevelUpReq = LevelUpReq + 3 * level;
    if(level < 10)
    {
        setMaxHealth(getMaxHealth()*1.3);
        changeHealth(0.5 * getCurrentHealth());
        MaxMana *= 1.23;
    }
    else if(level < 30)
    {
        setMaxHealth(getMaxHealth()*1.18);
        MaxMana *= 1.13;
    }
    else
    {
        setMaxHealth(getMaxHealth()*1.1);
        MaxMana *= 1.06;
    }
    level += 1;
}

void Character::gainXP(int addedXP)
{
    if ((CurrentXP + addedXP) >= LevelUpReq)
    {
        CurrentXP += addedXP - LevelUpReq;
        LevelUp();
        std::cout << "Level up!" << std::endl;
    }
    else
        CurrentXP += addedXP;
}

int Character::getLevel() const
{
    return level;
}
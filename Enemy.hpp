#ifndef ENEMY_HPP
#define ENEMY_HPP


#include "Common_for_units.hpp"

#include <iostream>

class Enemy : public Common_for_units
{
private:
    std::string name;
    bool alive = true;
    double PowerMultiplier = 1; // multiplier how much stronger his attack should be
    int xp;

public:
    Enemy(std::string name, int MaxHealth, int PhysicalRes, int MagicalRes, int DodgeChance, double PowerMultiplier, int xp);
    Enemy();
    ~Enemy();
    std::string getName() const;
    void setPowerMultiplier(double newPowerMultiplier);
    double getPowerMultiplier() const;
    bool isAlive();
    void kill();
    int getXP();
    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
};

#endif
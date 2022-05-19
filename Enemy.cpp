#include "Enemy.hpp"

Enemy::Enemy(std::string name, int MaxHealth, int PhysicalRes, int MagicRes, int DodgeChance, double PowerMultiplier, int xp) : name(name), PowerMultiplier(PowerMultiplier), xp(xp)
{
    setMaxHealth(MaxHealth);
    setCurrentHealth(MaxHealth);
    setPhysicalRes(PhysicalRes);
    setMagicRes(MagicRes);
    setDodgeChance(DodgeChance);
}

Enemy::Enemy()
{
    name = "1";
    PowerMultiplier = 1;
    setMaxHealth(100000);
    setCurrentHealth(100000);
    setPhysicalRes(100);
    setMagicRes(100);
    setDodgeChance(0);
}

Enemy::~Enemy() {}

std::string Enemy::getName() const
{
    return name;
}

void Enemy::setPowerMultiplier(double newPowerMultiplier)
{
    PowerMultiplier = newPowerMultiplier;
}

double Enemy::getPowerMultiplier() const
{
    return PowerMultiplier;
}

bool Enemy::isAlive()
{
    return alive;
}

void Enemy::kill()
{
    alive = false;
}

int Enemy::getXP()
{
    return xp;
}

std::ostream &operator<<(std::ostream &os, const Enemy &enemy)
{
    os << enemy.name << " (" << enemy.getCurrentHealth() << "/" << enemy.getMaxHealth() << ")";
    return os;
}
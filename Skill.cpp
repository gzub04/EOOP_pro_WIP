#include "Skill.hpp"

#include <cstdlib>
#include <ctime>

Skill::Skill(std::string name, std::string target, std::string dmgType, int power, int ManaCost, Character &MC, Inventory *eq) : name(name), target(target), dmgType(dmgType), power(power), ManaCost(ManaCost), MC(MC), eq(eq) {}

Skill::~Skill() {}

std::string Skill::getName() const
{
    return name;
}

void Skill::setEnemy(Enemy *newEnemy)
{
    enemy = newEnemy;
}

void Skill::setDescription(std::string newDescription)
{
    description = newDescription;
}

std::string Skill::getDescription() const
{
    std::cout << "Target: ";
    if (target == "targeted")
    {
        std::cout << "one enemy";
    }
    else
    {
        std::cout << "all enemies";
    }
    std::cout << std::endl << "Damage: ";
    if (ManaCost == 0)
        {
            std::cout << eq->getEquippedWeapon()->getDamage() + power;
        }
    else
    {
        std::cout << power;
    }
    std::cout << std::endl;
    return description;
}

bool Skill::useSkill()
{
    std::srand(std::time(NULL));
    int random = std::rand() % 100 + 1;
    int damage;
    if (target == "targeted" && random <= enemy->getDodgeChance())
    {
        if (MC.removeMana(ManaCost))
        {
            std::cout << enemy->getName() << " dodged!\n";
            return true;
        }
        else
        {
            std::cout << "You don't have enough mana!\n";
            return false;
        }
    }
    else
    {
        if (ManaCost == 0)
        {
            damage = eq->getEquippedWeapon()->getDamage() + power;
            damage -= damage * enemy->getResistance(eq->getEquippedWeapon()->getDamageType());
            enemy->changeHealth(-damage);
            std::cout << "You dealt " << damage << " damage with " << eq->getEquippedWeapon()->getName() << " to " << enemy->getName() << std::endl;
            return true;
        }
        else
        {
            if (MC.removeMana(ManaCost))
            {
                damage = power - power * enemy->getResistance(dmgType);
                enemy->changeHealth(-damage);
                std::cout << "You dealt " << damage << " damage with " << name << " to " << enemy->getName() << "." << std::endl;
                return true;
            }
            else
            {
                std::cout << "You don't have enough mana!\n";
                return false;
            }
        }
    }
}

void Skill::useEnemySkill()
{
    std::srand(std::time(NULL));
    int random = std::rand() % 100 + 1;
    int damage;
    if (random <= MC.getDodgeChance())
    {
        std::cout << "You dodged " << enemy->getName() << "'s " << name << "!" << std::endl;
        return;
    }
    else
    {
        damage = power * enemy->getPowerMultiplier();
        damage -= damage * eq->getEquippedArmour()->getResistance(dmgType);
        std::cout << enemy->getName() << " used " << name << " and hit you for " << damage << ".\n";
    }
}

/*
Enemy Skill::getEnemy() const
{
    return enemy;
}

int Skill::getValue() const
{
    return value;
}
*/
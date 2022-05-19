#ifndef SKILL_HPP
#define SKILL_HPP

#include "Character.hpp"
#include "Enemy.hpp"
#include "Inventory.hpp"

class Skill
{
private:
    std::string name;
    std::string target; // targeted/AOE
    std::string dmgType;
    int power;
    int ManaCost;
    std::string description;
    Character &MC;
    Enemy *enemy;
    Inventory *eq;

public:
    Skill(std::string name, std::string target, std::string dmgType, int power, int ManaCost, Character &MC, Inventory *eq);
    ~Skill();
    std::string getName() const;
    void setEnemy(Enemy *newEnemy);
    //Enemy getEnemy() const;
    //void setValue(int newValue);
    //int getValue() const;
    //void setManaCost(int ManaCost);
    //unsigned int getManaCost() const;
    void setDescription(std::string newDescription);
    std::string getDescription() const;
    bool useSkill();    //true if used, false if not enough mana
    void useEnemySkill();
};

#endif
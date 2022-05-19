#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Character.hpp"
#include "Enemy.hpp"
#include "Skill.hpp"
#include "Inventory.hpp"

#include <ctime>

class Battle
{
private:
    Character& MC;
    Inventory& eq;
    Enemy *targeted_enemy;
    std::vector<Skill*> attacks, skills, enemy_attacks;
    int number_of_enemies;
    Enemy enemy1, enemy2, enemy3;
    bool boss_room = false;

public:
    Battle(Character& MC, Inventory& eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1); //addEnemies here
    Battle(Character& MC, Inventory& eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1, Enemy enemy2); //addEnemies here
    Battle(Character& MC, Inventory& eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1, Enemy enemy2, Enemy enemy3); //addEnemies here
    ~Battle();
    void setBossRoom();
    void chooseEnemy();
    bool attackmenu(std::vector<Skill*> attacks_);
    void entryMsg();
    void roundMenu();
    void enemyAttack();
    int endOfRoundSummary();  // 0 if still going, 1 if player won, 2 if player lost
    bool runWholeBattle();  // true if won, false if lost
};

#endif
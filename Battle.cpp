#include "Battle.hpp"

#include <iostream>

void listAttacks(std::vector<Skill*> attacks)
{
    std::cout << "0 to return\n";
    for (unsigned int i = 0; i < attacks.size(); i++)
    {
        std::cout << i + 1 << "." << attacks.at(i)->getName() << "\t";
        if ((i + 1) % 3)
        {
            std::cout << std::endl;
        }
        else if ((i + 1) == attacks.size())
            std::cout << std::endl;
    }
}

Battle::Battle(Character &MC, Inventory &eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1) : MC(MC), eq(eq), attacks(attacks), skills(skills), enemy_attacks(enemy_attacks), number_of_enemies(number_of_enemies), enemy1(enemy1) {}

Battle::Battle(Character &MC, Inventory &eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1, Enemy enemy2) : MC(MC), eq(eq), attacks(attacks), skills(skills), enemy_attacks(enemy_attacks), number_of_enemies(number_of_enemies), enemy1(enemy1), enemy2(enemy2) {}

Battle::Battle(Character &MC, Inventory &eq, std::vector<Skill*> attacks, std::vector<Skill*> skills, std::vector<Skill*> enemy_attacks, int number_of_enemies, Enemy enemy1, Enemy enemy2, Enemy enemy3) : MC(MC), eq(eq), attacks(attacks), skills(skills), enemy_attacks(enemy_attacks), number_of_enemies(number_of_enemies), enemy1(enemy1), enemy2(enemy2), enemy3(enemy3) {}

Battle::~Battle() {}

void Battle::setBossRoom()
{
    boss_room = true;
}

void Battle::chooseEnemy()
{
    int choice;
    std::cout << "Choose the enemy: ";
    while (true)
    {
        for (int i = 1; i <= number_of_enemies; i++)
        {
            if (i == 1 && enemy1.isAlive())
                std::cout << "1." << enemy1 << "\t";
            else if (i == 2 && enemy2.isAlive())
                std::cout << "2." << enemy2 << "\t";
            else if (i == 3 && enemy3.isAlive())
                std::cout << "3." << enemy3;
        }
        std::cout << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            targeted_enemy = &enemy1;
            return;
            break;
        case 2:
            targeted_enemy = &enemy2;
            return;
            break;
        case 3:
            targeted_enemy = &enemy3;
            return;
            break;

        default:
            std::cout << "Choose a proper number.\n";
            break;
        }
    }
}

bool Battle::attackmenu(std::vector<Skill*> attacks_)
{
    int choice, confirm;
    while (true)
    {
        listAttacks(attacks_);
        std::cout << "0 to go back.\n";
        std::cin >> choice;
        if (choice == 0)
            return false;
        std::cout << attacks_.at(choice - 1)->getDescription() << std::endl
                  << "Press " << choice << " again to confirm.\n";
        std::cin >> confirm;
        if (choice == confirm)
        {
            chooseEnemy();
            if (attacks_.at(choice - 1)->useSkill())
                return true;
        }
    }
}

void Battle::entryMsg()
{
    std::cout << enemy1.getName();
    if (number_of_enemies == 2)
    {
        std::cout << " and ";
    }
    else if (number_of_enemies == 3)
    {
        std::cout << ", ";
    }
    if (number_of_enemies != 1)
        std::cout << enemy2.getName();
    if (number_of_enemies == 3)
    {
        std::cout << " and " << enemy3.getName();
    }
    std::cout << " appeared!\n\n";
}

void Battle::roundMenu()
{
    while (true)
    {
        std::cout << "Health: ";
        MC.showHealth();
        std::cout << "\t Mana: ";
        MC.showMana();
        std::cout << "1.Attack    2.Skill    3.Use potion" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (attackmenu(attacks))
                return;
            break;
        case 2:
            if (attackmenu(skills))
                return;
            break;
        case 3:
            if (eq.usePotion())
                return;
        default:
            break;
        }
    }
}

void Battle::enemyAttack()
{
    std::srand(std::time(NULL));
    int attack_choice = std::rand() % enemy_attacks.size();
    skills.at(attack_choice)->useEnemySkill();
}

int Battle::endOfRoundSummary()
{
    if (enemy1.getCurrentHealth() == 0)
    {
        enemy1.kill();
        std::cout << enemy1.getName() << " died!\n";
        MC.gainXP(enemy1.getXP());
    }
    if (enemy2.getCurrentHealth() == 0)
    {
        enemy2.kill();
        std::cout << enemy2.getName() << " died!\n";
        MC.gainXP(enemy2.getXP());
    }
    if (enemy3.getCurrentHealth() == 0)
    {
        enemy3.kill();
        std::cout << enemy3.getName() << " died!\n";
        MC.gainXP(enemy3.getXP());
    }
    if (MC.getCurrentHealth() == 0)
    {
        std::cout << "You died...";
        return 2;
    }
    if (!enemy1.isAlive() && !enemy2.isAlive() && !enemy3.isAlive())
    {
        std::cout << "Victory!\n";
        return 1;
    }
    return 0;
}

bool Battle::runWholeBattle()
{
    entryMsg();
    while (true)
    {
        roundMenu();
        if (endOfRoundSummary() == 1)
        {
            eq.getEquippedArmour()->resetBuffs();
            return true;
        }
        enemyAttack();
        if (endOfRoundSummary() == 2)
        {
            eq.getEquippedArmour()->resetBuffs();
            return false;
        }
    }
}
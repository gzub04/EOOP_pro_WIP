#include "Loot.hpp"

Loot::Loot(Inventory& eq, std::vector<Weapon*> allWeapons, std::vector<Armour*> allArmour, std::vector<Potion*> allPotions, int number_of_enemies) : eq(eq), allWeapons(allWeapons), allArmour(allArmour), allPotions(allPotions), number_of_enemies(number_of_enemies) {}

Loot::~Loot() {}

void Loot::getLoot()
{
    std::srand(std::time(NULL));
    if (number_of_enemies == 1)
    {
        loot_rolls = rand()%2;
    }
    else if (number_of_enemies == 2)
    {
        loot_rolls = rand()%2 + 1;
    }
    else
    {
        loot_rolls = 2;
    }
    int random;
    for (int i = 0; i < loot_rolls; i++)
    {
        random = rand()%3;
        if (random == 0)
        {
            random = rand()%allWeapons.size();
            eq.addWeapon(*allWeapons.at(random));
            std::cout << "You found a " << allWeapons.at(random)->getName() << "!\n";
        }
        else if (random == 1)
        {
            random = rand()%allArmour.size();
            eq.addArmour(*allArmour.at(random));
            std::cout << "You found a " << allArmour.at(random)->getName() << "!\n";
        }
        else if (random == 2)
        {
            random = rand()%allPotions.size();
            eq.addPotion(*allPotions.at(random));
            std::cout << "You found a " << allPotions.at(random)->getName() << "!\n";
        }
    }    
}
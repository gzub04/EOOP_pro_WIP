#include "Inventory.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "Skill.hpp"
#include "Battle.hpp"
#include "Room.hpp"
#include "Shop.hpp"
#include "Loot.hpp"

int smallMenu()
{
    int choice;
    std::cout << "1.Browse inventory    2.Move forward\n";
    std::cin >> choice;
    return choice;
}

int main()
{
    //  Welcome message

    Character MC(20, 15, 20);
    // Weapons
    std::vector<Weapon*> allWeapons;
    Weapon simple_sword("Simple sword", 5, "physical", 4);
    allWeapons.push_back(&simple_sword);
    Weapon iron_swan("Iron Swan", 8, "physical", 7);
    allWeapons.push_back(&iron_swan);
    Weapon Burning_justice("Burning Justice", 18, "magical", 23);
    allWeapons.push_back(&Burning_justice);
    Weapon Demon_Slayer("Demon Slayer", 20, "physical", 26);
    allWeapons.push_back(&Demon_Slayer);

    // Armour
    std::vector<Armour*> allArmour;
    Armour sturdy_vest("Sturdy vest", "light", 10, 10, 3);
    allArmour.push_back(&sturdy_vest);
    Armour chainmail("Chainmail", "medium", 30, 9, 10);
    allArmour.push_back(&chainmail);
    Armour Magical_imbued_cape("Magic imbued cape", "light", 10, 60, 14);
    allArmour.push_back(&Magical_imbued_cape);
    Armour fullPlateArmour("Full plate armour", "heavy", 70, 60, 38);
    allArmour.push_back(&fullPlateArmour);

    // Potions
    std::vector<Potion*> allPotions;
    Potion minor_healing("Potion of minor healing", "heal", 7, 3, &MC);
    allPotions.push_back(&minor_healing);
    Potion minor_mana("Small potion of mana regen", "manaRegen", 5, 4, &MC);
    allPotions.push_back(&minor_mana);
    Potion healing("Potion of healing", "heal", 15, 9, &MC);
    allPotions.push_back(&healing);
    Potion manaPotion("Potion of mana regeneration", "manaRegen", 13, 10, &MC);
    allPotions.push_back(&manaPotion);
    Potion buffAtk("Potion of empowered attacks", "buffAtk", 20, 13, &MC);
    allPotions.push_back(&buffAtk);
    Potion buffRes("Stone skin", "buffRes", 20, 13, &MC);
    allPotions.push_back(&buffRes);

    Inventory eq(*allWeapons.at(0), *allArmour.at(0), *allPotions.at(0), *allPotions.at(1));

    // Attacks
    std::vector<Skill*> allAttacks;
    Skill slash("Slash", "targeted", "physical", 3, 0, MC, &eq);
    allAttacks.push_back(&slash);
    Skill spin_to_win("Spin to win", "AOE", "physical", 0, 0, MC, &eq);
    allAttacks.push_back(&spin_to_win);

    // Skills
    std::vector<Skill*> allSkills;
    Skill fireball("Fireball", "targeted", "magical", 15, 5, MC, &eq);
    allSkills.push_back(&fireball);
    Skill earthquake("Earthquake", "AOE", "physical", 15, 9, MC, &eq);  // will be added later

    // Enemy attakcs
    std::vector<Skill*> allEnemySkills;
    Skill punch("punch", "targeted", "physical", 5, 0, MC, &eq);
    allEnemySkills.push_back(&punch);
    Skill kick("kick", "targeted", "physical", 7, 0, MC, &eq);
    allEnemySkills.push_back(&kick);

    // Enemies
    Enemy goblin("Goblin", 12, 30, 10, 20, 1, 10);
    Enemy bandit("Bandit", 15, 20, 30, 10, 1, 20);
    

    std::cout << "You start your journey here. Choose what to do:" << std::endl;
    int choice;
    while (true)
    {
        choice = smallMenu();
        if (choice == 1)
        {
            eq.BrowseInventory();
        }
        else if (choice == 2)
            break;
    }
    Room room1("hostile");
    std::string roomdescription = "You enter a dark room. You can't see much, but you move on. Suddenly you stumble upon something... or somebody\n";
    room1.setDescription(roomdescription);
    room1.getDescription();
    Battle battle1(MC, eq, allAttacks, allSkills, allEnemySkills, 1, goblin);
    Loot newloot(eq, allWeapons, allArmour, allPotions, 1);
    if (battle1.runWholeBattle() == false)
        {
            char w;
            std::cout << "Press any button to quit\n";
            std::cin >> w;
        }
    newloot.getLoot();
    if ( MC.getLevel() > 2)
    {
        allSkills.push_back(&earthquake);
        std::cout << "You got a new ability!\n";
    }
    Room room2("hostile");
    while (true)
    {
        choice = smallMenu();
        if (choice == 1)
        {
            eq.BrowseInventory();
        }
        else if (choice == 2)
            break;
    }
    roomdescription = "It's bright and new enemies are already rushing towards you\n";
    room2.getDescription();
    Battle battle2(MC, eq, allAttacks, allSkills, allEnemySkills, 2, goblin, bandit);
    Loot newloot2(eq, allWeapons, allArmour, allPotions, 2);
    if (battle1.runWholeBattle() == false)
        {
            char w;
            std::cout << "Press any button to quit\n";
            std::cin >> w;
        }
    newloot2.getLoot();
    if ( MC.getLevel() > 2)
    {
        allSkills.push_back(&earthquake);
        std::cout << "You got a new ability!\n";
    }
    std::cout << "You move on to the next room\n";
    roomdescription = "It's a shop! Finally you can catch a breath\n";
    Room room3("shop");
    room3.setDescription(roomdescription);
    room3.getDescription();
    Shop shop(simple_sword, Burning_justice, chainmail, fullPlateArmour, buffRes, healing, eq); // should be randomly generated, but I run out of time
    Room room4("hostile");
    std::cout << "The final battle awaits\n";
    roomdescription = "You enter a rather big corridor where 3 bandits were already waiting for you\n";
    room4.setDescription(roomdescription);
    room4.getDescription();
    Battle battle3(MC, eq, allAttacks, allSkills, allEnemySkills, 2, goblin, bandit);
    Loot newloot3(eq, allWeapons, allArmour, allPotions, 2);
    if (battle1.runWholeBattle() == false)
        {
            char w;
            std::cout << "Press any button to quit\n";
            std::cin >> w;
        }
    newloot3.getLoot();
    if ( MC.getLevel() > 2)
    {
        allSkills.push_back(&earthquake);
        std::cout << "You got a new ability!\n";
    }
    std::cout << "Thank you for playing this Demo! :)\n";
    getchar();
    return 0;
}
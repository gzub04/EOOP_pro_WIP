#include "Inventory.hpp"

template <class T>
int findItem(std::vector<T> list, T item) // if item doesn't exist, returns -1
{
    for (unsigned int i = 0; i < list.size(); i++)
    {
        if (list.at(i) == item)
            return i;
    }
    return -1;
}

template <class T>
void listItems(std::vector<T> list)
{
    for (unsigned int i = 0; i < list.size(); i++)
    {
        std::cout << i + 1 << "." << list.at(i).getName() << "\t";
        if ((i + 1) % 4)
            std::cout << std::endl;
        else if ((i + 1) == list.size())
            std::cout << std::endl;
    }
}

Inventory::Inventory(Weapon firstWeapon, Armour firstArmour, Potion two_starting_potions, Potion starting_potion2)
{
    vWeapons.push_back(firstWeapon);
    vArmour.push_back(firstArmour);
    equippedWeapon = vWeapons.data();
    equippedArmour = vArmour.data();
    addPotion(two_starting_potions);
    addPotion(two_starting_potions);
    addPotion(starting_potion2);
}

Inventory::~Inventory() {}

void Inventory::addWeapon(Weapon newWeapon)
{
    int i = findItem(vWeapons, newWeapon);
    if (i == -1)
    {
        vWeapons.push_back(newWeapon);
        return;
    }
    vWeapons.at(i).addItem(1);
}

void Inventory::removeWeapon(Weapon weapon)
{
    int i = findItem(vWeapons, weapon);
    vWeapons.at(i).addItem(-1);
    if (!vWeapons.at(i).getQuantity())
        vWeapons.erase(vWeapons.begin() + i);
}

void Inventory::addArmour(Armour newArmour)
{
    int i = findItem(vArmour, newArmour);
    if (i == -1)
    {
        vArmour.push_back(newArmour);
        return;
    }
    vArmour.at(i).addItem(1);
}

void Inventory::removeArmour(Armour armour)
{
    int i = findItem(vArmour, armour);
    vArmour.at(i).addItem(-1);
    if (!vArmour.at(i).getQuantity())
        vArmour.erase(vArmour.begin() + i);
}

void Inventory::addPotion(Potion newPotion)
{
    int i = findItem(vPotions, newPotion);
    if (i == -1)
    {
        vPotions.push_back(newPotion);
        return;
    }
    vPotions.at(i).addItem(1);
}

void Inventory::removePotion(Potion potion)
{
    int i = findItem(vPotions, potion);
    vPotions.at(i).addItem(-1);
    if (!vPotions.at(i).getQuantity())
        vPotions.erase(vPotions.begin() + i);
}

bool Inventory::usePotion()
{
    int choice, confirm;

    while (true)
    {
        listItems(vPotions);
        while (true)
        {
            std::cout << "Choose potion or press 0 to go back.\n";
            std::cin >> choice;
            if (choice == 0)
                return false;
            vPotions.at(choice - 1).getDescription();
            std::cout << "Press " << choice << " again to use.\n";
            std::cin >> confirm;
            if (choice == confirm)
            {
                std::string purpose;
                purpose = vPotions.at(choice - 1).getPurpose();
                if (purpose == "heal" && vPotions.at(choice - 1).heal())
                {
                    removePotion(vPotions.at(choice - 1));
                    return true;
                }
                else if (purpose == "buffRes" && vPotions.at(choice - 1).buffRes(getEquippedArmour()))
                {
                    removePotion(vPotions.at(choice - 1));
                    return true;
                }
                else if (purpose == "buffAtk" && vPotions.at(choice - 1).buffAtk(getEquippedWeapon()))
                {
                    removePotion(vPotions.at(choice - 1));
                    return true;
                }
            }
        }
    }
}

Weapon *Inventory::getEquippedWeapon()
{
    return equippedWeapon;
}

Armour *Inventory::getEquippedArmour()
{
    return equippedArmour;
}

void Inventory::listWeaponsWithPrices()
{
    for (unsigned int i = 0; i < vWeapons.size(); i++)
    {
        std::cout << i + 1 << "." << vWeapons.at(i).getName() << " " << vWeapons.at(i).getPrice() << "$" << "\t";
        if ((i + 1) % 4)
            std::cout << std::endl;
        else if ((i + 1) == vWeapons.size())
            std::cout << std::endl;
    }
}

void Inventory::listArmourWithPrices()
{
    for (unsigned int i = 0; i < vArmour.size(); i++)
    {
        std::cout << i + 1 << "." << vArmour.at(i).getName() << " " << vArmour.at(i).getPrice() << "$" << "\t";
        if ((i + 1) % 4)
            std::cout << std::endl;
        else if ((i + 1) == vArmour.size())
            std::cout << std::endl;
    }
}

void Inventory::listPotionsWithPrices()
{
    for (unsigned int i = 0; i < vPotions.size(); i++)
    {
        std::cout << i + 1 << "." << vPotions.at(i).getName() << " " << vPotions.at(i).getPrice() << "$" << "\t";
        if ((i + 1) % 4)
            std::cout << std::endl;
        else if ((i + 1) == vPotions.size())
            std::cout << std::endl;
    }
}

void Inventory::sellWeapon(int i)
{
    addMoney(vWeapons.at(i).getPrice()*0.8);
    removeWeapon(vWeapons.at(i));
}

void Inventory::sellArmour(int i)
{
    addMoney(vWeapons.at(i).getPrice() * 0.8);
    removeArmour(vArmour.at(i));
}

void Inventory::sellPotion(int i)
{
    addMoney(vWeapons.at(i).getPrice() * 0.8);
    removePotion(vPotions.at(i));
}

void Inventory::BrowseInventory()
{
    std::cout << "1.Weapons    2.Armour    3. Potions    0.Back\n";
    int choice, choice2;
    std::cin >> choice;
    while (true)
    {
        switch (choice)
        {
        case 1:
            while (true)
            {
                listItems(vWeapons);
                std::cout << "Choose the weapon or press 0 to go back.\n";
                std::cin >> choice;
                vWeapons.at(choice - 1).getDescription();
                std::cout << "Press " << choice << " again to equip.\n";
                std::cin >> choice2;
                if (choice == choice2)
                {
                    *equippedWeapon = vWeapons.at(choice - 1);
                    break;
                }
                else if (choice2 == 0)
                    break;
            }
            break;
        case 2:
            while (true)
            {
                listItems(vArmour);
                std::cout << "Choose the armour or press 0 to go back.\n";
                std::cin >> choice;
                vArmour.at(choice - 1).getDescription();
                std::cout << "Press " << choice << " again to equip.\n";
                std::cin >> choice2;
                if (choice == choice2)
                {
                    *equippedArmour = vArmour.at(choice - 1);
                    break;
                }
                else if (choice2 == 0)
                    break;
            }
            break;
        case 3:
            while (true)
            {
                listItems(vPotions);
                std::cout << "Choose potion or press 0 to go back.\n";
                std::cin >> choice;
                vPotions.at(choice - 1).getDescription();
                std::cout << "Press " << choice << " again to use.\n";
                std::cin >> choice2;
                if (choice == choice2 && vPotions.at(choice - 1).getPurpose() == "heal")
                {
                    vPotions.at(choice - 1).heal();
                    break;
                }
                else if (choice2 == 0)
                    break;
            }
            break;

        default:
            return;
        }
    }
}

void Inventory::addMoney(unsigned int value)
{
    money += value;
}

bool Inventory::spendMoney(unsigned int value)
{
    if (value > money)
        return false;
    else
    {
        money -= value;
        return true;
    }
}
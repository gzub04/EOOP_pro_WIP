#include "Shop.hpp"

Shop::Shop(Weapon weapon1, Weapon weapon2, Armour armour1, Armour armour2, Potion potion1, Potion potion2, Inventory &eq) : weapon1(weapon1), weapon2(weapon2), armour1(armour1), armour2(armour2), potion1(potion1), potion2(potion2), eq(eq) {}

Shop::~Shop() {}

void Shop::sellmenu()
{
    int choice;
    while (true)
    {
        std::cout << "1.Weapons    2.Armour    3.Potions    0.Return\n";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            return;
            break;
        case 1:
            eq.listWeaponsWithPrices();
            std::cin >> choice;
            if (choice == 0)
                return;
            eq.sellWeapon(choice - 1);
            break;
        case 2:
            eq.listArmourWithPrices();
            std::cin >> choice;
            if (choice == 0)
                return;
            eq.sellArmour(choice - 1);
            break;
        case 3:
            eq.listPotionsWithPrices();
            std::cin >> choice;
            if (choice == 0)
                return;
            eq.sellPotion(choice - 1);
            break;

        default:
            break;
        
        }
    }
}

void Shop::menu()
{
    int choice, confirm;
    std::cout << "Welcome to my shop! Do you want to buy something?" << std::endl;
    while (true)
    {
        std::cout << "1." << weapon1.getName() << " " << weapon1.getPrice() << "$\t2." << weapon2.getName() << " " << weapon2.getPrice() << "$" << std::endl
                  << "3." << armour1.getName() << " " << armour1.getPrice() << "$\t4." << armour2.getName() << " " << armour2.getPrice() << "$" << std::endl
                  << "5." << potion1.getName() << " " << potion1.getPrice() << "$\t6." << potion2.getName() << " " << potion2.getPrice() << "$" << std::endl
                  << "7. to open sell menu, 0. to exit the shop\n";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Thank you for visiting my shop!\n";
            return;
            break;
        case 1:
            std::cout << weapon1.getDescription();
            break;
        case 2:
            std::cout << weapon2.getDescription();
            break;
        case 3:
            std::cout << armour1.getDescription();
            break;
        case 4:
            std::cout << armour2.getDescription();
            break;
        case 5:
            std::cout << potion1.getDescription();
            break;
        case 6:
            std::cout << potion2.getDescription();
            break;
        case 7:

        default:
            break;
        }
        std::cout << "To confirm the choice, type " << choice << " again.\n";
        std::cin >> confirm;
        if (choice == confirm)
        {
            switch (choice)
            {
            case 1:
                if (eq.spendMoney(weapon1.getPrice()))
                {
                    eq.addWeapon(weapon1);
                    std::cout << "You bought " << weapon1.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;
            case 2:
                if (eq.spendMoney(weapon2.getPrice()))
                {
                    eq.addWeapon(weapon2);
                    std::cout << "You bought " << weapon2.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;
            case 3:
                if (eq.spendMoney(armour1.getPrice()))
                {
                    eq.addArmour(armour1);
                    std::cout << "You bought " << armour1.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;
            case 4:
                if (eq.spendMoney(armour2.getPrice()))
                {
                    eq.addArmour(armour2);
                    std::cout << "You bought " << armour2.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;
            case 5:
                if (eq.spendMoney(potion1.getPrice()))
                {
                    eq.addPotion(potion1);
                    std::cout << "You bought " << potion1.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;
            case 6:
                if (eq.spendMoney(potion2.getPrice()))
                {
                    eq.addPotion(potion2);
                    std::cout << "You bought " << potion2.getName() << ".\n";
                }
                else
                    std::cout << "You don't have enough money!\n";
                break;

            default:
                break;
            }
        }
    }
}
#include "Potion.hpp"

Potion::Potion(std::string name, std::string purpose, int value, int price, Character *MC) : purpose(purpose), value(value), MC(MC)
{
    setName(name);
    setPrice(price);
}

Potion::~Potion() {}

std::string Potion::getPurpose()
{
    return purpose;
}

bool Potion::heal()
{
    if (purpose == "heal")
    {
        int newCurrentHealth = MC->getCurrentHealth() + value;
        if (MC->getCurrentHealth() == MC->getMaxHealth())
        {
            std::cout << "You are already full health!";
            return false;
        }
        else if (newCurrentHealth >= MC->getMaxHealth())
        {
            MC->setCurrentHealth(MC->getMaxHealth());
        }
        else
        {
            MC->changeHealth(value);
        }
        std::cout << "You now have " << MC->getCurrentHealth() << " health.\n";
        return true;
    }
    else
    {
        std::cout << "Wrong purpose: heal.\n";
        return false;
    }
}

bool Potion::manaRegen()
{
    if (purpose == "manaRegen")
    {
        int newCurrentMana = MC->getCurrentMana() + value;
        if (MC->getCurrentMana() == MC->getMaxMana())
        {
            std::cout << "You already have full mana!\n";
            return false;
        }
        else if (newCurrentMana >= MC->getMaxMana())
        {
            MC->setCurrentMana(MC->getMaxMana());
        }
        else
        {
            MC->removeMana(-value);
        }
        std::cout << "You now have " << MC->getCurrentMana() << " mana.\n";
        return true;
    }
    else
    {
        std::cout << "Wrong purpose: mana.\n";
        return false;
    }
    
}

bool Potion::buffRes(Armour *armour)
{
    if (purpose == "buffRes")
    {
        armour->buffResistances(value);
        std::cout << "Resistance increased!\n";
        return true;
    }
    else
    {
        std::cout << "Wrong purpose: buffRes.\n";
        return false;
    }
}

bool Potion::buffAtk(Weapon *weapon)
{
    if (purpose == "buffAtk")
    {
        weapon->buffDamage(value);
        return true;
    }
    else
    {
        std::cout << "Wrong purpose: buffAtk.\n";
        return false;
    }
}

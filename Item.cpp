#include "Item.hpp"

Item::Item() {}

Item::~Item() {}

void Item::setName(std::string newName)
{
    name = newName;
}

std::string Item::getName() const
{
    return name;
}
/*
void Item::setQuantity(unsigned int newQuantity)
{
    quantity = newQuantity;
}
*/
int Item::getQuantity() const
{
    return quantity;
}

void Item::addItem(int amount)
{
    if (quantity + amount < 0)
    {
        std::cerr << "Somehow you got negative quantitiy\n";
        quantity = 0;
    }
    else
        quantity += amount;
}

void Item::setPrice(int newPrice)
{
    price = newPrice;
}

int Item::getPrice()
{
    return price;
}
/*
void Item::setRarity(int newRarity)
{
    rarity = newRarity;
}

int Item::getRarity()
{
    return rarity;
}
*/
void Item::setDescription(std::string newDescription)
{
    newDescription = description;
}

std::string Item::getDescription() const
{
    return description;
}

bool Item::operator==(const Item &item)
{
    if (this->name == item.name)
        return true;
    else
        return false;
}
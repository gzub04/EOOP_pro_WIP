#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
class Item
{
private:
    std::string name;
    int quantity = 1;
    int price;
    //int rarity;
    std::string description;

public:
    Item();
    ~Item();
    void setName(std::string newName);
    std::string getName() const;
    int getQuantity() const;
    void addItem(int amount);
    void setPrice(int newPrice);
    int getPrice();
    //void setRarity(int newRarity);
    //int getRarity();
    void setDescription(std::string newDescription);
    std::string getDescription() const;
    bool operator==(const Item& item);
};

#endif
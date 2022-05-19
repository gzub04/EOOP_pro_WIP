#ifndef ARMOUR_HPP
#define ARMOUR_HPP

#include "Item.hpp"

class Armour : public Item
{
private:
    std::string ArmourClass; // light/medium/heavy
    int PhysicalRes;
    int MagicRes;
    int preBuffPhysRes;
    int preBuffMagicRes;

public:
    Armour(std::string name, std::string ArmourClass, int PhysicalRes, int MagicRes, int price);
    ~Armour();
    std::string getClass() const;
    //void setPhysicalRes(int newPhysicalRes);
    //int getPhysicalRes() const;
    //void setMagicRes(int newMagicRes);
    //int getMagicRes() const;
    int getResistance(std::string type);
    void buffResistances(int value);
    void resetBuffs();
};

#endif
#include "Armour.hpp"

Armour::Armour(std::string name, std::string ArmourClass, int PhysicalRes, int MagicRes, int price) : ArmourClass(ArmourClass), PhysicalRes(PhysicalRes), MagicRes(MagicRes), preBuffPhysRes(PhysicalRes), preBuffMagicRes(MagicRes)
{
    setName(name);
    setPrice(price);
}

Armour::~Armour() {}

std::string Armour::getClass() const
{
    return ArmourClass;
}
/*
int Armour::getPhysicalRes() const
{
    return PhysicalRes;
}

int Armour::getMagicRes() const
{
    return MagicRes;
}
*/
int Armour::getResistance(std::string type)
{
    if(type == "physical")
        return PhysicalRes;
    else if(type == "magical")
        return MagicRes;
        else
        {
            std::cout << "Wrong resistance name in Armour.cpp\n";
            return -1;
        }
        
}

void Armour::buffResistances(int value)
{
    PhysicalRes += PhysicalRes * value/100;
    MagicRes += MagicRes * value/100;
}

void Armour::resetBuffs()
{
    PhysicalRes = preBuffPhysRes;
    MagicRes = preBuffMagicRes;
}
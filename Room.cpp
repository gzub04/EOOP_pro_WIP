#include "Room.hpp"

Room::Room(std::string type) : type(type) {}

Room::~Room() {}

std::string Room::getType()
{
    return type;
}

void Room::setDescription(std::string newDescription)
{
    description = newDescription;
}

std::string Room::getDescription()
{
    return description;
}
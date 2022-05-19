#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>

class Room
{
private:
    std::string type; // hostile/shop
    std::string description;

public:
    Room(std::string type);
    ~Room();
    std::string getType();
    void setDescription(std::string newDescription);
    std::string getDescription();
};

#endif
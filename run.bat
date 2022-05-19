@ECHO OFF
g++ -Wall -Wextra -pedantic Common_for_units.hpp Character.hpp Enemy.hpp Item.hpp Weapon.hpp Armour.hpp Potion.hpp Inventory.hpp Skill.hpp Battle.hpp Shop.hpp Loot.hpp Room.hpp
g++ -Wall -Wextra -pedantic Common_for_units.cpp Character.cpp Enemy.cpp Item.cpp Weapon.cpp Armour.cpp Potion.cpp Inventory.cpp Skill.cpp Battle.cpp Shop.cpp Loot.cpp Room.cpp main.cpp -o run.exe
PAUSE
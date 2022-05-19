# EOOP project - Text game in terminal (WIP)
This project was created for **Object-Oriented Programming** classes at Warsaw University of Technology. Currently work in progress.
## General description
The keyword for my EOOP project is “Adventure game”, a simple console-based text game. The game will be divided into few floors, where each floor contains 12 rooms with either enemies, items (those rooms may or may not be trapped) or a shop. On each floor there is guarantee of at least one shop and there will be between 1-3 rooms with items. The player will level up, collect equipment, and learn new skills while progressing through the floors. At the end of each floor there will be a boss battle with the final enemy on the last floor. When entering certain rooms there will be some additional narration to add some story to keep the game interesting.
For that project I have created a total of 9 classes, the most important being “Character.hpp”, containing all the information about player, his stats and equipment. The class “Item.hpp” was only made to shorten the code as 3 other classes, “Weapon.hpp”, “Armour.hpp” and “Potion.hpp”, inherit this class. ”Enemy.hpp” is used to create new enemies and “Skill.hpp” is used to make a new skill or attack that the player or enemy will use. The “Room.hpp” creates a new room, either a room with up to 3 enemies, items (may or may not be trapped) or a shop.
## Memory map
memory_map.pdf contains a memory map, which purpose is to give overview over the project.
## Class declaration
Each class declaration is in a separate header while methods will be in cpp files with the same name as the header file. For example, methods to the class declared in “Character.hpp” will be in “Character.cpp”.  
Additional information about specific classes  
- Character.hpp
  -	Player’s inventory will be stored in vectors and the size of it will be increased as player gains new items.
  -	LevelUp() method will change current XP to 0, increment level by 1 and change LevelUpReq to a higher value.
  -	Strength, Intelligence and Agility are statistics from which depend how effective you will be with certain weapons; also they slightly affect max health, mana and dodge chance/speed.
  -	Speed affects how often player can attack in battle.
- Weapon.hpp
  -	Scaling[3] will contain the information how much player’s strength/intelligence/agility will increase the effectiveness of the weapon.
  -	Some weapons will have a chance to stun, disabling the enemy for one turn.
- Armour.hpp
  -	Depending on ArmourClass there will be different boosts: light armour grants additional speed and dodgechance, heavy decreases speed/dodge chance but grants great boost in resistances, medium will be the balance between the two.
- Skill.hpp
  -	There are 5 types of skills: damaging ones, applying bleed, buffs, debuffs and healing.
  -	Skills can be used by either the player or enemies.
  -	Note: Not all skills will require mana
- Room.hpp
  -	Room can be either with hostiles, items or can be a shop.
  -	In hostile rooms loot will depend on the killed enemies, in item room there will be between 1 and 2 items (may be trapped) and in shop there will be always 6 items to choose from, 2 weapons, 2 armour pieces and 2 potions (this values may change).
- Map.hpp
  -	Each floor consists of 12 rooms, once reaching the last room with the boss battle, the next floor will overwrite the rooms on the previous floor.
  -	There will be 1, max 2 shops on each floor and between 1 to 3 item rooms. Rest of the rooms are filled with enemies.

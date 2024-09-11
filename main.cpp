#include <iostream>
#include "MonsterFactory.h"

int main()
{
    //Print intro text
    //Let Player create a character
        //Player can choose a class and spend points on stats.
        //Player gets a weapon to start with depending on class
    //Monsters get created in factory
        //at first only create 2-3
            //get stats for monster from Bestiary.csv
    //Player can choose what monster to fight
    //Fight starts
        //Player can choose to either attack or use their ability
        //Every attack the player AND the monster Roll a 1 D20 + their STR stats to determine if the attack hits
            //If the value is higher than the enemies AC the attack hits
        //If the attack hits, damage is calculated based on the equipped weapon + their stats
        //The damage is then subtracted from the HP of the character that got hit

    CMonsterFactory *factory = new CMonsterFactory();
    std::vector<CEntityData> monsters = factory->CreateMonster();
    CEntityData *Player = new CEntityData("Fili", 100, 15, 10,10,10,10,10);

    std::cout << monsters.size() << "\n";
}

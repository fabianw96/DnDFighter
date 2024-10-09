#include <iostream>
#include <memory>
#include "Game.h"
#include "MonsterFactory.h"
#include "raylib.h"
#include "WindowManager.h"
#include "HelperMacros.h"
#include "Weapon.h"

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

    bool bUseRaylib = true;
    const std::unique_ptr<MonsterFactory> factory = std::make_unique<MonsterFactory>();
    const std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>();
    const std::unique_ptr<EntityData> entity_data = std::make_unique<EntityData>();
    const std::unique_ptr<WindowManager> window_manager = std::make_unique<WindowManager>();
    const std::unique_ptr<Game> game = std::make_unique<Game>();

    const std::vector<EntityData> monsters = factory->CreateMonster();
    const std::vector<Weapon> weapons = weapon->CreateWeapons();

    //choose a way to play the game
    std::cout << "Please choose a way to open the game: [0] Peter mode [1] Raylib \n";
    std::cin >> bUseRaylib;

    if (!bUseRaylib)
    {
        const EntityData player = entity_data->CreatePlayer(weapons);
        game->InitGame(player, monsters);
    }
    else
    {
        window_manager->CreateGameWindow();
    }
        
    return 0;
}

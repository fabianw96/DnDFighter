#include <iostream>
#include <memory>
#include "Game.h"
#include "MonsterFactory.h"
#include "raylib.h"
#include "HelperMacros.h"
#include "Weapon.h"

int main()
{
    //create smart pointer for needed classes
    const std::unique_ptr<MonsterFactory> factory = std::make_unique<MonsterFactory>();
    const std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>();
    const std::unique_ptr<EntityData> entity_data = std::make_unique<EntityData>();
    const std::unique_ptr<Game> game = std::make_unique<Game>();

    const std::vector<EntityData> monsters = factory->CreateMonster();
    const std::vector<Weapon> weapons = weapon->CreateWeapons();

    const EntityData player = entity_data->CreatePlayer(weapons);
    game->InitGame(player, monsters);

        
    return 0;
}

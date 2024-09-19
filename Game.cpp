//
// Created by wittg on 18/09/2024.
//

#include "Game.h"
#include "raylib.h"

void Game::InitGame(const CEntityData& player, const std::vector<CEntityData>& monsters)
{
    PopulateMonsterGroups(monsters);

    
}

void Game::PopulateMonsterGroups(const std::vector<CEntityData>& monsters)
{
    for (const auto & monster : monsters)
    {
        if (monster.GetLevel() <= 10)
        {
            lowLevelMonster.emplace_back(monster);
        }
        else if (monster.GetLevel() > 10 && monster.GetLevel() <= 20)
        {
            midLevelMonster.emplace_back(monster);
        }
        else if (monster.GetLevel() > 10 && monster.GetLevel() > 20)
        {
            highLevelMonster.emplace_back(monster);
        }
    }
}





//
// Created by wittg on 18/09/2024.
//

#include "Game.h"

void Game::InitGame(CEntityData& player, std::vector<CEntityData>& monsters)
{
    for (int i = 0; i < monsters.size(); ++i)
    {
        if (monsters.at(i).GetLevel() <= 10)
        {
            lowLevelMonster.emplace_back(monsters.at(i));
        }
        else if (monsters.at(i).GetLevel() > 10 && monsters.at(i).GetLevel() <= 20)
        {
            midLevelMonster.emplace_back(monsters.at(i));
        }
        else if (monsters.at(i).GetLevel() > 10 && monsters.at(i).GetLevel() > 20)
        {
            highLevelMonster.emplace_back(monsters.at(i));
        }
    }
}



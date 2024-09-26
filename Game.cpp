//
// Created by wittg on 18/09/2024.
//

#include "Game.h"


void Game::InitGame(const CEntityData& player, const std::vector<CEntityData>& monsters)
{
    PopulateMonsterGroups(monsters);
    ChooseRandomMonster(player);
}

void Game::PopulateMonsterGroups(const std::vector<CEntityData>& monsters)
{
    for (const auto & monster : monsters)
    {
        if (monster.GetLevel() < 10)
        {
            lowLevelMonster.emplace_back(monster);
        }
        else if (monster.GetLevel() >= 10 && monster.GetLevel() < 15)
        {
            midLevelMonster.emplace_back(monster);
        }
        else
        {
            highLevelMonster.emplace_back(monster);
        }
    }
}

void Game::ChooseRandomMonster(const CEntityData& player)
{
    std::random_device random_device;
    std::mt19937 rng(random_device());

    if (player.GetLevel() <= 10)
    {
        std::uniform_int_distribution<> distribution(0, lowLevelMonster.size());
        StartFight(player, lowLevelMonster[distribution(rng)]);
    }
    else if (player.GetLevel() > 10 && player.GetLevel() < 20)
    {
        std::uniform_int_distribution<> distribution(0, midLevelMonster.size());
        StartFight(player, midLevelMonster[distribution(rng)]);
    }
    else
    {
        std::uniform_int_distribution<> distribution(0, highLevelMonster.size());
        StartFight(player, highLevelMonster[distribution(rng)]);
    }
}

void Game::StartFight(const CEntityData& player, const CEntityData& chosenMonster)
{
    //roll dice for initiative
    //higher init rolls for AC first
    //dmg is dealt if roll is even or higher to enemy AC
    //dmg is then dealt with dmg die
    std::cout << "Today fighting: " << chosenMonster.GetName() << " vs. " << player.GetName() << "\n";
    
    std::cout << Dice::RollDice(DT_D20);
    
}





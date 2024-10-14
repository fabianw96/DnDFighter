//
// Created by wittg on 18/09/2024.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include <random>
#include "EntityData.h"
#include "Dice.h"
#include "Weapon.h"

class Game {
private:
    std::vector<EntityData> m_lowLevelMonster;
    std::vector<EntityData> m_midLevelMonster;
    std::vector<EntityData> m_highLevelMonster;
    
public:
    void InitGame(const EntityData& player, const std::vector<EntityData>& monsters);
    void PopulateMonsterGroups(const std::vector<EntityData>& monsters);
    void ChooseRandomMonster(const EntityData& player);
    void StartFight(const EntityData& player, const EntityData& chosenMonster);
    void Attack(EntityData& attacker, EntityData& defender);
    void Swap(EntityData& attacker, EntityData& defender);
};

#endif //GAME_H

//
// Created by wittg on 18/09/2024.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include <random>
#include "EntityData.h"
#include "raylib.h"
#include "WindowManager.h"

class Game {
private:
    std::vector<CEntityData> lowLevelMonster;
    std::vector<CEntityData> midLevelMonster;
    std::vector<CEntityData> highLevelMonster;
public:
    void InitGame(const CEntityData& player, const std::vector<CEntityData>& monsters);
    void PopulateMonsterGroups(const std::vector<CEntityData>& monsters);
    void ChooseRandomMonster(const CEntityData& player);
    void StartFight(const CEntityData& player, const CEntityData& chosenMonster);
};

#endif //GAME_H

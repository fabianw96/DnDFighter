//
// Created by wittg on 18/09/2024.
//

#ifndef GAME_H
#define GAME_H
#include "EntityData.h"

class Game {
private:
    std::vector<CEntityData> lowLevelMonster;
    std::vector<CEntityData> midLevelMonster;
    std::vector<CEntityData> highLevelMonster;
public:
    void InitGame(const CEntityData& player, const std::vector<CEntityData>& monsters);
    void PopulateMonsterGroups(const std::vector<CEntityData>& monsters);
};

#endif //GAME_H

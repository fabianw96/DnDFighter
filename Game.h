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
    void InitGame(CEntityData& player, std::vector<CEntityData>& monsters);
};

#endif //GAME_H

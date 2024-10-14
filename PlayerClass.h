//
// Created by wittg on 14/10/2024.
//

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <array>
#include <string>
#include <vector>


struct PlayerClass {
    std::string name;
    int baseHealth;
    int baseArmorClass;
    std::array<int, 6> stats;


    PlayerClass() : name(""), baseHealth(0), baseArmorClass(0), stats({0, 0, 0, 0, 0, 0}) {}
    PlayerClass(const std::string& name, int baseHealth, int baseArmorClass, const std::array<int, 6>& stats)
    : name(name), baseHealth(baseHealth), baseArmorClass(baseArmorClass), stats(stats) {}
};
#endif //PLAYERCLASS_H

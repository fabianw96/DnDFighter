//
// Created by wittg on 10/09/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <vector>
#include <string>
#include "CsvReader.h"
#include "Dice.h"

class Weapon {
private:
    std::string m_name;
    EDiceType m_diceType = DT_D6;
public:
    Weapon();
    Weapon(const std::string& a_name, EDiceType a_diceType);
    std::vector<Weapon> CreateWeapons();

    [[nodiscard]] std::string GetName() const { return m_name; }
    [[nodiscard]] EDiceType GetDiceType() const { return m_diceType; }
};

#endif //WEAPON_H

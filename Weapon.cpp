//
// Created by wittg on 10/09/2024.
//

#include "Weapon.h"

Weapon::Weapon() = default;

Weapon::Weapon(const std::string &a_name, EDiceType a_diceType) {
    m_name = a_name;
    m_diceType = a_diceType;
}

std::vector<Weapon> Weapon::CreateWeapons() {
    std::vector<std::pair<std::string, std::vector<int>>> csvData = CsvReader::ReadCsvData("../Weapons.csv");

    std::vector<Weapon> weapons;

    //TODO: Create Weapons

    for (const auto& data: csvData) {
        const std::string& name = data.first;
        const std::vector<int>& diceType = data.second;

        Weapon weapon;

        switch (diceType[0]) {
            case 4:
                weapon = Weapon(name, DT_D4);
                weapons.emplace_back(weapon);
                break;
            case 6:
                weapon = Weapon(name, DT_D6);
                weapons.emplace_back(weapon);
                break;
            case 8:
                weapon = Weapon(name, DT_D8);
                weapons.emplace_back(weapon);
                break;
            case 10:
                weapon = Weapon(name, DT_D10);
                weapons.emplace_back(weapon);
                break;
            case 12:
                weapon = Weapon(name, DT_D12);
                weapons.emplace_back(weapon);
                break;
            default:
                std::cout << "Error: Dice type for Weapon: " << name << " not found!\n";
                break;
        }
    }

    return weapons;
}

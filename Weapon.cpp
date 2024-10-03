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



    }

    return weapons;

}

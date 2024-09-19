#include "MonsterFactory.h"
#include "EntityData.h"
#include <iostream>
#include <numeric>
#include <vector>


std::vector<CEntityData> CMonsterFactory::CreateMonster()
{
	CEntityData *entity_data = new CEntityData();
	
	std::vector<std::pair<std::string, std::vector<int>>> MonsterData = entity_data->ReadCsvData("../Bestiary.csv");

	std::vector<CEntityData> monsters;

	for (const auto& monster_data: MonsterData)
	{
		const std::string& name = monster_data.first;
		const std::vector<int>& stats = monster_data.second;

		if (stats.size() >= 9)
		{
			CEntityData monster(name, static_cast<float>(stats[0]), stats[1], stats[2], stats[3], stats[4], stats[5], stats[6], stats[7], stats[8]);
			monsters.emplace_back(monster);
		}
		else {
			std::cerr << "Error: Stats for Monster : " << name << " not found!\n";
		}
	}

	return monsters;
}


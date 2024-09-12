#include "MonsterFactory.h"
#include "EntityData.h"
#include <iostream>
#include <numeric>
#include <vector>


std::vector<CEntityData> CMonsterFactory::CreateMonster()
{
	CEntityData *entity_data = new CEntityData();
	
	std::vector<std::pair<std::string, std::vector<int>>> MonsterData = entity_data->ReadCsvData("../Bestiary.csv");

	//iterate through MonsterData and create a new monster for every entry in the Vector. Then save it to a new vector.

	std::vector<CEntityData> monsters;

	for (const auto& monster_data: MonsterData)
	{
		const std::string& name = monster_data.first;
		const std::vector<int>& stats = monster_data.second;

		int combinedStats = std::accumulate(stats.begin(), stats.end(),0);
		std::cout << combinedStats << "\n";

		if (stats.size() >= 8)
		{
			CEntityData monster(name, static_cast<float>(stats[0]), stats[1], stats[2], stats[3], stats[4], stats[5], stats[6], stats[7]);
			monsters.emplace_back(monster);
		}
		else {
			std::cerr << "Error: Stats for Monster : " << name << " not found!\n";
		}
	}

	return monsters;
}


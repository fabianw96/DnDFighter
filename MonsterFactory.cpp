#include "MonsterFactory.h"


//read data from CSV and create monster from data
std::vector<EntityData> MonsterFactory::CreateMonster()
{
	std::vector<std::pair<std::string, std::vector<int>>> csvData = CsvReader::ReadCsvData("../Bestiary.csv");
	const PlayerClass defaultMonsterClass = {"Monster",0,0,{0,0,0,0,0,0,}};

	std::vector<EntityData> monsters;

	for (const auto& monster_data: csvData)
	{
		const std::string& name = monster_data.first;
		const std::vector<int>& stats = monster_data.second;

		if (stats.size() >= 9)
		{
			EntityData monster(name, stats[0], stats[1], stats[2], stats[3], stats[4], stats[5],
			                   stats[6], stats[7], Weapon(), stats[8], true, false, defaultMonsterClass);
			monsters.emplace_back(monster);
		}
		else {
			std::cerr << "Error: Stats for Monster : " << name << " not found!\n";
		}
	}
	return monsters;
}


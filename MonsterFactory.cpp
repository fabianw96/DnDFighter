#include "MonsterFactory.h"
#include "EntityData.h"
#include <iostream>
#include <vector>

void MonsterFactory::CreateMonster()
{
	//read values from CSV to create all monsters at game start
	EntityData *entity_data = new EntityData;
	std::vector<std::pair<std::string, std::vector<int>>> MonsterData = entity_data->readCsvData("D:/Fabian/DnDFighter/Bestiary.csv");


	for (auto monster_data : MonsterData)
	{
		std::cout << monster_data.first;
	}
}


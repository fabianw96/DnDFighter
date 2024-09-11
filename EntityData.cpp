#include <iostream>
#include "EntityData.h"

CEntityData::CEntityData() = default;


CEntityData::CEntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, bool a_isAlive)
{
	m_Name = a_name;
	m_HealthPoints = a_healthPoints;
	m_ArmorClass = a_armorClass;
	m_Strength = a_strength;
	m_Dexterity = a_dexterity;
	m_Constitution = a_constitution;
	m_Intelligence = a_intelligence;
	m_Wisdom = a_wisdom;
	m_BIsAlive = a_isAlive;
}

std::vector<std::pair<std::string, std::vector<int>>> CEntityData::ReadCsvData(const std::string& filename)
{
	std::vector<std::pair<std::string, std::vector<int>>> resultData;

	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) throw std::runtime_error("Could not open CSV ");

	std::string line;
	std::string colname;
	int value;

	if (inputFile.good())
	{
		std::getline(inputFile, line);

		std::stringstream ss(line);

		while (std::getline(ss, colname, ','))
		{
			resultData.emplace_back(colname, std::vector<int> {});
		}
	}

	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);

		int colIdx = 0;

		while (ss >> value)
		{
			resultData.at(colIdx).second.emplace_back(value);

			if (ss.peek() == ',') ss.ignore();

			colIdx++;
		}
	}

	inputFile.close();

	return resultData;
}



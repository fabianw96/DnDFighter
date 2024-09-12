#include <iostream>
#include <algorithm>
#include "EntityData.h"
#include "HelperMacros.h"

CEntityData::CEntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, int a_charisma, int a_level, bool a_isAlive)
{
	m_sName = a_name;
	m_iHealthPoints = a_healthPoints;
	m_iArmorClass = a_armorClass;
	m_iStrength = a_strength;
	m_iDexterity = a_dexterity;
	m_iConstitution = a_constitution;
	m_iIntelligence = a_intelligence;
	m_iWisdom = a_wisdom;
	m_iCharisma = a_charisma;
	m_iLevel = a_level;
	m_bIsAlive = a_isAlive;
}

CEntityData CEntityData::CreatePlayer()
{
	
	int iUserInput;
	std::vector<int> statValues = {15,14,13,12,19,8};
	std::vector<std::string> statChoices = {"Str", "Dex", "Con", "Int", "Wis", "Char"};
	
	std::string playerName;
	std::vector<int> playerValues = {1,1,1,1,1,1};

	std::cout << "Please enter your Name: ";
	std::cin >> playerName;

	while (!statValues.empty())
	{
		std::cout << "Please distribute your stats. \n";
		for (auto const &choice : statChoices)
		{
			std::cout << choice << ",";
		}

		std::cout << "Enter the amount of Stats you want to use for: " << statChoices[0] << "\n";
		
		//erase the values that are used
		statValues.erase(statValues.begin());
		
		//std::find findet den ersten match im statchoices vector zum userinput
		auto it = std::find(statChoices.begin(), statChoices.end(), iUserInput);
		statChoices.erase(it);
		// playerValues.insert(playerValues.begin());
		
		
		CLEAR_SCREEN;
	}

	CEntityData Player = CEntityData(playerName, 100, 10, playerValues[0], playerValues[1], playerValues[2], playerValues[3], playerValues[4], playerValues[5]);	

	return Player;
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



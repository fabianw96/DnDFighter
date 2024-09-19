#include <iostream>
#include <algorithm>
#include "EntityData.h"

#include <map>
#include <set>

#include "HelperMacros.h"

CEntityData::CEntityData() = default;

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

/// <summary>
/// <para> Create a player from Userinput</para>
/// </summary>
CEntityData CEntityData::CreatePlayer()
{
	
	int iUserInput;
	std::set<int> statValues = {15,14,13,12,10,8};
	std::vector<std::string> statChoices = {"Str", "Dex", "Con", "Int", "Wis", "Char"};
	
	std::string playerName;
	std::vector<int> playerValues = {1,1,1,1,1,1};

	std::cout << "Please enter your Name: ";
	std::cin >> playerName;	

	std::cout << "Please distribute your stats. \n";
	
	for (int i = 0; i < playerValues.size(); ++i)
	{
		std::cout << "Please enter the amount of Stats you want to use for: " << statChoices[i] << "\n";
		std::cout << "You can still use these stats: ";

		for (const int statValue : statValues)
		{
			std::cout << statValue << " ";
		}

		std::cout << "\n";

		std::cin >> iUserInput;

		while (!statValues.contains(iUserInput))
		{
			std::cout << "The Value you have entered does not exist. \n";
			std::cout << "Please try again: ";
			std::cin >> iUserInput;
		}
		
		playerValues[i] += iUserInput;
		statValues.erase(std::ranges::find(statValues, iUserInput));
		
		CLEAR_SCREEN;
	}

	std::cout << "Please choose a class: \n";
	std::cout << "1. Barbarian \n";
	std::cout << "2. Monk \n";
	std::cout << "3. Fighter \n";
	
	std::cin >> iUserInput;

	float playerHealth;
	float playerAC;
	
	switch (iUserInput)
	{
	case 1:
		{
			playerHealth = playerValues[2] + 12;
			playerAC = (playerValues[1] - 10) / 2 + (playerValues[2] - 10) / 2 + 10;
		}
		break;
	case 2:
		{
			playerHealth = playerValues[2] + 8;
			playerAC = (playerValues[1] - 10) / 2 + (playerValues[4] - 10) / 2 + 10;
		}
		break;
	case 3:
		{
			playerHealth = playerValues[2] + 10;
			playerAC = (playerValues[1] - 10) / 2 + 10;
		}
		break;
	default:
		std::cout << "That's not a valid class!";
		break;
	}

	CEntityData Player = CEntityData(playerName, playerHealth, playerAC, playerValues[0], playerValues[1], playerValues[2], playerValues[3], playerValues[4], playerValues[5], 1);	

	return Player;
}

/// <summary>
/// <para> Function to extract Data from a CSV file. </para>
/// <param name="filename"> Path to CSV file </param>
/// <returns> A vector of a pair consisting of a string and a int vector </returns>
/// </summary>
std::vector<std::pair<std::string, std::vector<int>>> CEntityData::ReadCsvData(const std::string& filename)
{
	//maybe use map/dictionary?
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



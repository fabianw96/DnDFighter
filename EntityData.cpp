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
		
	}

	std::cout << "Please choose a class: \n";
	std::cout << "1. Barbarian \n";
	std::cout << "2. Bard \n";
	std::cout << "3. Cleric \n";
	std::cout << "4. Druid \n";
	std::cout << "5. Fighter \n";
	std::cout << "6. Monk \n";
	std::cout << "7. Paladin \n";
	std::cout << "8. Ranger \n";
	std::cout << "9. Rogue \n";
	std::cout << "10. Sorcerer \n";
	std::cout << "11. Warlock \n";
	std::cout << "12. Wizard \n";

	
	std::cin >> iUserInput;

	float playerHealth = 0;
	float playerAC = 0;
	
	switch (iUserInput)
	{
		//Barbarian
	case 1:
		{
			playerHealth = CONST_MOD + 12;
			playerAC = DEX_MOD + CONST_MOD + 10;
		}
		break;
		//Bard
	case 2:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
		//Cleric
	case 3:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
		//Druid
	case 4:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 5:
		{
			playerHealth = CONST_MOD + 10;
			playerAC = DEX_MOD + 10;
		}
		break;
	case 6:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = DEX_MOD + WIS_MOD + 10;
		}
		break;
	case 7:
		{
			playerHealth = CONST_MOD + 10;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 8:
		{
			playerHealth = CONST_MOD + 10;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 9:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 10:
		{
			playerHealth = CONST_MOD + 6;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 11:
		{
			playerHealth = CONST_MOD + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 12:
		{
			playerHealth = CONST_MOD + 6;
			playerAC = BASE_ARMOR_CLASS;
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



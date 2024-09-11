#include <iostream>
#include "EntityData.h"

CEntityData::CEntityData()
{
	char iUserInput;
	std::vector<int> playerStats = {15,14,13,12,19,8};
	std::vector<std::string> statChoices = {"[S]trength", "[D]exterity", "[C]onstitution", "[I]ntelligence", "[W]isdom", "Ch[a]risma"};

	while (!playerStats.empty())
	{
		std::cout << "Please distribute your stats. \n";
		for (auto const &choice : statChoices)
		{
			std::cout << choice << std::endl;
		}
		
		//Make player distribute the stats to str, dex, const, int, wis, char
		std::cout << "Choose your Stat: \n";
		std::cin >> iUserInput;
		
		//erase the values that are used
		playerStats.erase(playerStats.begin());
		// statChoices.erase(statChoices.begin() + iUserInput - 1);

		// for (std::vector<std::string>::const_iterator iterator = statChoices.cbegin(); iterator != statChoices.end(); ++iterator)
		// {
		// 	if (statChoices[iterator].find(iUserInput))
		// 	{
		// 		statChoices.;
		// 	}
		// }
	}
};


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



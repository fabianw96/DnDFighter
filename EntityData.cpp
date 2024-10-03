#include "EntityData.h"


EntityData::EntityData() = default;

EntityData::EntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, int a_charisma, int a_level, bool a_isAlive)
{
	m_Name = a_name;
	m_HealthPoints = a_healthPoints;
	m_ArmorClass = a_armorClass;
	m_Strength = a_strength;
	m_Dexterity = a_dexterity;
	m_Constitution = a_constitution;
	m_Intelligence = a_intelligence;
	m_Wisdom = a_wisdom;
	m_Charisma = a_charisma;
	m_Level = a_level;
	m_IsAlive = a_isAlive;
}

/// <summary>
/// <para> Create a player from Userinput</para>
/// </summary>
EntityData EntityData::CreatePlayer()
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

	//0=str, 1=dex, 2=const, 3=int, 4=wis, 5=char
	switch (iUserInput)
	{
		//Barbarian
	case 1:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 12;
			playerAC = GetAbilityModifier(playerValues[1]) + GetAbilityModifier(playerValues[2]) + 10;
		}
		break;
		//Bard
	case 2:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
		//Cleric
	case 3:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
		//Druid
	case 4:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 5:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 10;
			playerAC = GetAbilityModifier(playerValues[1]) + 10;
		}
		break;
	case 6:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = GetAbilityModifier(playerValues[1]) + GetAbilityModifier(playerValues[4]) + 10;
		}
		break;
	case 7:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 10;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 8:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 10;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 9:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 10:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 6;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 11:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 8;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	case 12:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 6;
			playerAC = BASE_ARMOR_CLASS;
		}
		break;
	default:
		std::cout << "That's not a valid class!";
		break;
	}

	EntityData Player = EntityData(playerName, playerHealth, playerAC, playerValues[0], playerValues[1], playerValues[2], playerValues[3], playerValues[4], playerValues[5], 1);	

	return Player;
}

void EntityData::GetHit(int takenDamage) const {
	m_HealthPoints -= takenDamage;
}


#include "EntityData.h"


EntityData::EntityData() = default;

EntityData::EntityData(const std::string& a_name, const int a_healthPoints, const int a_armorClass, const int a_strength, const int a_dexterity, const int a_constitution, const int a_intelligence, const int a_wisdom, const int a_charisma, const Weapon& a_weapon, const int a_level, const bool a_isAlive)
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
	m_weapon = a_weapon;
}

/// <summary>
/// <para> Create a player from Userinput</para>
/// </summary>
EntityData EntityData::CreatePlayer(const std::vector<Weapon>& weapons)
{
	int userInput;
	std::set<int> statValues = {15,14,13,12,10,8};
	const std::vector<std::string> statChoices = {"Str", "Dex", "Con", "Int", "Wis", "Char"};

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

		std::cin >> userInput;

		while (!statValues.contains(userInput))
		{
			std::cout << "The Value you have entered does not exist. \n";
			std::cout << "Please try again: ";
			std::cin >> userInput;
		}

		playerValues[i] += userInput;
		statValues.erase(std::ranges::find(statValues, userInput));

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


	std::cin >> userInput;

	int playerHealth = 0;
	int playerAC = 0;

	//0=str, 1=dex, 2=const, 3=int, 4=wis, 5=char
	switch (userInput)
	{
	case 1:
		{
			playerHealth = GetAbilityModifier(playerValues[2]) + 12;
			playerAC = GetAbilityModifier(playerValues[1]) + GetAbilityModifier(playerValues[2]) + 10;
		}
		break;
	case 2:
	case 3:
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

	std::cout << "Please choose a weapon for your character : \n";

	int i = 0;
	for (auto const& weapon : weapons)
	{
		std::cout << i << " : " << weapon.GetName() << "\n";
		i++;
	}

	std::cin >> userInput;

	EntityData Player = EntityData(playerName, playerHealth, playerAC, playerValues[0], playerValues[1], playerValues[2], playerValues[3], playerValues[4], playerValues[5], weapons[userInput], 1);

	return Player;
}

void EntityData::GetHit(const int takenDamage) const {
	m_HealthPoints -= takenDamage;
}


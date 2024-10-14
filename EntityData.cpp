#include "EntityData.h"


EntityData::EntityData() = default;

//constructor to create an entity with data
EntityData::EntityData(const std::string& a_name, const int a_healthPoints, const int a_armorClass, const int a_strength, const int a_dexterity, const int a_constitution, const int a_intelligence, const int a_wisdom, const int a_charisma, const Weapon& a_weapon, const int a_level, const bool a_IsAlive, const bool a_IsPlayer, const PlayerClass& a_playerClass)
	: m_Name(a_name), m_HealthPoints(a_healthPoints), m_MaxHealthPoints(a_healthPoints), m_ArmorClass(a_armorClass), m_Strength(a_strength), m_Dexterity(a_dexterity), m_Constitution(a_constitution), m_Intelligence(a_intelligence), m_Wisdom(a_wisdom), m_Charisma(a_charisma), m_Level(a_level), m_IsAlive(a_IsAlive), m_weapon(a_weapon), m_IsPlayer(a_IsPlayer), m_playerClass(a_playerClass) {}

/// <summary>
/// <para> Create a player from Userinput</para>
/// </summary>
EntityData EntityData::CreatePlayer(const std::vector<Weapon>& weapons) const {
	int userInput;
	std::set<int> statValues = {15,14,13,12,10,8};
	const std::vector<std::string> statChoices = {"Str", "Dex", "Con", "Int", "Wis", "Char"};

	std::string playerName;
	std::vector<int> playerValues = {1,1,1,1,1,1};

	std::cout << "Please enter your Name: \n";
	std::cin >> playerName;

	std::cout << "Please distribute your stats. \n";

	//prompt user for stat distribution
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

	std::vector<PlayerClass> playerClasses = {
		{"Barbarian", 12, 10, {0, 0, 0, 0, 0, 0}},
		{"Bard", 8, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Cleric", 8, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Druid", 8, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Fighter", 10, 10, {0, 0, 0, 0, 0, 0}},
		{"Monk", 8, 10, {0, 0, 0, 0, 0, 0}},
		{"Paladin", 10, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Ranger", 10, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Rogue", 8, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Sorcerer", 6, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Warlock", 8, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}},
		{"Wizard", 6, BASE_ARMOR_CLASS, {0, 0, 0, 0, 0, 0}}
	};

	std::cout << "Please choose a class: \n";
	for (int i = 0; i < playerClasses.size(); ++i) {
		std::cout << i + 1 << ". " << playerClasses[i].name << "\n";
	}

	std::cin >> userInput;

	//validate user input
	if (userInput < 1 || userInput >> playerClasses.size()) {
		std::cout << "That's not a valid class!";
		//return empty entitydata TODO: replace with loop so player can try again.
		return {};
	}

	const PlayerClass& chosenClass = playerClasses[userInput - 1];
	int playerHealth = GetAbilityModifier(playerValues[2]) + chosenClass.baseHealth;
	int playerAC = chosenClass.baseArmorClass;

	std::cout << "Please choose a weapon for your character : \n";

	int i = 0;
	for (auto const& weapon : weapons)
	{
		std::cout << i << ": " << weapon.GetName() << " - Dice type: "<< weapon.GetDiceType() <<"\n";
		i++;
	}

	std::cin >> userInput;

	//create player with chosen stats and class
	EntityData Player = EntityData(playerName, playerHealth, playerAC, playerValues[0], playerValues[1], playerValues[2], playerValues[3], playerValues[4], playerValues[5], weapons[userInput], 1, true, true,chosenClass);
	Player.m_MaxHealthPoints = playerHealth;

	CLEAR_SCREEN;

	return Player;
}

//general gethit for player and monster
void EntityData::GetHit(const int takenDamage) const {
	m_HealthPoints -= takenDamage;
}

//player levelup, heals player and increases HP
void EntityData::LevelUp() {
	m_Level += 1;
	m_HealthPoints = m_MaxHealthPoints;

	//dertmine class by HP
	EDiceType diceType;
	switch (m_playerClass.baseHealth) {
		case 6:
			diceType = DT_D6;
			break;
		case 8:
			diceType = DT_D8;
			break;
		case 10:
			diceType = DT_D10;
			break;
		case 12:
			diceType = DT_D12;
			break;
		default:
			diceType = DT_D6;
			break;
	}

	//increase HP on levelup
	int hpIncrease = Dice::RollDice(diceType);
	m_MaxHealthPoints += hpIncrease;
	m_HealthPoints += hpIncrease;

	std::cout << "After the fight, you gained a level! You are now level: " << m_Level << "! \n";
	std::cout << "Your HP increased by " << hpIncrease << " points!\n";
}


#ifndef ENTITYDATA_H
#define ENTITYDATA_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "HelperMacros.h"

#define BASE_ARMOR_CLASS 10

class EntityData
{
private:
	std::string m_Name;
	mutable int m_HealthPoints = 0;
	int m_ArmorClass = 0;
	int m_Strength = 0;
	int m_Dexterity = 0;
	int m_Constitution = 0;
	int m_Intelligence = 0;
	int m_Wisdom = 0;
	int m_Charisma = 0;
	int m_Level = 0;
	bool m_IsAlive = true;

public:
	EntityData();
	EntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, int a_charisma, int a_level = 0, bool a_isAlive = true);
	EntityData CreatePlayer();
	void GetHit(int takenDamage) const;

	[[nodiscard]] std::string GetName() const { return m_Name; }
	[[nodiscard]] int GetHealthPoints() const { return m_HealthPoints; }
	[[nodiscard]] int GetArmorClass() const { return m_ArmorClass; }
	[[nodiscard]] int GetStrength() const { return m_Strength; }
	[[nodiscard]] int GetDexterity() const { return m_Dexterity; }
	[[nodiscard]] int GetConstitution() const { return m_Constitution; }
	[[nodiscard]] int GetIntelligence() const { return m_Intelligence; }
	[[nodiscard]] int GetWisdom() const { return m_Wisdom; }
	[[nodiscard]] int GetCharisma() const { return m_Charisma; }
	[[nodiscard]] int GetLevel() const { return m_Level; }
	[[nodiscard]] bool GetIsAlive() const { return m_IsAlive; }
	[[nodiscard]] int GetAbilityModifier(int ability) const { return ((ability - 10) / 2); }
};
#endif // !ENTITYDATA_H

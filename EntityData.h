#ifndef ENTITYDATA_H
#define ENTITYDATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "HelperMacros.h"


#define STR_MOD ((playerValues[0] - 10) / 2)
#define DEX_MOD ((playerValues[1] - 10) / 2)
#define CONST_MOD ((playerValues[2] - 10) / 2)
#define INT_MOD ((playerValues[3] - 10) / 2)
#define WIS_MOD ((playerValues[4] - 10) / 2)
#define CHAR_MOD ((playerValues[5] - 10) / 2)

#define BASE_ARMOR_CLASS 10

class CEntityData
{
private:
	std::string m_sName;
	float m_iHealthPoints = 0;
	int m_iArmorClass = 0;
	int m_iStrength = 0;
	int m_iDexterity = 0;
	int m_iConstitution = 0;
	int m_iIntelligence = 0;
	int m_iWisdom = 0;
	int m_iCharisma = 0;
	int m_iLevel = 0;
	bool m_bIsAlive = true;

public:
	std::vector<std::pair<std::string, std::vector<int>>> ReadCsvData(const std::string& filename);
	CEntityData();
	CEntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, int a_charisma, int a_level = 0, bool a_isAlive = true);
	CEntityData CreatePlayer();

	[[nodiscard]] std::string GetName() const { return m_sName; }
	[[nodiscard]] float GetHealthPoints() const { return m_iHealthPoints; }
	[[nodiscard]] int GetArmorClass() const { return m_iArmorClass; }
	[[nodiscard]] int GetStrength() const { return m_iStrength; }
	[[nodiscard]] int GetDexterity() const { return m_iDexterity; }
	[[nodiscard]] int GetConstitution() const { return m_iConstitution; }
	[[nodiscard]] int GetIntelligence() const { return m_iIntelligence; }
	[[nodiscard]] int GetWisdom() const { return m_iWisdom; }
	[[nodiscard]] int GetCharisma() const { return m_iCharisma; }
	[[nodiscard]] int GetLevel() const { return m_iLevel; }
	[[nodiscard]] bool GetIsAlive() const { return m_bIsAlive; }
};
#endif // !ENTITYDATA_H

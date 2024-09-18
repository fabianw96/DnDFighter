#ifndef ENTITYDATA_H
#define ENTITYDATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

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

	std::string GetName() { return m_sName; }
	float GetHealthPoints() { return m_iHealthPoints; }
	int GetArmorClass() { return m_iArmorClass; }
	int GetStrength() { return m_iStrength; }
	int GetDexterity() { return m_iDexterity; }
	int GetConstitution() { return m_iConstitution; }
	int GetIntelligence() { return m_iIntelligence; }
	int GetWisdom() { return m_iWisdom; }
	int GetCharisma() { return m_iCharisma; }
	int GetLevel() { return m_iLevel; }
	bool GetIsAlive() { return m_bIsAlive; }
};
#endif // !ENTITYDATA_H

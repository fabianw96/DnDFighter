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
	std::string m_Name;
	float m_HealthPoints = 0;
	int m_ArmorClass = 0;
	int m_Strength = 0;
	int m_Dexterity = 0;
	int m_Constitution = 0;
	int m_Intelligence = 0;
	int m_Wisdom = 0;
	bool m_BIsAlive = true;

public:
	std::vector<std::pair<std::string, std::vector<int>>> ReadCsvData(const std::string& filename);
	CEntityData();
	CEntityData(const std::string& a_name, float a_healthPoints, int a_armorClass, int a_strength, int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom, bool a_isAlive = true);

	float GetHealthPoints() { return m_HealthPoints; }
	int GetArmorClass() { return m_ArmorClass; }
	int GetStrength() { return m_Strength; }
	int GetDexterity() { return m_Dexterity; }
	int GetConstitution() { return m_Constitution; }
	int GetIntelligence() { return m_Intelligence; }
	int GetWisdom() { return m_Wisdom; }
	bool GetIsAlive() { return m_BIsAlive; }
};
#endif // !ENTITYDATA_H

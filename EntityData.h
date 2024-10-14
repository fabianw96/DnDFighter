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
#include "Weapon.h"
#include "PlayerClass.h"

#define BASE_ARMOR_CLASS 10

class EntityData
{
private:
	PlayerClass m_playerClass;
	std::string m_Name;
	mutable int m_HealthPoints = 0;
	int m_MaxHealthPoints = 0;
	int m_ArmorClass = 0;
	int m_Strength = 0;
	int m_Dexterity = 0;
	int m_Constitution = 0;
	int m_Intelligence = 0;
	int m_Wisdom = 0;
	int m_Charisma = 0;
	int m_Level = 0;
	bool m_IsAlive = true;
	Weapon m_weapon;
	bool m_IsPlayer = false;

public:
	EntityData();
	EntityData(const std::string &a_name, int a_healthPoints, int a_armorClass, int a_strength,
	           int a_dexterity, int a_constitution, int a_intelligence, int a_wisdom,
	           int a_charisma, const Weapon &a_weapon, int a_level, bool a_IsAlive,
	           bool a_IsPlayer, const PlayerClass &a_playerClass);
	EntityData CreatePlayer(const std::vector<Weapon>& weapons) const;
	void GetHit(int takenDamage) const;
	void LevelUp();

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
	[[nodiscard]] EDiceType GetWeaponDice() const { return m_weapon.GetDiceType(); }
	[[nodiscard]] bool GetIsPlayer() const { return m_IsPlayer; }
};
#endif // !ENTITYDATA_H

#ifndef ENTITYDATA_H
#define ENTITYDATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

struct EntityData
{
public:
	std::vector<std::pair<std::string, std::vector<int>>> readCsvData(std::string filename);
protected:
	std::string Name;
	float HealthPoints;
	int ArmorClass;
	int Strength;
	int Dexterity;
	int Constitution;
	int Intelligence;
	int Wisdom;
};
#endif // !ENTITYDATA_H

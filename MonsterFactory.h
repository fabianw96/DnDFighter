#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include <vector>
#include "EntityData.h"
#include <iostream>
#include <numeric>
#include "CsvReader.h"

class MonsterFactory
{
public:
	std::vector<EntityData> CreateMonster();
};

#endif

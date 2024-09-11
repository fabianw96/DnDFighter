#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include <vector>

#include "EntityData.h"

class CMonsterFactory
{
public:
	std::vector<CEntityData> CreateMonster();
};

#endif

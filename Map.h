#pragma once
#include <vector>
#include "MapEntity.h"

class Map
{
public:
	Map();
	~Map();

private:
	std::vector<MapEntity> entities;
};


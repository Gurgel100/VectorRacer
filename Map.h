#pragma once
#include "MapEntity.h"
#include <vector>

class Map
{
public:
	Map(size_t width, size_t height);
	~Map();

	void print() const;

private:
	const size_t width, height;
	std::vector<MapEntity> entities;
};


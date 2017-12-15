#pragma once
#include "MapEntity.h"
#include "Checkpoint.h"
#include <vector>

class Map
{
public:
	Map(size_t width, size_t height, const std::vector<MapEntity::EntityType> &entityTypes, const std::vector<Checkpoint> &checkpoints);
	~Map();

	void print() const;

private:
	const size_t width, height;
	std::vector<MapEntity> entities;
	const std::vector<Checkpoint> checkpoints;
};


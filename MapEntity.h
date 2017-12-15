#pragma once
class MapEntity
{
public:
	enum class EntityType
	{
		Road,
		Wall,
		Gravel
	};

	MapEntity(EntityType entityType);
	~MapEntity();

private:
	EntityType entityType;
};


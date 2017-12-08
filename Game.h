#pragma once
#include "Map.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	Game(const Map &&map);
	~Game();

private:
	const Map map;
	std::vector<Player> players;
};


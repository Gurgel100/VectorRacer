#pragma once
#include "Map.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	Game(const Map &&map);
	~Game();

	void loop();

private:
	const Map map;
	std::vector<Player> players;
};


#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(const Map &&map) : map(map)
{
}

Game::~Game()
{
}

void Game::loop()
{
	char input;
	do
	{
		map.print();
		cin >> input;
	}
	while (input != 'q');
}

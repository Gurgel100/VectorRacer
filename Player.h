#pragma once
#include "Eigen\Eigen"
#include <string>

class Player
{
public:
	Player(const std::string &name);
	~Player();

	void move(const Eigen::Vector2i &dir);

private:
	const std::string name;
	Eigen::Vector2i pos;
	Eigen::Vector2i dir;
};


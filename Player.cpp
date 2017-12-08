#include "Player.h"

using std::string;
using Eigen::Vector2i;

Player::Player(const string &name) : name(name)
{
}

Player::~Player()
{
}

void Player::move(const Vector2i &dir)
{
	this->dir += dir;
	pos += this->dir;
}

#pragma once

#include "Eigen\Eigen"

class Checkpoint
{
public:
	Checkpoint(const Eigen::Vector2i &start, const Eigen::Vector2i &end);
	~Checkpoint();

private:
	const Eigen::Vector2i start, end;
};

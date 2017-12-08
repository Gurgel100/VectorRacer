#include "Map.h"
#include <iostream>
#include <string>

using namespace std;

Map::Map(size_t width, size_t height) : width(width), height(height)
{
}

Map::~Map()
{
}

void Map::print() const
{
	const string verticalDelimiter(width, '-');

	cout << verticalDelimiter << endl;
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
		}
		cout << endl;
	}
	cout << verticalDelimiter << endl;
}

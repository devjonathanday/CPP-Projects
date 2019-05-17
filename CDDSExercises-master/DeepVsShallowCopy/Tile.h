#include <string>
#include <iostream>
#include "raylib.h"

class Tile
{
public:
	Texture2D texture;
	Color tint;

	Tile(std::string imageFilename);
	Tile();
	~Tile();

	Tile& operator=(const Tile& rhs);
	int randomNumber(int minRange, int maxRange);
	Color randomizeTint();
};
#include"Tile.h"
#include<iostream>
#include<string.h>

using namespace std;

Tile::Tile(string imageFileName)
{
	texture = LoadTexture(imageFileName.c_str());
	tint = WHITE;
	//tint = randomizeTint();
}
Tile::Tile()
{
	texture = LoadTexture("mapTile_5.png");
	tint = WHITE;
}
Tile::~Tile()
{
	
}
int Tile::randomNumber(int minRange, int maxRange)
{
	return rand() % (maxRange - minRange) + minRange;
}
Color Tile::randomizeTint()
{
	Color newColor;
	newColor.r = randomNumber(240, 255);
	newColor.g = randomNumber(240, 255);
	newColor.b = randomNumber(240, 255);
	newColor.a = 255;
	return newColor;
}
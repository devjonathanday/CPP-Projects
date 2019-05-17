#include "Item.h"
#include<string>
#include<iostream>

using namespace std;

Item::Item()
{
	x = 200;
	y = 200;
}
Item::Item(int * _itemType, int _quality, int _range, Texture2D * _texture, int _damage)
{
	itemType = _itemType;
	quality = _quality;
	range = _range;
	texture = _texture;

	x = 200;
	y = 200;
}
Item::~Item()
{
	UnloadTexture(*texture);
	delete texture;
	delete itemType;
}
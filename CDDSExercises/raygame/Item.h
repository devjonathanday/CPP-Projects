#pragma once
#include "raylib.h"
#include<string>

using std::string;

class Item
{
public:

	//Vars
	int *itemType;
	int quality;
	int range;
	Texture2D * texture;
	int damage;

	int x;
	int y;

	// Constructors & Destructors
	Item();
	Item(int * _itemType, int _quality, int _range, Texture2D * _texture, int _damage);
	~Item();

	// Misc Functions
	void refresh();

private:
};
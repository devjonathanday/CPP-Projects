#pragma once
#include "raylib.h"
#include<string>

using std::string;

class Meep
{
public:

	//Vars
	bool enabled;
	bool playerControlled;
	Texture2D texture;
	Texture2D* dTexture;

	int x;
	int y;

	// Constructors & Destructors
	Meep();
	Meep(bool _enabled);
	Meep(bool _enabled, string fileName, bool _playerControlled);
	~Meep();

	// Misc Functions
	void refresh();

private:
};
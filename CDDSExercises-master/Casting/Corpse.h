#pragma once
#include <iostream>
#include "raylib.h"
#include"Wizard.h"
#include"Barbarian.h"

class Corpse
{
public:

	Corpse(); // sets default values
	~Corpse();
	Corpse(Wizard wizard);
	Corpse(Barbarian barbarian);

	std::string name;
	int gold = 50;
	Vector2 position = { 200, 200 };
	Texture2D tex;

	void draw(); // call this in your draw loop to render the wizard
};
#pragma once
#include <iostream>
#include "raylib.h"
#include"Wizard.h"

class Barbarian
{
public:
	std::string name;
	int power = 50;
	int gold = 50;
	Vector2 position = { 200, 200 };
	Texture2D tex;

	Barbarian(); // sets default values
	~Barbarian();

	void draw(); // call this in your draw loop to render the wizard
};
#pragma once
#include <iostream>
#include "raylib.h"
#include"Barbarian.h"

class Wizard
{
public:
	std::string name;
	int mana = 50;
	int gold = 50;
	Vector2 position = { 200, 200 };
	Texture2D tex;

	Wizard(); // sets default values
	Wizard(std::string _name, int _mana, int _gold, Vector2 _position, Texture2D _tex); // values are input upon declaration
	~Wizard();

	void draw(); // call this in your draw loop to render the wizard
};
#pragma once
#include <iostream>
#include "raylib.h"

class Player
{
public:
	Player(); // sets default values
	~Player();

	int power = 50;
	int gold = 0;
	Vector2 position = { 400, 225 };
	Texture2D tex;
	int health = 100;

	void update(); // call this in your draw loop to render the wizard
};
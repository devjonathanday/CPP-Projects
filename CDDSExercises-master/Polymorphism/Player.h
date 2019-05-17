#pragma once
#include "raylib.h"
#include <iostream>
class Player
{
public:
	Vector2 position = { 100,100 };
	Vector2 destination = { 0,0 };

	float speed;
	Texture2D mySprite;

	virtual void moveTo(Vector2 destination);
	void update();

	Player();
	Player(Texture2D sprite);
	~Player();
	//Player& operator=(Wizard wizard);
	//Player& operator=(Barbarian barbarian);
};
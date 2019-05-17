#pragma once
#include<raylib.h>

class Player
{
public:
	Texture2D tex;
	Rectangle collider;
	int health;
	float moveSpeed;

	Player();
	~Player();
	Player(Texture2D _tex, Rectangle _col, int _health, float _moveSpeed); //Assigns all default values for the player
};
#pragma once
#include "raylib.h"
#include <iostream>

class Enemy
{
public:
	Vector2 position = { 100,100 };
	float speed = 0;
	Texture2D mySprite;

	Enemy();
	Enemy(Texture2D sprite);
	~Enemy();
	virtual void update(Vector2 destination);
	bool CheckHit();
};
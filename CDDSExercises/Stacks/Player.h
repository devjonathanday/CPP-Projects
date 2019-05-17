#include"raylib.h"
#include"Command.h"
#include"tQueue.h"
#pragma once

class Player
{
public:
	Vector2 position;
	Texture2D texture;
	float moveSpeed;

	Player();
	~Player();
	Player(Texture2D _tex, float _moveSpeed);
	void moveTo(tQueue<Vector2> &positionQueue);
};
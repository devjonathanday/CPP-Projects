#pragma once
#include "raylib.h"
#include"Player.h"
#include <iostream>
class Barbarian : public Player
{
public:
	void moveTo(Vector2 destination) override;

	Barbarian();
	Barbarian(Texture2D sprite);
	~Barbarian();
};
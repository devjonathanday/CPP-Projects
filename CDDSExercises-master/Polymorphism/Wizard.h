#pragma once
#include "raylib.h"
#include"Player.h"
#include <iostream>
class Wizard : public Player
{
public:
	void moveTo(Vector2 destination) override;

	Wizard();
	Wizard(Texture2D sprite);
	~Wizard();
};
#pragma once
#include"raylib.h"

class Soldier
{
public:
	Texture2D tex;
	Vector2 position;

	Soldier(Texture2D _tex, Vector2 _position);
	void render();
	Soldier();
	~Soldier();
};
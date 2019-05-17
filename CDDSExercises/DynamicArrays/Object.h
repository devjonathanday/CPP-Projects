#pragma once
#include<raylib.h>

struct Object
{
	Vector2 movementDir;
	Vector2 position;
	Texture2D tex;
	int rotation;
	float scale;
};
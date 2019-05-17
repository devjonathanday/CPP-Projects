#pragma once
#include <iostream>
#include "raylib.h"
class SimpleSprite
{
public:
	std::string spriteType;
	Vector2 pos;
	float rotation;
	Rectangle rec1, rec2;
	Texture2D texture;

	void Translate(Vector2 delta);
	void Draw();
	SimpleSprite();
	SimpleSprite(const std::string & filename, const std::string _sprType, float scale);
	~SimpleSprite();
};
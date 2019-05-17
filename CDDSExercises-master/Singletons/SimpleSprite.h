#pragma once
#include <iostream>
#include "raylib.h"
#include"Functions.h"

class SimpleSprite
{
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle rec1;
	Rectangle rec2;
	Texture2D texture;

	void Translate(Vector2 delta);
	void Draw();
	void Update();

	SimpleSprite * Clone();
	SimpleSprite();
	SimpleSprite(const SimpleSprite &original);
	SimpleSprite(const std::string & filename, const std::string _sprType, float scale);
	~SimpleSprite();
	
};
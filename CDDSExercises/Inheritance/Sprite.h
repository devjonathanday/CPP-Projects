#pragma once
#include "raylib.h"
#include <iostream>
class Sprite : public Vector2
{
public:
	Texture2D currentSprite;
	Texture2D * textureList = NULL;
	int cellCount;
	float frameRate;

	void Update();
	void Animate(float gameTimer, int frameCount);

	Sprite(const std::string * filename, const int cellCount, const float _frameRate);
	Sprite();
	~Sprite();
};
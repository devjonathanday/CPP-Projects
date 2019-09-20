#pragma once
#include"vec2.h"
#include"raylib.h"

class Ball
{
public:
	Texture2D tex;
	vec2 position;
	vec2 velocity;
	vec2 leftEdge;
	vec2 rightEdge;
	float aimAngle;
	float offset;
};
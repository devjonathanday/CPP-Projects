#pragma once
#include "raylib.h"
#include <math.h>
class DialFace
{
public:
	static Vector2 position;
	static float radius;

	static float seconds;
	static int minutes;
	static int hours;

	static void DrawFace();
	void Tick();
	static float DegToRad(float degrees);

	DialFace();
	~DialFace();
};
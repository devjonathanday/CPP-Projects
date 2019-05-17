#include"Functions.h"
#include<iostream>
#include"raylib.h"

Vector2 NormalizeVector2(Vector2 vector)
{
	float distance = sqrt(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / distance, vector.y / distance };
}
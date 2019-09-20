#include"Functions.h"

Vector2 NormalizeVector2(Vector2 vector)
{
	float distance = sqrt(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / distance, vector.y / distance };
}
int randomNumber(int minRange, int maxRange)
{
	return rand() % (maxRange - minRange) + minRange;
}
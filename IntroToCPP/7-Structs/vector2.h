#pragma once

struct vector2
{
	float x;
	float y;
};

vector2 vectorSum(vector2 vec1, vector2 vec2);
vector2 vectorDifference(vector2 vec1, vector2 vec2);
float vectorDistance(vector2 vec1, vector2 vec2);
void printVector(vector2 vec1);
float pythagoreanTheorem(int x1, int y1, int x2, int y2);
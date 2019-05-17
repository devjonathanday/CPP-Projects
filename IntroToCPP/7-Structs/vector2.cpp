#include<iostream>
#include "vector2.h"
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

float pythagoreanTheorem(int x1, int y1, int x2, int y2)
{
	int a = x2 - x1;
	int b = y2 - y1;
	return sqrt(a * a + b * b);
}

vector2 vectorSum(vector2 vec1, vector2 vec2)
{
	vector2 newVec;
	newVec.x = vec1.x + vec2.x;
	newVec.y = vec1.y + vec2.y;
	return newVec;
}
vector2 vectorDifference(vector2 vec1, vector2 vec2)
{
	vector2 newVec;
	if (vec1.x > vec2.x)
	{
		newVec.x = abs(vec1.x - vec2.x);
	}
	else
	{
		newVec.x = abs(vec2.x - vec1.x);
	}
	if (vec1.y > vec2.y)
	{
		newVec.y = abs(vec1.y - vec2.y);
	}
	else
	{
		newVec.y = abs(vec2.y - vec1.y);
	}
	return newVec;
}
void printVector(vector2 vec1)
{
	cout << "(" << vec1.x << ", " << vec1.y << ")" << endl;
}
float vectorDistance(vector2 vec1, vector2 vec2)
{
	return pythagoreanTheorem(vec1.x, vec1.y, vec2.x, vec2.y);
}
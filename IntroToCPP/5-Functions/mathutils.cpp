#include "mathutils.h"
#include<cmath>

void Pause()
{
	cout << "Press any key to continue..." << endl;
	char okToGo;
	cin >> okToGo;
}
int sum(int a, int b)
{
	return a + b;
}
float sum(float a, float b)
{
	return a + b;
}
void HelloFunctions()
{
	cout << "Hello Functions!\n";
}
int squareInt(int x)
{
	return x * x;
}
float fractionToDecimal(float top, float bottom)
{
	return top / bottom;
}
float largestDifference(int x, int y, int z)
{
	if (abs(x - y) > abs(y - z))
	{
		if (abs(x - y) > abs(x - z))
		{
			return abs(x - y);
		}
		else
		{
			return abs(x - z);
		}
	}
	else
	{
		if (abs(y - z) > abs(x - z))
		{
			return abs(y - z);
		}
		else
		{
			return abs(x - z);
		}
	}

}

void printTwoNums(int x, int y)
{
	cout << x << ", " << y << endl;
}
int sumOfThree(int x, int y, int z)
{
	return x + y + z;
}
int minimumNum(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int maximumNum(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int clamp(int lower, int upper, int num)
{
	if (num < lower)
	{
		num = lower;
	}
	if (num > upper)
	{
		num = upper;
	}
	return num;
}
float pythagoreanTheorem(int x1, int y1, int x2, int y2)
{
	int a = x2 - x1;
	int b = y2 - y1;
	return sqrt(a * a + b * b);
}
float timeOfArrival(int x1, int y1, int x2, int y2, int speed)
{
	return pythagoreanTheorem(x1, y1, x2, y2) / speed;
}
float linearInterpolation(int x, int y, float range)
{
	return (x*range) + (y*range);
}
//float supremeClamp(int lower, int upper, int num)
//{
//
//}
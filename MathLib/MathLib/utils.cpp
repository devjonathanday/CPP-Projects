#include"utils.h"
#include<cmath>

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int sum(int a, int b)
{
	return (a + b);
}
int clamp(int value, int lower, int upper)
{
	return max(lower, min(value, upper));
}
int absVal(int val)
{
	return val >= 0 ? val : -val;
}
int pow(int base, int power)
{
	int oldBase = base;
	for (int i = 1; i < power; i++)
	{ base *= oldBase; }
	return base;
}
bool isPowerOfTwo(int val)
{
	if (val < 2)
		return false;
	float check = val;
	while (check > 1)
		check /= 2;
	return check == 1 ? true : false;
}
int nextPowerOfTwo(int val)
{
	if (val < 2) return 2;
	while (!isPowerOfTwo(val += 1))
	{ if ((val + 1) < val) return 0; }
	return val;
}
float moveTowards(float current, float target, float maxDelta)
{
	if (current < target)
		return (current + maxDelta > target) ? target : current + maxDelta;
	if (current > target)
		return (current - maxDelta < target) ? target : current - maxDelta;
	return target;
}
//float angleFromVector(float x, float y)
//{
//	return atan2(x, -y) * (float)RAD_TO_DEG;
//}
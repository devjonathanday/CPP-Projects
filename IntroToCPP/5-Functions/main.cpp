#include<iostream>
#include "mathutils.h"

int main()
{
	HelloFunctions();
	cout << squareInt(5) << endl;
	cout << fractionToDecimal(4.0f, 5.0f) << endl;
	cout << largestDifference(5, 10, 1) << endl;
	printTwoNums(1, 5);
	cout << sumOfThree(1, 2, 3) << endl;
	cout << minimumNum(2, 5) << endl;
	cout << maximumNum(2, 5) << endl;
	cout << clamp(5, 10, 2) << endl;
	cout << pythagoreanTheorem(7, 23, 9, 0) << endl;
	cout << timeOfArrival(4, 4, 4, 8, 4) << endl;
	cout << linearInterpolation(-10, 5, 0.25f) << endl;
	Pause();
	return 0;
}


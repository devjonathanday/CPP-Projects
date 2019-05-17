#include<iostream>
#include"Functions.h"

int randomNumber(int minRange, int maxRange) // Generates a random number, starting at minRange and going until maxRange
{
	return rand() % (maxRange - minRange) + minRange;
}
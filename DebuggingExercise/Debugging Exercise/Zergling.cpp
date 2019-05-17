#include "Zergling.h"

Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 10;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

// How many zerglings are still alive
int zerglingCount(Zergling * swarmArr, size_t arrSize)
{
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			count++;
		}
	}
	return count;
}
bool Zergling::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

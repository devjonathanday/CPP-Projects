#include "Marine.h"



Marine::Marine()
{
	health = 50;
}


Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

// How many marines are still alive
int marineCount(Marine * squadArr, size_t arrSize)
{
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (squadArr[i].health > 0)
		{
			count++;
		}
	}
	return count;
}
bool Marine::isAlive()
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
#pragma once

class Zergling
{
public:
	Zergling();
	~Zergling();

	int attack();
	void takeDamage(int damage);
	int health = 20;
	int maxHealth = 20;
	bool isAlive();
	
};

int zerglingCount(Zergling * swarmArr, size_t arrSize);
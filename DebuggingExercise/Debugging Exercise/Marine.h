#pragma once

class Marine
{
public:
	Marine();
	~Marine();

	int attack();
	void takeDamage(int damage);
	int health = 50;
	int maxHealth = 50;
	bool isAlive();
	
};

int marineCount(Marine * squadArr, size_t arrSize);
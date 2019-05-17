#pragma once

struct fighter
{
	int HP;
	int attack;
	int defense;
};

void TakeDamage(fighter source, fighter target);
void DisplayStats();
void Battle();
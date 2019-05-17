#pragma once
#include<string>
#include<iostream>

using namespace std;

class Character
{
private:
	
//	int health;
public:
	int maxHealth;
	int health;
	string name;
	int minAttack;
	int maxAttack;
	//int GetCharacterHP(Character myCharacter);
	//int GetCharacterMaxHP(Character myCharacter);
};

void DisplayStats(Character teamA[], Character teamB[], int teamSize);
int GetRando(int minRange, int maxRange);
void TeamAttack(Character sourceTeam[], Character targetTeam[], int teamSize);
bool TeamAlive(Character team[], int teamSize);
void sortAscending(Character team[], int size);
void Pause();
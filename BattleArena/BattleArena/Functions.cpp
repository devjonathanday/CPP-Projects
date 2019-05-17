#include<string>
#include<iostream>
#include"Functions.h"
#include<conio.h>

using namespace std;

//int Character::GetCharacterHP(Character myCharacter)
//{
//	return myCharacter.health;
//}

//int Character::GetCharacterMaxHP(Character myCharacter)
//{
//	return myCharacter.maxHealth;
//}

void Pause()
{
	/*cout << "Press any key to continue..." << endl;
	_getch();*/
	system("pause");
}

void DisplayStats(Character teamA[], Character teamB[], int teamSize)
{
	cout << "Current Stats:\n\n";
	cout << "Team A:\n";
	for (int i = 0; i < teamSize; i++)
	{
		cout << teamA[i].name << ": " << teamA[i].health << "/" << teamA[i].maxHealth << endl;
	}
	cout << "\nTeam B:\n";
	for (int i = 0; i < teamSize; i++)
	{
		cout << teamB[i].name << ": " << teamB[i].health << "/" << teamB[i].maxHealth << endl;
	}
	cout << endl;
}

void TeamAttack(Character sourceTeam[], Character targetTeam[], int teamSize)
{
	for (int i = 0; i < teamSize; i++) //Loop through the team
	{
		if (sourceTeam[i].health > 0)
		{
			int damage = GetRando(sourceTeam[i].minAttack, sourceTeam[i].maxAttack); //Get a random damage value based on the source character
			int target = GetRando(0, 3); //Get a random index from 0 to 3
			if (TeamAlive(targetTeam, 3)) //If anyone on the target team is alive
			{
				while (targetTeam[target].health <= 0) // While the target selected is dead
				{
					target = GetRando(0, 3); //Find another random target
				}
			}
			if (targetTeam[target].health > 0) //Check if that target is alive
			{
				targetTeam[target].health -= damage; //Deal the damage
				cout << sourceTeam[i].name << " attacked " << targetTeam[target].name << " for " << damage << " damage!" << endl; //Player feedback
				if (targetTeam[target].health <= 0) //Check to make sure the target doesn't have negative health, or is dead
				{
					targetTeam[target].health = 0;
					cout << targetTeam[target].name << " has fallen!" << endl; //Player feedback
				}
			}
		}
	}
}

int GetRando(int minRange, int maxRange) // Generates a random number, starting at minRange (inclusive) and going until maxRange (inclusive)
{
	return (rand() % maxRange) + minRange;
}
bool TeamAlive(Character team[], int teamSize)
{
	for (int i = 0; i < teamSize; i++)
	{
		if (team[i].health > 0)
		{
			return true;
		}
	}
	return false;
}

void sortAscending(Character team[], int size)
{
	bool changed = true;
	while (changed)
	{
		changed = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (team[i].health > team[i + 1].health)
			{
				Character temp = team[i];
				team[i] = team[i+1];
				team[i+1] = temp;
				changed = true;
			}
		}
	}
}
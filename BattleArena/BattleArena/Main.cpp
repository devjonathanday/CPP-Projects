#include<string>
#include<iostream>
#include"Functions.h"
#include<time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int turnCount = 0;

	Character fighter1{ 150, 150, "Parrot", 15, 20 },
		fighter2{ 100, 100, "Pigeon", 5, 15 },
		fighter3{ 200, 200, "Owl", 10, 20 },

		fighter4{ 150, 150, "Penguin", 15, 20 },
		fighter5{ 100, 100, "Sparrow", 5, 15 },
		fighter6{ 200, 200, "Toucan", 10, 20 };

	Character teamA[3] = { fighter1, fighter2, fighter3 };
	Character teamB[3] = { fighter4, fighter5, fighter6 };

	DisplayStats(teamA, teamB, 3);
	Pause();

	while(TeamAlive(teamA, 3) && TeamAlive(teamB, 3)) //If both teams are alive
	{
		system("cls");
		turnCount++;
		cout << "TURN " << turnCount << "\n\n";
		if (TeamAlive(teamB, 3))
		{
			TeamAttack(teamA, teamB, 3);
		}
		if (TeamAlive(teamA, 3))
		{
			TeamAttack(teamB, teamA, 3);
		}
		sortAscending(teamA, 3);
		sortAscending(teamB, 3);
		DisplayStats(teamA, teamB, 3);
		Pause();
	}
	if (TeamAlive(teamA, 3))
	{
		system("cls");
		DisplayStats(teamA, teamB, 3);
		cout << "Team A has won in " << turnCount << " turns! Congratulations!" << endl;
		Pause();
	}
	else
	{
		system("cls");
		DisplayStats(teamA, teamB, 3);
		cout << "Team B has won in " << turnCount << " turns! Congratulations!" << endl;
		Pause();
	}
	return 0;
}
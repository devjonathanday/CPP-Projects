// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	bool marinesWin;

	int turnCount = 1;

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineCount(squad, 10) > 0 && zerglingCount(swarm, 20) > 0) // If anyone is left alive to fight . . .
	{
		cout << "\nTURN " << turnCount << endl;
		turnCount++;
		if (zerglingCount(swarm, 20) > 0) // if there's at least one zergling alive
		{
			marinesWin = true;
			for (size_t i = 0; i < marineCount(squad, 10); i++) // go through the squad
			{
				for (size_t j = 0; j < zerglingCount(swarm, 20); j++) //go through the zerglings
				{
					if (swarm[j].isAlive()) //checks if the zergling in question is still alive
					{
						// each marine will attack the first zergling in the swarm
						cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
						swarm[j].takeDamage(squad[i].attack());
						if (!swarm[j].isAlive()) // if the zergling dies, it is marked as such
						{
							cout << "The zergling target dies." << endl;
						}
						break;
					}
				}
			}
		}

		if (marineCount(squad, 10) > 0) // if there's at least one marine alive
		{
			marinesWin = false;
			for (size_t i = 0; i < zerglingCount(swarm, 20); i++) // loop through zerglings
			{
				if (marineCount(squad, 10) > 0)
				{
					cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
					int nextAliveMarine = 10 - marineCount(squad, 10);
					squad[nextAliveMarine].takeDamage(swarm[i].attack());
					if (squad[nextAliveMarine].health <= 0)
					{
						cout << "There are " << marineCount(squad, 10) << " marine(s) left." << endl;
					}
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marinesWin) //If there is a marine still alive
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerglings win." << endl;
	}
	system("pause");
}
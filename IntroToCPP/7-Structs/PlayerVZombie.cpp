#include <iostream>
#include "PlayerVZombie.h"

using std::cout;
using std::cin;
using std::endl;

void TakeDamage(fighter source, fighter target)
{
	if (source.attack - target.defense > 0)
	{
		target.HP -= source.attack - target.defense;
	}
}

fighter Player = {100, 5, 3};
fighter Zombie = { 50, 4, 4 };

void DisplayStats()
{
	if (Player.HP <= 0)
	{
		Player.HP = 0;
	}
	if (Zombie.HP <= 0)
	{
		Zombie.HP = 0;
	}
	cout << "Player\nHP: " << Player.HP << "\nAttack: " << Player.attack << "\nDefense: " << Player.defense << endl;
	cout << "Zombie\nHP: " << Zombie.HP << "\nAttack: " << Zombie.attack << "\nDefense: " << Zombie.defense << endl;
}

void Battle()
{
	char command;
	bool gameOver = false;
	cout << "A zombie appears!" << endl;
	while (!gameOver)
	{
		void DisplayStats();
		cout << "What do you want to do?" << endl;
		cout << "[A]ttack" << endl;
		bool okToGo = false;
		while (!okToGo)
		{
			cin >> command;
			if (command == 'a')
			{
				TakeDamage(Player, Zombie);
				cout << "The player dealt " << Player.attack - Zombie.defense << " damage to the zombie!" << endl;
				okToGo = true;
			}
			else
			{
				cout << "That's not a command! Try again!" << endl;
			}
		}
		void DisplayStats();
		if (Player.HP <= 0 || Zombie.HP <= 0)
		{
			gameOver = true;
			break;
		}
		cout << "It is now the zombie's turn to attack." << endl;
		cin >> command;
		TakeDamage(Zombie, Player);
		cout << "The zombie dealt " << Zombie.attack - Player.defense << " damage to the player!" << endl;
		void DisplayStats();
		cin >> command;
		if (Player.HP <= 0 || Zombie.HP <= 0)
		{
			gameOver = true;
			break;
		}
	}
	if (Zombie.HP = 0)
	{
		cout << "You defeated the zombie! Congratulations!" << endl;
		cin >> command;
	}
	if (Player.HP = 0)
	{
		cout << "The zombie has defeated you. He will now feast on your brains." << endl;
		cin >> command;
	}
}
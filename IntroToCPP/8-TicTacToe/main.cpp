#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

char spaces[3][3] = { { '_', '_', '_' }, { '_', '_', '_' }, { '_', '_', '_' } };

int main()
{
	char userInput;
	cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "To play, use the number pad to select the space you want to occupy, like so:" << endl;
	cout << " _ _ _ _ _ _" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| 7 | 8 | 9 |" << endl;
	cout << "|_ _|_ _|_ _|" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| 4 | 5 | 6 |" << endl;
	cout << "|_ _|_ _|_ _|" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| 1 | 2 | 3 |" << endl;
	cout << "|_ _|_ _|_ _|\n" << endl;
	cout << "Player 1: 'X's" << endl;
	cout << "Player 2: 'O's" << endl;
	cout << "Multiple inputs can be entered at once to play a faster game!" << endl;
	cout << "Press any key to begin playing!" << endl;
	cin >> userInput;
	//Game Loop
	bool okToGo = false;
	bool gameOver = false;
	bool draw = false;
	int turnCount = 0;
	while (!gameOver)
	{
		okToGo = false;
		while (!okToGo)
		{
			cout << "Player 1's turn." << endl;
			DisplayBoard();
			cin >> userInput;
			if (userInput < '1' || userInput > '9')
			{
				cout << "Invalid input, try again." << endl;
			}
			else
			{
				switch (userInput)
				{
				case '1':
					if (spaces[2][0] == '_')
					{
						spaces[2][0] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '2':
					if (spaces[2][1] == '_')
					{
						spaces[2][1] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '3':
					if (spaces[2][2] == '_')
					{
						spaces[2][2] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '4':
					if (spaces[1][0] == '_')
					{
						spaces[1][0] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '5':
					if (spaces[1][1] == '_')
					{
						spaces[1][1] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '6':
					if (spaces[1][2] == '_')
					{
						spaces[1][2] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '7':
					if (spaces[0][0] == '_')
					{
						spaces[0][0] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '8':
					if (spaces[0][1] == '_')
					{
						spaces[0][1] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '9':
					if (spaces[0][2] == '_')
					{
						spaces[0][2] = 'x';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				}
				system("cls");
			}
		}

		if (GameOverYet('x'))
		{
			gameOver = true;
			break;
		}
		if (turnCount == 9)
		{
			draw = true;
			break;
		}


		okToGo = false;
		while (!okToGo)
		{
			cout << "Player 2's turn." << endl;
			DisplayBoard();
			cin >> userInput;
			if (userInput < '1' || userInput > '9')
			{
				cout << "Invalid input, try again." << endl;
			}
			else
			{
				switch (userInput)
				{
				case '1':
					if (spaces[2][0] == '_')
					{
						spaces[2][0] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '2':
					if (spaces[2][1] == '_')
					{
						spaces[2][1] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '3':
					if (spaces[2][2] == '_')
					{
						spaces[2][2] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '4':
					if (spaces[1][0] == '_')
					{
						spaces[1][0] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '5':
					if (spaces[1][1] == '_')
					{
						spaces[1][1] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '6':
					if (spaces[1][2] == '_')
					{
						spaces[1][2] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '7':
					if (spaces[0][0] == '_')
					{
						spaces[0][0] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '8':
					if (spaces[0][1] == '_')
					{
						spaces[0][1] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				case '9':
					if (spaces[0][2] == '_')
					{
						spaces[0][2] = 'o';
						okToGo = true;
					}
					else
					{
						cout << "That space is already occupied, try again." << endl;
						continue;
					}
					turnCount++;
					break;
				}
				system("cls");
			}
		}
		if (GameOverYet('o'))
		{
			gameOver = true;
			break;
		}
		if (turnCount == 9)
		{
			draw = true;
			break;
		}

	}
	if (!draw)
	{
		if (GameOverYet('x'))
		{
			system("cls");
			cout << "\nPlayer 1 Wins!\n\nCongratulations!" << endl;
			DisplayBoard();
			cin >> userInput;
		}
		if (GameOverYet('o'))
		{
			system("cls");
			cout << "\nPlayer 2 Wins!\n\nCongratulations!" << endl;
			DisplayBoard();
			cin >> userInput;
		}
	}
	else
	{
		cout << "\nThe game was a draw!\n\nNo one wins!" << endl;
		cin >> userInput;
	}
}

void DisplayBoard()
{
	cout << " _ _ _ _ _ _" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| " << spaces[0][0] << " | " << spaces[0][1] << " | " << spaces[0][2] << " |" << endl;
	cout << "|_ _|_ _|_ _|" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| " << spaces[1][0] << " | " << spaces[1][1] << " | " << spaces[1][2] << " |" << endl;
	cout << "|_ _|_ _|_ _|" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| " << spaces[2][0] << " | " << spaces[2][1] << " | " << spaces[2][2] << " |" << endl;
	cout << "|_ _|_ _|_ _|\n" << endl;
}
bool GameOverYet(char token)
{
	if ((spaces[0][0] == token && spaces[0][1] == token && spaces[0][1] == token) ||
		(spaces[1][0] == token && spaces[1][1] == token && spaces[1][2] == token) ||
		(spaces[2][0] == token && spaces[2][1] == token && spaces[2][2] == token) ||
		(spaces[0][0] == token && spaces[1][0] == token && spaces[2][0] == token) ||
		(spaces[0][1] == token && spaces[1][1] == token && spaces[2][1] == token) ||
		(spaces[0][2] == token && spaces[1][2] == token && spaces[2][2] == token) ||
		(spaces[0][0] == token && spaces[1][1] == token && spaces[2][2] == token) ||
		(spaces[2][0] == token && spaces[1][1] == token && spaces[0][2] == token))
	{
		return true;
	}
	else
	{
		return false;
	}
}
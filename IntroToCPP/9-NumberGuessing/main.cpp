#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int userInput = 0;
	int tries = 0;
	int maxRange = 0;
	int guess = 0;
	int number = 0;
	bool win = false;
	float winCounter = 0;
	float gameCounter = 0;
	bool exit = false;
	while (!exit)
	{
		win = false;
		while (!win)
		{
			system("cls");
			cout << "Welcome to Guess My Number!" << endl;
			cout << "\nWins: " << winCounter << "\n" << endl;
			if (winCounter > 0)
			{
				cout << "You won " << (winCounter / gameCounter) * 100 << "% of your games!" << endl;
			}
			cout << "Select a difficulty:" << endl;
			cout << "1.) Easy: 15 tries, 1-50 range." << endl;
			cout << "2.) Medium: 10 tries, 1-100 range." << endl;
			cout << "3.) Hard: 5 tries, 1-200 range." << endl;
			cout << "4.) Custom Difficulty" << endl;
			cout << "5.) Exit" << endl;
			cin >> userInput;
			if (userInput < 1 || userInput > 5)
			{
				cout << "Please choose a valid difficulty." << endl;
				system("pause");
			}
			else
			{
				win = true;
			}
		}
		win = false;
		switch (userInput)
		{
		case 1:
			tries = 15;
			maxRange = 50;
			break;
		case 2:
			tries = 10;
			maxRange = 100;
			break;
		case 3:
			tries = 5;
			maxRange = 200;
			break;
		case 4:
			cout << "How many tries do you want?" << endl;
			cin >> tries;
			cout << "What is the maximum range of numbers?" << endl;
			cin >> maxRange;
			break;
		case 5:
			exit = true;
			break;
		}
		number = randomNumber(maxRange);
		while (!win && !exit)
		{
			if (tries > 0)
			{
				system("cls");
				cout << "You have " << tries << " tries left." << endl;
				cout << "Guess the number from 1 to " << maxRange << "." << endl;
				cin >> guess;
				if (guess < number)
				{
					cout << "The number is greater than that!" << endl;
					tries--;
					system("pause");
				}
				if (guess > number)
				{
					cout << "The number is smaller than that!" << endl;
					tries--;
					system("pause");
				}
				if (guess == number)
				{
					cout << "You guessed it! The number was " << number << "!" << endl;
					winCounter++;
					win = true;
				}
			}
			else
			{
				cout << "You're out of tries! The number was " << number << ". Thank you for playing!" << endl;
				win = true;
			}
		}
		gameCounter++;
		system("pause");
	}
}


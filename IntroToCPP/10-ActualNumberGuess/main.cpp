#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main()
{
	int guess = 50;
	int userInput = 0;
	bool win = false;
	int guessCount = 0;
	int min = 1;
	int max = 100;
	cout << "Welcome to Guess My Number 2: The Computer Does It This Time!" << endl;
	cout << "\nStart by thinking of a number from 1-100.\nI will then try to guess your number." << endl;
	cout << "\nAll you have to do is say whether the guess is too HIGH or too LOW." << endl;
	cout << "\nWhen you have thought of your number, press ENTER." << endl;
	getchar();
	while (!win)
	{
		cout << "I'm guessing the number " << guess << ".\nIs this number..." << endl;
		cout << "1.) Too high" << endl;
		cout << "2.) Correct" << endl;
		cout << "3.) Too low" << endl;
		guessCount++;
		cin >> userInput;
		if (userInput < 1 || userInput > 3)
		{
			cout << "Invalid input, try again." << endl;
			cin >> userInput;
		}
		else
		{
			int oldGuess = guess;
			switch (userInput)
			{
			case 1:
				max = guess;
				guess = midPoint(min, max);
				if (oldGuess == guess)
				{
					cout << "Your number has to be " << guess << "!" << endl;
					cout << "I guessed the number in " << guessCount << " guesse(s)." << endl;
					getchar();
					getchar();
					win = true;
				}
				break;
			case 2:
				cout << "Cool! I guessed the number in " << guessCount << " guesse(s)!" << endl;
				getchar();
				getchar();
				win = true;
				break;
			case 3:
				min = guess;
				guess = midPoint(min, max);
				if (oldGuess == guess)
				{
					cout << "Your number has to be " << guess << "!" << endl;
					cout << "I guessed the number in " << guessCount << " guesse(s)." << endl;
					getchar();
					getchar();
					win = true;
				}
				break;
			}
		}
		system("cls");
	}


	//Forzascii car
}
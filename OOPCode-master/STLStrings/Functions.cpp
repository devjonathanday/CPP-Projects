#include<iostream>
#include<string>
#include"Functions.h"
#include <time.h>

using namespace std;

string EveryOther(string inputString)
{
	string newString (inputString.length(), ' ');
	int index = 0;
	for(int i = 0; i < inputString.length(); i++)
	{
		if (i % 2 == 0)
		{
			newString[index] = inputString[i];
			index++;
		}
	}
	return newString;
}
int countLetters(string inputString, char check)
{
	/*int spaceCount = 0;
	for (int i = 0; i < inputString.length(); i++)
	{
		spaceCount += inputString.find(32, i);
	}
	return spaceCount;*/

	int spaceCount = 0;
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == check)
		{
			spaceCount++;
		}
	}
	return spaceCount;
}
int patternOccurrences(string inputString, string pattern)
{
	int occurrences = 0;
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString.find(pattern, i) != string::npos)
		{
			occurrences++;
			i = inputString.find(pattern, i);
		}
	}
	return occurrences;
}
void Hangman()
{
	cout << "Hangman but with cars!" << endl;
	cout << "Select a difficulty:" << endl;
	cout << "[1] Common car manufacturers\n[2] Less common car manufacturers\n[3] All car manufacturers" << endl;
	int userInput = 0;
	cin >> userInput;
	string answer (30, ' ');
	string letters(30, 0);
	bool gameOver = false;
	if (userInput == 1)
	{
		int rando = randomNumber(10);
		switch (rando)
		{
		default:
		case 1:
			answer = "ford";
			break;
		case 2:
			answer = "chevrolet";
			break;
		case 3:
			answer = "mazda";
			break;
		case 4:
			answer = "toyota";
			break;
		case 5:
			answer = "honda";
			break;
		case 6:
			answer = "volkswagen";
			break;
		case 7:
			answer = "hyundai";
			break;
		case 8:
			answer = "dodge";
			break;
		case 9:
			answer = "bmw";
			break;
		case 10:
			answer = "nissan";
			break;
		}
	}
	if (userInput == 2)
	{
		int rando = randomNumber(10);
		switch (rando)
		{
		default:
		case 1:
			answer = "buick";
			break;
		case 2:
			answer = "oldsmobile";
			break;
		case 3:
			answer = "pontiac";
			break;
		case 4:
			answer = "chrysler";
			break;
		case 5:
			answer = "acura";
			break;
		case 6:
			answer = "cadillac";
			break;
		case 7:
			answer = "suzuki";
			break;
		case 8:
			answer = "subaru";
			break;
		case 9:
			answer = "mitsubishi";
			break;
		case 10:
			answer = "tesla";
			break;
		}
	}
	else
	{
		cout << "Invalid input! We'll go with difficulty 1." << endl;
		int rando = randomNumber(10);
		switch (rando)
		{
		default:
		case 1:
			answer = "ford";
			break;
		case 2:
			answer = "chevrolet";
			break;
		case 3:
			answer = "mazda";
			break;
		case 4:
			answer = "toyota";
			break;
		case 5:
			answer = "honda";
			break;
		case 6:
			answer = "volkswagen";
			break;
		case 7:
			answer = "hyundai";
			break;
		case 8:
			answer = "dodge";
			break;
		case 9:
			answer = "bmw";
			break;
		case 10:
			answer = "nissan";
			break;
		}
	}
	int strikes = 0;
	char guess;
	while (!gameOver)
	{
		system("cls");
		cout << "Try to guess my word!" << endl;
		HangmanStatus(strikes);
		for (int i = 0; i < answer.length(); i++)
		{
			if (letters[i] == NULL)
			{
				cout << "_ ";
			}
			else
			{
				cout << letters[i] << " ";
			}
		}
		cout << "\nYou have " << strikes << " strike(s). 5 strikes and you're out." << endl;
		cout << "What letter do you want to guess?" << endl;
		cin >> guess;
		int found = countLetters(answer, guess);
		if (found <= 0)
		{
			cout << "That letter is not in the word!" << endl;
			strikes++;
			system("pause");
		}
		else
		{
			for (int i = 0; i < answer.length(); i++)
			{
				if (answer[i] == guess)
				{
					letters[i] = answer[i];
				}
				/*if (answer.find(guess, i) != string::npos)
				{
					letters[i] = answer[i];
					i = answer.find(guess, i);
				}*/
			}
		}

		//Win/Lose condition
		bool solved = true;
		for (int i = 0; i < answer.length(); i++)
		{
			if (letters[i] == 0)
			{
				solved = false;
			}
		}
		if (solved)
		{
			system("cls");
			cout << "You win! The word was " << answer << "!" << endl;
			gameOver = true;
		}
		
		if (strikes >= 5)
		{
			system("cls");
			cout << "You lost! The word was " << answer << "." << endl;
			gameOver = true;
		}
	}

}
void HangmanStatus(int strikes)
{
	switch (strikes)
	{
	case 0:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	case 1:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |      O" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	case 2:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |      O" << endl;
		cout << " |      |" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	case 3:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |      O" << endl;
		cout << " |     -|-" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	case 4:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |      O" << endl;
		cout << " |     -|-" << endl;
		cout << " |       \\" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	case 5:
		cout << "  _______" << endl;
		cout << " |      |" << endl;
		cout << " |      O" << endl;
		cout << " |     -|-" << endl;
		cout << " |     / \\" << endl;
		cout << " |" << endl;
		cout << "_|_" << endl;
		cout << "" << endl;
		break;
	}
}

int randomNumber(int maxRange) // Generates a random number, starting at 1 and going until maxRange
{
	srand(time(NULL));
	return rand() % maxRange + 1;
}
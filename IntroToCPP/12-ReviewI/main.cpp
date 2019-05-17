#include<iostream>
#include "Functions.h"

using namespace std;

int main()
{
	Quiz();
	printMultiples();
	birthdayCandles();
	arrayRotation();
}
int Quiz()
{
	system("cls");
	char userInput;
	cout << "Multiple choice quiz!" << endl;
	cout << "Question 1) What is the capital of Washington?" << endl;
	cout << "A) Bellevue\nB) Olympia\nC) Seattle\nD) Yakima" << endl;
	bool okToGo = false;
	while (!okToGo)
	{
		userInput = 0;
		cin >> userInput;
		switch (userInput)
		{
		case 'a':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'b':
			cout << "Correct! Next Question..." << endl;
			system("pause");
			okToGo = true;
			break;
		case 'c':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'd':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		default:
			cout << "Invalid input! Try again!" << endl;
			system("pause");
			break;
		}
	}
	system("cls");
	cout << "Multiple choice quiz!" << endl;
	cout << "Question 2) Which of the following nations has the largest population in 2018?" << endl;
	cout << "A) North Korea\nB) Luxembourg\nC) Denmark\nD) Syria" << endl;
	okToGo = false;
	while (!okToGo)
	{
		userInput = 0;
		cin >> userInput;
		switch (userInput)
		{
		case 'b':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'a':
			cout << "Correct! Next Question..." << endl;
			system("pause");
			okToGo = true;
			break;
		case 'c':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'd':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		default:
			cout << "Invalid input! Try again!" << endl;
			system("pause");
			break;
		}
	}
	system("cls");
	cout << "Multiple choice quiz!" << endl;
	cout << "Question 3) Which of the following locations does not have an AIE campus?" << endl;
	cout << "A) Canberra, Australia\nB) Lafayette, Louisiana\nC) Brisbane, Australia\nD) Adelaide, Australia" << endl;
	okToGo = false;
	while (!okToGo)
	{
		userInput = 0;
		cin >> userInput;
		switch (userInput)
		{
		case 'a':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'c':
			cout << "Correct! Next Question..." << endl;
			system("pause");
			okToGo = true;
			break;
		case 'b':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		case 'd':
			cout << "Incorrect! Next Question!" << endl;
			system("pause");
			okToGo = true;
			break;
		default:
			cout << "Invalid input! Try again!" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
int printMultiples()
{
	int startingNum = 0;
	int endingNum = 0;
	cout << "Let's print some multiples of 5." << endl;
	cout << "Starting number: ";
	cin >> startingNum;
	cout << "Ending number: ";
	cin >> endingNum;
	for (int i = startingNum; i < endingNum + 1; i++)
	{
		cout << (i * 5) << endl;
	}
	system("pause");
	return 0;
}
int birthdayCandles()
{
	cout << "Let's blow out some candles!" << endl;
	system("pause");
	int biggestNum = 0;
	int Candles[] { 3, 3, 2, 4, 3, 5};
	for (int i = 0; i < 6; i++)
	{
		if (Candles[i] >= biggestNum)
		{
			cout << "Blown" << endl;
			biggestNum = Candles[i];
		}
		else
		{
			cout << "Lit" << endl;
		}
	}
	system("pause");
	return 0;
}
int arrayRotation()
{
	int myArray[]{ 32, 25, 76, 69, 11, 88 };
	int userInput = 0;
	cout << "Array: ";
	for (int i = 0; i < 6; i++)
	{
		cout << myArray[i] << ", ";
	}
	cout << "How many times do you want to shift this array?" << endl;
	cin >> userInput;
	for (int i = 0; i < userInput; i++)
	{
		int savedNum = myArray[5];
		for (int j = 5; j > 0; j--)
		{
			myArray[j] = myArray[j - 1];
		}
		myArray[0] = savedNum;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << myArray[i] << ", ";
	}
	system("pause");
	return 0;
}
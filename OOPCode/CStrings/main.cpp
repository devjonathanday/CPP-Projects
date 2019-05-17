#include<iostream>
#include"Functions.h"
#include<cmath>

using namespace std;

int main()

{   /*
	char name[30] {};
	cout << "What's your name? ";
	cin.getline(name, 30);
	cout << "Hello " << name << "!" << endl;

	char favColor[30] {};
	cout << "What's your favorite color? ";
	cin.getline(favColor, 30);

	if (!strcmp(ToUpper(favColor), "RED"))
	{
		cout << "Red is the color of blood." << endl;
	}
	else if (!strcmp(ToUpper(favColor), "ORANGE"))
	{
		cout << "Orange is a great color." << endl;
	}
	else if (!strcmp(ToUpper(favColor), "BLUE"))
	{
		cout << "Blue is my favorite color too!" << endl;
	}
	else if (!strcmp(ToUpper(favColor), "BLACK"))
	{
		cout << "That's metal as heck." << endl;
	}
	else
	{
		cout << "I've never heard of that color." << endl;
	}
	*/
	char userInput[100]{};
	/*
	cout << "Give me a phrase so I can SHOUT it!" << endl;
	cin.getline(userInput, 100);
	cout << ToUpper(userInput) << "!\n" << endl;

	cout << "Give me a phrase with spaces!" << endl;
	cin.getline(userInput, 100);
	cout << RemoveWhiteSpace(userInput) << endl;

	int start;
	int end;

	cout << "Give me a phrase!" << endl;
	cin.getline(userInput, 100);
	cout << "Enter the start of substring: ";
	cin >> start;
	cout << "Enter the end of substring: ";
	cin >> end;
	cout << GetSubString(userInput, start, end) << endl;
	system("pause");
	system("cls");
	cout << "Give me a palindrome to test!" << endl;
	*/
	cin.getline(userInput, 100);

	//cout << ReverseString(userInput) << endl;

	//cout << ReverseString(userInput) << endl;
	//cout << stringLength(userInput) << endl;

	if (PalindromeTest(userInput))
	{
		cout << userInput << " is a palindrome!" << endl;
	}
	else
	{
		cout << userInput << " is not a palindrome!" << endl;
	}

	cout << "Enter a string to have the spaces trimmed off the beginning and end!" << endl;
	cin.getline(userInput, 100);
	cout << trimString(userInput);
	cin.getline(userInput, 100);
	//system("cls");
	int input;
	bool quit = false;
	while (!quit)
	{
		cout << "Would you like to decode or encode a string?" << endl;
		cout << "[1] Decode" << endl;
		cout << "[2] Encode" << endl;
		cin >> input;
		if (input == 1)
		{
			cout << "Enter your string. [Max 100 characters]" << endl;
			//cin.getline(userInput, 100);
			cin >> userInput;
			cout << "How many times was the string shifted?" << endl;
			cin >> input;
			cout << "Your string: " << shiftCipher(userInput, input, false) << endl;
			quit = true;
		}
		else if (input == 2)
		{
			cout << "Enter your string. [Max 100 characters]" << endl;
			//cin.getline(userInput, 100);
			cin >> userInput;
			cout << "How many times do you want to shift the string?" << endl;
			cin >> input;
			cout << "Your string: " << shiftCipher(userInput, input, true) << endl;
			quit = true;
		}
		else
		{
			cout << "Invalid input. Try again." << endl;
		}
	}

	system("pause");
	return 0;
}

char * ToUpper(char * myString)
{
	/*
	//The boring way to do it
	for (int i = 0; i < strlen(myString); i++)
	{
		myString[i] = toupper(myString[i]);
	}*/

	//The fancy way to do it
	for (int i = 0; i < strlen(myString); i++)
	{
		if (myString[i] >= 97 && myString[i] <= 122)
		{
			myString[i] -= 32;
		}
	}
	return myString;
}

char * RemoveWhiteSpace(char * myString)
{
	char * newString = new char[100]();
	int index = 0;
	for (int i = 0; i < strlen(myString); i++)
	{
		if (myString[i] != 32)
		{
			newString[index] = myString[i];
			index++;
		}
	}
	return newString;
}

char * GetSubString(char * myString, int start, int end)
{
	char * newString = new char[100]();
	for (int i = start; i < end+1; i++)
	{
		newString[i] = myString[i];
	}
	return newString;
}

bool PalindromeTest(char * myString)
{
	bool value = true;
	for (int i = 0; i < strlen(myString) / 2; i++)
	{
		if(myString[i] != myString[strlen(myString) - i - 1])
		{
			value = false;
		}
	}
	return value;
}

char * ReverseString(char * myString)
{
	//now the fLIP
	char * reversedString = myString;
	for (int i = 0; i < strlen(reversedString) / 2; i++)
	{
		int temp = reversedString[i];
		reversedString[i] = reversedString[strlen(reversedString) - i - 1];
		reversedString[strlen(reversedString) - 1 - i] = temp;
	}
	return reversedString;
}
int stringLength(char * myString)
{
	int counter = 0;
	for (int i = 0; i < 100; i++)
	{
		if (myString[i] != NULL)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	return counter;
}

char * trimString(char * myString)
{
	char * newString = new char[100]();
	bool startCounting = false;
	int index = 0;
	int endCounter = 0;

	//Counts how many spaces there are at the end of the string
	for (int i = strlen(myString) - 1; i > -1; i--)
	{
		if (myString[i] == 32)
		{
			endCounter++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < strlen(myString) - endCounter; i++)
	{
		if (startCounting)
		{
			newString[index] = myString[i];
			index++;
		}
		else
		{
			if (myString[i] != 32)
			{
				startCounting = true;
				newString[index] = myString[i];
				index++;
			}
		}
	}
	return newString;
}
char * shiftCipher(char * myString, int shift, bool encode)
{
	for (int j = 0; j < abs(shift); j++)
	{
		for (int i = 0; i < strlen(myString); i++)
		{
			if (encode)
			{
				myString[i] += 1;
			}
			else
			{
				myString[i] -= 1;
			}

			if (myString[i] > 90 && myString[i] < 97)
			{
				myString[i] = 97;
			}
			if (myString[i] > 122 || myString[i] < 65)
			{
				myString[i] = 65;
			}
		}
	}
	return myString;
}
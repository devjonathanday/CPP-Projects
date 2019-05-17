#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

int main()
{
	

	string myString = "Every other letter in this sentence.";
	string pattern;
	cout << EveryOther(myString) << endl;

	cout << "What is your name?" << endl;
	getline(cin, myString);
	cout << "You are " << myString << ", The Great!" << endl;

	cout << "Give me a string and I will count the spaces!" << endl;
	getline(cin, myString);
	cout << "There are " << countLetters(myString, 32) << " spaces in that string!" << endl;
	Hangman();

	system("pause");
	return 0;
}
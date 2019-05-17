#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;



int main()
{
	Contact AddressBook[5] = 
	{ 
		{"Jonathan", "4255121499", "3116 54th St SW"}, 
		{"Madeline", "4255125158", "4500 Harbour Pointe Dr"}, 
		{"Father", "4255122500", "3116 54th St SW"}, 
		{"Mother", "4255122503", "Hell, Portland, OR"}, 
		{"Gavin", "4253438779", "Hidden Oaks, Edmonds, WA"} 
	};

	char userInput1[100]{};
	char userInput2[100]{};
	int userInput3 = 0;
	/*cout << "Give me the start of a string! ";
	cin.getline(userInput1, 100);
	cout << "Give me the end of a string! ";
	cin.getline(userInput2, 100);
	cout << "Put together: " << appendString(userInput1, userInput2, 200) << endl;*/
	/*cout << "Give me the start of a string! ";
	cin.getline(userInput1, 100);
	cout << "Give me another string! ";
	cin.getline(userInput2, 100);
	cout << "What position do you want to put that string into the first? ";
	cin >> userInput3;
	cout << "Put together: " << insertString(userInput1, userInput2, 200, userInput3) << endl;*/
	/*cout << "Give me a string to count the words!" << endl;
	cin.getline(userInput1, 100);
	cout << wordCount(userInput1) << endl;*/
	cin.getline(userInput1, 100);
	wordWrap(userInput1, 20);

	string newName;
	string newNumber;
	string newAddress;

	cout << "-----ADDRESS BOOK-----" << endl;
	cout << "[1] Add Contact" << endl;
	cout << "[2] Remove Contact" << endl;
	cout << "[3] View Contacts" << endl;
	cin >> userInput3;
	system("pause");
	return 0;
}
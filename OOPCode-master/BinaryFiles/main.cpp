#include<iostream>
#include<string>
#include<fstream>
#include"Functions.h"

using namespace std;

int main()
{
	HelloWorld("HelloWorld.bin");
	cout << "\"Hello World\" has been printed to the file!" << endl;
	system("pause");

	dataSaved myData;
	string fileName;
	int userInput;
	cout << "You now have a game you know everything about!" << endl;
	cout << "Would you like to...\n[1] Save your game\n[2] Load a game\n[3] Skip to MCQ" << endl;
	while (true)
	{
		cin >> userInput;
		if (userInput == 1)
		{
			cout << "How many times have you died? ";
			cin >> myData.deathCount;
			cout << "What's the deepest floor you've been to? ";
			cin >> myData.deepestFloor;
			cout << "Have you beaten the game?\n[1] Yes\n[0] No" << endl;
			cin >> myData.hasBeatenGame;
			cout << "How long have you been playing the game (in seconds)? ";
			cin >> myData.timePlayed;
			cout << "What is the player's name? ";
			cin.ignore();
			getline(cin, myData.playerName);
			cout << "Enter the name of your new save file (without file extension)" << endl;
			getline(cin, fileName);
			fileName.append(".bin");
			SaveData(myData, fileName);
			break;
		}
		if (userInput == 2)
		{
			cout << "What is the file name of your saved game?" << endl;
			cin >> fileName;
			myData = LoadData(fileName);
			cout << "Contents of \"" << fileName << "\": " << endl;
			cout << "Player name: " << myData.playerName << endl;
			cout << "Death count: " << myData.deathCount << endl;
			cout << "Deepest floor explored: " << myData.deepestFloor << endl;
			if (myData.hasBeatenGame)
			{
				cout << "Game Cleared: Yes" << endl;
			}
			else
			{
				cout << "Game Cleared: No" << endl;
			}
			cout << "Time played: " << myData.timePlayed << endl;
			break;
		}
		if (userInput == 3)
		{
			break;
		}
		else
		{
			cout << "Invalid input! Try again." << endl;
			continue;
		}
		system("pause");
	}

	//Monster Creature Quest

	MonsterQuest();

	return 0;
}
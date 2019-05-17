#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

void HelloWorld(string fileName)
{
	fstream file;
	file.open(fileName, ios::app | ios::binary);
	file << "Hello World!";
	file.flush();
	file.close();
}
void SaveData(dataSaved data, string fileName)
{
	fstream file;
	file.open(fileName, ios::out | ios::binary);
	file << data.deathCount << "\n";
	file << data.deepestFloor << "\n";
	file << data.hasBeatenGame << "\n";
	file << data.playerName << "\n";
	file << data.timePlayed;
	file.flush();
	file.close();
	cout << "Saved successfully." << endl;
}
dataSaved LoadData(string fileName)
{
	fstream file;
	dataSaved dataToWrite;
	file.open(fileName, ios::in);
	if (!file.is_open())
	{
		cout << "Could not find the file requested." << endl;
		return dataToWrite;
	}
	string line;
	while (getline(file, line))
	{
		dataToWrite.deathCount = stoi(line);

		getline(file, line);
		dataToWrite.deepestFloor = stoi(line);

		getline(file, line);
		dataToWrite.hasBeatenGame = stoi(line);

		getline(file, line);
		dataToWrite.playerName = line;

		getline(file, line);
		dataToWrite.timePlayed = stod(line);
	}
	cout << "Loaded successfully." << endl;
	return dataToWrite;
}

void MonsterQuest()
{
	//Monster Creature Quest

	fstream file;
	int userInput = 0;
	bool okToGo = false;
	int IDList[100]{ 0 };

	cout << "Welcome to Monster Creature Quest!" << endl;
	while (!okToGo)
	{
		system("cls");
		string tempID;
		string tempName;
		string tempFlavorText;

		cout << "\nWhat would you like to do?\n" << endl;
		cout << "1) Add a monster by ID\n2) Remove a monster by ID\n3) View a monster by ID\n4) Browse monsters\n5) Exit" << endl;
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cout << "What ID would you like to save this monster under? (1-99)" << endl;
			cin >> tempID;
			if (stoi(tempID) < 1 || stoi(tempID) > 99)
			{
				cout << "ID out of bounds. Choose a number from 1-99" << endl;
			}
			if (IDList[stoi(tempID)] != 0) //Check if that ID already exists
			{
				cout << "That ID already contains a monster! Remove it first or choose another ID." << endl;
				system("pause");
				break;
			}
			else
			{
				IDList[stoi(tempID)] = 1;
				cout << "What is the name of your monster?" << endl;
				cin.ignore();
				getline(cin, tempName);
				cout << "Describe your monster in a short description." << endl;
				getline(cin, tempFlavorText);
				file.open(tempID.append(".bin"), ios::out | ios::binary);
				file << tempName << ":" << endl;
				file << tempFlavorText;
				file.flush();
				file.close();
				cout << tempName << " was added successfully!" << endl;
				system("pause");
				break;
			}
		case 2:
		{
			cout << "What is the ID of the monster you would like to remove?" << endl;
			cin >> tempID;
			string tempFileName = tempID.append(".bin");
			if (remove(tempFileName.c_str()))
			{
				cout << "Could not find such file to delete." << endl;
				system("pause");
			}
			else
			{
				IDList[stoi(tempID)] = 0;
				cout << "File deleted successfully." << endl;
			}
			break;
		}
		case 3:
			cout << "What is the ID of the monster you would like to view?" << endl;
			cin.ignore();
			cin >> tempID;
			if (IDList[stoi(tempID)] != 0)
			{
				string tempFileName = tempID.append(".bin");
				file.open(tempFileName.c_str(), ios::in | ios::binary);
				string buffer;
				buffer.clear();
				getline(file, buffer);
				cout << buffer << endl;
				getline(file, buffer);
				cout << buffer << endl;
				system("pause");
			}
			else
			{
				cout << "Could not find such file to view." << endl;
			}
			break;
		case 4:
			for (int i = 0; i < 99; i++)
			{
				if (IDList[i] != 0)
				{
					tempID = to_string(i);
					string tempFileName = tempID.append(".bin");
					file.open(tempFileName.c_str(), ios::in | ios::binary);
					string buffer;
					buffer.clear();
					getline(file, buffer);
					cout << buffer << endl;
					getline(file, buffer);
					cout << buffer << endl;
					file.flush();
					file.close();
				}
				//cout << endl;
			}
			system("pause");
			break;
		case 5:
			okToGo = true;
			break;
		default:
			cout << "Invalid input. Try again!" << endl;
			break;
		}
		file.flush();
		file.close();
	}
	
	for (int i = 0; i < 100; i++)
	{
		if (IDList[i] != 0)
		{
			string tempFileName = to_string(i).append(".bin");
			remove(tempFileName.c_str());
			IDList[i] = 0;
		}
	}
	cout << "All your monsters went on to live full, long lives outside of your computer." << endl;
	cout << "See ya next time!" << endl;
	system("pause");
}

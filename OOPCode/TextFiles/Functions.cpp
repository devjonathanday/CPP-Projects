#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include"Functions.h"

using namespace std;

int randomNumber(int minRange, int maxRange) // Generates a random number, starting at minRange (inclusive) and going until maxRange (inclusive)
{
	//srand(time(NULL));
	return rand() % maxRange + minRange;
}
void ReadFile(fstream &file)
{
	string fileName;
	cout << "What file name would you like to read?" << endl;
	while (true)
	{
		cin >> fileName;
		file.open(fileName, ios::in);
		if (!file.is_open())
		{
			cout << "That file does not exist. Type a valid filename." << endl;
			continue;
		}
		break;
	}
	cout << "Contents of " << fileName << ":" << endl;
	string buffer;
	while (std::getline(file, buffer))
	{
		std::cout << buffer << std::endl;
	}
	system("pause");
	file.close();
}
void SaveFile(fstream &file)
{
	cout << "You are going to make a save file for your information." << endl;

	string saveFile;
	string name;
	int age;
	string favColor;

	cout << "Where would you like to save this? ";
	cin >> saveFile;
	cout << "What is your name? ";
	getline(cin, name);
	cout << "How old are you? ";
	cin >> age;
	cout << "What is your favorite color? ";
	getline(cin, favColor);

	file.open(saveFile, ios::out);

	file << "Name: " << name << "\nAge: " << age << "\nFavorite Color: " << favColor;

	file.flush();
	file.close();

	cout << "Thanks! Check your file for your results." << endl;
}
void CorruptFile(fstream &file)
{
	file.open("dyingWords.txt", ios::in);
	string fileString;
	while (getline(file, fileString)) //Set fileString's value equal to the text in "file".
	{
		for (int i = 0; i < fileString.length(); i++)
		{
			if (randomNumber(1, 100) > 50)
			{
				cout << "?";
			}
			else 
			{
				cout << fileString[i];
			}
		}
		cout << endl;
	}
}
void SeparateFileByCommas(fstream &file, string numList[], size_t arrSize)
{
	file.open("separateMe.txt", ios::in);
	string fileString;
	string currentValue;
	int localIndex = 0; //currentValue starts at 0
	int globalIndex = 0; //the index of the final array
	while (getline(file, fileString)) //Set fileString's value equal to the text in "file".
	{
		for (int i = 0; i < fileString.length(); i++) //Iterate through the following code for every character in the array.
		{
			if (fileString[i] == ',')
			{
				numList[globalIndex] = currentValue;
				currentValue.clear();
				localIndex = 0;
				globalIndex++;
			}
			else
			{
				currentValue += fileString[i];
				localIndex++;
			}
		}
		numList[globalIndex] = currentValue;
		for (int i = 0; i < arrSize; i++)
		{
			cout << numList[i] << endl;
		}
	}
	//for (int i = 0; i < fileString.length(); i++) //iterate until i = End Of File
	//{
	//	fileString[i] = '0';
	//}
	file.close();
}
Entity * ReadEntity()
{
	fstream file;
	file.open("monsters.txt", ios::in);
	if (!file.is_open()) 
	{ 
		return NULL;
	}

	size_t capacity = 1;
	size_t size = 0;
	Entity * ents = new Entity[capacity];
	
	string line;
	while (getline(file, line))
	{
		if (line.length() == 0 || line[0] != '@')
		{
			continue;
		}

		Entity temp;
		//for (int i = 0; i < line.length(); i++)
		//{
		//	temp.name[i] = line[i];
		//}

		temp.name = line;

		getline(file, line);
		temp.hitpoints = stof(line);

		getline(file, line);
		temp.armor = stof(line);

		getline(file, line);
		temp.strength = stoi(line);

		getline(file, line);
		temp.defense = stoi(line);

		getline(file, line);
		temp.agility = stoi(line);

		getline(file, line);
		temp.luck = stoi(line);

		if (size < capacity)
		{
			std::cout << "enter\n";
			ents[size] = temp;
			size++;
		}
		else
		{
			std::cout << "resize\n";
			Entity * newEnts = new Entity[capacity + 1];
			for (int i = 0; i < capacity; ++i)
			{
				newEnts[i].name = ents[i].name;
				newEnts[i].hitpoints = ents[i].hitpoints;
				newEnts[i].armor = ents[i].armor;
				newEnts[i].strength = ents[i].strength;
				newEnts[i].defense = ents[i].defense;
				newEnts[i].agility = ents[i].agility;
				newEnts[i].luck = ents[i].luck;
			}

			//memcpy(newEnts, ents, sizeof(Entity)*capacity);
			delete[] ents;
			capacity += 1;
			
			ents = newEnts;
			ents[size] = temp;
			size++;
		}
	}
	return ents;
}
#include<iostream>
#include<array>
#include<time.h>
#include<Windows.h>
using namespace std;

void InitArr(int * arr, int size, int defaultVal)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = defaultVal;
	}
}

void printInt(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << ", ";
	}
	cout << endl;
}

int * zeroArray(int size)
{
	int * myArray = new int[size] {0};
	//for (int i = 0; i < size; i++)
	//{
	//	*(myArray+i) = 0;
	//}
	return myArray;
}

int * duplicateArray(int * arr, int size)
{
	int * newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	return newArray;
}

void ILoveNumbers()
{
	int size;
	cout << "How many numbers do you have?" << endl;
	cin >> size;
	int * myArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "What is number " << (i+1) << "? ";
		cin >> myArray[i];
	}
	cout << "Cool! Your numbers are ";
	printInt(myArray, size);
	delete[] myArray;
}

struct Player
{
	int ATK;
	int DEF;
	int EXP;
	Item * inventory = new Item[0];
};

void RandomPlayerGen()
{
	int userInput;
	cout << "How many players are there?" << endl;
	cin >> userInput;
	Player * party = new Player[userInput];
	srand(time(0));
	for (int i = 0; i < userInput; i++)
	{
		party[i].ATK = rand() % 100;
		party[i].DEF = rand() % 100;
		party[i].EXP = rand() % 100;
		cout << "Player " << (i+1) << ": " << endl;
		cout << "ATK: " << party[i].ATK << endl;
		cout << "DEF: " << party[i].DEF << endl;
		cout << "EXP: " << party[i].EXP << endl;
	}
}

struct Item
{
	int id;
	int gold;
};

bool addItem(Player * recipient, Item gift)
{

}
bool hasItem(Player * holder, int itemID)
{

}
float totalValue(Player * holder)
{
	
}

int main()
{
	//create a single object on the heap
	int * age = new int(0);
	//create an array object on the heap
	int * ages = new int[10];

	delete age;
	delete[] ages;
	//pass a heap instantiated object to a function
	int * newArray = zeroArray(50);
	printInt(newArray, 50);
	delete newArray;
	int * copyArray = new int[5] {1, 2, 3, 4, 5};
	printInt(copyArray, 5);
	printInt(duplicateArray(copyArray, 5), 5);
	ILoveNumbers();

	delete[] copyArray;

	RandomPlayerGen();

	system("pause");
}
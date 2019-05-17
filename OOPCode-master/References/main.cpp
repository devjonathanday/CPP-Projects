#include<iostream>
#include "Functions.h"

using namespace std;

int main()
{
	/*
	int myVal = 0;
	int &myRef = myVal;

	cout << myVal << endl;
	cout << myRef << endl;

	myRef = 4; //Setting a reference changes the variable it's referring to as well.
	//myVal = 3;

	cout << myVal << endl;
	cout << myRef << endl;
	
	
	int a = 1;
	int b = 2;
	int c = 0;

	cout << intSum(a, b, c) << endl;
	

	// variables
	int num = 0;
	float dec = 0.0f;
	bool tf = false;
	char letter = 'a';

	// references to said variables
	int& numRef = num;  // a reference to an int
	float& decRef = dec; // a reference to a float
	bool& tfRef = tf; // a reference to a bool
	char& letterRef = letter; // a reference to a char

	float firstNum = 2;
	float secondNum = 4;
	float total = 0;

	product(firstNum, secondNum, total);

	cout << total << endl;
	
	float a = 1;
	float b = 2;

	cout << "Variable A: " << a << endl;
	cout << "Variable B: " << b << endl;

	swap(a, b);

	cout << "Variable A: " << a << endl;
	cout << "Variable B: " << b << endl;
	*/

	Aussiegochi myAussie { 50, 0, 0, 50, false };
	//Aussiegochi& myAussieRef = myAussie;
	cout << "You have a pet Aussie now for some reason." << endl;
	bool okToGo = false;
	while (!okToGo)
	{
		//Aussiegochi& myAussieRef = myAussie;
		system("cls");
		maxAussieStats(myAussie);
		if (!myAussie.dead)
		{
			myAussie.hunger++;
			myAussie.thirst++;
			myAussie.sanity--;
			myAussie.happiness--;
			cout << "Aussie stats: " << endl;
			cout << "Happiness: " << myAussie.happiness << "%" << endl;
			cout << "Hunger: " << myAussie.hunger << "%" << endl;
			cout << "Thirst: " << myAussie.thirst << "%" << endl;
			cout << "Sanity: " << myAussie.sanity << "%" << endl;
			cout << "[1] Cuddle the aussie\n[2] Feed the aussie\n[3] Water the aussie\n[4] Abuse the aussie\n[5] Do absolutely nothing" << endl;
			int userInput = 0;
			cin >> userInput;
			switch (userInput)
			{
			case 1:
				cout << "You cuddled the aussie! That was nice." << endl;
				cuddleAussie(myAussie);
				break;
			case 2:
				feedAussie(myAussie);
				break;
			case 3:
				waterAussie(myAussie);
				break;
			case 4:
				abuseAussie(myAussie);
				break;
			case 5:
				break;
			default:
				cout << "Invalid input, try again." << endl;
				break;
			}
		}
		else
		{
			okToGo = true;
		}
	}
	system("pause");
	return 0;
}

int intSum(int a, int b, int& c)
{
	c = a + b;
	return c;
}
void product(float a, float b, float& result)
{
	result = a * b;
}
void swap(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}

void cuddleAussie(Aussiegochi& aus)
{
	aus.happiness += 10;
	aus.sanity += 5;
}
void feedAussie(Aussiegochi& aus)
{
	aus.hunger -= 5;
	aus.sanity += 3;
}
void waterAussie(Aussiegochi& aus)
{
	aus.thirst -= 5;
	aus.sanity += 2;
}
void abuseAussie(Aussiegochi& aus)
{
	aus.sanity -= 5;
	aus.happiness -= 10;
}
void maxAussieStats(Aussiegochi& aus)
{
	if (aus.happiness > 100)
	{
		aus.happiness = 100;
	}
	if (aus.sanity > 100)
	{
		aus.sanity = 100;
	}
	if (aus.hunger <= 0)
	{
		aus.hunger = 0;
	}
	if (aus.thirst <= 0)
	{
		aus.thirst = 0;
	}
	if (aus.hunger >= 100)
	{
		cout << "Your aussie died of hunger." << endl;
		aus.dead = true;
	}
	else if (aus.thirst >= 100)
	{
		cout << "Your aussie died of thirst." << endl;
		aus.dead = true;
	}
	else if (aus.happiness <= 0)
	{
		cout << "Your aussie was so sad that it committed suicide." << endl;
		aus.dead = true;
	}
	else if (aus.sanity <= 0)
	{
		cout << "Your aussie went insane and ran away. And died." << endl;
		aus.dead = true;
	}
}
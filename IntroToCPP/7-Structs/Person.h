#pragma once

using std::cout;
using std::cin;
using std::endl;

struct Person
{	//Age of the person in years.
	int age;
	//Pocket change the person has.
	float cash; 
	//Reward points at the local deli.
	int points; 
};

void printPerson(Person target)
{
	cout << "Age: " << target.age << endl;
	cout << "Cash: " << target.cash << endl;
	cout << "Points: " << target.points << endl;
}
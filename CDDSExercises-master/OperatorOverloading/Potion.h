#pragma once
#include<iostream>
#include<string>

using std::string;

class Potion
{
public:
	string name;
	int HPModifier;
	int quality;
	int useByDate;

	Potion();
	Potion(string _name, int _HPModifier, int _quality, int _useByDate);
	~Potion();
};
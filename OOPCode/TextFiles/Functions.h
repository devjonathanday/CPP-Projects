#pragma once

#include<iostream>
#include<fstream>

using namespace std;

int randomNumber(int maxRange, int minRange);
void ReadFile(fstream &file);
void SaveFile(fstream &file);
void CorruptFile(fstream &file);
void SeparateFileByCommas(fstream &file, string numList[], size_t arrSize);

struct Entity
{
	//char * name = new char[100]();
	string name;
	float hitpoints;
	float armor;

	int strength;
	int defense;
	int agility;
	int luck;
};

Entity * ReadEntity();
#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct dataSaved
{
	string playerName;
	int deathCount;
	int deepestFloor;
	bool hasBeatenGame;
	double timePlayed;  // given in seconds
};

void HelloWorld(string fileName);
void SaveData(dataSaved data, string fileName);
dataSaved LoadData(string fileName);
void MonsterQuest();
#pragma once
#pragma once
#include <iostream>

using namespace std;

class HighScoreEntry
{
public:
	std::string name;
	int score;
	int level;

	HighScoreEntry();
	HighScoreEntry(string _name, int _score, int _level);
	~HighScoreEntry();
	bool operator>(HighScoreEntry& entry);
	bool operator<(HighScoreEntry& entry);
	bool operator>=(HighScoreEntry& entry);
	bool operator<=(HighScoreEntry& entry);
	void operator=(HighScoreEntry * entry);
};
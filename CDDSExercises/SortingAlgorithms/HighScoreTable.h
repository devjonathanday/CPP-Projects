#pragma once
#include "HighScoreEntry.h"
#include <vector>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;

	void bubbleSortByScore(bool ascending);
	void modBubbleSortByScore();
	void insertionSortByScore();
	vector<HighScoreEntry> topNNScores(int topRows);
	void printScores(vector<HighScoreEntry> scores);
	bool pruneBottomNNScores(int bottomRows);
	HighScoreEntry operator[](const int index);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
	vector<string> split(std::string& line);
};
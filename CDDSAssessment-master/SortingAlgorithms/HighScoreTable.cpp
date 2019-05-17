#include"HighScoreTable.h"
#include"HighScoreEntry.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

HighScoreTable::HighScoreTable() {}
HighScoreTable::~HighScoreTable()
{
	//delete hsVector;
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	std::fstream file;
	file.open(fileName, ios::in);

	HighScoreEntry * temp = new HighScoreEntry();
	string information;
	while (getline(file, information))
	{
		vector<string> tableEntry = split(information);
		(*temp).level = stoi(tableEntry[tableEntry.size() - 1]);
		tableEntry.pop_back();
		(*temp).score = stoi(tableEntry[tableEntry.size() - 1]);
		tableEntry.pop_back();
		(*temp).name = tableEntry[tableEntry.size() - 1];
		hsVector.push_back(*temp);
	}
	delete temp;
	file.flush();
	file.close();
}

vector<std::string> HighScoreTable::split(std::string& line)
{
	vector<string> result;
	stringstream lineStream(line);
	string cell;
	while (getline(lineStream, cell, ','))
		result.push_back(cell);
	if (!lineStream && cell.empty())
		result.push_back("");
	return result;
}

void HighScoreTable::bubbleSortByScore(bool ascending)
{
	for (int i = 0; i < hsVector.size(); i++)
	{
		for (size_t j = hsVector.size() - 1; j > 0; j--)
		{
			if ((hsVector[j].score < hsVector[j - 1].score && ascending)
				|| (hsVector[j].score > hsVector[j - 1].score && !ascending))
			{
				auto temp = hsVector[j];
				hsVector[j] = hsVector[j - 1];
				hsVector[j - 1] = temp;
			}
		}
	}
}

void HighScoreTable::insertionSortByScore()
{
	for (int i = 1; i < hsVector.size(); i++)
	{
		int m = i;
		while (hsVector[m].score < hsVector[m - 1].score)
		{
			//SWAP
			{
				auto temp = hsVector[m];
				hsVector[m] = hsVector[m - 1];
				hsVector[m - 1] = temp;
			}
			if (m > 1)
				m--;
			else
				break;
		}
	}
}
vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	bubbleSortByScore(false); //TODO sort by descending, then grab the first topRows elements
	vector<HighScoreEntry> newTable;
	for (auto i = hsVector.size() - 1; i > hsVector.size() - topRows - 1; i--)
	{
		newTable.push_back(hsVector[i]);
	}
	return newTable;
}
void HighScoreTable::printScores(vector<HighScoreEntry> scores)
{
	HighScoreTable table;
	table.hsVector = scores;
	//table.bubbleSortByScore(true);
	for (auto i = 0; i < table.hsVector.size(); i++)
	{
		cout << table.hsVector[i].score << endl;
	}
	//cout << endl;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	for (int i = 0; i < bottomRows; i++)
	{
		if (hsVector.size() == 0)
		{
			return false;
		}
		hsVector.pop_back();
	}
	return true;
}

HighScoreEntry  HighScoreTable::operator[](const int index)
{
	return hsVector[index];
}
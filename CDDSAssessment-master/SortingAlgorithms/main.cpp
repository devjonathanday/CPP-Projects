#include "HighScoreTable.h"
#include"Algorithms.h"
#include <vector>

int main()
{
	//Loading up 3 copies of the file, each will be sorted using a different method.
	HighScoreTable hst1("highscores.txt");
	HighScoreTable hst2("highscores.txt");
	HighScoreTable hst3("highscores.txt");

	//Initialization
	cout << "First table:" << endl;
	hst1.printScores(hst1.hsVector);
	cout << "Second table:" << endl;
	hst2.printScores(hst2.hsVector);
	cout << "Third table:" << endl;
	hst3.printScores(hst3.hsVector);

	//Sorting
	hst1.bubbleSortByScore(true);
	hst2.insertionSortByScore();
	MergeSort(&hst3.hsVector, 0, hst3.hsVector.size() - 1);

	//Results
	cout << endl;
	cout << "First table:" << endl;
	hst1.printScores(hst1.hsVector);
	cout << "Second table:" << endl;
	hst2.printScores(hst2.hsVector);
	cout << "Third table:" << endl;
	hst3.printScores(hst3.hsVector);

	system("pause");

	return 0;
}
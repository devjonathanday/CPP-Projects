#include "HighScoreTable.h"
#include <vector>
#include"MergeSort.h"

int main()
{
	HighScoreTable hst("highscores.txt");
	MergeSort(&hst.hsVector, 0, hst.hsVector.size() - 1);
	//vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//hst.printScores(topScores);
	//hst.pruneBottomNNScores(3);

	//int arr[] = { 1, 8, 4, 3, 6, 5, 7, 2 };
	//MergeSort(arr, 0, 7);

	return 0;
}
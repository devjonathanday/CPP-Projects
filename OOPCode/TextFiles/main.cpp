#include<iostream>
#include<fstream>
#include<string>
#include"Functions.h"
#include<time.h>

using namespace std;

int main()
{
	fstream file;
	srand(time(NULL));

	//ReadFile(file);
	//SaveFile(file);
	//CorruptFile(file);

	//string numList[5];
	//SeparateFileByCommas(file, numList, 5);

	Entity * ents = ReadEntity();

	delete[] ents;
	system("pause");
	return 0;
}
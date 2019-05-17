#include<iostream>
#include<string.h>
#include"Functions.h"

using namespace std;

char * appendString(char * inputString, char * endString, int totalSize)
{
	char * newString = new char[200]();
	for (int i = 0; i < strlen(inputString); i++)
	{
		newString[i] = inputString[i];
	}
	for (int i = 0; i < strlen(endString); i++)
	{
		newString[i + strlen(inputString)] = endString[i];
	}
	return newString;
}
char * insertString(char * inputString, char * endString, int totalSize, int insertPosition)
{
	char * newString = new char[totalSize]();
	for (int i = 0; i < insertPosition; i++)
	{
		newString[i] = inputString[i];
	}
	for (int i = 0; i < strlen(endString); i++)
	{
		newString[i + insertPosition] = endString[i];
	}
	for (int i = 0; i < strlen(inputString) - insertPosition; i++)
	{
		newString[i + insertPosition + strlen(endString)] = inputString[i + insertPosition];
	}
	return newString;
}
int wordCount(char * inputString)
{
	bool countingWord = false;
	int count = 0;
	for (int i = 0; i < strlen(inputString); i++)
	{
		if ((inputString[i] >= 65 && inputString[i] <= 90) || (inputString[i] >= 97 && inputString[i] <= 122)) //Is [i] a letter?
		{
			if (!countingWord)
			{
				countingWord = true;
				count++;
			}
		}
		else
		{
			countingWord = false;
		}
	}
	return count;
}
void wordWrap(char * inputString, int lineLength)
{
	for (int i = 0; i < (strlen(inputString)); i++)
	{
		if (i % lineLength == 0)
		{
			for (int j = i; ; j--)
			{
				if (inputString[j] == 32)
				{
					inputString[j] = '\n';
					break;
				}
			}
		}
	}
	cout << inputString << endl;
}
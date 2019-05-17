#pragma once
#include<iostream>
#include<string.h>

using namespace std;

struct Contact
{
	string name;
	string phoneNumber;
	string address;
};

char * appendString(char * inputString, char * endString, int totalSize);
char * insertString(char * inputString, char * endString, int totalSize, int insertPosition);
int wordCount(char * inputString);
void wordWrap(char * inputString, int lineLength);
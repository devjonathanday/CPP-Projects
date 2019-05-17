#pragma once

using namespace std;

char * ToUpper(char * myString);
char * RemoveWhiteSpace(char * myString);
char * GetSubString(char * myString, int start, int end);
bool PalindromeTest(char * myString);
char * ReverseString(char * myString);
int stringLength(char * myString);
char * trimString(char * myString);
char * shiftCipher(char * myString, int shift, bool encode);
#include<iostream>
#include "Functions.h"
using namespace std;



int main()
{
	//Practice stuff
	int coffeeCup = 0;
	int * pointer = &coffeeCup;
	cout << coffeeCup << endl;
	cout << pointer << endl;
	cout << *pointer << endl;

	coffeeCup++;

	int numbers[] = { 0, 5, 7, 9, 99, 99 };

	float floatArray[] = { 1, 2, 3, 4, 5 };
	int intArray[] = { 1, 2, 3, 4, 5 };
	bool boolArray[] = { true, false, true, false, false };

	printFloats(floatArray, 5);
	//cout << arraySum(intArray, 5) << endl;
	//initBools(boolArray, 5, true);

	int start;
	int end;

	cout << "Using the array from above, which values do you want to copy to a new array?" << endl;
	cout << "Starting index: ";
	cin >> start;
	cout << "Ending index: ";
	cin >> end;

	copyArraySubset(intArray, 5, start, end);

	char searchQuery;

	char charArray[]{ 'a', 'b', 'c', 'd', 'e' };
	cout << "{ a, b, c, d, e }" << endl;
	cout << "Given the above array, what letter do you want to look for?" << endl;
	cin >> searchQuery;
	cout << "The memory location of that value: " << (int)getPointerToElement(charArray, 5, searchQuery) << endl;

	int valA = 2;
	int valB = 4;

	int * ptrA = &valA;
	int * ptrB = &valB;

	

	std::cout << valA << std::endl; // should be 2
	std::cout << valB << std::endl; // should be 4

	swapPointers(ptrA, ptrB);

	std::cout << valA << std::endl; // should be 2
	std::cout << valB << std::endl; // should be 4

	std::cout << *ptrA << std::endl; // should be 4
	std::cout << *ptrB << std::endl; // should be 2

	system("pause");

	return 0;
}

void printFloats(float * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << endl;
	}
}
int arraySum(int * arr, int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += *(arr + i);
	}
	return total;
}
void initBools(bool * arr, int size, bool defaultValue)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = defaultValue;
		if (*(arr + i))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
}
void copyArraySubset(int * arr, int size, int start, int end)
{
	int newArray[]{0, 0, 0, 0, 0};
	//int * newPointer;
	for (int i = start; i < end+1; i++)
	{
		*(newArray + i) = *(arr + i);
		cout << *(newArray + i) << endl;
	}
}

char * getPointerToElement(char * arr, int size, char search)
{
	char * myPointer = 0;
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == search)
		{
			myPointer = arr+i;
			found = true;
		}
	}
	if (!found)
	{
		myPointer = nullptr;
	}
	return myPointer;
}

void swapPointers(int *& num1, int *& num2)
{
	int * temp = num1;
	num1 = num2;
	num2 = temp;
}
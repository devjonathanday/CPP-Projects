#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//void initializeToTwo(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = 2;
//	}
//}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size  - 1; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << ".";
	cout << endl;
}

int sumArray(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int smallestNumber(int arr[], int size)
{
	int smallNum = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (smallNum > arr[i])
		{
			smallNum = arr[i];
		}
	}
	return smallNum;
}

int largestNumber(int arr[], int size)
{
	int bigNum = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (bigNum < arr[i])
		{
			bigNum = arr[i];
		}
	}
	return bigNum;
}

int findNumber(int arr[], int size, int value)
{
	int foundNum = -1;
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		{
			foundNum = i;
		}
	}
	return foundNum;
}

int countNumbers(int arr[], int size, int value)
{
	int foundNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		{
			foundNum++;
		}
	}
	return foundNum;
}
void numberUnique(int arr[], int size, int value)
{
	int foundNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		{
			foundNum++;
		}
	}
	switch (foundNum)
	{
	case 0:
		cout << "Not Found" << endl;
		break;
	case 1:
		cout << "Unique" << endl;
		break;
	case 2:
	default:
		cout << "Not Unique" << endl;
		break;
	}
}

void reverseArray(int arr[], int size)
{
	/*
	int reverseNumbers[sizeof(arr) / sizeof(int)];
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		reversedNumbers[i] = arr[sizeof(arr) / sizeof(int) - i];
	}
	*/

	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - 1 - i] = temp;
	}

	printArray(arr, size);
}

void sortAscending(int arr[], int size)
{
	bool changed = true;
	while (changed)
	{
		changed = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				changed = true;
			}
		}
	}

	//for (int i = 0; i < size; i++)
	//{
	//	int smallest = findNumber(arr, size, smallestNumber(arr, size));
	//	if (arr[i] > arr[smallest])
	//	{
	//		int temp = arr[i];
	//		arr[i] = arr[smallest];
	//		arr[smallest] = temp;
	//	}
	//}

	printArray(arr, size);
}

int main()
{
	//int numbers[]{ 16, 124, 263, 643, 65};
	int numbers[]{ 1, 8, 4, 3, 6, 5, 7, 2, 9 };
	printArray(numbers, 9);
	//cout << sumArray(numbers, 4) << endl;
	//cout << smallestNumber(numbers, 5) << endl;
	//cout << largestNumber(numbers, 5) << endl;.
	//cout << largestNumber(numbers, 5) << endl;
	//cout << findNumber(numbers, 5, 263) << endl;
	//cout << countNumbers(numbers, 10, 4) << endl;
	//numberUnique(numbers, 10, 1);
	//reverseArray(numbers, 9);
	sortAscending(numbers, 9);
	system("pause");
	return 0;
}
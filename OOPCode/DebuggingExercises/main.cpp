#include<iostream>
#include<random>
#include<string>
#include<time.h>

using namespace std;
bool containsValue(int value, int * arr, int arrSize);

int main()
{
	//Program 1

	std::cout << "Provide two numbers and you will be given the sum." << std::endl;

	int numA = -1;
	int numB = -1;
	std::cin >> numA >> numB;

	std::cout << "The sum of the two numbers is " << (numA + numB) << "." << std::endl;

	//Problems with program 1:
	//This program has 1 compile error.
	//The problem with program 1 is a missing quotation mark on line 15.
	//The program doesn't know how to treat that line because it doesn't know where the end of the string (the null terminator) is.
	//The solution would simply be to insert the quotation mark at the end of the string.

	//Program 2

	std::cout << "-=xXx FOUR FUNCTION CALCULATOR PUNCH xXx=-" << std::endl;

	std::cout << "What are your two numbers?" << std::endl;

	double numC = -1.0;
	double numD = -1.0;
	double result = -1.0;

	std::cin >> numC >> numD;

	std::cout << "What operation would you like to perform? (+, -, /, *)" << std::endl;

	while (true)
	{
		char operation = ' ';
		std::cin >> operation;

		switch (operation)
		{
		case '+':
			result = numC + numD;
			break;
		case '-':
			result = numC - numD;
			break;
		case '/':
			result = numC / numD;
			break;
		case '*':
			result = numC * numD;
			break;
		default:
			std::cout << "Sorry, that isn't a recognized operation." << std::endl;
			continue;
		}
		break;
	}

	std::cout << "Your final result was " << result << std::endl;

	//Problems with program 2:
	//This program has 1 compile error and 2 semantic errors.
	//Another missing quotation mark on line 52, so the program doesn't know where to end the string.
	//All the cases in the switch statement yields the same result.
	//No break statements in the switch, so the default will always run in addition to the case determined by the 'operation' variable.
	//Not really necessary, but for good design sake the switch should be put inside a while loop so the player can retry their input if it was invalid.

	//Solutions to program 2:
	//A quotation must be put at the end of "Your final result was" to properly run std::cout.
	//The operator on each equation must be changed to match the program's intended functionality.
	//A break must be added at the end of each case in the switch.
	//Encase the switch and the std::cin statement in a while loop, add a continue statement after the default case, then add a break after the switch to exit the while loop.

	//Program 3

	std::string names[10] =
	{
		"Terry Nguyen",
		"Johnny Collins",
		"Taerrance Tooker",
		"Kristen Uguudesu",
		"Nisha Williera",
		"Davin Jobbson",
		"Michael Pascal",
		"Jamison Cardigan",
		"Charles Hernia",
		"Reggie Grawcannon"
	};

	srand(time(NULL));
	size_t index = rand() % 10;

	std::cout << "Your random name is " << names[index] << std::endl;

	//Problems with program 3:
	//This program has 1 semantic error.
	//The random number generated has no seed, therefore will always return the same number.

	//Solutions to program 3:
	//Get a random seed for the number generator by using srand(), then set the parameter to time(NULL) to find a pseudo-random number based on time.
	//Additionally, the <time.h> header must be included outside int main() to properly randomize the seed.

	//Program 4

	int nums[] = { 0, 5, 7, 1, 2, 3 };

	std::cout << "The value was " << (containsValue(7, nums, 6) ? "found" : "not found") << "!" << std::endl;

	//Problems with program 4:
	//This program has 1 compile error.
	//The program does not know how to print 'result ? "found" : "not found"' because the colon operator is applied to cout.

	//Solutions to program 4:
	//Add parentheses around the ternary operation so it completes the string before cout reads it.

	system("pause");

	return 0;
}

bool containsValue(int value, int * arr, int arrSize)
{
	for (int i = 0; i < arrSize; i)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}
#include<iostream>

void printXY(int x, int y);
void promptLargest(int qtyRequested);
void promptSmallest(int qtyRequested);
void EvenOrOdd(int x, int y);
void FizzBuzz(int x, int y);
void gridGen(int width, int height);
int main()
{
	//std::cout <<  << std::endl;
	/*
	//From 1 to 100, 100 to 1, 1995 to 2017
	{
		for (int i = 1; i <= 100; i++)
		{
			std::cout << i << std::endl;
		}
		system("pause");
		for (int i = 100; i >= 1; i--)
		{
			std::cout << i << std::endl;
		}
		system("pause");
		for (int i = 1995; i <= 2017; i++)
		{
			std::cout << i << std::endl;
		}
		system("pause");
	}

	//Three favorite numbers
	{
		int num1;
		int num2;
		int num3;
		std::cout << "What are your three favorite numbers?" << std::endl;
		std::cout << "What's the first number?" << std::endl;
		std::cin >> num1;
		std::cout << "Okay, your first number is " << num1 << ". What's the second number?" << std::endl;
		std::cin >> num2;
		std::cout << "Okay, your numbers are " << num1 << " and " << num2 << ". What's the last number?" << std::endl;
		std::cin >> num3;
		std::cout << "Okay, your favorite numbers are " << num1 << ", " << num2 << ", and " << num3 << "." << std::endl;
		system("pause");
	}

	//PrintXY
	{
		std::cout << "Type a starting and ending number to count between them." << std::endl;
		int x, y;
		std::cin >> x >> y;
		printXY(x, y);
		system("pause");
	}
	//Prompt Largest
	{
		int qty;
		std::cout << "How many numbers do you want to enter?" << std::endl;
		std::cin >> qty;
		promptLargest(qty);
		system("pause");
	}
	//Prompt Smallest
	{
		int qty;
		std::cout << "How many numbers do you want to enter?" << std::endl;
		std::cin >> qty;
		promptSmallest(qty);
		system("pause");
	}
	//Even or Odd 2: Electric Avenue
	{
		std::cout << "Type a starting and ending number to see which are even and odd!" << std::endl;
		int x, y;
		std::cin >> x >> y;
		EvenOrOdd(x, y);
		system("pause");
	}
	//Fizz Buzz
	{
		std::cout << "Let's Play FIZZ BUZZ!!" << std::endl;
		int x, y;
		std::cout << "First enter an X value!" << std::endl;
		std::cin >> x;
		std::cout << "Now, enter a Y value!" << std::endl;
		std::cin >> y;
		FizzBuzz(x, y);
		system("pause");
	}
	*/
	//Grid Generator
	{
		int w = 0;
		int h = 0;
		std::cout << "Let's make a box!" << std::endl;
		std::cout << "Enter the width of the box." << std::endl;
		std::cin >> w;
		std::cout << "Now, enter the height of the box." << std::endl;
		std::cin >> h;
		gridGen(w, h);
	}


	system("pause");
	return 0;
}
void printXY(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		if (i < y)
		{
			std::cout << i << ", ";
		}
		else
		{
			std::cout << i << "." << std::endl;
		}
	}
}
void promptLargest(int qtyRequested)
{
	int userInput = 0;
	int highestNum = 0;
	for (int i = 0; i < qtyRequested; i++)
	{
		std::cout << "Type a number. ";
		std::cin >> userInput;
		if (highestNum < userInput)
		{
			highestNum = userInput;
		}
	}
	std::cout << "The largest number you typed was " << highestNum << "." << std::endl;
}
void promptSmallest(int qtyRequested)
{
	int userInput = 0;
	int lowestNum = 0;

	std::cout << "Type a number. ";
	std::cin >> userInput;
	lowestNum = userInput;

	for (int i = 0; i < qtyRequested - 1; i++)
	{
		std::cout << "Type a number. ";
		std::cin >> userInput;
		if (lowestNum > userInput)
		{
			lowestNum = userInput;
		}
	}
	std::cout << "The smallest number you typed was " << lowestNum << "." << std::endl;
}
void EvenOrOdd(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		if (i < y)
		{
			if (i % 2 > 0)
			{
				std::cout << "Odd" << ", ";
			}
			else
			{
				std::cout << "Even" << ", ";
			}
		}
		else
		{
			if (i % 2 > 0)
			{
				std::cout << "Odd" << "." << std::endl;
			}
			else
			{
				std::cout << "Even" << "." << std::endl;
			}
		}
	}
}
void FizzBuzz(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		if (i < y)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				std::cout << "FizzBuzz" << ", ";
			}
			else if (i % 3 == 0)
			{
				std::cout << "Fizz" << ", ";
			}
			else if (i % 5 == 0)
			{
				std::cout << "Buzz" << ", ";
			}
			else
			{
				std::cout << i << ", ";
			}
		}
		else
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				std::cout << "FizzBuzz" << "." << std::endl;
			}
			else if (i % 3 == 0)
			{
				std::cout << "Fizz" << "." << std::endl;
			}
			else if (i % 5 == 0)
			{
				std::cout << "Buzz" << "." << std::endl;
			}
			else
			{
				std::cout << i << "." << std::endl;
			}
		}
	}
}
void gridGen(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << "X";
		}
		std::cout << std::endl;
	}
}
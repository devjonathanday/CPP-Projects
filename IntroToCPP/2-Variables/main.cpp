#include<iostream>

int main()
{
	
	//creating and assigning variables
	{
		int weightKg = 68;
		std::cout << weightKg << std::endl;
		weightKg++;
		std::cout << weightKg << std::endl;

		weightKg++;
		std::cout << weightKg << std::endl;
		weightKg++;
		std::cout << weightKg << std::endl;
		weightKg = 60;
		std::cout << weightKg << std::endl;
		weightKg--;
		std::cout << weightKg << std::endl;
	}
	//using arithmetic operators on integer variables
	{
		int num1 = 5;
		int num2 = 10;
		int sum = num1 + num2;

		std::cout << sum << std::endl;
	}
	//using arithmetic operators on floating point variables
	{
		float float1 = 10.3f;
		float float2 = 11.2f;
		float flotsam = float1 + float2;

		std::cout << flotsam << std::endl;
	}
	//storing user input in integer variables
	{
		std::cout << "How much do you weight?" << std::endl;
		int userWeight = 0;
		std::cin >> userWeight;
		std::cout << "You weight " << userWeight << "!" << std::endl;
	}

	//A.) 14
	//B.) 9
	//C.) 21
	//D.) 3
	//E.) 6
	//F.) 6.5

	//my final form
	{
		int numberA = 5;

		numberA = 9;
		numberA = 11;
		numberA = 14;

		std::cout << "A) " << numberA << std::endl;

		int numberB = 10;
		numberB = 9;

		int thingB = 55;
		thingB = 22;

		std::cout << "B) " << numberB << std::endl;

		int numberC = 3;
		numberC = 7;
		numberC = 1;

		int somethingC = 23;
		somethingC = 21;

		numberC = somethingC;

		std::cout << "C) " << numberC << std::endl;

		int numberD = 1;
		int somethingD = 3;

		numberD = somethingD;

		std::cout << "D) " << somethingD << std::endl;

		int x = 13;

		x = x / 2;

		std::cout << "E) " << x << std::endl;

		float y = 13;

		y = y / 2;

		std::cout << "F)" << y << std::endl;

	}

	//Celsius to Fahrenheit
	{
		float degCelsius = 0.1f;
		float degFahrenheit = 0.1f;
		
		std::cout << "Type a number in Celsuis to convert it to Fahrenheit:" << std::endl;
		std::cin >> degCelsius;

		degFahrenheit = ((degCelsius * 1.8) + 32);

		std::cout << "Celsius:    " << degCelsius << std::endl;
		std::cout << "Fahrenheit: " << degFahrenheit << std::endl;
	}

	//Area of a rectangle
	{
		float rectWidth = 0.0f;
		float rectHeight = 0.0f;
		float rectArea = 0.0f;

		std::cout << "Type the width and height of a rectangle to calculate its area!" << std::endl;
		std::cout << "Width:" << std::endl;
		std::cin >> rectWidth;
		std::cout << "Height:" << std::endl;
		std::cin >> rectHeight;

		rectArea = (rectWidth * rectHeight);

		std::cout << "Area of a Rectangle)" << std::endl;
		std::cout << "H: " << rectHeight << ", W: " << rectWidth << std::endl;
		std::cout << "Area: " << rectArea << std::endl;
	}

	//Average of five
	{
		float a, b, c, d, e;
		float avg;
		avg = a = b = c = d = e = 0.0f;

		std::cout << "Type five numbers to find the average of them!" << std::endl;
		
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		std::cin >> d;
		std::cin >> e;

		avg = (a + b + c + d + e) / 5;

		std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
		std::cout << "Average: " << avg << std::endl;
	}

	//Number Swap
	{
		int x = 0;
		int y = 0;
		int newX = 0;
		int newY = 0;

		std::cout << "Type two numbers to swap them around!" << std::endl;

		std::cout << "X:" << std::endl;
		std::cin >> x;
		std::cout << "Y:" << std::endl;
		std::cin >> y;

		newX = y;
		newY = x;

		std::cout << "The numbers after being swapped:" << std::endl;
		std::cout << "x is " << x << std::endl;
		std::cout << "y is " << y << std::endl;
	}
	
	//Fun Facts for your age
	{
		int power = 0;
		std::cout << "How much horsepower does your car have?" << std::endl;
		std::cin >> power;
		std::cout << "That's " << (power * 2849) << " duckpower" << std::endl;
	}

	//camelCase to lower_snake_case
	{
		int age;
		int bullet_count;
		float dog_years;
		int qty;
		float shield_value;
		float defense_matrix_cooldown;
		int red_armor_value;
		float red_armor_ratio;
		int happiness;
		int gandhi_aggression = 0;
	}

	// The Right Tool for the Job
	{
		int num;        // integer
		float num2;     // single precision floating point
		double num3;	// double precision floating point
		bool num4;		//boolean value, true or false only
		enum myEnum {item1, item2, item3}; //enumerated list, acts as a collection of variables, like a numbered array.
	}
	//Number swap 2: return of swapper
	{
		std::cout << "Type two numbers to have them swapped! Again." << std::endl;
		int x = 0;
		int y = 0;

		std::cout << "X: " << std::endl;
		std::cin >> x;
		std::cout << "Y: " << std::endl;
		std::cin >> y;

		x = x + y;
		y = x - y;
		x = x - y;

		std::cout << "The numbers after being swapped:" << std::endl;
		std::cout << "x is " << x << std::endl;
		std::cout << "y is " << y << std::endl;
	}
	//Handling errors
	{
		int myNumber;
		bool okToGo = false;
		for (; okToGo != true;)
		{
			std::cout << "Give me a number to use!" << std::endl;

			std::cin >> myNumber;

			if (myNumber == NULL)
			{
				std::cout << "That's not a number! Try again!" << std::endl;
			}
			else
			{
				std::cout << "Thanks! You gave me the number " << myNumber << std::endl;
				okToGo = true;
			}
			
		}
	}
	system("pause");

	return 0;
}
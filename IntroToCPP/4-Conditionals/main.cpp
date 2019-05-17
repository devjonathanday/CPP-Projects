#include<iostream>;

using std::cout;
using std::cin;
using std::endl;

int main()
{   /*
	//Evaluating the truth table
	{
		//1.) true
		//2.) true
		//3.) true
		//4.) false
		//5.) false
		//6.) true
		//7.) true


	}

	//Evaluate the following (A and B)
	{
		// A) 30
		int numberA = 15;
		if (numberA > 10)
		{
			numberA = numberA * 2;
		}
		cout << "A) " << numberA << endl;

		// B) 15
		int numberB = 15;
		if (numberB < 15)
		{
			numberB = numberB * 3;
		}

		std::cout << "B) " << numberB << std::endl;
	}

	//Number judging
	{
		int userInput = 0;
		bool retry = true;
		cout << "Give me a number from 1 to 100, and I will judge it harshly." << endl;
		while (retry)
		{
			cin >> userInput;
			if (userInput >= 1 && userInput <= 100)
			{
				retry = false;
				if (userInput > 50)
				{
					cout << userInput << "? That sure is a large number." << endl;
				}
				else if (userInput < 50)
				{
					cout << userInput << " is a really small number." << endl;
				}
				else if (userInput = 50)
				{
					cout << userInput << " is a perfectly balanced number." << endl;
				}
			}
			else
			{
				cout << "That's not from 1 to 100! Try again!" << endl;
			}
		}
	}

	//Age Gate
	{
		int userInput = 0;
		bool retry = true;
		cout << "Before I let you into this spooky nightclub, what is your age?" << endl;
		while (retry)
		{
			cin >> userInput;
			if (userInput > 0)
			{
				retry = false;
				if (userInput < 18)
				{
					cout << "You're only " << userInput << " years old? You're a minor, not getting in today." << endl;
				}
				if (userInput >= 18 && userInput < 50)
				{
					cout << "Fantastic, you're " << userInput << " years old. You're an adult!" << endl;
				}
				if (userInput >= 50 && userInput < 65)
				{
					cout << "You're " << userInput << " years old. You're eligible to join AARP." << endl;
				}
				if (userInput >= 65)
				{
					cout << "Oh, you're " << userInput << " years old. I think you're eligible for retirement benefits!" << endl;
				}
			}
			else
			{
				cout << "You're a liar! What is your real age?" << endl;
			}
		}
	}

	//The Smallest Of 3 Numbers
	{
		int userInput;
		int lowestNum;
		cout << "Give me 3 numbers." << endl;
		cout << "What's the first number? ";
		cin >> userInput;
		lowestNum = userInput;
		cout << "What's the second number? ";
		cin >> userInput;
		if (userInput < lowestNum)
		{
			lowestNum = userInput;
		}
		cout << "What's the third number? ";
		cin >> userInput;
		if (userInput < lowestNum)
		{
			lowestNum = userInput;
		}
		cout << "The lowest number you typed was " << lowestNum << "." << endl;
	}

	//Even Or Odd
	{
		int userInput;
		int lowestNum;
		cout << "Give me a number. ";
		cin >> userInput;
		if (userInput % 2 == 0)
		{
			cout << userInput << " is an even number!" << endl;
		}
		else
		{
			cout << userInput << " is an odd number!" << endl;
		}
	}

	*/
	//Clamp the number
	{
		int userInput;
		cout << "Give me a number. Minimum: 15, Maximum: 30" << endl;
		cin >> userInput;
		if (userInput < 15)
		{
			userInput = 15;
		}
		else if (userInput > 30)
		{
			userInput = 30;
		}
		cout << "You chose " << userInput << "." << endl;
		//Spiciniess
		{
			// Field: Thai Spiciness Rating
			// Constraints: Any number from 0 to 5, inclusive of both ends.

			int thaiSpiceRating = 0;

			std::cout << "How spicy should your food be?\n";
			std::cin >> thaiSpiceRating;

			if (thaiSpiceRating > 5)
			{
				thaiSpiceRating = 5;
			}
			else if (thaiSpiceRating < 0)
			{
				thaiSpiceRating = 0;
			}
			std::cout << "You ordered with a spiciness rating of " << thaiSpiceRating << "!\n";
		}
		//Cookies
		{
			// Field:       Purchase Order for Cookies
			// Constraints: Must be ordered in multiples of 23. Only whole numbers.
			//              Round down to the nearest multiple if not a multiple of 23.

			int cookies = 0;

			std::cout << "How many cookies do you want to order? Only available in 23-packs." << endl;
			std::cin >> cookies;

			if (cookies % 23 != 0)
			{
				cookies -= cookies % 23;
			}

			if (cookies <= 0)
			{
				cout << "You don't want any cookies? That's alright!" << endl;
			}
			else if (cookies > 0 && cookies < 100)
			{
				cout << "Cool! That'll be " << cookies << " cookies!" << endl;
			}
			else
			{
				cout << "Wow! " << cookies << " is a lot of cookies!" << endl;
			}
		}
		//Sketchbooks
		{
			// Field:       Purchase Order for Sketchbooks (3pk)
			// Constraints: Must order at least 9 sketchbooks total.
			//              The total may not exceed 30 sketchbooks ordered.

			bool retry = true;
			int sBooks = 0;

			std::cout << "How many sketchbook packs do you want to order? 3 packs, only accepting orders between 3 and 10 packs." << endl;

			while (retry)
			{
				std::cin >> sBooks;

				if (sBooks < 3)
				{
					cout << "That's not enough sketchbooks! Try again." << endl;
				}
				else if (sBooks > 10)
				{
					cout << "That's too many sketchbooks! Try again." << endl;
				}
				else
				{
					cout << "Cool! You ordered " << sBooks << " packs, which adds up to " << sBooks * 3 << " books." << endl;
					retry = false;
				}
			}
		}
		//Motion blur
		{
			// Field:       Enable Motion Blur
			// Constraints: Must be a 'y' or 'n' value.
			char userInput = 'x';
			cout << "Do you want to enable Motion Blur? Type [y] or [n]." << endl;
			bool retry = true;
			while (retry)
			{
				cin >> userInput;
				if (userInput != 'y' && userInput != 'n')
				{
					cout << "Please enter a valid response." << endl;
				}
				if (userInput == 'y')
				{
					cout << "Motion blur activated." << endl;
					retry = false;
				}
				if (userInput == 'n')
				{
					cout << "Motion blur deactivated." << endl;
					retry = false;
				}
			}
		}


		//Four Function Disposable Calculator
		{
			bool retry = true;

			int userInput = 0;

			int x = 0;
			int y = 0;
			while (retry)
			{
				cout << "Enter two numbers to be used in the calculation.\nWhat's the first number?" << endl;
				cin >> x;
				cout << "What's the second number?" << endl;
				cin >> y;
				cout << "What do you want to do with the numbers?\n1.)Add\n2.)Subtract\n3.)Multiply\n4.)Divide" << endl;
				cin >> userInput;

				if (userInput == 1)
				{
					retry = false;
					cout << x << " + " << y << " = " << x + y << endl;
				}
				else if (userInput == 2)
				{
					retry = false;
					cout << x << " - " << y << " = " << x - y << endl;
				}
				else if (userInput == 3)
				{
					retry = false;
					cout << x << " * " << y << " = " << x * y << endl;
				}
				else if (userInput == 4)
				{
					if (y != 0)
					{
						retry = false;
						cout << x << " / " << y << " = " << x / y << endl;
					}
					else
					{
						cout << "Cannot divide by 0. Pick a different operator." << endl;
					}
				}
				else
				{
					cout << "Invalid input, try again." << endl;
				}
			}
			system("pause");
		}

		//A Battle Of Prehistoric Proportions
		{
			int userInput = 0;
			int playerPoints = 0;
			int enemyPoints = 0;

			//Dino Stats
			int enemyStrength = 0;
			int enemyWeapon = 0;
			int enemyBattles = 0;
			bool enemySleep = 0;
			int enemyVitaminC = 0;

			bool retry = true;

			//1 = Rock
			//2 = Paper
			//3 = Scissors

			system("cls");

			enemyStrength = rand() % 10 + 1;
			enemyWeapon = rand() % 3 + 1;
			enemyBattles = rand() % 100;
			enemySleep = rand() % 2;
			enemyVitaminC = rand() % 150 + 1;

			cout << "A dino appears!" << endl;
			cout << "Answer these questions to prove your might!" << endl;

			cout << "1. How would you rate your strength on a scale of 1 to 10?" << endl;
			cin >> userInput;
			if (userInput < 1 || userInput > 10)
			{
				cout << "Liar! The dino gets a point!" << endl;
				enemyPoints++;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			else if (userInput > enemyStrength)
			{
				cout << "Your strength is " << userInput << ", and the dino's is " << enemyStrength << ". You get a point!" << endl;
				playerPoints++;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			else if (userInput < enemyStrength)
			{
				cout << "Your strength is " << userInput << ", but the dino's is " << enemyStrength << ". The dino gets a point!" << endl;
				enemyPoints++;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			else if (userInput = enemyStrength)
			{
				cout << "Your strength is " << userInput << ", and the dino's is also " << enemyStrength << ". No one gets the point." << endl;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			system("pause");

			cout << "\n\n2. Rock, Paper, or Scissors?" << endl;

			while (retry)
			{
				cout << "1.) Rock\n2.) Paper\n3.) Scissors." << endl;
				cin >> userInput;
				if (userInput < 1 || userInput > 3)
				{
					cout << "Invalid input! Try again!" << endl;
				}
				else if (userInput == 1)
				{
					retry = false;
					switch (enemyWeapon)
					{
					default:
					case 1:
						cout << "You and the dino both chose rock. No one gets a point!" << endl;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 2:
						cout << "The dino's paper beat your rock! The dino scores a point!" << endl;
						enemyPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 3:
						cout << "Your rock beat the dino's scissors! You scored a point!" << endl;
						playerPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					}
				}
				else if (userInput == 2)
				{
					retry = false;
					switch (enemyWeapon)
					{
					default:
					case 1:
						cout << "Your paper beat the dino's rock! You scored a point!" << endl;
						playerPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 2:
						cout << "You and the dino both chose paper. No one gets a point!" << endl;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 3:
						cout << "The dino's scissors beat your paper! The dino scores a point!" << endl;
						enemyPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					}
				}
				else if (userInput == 3)
				{
					retry = false;
					switch (enemyWeapon)
					{
					default:
					case 1:
						cout << "The dino's rock beat your scissors! The dino scored a point!" << endl;
						enemyPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 2:
						cout << "Your scissors beat the dino's paper! You scored a point!" << endl;
						playerPoints++;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					case 3:
						cout << "You and the dino both chose scissors. No one gets a point!" << endl;
						cout << "You: " << playerPoints << endl;
						cout << "Dino: " << enemyPoints << endl;
						break;
					}
				}
			}
			system("pause");
			cout << "\n\nHow many battles have you fought?" << endl;
			cin >> userInput;
			if (userInput > enemyBattles)
			{
				cout << "You have fought " << userInput << " battles, and the dino has only fought " << enemyBattles << ". You get a point!" << endl;
				playerPoints++;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			else if (userInput < enemyBattles)
			{
				cout << "You have fought " << userInput << " battles, but the dino has fought " << enemyBattles << ". The dino gets a point!" << endl;
				enemyPoints++;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			else if (userInput = enemyBattles)
			{
				cout << "The dino has also fought " << userInput << " battles. No one gets a point." << endl;
				cout << "You: " << playerPoints << endl;
				cout << "Dino: " << enemyPoints << endl;
			}
			system("pause");
			retry = true;
			cout << "\n\nFinal Question: Did you get enough sleep last night?\nType [y] or [n]." << endl;
			while (retry)
			{
				userInput = 0;
				cin >> userInput;
				if (userInput == 'y')
				{
					retry = false;
					cout << "You got enough sleep! You get a point!" << endl;
					playerPoints++;
					cout << "You: " << playerPoints << endl;
					cout << "Dino: " << enemyPoints << endl;
				}
				else if (userInput == 'n')
				{
					retry = false;
					cout << "The dino got sleep and you didn't! The dino gets a point!" << endl;
					enemyPoints++;
					cout << "You: " << playerPoints << endl;
					cout << "Dino: " << enemyPoints << endl;
				}
				else 
				{
					cout << "Invalid response! Try again!" << endl;
				}
			}

			if (playerPoints > enemyPoints)
			{
				cout << "You defeated the dino! Congratulations!" << endl;
			}
			if (playerPoints < enemyPoints)
			{
				cout << "You were defeated by the dino! Better luck next time." << endl;
			}
			if (playerPoints = enemyPoints)
			{
				cout << "Sudden Death! How much Vitamin C do you get every day in mg?" << endl;
				cin >> userInput;
				if (userInput >= 75)
				{
					cout << "You ate your wheaties this morning! You win!" << endl;
					playerPoints++;
					cout << "You: " << playerPoints << endl;
					cout << "Dino: " << enemyPoints << endl;
				}
				else if (userInput < 75)
				{
					cout << "You're malnourished! You need at least 75 mg a day. You lost!" << endl;
					enemyPoints++;
					cout << "You: " << playerPoints << endl;
					cout << "Dino: " << enemyPoints << endl;
				}
				
				system("pause");
			}
		}
	}
	system("pause");
}
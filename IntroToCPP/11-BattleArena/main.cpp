#include <iostream>
#include "info.h"
#include <conio.h>
#include <Windows.h>

int main()
{
	//int userInput;

	cout << ColoredMessage(12, "I'm in color!");
	cout << ColoredMessage(7, " I'm not in color!") << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "I'm not!" << endl;

	Fighter TinkyWinky { 100, 100, "Iron Man", "Repulsor Beam", 20, 30 };
	Fighter Dipsy{ 90, 90, "War Machine", "Machine Gun", 15, 25 };
	Fighter LaaLaa{ 60, 60, "Black Widow", "High Kick", 10, 15 };
	Fighter Po{ 90, 90, "Black Panther", "Panther Claw", 20, 25 };
	Fighter Donatello{ 120, 120, "Vision", "Soul Beam", 25, 35 };
	Fighter Raphaek{ 70, 70, "Spider-Man", "Strangle Web", 10, 30 };
	Fighter Michaelangelo{ 90, 90, "Captain America", "Shield Throw", 5, 25 };
	Fighter Hawkeye{ 65, 65, "Hawkeye", "Bow & Arrow", 5, 10 };
	
	getchar();
	
	return 0;
}
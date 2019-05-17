#pragma once
#include <string>
#include<Windows.h>
using namespace std;

class Fighter
{
	public:
	int HP;
	int maxHP;
	string name;
	string attack;
	int minDamage;
	int maxDamage;
};
//void SetColor(int value)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
//}
string ColoredMessage(int color, string message)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return message;
}
void SetColor()
{

}
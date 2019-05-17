#include"raylib.h"
#include"Potion.h"
#include"MyHero.h"
#include<string.h>

using namespace std;

MyHero::MyHero()
{
	name = "DoomGuy";
	special = "SpecialAttack";
	age = 30;
	HP = 1;
	wealth = 50;
	position.x = 400;
	position.y = 225;
}
MyHero::MyHero(string _name, string _special, int _age, int _HP, int _wealth, Vector2 _position)// ,Texture2D _texture)
{
	name = _name;
	special = _special;
	age = _age;
	HP = _HP;
	wealth = _wealth;
	position.x = _position.x;
	position.y = _position.y;
}
MyHero::~MyHero()
{

}
MyHero MyHero::operator+(const Potion & item) const
{
	MyHero hero = *this;
	hero.HP += item.HPModifier;

	return hero;
}
MyHero& MyHero::operator+=(Potion item)
{
	(*this) = (*this) + item;
	return (*this);
}
void MyHero::update()
{
	string fileName = "ouch";
	fileName.append(to_string(HP));
	fileName.append(".png");
	Texture2D myTexture = LoadTexture(fileName.c_str());
	DrawTexture(myTexture, position.x, position.y, WHITE);
}

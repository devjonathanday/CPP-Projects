#pragma once
#include"raylib.h"
#include"Potion.h"

using std::string;

class MyHero
{
public:
	string name;
	string special;
	int age;
	int HP;
	int wealth;
	Vector2 position;
	Texture2D texture;

	MyHero();
	MyHero(string _name, string _special, int _age, int _HP, int _wealth, Vector2 _position);//, Texture2D _texture);
	~MyHero();

	MyHero operator+(const Potion &item) const;
	MyHero& operator+=(Potion item);
	void update();
};
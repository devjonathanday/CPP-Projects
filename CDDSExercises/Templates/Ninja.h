#pragma once
#include"raylib.h"
#include<iostream>

using namespace std;

class Ninja
{
public:
	Texture2D tex;
	Vector2 position;
	float speed;

	Ninja(Texture2D _tex, Vector2 _position, float _speed);
	void update();
	Ninja();
	~Ninja();
};
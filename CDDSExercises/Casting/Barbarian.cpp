#include <iostream>
#include "raylib.h"
#include"Barbarian.h"

Barbarian::Barbarian()
{
	name = "Barbar";
	power = 50;
	gold = 50;
	position = { 200,200 };
	tex = LoadTexture("Assets/barbarian.png");
}
Barbarian::~Barbarian()
{

}

void Barbarian::draw()
{
	DrawTexture(tex, position.x, position.y, WHITE);
}
#include <iostream>
#include "raylib.h"
#include"Wizard.h"

Wizard::Wizard()
{
	name = "Wiz";
	mana = 50;
	gold = 50;
	position = { 200,200 };
	tex = LoadTexture("Assets/wizard.png");
}
Wizard::Wizard(std::string _name, int _mana, int _gold, Vector2 _position, Texture2D _tex)
{
	name = _name;
	mana = _mana;
	gold = _gold;
	position = _position;
	tex = _tex;
}
Wizard::~Wizard()
{

}
void Wizard::draw()
{
	DrawTexture(tex, position.x, position.y, WHITE);
}
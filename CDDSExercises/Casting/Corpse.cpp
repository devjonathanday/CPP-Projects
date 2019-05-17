#include <iostream>
#include "raylib.h"
#include"Corpse.h"

Corpse::Corpse()
{
	name = "Corpse";
	gold = 50;
	position = { 200,200 };
	//tex = LoadTexture("wizard.png");
}
Corpse::~Corpse()
{

}
Corpse::Corpse(Wizard wizard)
{
	name = wizard.name;
	gold = wizard.gold;
	position = wizard.position;
	//tex = LoadTexture("corpse.png");
}
Corpse::Corpse(Barbarian barbarian)
{
	name = barbarian.name;
	gold = barbarian.gold;
	position = barbarian.position;
	//tex = LoadTexture("corpse.png");
}

void Corpse::draw()
{
	DrawTexture(tex, position.x, position.y, WHITE);
}
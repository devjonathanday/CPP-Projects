#pragma once
#include"raylib.h"
#include<iostream>
#include<vector>

struct Bullet
{
	Texture2D tex;
	Rectangle rec;
	float speed;
	float damage;
	Vector2 direction;
	bool playerMade;

	void Draw();
	void Update();
};

bool CheckButton(Rectangle button); //Returns true if the mouse is within the bounds of a given rectangle.
void DrawRecLines(Rectangle rec, Color tint); //Draws the rectangle lines of 'rec' in color 'tint'
int RandomNumber(int minRange, int maxRange); // Generates a random number, starting at minRange and going until maxRange
Color RandomColor(); //Generates a random 'visible' color (no RGB values less than 50)
Vector2 NormalizeVector2(Vector2 vector); //Takes in a Vector2 and normalizes it to a unit circle
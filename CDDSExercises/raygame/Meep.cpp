#include "Meep.h"
#include<string>
#include<iostream>

using namespace std;

Meep::Meep()
{
	texture = LoadTexture("meep.png");
	x = 100;
	y = 100;
}
Meep::Meep(bool _enabled)
{
	texture = LoadTexture("meep.png");
	enabled = _enabled;
	x = 100;
	y = 100;
}
Meep::Meep(bool _enabled, string fileName, bool _playerControlled)
{
	texture = LoadTexture(fileName.c_str());
	dTexture = new Texture2D(texture);
	if (dTexture == nullptr)
	{
		cout << "Error: out of memory." << endl;
		exit(1);
	}
	enabled = _enabled;
	playerControlled = _playerControlled;
	x = 100;
	y = 100;
}
void Meep::refresh()
{
	if (enabled)
	{
		DrawTexture(texture, x, y, WHITE);
		if (playerControlled)
		{
			
			if (IsKeyDown(KEY_W))
			{
				y--;
			}
			if (IsKeyDown(KEY_A))
			{
				x--;
			}
			if (IsKeyDown(KEY_S))
			{
				y++;
			}
			if (IsKeyDown(KEY_D))
			{
				x++;
			}
		}
	}
}
Meep::~Meep()
{
	UnloadTexture(*dTexture);
	delete dTexture;
}
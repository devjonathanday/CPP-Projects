#pragma once
#include<raylib.h>
#include"Functions.h"

class ColorMenu
{
public:
	ColorMenu();
	~ColorMenu();

	Rectangle rUp = { 64,64,64,64 };
	Rectangle rDown = { 64,170,64,64 };
	Rectangle gUp = { 138,64,64,64 };
	Rectangle gDown = { 138,170,64,64 };
	Rectangle bUp = { 212,64,64,64 };
	Rectangle bDown = { 212,170,64,64 };

	void Draw();
	void Update(Color &changedColor);
};
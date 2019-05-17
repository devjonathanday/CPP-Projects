#pragma once
#include "Sprite.h"
class Button :
	public Sprite
{
public:
	void Update();// This Draw function will override the base classes Draw.
	bool CheckForClick();

	Button(const std::string *filename, const Vector2 & position, const  int cellCount = 1);
	Button();
	~Button();
};
#pragma once
#include"Button.h"

Button::Button() {};
Button::Button(Rectangle _rec)
{
	rec = _rec;
};
Button::~Button() {};

bool Button::CheckClicked()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		GetMouseX() > rec.x &&
		GetMouseX() < rec.x + rec.width &&
		GetMouseY() > rec.y &&
		GetMouseY() < rec.y + rec.height)
	{
		return true;
	}
	return false;
};
void Button::DrawButtonRec(Color color)
{
	DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
}
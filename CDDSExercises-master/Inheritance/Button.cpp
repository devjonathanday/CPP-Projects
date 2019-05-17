#include"Button.h"
void Button::Update()
{
	if (CheckForClick())
	{
		currentSprite = textureList[0];
	}
	else
	{
		currentSprite = textureList[1];
	}
	DrawTexture(currentSprite, x, y, WHITE);
}
bool Button::CheckForClick()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		if (GetMouseX() > x &&
			GetMouseY() > y &&
			GetMouseX() < x + currentSprite.width &&
			GetMouseY() < y + currentSprite.height)
			return true;
	}
	return false;
}

Button::Button(const std::string * filename, const Vector2 & position, const int cellCount)
{
	x = position.x;
	y = position.y;
	Texture2D * newList = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; i++)
	{
		newList[i] = LoadTexture(filename[i].c_str());
	}
	textureList = newList;
	currentSprite = textureList[0];
}
Button::Button()
{

}
Button::~Button()
{

}
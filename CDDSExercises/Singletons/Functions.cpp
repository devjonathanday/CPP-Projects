#include"Everything.h"

bool CheckButtonClicked(Rectangle buttonRec)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		GetMouseX() > buttonRec.x &&
		GetMouseY() > buttonRec.y &&
		GetMouseX() < buttonRec.x + buttonRec.width &&
		GetMouseY() < buttonRec.y + buttonRec.height)
		return true;
	return false;
}
bool CheckButtonHeld(Rectangle buttonRec)
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
		GetMouseX() > buttonRec.x &&
		GetMouseY() > buttonRec.y &&
		GetMouseX() < buttonRec.x + buttonRec.width &&
		GetMouseY() < buttonRec.y + buttonRec.height)
		return true;
	return false;
}
void DrawRecLines(Rectangle rec, Color color)
{
	DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, color);
}
int randomNumber(int minRange, int maxRange) // Generates a random number, starting at minRange and going until maxRange
{
	return rand() % (maxRange - minRange) + minRange;
}
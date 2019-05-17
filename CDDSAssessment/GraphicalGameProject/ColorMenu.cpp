#include"ColorMenu.h"

ColorMenu::ColorMenu() {}
ColorMenu::~ColorMenu() {}

void ColorMenu::Draw()
{
	DrawText("/\\", rUp.x + 2, rUp.y + 12, 40, RED);
	DrawText("\\/", rDown.x + 2, rDown.y + 12, 40, RED);
	DrawText("/\\", gUp.x + 2, gUp.y + 12, 40, GREEN); 
	DrawText("\\/", gDown.x + 2, gDown.y + 12, 40, GREEN);
	DrawText("/\\", bUp.x + 2, bUp.y + 12, 40, BLUE);
	DrawText("\\/", bDown.x + 2, bDown.y + 12, 40, BLUE);

	DrawText("R", rUp.x + 20, rUp.y + 70, 40, RED);
	DrawText("G", gUp.x + 20, gUp.y + 70, 40, GREEN);
	DrawText("B", bUp.x + 20, bUp.y + 70, 40, BLUE);
}
void ColorMenu::Update(Color &changedColor)
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		if (CheckButton(rUp) && changedColor.r < 255) changedColor.r++;
		if (CheckButton(gUp) && changedColor.g < 255) changedColor.g++;
		if (CheckButton(bUp) && changedColor.b < 255) changedColor.b++;
		if (CheckButton(rDown) && changedColor.r > 50) changedColor.r--;
		if (CheckButton(gDown) && changedColor.g > 50) changedColor.g--;
		if (CheckButton(bDown) && changedColor.b > 50) changedColor.b--;
	}
}
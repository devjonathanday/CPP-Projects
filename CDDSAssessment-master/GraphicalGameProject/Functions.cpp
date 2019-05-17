#include"Functions.h"

bool CheckButton(Rectangle button)
{
	Vector2 mouse = { GetMouseX(), GetMouseY() };
	if (mouse.x > button.x &&
		mouse.y > button.y &&
		mouse.x < button.x + button.width &&
		mouse.y < button.y + button.height)
		return true;
	else
	return false;
}
void DrawRecLines(Rectangle rec, Color tint)
{
	DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, tint);
}
int RandomNumber(int minRange, int maxRange)
{
	return rand() % (maxRange - minRange) + minRange;
}
Color RandomColor()
{
	return { (unsigned char)RandomNumber(50, 255), (unsigned char)RandomNumber(50, 255) , (unsigned char)RandomNumber(50, 255), 255 };
}
Vector2 NormalizeVector2(Vector2 vector)
{
	float distance = sqrt(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / distance, vector.y / distance };
}
void Bullet::Draw()
{
	DrawTexture(tex, rec.x, rec.y, WHITE);
	//DrawRecLines(rec, WHITE);
}
void Bullet::Update()
{
	rec.x += direction.x * speed * GetFrameTime() * 60;
	rec.y += direction.y * speed * GetFrameTime() * 60;
}
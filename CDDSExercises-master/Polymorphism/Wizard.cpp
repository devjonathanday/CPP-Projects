#include "Wizard.h"

Wizard::Wizard()
{

}
Wizard::Wizard(Texture2D sprite)
{
	mySprite = sprite;
}
Wizard::~Wizard()
{
	UnloadTexture(mySprite);
}
void Wizard::moveTo(Vector2 destination)
{
	position.x = destination.x;
	position.y = destination.y;
	DrawTexture(mySprite, position.x, position.y, WHITE);
};
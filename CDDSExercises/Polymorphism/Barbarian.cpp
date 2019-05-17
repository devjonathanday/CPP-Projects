#include "Barbarian.h"
#include"Functions.h"

Barbarian::Barbarian()
{

}
Barbarian::Barbarian(Texture2D sprite)
{
	mySprite = sprite;
	speed = 3;
}
Barbarian::~Barbarian()
{
	UnloadTexture(mySprite);
}
void Barbarian::moveTo(Vector2 destination)
{
	Vector2 newPosition = NormalizeVector2({ destination.x - position.x, destination.y - position.y });
	position.x += newPosition.x * speed;
	position.y += newPosition.y * speed;
	DrawTexture(mySprite, position.x, position.y, WHITE);
};
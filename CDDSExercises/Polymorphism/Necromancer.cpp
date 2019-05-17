#include"Necromancer.h"
#include"Functions.h"

Necromancer::Necromancer() {};
Necromancer::Necromancer(Texture2D sprite)
{
	mySprite = sprite;
};
Necromancer::~Necromancer()
{
	UnloadTexture(mySprite);
};
void Necromancer::update(Vector2 destination)
{
	std::cout << "Necromancer updating" << std::endl;
	speed = 2;
	Vector2 newPosition = NormalizeVector2({ destination.x - position.x, destination.y - position.y });
	position.x += newPosition.x * speed;
	position.y += newPosition.y * speed;
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
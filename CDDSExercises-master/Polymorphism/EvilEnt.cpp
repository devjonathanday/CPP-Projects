#include"EvilEnt.h"
#include"Functions.h"

EvilEnt::EvilEnt() {};
EvilEnt::EvilEnt(Texture2D sprite)
{
	mySprite = sprite;
};
EvilEnt::~EvilEnt()
{
	UnloadTexture(mySprite);
};
void EvilEnt::update(Vector2 destination)
{
	std::cout << "Ent updating" << std::endl;
	speed = 1;
	Vector2 newPosition = NormalizeVector2({ destination.x - position.x, destination.y - position.y });
	position.x += newPosition.x * speed;
	position.y += newPosition.y * speed;
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
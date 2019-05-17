#include"Enemy.h"
#include"Functions.h"

#include<iostream>

Enemy::Enemy() {};
Enemy::Enemy(Texture2D sprite)
{
	mySprite = sprite;
};
Enemy::~Enemy()
{
	UnloadTexture(mySprite);
};
void Enemy::update(Vector2 destination)
{
	std::cout << "Enemy updating" << std::endl;
	Vector2 newPosition = NormalizeVector2({ destination.x - position.x, destination.y - position.y });
	position.x += newPosition.x * speed;
	position.y += newPosition.y * speed;
	DrawTexture(mySprite, position.x, position.y, WHITE);
};
bool Enemy::CheckHit()
{
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) &&
		GetMouseX() > position.x - 10 &&
		GetMouseX() < position.x + 10 &&
		GetMouseY() > position.y - 10 &&
		GetMouseY() < position.y + 10)
	{
		return true;
	}
	return false;
}
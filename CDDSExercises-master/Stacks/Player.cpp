#include"raylib.h"
#include"Player.h"
#include"Functions.h"
#include"Command.h"
#include"tQueue.h"
#include<cmath>

Player::Player()
{
	position = { 400,200 };
}
Player::Player(Texture2D _tex, float _moveSpeed)
{
	position = { 400,200 };
	texture = _tex;
	moveSpeed = _moveSpeed;
}
Player::~Player()
{

}
void Player::moveTo(tQueue<Vector2> &positionQueue)
{
	Vector2 direction = { positionQueue.front().x - position.x, positionQueue.front().y - position.y };
	if (abs(direction.x) > 2 && abs(direction.y) > 2)
	{
		direction = NormalizeVector2(direction);
		position.x += direction.x * moveSpeed;
		position.y += direction.y * moveSpeed;
	}
	else
	{
		positionQueue.pop_front();
	}
}
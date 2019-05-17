#include <iostream>
#include "raylib.h"
#include"Player.h"

Player::Player()
{
	power = 50;
	gold = 0;
	Vector2 position = { 400, 225 };
	Texture2D tex = LoadTexture("Assets/player.png");
	health = 100;
}
Player::~Player()
{

}
void Player::update()
{
	if (IsKeyDown(KEY_W))
	{
		position.y--;
	}
	if (IsKeyDown(KEY_A))
	{
		position.x--;
	}
	if (IsKeyDown(KEY_S))
	{
		position.y++;
	}
	if (IsKeyDown(KEY_D))
	{
		position.x++;
	}
	DrawTexture(tex, position.x, position.y, WHITE);
}
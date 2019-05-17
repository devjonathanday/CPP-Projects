#include"Player.h"
#include"Wizard.h"
#include"Barbarian.h"

Player::Player()
{

}
Player::Player(Texture2D sprite)
{
	mySprite = sprite;
	speed = 3;
}
Player::~Player()
{
	UnloadTexture(mySprite);
}
void Player::moveTo(Vector2 destination)
{
	position = destination;
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
void Player::update()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
//Player& Player::operator=(Wizard wizard)
//{
//	(*this) = wizard;
//}
//Player& Player::operator=(Barbarian barbarian)
//{
//
//}
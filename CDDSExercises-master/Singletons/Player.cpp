#include"Player.h"

Player::Player() {}
Player::~Player() {}
Player::Player(Texture2D _tex, Rectangle _col, int _health, float _moveSpeed)
{
	tex = _tex;
	collider = _col;
	health = _health;
	moveSpeed = _moveSpeed;
}
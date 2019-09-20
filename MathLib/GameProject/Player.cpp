#include"Player.h"

void Player::Update()
{
	//Physics Updates
	rec.x += velocity.x;
	rec.y += velocity.y;
	velocity.y += gravityScale;
	rotationSpeed /= 1.025f;
	rotation += rotationSpeed;

	//Input
	if (IsKeyDown(KEY_A) && velocity.x > -3)
		velocity.x -= moveSpeed;
	if (IsKeyDown(KEY_D) && velocity.x < 3)
		velocity.x += moveSpeed;
	if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D))
		velocity.x /= 1.1f;
	if (IsKeyPressed(KEY_W))
	{
		velocity.y = -jumpVelocity;
		rotationSpeed = 20;
	}
}
void Player::Draw()
{
	DrawTexturePro(tex, { 0,0, (float)tex.width, (float)tex.height },
						{ rec.x,rec.y, (float)tex.width, (float)tex.height },
						{ (float)tex.width / 2, (float)tex.height / 2 }, rotation, tint);
}
Player::Player() {}
Player::Player(Texture2D _tex, Rectangle _rec)
{
	tex = _tex;
	rec = _rec;
	rotation = 0;
	rotationSpeed = 10;
	tint = {255, 255, 255, 255};
	velocity = { 0,0 };
	gravityScale = 0.1f;
	moveSpeed = 0.25f;
	jumpVelocity = 4;
}
Player::~Player() {}
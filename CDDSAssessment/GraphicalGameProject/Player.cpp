#include"Player.h"

Player::Player() {};
Player::~Player() {};
Player::Player(Texture2D _tex, Color _color, int _health, float _speed/* float fireTimer, float timeToFire*/)
{
	tex = _tex;
	rec = { (GetScreenWidth() / 2) - (float)(tex.width / 2), GetScreenHeight() - (float)(tex.height * 2), (float)(tex.width), (float)(tex.height) };
	color = _color;
	health = _health;
	speed = _speed;
};
void Player::Draw()
{
	DrawTexture(tex, rec.x, rec.y, color);
}
void Player::Update(std::vector<Bullet> &bulletList, Bullet bullet)
{
	if (IsKeyDown(KEY_A))
		if(rec.x > 0)
		rec.x -= speed * GetFrameTime() * 60;
	if (IsKeyDown(KEY_D))
		if (rec.x < GetScreenWidth() - tex.width)
			rec.x += speed * GetFrameTime() * 60;
	fireTimer += GetFrameTime();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)/* && fireTimer >= timeToFire*/)
	{
		//fireTimer = 0;
		Fire(bulletList, bullet);
	}
}
void Player::Fire(std::vector<Bullet> &bulletList, Bullet bullet)
{
	Bullet newBullet = { bullet.tex, {rec.x + (bullet.tex.width / 2), rec.y - bullet.tex.height}, 5, 1,
						 NormalizeVector2({ GetMouseX() - rec.x - 16, GetMouseY() - rec.y}), true };
	bulletList.push_back(newBullet);
}

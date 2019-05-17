#include"Alien.h"

Alien::Alien() {};
Alien::~Alien() {};
Alien::Alien(Texture2D _tex)
{
	tex = _tex;
	rec = { (float)-tex.width, (float)RandomNumber(64, 300), (float)tex.width, (float)tex.height };
	color = RandomColor();
	health = 3;
	speed = ((float)RandomNumber(10, 40)) / 10;
	dead = false;
	fireTimer = 0;
	fireTime = RandomNumber(2, 4);
};
void Alien::Draw()
{
	DrawTexture(tex, rec.x, rec.y, color);
}
void Alien::Update(Vector2 target, std::vector<Bullet> &bulletList, Bullet defaultBullet)
{
	fireTimer += GetFrameTime();

	if (fireTimer >= fireTime)
	{
		Fire(target, bulletList, defaultBullet);
		fireTimer = 0;
	}

	rec.x += speed * GetFrameTime() * 60;

	if (health <= 0)
		dead = true;
}
void Alien::Fire(Vector2 target, std::vector<Bullet> &bulletList, Bullet defaultBullet)
{
	Bullet myBullet = { defaultBullet.tex, { rec.x + (tex.width / 2) - 16, rec.y + (tex.height / 2) - 16 }, RandomNumber(2, 4), 1, NormalizeVector2({ target.x - rec.x, target.y - rec.y }), false };
	bulletList.push_back(myBullet);
}
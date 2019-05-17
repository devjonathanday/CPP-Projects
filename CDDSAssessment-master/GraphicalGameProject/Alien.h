#pragma once
#include"raylib.h"
#include"Functions.h"

class Alien
{
public:
	Texture2D tex;
	Rectangle rec;
	Color color;
	int health;
	float speed;
	bool dead;
	float fireTimer;
	float fireTime;

	Alien();
	~Alien();
	Alien(Texture2D _tex);
	void Draw();
	void Update(Vector2 target, std::vector<Bullet> &bulletList, Bullet defaultBullet);
	void Fire(Vector2 target, std::vector<Bullet> &bulletList, Bullet defaultBullet);
};
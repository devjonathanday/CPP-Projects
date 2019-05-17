#pragma once
#include"raylib.h"
#include"Functions.h"
#include<vector>

class Player
{
public:
	Texture2D tex;
	Rectangle rec;
	Color color;
	int health;
	float speed;
	float timeToFire;
	float fireTimer;

	Player();
	~Player();
	Player(Texture2D _tex, Color _color, int _health, float _speed /* float fireTimer, float timeToFire*/);
	void Draw();
	void Update(std::vector<Bullet> &bulletList, Bullet bullet);
	void Fire(std::vector<Bullet> &bulletList, Bullet bullet);
};
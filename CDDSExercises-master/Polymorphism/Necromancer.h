#pragma once
#include"Enemy.h"

class Necromancer : public Enemy
{
public:
	void update(Vector2 destination) override;
	Necromancer();
	Necromancer(Texture2D sprite);
	~Necromancer();
};
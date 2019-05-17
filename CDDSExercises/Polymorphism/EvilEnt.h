#pragma once
#include"Enemy.h"

class EvilEnt : public Enemy
{
public:
	void update(Vector2 destination) override;
	EvilEnt();
	EvilEnt(Texture2D sprite);
	~EvilEnt();
};
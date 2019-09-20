#pragma once
#include"raylib.h"
#include"vec2.h"
#include<vector>

class ParticleSystem
{
	struct Particle
	{
		Texture2D tex;
		vec2 position;
		vec2 velocity;
		Color color;
	};

	Particle defaultParticle;
	std::vector<Particle> particles;

	void Burst(int amount);
	void Draw();
	void Update();

	ParticleSystem();
	~ParticleSystem();
};
#include"ParticleSystem.h"


void ParticleSystem::Burst(int amount)
{
	for(int i = 0; i < amount; i++)
	particles.push_back(defaultParticle);
}
void ParticleSystem::Draw()
{
	for (int i = 0; i < particles.size(); i++)
		DrawTexture(particles[i].tex, particles[i].position.x, particles[i].position.y, particles[i].color);
}
void ParticleSystem::Update()
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].position += particles[i].velocity;
		particles[i].color.a -= 2;
	}
}

ParticleSystem::ParticleSystem() {}
ParticleSystem::~ParticleSystem() {}

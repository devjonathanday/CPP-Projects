#pragma once

int intSum(int a, int b, int& c);
void product(float a, float b, float &result);
void swap(float &a, float &b);

struct Aussiegochi
{
	float happiness;
	float hunger;
	float thirst;
	float sanity;
	bool dead;
};

void cuddleAussie(Aussiegochi& aus);
void feedAussie(Aussiegochi& aus);
void waterAussie(Aussiegochi& aus);
void abuseAussie(Aussiegochi& aus);
void maxAussieStats(Aussiegochi& aus);
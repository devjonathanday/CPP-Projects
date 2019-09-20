#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include"utils.h"
#include<time.h>

class RandomGenerator
{
	long long seed;
	int originalSeed = seed;

public:
	
	template <typename T>
	T rand(T min, T max)
	{
		seedRand(seed);
		return (seed % (max - min) + min);
	};

	template <typename T>
	T randDecimal(T min, T max, int precision)
	{
		return (T)rand((int)(min * pow(10, precision)), (int)(max * pow(10, precision))) / pow(10, precision);
	};

	void seedRand(long long _seed);
	int getOriginalSeed();
	int getCurrentSeed();
	uint32_t seedRandWeyl(uint64_t _seed);

	RandomGenerator();
	RandomGenerator(int _seed);
	~RandomGenerator();
};
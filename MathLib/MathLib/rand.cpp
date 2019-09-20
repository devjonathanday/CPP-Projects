#include"rand.h"
typedef unsigned long long uint64_t;

RandomGenerator::RandomGenerator()
{
	seedRandWeyl(time(NULL));
	originalSeed = seed;
};
RandomGenerator::RandomGenerator(int _seed)
{
	originalSeed = seed = _seed;
	seedRandWeyl(seed);
};
RandomGenerator::~RandomGenerator() {};

void RandomGenerator::seedRand(long long _seed)
{
	long long int temp = _seed * _seed; //Get the squared seed
	std::string tempValues = std::to_string(temp); //Convert squared seed to string
	std::string result = std::to_string(_seed); //Create final string with same length as seed
	while (result.length() < 6) //If the string is less than 6 digits
		result = std::to_string(0).c_str() + result; //Add a zero to the front of the string
	result = tempValues.substr((result.length() / 2) - 3, 6); //Get the middle 6 numbers from squared seed
	seed = std::stoi(result); //Convert back to int and assign seed
}

int RandomGenerator::getOriginalSeed()
{
	return originalSeed;
}
int RandomGenerator::getCurrentSeed()
{
	return seed;
}
uint64_t w = 0, s = 0xb5ad4eceda1ce2a9; // qualifying seed
uint32_t RandomGenerator::seedRandWeyl(uint64_t _seed)
{
	static uint64_t seed;

	if (_seed != 1)
	{
		seed = _seed;
	}
	else
	{
		seed = pow(seed, 2);
		w += s;
		seed += w;
	}
	return seed = (seed >> 32) | (seed << 32);
}
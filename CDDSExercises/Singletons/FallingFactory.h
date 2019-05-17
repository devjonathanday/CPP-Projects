#pragma once
#include "raylib.h"
#include "SimpleSprite.h"

class FallingFactory
{
private:
	FallingFactory();
	FallingFactory(FallingFactory const&);
	void operator=(FallingFactory const&);

public:
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;

	static void init(int spriteCount);

	SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	//SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	static FallingFactory& GetInstance();
};
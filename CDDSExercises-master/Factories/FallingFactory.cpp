#include"FallingFactory.h"
#include"Functions.h"
#include<string>
#include<iostream>

FallingFactory::FallingFactory() {}
FallingFactory::~FallingFactory() {}

void FallingFactory::init(int spriteCount)
{
	//Load in the various sprites
	spriteMasters = new SimpleSprite[spriteCount];
	for (int i = 0; i < spriteCount; i++)
	{
		std::string fileName = "Sprites/spaceMeteors_";
		fileName.append(std::to_string(i));
		fileName.append(".png");
		spriteMasters[i] = *(new SimpleSprite(fileName, "rock", .1f));
	}
	
}
SimpleSprite * FallingFactory::getRandom()
{
	return &(spriteMasters[randomNumber(0, spriteCount)]);
}
SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	return nullptr;
}
#include"FallingFactory.h"
#include"Functions.h"
#include<string>
#include<iostream>

FallingFactory::FallingFactory() {}
FallingFactory::FallingFactory(FallingFactory const&) {}
void FallingFactory::operator=(FallingFactory const&) {}

void FallingFactory::init(int spriteCount)
{
	//Load in the various sprites
	spriteMasters = new SimpleSprite[spriteCount];
	for (int i = 0; i < spriteCount; i++)
	{
		std::string fileName = "moonRock";
		fileName.append(std::to_string(i+1));
		fileName.append(".png");
		spriteMasters[i] = *(new SimpleSprite(fileName, "rock", 1));
	}
}
SimpleSprite * FallingFactory::getRandom()
{
	return (new SimpleSprite(spriteMasters[randomNumber(0, spriteCount)]));
}
//SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
//{
//	return nullptr;
//}
FallingFactory& FallingFactory::GetInstance()
{
	static FallingFactory instance;
	return instance;
}
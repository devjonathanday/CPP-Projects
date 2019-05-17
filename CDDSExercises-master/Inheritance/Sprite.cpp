#include"raylib.h"
#include"Sprite.h"
#include<time.h>

void Sprite::Update()
{
	DrawTexture(currentSprite, x, y, WHITE);
}
void Sprite::Animate(float gameTimer, int frameCount)
{
	currentSprite = textureList[((int)(gameTimer * frameRate) % frameCount)];
	DrawTexture(currentSprite, x, y, WHITE);
}
Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	x = 400;
	y = 200;
	Texture2D * newList = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; i++)
	{
		newList[i] = LoadTexture(filename[i].c_str());
	}
	textureList = newList;
	frameRate = _frameRate;
	currentSprite = textureList[0];
}
Sprite::Sprite()
{

}
Sprite::~Sprite()
{
	delete textureList;
}
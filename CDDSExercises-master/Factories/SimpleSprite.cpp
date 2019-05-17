#include"SimpleSprite.h"

void SimpleSprite::Translate(Vector2 delta)
{

}
void SimpleSprite::Draw()
{
	DrawTexturePro(texture, rec1, rec2, pos, rotation, WHITE);
}
SimpleSprite::SimpleSprite() {}
SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{

}
SimpleSprite::~SimpleSprite() {}
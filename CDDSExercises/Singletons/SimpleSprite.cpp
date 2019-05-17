#include"SimpleSprite.h"

void SimpleSprite::Translate(Vector2 delta)
{
	rec2.x += delta.x;
	rec2.y += delta.y;
	//rot++;
}
void SimpleSprite::Draw()
{
	//DrawTexturePro(texture, rec1, rec2, { -pos.x, -pos.y }, rot, WHITE);
	DrawTextureEx(texture, {rec2.x, rec2.y}, 0, 1, WHITE);
}
void SimpleSprite::Update()
{
	Translate({ 0, 1 });
	Draw();
}
SimpleSprite::SimpleSprite(){}
SimpleSprite::SimpleSprite(const SimpleSprite &original)
{
	sprType = original.sprType;
	rot = 0;
	texture = original.texture;
	pos.x = randomNumber(0, GetScreenWidth() - texture.width);
	pos.y = -texture.height;
	rec1 = { 0, 0, (float)texture.width, (float)texture.height };
	rec2 = { pos.x,pos.y,rec1.width,rec1.height};
}
SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	sprType = _sprType;
	rot = 0;
	texture = LoadTexture(filename.c_str());
	//texture = LoadTexture("moonRock1.png");
	pos.x = randomNumber(0, GetScreenWidth() - texture.width);
	pos.y = -texture.height;
	rec1 = { 0, 0, (float)texture.width, (float)texture.height };
	rec2 = { pos.x,pos.y,rec1.width * scale,rec1.height * scale };
}
SimpleSprite::~SimpleSprite() {}
//SimpleSprite * Clone()
//{
//	return new SimpleSprite(this);
//}
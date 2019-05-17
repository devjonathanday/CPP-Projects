#include"Ninja.h"

Ninja::Ninja(Texture2D _tex, Vector2 _position, float _speed)
{
	tex = _tex;
	position = _position;
	speed = _speed;
};
void Ninja::update()
{
	DrawTexture(tex, position.x, position.y, WHITE);
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed;
	}
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed;
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed;
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed;
	}
	//cout << "do the thing" << endl;
}
Ninja::Ninja()
{

};
Ninja::~Ninja()
{

};
#include"Soldier.h"

Soldier::Soldier(Texture2D _tex, Vector2 _position)
{
	tex = _tex;
	position = _position;
};
void Soldier::render()
{
	DrawTexture(tex, position.x, position.y, WHITE);
}
Soldier::Soldier()
{

};
Soldier::~Soldier()
{

};